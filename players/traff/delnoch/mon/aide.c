/*  AIDE.C - Loads into EASTHALL.C of Delnoch Keep.
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/monster";

reset(arg){
  object coins, weapon;
  ::reset(arg);
  if(arg) return;
  set_name("aide");
  set_race("human");
  set_short(HIG+"Aide"+NORM);
  set_long(HIG+
"A typical military aide.  His armor is bright and shiney, if little\n"+
"used.  He hovers around the General he serves.\n"+NORM);
  set_level(17);
  set_hp(375 + random(100));
  set_al(-600);
  set_ac(14);
  set_chance(20);
  set_spell_dam(random(25));
  set_spell_mess1("Aide gouges "+tp+" in the eye with his pen!\n"+RED+
"BLOOD "+NORM+"starts dripping down his face.\n");
  set_spell_mess2("Aide gouges you in the eye with his pen!\n"+RED+
"BLOOD "+NORM+"starts dripping down your face.\n");
  set_chat_chance(5);
  set_a_chat_chance(15);
  load_chat("Aide rapidly enters a note in his log.\n");
  load_chat("Aide smiles brightly.\n");
  load_a_chat("Aide blusters: You can't do this!\n");
  load_a_chat("Aide Shouts: You'll never get out of here alive!\n");
  load_a_chat("Aide says: Where are those blasted guards?\n");
/* NOTE:  The sword has average value of 600, (500+random(201)), with
monsters coins set to random(700)+1 average is 350, for a total
average of 950, which is correct for level 17.  */
  coins=clone_object("obj/money");
  coins->set_money(random(700)+1);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
/* MOVED SET_WC TO AFTER INIT WIELD -Snow */
  set_wc(24);
}

