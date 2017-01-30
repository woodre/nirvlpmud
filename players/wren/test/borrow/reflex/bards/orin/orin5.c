#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Wine Celler";
long_desc=
 "You stand in the wine cellar of Orin's Inn.  The room is dimly lit by a\n"+
 "single flickering torch which casts strange shadows about the chamber.\n"+
 "There are many racks filled with bottles of fine wine, and three large\n"+
 "casks full of Orin's renown Dark Ale.  A small staircase runs up to the\n"+
 "cloak room above.\n";

items=({
 "torch","A single flickering torch",
 "room","The wine cellar of Orin's Inn",
 "wine","Many bottles of fine wine.  But you wouldn't steal one, would you?",
 "cellar","The wine callar of Orin's Inn",
 "racks","Many racks filled with bottles of fine wine",
 "rack","Many racks filled with bottles of fine wine",
 "casks","Three casks full of Orin's renown Dark Ale",
 "cask","One of three casks filled with Orin's renown Dark Ale",
 "staircase","A staircase running up to the cloak room",
 "floor","The floor is made from a beautiful mahogany wood",
 });

  dest_dir=({
 "/players/reflex/guilds/bards/orin/orin1.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
