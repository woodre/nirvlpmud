/* Toggle Guild channel */

#define CHAND "/bin/channel_daemon.c"

status main(string str) {
  object badge;

  badge = present("V-GUILD", this_player());

  if (str) return 0;
  if (badge->query_shaddup()) {
    badge->set_shaddup(0);
    CHAND->add_channel("dopplegangers", this_player());
    if (badge->query_faction("mystic"))
      CHAND->add_channel("dopplegangersM");
    if (badge->query_faction("barbarian"))
      CHAND->add_channel("dopplegangersB");
  } else {
    badge->set_shaddup(1);
    if (CHAND->query_channel("dopplegangers", this_player()))
      CHAND->remove_channel("dopplegangers", this_player());
    if (CHAND->query_channel("dopplegangersM", this_player()))
      CHAND->remove_channel("dopplegangersM", this_player());
    if (CHAND->query_channel("dopplegangersB", this_player()))
      CHAND->remove_channel("dopplegangersB", this_player());
  }
  return 1;
}
