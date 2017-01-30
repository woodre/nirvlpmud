inherit "/obj/monster";

reset (arg) {
:: reset (arg);
if (!arg) {
 object ob, ob1;
 ob1 = clone_object ("/players/beren/Objects/Armors/Olgyo/oarmor.c");
 move_object (ob1, this_object ());
 command ("wear armor", this_object ());
 ob = clone_object ("/players/beren/Objects/Weapons/Olgyo/osword.c");
 move_object (ob, this_object ());
 command ("wield sword", this_object ());

 set_name ("warrior");
 set_short ("Olgyo Warrior");
 set_race ("olgyo");
 set_long ("You see powerful Olgyo Warrior. You are better not to fight him.\n");
 set_level (19);
 set_ac (30);
 set_wc (40);
 set_hp (250);
 set_al (0);
 set_aggressive (0);
 set_a_chat_chance (10);
 load_a_chat ("Warrior cries: You 'll die now! Nobody can beat me!\n");
}
}
