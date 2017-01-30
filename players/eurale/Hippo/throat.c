inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("contraction_wave")){
  move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object()); }
short_desc = "A throat";

long_desc =
  "  You are surrounded by the contracting muscles of the throat.  The room\n"+
  "moves back and forth as the throat swallows different objects.  There are\n"+
  "openings both up and down from here.\n";

items = ({
  "muscles","Stretching and contracting tissues of the throat",
  "object","Pieces of food heading down into the stomach",
  "openings","Exits up into the mouth and farther down into the stomach",
});

dest_dir = ({
  "players/eurale/Hippo/mouth","climb",
  "players/eurale/Hippo/stomac","down",
});

}
