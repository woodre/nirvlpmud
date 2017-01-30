inherit "obj/armor";

reset(arg){
::reset(arg);

set_name("mask");
set_short ("A silk mask");
set_alias("mask");
set_long("A yellowish silk mask, with blood teardrops under each eye opening.\n"+
"A merchant would give you a fair price if you were to 'trade' it.\n");

   set_ac(1);
set_type("helmet");
set_weight(1);
set_value(350+random(250));
}

init(){
::init();
add_action("cmd_cash","trade");
}
 
cmd_cash(str) {
if(!id(str)) {
    notify_fail("Trade what?\n");
     return 0; }

if(!present("trader",environment(this_player()))) {
notify_fail("There is nobody here who wants to trade that."); return 0; }

write("The merchant trades you "+(value+650)+" in coins for the "+short_desc+".\n");
 this_player()->add_money(value+650);
  destruct(this_object());
  this_player()->recalc_carry();
return 1; }
