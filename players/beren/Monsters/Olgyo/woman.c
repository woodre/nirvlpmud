inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob;
 ob = clone_object ("/players/beren/Objects/Armors/Olgyo/odress.c");
 move_object (ob, this_object ());
 command ("wear armor", this_object ());

 set_name ("woman");
 set_short ("Olgyo Woman");
 set_race ("olgyo");
 set_long ("You see Olgyo Woman. She is ugly, not that kind you like.\n");
/* Changed level from 19 to 5 due to description and previous illegality. - Snow */
 set_level (5);
 set_ac (random(10));
 set_wc (random(8)+5);
 set_hp (random(50)+50);
 set_al (0);
 set_aggressive (0);
 set_chat_chance (50);
 set_a_chat_chance (50);
 load_chat ("Woman talks without a pause!\n");
 load_a_chat ("Woman cries: Don't touch me!\n");
}
}
