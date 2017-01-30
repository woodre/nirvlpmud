inherit "obj/monster";
#include "ex.h"
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("prosper");
   set_alias("proctor");
   set_short("Proctor Prosper");
   set_long("\n"+
	"	This grizzled old man seems to be on the verge of\n"+
	"death.  His body seems to hake slightly as he watches \n"+
	"you enter the room.  There is a hint of wiseness in his\n"+
	"eyes and you know that he knows a lot about Greyhawk.\n");
   set_level(20);
   set_hp(550);
   set_wc(28);
   set_ac(17);
   set_al(0);
   set_chat_chance(4);
   set_spell_dam(random(30));
   set_chance(20);
   set_spell_mess1("Prosper summons a lacky to hit you fiercely!\n");
   set_spell_mess2("Prosper summons a lacky to hit his attacker hard!\n");
   load_chat("Prosper says: The two must become one again...\n");
   load_chat("Prosper says: There is a bridge north of the city.\n");
   load_chat("Prosper says: The bridge leads to the barrows.\n");
   load_chat("Prosper says: It is rumored that a great evil is in the barrows.\n");
   gold=clone_object("obj/money");
   gold->set_money(5000);
   move_object(gold,TOB);
}
