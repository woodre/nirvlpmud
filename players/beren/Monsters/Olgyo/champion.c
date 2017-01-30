/* Changed level from 17 to 20, hps from 800 to 600 -Snow 3/00 */
inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, ob1, gold;
 gold = clone_object ("obj/money");
 gold -> set_money (1000);
 move_object (gold, this_object ());
 ob = clone_object ("/players/beren/Objects/Armors/Olgyo/oarmor.c");
 move_object (ob, this_object ());
 command ("wear armor", this_object ());
 ob1 = clone_object ("/players/beren/Objects/Weapons/Olgyo/olongs.c");
 move_object (ob1, this_object ());
 command ("wield longsword", this_object ());

 set_name ("champion");
 set_short ("Olgyo Champion");
 set_race ("olgyo");
 set_long ("You see Olgyo Champion. Beware of him!\n");
 set_level (20);
 set_ac (random(6)+10);
 set_wc (40);
 set_hp (600);
 set_al (0);
 set_aggressive (0);
 set_a_chat_chance (10);
 load_a_chat ("Champion cries: Run before I killed you!\n");
}
}
