/* Pet health monitor toggle */

status main(string str) {
  object badge;

  badge = present("V-GUILD", this_player());

  if (str) return 0;
  badge->toggle_monitor();
  write("Pet Health Monitor is now " +
        (badge->query_monitor() ? "on" : "off") +
        ".\n");
  return 1;
}
