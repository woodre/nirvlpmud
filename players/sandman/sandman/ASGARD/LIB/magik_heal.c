inherit "room/room";

reset(arg) {
   if(arg) { extra_reset(); return; }
   set_light(1);
   short_desc=("shelf [sw]");
   long_desc=
      "This is a large aisle lined with shelves filled with books on the\n"+
      "healing arts. Standing here is an impressive looking viking priest.\n"+
      "In his hands is a rather impressive looking book.\n";
   dest_dir=
   ({
     "players/sandman/ASGARD/LIB/magik1","southwest",
   });
   extra_reset();
}

extra_reset() {
   object mon;
   if(!present("cleric")) {
   mon = clone_object("obj/monster");
   mon->set_name("priest");
   mon->set_alias("viking priest");
   mon->set_short("A Viking Priest");
   mon->set_long("This is a formidable looking cleric.\n");
   mon->set_level(16);
   mon->set_hp(450);
   mon->set_wc(12);
   mon->set_ac(10);
   mon->set_al(300);
   mon->set_aggressive(0);
   mon->set_chat_chance(10);
   mon->load_chat("Priest says: Ohhh I've been looking for this book!\n");
   mon->set_chance(20);
   mon->set_spell_mess1("Priest calls down the wrath of the gods!\n");
   mon->set_spell_mess2("Priest smashes you with his faith!\n");
   mon->set_spell_dam(25);
   move_object(clone_object("players/sandman/OBJ/book_heal"),mon);
   move_object(mon,this_object());
   }
}
