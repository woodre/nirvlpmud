/*  GWEN.C - Loads into EASTHALL.C of Delnoch Keep.
    Changes as of 5-28-96:
    Added color,paths changed for new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins,doodad;
  ::reset(arg);
  if(arg) return;
  set_name("gwen");
  set_race("human");
  set_alias("woman");
  set_short(MAG+"Gwen"+NORM);
  set_long(YEL+
"One of the ladies in residence here.  She loves to gossip.\n"+
"She often meets William here so she can pick up tidbits of news\n"+
"to share with her friends.\n"+NORM);
  set_level(17);
  set_hp(350+random(100));
  set_al(-750);
  set_wc(24);
  set_ac(14);
  set_chat_chance(15);
  set_a_chat_chance(20);
  load_chat("Gwen says: How very interesting, tell me more.\n");
  load_chat("Gwen says: I'll be glad when the halflings are gone.\n");
  load_chat("Gwen says: Girl!  Bring me some tea.\n");
  load_chat("Gwen bats her eyes and smiles.\n");
  load_chat("Gwen asks: How long will the men be away fighting?\n");
  load_chat("Gwen asks: Is Tenaka really leading the Dragon Troops?\n");
  load_chat("Gwen listens intently.\n");
  load_chat("Gwen says: The minions make me nervous, always skulking about.\n");
  load_a_chat("Gwen shouts: Guards!  Help me!");
  load_a_chat("Gwen laughs: The halflings will feed on your corpse!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(250)+790);
  move_object(coins,this_object());
  doodad = clone_object("/players/traff/delnoch/obj/trinket.c");
  move_object(doodad,this_object());
}
