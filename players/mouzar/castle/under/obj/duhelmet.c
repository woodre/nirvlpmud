inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("helmet");
set_alias("gold helmet");
set_size(1);
set_short("A golden Helmet");
set_long(
"This helmet serves or served as a kings crown.  It is of Duergar make and\n"
+ "is has great detail on it.  This helmet was made for a great leader.\n");
set_weight(1);
set_value(500);
set_ac(1);
set_type("helmet");
}
