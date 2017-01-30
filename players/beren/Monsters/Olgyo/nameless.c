/* These are simple hunters and fishermen. Thus level and coins decreased from 20 standards. -Snow 3/00 */
inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, gold;
/* Bow is worth the level 15 value. -Snow
 gold = clone_object ("obj/money");
 gold -> set_money (4000);
 move_object (gold, this_object ());
*/
 ob = clone_object ("/players/beren/Objects/Weapons/Olgyo/obow.c");
 move_object (ob, this_object ());
 command ("wield bow", this_object ());

 set_name ("nameless");
 set_short ("Nameless Olgyo");
 set_race ("olgyo");
 set_long ("You see Olgyo. You can say nothing about him.\n");
 set_level (15);
 set_ac (random(5)+8);
 set_wc (random(10)+17);
 set_hp (random(50)+175);
 set_al (-500);
 set_aggressive (1);
}
}
