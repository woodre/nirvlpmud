inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="In a Tunnel";
long_desc=
"This underground corridor leads farther down into the bowels of\n"+
"the Earth.  A red glow can be seen further down the tunnel, and the\n"+
"underground lake is behind you to the south.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell1", "down",
 "/players/pavlik/ilstkarn/beach1", "south",
});

   }
}

query_ilstkarn(){ return "cavern1"; }
realm(){ return "NT"; }

okay_follow() { return 1; }
