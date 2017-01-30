inherit "/obj/treasure.c";

reset(arg){
if(arg)return;
 
  set_id("unicorn's horn");
  set_alias("horn");
  set_short("A unicorn's horn");
  set_long(
"This is a shiny unicorn's horn, legand says this is a lucky\n"+
"sign.  A merchant might 'trade' it for a decent price.\n");
  set_weight(2);
  set_value(150+random(50));
}
init() {
  ::init();
  add_action("cmd_cash","trade");
}
cmd_cash(str) {
  if(!str || str!="horn") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
  notify_fail("There is nobody here who wants to trade that.\n");
  return 0;
  }

write("The merchant looks over your item, then trades you "+(value+50)+"\n"+
      "coins which is a fair price.\n");
  this_player()->add_money(value+50);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
