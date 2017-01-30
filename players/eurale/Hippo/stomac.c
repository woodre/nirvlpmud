inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(1);
if(!present("contraction_wave")) {
  move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object()); }
if(!present("bread_piece")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/bread_piece.c"),this_object()); }}

short_desc = "The stomach";
long_desc =
  "  Although it's quite dark in here, you can see different things swirling\n"+
  "around in this wetness.  The lining that surrounds you is rough and red.\n"+
  "There are several unrecognizable things floating about.\n";

items = ({
  "things","They look like pieces of decaying food",
  "lining","This appears to be the lining of an irritated stomach",
});

dest_dir = ({
  "/players/eurale/Hippo/throat","up",
  "/players/eurale/Hippo/thin_colon1","south",
  "players/eurale/Hippo/blood1","blood",
});

}
