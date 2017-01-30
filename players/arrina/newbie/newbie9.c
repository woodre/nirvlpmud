 inherit "room/room";
 int i;
   reset(arg){
     if(!present("guard")) {
       for(i=0;i<2;i++) {
    move_object(clone_object("players/arrina/monsters/guard"),this_object());
       }
    }
    if(arg) return;
    set_light(0);
    short_desc=("Meeting Room");
    long_desc=
    "This room appears to have been used as a meeting room for the\n"
 +  "former guards of the castle.  The tables have benches instead of \n"
 +  "chairs, and as elsewhere, everything is in disarray.  You wonder \n"
 +  "what could have caused the downfall of a place as fortified and \n"
 +  "well cared for as this castle obviously once was.\n";
     items=
   ({
     "benches","The benches look like they have seen years of use and\n"
 +             "have an occasional name or saying carved into them",
      "tables","The tables are heavy and of good quality, but show scars\n"
 +             "from the weapons of the guards who used them",
     });
    dest_dir=
    ({
      "players/arrina/newbie/newbie10","west",
      "players/arrina/newbie/newbie8","north",
      "players/arrina/newbie/newbie2","south",
      "players/arrina/newbie/newbie5","east",
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
