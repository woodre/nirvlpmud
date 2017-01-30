#include "/players/forbin/define.h"

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
set_name("shockwave");
set_alias("transformer");
set_race("transformer");
set_short("Shockwave");
set_long(
         "Shockwave descrip\n"+
         "PART 2.\n");
set_level(18);
set_hp(400);
set_wc(26);
set_ac(15);
set_al(-750);

set_chance(20);
set_spell_dam(25+random(25));
set_spell_mess1(
     "\nShockwave fires a lethal beam of "+HIG+"Gamma Rays"+NORM+" at " +
     (string)attacker_ob->query_name()"\n\n");
set_spell_mess2(
     "\nShockwave fires a lethal beam of "+HIG+"Gamma Rays"+NORM+" at you.\n\n");
}

