inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("servant");
set_race("durkor");
set_short("A durkor servant");
set_long(
  "  A pale skinned woman wanders around cleaning the area up\n"+
  "after the blademasters of the Jacor House.  The woman before\n"+
  "you has deep midnight blue eyes made even darker with her \n"+
  "white skin.  Her body has been completely covered in a white\n"+
  "robe as is required through ji'e'toh.\n");
 
set_level(15);
set_hp(250);
set_al(100);
set_dead_ob(this_object());
set_aggressive(0);
set_chance(5);
set_spell_dam(random (20)+10);
set_spell_mess1(			
  "The servant smashes her foe in the face in defense of her life.\n");
set_spell_mess2(			
  "The servant smashes you in the face, defending her life.\n");
set_wc(20);
set_ac(12);
}
  