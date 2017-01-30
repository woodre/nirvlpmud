 inherit "room/room";
 int i;
   reset(arg){
     if(!present("wraith")) {
       for(i=0;i<4;i++) {
    move_object(clone_object("players/arrina/monsters/dkwraith"),this_object());
       }
    }
    if(arg) return;
    set_light(0);
    short_desc=("Dark Chamber");
    long_desc=
    "This chamber has no distinct features other than a table that has\n"
 +  "been pushed against the wall, and broken glass in the floor.  The \n"
 +  "outside wall appears to have newer stones in it, and no outside light\n"
 +  "can get in.  The atmosphere is musty and dank, the air stale and \n"
 +  "fetid.  The gloom is overpowering.\n";
    items=
   ({
     "glass","Broken glass covers the floor, and seems like it might \n"
 +             "have at one time come from a window",
      "table","The table appears to be of good quality, but is now just \n"
 +             "a remnant of better days here",
    });
    dest_dir=
    ({
      "players/arrina/newbie/newbie2","west",
      "players/arrina/newbie/newbie5","north",
      });
 }
  init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
   write("You search through the room but find nothing.\n");
 say (this_player()->query_name() +" searches the room but finds nothing.\n");
   return 1;         }
