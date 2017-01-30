inherit "obj/monster.c";


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("soul fire");
set_alt_name("soul");
set_alt_name("fire");
set_race("creature");
set_short("A soul fire");
set_long(
  "  A soul that has been completely consumed in flames.  Small bursts\n"+
  "of fire flicker off the dead creature as it walks aimlessly around \n"+
  "the area.\n");
 
set_level(17);
set_hp(350);
set_al(0);
set_ac(14);
set_wc(24);
set_dead_ob(this_object());
set_aggressive(0);
add_money(500 + random(1000));
}
   