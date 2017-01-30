object room;
id(str) { return str == "summons"; }
set_room(ob) { 
  room = ob;
  call_out("destme", 120);
}
init() {
add_action("accept","accept");
}
short(){return "A summons"; }
long(){write("A summons to Templar Castle.\n"); return 1;}
accept(){
  write("You accept the summons.\n");
  if(call_other(environment(this_player()), "realm", 0 == "NT")) {
    write("You cannot be summoned from here.\n");
    destruct(this_object());
    return 1;
   }
  tell_room(environment(this_player()), this_player()->query_name() + 
  " vanishes in a bright flash of light.\n");
  move_object(this_player(),room);
  tell_room(room, this_player()->query_name() + " arrives in a flash of light.\n");
  destruct(this_object());
  return 1;
}
drop(){
  write("The summons vanishes as it reaches the ground.\n");
  destruct(this_object());
  return 1;
}
destme() {
  write("The summons dissolves into a wet paper mush.\n");
  destruct(this_object());
  return 1;
}
