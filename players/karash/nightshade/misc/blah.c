inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short("Topaz");
set_long
("A rather large topaz gem Hephastus has plundered.\n");
set_weight(1);
set_alias("gem");
set_value(500);
}
init() {
::init();
add_action("do_crush", "crush");
}
do_crush(str) {
if(!str) return;
if(this_player()->query_exp() < 10000) {
write("Ha yeah right.\n");
return 1;
}
if(random(4) > 2) {
write("You gained exp as the dust blows away in the wind.\n");
this_player()->add_exp(10000);
destruct(this_object());
return 1;
}
else {
write("You lose xp as the dust blows away. SUCKER!\n");
this_player()->add_exp(-10000);
destruct(this_object());
return 1;
}
}
