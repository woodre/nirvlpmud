inherit "room/room";
#define TO this_object()
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("ery")){
  move_object(clone_object("/players/hippo/c/ery.c"),this_object()); }
if(!present("leuco")){
  move_object(clone_object("/players/hippo/c/leuco.c"),this_object()); }
if(!present("thrombo")){
  move_object(clone_object("/players/eurale/Hippo/NPC/thrombo"),TO); }

short_desc = "A blood vessel";
long_desc =
  "  Swirling red liquid swishes past going to feed the other parts of the body.\n";

items = ({
  "liquid","Healthy red blood... A- it would appear",
});

dest_dir = ({
  "players/eurale/Hippo/thin_colon2","colon",
  "players/eurale/Hippo/blood2","up",
  "players/eurale/Hippo/blood4","down",
});

}
