inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);

if(!present("dna")){
  move_object(clone_object("/players/hippo/c/staphylococ.c"),this_object()); }
if(!present("something")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/something.c"),this_object()); }}

short_desc = "The rectum";
long_desc =
  "  Below this area is a small hole through which muted light is coming.  The\n"+
  "thick substance in this area is at a standstill and seems to be packing itself\n"+
  "tighter and tighter.\n";

items = ({
  "hole","It appears to be the body's anus",
  "substance","A fully formed turd being added to by the minute",
});

dest_dir = ({
  "players/eurale/Hippo/thick_colon3","up",
  "players/eurale/Hippo/blood8","blood",
  "room/jetty2","hole",
});

}
