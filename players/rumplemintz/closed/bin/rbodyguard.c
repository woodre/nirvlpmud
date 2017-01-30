int rbodyguard(string str) {
  object bg, client;

  if (!str) {
    notify_fail("Usage: rbodyguard <who>\n");
    return 0;
  }
  client = find_player(str);
  if (!client) {
    notify_fail("Cannot find " + str + " currently.\n");
    return 0;
  }
  bg = (object)"players/padrone/inside/antonios"->make_bodyguard(client);
  if (!bg) {
    tell_object(this_player(), "Sorry, all bodyguards are busy.\n");
    return 1;
  }
  move_object(bg, environment(client));
  move_object(client, environment(client));
  move_object(bg, "players/padrone/inside/antonios");
  write(client->query_name() + " has been given a bodyguard at Atonio's!\n");
  tell_object(client, "Rumplemintz has arranged for you to have a bodyguard.\n" +
                   "Just go to Antonio's Personal Protection Service in Padrone's castle.\n");
  return 1;
}
