inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("hiv")){
  move_object(clone_object("/players/hippo/c/hiv.c"),this_object()); }

short_desc = "A blood vessel";
long_desc =
  "  Swirling red liquid moving slowly along as it nears its organ destination.\n";

dest_dir = ({
  "players/eurale/Hippo/rectum","rectum",
  "players/eurale/Hippo/blood7","up",
  "players/eurale/Hippo/ratrium","heart",
});

}
