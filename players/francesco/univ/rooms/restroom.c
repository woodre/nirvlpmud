#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Restroom";
long_desc =
   "    In the restroom area there are some doors leading to private\n"+
   "booths for  ....ahemm....  for your personal needs.  A long mirror\n"+
   "facing a series of washers and a dispenser hanging onto a wall are\n"+
   "the other items in here.  This room is very clean and well maintained.\n"+
   "The hygiene is important.\n";

items = ({
   "dispenser","A towel dispenser, likely to dry your hands",
   "mirror","You see yourself in it",
   "washer","With warm and cold water plumbing",
});

dest_dir = ({
  "/players/francesco/univ/rooms/corridor3","north",
  "/players/francesco/univ/rooms/booth10.c","south", 
  "/players/francesco/univ/rooms/booth11.c","southeast",
  "/players/francesco/univ/rooms/booth12.c","southwest",
  "/players/francesco/univ/rooms/booth13.c","east",
  "/players/francesco/univ/rooms/booth14.c","west",
  "/players/francesco/univ/rooms/booth15.c","northeast",
  "/players/francesco/univ/rooms/booth16.c","northwest",

});

}
