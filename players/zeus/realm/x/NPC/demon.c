
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define TIME 120+random(120)
object counter;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("a cursed demon");
  set_short("A cursed demon");
  set_race("demon");
  set_long(
"This is a small red demon.  It has a tough little body with gangly arms.\n"+
"It is hunched over, but looks only to be about two feet tall.  A constant\n"+
"grin adorns it's face, which is highlighted by it's burning eyes.  It's\n"+
"claws are razor sharp and caked with dry blood.  It is forever cursed\n"+
"to hunt the weak who would dare venture into the Fallen Lands.\n");
  set_level(15);
  set_ac(8);
  set_wc(32+random(9));
  set_hp(180);
  set_gender("creature");
  set_aggressive(1);
  set_al(-666);
  set_chance(8);
  set_spell_dam(15+random(26));
  set_spell_mess1("The cursed demon slashes you with its claws!\n");
  set_spell_mess2("The cursed demons eyes glaze over in bloodlust.\n");
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat("The demon glares at you.\n");
  load_chat("The demon's eyes burn.\n");
  load_chat("The demon grins.\n");
  load_chat("The demon examines you.\n");
  load_a_chat("The demons eyes glaze over in bloodlust.\n");
  set_dead_ob(TO);
  call_out("destruct_demon", TIME);
}  }

id(str){ return str == "demon" || str == "daemon" || str == "cursed demon"; }


monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  say("The cursed demon bursts into flames!\n"+
    "Its charred body falls to the ground.\n");
  remove_call_out("destruct_demon");
  if(corpse)
  {
    corpse->set_long(
      "This is the charred remains of a cursed demon.  Its skin is mostly\n"+
      "black, spattered with blood.  Pieces of bone are protruding from\n"+
      "its flesh in numerous places.  A very pungent odor of rot and decay\n"+
      "surrounds the twisted corpse.");
    corpse->set_short("The charred remains of a cursed demon");
  }
  DD->add_kills(AO, 1);
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a small demon [mean].\n");
}

destruct_demon(){
   if(!environment()) return 1;
   TR(environment(),
		"The cursed demon bursts into flames!\n");
   destruct(TO);
   return 1; 
}
