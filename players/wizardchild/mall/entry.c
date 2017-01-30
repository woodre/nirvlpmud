/* entry.c: entry to the mall */
inherit "room/room";
reset(arg) {
  object dir;
  if(arg) return ;
  set_light(1);
  short_desc = "Entrance to the Mall";
  long_desc  =
 "You are standing in what appears to be an enormous shopping mall. Around\n"
+"you, many people walk to and fro various types of shops.\n"
+"There is a candy store to the east, and to the west is a Taco Bell.\n";
  dest_dir   =
  ({
  "/players/wizardchild/mall/candy", "east",
  "/players/wizardchild/mall/tacobell", "west",
  "/players/wizardchild/mall/main1", "south",
  "/room/vill_green", "out"
  });
  dir = clone_object("/players/wizardchild/mall/direc");
  move_object(dir, this_object());
}
