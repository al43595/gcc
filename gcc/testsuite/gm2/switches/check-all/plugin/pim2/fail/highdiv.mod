(* highdiv.mod test for compiletime detection of div overflow.

Copyright (C) 2019 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius.mulley@southwales.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Modula-2; see the file COPYING.  If not,
see <https://www.gnu.org/licenses/>.  *)

MODULE highdiv ;  (*!m2pim+gm2*)

TYPE
   foo = [MAX(INTEGER) DIV 4..MAX(INTEGER)] ;

VAR
   x, y, z,
   bar    : foo ;
BEGIN
   x := MIN(foo) ;
   bar := x + x ;
   bar := bar DIV x
END highdiv.
