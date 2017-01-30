inherit "/room/room";
int locked;

reset(arg) {
  if(arg) return;
  locked=1;
  short_desc = "Grimm's Solitude Room: Shhhhhh";
  long_desc = "This is Grimm's Solitude Room.\nShhhhhh!\n";
}

init() {
  if(this_player()->query_real_name()!="grimm" && locked)
    { write("Grimm is busy!\n");
      move_object(this_player(),"/room/church");
      command("look",this_player());
      return 1;
    }
  add_action("lock","lock");
  ::init();
}

lock() {
  if(locked) {
    write("Room Unlocked.\n");
    locked=0;
  }
  else {
    write("Room Locked.\n");
    locked=1;
  }
  return 1;
}
