 inherit "room/room";
 reset(arg){
   if(!present("qurd")) {
 move_object(clone_object("/players/arrina/tmon/qurd1.c"),this_object());
 }

    if(!arg){
    set_light(0);
    short_desc=("Dark Tunnel");
    long_desc=
    "You are deep within the earth.  Limestone formations drip \n" +
    "water from the ceiling.  The tunnel seems to twist and wind \n"+
    "back on itself.  The walls feel like they are closing in on \n" +
    "you.  The power of the earth all around you makes you feel \n" +
    "small and helpless and lost.  You sense the presence of \n" +
    "dark evil all around you.\n";

    items= ({
 
     "walls","Damp and wet, the walls seem to be formed of some  \n" + 
             "strange combination of earth and stone",
      "ceiling","You see, through a tiny crack, a very small bit \n" +
                "of light leading to the open air above the cave",
    });

    dest_dir=
    ({
      "players/arrina/tunnel/tunnel6.c","west",
      "players/arrina/tunnel/tunnel9.c","east",
      "players/arrina/tunnel/tunnel3.c","south",
      "players/arrina/tunnel/tunnel3.c","north",
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


