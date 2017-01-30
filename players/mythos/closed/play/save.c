id(str) { return str == "save"; }

init() { 
  if(this_player() == environment(this_object())) {
   this_player()->save_me(); } destruct(this_object()); }
