inherit "/obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("stinger");
   set_short("A bee stinger");
   set_long(
 "A small stinger that honey bees use to defend themselves and their hive.\n");
   set_type("spear");
   set_class(6);
   set_weight(1);
   set_value(150+random(100));
   set_hit_func(this_object());
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah>2) {
 say(this_player()->query_name()+" strikes hard with the stinger.\n");
 write("You strike hard with your stinger!\n");
}
}
