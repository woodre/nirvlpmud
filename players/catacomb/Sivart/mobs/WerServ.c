inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("servant");
set_race("durkor");
set_short("A servant");
set_long(
  "  One of the lower class Durkor that has become a servant\n"+
  "for House Werjor.  Clad in a drab, off-white cloak, he\n"+
  "blends into the environment.  The servant runs around doing\n"+
  "the day-to-day activities that make the house the way it is.\n");
 
set_level(15);
set_hp(200);
set_al(-100);
set_dead_ob(this_object());
set_aggressive(0);
add_money(random(700));
set_wc(15 + random(7));
set_ac(12);

}
  