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
"This gurther guard has the body of a true fighter.  Her shiny black skin\n"+
"is incredibly muscular.  She has two sharp horns on the top of her head.\n"+
"She is watching over the area with deathly eyes, they seem incredibly\n"+
"focused, as though they are taking in every little detail of the forest.\n");
  set_level(20);
  set_ac(17);
  set_wc(32);
  set_hp(500);
  set_al(0);
  set_aggressive(0);
  set_chance(15);
  set_gender("female");
  set_spell_dam(random(30));
  set_spell_mess1("The guard hits you extremely hard!\n");
  set_spell_mess2("The guard hits you extremely hard!\n");
  set_chat_chance(4);
  load_chat("The guard looks at you intently.\n");
  load_chat("The guard looks out across the river.\n");
  load_chat("The guard looks into the forest.\n");
  load_chat("The guard watches you closely.\n");
  load_chat("The guard asks:  What is your business here?\n");
  load_chat("The guard stares straight ahead.\n");
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
