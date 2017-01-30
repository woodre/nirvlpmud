int i;
inherit "obj/treasure";
reset(arg){
set_short("Nightcrawler's Tail");
set_value(2000);
set_weight(1);
set_save_flag(1);
set_id("tail");
set_alias("nightcrawler's tail");
set_long("This is the Nightcrawler's tail, now hacked off.  You get a strange feeling\n"+
"about it.  Maybe it has power?\n");
}
init(){
::init();
add_action("bamf","bamf");
add_action("bamf","BAMF");
}
bamf() {
if (environment(this_player())->realm() == "NT") {
write("Not even Nightcrawler could bamf outta this place.\n");
return 1;}
write("You discover your mutant ability to teleport!\n");
write("You teleport to limbo!\n");
say("BAMF!\n");
move_object(this_player(),"/players/unsane/xmen/bamf");
say("BAMF\n");
i = random(20);
if (i < 3) {
write("That last bamf took all the power out of the tail.\n");
destruct(this_object());
}
return 1;
}
