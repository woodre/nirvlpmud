quest_ok(next_lvl) {
  string which;
  if(next_lvl==6 && !this_player()->query_quests("grail")) which="Grail";
  else if(next_lvl==11 && !this_player()->query_quests("protoculture"))
    which="Protoculture";
  else if(next_lvl==16 && !this_player()->query_quests("galileo"))
    which="Galileo";
  else return 1;
  write("You need to do the "+which+" quest before reaching that level.\n");
  return 0;
}
