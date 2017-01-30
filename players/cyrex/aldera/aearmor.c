inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("glimmering platemail");
set_alias("platemail");
set_short("Glimmering Platemail");
set_long(
"This is one of the finest armors made by the elvish people. It is bound by\n"
+ "forces known only to the elven people. Made to protect it is.\n");
set_weight(3);
set_value(2000);
set_ac(4);
set_arm_light(1);
set_type("armor");
}
