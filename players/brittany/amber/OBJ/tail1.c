inherit "/obj/treasure";
 
reset(arg){
if(arg)return;
 
  set_id("zoog's tail");
  set_alias("tail");
  set_short("A zoogs tail");
  set_long(
    "     The broken tail of a zoog.  A merchant will give you\n"+
    "a decent price if you 'trade' it with him.\n");
  set_weight(2);
  set_value(250+random(250));
}
init() {
  ::init();
  add_action("cmd_cash","trade");
}
cmd_cash(str) {
  if(!str || str!="tail") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
  notify_fail("There is nobody here who wants to trade that.\n");
  return 0;
  }

write("The merchant looks over your item, then trades you "+(value+375)+"\n"+
      "coins which is fair market value.\n");
  this_player()->add_money(value+375);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
