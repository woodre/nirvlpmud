inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Dancing Sword of Light");
set_alias("sword");
set_short("Dancing Sword");
set_long(
"Longsword in configuration, made of an unusual alloy of metals.  It has\n"
+ "a glowing sheen, cast from it's blade that makes the shadows from the\n"
+ "carvings on the hilt dance.\n");
set_value(2000);
set_weight(1);
set_class(12);
set_hit_func(this_object());
}
