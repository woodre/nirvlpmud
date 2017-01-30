id(str) { return str == "chan"; }
init() {
  add_action("removechannel","removechannel");
  add_action("addchannel","addchannel"); }
addchannel() {
  "/players/dune/closed/guild/daemons/channels.c"->add_listener(this_player());
  return 1; }
removechannel() {
  "/players/dune/closed/guild/daemons/channels.c"->remove_listener(this_player());
  return 1; }
