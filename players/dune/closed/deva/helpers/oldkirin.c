#include "../def.h"
inherit "obj/monster";

string owner;

ENABLE_SPIRIT

id(str) { return str == "spirit_helper_mon" || 
                 str == "kirin" || str == "ki-rin"; }

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Ki-Rin");
   set_race("spirit");
   set_short("A Ki-Rin, funny looking unicorn");
   set_long("Ki-Rins are wierd. This kirin is aiding "+owner+".\n");
   set_level(1);
   set_hp(50);
   set_al(1000);
   set_wc(20);
   set_ac(5);
   set_chance(20);
   set_spell_dam(20);
   set_spell_mess1("Ki-Rin kicks its enemy");
   set_spell_mess2("Ki-Rin snorts fire at evil");
   enable_commands();
}
