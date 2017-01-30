inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("cheese")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/cheese.c"),this_object()); }}
if(!present("something")){
  move_object(clone_object("/players/hippo/c/something.c"),this_object()); }

short_desc = "Transvers colon";
long_desc =
  "  Floating flotsam and jetsum surrounds you.  The matter of the thin colon\n"+
  "seems to be changing into something more solid and smelly.\n";

items = ({
  "flotsam","Floating materials of unrecognizable origin",
  "jetsam","Discarded particles of some food source",
});

dest_dir = ({
  "players/eurale/Hippo/thick_colon1","down",
  "players/eurale/Hippo/thick_colon3","east",
  "players/eurale/Hippo/blood6","blood",
});

}
