#define NAME "Molasar"
#define DEST "room/sunalley2"

id(str) { return str == "keep" || str=="town" || str=="rowan" ||
          str=="town of rowan" || str=="trees" || str=="road" ||
          str=="dirt road" || str=="trail" || str=="dusty trail"; 
}

short() {
/*
  return "A dusty trail begins to the north.\n"+
         "The Town of Rowan lies west of here along a dirt road";
*/
  return "A dusty trail begins to the north.\n"+
         "To the south you can see a long road with a guard post";
}

long(str) {
/*
    write("This is " + short() + ".\n");
    write(NAME + " is a spectacular wizard capable of any form of\n");
    write("mutilation or maiming to those who enter without leave.\n");
    write("The Keep is partially open for adventuring.  BEWARE!\n");
  if(str=="road" || str=="town" || str=="rowan" || str=="dirt road" ||
     str=="town of rowan") {
    write("You can see the town in the distance, it appears to be \n"+
          "adbandoned and the road impassable.\n");
    return 1;
  }
*/
  if(str=="trail" || str=="dusty trail") {
   write("A dry, worn, dusty dirt trail leading to the north.\n");
   return 1;
  }
  if(str) return 0;
  write(short()+"\n");
}

init() {
  add_action("north","north");
/*  
  add_action("west","west"); 
*/
  add_action("south","south");
}

/*
west() {
  write("A series of large trees have fallen across the road making it\n"+
        "impossible to pass.\n");
    return 1;
}
*/


south() {
   if (this_player()->query_level() < 21) {
      write("A series of large trees have fallen across the road making it\n"+
           "impossible to pass.\n");
      return 1;
   }
   call_other(this_player(),"move_player", 
      "south#players/molasar/sunndi/rooms/road1");
   return 1;
}


north() {
     call_other(this_player(),"move_player",
                    "north#players/molasar/UNDER/path1");
/*
   write("This area has been temporarily closed.\n");
*/
     return 1;
}



reset(arg) {
    object facade, ob, ob1;
/* 08/04/06 Earwax: taking this out til we fix it
    if(!arg) 
      call_other("/players/molasar/rowan/obj/clock","????");
*/
    ob = find_object("room/quest_room");
    if(!present("medallion", ob)) {
      ob1 = clone_object("obj/quest_obj");
      ob1->set_name("medallion");
      ob1->set_hint("Retrieve the lost medallion.\n"+
                    "See the wizard Galileo under the castle beyond the "+
                    "mountains.\nAsk him about the orc tunnels.\n");
      move_object(ob1, ob);
    }
    if (arg)
	return;
/*
    move_object(this_object(), "players/molasar/ad_ent");
*/
    move_object(this_object(), DEST);
/*
    call_other("/players/sandman/paladin/obj/boots","???");
*/
}
is_castle() { return 1; }
