inherit "room/room";
reset(arg) {
  if(arg) return;
set_light(0);
short_desc = "A lung vein.";
long_desc =
  "  This is the only vein in the body that contains fresh blood with oxygen\n"+
  "to nourish and sustain the organs.\n";

dest_dir = ({
  "players/eurale/Hippo/latrium","up",
  "players/eurale/Hippo/lung","south",
   });
}
