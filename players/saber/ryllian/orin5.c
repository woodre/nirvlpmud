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
 "The once full wine racks are laying at your feet in a pile of broken\n"+
 "wood and smashed bottles. A small staircase runs up to the cloak room above.\n";

  dest_dir=({
 "/players/saber/ryllian/orin1.c","up",
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
