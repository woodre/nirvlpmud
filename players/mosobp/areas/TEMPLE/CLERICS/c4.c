inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A hallway";
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/TEMPLE/CLERICS/c2.c","southwest",
"players/mosobp/areas/TEMPLE/CLERICS/c3.c","southeast",
"players/mosobp/areas/TEMPLE/CLERICS/c5.c","north",
});
}

