short() { return "Wizardchild's Hangout"; }
long() {
  write("A large cluttered room, with a lookout over all of Nirvana. There doesn't\n");
  write("appear to be anything special here, besides Wizardchild himself.\n");
  write("    There are five obvious exits: church, plane, advance, shop and guild\n");
  write("    post\n");
  return 1;
}
reset(arg) { if(arg) return 0; set_light(1); }
init() {
  add_action("church", "church");
  add_action("plane", "plane");
  add_action("post", "post");
  add_action("advance", "advance");
  add_action("shop", "shop");
  add_action("guild", "guild");
}
plane() {
  move_object(this_player(), "room/plane12");
  command("l", this_player());
  return 1;
}
shop() {
  move_object(this_player(), "room/shop");
  command("l", this_player());
  return 1;
}
advance() {
  move_object(this_player(), "room/adv_guild");
  command("l", this_player());
  return 1;
}
guild() {
  move_object(this_player(), "/players/wizardchild/closed/logger/room/g_hall");
  command("l", this_player());
  return 1;
}
church() {this_player()->move_player("church#room/church"); return 1; }
post() {
  this_player()->move_player("post office#room/post");
  return 1;
}
