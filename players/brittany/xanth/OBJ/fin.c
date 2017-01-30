inherit "/obj/treasure.c";

reset(arg){
if(arg)return;
 
  set_id("anzoog's tail");
  set_alias("tail");
  set_short("A anzoogs tail");
  set_long(
"This is the chopped off tail of the ancient guard's tail.\n"+
"It looks like it may be worth something if you 'trade' it with\n"+
"a merchant trader.\n");
  set_weight(3);
  set_value(300+random(200));
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
  if(!present("trader",environment(this_player()))){
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
