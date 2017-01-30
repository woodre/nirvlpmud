#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("eshin nightrunner");
  set_alt_name("nightrunner");
  set_alias("eshin");
  set_short(HIK+"An Eshin Nightrunner"+NORM);
  set_long("\
     Clan Eshin uses nightrunners as forward scouts and also as a way of\n\
weeding out the less skilled through attrition.  Garbed all in black and\n\
sporting various wicked weapons of their clan.\n");
  set_race("skaven");
  set_level(18);
  set_wc(25+random(5));
  set_ac(14+random(2));
  set_hp(350+random(200));
  set_al(-800);
  set_aggressive(2);

set_chat_chance(10);
load_chat("The nightrunner surveys the area.\n");

set_a_chat_chance(10);
load_a_chat("The skaven squirts the musk of fear!\n");
  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("The"+HIK+" Nightrunner"+NORM+" violently slashes into you and\n\n\
  				      "+RED+" R I P S "+NORM+"\n\n\
  				      away some flesh!\n");           

  set_spell_mess2(
"The"+HIK+" Nightrunner"+NORM+" violently slashes its foe!\n");

  gold=clone_object("obj/money");
  gold->set_money(random(2000)+2000);
  move_object(gold,this_object());

}
