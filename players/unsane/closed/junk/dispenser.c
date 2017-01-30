inherit "obj/treasure.c";
#define tp this_player()->query_name()

object goodie;
reset(arg) {
set_id("dispenser");
set_alias("machine");
set_short("A Safety Pin Dispenser");
set_long("What a great machine!  Just type press button, and after we take\n"+
"some of your cash..he he he...(100 coins) you will have a new toy!\n");
set_weight(1000);
}
init() {
add_action("press","press");
add_action("press","push");
}
press() {
if (this_player()->query_money() < 100) {
write("You need 100 coins to buy this.\n");
return 1;}
write("I always knew you were punk fucking rock!\n"+
"Ok, here is your new toy.\n  Mail unsane if you find any bugs, ok?\n");
say(tp +" buys a great toy!");
this_player()->add_money(-100);
goodie=clone_object("/players/unsane/closed/junk/pin.c");
move_object(goodie, this_player());
return 1;
}
