
heart_beat() {
  int i;
  string feedme;
  feedme=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
  command(feedme, this_object());
    if(this_player()->query_attack() && 1 == random(4)) this_object()->run_away();
  ::heart_beat();
}
