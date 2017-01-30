main() {
  if(previous_object()->QMKChallenge()) {
    command("forfeit",this_player());
  }
  previous_object()->save_me();
}
