inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="The Lava Tunnels";
long_desc=
"You walk through the lava tunnels, far below the surface of the world.\n"+
"A river of hot, bubbling lava slowly churns through the underground\n"+
"cavern.  The air is hot and thick with the smell of sulfur.  The lava's\n"+
"red glow casts evil shadows everywhere about you.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell5", "west",
 "/players/pavlik/ilstkarn/hell8", "north",
 "/players/pavlik/ilstkarn/hell4", "southwest",
});

if(!present("salamander", this_object())) {
  int x;
  x = 2 + random(3);
  for(x=1+random(4); x>0; x--) {
    move_object(clone_object("players/pavlik/monsters/ilstkarn/salamander"),
    this_object());
  }
}

   }
}

query_ilstkarn(){ return "hell6"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
