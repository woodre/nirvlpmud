inherit "room/room";

reset(arg) {
   if(arg) { extra_reset(); return; }
   set_light(1);
   short_desc=("classroom [s]");
   long_desc=
     "This is a very popular daydream with the student population.\n"+
     "The mists part to reveal a ordinary looking classroom. At the\n"+
     "front of the classroom stands the most evil teacher from your past\n"+
     "Well this is a dream now, so kick some ass!\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/path1","south",
   });
   extra_reset();
}

extra_reset() {
   object mon;
   if(!present("teacher")) {
   mon = clone_object("obj/monster");
   mon->set_name("teacher");
   mon->set_alias("evil teacher");
   mon->set_short("An Evil Teacher");
   mon->set_long("This is the most hated teacher in your memory.\n");
   mon->set_level(7);
   mon->set_hp(75);
   mon->set_wc(6);
   mon->set_ac(3);
   mon->set_al(-500);
   mon->set_aggressive(0);
   mon->set_chat_chance(15);
   mon->load_chat("Your late, that's a detention for you!\n");
   mon->set_a_chat_chance(15);
   mon->load_a_chat("That's it, you are suspended!\n");
   move_object(clone_object("players/sandman/OBJ/answer_manual"),mon);
   move_object(mon,this_object());
   }
}
