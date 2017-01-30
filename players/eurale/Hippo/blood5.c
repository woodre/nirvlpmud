inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("ery")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/ery.c"),this_object()); }}
if(!present("leuco")){
  move_object(clone_object("/players/hippo/c/leuco.c"),this_object()); }

short_desc = "A blood vessel";
long_desc =
  "  Rich red liquid swirling past on its way to other body parts.\n";

dest_dir = ({
  "players/eurale/Hippo/thick_colon1","colon",
  "players/eurale/Hippo/blood4","up",
  "players/eurale/Hippo/blood6","down",
});

}
