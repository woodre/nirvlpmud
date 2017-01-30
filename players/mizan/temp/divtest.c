get() { return 1; }
id(str) { return str == "ftest"; }

int a, b;

init() { add_action("ftest", "ftest"); }

ftest()
{
	a = 3;
	b = 5;
	write(b/a + "\n");
	return 1;
}
