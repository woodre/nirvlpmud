inherit"obj/treasure";
reset(arg) {
if(arg) return;
set_id("rose");
set_alias("card");
set_short("A Small Knife");
set_long(
"It is a meal card from IIT.\n");
set_value(0);
set_weight(0);
}
init(){
add_action("heal","sniff");
}
heal(){
this_player()->heal_self(350);
return 1;
}
