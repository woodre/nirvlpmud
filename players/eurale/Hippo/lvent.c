inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("valvula")){
  move_object(clone_object("/players/hippo/c/valvula.c"),this_object()); }
if(!present("trabeculae")){
  move_object(clone_object("/players/hippo/c/trabeculae.c"),this_object()); }

short_desc = "Left ventricle";
long_desc =
  "  One of the lower chambers of the heart which receives blood from the\n"+
  "auricles and pumps it out into the arteries.\n";

dest_dir = ({
  "players/eurale/Hippo/latrium","north",
  "players/eurale/Hippo/aorta","northeast",
});

}
