inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="The Lava Pit";
long_desc=
"You walk into a high domed cavern deep below the Earth's surface.\n"+
"There is a huge pit of molten lava in the center of this room.  The\n"+
"lava bubbles and pops quietly.  The cavern is very warm and beads of\n"+
"sweat run down your face.  Narrow passages lead off in several directions.\n"+
"A smaller corridor leads upwards to the underground lake.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell2", "west",
 "/players/pavlik/ilstkarn/hell3", "north",
 "/players/pavlik/ilstkarn/hell4", "northeast",
 "/players/pavlik/ilstkarn/corridor1", "up",
});

   }
}

query_ilstkarn(){ return "hell1"; }
realm(){ return "NT"; }


okay_follow() { return 1; }

