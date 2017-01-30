inherit "room/room";

reset(arg) {
   if(arg) { extra_reset(); return; }
   set_light(1);
   short_desc=("shelf [s]");
   long_desc=
      "This is a large aisle lined with shelves filled with books on the\n"+
      "defensive arts. Standing here is an burly looking Blacksmith.\n"+
      "In his hands is a rather impressive looking book.\n";
   dest_dir=
   ({
     "players/sandman/ASGARD/LIB/magik1","south",
   });
   extra_reset();
}

extra_reset() {
   object mon;
   if(!present("blacksmith")) {
   mon = clone_object("obj/monster");
   mon->set_name("blacksmith");
   mon->set_alias("burly blacksmith");
   mon->set_short("A Burly Blacksmith");
   mon->set_long("A muscular blacksmith.\n");
   mon->set_level(16);
   mon->set_hp(550);
   mon->set_wc(14);
   mon->set_ac(8);
   mon->set_al(0);
   mon->set_aggressive(0);
   mon->set_chat_chance(10);
   mon->load_chat("Blacksmith mutters: What a fine book!\n");
   mon->set_chance(20);
   mon->set_spell_mess1("Blacksmith pummels you within an inch of your life!\n");
   mon->set_spell_mess2("Blacksmith body slams you!\n");
   mon->set_spell_dam(25);
   move_object(clone_object("players/sandman/OBJ/book_protection"),mon);
   move_object(mon,this_object());
   }
}
