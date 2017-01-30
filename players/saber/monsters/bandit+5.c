inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 object ob2, ob3;
  ob2 = clone_object("/players/saber/armor/blackcloak.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/fmask.c");
move_object(ob3,this_object());

set_name("Masked bandit"); /* Took out the number -Dar */
      set_alias("bandit");
     set_short("A Masked Bandit");
     set_race( "human");
     set_long("A shady looking character wearing a black face mask.\n");
     set_level(2);
     set_ac(3);
     set_wc(6);
     set_hp(30);
     set_al(-150);
     set_aggressive(0);
     set_a_chat_chance(35);
     load_a_chat("Bandit curses at you.\n");
   }
}
