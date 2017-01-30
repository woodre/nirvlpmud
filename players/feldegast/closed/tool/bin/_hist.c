int do_cmd(string str) {
  object qt;
  object targ;
  if(!str) {
    write("Usage: hist <player>\n");
    return 1;
  }
  targ=find_player(str);
  if(!targ) {
    write("Player not present.\n");
    return 1;
  }
  qt=present("quicktyper",targ);
  if(!qt) {
    write("That person does not possess a quicktyper.\n");
    return 1;
  }
  qt->history();
  return 1;
}
