inherit "room/room";
reset(arg) {
  if(arg)  return;

short_desc = "A hallway";
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/TEMPLE/CLERICS/c4.c","south",
"players/mosobp/areas/TEMPLE/CLERICS/c6.c","west",
"players/mosobp/areas/TEMPLE/CLERICS/c7.c","east",
"players/mosobp/areas/TEMPLE/CLERICS/c8.c","northwest",
"players/mosobp/areas/TEMPLE/CLERICS/c9.c","northeast",
});
}
