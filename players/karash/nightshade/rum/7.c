inherit "/players/nightshade/new_room";
reset(arg) {
if(arg) return;
  set_light(1);
  short_desc = "Trail";
  long_desc  =
"The small trail you are on runs east, west and north. To the east\n"+
"is the small cave you exited, while the northern trail turns into\n"+
"a small road, and the western trail ends right before another cave.\n";
dest_dir=
({
"/players/nightshade/rum/8", "east",
"/players/nightshade/rum/6", "west",
"/players/nightshade/rum/10", "north",
});
}
