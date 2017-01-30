inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The lung artery.";
long_desc =
  "  One of the many branching tubes that carry blood from the heart to all the\n"+
  "other parts of the body.\n";

dest_dir = ({
  "players/eurale/Hippo/lung","east",
  "players/eurale/Hippo/rvent","up",
});

}
