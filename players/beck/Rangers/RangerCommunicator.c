init() {
  if(this_player() && present(this_object(), this_player())) {
    move_object(clone_object("/players/guilds/Rangers/RangerCommunicator"), this_player());
    destruct(this_object());
    return;
  }
}
