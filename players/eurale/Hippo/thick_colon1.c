inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("cheese")){
  move_object(clone_object("/players/hippo/c/cheese.c"),this_object()); }
if(!present("bread_piece")){
  move_object(clone_object("/players/hippo/c/bread_piece.c"),this_object()); }
if(!present("nut")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/nut.c"),this_object()); }}
if(!present("up")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/7_up.c"),this_object()); }}

short_desc = "Thick ascending colon";
long_desc =
  "  Darker walls surround this area and small hard things float past.  The\n"+
  "smell of feces permeates the stagnant air.\n";

items = ({
  "walls","Smooth and dark intestine walls with tiny, hairlike fractures",
  "things","Looks like they could be small turds forming",
});

dest_dir = ({
  "players/eurale/Hippo/thin_colon3","west",
  "players/eurale/Hippo/thick_colon2","up",
  "players/eurale/Hippo/blood5","blood",
});

}
