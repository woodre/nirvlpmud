inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("demon priest");
set_alias("priest");
  set_race("demon");
set_short("demon priest");
set_long("A priest of the Demon Lord's. He wields no weapon... yet\n" +
      "you don't seem to think he needs one by his appearance.\n");
set_level(15);
set_hp(250);
set_al(-2000);
set_wc(15);
set_ac(12);
add_spell("chill touch",
   "#MN# touches you lightly with #MP# fingers, chilling you.\n",
   "#MN# touches #TN# lightly. #TN# looks weaker.\n",
   30, 10, "other|evil");

add_spell("Enervate",
   "#MN# places both hands upon you, enervating you severely.\n",
   "#MN# places both hands upon #TN#. #TN# looks much weaker.\n",
   10,25, "other|evil");

set_multi_cast(0);
set_chat_chance(15);
load_chat("Small demons whirl around the room.\n");
load_chat("The Demon Priest prays to the Demon Lord Brakian.\n"+
          "The Demon Priest becomes infused with necromantic energies.\n");
money = clone_object("obj/money");
money->set_money(1000);
move_object(money, this_object());
}
