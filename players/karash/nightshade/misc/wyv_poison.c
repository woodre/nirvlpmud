inherit "obj/treasure";
int blood;
reset(arg) {
if (arg) return;
set_short("Wyvern's poison (sobering)");
set_weight(1);
set_alias("poison");
set_value(150);
}
long() {
write("This is poison that has been collectd from a wyverns poisonous\n"+
      "sting. It breaks down the alcohol in the body and sobers you up.\n");
   }
init()
{
add_action("do_inject", "drink");
}
do_inject(str)
{
if(!str) return;
if(str == "poison");
{
if(call_other(this_player(), "drink_alcohol", -5))
{
say(call_other(this_player(), "query_name") + " cringes as they quaff down the poison.\n");
write("The thick, green liquid suddenly bubbles and you think you better get\n"+
"this over with and quaff the poison.\n");
destruct(this_object());
return 1;
}
}
}
