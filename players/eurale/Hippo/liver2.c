inherit "room/room";
int i;

reset(arg){
  if(arg) return;
set_light(0);

if(!present("cancer")) {
  move_object(clone_object("/players/hippo/c/cahepar.c"),this_object()); }

short_desc = "The liver";
long_desc =
  "  Cancer invades the healthy, red tissue around you making it grotesque.\n"+
  "The once healthy liver is doomed to die from its current condition.\n";

items = ({
  "cancer","Red festering pockets of tissue feeding upon itself",
  "tissue","Blistered and dying, it is an ugly sight",
});

dest_dir = ({
   "/players/eurale/Hippo/liver.c","liver",
	});
}
