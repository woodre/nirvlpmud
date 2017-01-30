inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("cheese")){
  move_object(clone_object("/players/hippo/c/cheese.c"),this_object()); }
if(!present("contraction_wave")){
  move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object()); }
if(!present("up")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/7_up.c"),this_object()); }}
if(!present("nut")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/nut.c"),this_object()); }}

short_desc = "The ileum";
long_desc =
  "  This is the lowest part of the small intestine and leads into the large\n"+
  "intestine to the east.  The stench of decaying food is almost too much to\n"+
  "handle.\n";

dest_dir = ({
  "players/eurale/Hippo/thin_colon2","north",
  "players/eurale/Hippo/thin_colon4","west",
  "players/eurale/Hippo/blood4","blood",
  "players/eurale/Hippo/thick_colon1","east",
});

}
