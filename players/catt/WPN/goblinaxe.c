inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("worn axe");
set_alias("axe");
set_short("a very worn axe");
set_long(
"what a piece of junk.. not likely this old thing will be useful.\n");
set_value(100);
set_weight(2);
set_class(7);
}
