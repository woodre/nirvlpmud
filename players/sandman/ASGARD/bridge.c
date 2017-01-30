/*
Changes:
  Changed Hemidal's wc from 17(15 with weapon) to 28.
  Added 3000(avg) coins.
  Fixed a few typos.
  -Feldegast 1/26/01
*/
inherit "room/room";

init() {
   ::init();
   add_action("east","east");
}

east() {
   if(present("hemidal") && this_player()->query_level() < 14) {
      write("Hemidal says, You are too puny to join the gods!\n");
      return 1;
   }
}
reset(arg) {
   object mon;
   if(arg) { extra_reset(); return; }

   set_light(1);
   short_desc=("A bridge");
   long_desc=
     "Where do god's go when thier followers are gone?? The answer is\n" +
     "simple when you think about it. They go to the land of dreams where\n" +
     "mortal man still honors them. A rainbow begins there at the foot of\n" +
     "stands a grim being.\n";
   no_castle_flag=1;
   items=
     ({
       "rainbow","A multi-colored bridge of light rising into the sky",
       "being","A sturdy warrior whose ice blue eyes read your soul",
     });
   dest_dir=
     ({
       "players/sandman/ASGARD/entrance","east",
       "players/sandman/SURR/path8","west",
     });
     extra_reset();
}
extra_reset() {
   object mon;
   if(!present("hemidal")) {
   mon = clone_object("obj/monster");
   mon->set_name("hemidal");
   mon->set_alias("watcher");
   mon->set_short("Hemidal");
   mon->set_long("Hemidal is the guardian god of Asgard.\n");
   mon->set_level(19);
   mon->set_hp(1200);
   mon->set_ac(17);
   mon->set_wc(28);
   mon->set_al(0);
   mon->set_aggressive(0);
   mon->set_race("god");
   mon->set_chance(35);
   mon->set_spell_mess1("Hemidal says: You may not pass!\n");
   mon->set_spell_mess2("Hemidal yells: Die mortal!\n");
   mon->set_spell_dam(35);
   mon->set_chat_chance(15);
   mon->load_chat("Hemidal announces: Only the mighty may enter!\n");
   move_object(clone_object("/players/sandman/WEAPONS/spear"),mon);
   mon->init_command("wield spear");
   mon->set_wc(28);
   mon->add_money(2000+(50*random(40)));
   move_object(mon, this_object());
   return;
   }
}
