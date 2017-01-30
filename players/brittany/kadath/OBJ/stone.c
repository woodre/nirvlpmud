inherit "/obj/treasure.c";

object item;
reset(arg){
if(arg)return;
 
  set_id("stone");
  set_alias("stone");
  set_short("A green stone");
  set_long(
"This is a rock fragment with a mysterious green\n"+
"radiance, the merchant would trade it for a decent\n"+
"price.\n");
  set_weight(2);
  set_value(350+random(275));
}
init() {
  ::init();
  add_action("cmd_cash","trade");
}
cmd_cash(str) {
  if(!str || str!="stone") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
  notify_fail("There is nobody here who wants to trade that.\n");
  return 0;
  }

write("The merchant looks over your item, then trades you "+(value+1500)+"\n"+
      "coins which is a fair price.\n");
  this_player()->add_money(value+1500);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}

