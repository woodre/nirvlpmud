/*
 * Renew the guild object, get a new one
 */

varargs status main(string str) {
  object currbadge, newbadge;

  if (!str) {
    currbadge = present("V-GUILD", this_player());
    if (!currbadge)
      return 0;
    if (this_player()->query_attack()) {
      write("It wouldn't really be a good idea to renew while in combat.\n");
      return 1;
    }
    if (currbadge->query_shift_flag()) {
      write("You are still concentrating on shifting! Wait a second.\n");
      return 1;
    }
    currbadge->save_me(1);
    newbadge = clone_object("/players/guilds/dopplegangers/guildob");
    newbadge->set_res_time(currbadge->query_res_time());
    newbadge->set_last_read(currbadge->query_last_read());
    newbadge->set_bz_time(currbadge->query_bz_time());
    newbadge->set_gate(1, currbadge->query_gate(1));
    newbadge->set_gate(2, currbadge->query_gate(2));
    newbadge->set_gate(3, currbadge->query_gate(3));
    newbadge->set_gate(4, currbadge->query_gate(4));
    newbadge->set_gate(5, currbadge->query_gate(5));
    newbadge->set_g(1, currbadge->query_g(1));
    newbadge->set_g(2, currbadge->query_g(2));
    newbadge->set_g(3, currbadge->query_g(3));
    newbadge->set_g(4, currbadge->query_g(4));
    newbadge->set_g(5, currbadge->query_g(5));
    move_object(newbadge, this_player());
    newbadge->reset();
    newbadge->change_me("1");
    newbadge->change_me("1");
    destruct(currbadge);
    write("Your badge has been renewed.\n");
    return 1;
  }
  return 0;
}
