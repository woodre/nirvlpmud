inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("something")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/something.c"),this_object()); }}
if(!present("up")){
  move_object(clone_object("/players/hippo/c/7_up.c"),this_object()); }
if(!present("nut")){
  move_object(clone_object("/players/hippo/c/nut.c"),this_object()); }
if(!present("staphylococ")){
  move_object(clone_object("/players/hippo/c/staphylococ.c"),this_object()); }

short_desc = "Descending colon";
long_desc =
  "  A thick, hardening substance is closing in on the whole area.  The stench\n"+
  "in the air is nauseating.\n";

items = ({
  "substance","Looks and feels like a big turd",
});

dest_dir = ({
  "players/eurale/Hippo/thick_colon2","west",
  "players/eurale/Hippo/rectum","down",
  "players/eurale/Hippo/blood7","blood",
});

}
