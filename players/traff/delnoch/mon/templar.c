/*  TEMPLAR.C - Loads into EASTHALL.C of Delnoch Keep.
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"

reset(arg){
  object coins, weapon;
  ::reset(arg);
  if(arg) return;
  set_name("templar");
  set_race("human");
  set_short(RED+"Templar"+NORM);
  set_long(RED+
"Dressed totally in BLACK, the Templar radiates an aura of pure\n"+
"evil!  He has a penetrating gaze that seems to look right\n"+
"through you.  He looks agitated already, and you think it might\n"+
"not be a good idea to anger him further.\n"+NORM);
  set_level(20);
  set_hp(450 + random(100));
  set_al(-900);
  set_ac(17);
  set_chance(33);
  set_spell_dam(random(25)+25);
  set_spell_mess1("Templar makes a gesture and mumbles a few words.\n"+tp+
" doubles over in "+WHT+"PAIN!"+NORM+"\n");
  set_spell_mess2("Templar makes a gesture and mumbles a few words!\nYou double over in "+WHT+"PAIN!"+NORM+"\n");
  set_chat_chance(20);
  set_a_chat_chance(20);
  load_chat("Templar says: Gentlemen, Casca is not pleased with you.\n");
  load_chat("Templar says: Your best is not good enough.\n");
  load_chat("Templar says: Supplies are being moved to the mountains now.\n");
  load_chat("Templar says: We are nearly ready to move the Halflings!\n");
  load_chat("Templar glares at the General.\n");
  load_chat("Templar glares at the Captain.\n");
  load_chat("Templar glares at the Aide.\n");
    load_a_chat("Templar snarles: You think you can withstand my power?\n");
    load_a_chat("Templar smiles an evil smile at you!\n");
    load_a_chat("Templar says: If you live, I'll put you in the Halfling army!\n");
/* NOTE:  The halfsword has a value of 1000, with the
monsters coins set to random(1000)+3500 average is 4000, for a total
average of 5000, which is correct for level 20.  */
  coins=clone_object("obj/money");
/* Max is max... why not have less than max anyway?  -Snow */
  coins->set_money(random(1000)+2500);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/halfsword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  set_wc(30); /* Placed after the init wield... -Snow */
  move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
}

