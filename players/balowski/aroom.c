inherit "/room/room";
void reset(int arg) {
  long_desc = "The room of testing.\n";
  short_desc = "Hell";
  set_light(1);
}

int exit(object ob) {
  object bal;
  bal = find_player("balowski");
  if (bal) {
    tell_object(bal, "Exit is being called:\n");
    tell_object(bal, file_name(ob));
    tell_object(bal, "\n");
  }
  ob->clear_fight_area();
  return 0;
}
