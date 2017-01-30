  id(str) { return str == "button" || str == "panicbutton" || str == "Mi361007"; }
short() { return "A portable panic button"; }

long() {
  write("This is a button you can push if you get REALLY lost in the\n"+
  "Plane of Etheriel. If you push it, provided you are not\n"+
  "fighting anything, will teleport you out of the realm.\n");
}

get() { return 1; }
drop() { return 1; }
query_save_flag() { return 1; }
query_value() { return 10; }

init() {
  add_action("pushme","push");
}

pushme(str) {
  string c_room_id;
string verify_me,verify_me_again;
  if(!str || str !="button") return 0;
  c_room_id=environment(this_player())->short();
  if(sscanf(c_room_id, "Plane of Etheri%s", verify_me) == 1 &&
       !this_player()->query_attack()) {
       say((this_player()->query_name())+" pushes a panic button and disappears.\n");
       this_player()->move_player("in a brilliant flash of goofiness#room/wild1");
       write("Ok.\nBlinded by a brillant flash of goofiness, you emerge elsewhere.\n");
       destruct(this_object());
       return 1;
  } else {
    write("Nothing happens.\n");
    return 1;
  }
}
