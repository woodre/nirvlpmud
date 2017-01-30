inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="Underground";
long_desc=
"In this chamber, pools of molten lava burn and bubble.  The air is\n"+
"thick with sulfur and the extreme heat makes you faint.  Tiny streamlets\n"+
"of lava run down the walls and across the rocky floor.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell1", "south",
});

if(!present("hell3_chest", this_object())) {
  move_object(clone_object("players/pavlik/items/ilstkarn/hell3_chest"),
  this_object());
}

   }
}

query_ilstkarn(){ return "hell3"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
