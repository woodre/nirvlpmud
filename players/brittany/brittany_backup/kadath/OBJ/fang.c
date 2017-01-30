inherit "/obj/treasure.c";

reset(arg){
if(arg)return;
 
  set_id("gug's fang");
  set_alias("fang");
  set_short("A gug's fang");
  set_long(
"This is a bloody fang from the mouth of that ugly gug.\n"+
"A merchant might 'trade' it for a decent price.\n");
  set_weight(3);
  set_value(250+random(250));
}
init() {
  ::init();
  add_action("cmd_cash","trade");
}
cmd_cash(str) {
  if(!str || str!="fang") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
  notify_fail("There is nobody here who wants to trade that.\n");
  return 0;
  }

write("The merchant looks over your item, then trades you "+(value+800)+"\n"+
      "coins which is a fair price.\n");
  this_player()->add_money(value+800);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
