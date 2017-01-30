inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("scales");
set_alias("dragon scales");
set_short("Dragon Scales");
set_long(
"This is a full suit of Byzantine armor. It is made entirely of overlapping\n"+
"dragon scales.\n");
set_weight(4);
set_value(2000);
set_ac(4);
set_type("armor");
}
