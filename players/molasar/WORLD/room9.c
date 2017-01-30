

string me, pers;

reset(arg) {
   object ped;
   set_light(1);
  if (present("pedestal"))
   destruct(present("pedestal"));
     ped = clone_object("players/molasar/OBJ/pedestal");
     move_object(ped, this_object());
}

init() {
/*
   if(this_player()->query_ghost() == 1) {
     return this_player()->remove_ghost(0);
   }
*/
   if(!present("qstob1", this_player())) {
     write("You did not go by the right paths!\n");
     move_object(this_player(), "/room/church");
     return 1;
   }
   add_action("south", "south");
   add_action("nt","trump");
   add_action("nt","teleport");
   add_action("nt","use");
   add_action("nt","invoke");
   add_action("nt","create");
}

nt() {
   write("Spells and magical items do not seem to function in this realm.\n");
   return 1;
}

south() {
   object ob;
   ob = present("qstob1", this_player());
   me = this_player()->query_real_name();

   write("You feel the fabric of space collapse and send you hurtling "+
         "through a void.\n");
   if(ob) { destruct(ob); }
   move_object(clone_object("players/molasar/OBJ/qstob2"), this_player());
   this_player()->move_player("away#room/sunalley2");
   return 1;
}

dest_dir() {
   int i;
   i = random(6);

   if(i == 0) {
     find_player(me)->move_player("south#room/church");
   }
   if(i == 1) {
     find_player(me)->move_player("south#room/south/sshore20");
   }
   if(i == 2) {
     find_player(me)->move_player("south#room/sunalley2");
   }
   if(i == 3) {
     find_player(me)->move_player("south#players/molasar/keep/cellar/meeting");
   }
   if(i == 4) {
     find_player(me)->move_player("south#players/molasar/CASTLE/tower_top");
   }
   if(i == 5) {
     find_player(me)->move_player("south#players/molasar/keep/lvl2/hall1");
   }
   return 1;
}


short() { return "An empty room"; }

long() {
   write("You are in an empty room.  Standing alone in the center of the room\n");
   write("is a pedestal.  On the southern wall you notice a small\n");
   write("shimmering entrance.  The hole is too dark to see where it leads, but it is\n");
   write("the only obvious exit.\n");
   write("   There is one obvious exit:  south\n");
}

