#define TPN this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int coins, open;
reset(arg) {
  if(arg) return;
  set_id("coinpurse");
  set_short("A lace coinpurse");
  set_long(
"A dainty coinpurse made of woven strands of silk tightly laced into a\n"+
"delicate pattern or representation of a white bird in flight on a blue\n"+
"background.  It has silver clasps at the top with two marques cut red\n"+
"amythyst jewel insets.  It has been passed from mother to daughter for\n"+
"over seven generations.  Mistress 'al Vere keeps her 'bread and milk'\n"+
"money inside.  Perhaps you could 'snatch' the coins from within.\n");
  set_value(500);
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
  if(arg == "coinpurse") {
    if(environment(this_object()) != this_player()) {
      notify_fail("You must get the coinpurse first!\n");
      return 0; }
    if(open) {
      notify_fail("You silly. The coinpurse is already open!\n");
      return 0; }
    write("You open up the coinpurse.\n");
    say(TPN+" opens up the coinpurse.\n");
    open = 1; return 1; }
  return 1; }

cmd_snatch(arg) {
  int x;
  if(!arg) {
    notify_fail("Syntax: 'snatch coins'\n");
    return 0; }
  if(arg == "coins") {
    if(environment(this_object()) != TP) {
    notify_fail("You must get the coinpurse first!\n");
    return 0; }
    if(!open) {
      notify_fail("You must open the coinpurse first!\n");
      return 0; }
    if(coins) {
     notify_fail("There are no more coins in the coinpurse!\n");
    return 0; }
    x = 100+random(50);
    write("You snatch "+x+" coins from the coinpurse!\n");
    say(TPN+" snatches some coins from a coinpurse!\n");
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
      notify_fail("You must get the coinpurse first!\n");
      return 0; }
    if(!open) {
       notify_fail("You silly. The coinpurse is already closed!\n");
      return 0; }
    write("You close up the coinpurse.\n");
    say(TPN+" closes up the coinpurse.\n");
    open = 0; return 1; }
  return 1; }
