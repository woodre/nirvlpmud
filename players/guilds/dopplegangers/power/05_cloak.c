/*
 * Cloak
 * Hide the badge
 */

status main(string str) {
  object badge;

  if (str) return 0;
  badge = present("V-GUILD", this_player());
  badge->toggle_cloaked();
  write("Your Doppleganger guild badge is now " +
        (badge->query_cloaked() ? "cloaked" : "uncloaked") + ".\n");
  return 1;
}
