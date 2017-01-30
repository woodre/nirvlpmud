prepare_robomech() {
  call_out("load_robomech", 10);
  return 1; 
}

load_robomech() {
   if(!present("pavilion", find_object("room/plane8.c"))) {
    move_object(
      clone_object("players/dune/closed/pavilion/pavilion.c"),
      "/room/plane8.c");
      }
   return 1; 
}
