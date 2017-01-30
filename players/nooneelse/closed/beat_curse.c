/*
  beat_curse.c - totally rude curse
*/

object my_player;

id(str) { return str=="curse" || str=="beat curse"; }

get() { return 1; }

drop() { return 1; }

init() {
  add_action("trap_command");add_xverb("");
}

/* trap all commands */
trap_command(str) {
  int i, j;

  if (!environment(this_object())) { destruct(this_object()); }
  if (!this_player()) return;
  if (this_player() != environment(this_object())) return;

  if (str=="destcurse") { destruct(this_object()); return 1; }


  my_player = this_player();
  write(
           capitalize(my_player->query_name())+
           " sits in a closet & starts playing with "+
           my_player->query_objective()+"self...\n");
  call_out("beat1", 5);
}

beat1() {
  write(
           "The action starts to speed up as "+my_player->query_name()+
           " starts to breathe heavy...\n");
  call_out("beat2", 5);
}

beat2() {
  write(
           my_player->query_name()+" continues, faster and faster!  "+
           my_player->query_name()+" starts to sweat...\n");
  call_out("beat3", 5);
}

beat3() {
  write(
           my_player->query_name()+" screams uh!  UH!  UUUHHHH!\n");
}
