inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("gurther");
  set_alias("creature");
  set_short("A black creature");
  set_race("gurther");
  set_long(
"This large creature is a gurther.  His body is covered by shiny black\n"+
"skin.  He is standing on his arms and legs, which are extremely muscular.\n"+
"He has a narrow face which looks deathly because of his eyes, which have\n"+
"very deep sockets.  On top of his head are two sharp horns, one of which\n"+
"is covered in dark dried blood.\n");
  set_level(20);
  set_ac(16);
  set_wc(38);
  set_hp(500);
  set_al(0);
  set_aggressive(0);
  set_chance(15);
  set_gender("male");
  set_spell_dam(50);
  set_spell_mess1("The gurther stares you down!\n");
  set_spell_mess2("The gurther slashes you with its claws!\n");
  set_chat_chance(4);
  load_chat("The creature looks at you intently.\n");
  load_chat("The creature looks out across the river.\n");
  load_chat("The creature looks into the forest.\n");
  load_chat("The creature watches you closely.\n");
  load_chat("The creature asks:  What is your business here?\n");
  load_chat("The creature rubs up against a tree.\n");
  set_dead_ob(this_object());
   }  
}

monster_died(){
  object horn;
  horn = CO("/players/zeus/realm/OBJ/ghorn.c");
  write("With your final blow you break off one of the creature's horns.\n");
  horn->set_value(4000+random(1500));
  MO(horn, ENV);
  return 1; 
}
