inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, ob1, gold;
 gold = clone_object ("obj/money");
 gold -> set_money (3000);
 move_object (gold, this_object ());
 ob = clone_object ("/players/beren/Objects/Armors/Olgyo/oleather.c");
 move_object (ob, this_object ());
 command ("wear armor", this_object ());
 ob1 = clone_object ("/players/beren/Objects/Weapons/Olgyo/cudgel.c");
 move_object (ob1, this_object ());
 command ("wield cudgel", this_object ());

 set_name ("zgama");
 set_short ("Zgama the ruler of Village");
 set_race ("olgyo");
/* This long description replaced -Snow 3/00
 set_long ("You see Zgama. He looks at you and wields his cudgel.\n");
*/
 set_long ("Standing before you is an Olgyor of uncommon size and strength.\n"+
    "While his muscles are redoubtable, his eyes betray a fear of the unknown.\n"+
    "You are a stranger to his land, and constitute a threat to his reign.\n");
 set_level (20);
 set_ac (20);
 set_wc (25);
 set_hp (1500);
 set_al (-500);
 set_aggressive (1);
 set_chat_chance (5);
 set_a_chat_chance (5);
 load_chat ("Zgama says: GET OUT OF HERE!\n");
 load_a_chat ("Zgama says: GET OUT OF HERE!\n");
}
}
