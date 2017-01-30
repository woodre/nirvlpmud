inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, ob1;
 ob = clone_object ("/players/beren/Objects/Armors/Olgyo/opadded.c");
 move_object (ob, this_object ());
 command ("wear armor", this_object ());
 ob1 = clone_object ("/players/beren/Objects/Weapons/Olgyo/obow.c");
 move_object (ob1, this_object ());
 command ("wield bow", this_object ());

 set_name ("hunter");
 set_short ("Olgyo Hunter");
 set_race ("olgyo");
 set_long ("This is one of Olgyo hunters. He is hunting now, don't disturb!\n");
/* Changed level from 19 to 16 due to previous illegality and mult. mons  -Snow */
 set_level (16);
/* Changed to level 16 basics. -Snow 3/00 */
  set_ac(random(6)+10);
 set_wc (random(8)+18);
 set_hp (random(100)+350);
 set_al (0);
 set_aggressive (0);
 set_a_chat_chance (10);
 load_a_chat ("Hunter cries: YOU are my target now!\n");
}
}
