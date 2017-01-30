object owner;
search() {
  if(this_player()->query_level()==19) {
    write("As you search the room you find a secret entrance leading down.\n");
    write("Feeling brave you decide to enter it!\n");
    owner = this_player()->query_name();
    move_object(this_player(),"players/grimm/caverns/cavern1");
    return 1;
  }
  else write("Sorry, only level 19 players can solve this quest.\n");
  return 1;
}
setowner(str) {
  if(!str) return owner;
  owner = str;
  return owner;
}
