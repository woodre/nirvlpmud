inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The circulosis Willosi";
long_desc =
  "  You are in the Circulosus Willosi, the central artery of the brain.\n";

dest_dir = ({
  "players/hippo/quest_1/brain","brain",
  "players/eurale/Hippo/carotis","carotis",
});

}
