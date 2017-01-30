inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("contraction_wave")){
  move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object()); }
if(!present("valvula")){
  move_object(clone_object("/players/hippo/c/valvula.c"),this_object()); }
if(!present("trabeculae")){
  move_object(clone_object("/players/hippo/c/trabeculae.c"),this_object()); }

short_desc = "Left atrium";
long_desc =
  "  One of the auricle chambers that pumps blood throughout the body.\n";

dest_dir = ({
  "players/eurale/Hippo/lvent","south",
  "players/eurale/Hippo/vein","down",
});

}
