inherit "obj/armor";

reset(arg){
::reset(arg);

set_name("suit");
set_short ("A riding suit");
set_alias("riding_suit");
set_long("A riding suit of green.  This is the suit that\n"+
"Bland wears.\n");

   set_ac(2);
set_type("armor");
set_weight(1);
set_value(100+random(50));
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
  write("The merchant trades you "+(value+50)+" in coins for the "+short_desc+".\n");
  this_player()->add_money(value+50);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
