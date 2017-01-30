inherit "room/room";
 
reset(arg){
 
if(!present("killer whale 2"))  {
move_object(clone_object("/players/snow/MONSTERS/killer_whale"),this_object());  }
if(!present("arctic seal 2")) {
move_object(clone_object("/players/snow/MONSTERS/arctic_seal"),this_object()); }
 
 if(!arg){
 
 set_light(1);
  short_desc="In the surf";
 long_desc=
 "You stand in the ice-cold surf of an arctic beach.\n"+
"Though the waves crash against your thighs where you are standing now, you think it would be \n"+
"possible to swim out to a ship you see a little further out.\n";
 
items=({
 "sun", "The sun is bright but doesn't seem to warm you much",
 "rocks","Jagged rocks beaten by the surf",
 "surf","Waves crash upon the shore",
 "waves","Frothy white water tops crystal clear water in the waves...",  
 "ship","If you swam out to it you could 'sail dock'... who knows what \n"+
        "would happen then...",
  });
 
  dest_dir=({
  "/players/snow/beach/beach2","beach",
  "/players/snow/beach/surf1","south",
});
  }   }

init() {
  ::init();
add_action("sail_dock","sail");
add_action("swim","swim");
}

sail_dock(arg) {
  if(!arg) { write("sail where?\n"); return 1; }
  if(arg == "dock") {
    write("You swim out to the ship and set sail for a far shore...\n");
    say(capitalize(this_player()->query_name())+ 
       " swims out to a ship and sets sail for a far shore...\n");
    call_other(this_player(),"move_player","on a ship#players/beck/room/pier1");
  return 1;
  }
}

swim(arg) {
  if(!arg) {
    write("You splash around in the surf!\n"+"\n"+
          "It is damn cold!\n");
    say(capitalize(this_player()->query_name())+ 
       " splashes around in the surf!\n");
    return 1;
  }
  if(arg == "ship") { write("Look at the ship...\n"); return 1; }
}
