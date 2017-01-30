#define TPN this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int coins, open;
reset(arg) {
  if(arg) return;
  set_id("purse");
  set_short("A coin purse");
  set_long(
"A soft leather coin purse closed with a drawstring of woven silver thread.\n"+
"Perhaps you could 'snatch coins' from the purse.\n");
  set_value(50);
  set_weight(1);
  }

init() {
  ::init();
  add_action("cmd_open","open");
  add_action("cmd_snatch","snatch");
  add_action("cmd_close","close");
  }

cmd_open(arg) {
  if(!arg) {
    notify_fail("Open what now?\n");
    return 0; }
  if(arg == "purse") {
    if(environment(this_object()) != this_player()) {
      notify_fail("You must get the purse first!\n");
      return 0; }
    if(open) {
      notify_fail("You dummy. The purse is already open!\n");
      return 0; }
    write("You open up the purse.\n");
    say(TPN+" opens up the purse.\n");
    open = 1; return 1; }
  return 1; }

cmd_snatch(arg) {
  int x;
  if(!arg) {
    notify_fail("Syntax: 'snatch coins'\n");
    return 0; }
  if(arg == "coins") {
    if(environment(this_object()) != TP) {
    notify_fail("You must get the purse first!\n");
    return 0; }
    if(!open) {
      notify_fail("You must open the purse first!\n");
      return 0; }
    if(coins) {
     notify_fail("There are no more coins in the purse!\n");
    return 0; }
    x = 1800+random(200);
    write("You snatch "+x+" coins from the purse!\n");
    say(TPN+" snatches some coins from a purse!\n");
    coins = 1;
    TP->add_money(x);
    return 1; }

  return 1; }
cmd_close(arg) {
  if(!arg) {
    notify_fail("Close what?\n");
    return 0; }
  if(arg == "purse") {
    if(environment(this_object()) != TP) {
      notify_fail("You must get the purse first!\n");
      return 0; }
    if(!open) {
       notify_fail("You dummy. The purse is already closed!\n");
      return 0; }
    write("You close up the purse.\n");
    say(TPN+" closes up the purse.\n");
    open = 0; return 1; }
  return 1; }

query_save_flag(){ return 1; }
