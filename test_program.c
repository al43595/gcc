int n() {
	return 42;
}

int m(int a, int b) {
	int c = [[ a, n(), b ]];
	return c;
}

int main() {
	return m(0, 1);
}
