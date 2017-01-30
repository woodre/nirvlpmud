inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
  ob = clone_object("/players/saber/closed/weapons/dclaws.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/closed/gems/bloodstone.c");
move_object(ob2,this_object());
init_command("wield claws");
     set_name( "manes" );
     set_alias("demon");
      set_short("A small Manes");
     set_race( "demon");
     set_long("A small demon with sharp claws and a hideous grin.\n"+
       "It is evil.\n");
     set_level(2);
     set_ac(3);
     set_wc(6);
     set_hp(30);
     set_al(-200);
     set_frog(1);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(40);
     load_chat("Manes wails like the tormented soul that it is.\n");
     load_chat("Manes wails like the tormented soul that it is.\n");
     load_chat("Manes glares at you.\n");
     load_chat("Manes glares at you.\n");
     load_chat("Manes says: Welcome to the chamber of damned souls.\n");
     load_a_chat("Manes hisses at you.\n");
     load_a_chat("Manes hisses at you.\n");
     load_a_chat("Manes wails like the tormented soul that it is.\n");
     load_a_chat("Manes tries to bite you.\n");
     load_a_chat("Manes glares at you.\n");
     load_a_chat("Manes says: You will dwell with us in hades forever!\n");

     set_spell_mess1("Manes rakes its foe with razor sharp claws.");
     set_spell_mess2("Manes rakes you with razor sharp claws.");
     set_chance(20);
     set_spell_dam(3);
   }
}
