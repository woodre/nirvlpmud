inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 object ob,ob2,ob3;
  ob2 = clone_object("/players/saber/weapons/rapier.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/smile.c");
move_object(ob3,this_object());
ob = clone_object("/players/saber/stuff/rose.c");
move_object(ob,this_object());

set_name("Masked bandit"); /* Changed to match the others -Dar */
set_alt_name("bandit");
     set_short("The Kissing Bandit");
     set_race( "human");
set_long("A tall, well dressed bandit with a sparkle in his eyes\n"+
    "and a smile on his lips.\n");
     set_level(6);
     set_ac(6);
     set_wc(9);
     set_hp(90);
     set_al(-150);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(25);
    load_chat("Bandit says: Ah ha!  A new object of affection!\n");
     load_chat("Bandit sniffs a rose.\n");
    load_chat("The kissing bandit looks at you.\n"+
 "Bandit says: Hello, my name is Richard.\n"+
  "Remember that, because you'll be screaming it later tonight!\n");
  load_chat("Bandit winks at you.\n");
   load_chat("Bandit leans forward and kisses you upon the lips!\n");
    load_a_chat("Bandit leans forward and kisses you upon the lips!\n");
    load_a_chat("Bandit winks at you.\n");
   load_a_chat("Bandit smiles wickedly at you.\n");
    load_a_chat("Bandit says: You can not kill the power of love!\n");
   }
}
