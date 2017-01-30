inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("blade of aldera");
set_alias("blade");
set_short("Blade of Aldera (enchanted)");
set_long(
"This blade used to belong to one of the Royal Guards at Aldera. It is covered\n"
+ "with a mystic glow that fills the room. Its hilt is embedded with shiny\n"
+ "gems. It feels powerful.\n");
set_value(3000);
set_weight(4);
set_class(18);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 35) {
write("You slice deep into "+attacker->query_name()+" and tear out bloody flesh!\n");
say(this_player()->query_name()+" slices deep into "+attacker->query_name()+" and tears out bloody flesh!\n");
return 1;
   }
return 0;
 }
