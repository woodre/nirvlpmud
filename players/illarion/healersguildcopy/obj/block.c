init() {
  add_action("nopes","raise");
}

nopes() {
  if(this_player()->query_guild_name() == "healer") {
    write("You must gotto your study to raise your attributes.\n");
    return 1;
  }
return 0;
}

get() { return 0; }
