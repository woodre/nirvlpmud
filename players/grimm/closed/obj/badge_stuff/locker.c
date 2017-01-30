inherit "room/room";
reset(arg) {
  if(arg) return;
  short_desc="Dopplegangers guild room-locker";
  long_desc="Here is the following inventory of the guild room:\n";
  set_light(1);
}

realm() { return "NT"; }

init() {
  object ob;
  say(this_player()->query_name()+"\n");
  if(this_player()->query_name()!="grimm") {
    write("You are not allowed in this room.\n");
    move_object(this_player(),"room/church");
    if(find_living("grimm"))
      tell_object(find_living("grimm"),this_player()->query_real_name()+" tried to enter the guild room.\n");
    }
  ::init();
}

