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
  set_short(HIK+"Eshin Nightrunner"+NORM);
  set_long("\
     Clan Eshin use nightrunners as forward scouts and also as a way of\n\
weeding out the less skilled through attrition.  Garbed all in black and\n\
sporting a set of wicked looking claws.  This one looks to be well trained\n\
and equipped.\n");
  set_race("skaven");
  set_level(18);
move_object(clone_object("/players/khrell/weapons/underways/eshclaw.c"));
init_command("wield claws");
  set_wc(25+random(6));
  set_ac(14+random(4));
  set_hp(360+random(150));
  set_al(-800);
  set_aggressive(2);

set_chat_chance(10);
load_chat("The nightrunner looks about the area.\n");

set_a_chat_chance(10);
load_a_chat("The skaven squirts the musk of fear and squeaks loudly!\n");
  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("The"+HIK+" Nightrunner"+NORM+" cuts into you and\n\n\
  				      "+HIR+" S L I C E S "+NORM+"\n\n\
  				      away some flesh!\n");           

  set_spell_mess2(
"The"+HIK+" Nightrunner"+NORM+" rips into its foe!\n");

  gold=clone_object("obj/money");
  gold->set_money(random(2000)+2000);
  move_object(gold,this_object());

}
