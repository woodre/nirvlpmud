inherit "room/room";
int i;

reset(arg){
  if(arg) return;
set_light(0);
if(!present("cancer")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/calangerh.c"),this_object()); }}

short_desc = "Langerhans";
long_desc =
  "  This area is surrounded by irregular groups of cells that produce the hormone\n"+
  "insulin.  Their degeneration is believed to be a cause of diabetes mellitus.\n";

dest_dir = ({
   "/players/eurale/Hippo/pancreas.c","pancreas",
});

}
