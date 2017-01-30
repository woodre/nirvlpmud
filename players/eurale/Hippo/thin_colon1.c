inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("cheese")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/cheese.c"),this_object()); }}
if(!present("bread_piece")){
  move_object(clone_object("/players/hippo/c/bread_piece.c"),this_object()); }
if(!present("up")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/7_up.c"),this_object()); }}

short_desc = "A duodenum";
long_desc =
  "  This is the duodenum, the first part of the small intestine.  You see many\n"+
  "pieces of things floating around and are probably pieces of digesting\n"+
  "food.\n";

items = ({
  "pieces","Particles of food in different stages of digestion",
});

dest_dir = ({
  "players/eurale/Hippo/stomac","north",
  "players/eurale/Hippo/blood2","blood",
  "players/eurale/Hippo/thin_colon2","southwest",
});

}
