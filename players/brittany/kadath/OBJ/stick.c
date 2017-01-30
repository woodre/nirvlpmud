inherit "/obj/treasure.c";

object item;
reset(arg){
if(arg)return;
 
  set_id("stick");
  set_alias("stick");
  set_short("A sharp stick");
  set_long(
"This is the pointed stick broken off of the rockworm's\n"+
"head, the merchant would trade it for a decent\n"+
"price.\n");
  set_weight(2);
  set_value(100+random(250));
}
init() {
  ::init();
  add_action("cmd_cash","trade");
}
cmd_cash(str) {
  if(!str || str!="stick") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
  notify_fail("There is nobody here who wants to trade that.\n");
  return 0;
  }

write("The merchant looks over your item, then trades you "+(value+600)+"\n"+
      "coins which is a fair price.\n");
  this_player()->add_money(value+600);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}

