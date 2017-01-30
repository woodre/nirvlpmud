inherit "/obj/treasure";
 
reset(arg){
if(arg)return;
 
  set_id("gem");
  set_alias("gem");
  set_short("A rare gem");
  set_long(
    "     A rare gem found deep in the mountains.\n");
  set_weight(2);
  set_value(250+random(100));
}

init() {
  ::init();
  add_action("cmd_cash","trade");
}

cmd_cash(str) {
  if(!str || str!="gem") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) return 0;
write("The merchant looks over your item, then trades you "+value+"\n"+
      "coins which is fair market value.\n");
  this_player()->add_money(value);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
