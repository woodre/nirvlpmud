/* fake_ob.c: master logger's fake object */
short() { return "A well-worn Logger pack"; }
get() { return 1; }
long() { return 0; }
id(str) { return str == "fake_pack" || str == "logger pack"; }
