inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Grey Sword");
set_alias("sword");
set_short("Sword");
set_long(
"Longsword in configuration, made of an unusual alloy of metals.  It has\n"
+ "a glowing sheen, cast from it's blade that makes the shadows from the\n"
+ "carvings on the hilt dance.\n");
set_value(30000);
set_weight(3);
set_class(18);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 30) {
write("Your sword flies from your hand to strike "+attacker->query_name()+" a second time.\n");
say("Dancing sword flies out of "+this_player()->query_name()+" grasp and strikes "+attacker->query_name()+"\n");
return 7;
 }
}
