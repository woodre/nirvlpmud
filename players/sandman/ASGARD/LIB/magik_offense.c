inherit "room/room";

reset(arg) {
   if(arg) { extra_reset(); return; }
   set_light(1);
   short_desc=("Shelves");
   long_desc=
      "This is a large aisle lined with shelves filled with books on the\n"+
      "offensive arts. Standing here is an gnarled looking wizard.\n"+
      "In his hands is a rather impressive looking book.\n";
   dest_dir=
   ({
     "players/sandman/ASGARD/LIB/magik1","southeast",
   });
   extra_reset();
}

extra_reset() {
   object mon;
   if(!present("wizard")) {
   mon = clone_object("obj/monster");
   mon->set_name("wizard");
   mon->set_alias("foul sorcerer");
   mon->set_short("An Old Wizard");
   mon->set_long("An old gnarled wizard, he looks to be in a bad mood.\n");
   mon->set_level(16);
   mon->set_hp(350);
   mon->set_wc(15);
   mon->set_ac(9);
   mon->set_al(-300);
   mon->set_aggressive(1);
   mon->set_chance(25);
   mon->set_spell_mess1("The wizard calls down a bolt of lightning!\n");
   mon->set_spell_mess2("Wizard says: You won't get my book!!!\n");
   mon->set_spell_dam(40);
   move_object(clone_object("players/sandman/OBJ/book_offense"),mon);
   move_object(mon,this_object());
   }
}
