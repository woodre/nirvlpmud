 inherit "room/room";
 reset(arg){

    if(!arg){
    set_light(0);
    short_desc=("Dark Tunnel");
    long_desc=
    "You are deep within the earth.  Limestone formations drip \n" +
    "water from the ceiling.  The tunnel seems to twist and wind \n"+
    "back on itself.  The walls feel like they are closing in on \n" +
    "you.  The power of the earth all around you makes you feel \n" +
    "small and helpless and lost.  You sense the presence of \n" +
    "dark evil all around you.  This room seems different from \n"+
    "the other rooms you have been in....there seems to be some\n"+
    "form of construction going on here, and you wonder when it's\n"+
    "inhabitants may return to finish their work! \n";

    items= ({
 
     "walls","Damp and wet, the walls seem to be formed of some  \n" + 
             "strange combination of earth and stone",
      "ceiling","The limestone formations drip water, which forms \n" +
                "small puddles on the already damp floor",
    });

    dest_dir=
    ({
     
      "players/arrina/tunnel/tunnel12.c","south",
      
      });
 }
 }
  init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
   write("You search through the room but find nothing.\n");
 say (this_player()->query_name() +" searches the room but finds nothing.\n");
   return 1;         }

realm() { return "NT";}

