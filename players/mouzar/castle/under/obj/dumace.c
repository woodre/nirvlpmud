inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("mace");
set_alias("cool");
set_short("Black Mace");
set_long(
"A piece of stick with a spiked ball on the end.  Must hurt to be hit\n"
+ "by this thing.\n");
set_value(600);
set_weight(3);
set_class(17);
}
