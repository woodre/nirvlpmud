inherit "room/room";

int dug;
 
reset(arg){

dug = 0;
  if(!present("hermit"))
    move_object(clone_object("/players/snow/MONSTERS/dhermit.c"), this_object());
 
 if(!arg){
 
 set_light(0);
  short_desc="In the cave";
 long_desc=
 "You find yourself in a small, dank chamber. The tons of earth crowd in \n\
above you like a leaden shroud. To make matters slightly more disturbing, \n\
a wickedly cold draft swirls lazily about your legs.\n";
 
items=({
 "walls", "The walls of this room appear unnaturally hewn from the stone",
  });
 
  dest_dir=({
  "/players/snow/ROOMS/cave1.c","northwest",
 });
  }   }
 
init()  {
 ::init();
  add_action("search_room","search");
  add_action("dig","dig");
}
 
search_room() {
  write("You search the room but find nothing of value.\n");
  say (this_player()->query_name() +"searches the room in vain.\n");
  return 1;  }

dig() {
  object mon;
  mon = clone_object("/obj/money");
  if(present("hermit")) {
    write("The Hermit kicks you!\n");
  this_player()->hit_player(random(10)+10);
  return 1; }
  else write("You dig into the wet dirt...\n\n");
  if(dug) { write("\tYou find nothing.\n"); return 1; }
  write("\tYou find a cache of coins!\n");
  mon->set_money(random(3000)+3000);
  move_object(mon, this_object());
  dug = 1;
  return 1; }
