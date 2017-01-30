inherit "room/room";

reset(arg) {
   if(arg) { extra_reset(); return; }
   set_light(1);
   short_desc=("school gym [s]");
   long_desc=
     "The mists part, and you are in your high school gym. It is after\n"+
     "school and the cheerleaders are practicing. In the center of the\n"+
     "gym is the prom queen and head cheerleader. She's never given you\n"+
     "the time of day, but then you've never met her in full armor,\n"+
     "wielding a sword *grin*. So go to it!\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/grypath2","south",
   });
   extra_reset();
}

extra_reset() {
   object mon;
   if(!present("cheerleader")) {
   mon = clone_object("obj/monster");
   mon->set_name("cheerleader");
   mon->set_alias("girl");
   mon->set_short("A Cheerleader");
   mon->set_long("This is the most popular girl in your high school.\n");
   mon->set_level(5);
   mon->set_hp(55);
   mon->set_wc(7);
   mon->set_ac(4);
   mon->set_al(-100);
   mon->set_aggressive(0);
   mon->set_chat_chance(15);
   mon->load_chat("Cheerleader shouts: I've got spirit how 'bout you???\n");
   mon->set_a_chat_chance(15);
   mon->load_a_chat("Ohhh fur sure, gag me with a spoon!\n");
   move_object(clone_object("players/sandman/ARMORS/shoes"),mon);
   move_object(mon,this_object());
   }
}
