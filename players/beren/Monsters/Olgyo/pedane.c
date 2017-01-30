inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, ob1, gold;
 gold = clone_object ("obj/money");
 gold -> set_money (3000);
 move_object (gold, this_object ());
 ob = clone_object ("/players/beren/Objects/Armors/Olgyo/pcloak.c");
 move_object (ob, this_object ());
 command ("wear cloak", this_object ());
 ob1 = clone_object ("/players/beren/Objects/Weapons/Olgyo/staff.c");
 move_object (ob1, this_object ());
 command ("wield staff", this_object ());

 set_name ("pedane");
 set_short ("Pedane");
 set_race ("human");
/* Description changed from "You see a great fire. Pedane is stading in the centre of it.\n"
 * -Snow 3/00 */
 set_long("The man before you stands enveloped in roaring flame. He is of normal\n"+
     "height and weight, with greying hair. For some reason the fire cannot touch him.\n"+
    "This man is known by the Olgyor as 'Pedane', which means 'God'.\n");
 set_level (20);
 set_ac (55);
 set_wc (25);
 set_hp (1500);
 set_al (500);
 set_aggressive (0);
}
}
