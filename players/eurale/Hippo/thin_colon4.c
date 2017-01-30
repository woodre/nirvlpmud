inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("thrombo")){
  move_object(clone_object("/players/hippo/thrombo.c"),this_object()); }
if(!present("nut")){
  move_object(clone_object("/players/hippo/c/nut.c"),this_object()); }
if(!present("staphylococ")){
  move_object(clone_object("/players/hippo/c/staphylococ.c"),this_object()); }

short_desc = "The appendix vermiformis";
long_desc =
  "  The colon ends here.  A small accumulation of undigested matter swirls\n"+
  "about the area coating the space with an oil, sickening layer.\n";

items = ({
  "matter","Grey, putrid material that was once probably food",
});

dest_dir = ({
  "players/eurale/Hippo/thin_colon3","east",
});

}
