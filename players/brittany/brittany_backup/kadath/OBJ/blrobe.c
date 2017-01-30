inherit "obj/armor";

reset(arg){
::reset(arg);

set_name("robe");
set_short ("A black robe");
set_alias("robe");
set_long("A black robe with a white pentagram and symbols engraved\n"+
"on it.  A merchant would 'trade' it for a fair price.\n");

   set_ac(2);
set_type("armor");
set_weight(1);
set_value(500+random(350));
}

init(){
::init();
add_action("cmd_cash","trade");
}
 
cmd_cash(str) {
  if(!id(str)) {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
    notify_fail("There is nobody here who wants to trade that.\n");
    return 0;
  }
  write("The merchant trades you "+(value+500)+" in coins for the "+short_desc+".\n");
  this_player()->add_money(value+500);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
