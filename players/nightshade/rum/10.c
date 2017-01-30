inherit "players/nightshade/new_room";
reset(arg) {
if(arg) return;
  set_light(1);
  short_desc = "Forest";
  long_desc  =
"The rough stone path beneath your feet becomes increasing smooth\n"+
"as you make your way north. Up further to the north you can see a sign.\n"+
"You seem to be entering the beginnings of a small villiage.\n";
dest_dir=
({
"players/nightshade/rum/11", "north",
"players/nightshade/rum/18", "west",
"players/nightshade/rum/7", "south",
});
}
