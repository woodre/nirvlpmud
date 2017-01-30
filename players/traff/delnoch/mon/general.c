/*  GENERAL.C - Loads into EASTHALL.C of Delnoch Keep.
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/monster";

reset(arg){
  object coins, weapon;
  ::reset(arg);
  if(arg) return;
  set_name("general");
  set_race("human");
  set_short(HIR+"General"+NORM);
  set_long(HIR+
"The General has been a fighter all his life.  He is starting to\n"+
"show his age, but you can tell by looking at him that he is\n"+
"as tough as nails, and cold as steel.  He is not pleased to be\n"+
"at this meeting, as things have not been going well lately.\n"+NORM);
  set_level(19);
  set_hp(425 + random(100));
  set_al(-800);
  set_ac(16);
  set_chance(25);
  set_spell_dam(random(25)+15);
  set_spell_mess1("General chops "+tp+" in the neck!\n"+tp+
" turns "+HIB+"BLUE"+WHT+"!\n"+NORM);
  set_spell_mess2("General chops you in the neck!\nYour face turns "+BLU+"BLUE"+WHT+"!"+NORM+"\n");
  set_chat_chance(15);
  set_a_chat_chance(20);
  load_chat("General says: Tenaka is gathering the Dragon Troops to aid the rebels.\n");
  load_chat("General says: We are doing the best we can.\n");
  load_chat("General says: The Captain is my best man.  It will just take time\n"+
"to catch the rebels.\n");
  load_chat("General says: I need more men and supplies!\n");
  load_chat("The General glances at the Templar, then looks away.\n");
  load_chat("The General glares at the Captain.\n");
  load_a_chat("General says: You fool!  I'll have you fed to the halflings.\n");
  load_a_chat("General says: You wouldn't last an hour in MY army!\n");
/* NOTE:  The sword has average value of 600, (500+random(201)), with
monsters coins set to random(700)+1050 average is 1400, for a total
average of 2000, which is correct for level 19.  */
  coins=clone_object("obj/money");
  coins->set_money(random(700)+1050);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
/* MOVED SET_WC TO AFTER INIT WIELD -Snow */
  set_wc(28);
}

