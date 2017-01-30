inherit "players/nightshade/new_room";
reset(arg) {
if(arg) return;
  set_light(1);
  short_desc = "Cave Entrance";
  long_desc =
"The bright sunlight assaults your now light sensitive eyes as you enter the\n"+
"mouth of the cave. When your eyes finally adjust to the light, you notice\n"+
"that the cave has exited near a forest. A clear worn path leads northeast/n"+
"to that forest. You notice another cave entrance to the west of you about\n"+
"20 feet.\n";
dest_dir=
({
"players/nightshade/rum/9", "south",
"players/nightshade/rum/f1", "northeast",
"players/nightshade/rum/7", "west",
});
}
