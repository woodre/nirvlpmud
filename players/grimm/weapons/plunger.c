inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("plunger");
      set_short("A large Plunger");
set_long("This is a rather large plunger that is designed to stick to an\n"+
"opponent's face, and rip it off.\n");
      set_class(8);
      set_weight(4);
      set_value(600);
      set_name("A large Plunger");
      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
/* no return...just a cool message */
  if (i>3) {
say(this_player()->query_name()+"'s plunger sticks to his opponent's face and"
+" rips off some skin.\n");
write("You stick the plunger on your opponent's face and rip off some flesh.\n");
    }
   return 0;
}
