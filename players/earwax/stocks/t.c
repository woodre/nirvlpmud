void reset(status arg) {
  if (arg)
    return;

  present("stocks", environment(find_player("earwax")))->set_info("waxman", 90, "testing");
  present("stocks", environment(find_player("earwax")))->slappem_in(find_player("waxman"));
}
