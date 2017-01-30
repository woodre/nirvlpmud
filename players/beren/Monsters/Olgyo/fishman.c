inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, gold;
 gold = clone_object ("obj/money");
 gold -> set_money (random(300)+200);
 move_object (gold, this_object ());
 ob = clone_object ("/players/beren/Objects/Weapons/Olgyo/onet.c");
 move_object (ob, this_object ());
 command ("wield net", this_object ());

 set_name ("fishman");
 set_short ("Olgyo Fishman");
 set_race ("olgyo");
 set_long ("This is one of Olgyo Fishmen. He is fishing now, don't disturb!\n");
/* Changed level from 19 to 10 due to previous illegality and desc. - Snow */
 set_level (10);
 set_ac(random(6)+5);
 set_wc(random(10)+10);
 set_hp (random(100)+100);
 set_al (0);
 set_aggressive (0);
 set_a_chat_chance (10);
 load_a_chat ("Fishman cries: I gonna catch you like a fish!\n");
}
}
