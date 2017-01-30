inherit "room/room";
#define TO this_object()

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("ery")){
  move_object(clone_object("/players/hippo/c/ery.c"),this_object()); }
if(!present("thrombo")){
  move_object(clone_object("/players/eurale/Hippo/NPC/thrombo"),TO); }
if(!present("hiv")){
  move_object(clone_object("/players/hippo/c/hiv.c"),this_object()); }

short_desc = "A blood vessel";
long_desc =
  "  Swirling red liquid gushes past heading out to other organs in the body.\n";

dest_dir = ({
  "players/eurale/Hippo/thick_colon2","colon",
  "players/eurale/Hippo/blood5","up",
  "players/eurale/Hippo/blood7","down",
});

}
