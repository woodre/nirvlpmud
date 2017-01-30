inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc =   "A Spaceship"  ;
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/ship.c","push button",
"/room/farmroad3.c","out",
"room/farmroad3","out",
});
}
