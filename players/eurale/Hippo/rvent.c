inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("contraction_wave")){
  move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object()); }
if(!present("valvula")){
  move_object(clone_object("/players/hippo/c/valvula.c"),this_object()); }
if(!present("trabeculae")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/trabeculae.c"),this_object()); }}

short_desc = "Right ventricle";
long_desc =
  "  One of the lower chambers of the heart that recieves blood from the\n"+
  "auricles and pumps it out into the arteries.\n";

dest_dir = ({
  "players/eurale/Hippo/ratrium","north",
  "players/eurale/Hippo/artery","down",
});

}
