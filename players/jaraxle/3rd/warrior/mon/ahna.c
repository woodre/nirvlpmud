#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("Ahna");
   set_alias("archeologist");
   set_alt_name("ahna");
   set_race("human");
   set_gender("female");
   set_short("Ahna");
   set_long(
      "A short, full figured woman with long locks of bright red\n"+
      "hair tied up in a long ponytail.  Ahna wears a wide\n"+
      "straw hat and tattered safari clothing. She is covered\n"+
      "with dust and grime.\n");
   
   set_level(16);
   set_hp(600);
   set_al(0);
   set_wc(20);
   set_ac(15);
   set_aggressive(0);
   
   set_chat_chance(8);
   load_chat("Ahna looks around carefully.\n");
   
   load_chat("Ahna says, 'I am looking to "+HIW+"trade"+NORM+" coins for "+HIB+"Blue Dragon"+NORM+" "+HIW+"scale"+NORM+"..'\n");
   load_chat("Ahna says, 'I am looking to trade coins for "+HIB+"Blue Dragon"+NORM+" Scales..'\n");
 set_chance(12);
   set_spell_dam(40+random(26));
   
   set_spell_mess1(
"\n\nAhna cracks you in the mouth with a swift slap.\n");
   set_spell_mess2(
"\n\nAhna cracks you in the mouth with a swift slap.\n");
}

