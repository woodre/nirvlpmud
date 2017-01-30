string short_desc;
id(str) { return str == "package" || str == "box"; }
short() { if(!short_desc) { return "A UPS shipping box"; }
	return short_desc; }
set_short(s) { short_desc = s; }
long() { write("This is a UPS package.\n"); }
can_put_and_get() { return 1; }
get() { return 1; }
