inherit"obj/weapon";
#include "/players/catt/AREAS/base_defines.c"
   object snow;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("balmung");
  set_alias("blade");
  set_short("Artic Blade");

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
    if(random(100) < 70) {
write("Balmung showers "+attacker->query_name()+" with snow\n");
write("You can feel the air getting colder as a storm approaches\n");
say("Balmung showers "+attacker->query_name()+" with snow\n");
say("You can feel the air getting colder as the storm gets closer\n");
return 3;
  }
    if(random(100) < 40) {
write("Snow glitters in the air\n");
snow = clone_object(MISC+"balmung_snow");
move_object(snow, environment(this_player()));
write("The storm comes with all its might and fury\n");
write("leaving large snow drifts\n");
return 0;
}
return 0;
}
