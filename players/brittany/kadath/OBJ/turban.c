inherit "obj/armor";

status rubie;

reset(arg){
rubie = 1;
::reset(arg);

set_name("turban");
set_short ("A white turban");
set_alias("helmet");
set_long("A high white turban with a red rubie set in the front,\n"+
"maybe you could 'twist' it off.  And you could 'trade' it with a merchant.\n");

   set_ac(1);
set_type("helmet");
set_weight(1);
set_value(500+random(250));
set_save_flag(1);
}
init(){
::init();
add_action("twist","twist");
add_action("trade","trade");
}

twist(str){
if(str != "rubie"){
notify_fail("twist what?\n");
return 0; }

if(rubie){
write("The rubie twist, then falls off.  It looks valuable, maybe you\n"+
"could 'trade' it with the merchant.\n");
move_object(clone_object("/players/brittany/kadath/OBJ/rubie.c"),this_player());
rubie = 0; }
else write("The rubie has already been removed.\n");
return 1; }
 
cmd_cash(str) {
if(!id(str)) {
    notify_fail("Trade what?\n");
     return 0; }
 
if(!present("trader",environment(this_player()))) {
notify_fail("There is nobody here who wants to trade that."); return 0; }
 
write("The merchant trades you "+(value+550)+" in coins for the "+short_desc+".\n");
 this_player()->add_money(value+550);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
