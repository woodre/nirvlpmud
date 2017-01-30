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
  "  Swirling red liquid pumps past at an alarming rate.  Small white cells also\n"+
  "stream past on their way through the body.\n";

items = ({
  "liquid","Oxygen enriched blood on its way to the body parts",
  "cells","Oxygen not completely absorbed in the blood",
});

dest_dir = ({
  "players/eurale/Hippo/liver","liver",
  "players/eurale/Hippo/thin_colon1","colon",
  "players/eurale/Hippo/blood1","up",
  "players/eurale/Hippo/blood3","down",
});

}
