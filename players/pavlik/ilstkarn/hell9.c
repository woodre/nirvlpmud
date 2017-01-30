inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="At the Gate of Hells";
long_desc=
"You follow the cold dark passageway deeper into the bowels of the Earth.\n"+
"The corridor leads you to a smll round chamber.  Unlike the other rooms,\n"+
"this chambers walls have been carefully sculpted, and the floor is smooth\n"+
"and polished.  A closer look at the walls reveals numerous grotesque\n"+
"statues each of which appears to be ready to leap from the wall and kill.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell8", "south",
});

items=({
"statues",
"Many horrible and threatening statues have been carved into the walls\n"+
"of this chamber.  The statues are disfigured and shocking in appearance.\n"+
"The might be the countenance of some devil",
"wall",
"Many horrible and threatening statues have been carved into the walls\n"+
"of this chamber.  The statues are disfigured and shocking in appearance.\n"+
"The might be the countenance of some devil",
"statue",
"Many horrible and threatening statues have been carved into the walls\n"+
"of this chamber.  The statues are disfigured and shocking in appearance.\n"+
"The might be the countenance of some devil",
});

if(!present("lancoz_lich", this_object())) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/lich"),
  this_object());
}

if(!present("lich_gate", this_object())) {
  move_object(clone_object("players/pavlik/items/ilstkarn/lich_gate"),
  this_object());
}

   }
}

clean_up() { return 0; }   /* do not dest this room */
query_ilstkarn(){ return "hell9"; }
query_nofollow(){ return 1; }
realm(){ return "NT"; }

