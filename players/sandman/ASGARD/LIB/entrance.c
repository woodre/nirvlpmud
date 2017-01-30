inherit "room/room";

init() {
   ::init();
   add_action("west","west");
}

west() {
   if(present("mimir") && present("book", this_player())) {
      write("Mimir says, Books may not leave the library!\n");
      return 1;
   }
}
reset(arg) {
   object mon;
   if(arg) { extra_reset(); return; }

   set_light(1);
   short_desc=("checkout desk [n,s,w]");
   long_desc=
     "This is the entrance to the Grand Library of Asgard. To the north\n"+
     "and south are huge arches. The arch to the north has the word MAGIK\n"+
     "and the arch to the south is emblazened with the word SAGAS\n"+
     "A desk is here and behind it sits the keeper of the library, Mimir.\n";
   no_castle_flag=1;
   items=
     ({
       "desk","A large desk cluttered with books",
     });
   dest_dir=
     ({
       "players/sandman/ASGARD/LIB/magik1","north",
       "players/sandman/ASGARD/LIB/saga1","south",
       "players/sandman/ASGARD/nstreet1","west",
     });
     extra_reset();
}
extra_reset() {
   object mon;
   if(!present("mimir")) {
   mon = clone_object("obj/monster");
   mon->set_name("mimir");
   mon->set_alias("the keeper");
   mon->set_short("Mimir");
   mon->set_long("Asgard's keeper of knowledge\n");
   mon->set_level(17);
   mon->set_hp(950);
   mon->set_ac(15);
   mon->set_wc(16);
   mon->set_al(0);
   mon->set_aggressive(0);
   mon->set_race("giant");
   mon->set_chance(35);
   mon->set_spell_mess1("Mimir freezes you with a glare!\n");
   mon->set_spell_mess2("Mimir leaps at you!\n");
   mon->set_spell_dam(35);
   mon->set_chat_chance(10);
   mon->load_chat("Mimir announces: Books may not leave the library!\n");
   move_object(mon, this_object());
   return;
   }
}
