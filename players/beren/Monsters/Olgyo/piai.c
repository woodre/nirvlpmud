/* These are simple hunters and fishermen. Thus level and coins decreased from 20 standards. -Snow 3/00 */
inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, gold;
/* Sword is worth the level 15 value. -Snow
 gold = clone_object ("obj/money");
 gold -> set_money (4000);
 move_object (gold, this_object ());
*/
 ob = clone_object ("/players/beren/Objects/Weapons/Olgyo/osword.c");
 move_object (ob, this_object ());
 command ("wield sword", this_object ());

 set_name ("piai");
 set_short ("Piai the Olgyo");
 set_race ("olgyo");
 set_long ("You see Piai, VERY greedy man.\n");
 set_level (15);
 set_ac (random(4)+10);
 set_wc (random(10)+15);
 set_hp (random(50)+175);
 set_al (-500);
 set_aggressive (1);
 set_a_chat_chance (50);
 load_a_chat ("Piai cries: Gimme your money!\n");
}
}
