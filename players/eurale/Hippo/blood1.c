inherit "room/room";
#define TO this_object()

reset(arg) {
  if(arg) return;
set_light(0);

if(!present("ery")) {
  move_object(clone_object("/players/hippo/c/ery.c"),this_object()); }
if(!present("leuco")) {
  move_object(clone_object("/players/hippo/c/leuco.c"),this_object()); }
if(!present("thrombo")) {
  move_object(clone_object("/players/eurale/Hippo/NPC/thrombo"),TO); }

short_desc = "A blood vessel";
long_desc =
  "  Swirling red liquid flows past at an amazing rate.  Small globules of yellow\n"+
  "occasionally pass by as well.\n";

items = ({
  "liquid","Creamy, red blood",
  "globules","These appear to be cholestoral",
});

dest_dir = ({
  "players/eurale/Hippo/liver","liver",
  "players/eurale/Hippo/stomac","stomach",
  "players/eurale/Hippo/aorta","up",
  "players/eurale/Hippo/blood2","down",
});

}
