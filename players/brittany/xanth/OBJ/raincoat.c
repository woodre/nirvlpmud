inherit "obj/armor";

reset(arg){
::reset(arg);

set_name("cloak");
set_short ("A yellow cloak");
set_alias("cloak");
set_long("A yellowish cloak, with blood stains smeared on it.\n"+
"A merchant would 'trade' it for a fair price.\n");

   set_ac(1);
set_type("misc");
set_weight(1);
set_value(500+random(400));
}

init(){
::init();
add_action("cmd_cash","trade");
}
 
cmd_cash(str) {
if(!id(str)){
notify_fail("Trade what?\n");
return 0;
}
if(!present("trader",environment(this_player()))) {
notify_fail("There is nobody here who wants to trade that."); return 0; }

write("The merchant trades you "+(value+400)+" in coins for the "+short_desc+".\n");
 this_player()->add_money(value+400);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
