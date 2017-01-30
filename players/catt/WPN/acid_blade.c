inherit"obj/weapon";
#include "/players/catt/AREAS/base_defines.c"
   object acid;
reset(arg) {
  ::reset(arg);
  if(arg) return;
   set_name("pain blade");
   set_alias("blade");
   set_short("Pain Blade");

  set_long(
      "You notice the beautifully god-crafted crystal blade\n"+
      "and hand wrapped hilt of stark electric white. This\n"+
      "blade, you feel, could freeze your very soul as it is\n"+
      "cold to your touch.\n");
  set_value(8000);
  set_weight(2);
  set_class(16);
  set_hit_func(this_object());
}
  weapon_hit(attacker) {
    if(random(100) < 40) {
      write("Acid drips off your blade.\n");
      say("Acid drips off "+this_player()->query_name()+"'s blade.\n");
      acid = clone_object(MISC+"acid_ob");
      move_object(acid, find_living(attacker));
      acid->dest_me(attacker);
return 0;
}
return 0;
}
