#define tp this_player()->query_name() 
inherit "obj/treasure";
int times;
reset(arg){
if (!arg) {times = 0; }
set_id("disc");
set_alias("curious disc");
set_short("A curious looking disc");
set_long("This item baffles you.  It appears to be made up of a myriad of other pieces.\n"+
"That would explain its segmented appearance.  There also appear to be coded \n"+
"runes covering every inch of it.\n");
set_value(random(2000));
set_weight(2);
}
init(){
add_action("solve");add_verb("solve");
add_action("read"); add_verb("read"); 
add_action("tele"); add_verb("tele"); }
read(str) {
if (str == "disc") {
write("You can't seem to make any sense of these runes, but you you get the\n"+
"the feeling that this is a puzzle of sorts.  The question is, can you\n"+
"solve it?\n");
return 1; }
}
solve(){
if (times == 2) {
write("You have solved the mysteries of this disc.  This is the item that the\n"+
"insect was using to teleport people.  To use it type tele #, where # is the \n"+
"number of the circle of hell you wish to visit.\n");
write("You can also type tele bar to visit the demon's bar.\n");
times++;
return 1;
}
else {
write("You can't seem to solve this thing.\n");
times++;
return 1;} }
tele(num) {
if (environment(this_player())->realm() == "NT"){
write("You cannot teleport from here.\n");
return 1;}
if (num == "two" || num == "2") {
write("You are teleported to the second circle of hell.\n");
say(tp+" fiddles with a disc and teleports away.\n");
move_object(this_player(),"/players/unsane/closed/hell/circle2.c");
say(tp+" arrives in a puff of brimstone.\n");
command("look",this_player());
return 1; }
if (num == "three" || num == "3") {
write ("You are teleported to the third circle of hell.\n");
say(tp+ " fiddles with a disc and teleports away.\n");
move_object(this_player(),"players/unsane/closed/hell/circle3.c");
say(tp+" arrives in a puff of brimstone.\n");
command("look", this_player());
return 1;}
if (num == "4" || num == "four") {
write("You are teleported to the fourth circle.\n");
say(tp+" fiddles with a disc and teleports away.\n");
move_object(this_player(),"/players/unsane/closed/hell/circle4.c");
say(tp+" arrives in a puff of brimstone.\n");
command("look",this_player());
return 1;}
if (num == "bar") {
write("You escape to the bar.\n");
say(tp+" runs away to the bar.\n");
if (this_player()->query_sp() < 10) {
write("You don't have enough spell points to teleport.\n");
return 1;}
this_player()->add_spell_point(-10);
move_object(this_player(),"/players/unsane/closed/hell/bar.c");
say(tp+" arrives in a puff of brimstone.\n");
command("look",this_player());
return 1;}
else {
write("You want to go where???\n");
return 1;}
}
