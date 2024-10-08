#!/usr/bin/env python3

# The script is used for finding PRs that have a GIT revision that
# mentiones the PR and are not closed.  It's done by iterating all
# comments of a PR and finding GIT commit entries.

"""
Sample output of the script:
Bugzilla URL page size: 50
HINT: bugs with following comment are ignored: Can the bug be marked as resolved?

Bug URL                                              GIT commits                   known-to-fail                           known-to-work                           Bug summary
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88129   master                                                                                                        Two blockage insns are emited in the function epilogue
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88122   master                                                                                                        [9 Regression] g++ ICE: internal compiler error: Segmentation fault
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88084   master                                                                                                        basic_string_view::copy doesn't use Traits::copy
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88083   master                                                                                                        ICE in find_constant_pool_ref_1, at config/s390/s390.c:8231
...
Bugzilla lists:
https://gcc.gnu.org/bugzilla/buglist.cgi?bug_id=88129,88122,88084,88083,88074,88073,88071,88070,88051,88018,87985,87955,87926,87917,87913,87898,87895,87874,87871,87855,87853,87826,87824,87819,87818,87799,87793,87789,87788,87787,87754,87725,87674,87665,87649,87647,87645,87625,87611,87610,87598,87593,87582,87566,87556,87547,87544,87541,87537,87528
https://gcc.gnu.org/bugzilla/buglist.cgi?bug_id=87486
"""

import argparse
import json

import requests

base_url = 'https://gcc.gnu.org/bugzilla/rest.cgi/'
statuses = ['UNCONFIRMED', 'ASSIGNED', 'SUSPENDED', 'NEW', 'WAITING', 'REOPENED']
regex = '(.*\[)([0-9\./]*)( [rR]egression])(.*)'
closure_question = 'Can the bug be marked as resolved?'
start_page = 20
url_page_size = 50

def get_branches_by_comments(comments):
    versions = set()
    for c in comments:
        text = c['text']
        lines = text.split('\n')
        if 'URL: https://gcc.gnu.org/viewcvs' in text:
            version = 'master'
            for line in lines:
                if 'branches/gcc-' in line:
                    parts = line.strip().split('/')
                    parts = parts[1].split('-')
                    assert len(parts) == 3
                    version = parts[1]
                    break
            versions.add(version)
        else:
            for line in lines:
                if line.startswith('The ') and 'branch has been updated' in line:
                    version = 'master'
                    name = line.strip().split(' ')[1]
                    if '/' in name:
                        name = name.split('/')[1]
                        assert '-' in name
                        version = name.split('-')[1]
                    versions.add(version)
                    break
    return versions

def get_bugs(query):
    u = base_url + 'bug'
    r = requests.get(u, params = query)
    return r.json()['bugs']

def search():
    chunk = 1000
    ids = []
    print('%-30s%-30s%-40s%-40s%-60s' % ('Bug URL', 'GIT commits', 'known-to-fail', 'known-to-work', 'Bug summary'))
    for i in range(start_page, 0, -1):
        # print('offset: %d' % (i * chunk), flush = True)
        bugs = get_bugs({'bug_status': statuses, 'limit': chunk, 'offset': i * chunk})
        for b in sorted(bugs, key = lambda x: x['id'], reverse = True):
            id = b['id']

            fail = b['cf_known_to_fail']
            work = b['cf_known_to_work']

            u = base_url + 'bug/' + str(id) + '/comment'
            r = requests.get(u).json()
            keys = list(r['bugs'].keys())
            assert len(keys) == 1
            comments = r['bugs'][keys[0]]['comments']
            skip = False
            for c in comments:
                if closure_question in c['text']:
                    skip = True
                    break
            if skip:
                continue

            branches = sorted(list(get_branches_by_comments(comments)),
                              key=lambda b: 999 if b is 'master' else int(b))
            if branches:
                branches_str = ','.join(branches)
                print('%-30s%-30s%-40s%-40s%-60s' % ('https://gcc.gnu.org/PR%d' % id, branches_str, fail, work, b['summary']), flush=True)
                ids.append(id)

    # print all URL lists
    print('\nBugzilla lists:')
    while len(ids) > 0:
        print('https://gcc.gnu.org/bugzilla/buglist.cgi?bug_id=%s' % ','.join([str(x) for x in ids[:url_page_size]]))
        ids = ids[url_page_size:]

print('Bugzilla URL page size: %d' % url_page_size)
print('HINT: bugs with following comment are ignored: %s\n' % closure_question)

parser = argparse.ArgumentParser(description='')

args = parser.parse_args()
search()
