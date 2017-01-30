/* Randomized this guard a bit, considering he is all over the place. -Snow 3/00 */
inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {

 set_name ("guard");
 set_short ("Olgyo Guard");
 set_race ("olgyo");
 set_long ("You see Olgyo Guard. It seems that you can't pass.\n");
 set_level (random(6)+10);
 set_ac (level - 2);
 set_wc (level + 4);
 set_hp (level * 10 + 55);
 set_al (0);
 set_aggressive (0);
 set_a_chat_chance (10);
 load_a_chat ("Guard cries: I just CAN'T let you pass!\n");
/* Put in a little profit potential.. -Snow 3/00 */
money = random(level * 40) + (level * 20);
}
}
