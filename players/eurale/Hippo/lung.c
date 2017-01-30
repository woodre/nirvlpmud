inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("tobacco")){
  move_object(clone_object("/players/hippo/c/tobacco.c"),this_object()); }
if(!present("hiv")){
  move_object(clone_object("/players/hippo/c/hiv.c"),this_object()); }

short_desc = "The lungs";
long_desc =
  "  Either of the two spongelike respiratory organs in the thorax of vertibrates\n"+
  "that oxygenate the blood and remove carbon dioxide from it.  Small, black spots\n"+
  "decorate the lining of this precious organ.\n";

items = ({
  "spots","Looks like tar build up from smoking",
});


dest_dir = ({
  "players/eurale/Hippo/artery","west",
  "players/eurale/Hippo/vein","north",
});

}
