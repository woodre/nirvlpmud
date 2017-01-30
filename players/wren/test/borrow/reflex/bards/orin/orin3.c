#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(arg){
if(!present("sign")) {
move_object(clone_object("/players/saber/food/orinbar.c"),this_object());
}
if(!present("man")) {
move_object(clone_object("/players/saber/monsters/orintender.c"),this_object());  }
if(!present("johnathin"))  {
move_object(clone_object("/players/reflex/guilds/bards/johnathin.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Orin's Bar";
long_desc=
 "You are standing at the bar, a beautiful construct fashioned of a dark\n"+
 "mahogany wood.  Behind the bar is a large collection of exotic liquors,\n"+
 "each hidden within an enticing dark glass container.  A sign made of the\n"+
 "same dark mahogany wood is embedded into the eastern wall.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "bar","A beautiful construct fashioned of dark mahogany wood.\n"+
 "It is well polished",
 "liquors","A large collection of exotic drinks",
 "wall","There is a sign on the wall",
 "containers","A large collection of enticing looking dark glass containers",
 });

  dest_dir=({
 "/players/reflex/guilds/bards/orin/orin2.c","south",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
