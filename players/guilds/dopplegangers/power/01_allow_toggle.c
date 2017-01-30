/* Toggle allowing steps/summons */

status main(string str) {
  object badge;

  badge = present("V-GUILD", this_player());

  if (str) return 0;
  badge->toggle_allowem();
  write("Badge now set to " +
        (badge->query_allowem() ? "allow" : "block") +
        " steps and summons.\n");
  return 1;
}
