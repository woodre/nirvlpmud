inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("plunger");
      set_short("A Silver Plunger");
set_long("This is a rather large plunger that is designed to stick to an\n"+
"opponent's face, and rip it off.\n");
      set_class(12);
      set_weight(6);
      set_value(2000);
      set_name("A large Silver Plunger");
      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(20);
  if (i>15) {
say(this_player()->query_name()+"'s plunger sticks to his opponent's face and"
+"rips off some flesh.\n");
write("You stick the plunger on your opponent's face and rip off some flesh.\n");
   return 1;
  }
return 0;
}
