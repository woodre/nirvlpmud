inherit "room/room";

init() {
   ::init();
   add_action("east","east");
}

east() {
   if(this_player()->query_level() > 6) {
      write("You are too high a level to go in here!\n");
      return 1;
   }
}
reset(arg) {
   object mon;
   if(arg) { extra_reset(); return; }

   set_light(1);
   short_desc=("a path [e,w]");
   long_desc=
     "The mist is lighter here, and the yellow paved road ends at a\n"+
     "gleaming golden gate. Beyond the gate is shrouded in a fine mist.\n"+
     "familiar sounds can be heard from beyond the gate. You wish to\n"+
     "continue, but then you see a stern figure guarding the gate.\n";
   no_castle_flag=1;
   items=
     ({
       "gate", "A gate carved out of what looks to be pure gold",
       "road", "A road paved with some sort of yellow stone",
       "mist", "You stare at the mist, and the longer you look the "+
               "harder it is to look away",
     });
   dest_dir=
     ({
       "players/sandman/SURR/path3","west",
       "players/sandman/DAYDREAM/entrance","east",
     });
     extra_reset();
}
extra_reset() {
   object mon;
   if(!present("untamo")) {
   mon = clone_object("obj/monster");
   mon->set_name("untamo");
   mon->set_alias("god of sleep");
   mon->set_short("Untamo");
   mon->set_long("An ancient Finnish god of dreams\n");
   mon->set_level(15);
   mon->set_hp(350);
   mon->set_ac(10);
   mon->set_wc(13);
   mon->set_al(0);
   mon->set_aggressive(0);
   mon->set_race("god");
   mon->set_chance(25);
   mon->set_spell_mess1("Untamo growls: prepare to meet your maker!\n");
   mon->set_spell_mess2("Untamo yells: Die mortal!\n");
   mon->set_spell_dam(25);
   mon->set_chat_chance(15);
   mon->load_chat("Untamo grumbles: Only level 5 and under may enter.\n");
   move_object(clone_object("/players/sandman/WEAPONS/sleep_club"),mon);
   mon->init_command("wield club");
   move_object(mon, this_object());
   return;
   }
}
