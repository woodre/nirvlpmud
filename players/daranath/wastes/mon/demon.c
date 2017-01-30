#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/players/daranath/closed/monster1.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
 ob = clone_object("obj/money");
  ob->set_money(random(400) + 1300);
  /* Average coins of 1500, plus two 1k items for 3500 coins per mon guide */
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/gauntlet.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/flamesword.c");
  move_object(ob3, this_object());

set_name("Cormax the Demon of Flame");
set_alias("flame demon");
set_alt_name("cormax");
set_race("demon");
set_gender("male");

set_short(HIW+"Cormax "+RED+"the Demon of Flame"+NORM);
set_long("Cormax stands before you, one of the rare Demons of Flame within Nirvana.\n"+
     "He must have escaped from hell to wreck havoc here, starting with this\n"+
     "small tribe of goblins. He slowly wants to crush the Gundar Wastes, and\n"+
     "then all of the world.\n");

set_level(18);
set_ac(15);
set_wc(25 + random(6));
set_hp(375 + random(60));
set_al(-1200);
set_aggressive(0);

init_command("wield sword");
init_command("wear gauntlet");

set_chance(25);
set_spell_dam(30);
set_spell_mess1(WHT+"Cormax"+NORM+" begins casting a spell:\n\n"+
     "A huge ball of "+RED+"FLAME"+NORM+" strikes out at you...\n\n");
set_spell_mess2(WHT+"Cormax"+NORM+" casts a spell, lashing out with "+RED+"FLAME"+NORM+"\n");

set_chat_chance(3);
set_a_chat_chance(10);
load_chat("Cormax growls at one of the goblins.\n");
load_chat("Cormax looks annoyed by your presence.\n");
load_a_chat(WHT+"Cormax"+NORM+" summons "+RED+"FLAME"+NORM+" and hurls it at you.\n");
load_a_chat("Cormax hits you with a crushing blow.\n");
load_a_chat("Cormax swings the Flaming sword high overhead.\n");

   }
}
