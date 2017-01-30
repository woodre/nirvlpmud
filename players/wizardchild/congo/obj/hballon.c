#define NOTUP 1
#define IDLE 120
string dest;
object home;
short() { return "A hot air balloon"; }
id(str) { return str == "balloon" || str == "hot air balloon"; }
get()   { 
  write("Before it gets you?\n");
  return 0; 
}
reset(arg) { if(!arg) call_out("delayed_reset",2); }
delayed_reset() {
  if(environment(this_object())) home = environment(this_object());
  dest = "our destination";
#ifndef NOTUP
  call_out("idle_move",IDLE);
#endif
}
long()  {
  if(!present(this_player(),this_object())) {
    write("A hot air balloon. If you wish, it can take you to or from the Congo.\n");
    write("Type \"board balloon\" to board it.\n");
  } else {
    write("You are standing inside of a floating hot air balloon. You should arrive\n");
    write("at "+dest+" any minute now.\n");
  }
}
init() {
  if(present(this_player(),this_object())) 
    add_action("leave","leave");
  else
    add_action("board","board");
}
leave(str) {
  if(!id(str)) {
  return 0; /* doh, it needs 3 lines... fuck i'm quick tonight */
  }
  write("You leave the balloon.\n");
  this_player()->move_player("the balloon#"+file_name(environment(this_object())));
  return 1;
}
board(str,flag) {
  if(!id(str)) return 0;
  if(!flag) {
    write("You board the hot air balloon.\n");
    this_player()->move_player("balloon#"+file_name(this_object()));
  }
  remove_call_out("idle_move");
  if(creator(environment(this_object())))
    dest = "Nirvana";
  else 
    dest = "the Congo";
  call_out("launch", 3);
  write("We will be taking off shortly.\n");
  return 1;
} 
launch() {
  tell_room(this_object(), "The hot air balloon lifts off.\n");
  tell_room(environment(this_object()), "The hot air balloon lifts off.\n");
  move_object(this_object(),"/room/void"); /* makes a good temp place */
  call_out("middle", 3);
}
middle() {
  tell_room(this_object(), "Drifting...\n");
  call_out("land",3);
}
land() {
  tell_room(this_object(), "We have arrived at "+dest+".\n");
  if(dest == "Nirvana") 
    move_object(this_object(),"/room/vill_track");
  else
    move_object(this_object(),home);
  tell_room(this_object(), "Type \"leave balloon\" to leave.\n");
  call_out("idle_move", IDLE);
}
idle_move() {
  while(remove_call_out("idle_move") != -1) ;
  board("balloon",1);
}
