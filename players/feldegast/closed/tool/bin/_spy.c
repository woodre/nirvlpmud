int do_cmd(string str) {
  object targ;
  if(!str) return 0;
  if(str=="on cybers") {
    "/players/dune/closed/guild/daemons/channels"->viewhistory();
    return 1;
  }
  targ=find_player(str);
  if(!targ) {
    notify_fail("Usage: spy <player>\n");
    return 0;
  }
  targ->write_tellhistory();
  return 1;
}
