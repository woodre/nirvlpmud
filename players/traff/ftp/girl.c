/*  GIRL.C - This file loads into room EASTHALL.C of the Delnoch Keep
    Girl will move randomly north and south, which can take her into
    rooms KITCHEN.C, SCULLERY.C and PANTRY.C        5-28-96
*/
xx#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg)  {
  object coins,doodad;
  ::reset(arg);
  if(arg) return;
  set_name("girl");
  set_race("human");
  set_alias("woman");
  set_short(BLU+"Serving Girl"+NORM);
  set_long(BOLD+
"One of the many serving girls employed by the Keep.  She serves\n"+
"food during the meals and helps clean up between meals.  She looks\n"+
"rather ordinary, but you suspect there is more to her than you see\n"+
"at first glance.\n"+NORM);
  set_level(16);
  set_hp(300+random(125));
  set_al(550);
  set_wc(22);
  set_ac(13);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The girl listens intently.\n");
  load_chat("The girl straightens some chairs, tyring to appear busy\n");
  load_chat("The girl scrubs the tables and appears bored.\n");
  load_chat("The girl brings a pot of tea.\n");
  load_chat("Girl whispers to you: Beware.  Casca's minions are everywhere.\n");
  load_a_chat("Girl says: Tenaka will feed your innards to the buzzards!\n");
  load_a_chat("Girl says: When you fight with me you fight with the Dragon!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(250)+650);
  move_object(coins,this_object());
  call_out("random_move",50);
}
status random_move()  {
  int n;
  n = random(2);
    switch(n)  {
      case 0 : command("north"); break;
      case 1 : command("sough"); break;
      }
  call_out("random_move",50);
  return 1;
}
