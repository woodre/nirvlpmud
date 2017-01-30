 inherit "room/room";
 int i;
   reset(arg){
     if(!present("guard")) {
       for(i=0;i<2;i++) {
    move_object(clone_object("players/arrina/monsters/guard1"),this_object());
       }
    }
    if(arg) return;
    set_light(0);
    short_desc=("Dark Passageway");
    long_desc=
    "This room is a simple passageway to another section of the castle.\n"
 +  "To the west lies a portion of the main part of the castle, and\n"
 +  "although what you have seen so far speaks of wealth and power, now\n"
 +  "laid ruin, you sense that the true grandeur is yet to come.  You\n"
 +  "wonder what has caused this ever-present feeling of evil.\n";
     dest_dir=
    ({
      "players/arrina/newbie/newbie11","west",
      "players/arrina/newbie/newbie9","south",
      "players/arrina/newbie/newbie7","east",
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
