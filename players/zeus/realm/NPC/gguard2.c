inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
object horn;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("guard");
  set_alias("gurther");
  set_short("A gurther guard");
  set_race("gurther");
  set_long(
"This is a mighty gurther guard.  He is about five feet tall, standing on\n"+
"his arms and legs.  His muscular body is covered by shiny black skin which\n"+
"glistens in the light.  The guards deathly eyes are very focused, taking\n"+
"in every little detail of the forest.  He has two sharp horns protruding\n"+
"from the top of his head.\n");
  set_level(20);
  set_ac(17);
  set_wc(32);
  set_hp(500);
  set_al(0);
  set_aggressive(0);
  set_chance(15);
  set_gender("male");
  set_spell_dam(random(30));
  set_spell_mess1("The guard hits its opponent extremely hard!\n");
  set_spell_mess2("The guard hits you extremely hard!\n");
  set_chat_chance(4);
  load_chat("The guard looks at you intently.\n");
  load_chat("The guard looks out across the river.\n");
  load_chat("The guard looks into the forest.\n");
  load_chat("The guard watches you closely.\n");
  load_chat("The guard asks:  What is your business here?\n");
  load_chat("The guard asks:  Why have you come here?\n");
  load_chat("The guard says:  Leave now.\n");
  set_dead_ob(TO);
}  }

monster_died()
{
	horn = CO("/players/zeus/realm/OBJ/ghorn.c");
 write("With your final blow you break off one of the guards horns.\n");
 horn->set_value(3000+random(2000));
  MO(horn, environment(TO));  
return 1; 
}
