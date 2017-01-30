inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("cheese")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/cheese.c"),this_object()); }}
if(!present("up")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/7_up.c"),this_object()); }}

short_desc = "The jejunum";
long_desc =
  "  This is the middle section of the small intestine.  It was formerly believed\n"+
  "to empty upon death and has various pieces of digesting food floating about.\n";

items = ({
  "food","Partly digested food taking on a grey appearance",
});

dest_dir = ({
  "players/eurale/Hippo/thin_colon1","northeast",
  "players/eurale/Hippo/blood3","blood",
  "players/eurale/Hippo/thin_colon3","south",
});

}
