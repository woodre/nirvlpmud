inherit "obj/armor";

reset(arg){
::reset(arg);

set_name("cloak");
set_short ("A brown cloak");
set_alias("brn_cloak");
set_long("A brown cloak that is trim with two different colors.\n"+
"The top color is yellow and the bottom color is orange.  This\n"+
"is the cloak that Benedict wears.  A merchant "would 'trade'\n"+
"it for a fair price.\n");

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
