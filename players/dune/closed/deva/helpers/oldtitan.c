#include "../def.h"
inherit "obj/monster";

string owner;

ENABLE_SPIRIT

id(str) { return str == "spirit_helper_mon" ||
                 str == "titan"; }

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Titan");
   set_race("spirit");
   set_short("A Titan, looks mean");
   set_long("Titans are tall. This titan is aiding "+owner+"\n");
   set_level(1);
   set_hp(50);
   set_al(1000);
   set_wc(25);
   set_ac(5);
   set_chance(20);
   set_spell_dam(20);
   set_spell_mess1("Titan stomps on its enemy");
   set_spell_mess2("Titan punches evil");
   set_chat_chance(5);
   load_chat("Titan says hi.\n");
   enable_commands();
}

