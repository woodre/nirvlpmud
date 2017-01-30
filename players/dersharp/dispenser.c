inherit"obj/treasure";
reset(arg){
if(arg) return;
set_id("dispenser");
set_short("A dispenser");
set_long("Map Dispenser...\n"+
   "Push button to recieve a map of Nirvana!\n");
}
get(){
return 0;
}
init() {
  add_action("push", "push");
}
push(str) {
object map;
  if(str != "button") {
    write("Push what?\n"); return 1; }
  map = clone_object("players/dersharp/map");
  move_object(map, this_player());
  write("You recieve a map from the machine.\n");
  say(this_player()->query_name()+
" pushes the button on the machine and recieves a map.\n");
  return 1;
}
