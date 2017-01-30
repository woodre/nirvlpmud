/*
 * Toggle drain from hp to sp
 */

status main(string str) {
  object badge;

  badge = present("V-GUILD", this_player());
  if (str) return 0;
  badge->toggle_which_drain();
  write("Drain now set for " +
        (badge->query_which_drain() ? "SP" : "HP") +
        ".\n");
  return 1;
}
