/*  CAPTAIN.C - Loads into EASTHALL.C of Delnoch Keep.
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/monster";

reset(arg){
  object coins, weapon;
  ::reset(arg);
  if(arg) return;
  set_name("captain");
  set_race("human");
  set_short(YEL+"Captain"+NORM);
  set_long(YEL+
"The Captain has just returned from the forest, chasing rebels.\n"+
"His armor is dented and dirty from weeks of fighting.  He has\n"+
"lost half his men to rebel ambushes.  The look on his face\n"+
"shows his anger.  Now is not a good time to mess with him!\n"+NORM);
  set_level(18);
  set_hp(400 + random(100));
  set_al(-700);
  set_ac(15);
  set_chance(25);
  set_spell_dam(random(25)+5);
  set_spell_mess1("Captain kicks "+tp+" in the knee!\n"+tp+
" crubles to the ground in "+WHT+"PAIN!"+NORM+"\n");
  set_spell_mess2("Captain kicks you in the knee!\nYou crumble to the ground in "+WHT+"PAIN!"+NORM+"\n");
  set_chat_chance(10);
  set_a_chat_chance(20);
  load_chat("Captain says: The rebels base is in the Skoda Mountains.\n");
  load_chat("Captain says: They come to the forest and hide while ambushing us!\n");
  load_chat("Captain says: The mountains are too far to chase them without supplies.\n");
  load_chat("Captain says: If we could reach their stronghold we might trap them.\n");
  load_chat("The captain glares at the Aide.\n");
  load_chat("Captain rolls his eyes, when the Templar isn't looking.\n");
  load_a_chat("Captain says: You will soon regret this foolishness.\n");
  load_a_chat("Captain says: You wouldn't last a day in my army!\n");
/* NOTE:  The sword has average value of 600, (500+random(201)), with
monsters coins set to random(700)+50 average is 400, for a total
average of 1000, which is correct for level 18.  */
  coins=clone_object("obj/money");
  coins->set_money(random(700)+50);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
/* MOVED SET_WC TO AFTER INIT WIELD -Snow */
  set_wc(26);
}

