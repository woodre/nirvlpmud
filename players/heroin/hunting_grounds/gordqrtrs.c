inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="City hall";
items=({
"directory", "This is a directory for city hall. Upstairs is\n where you'll find Comm. Gordon and downstairs \n is where the parking garage is located."});
dest_dir=({
"/players/heroin/hunting_grounds/gordqrtrsu.c","up"});
long_desc=
"You have walked up the front stairs and into the main floor of \n"+
"Gotham's City Hall.  This is where all the great laws and \n"+
"administration of these laws takes place.  As with any large city\n"+
"building, you see many of the same items found in each.  Directly\n"+
"in front of you, is the information desk.  Noone seems to be on duty\n"+
"right now but you do notice a bell sitting there.  Over to your\n"+
"right is the elevators and to the left is a stairwell.  Just as\n"+
"you begin to press the button to call the elevator, a maintainance\n"+
"walks over a put a OUT OF ORDER-DO NOT USE sign on the door.  You \n"+
"Think to yourself: No big deal I can always use the exercise. As\n"+
"you approach the stairwell, you notice a sign on the door.  The sign reads:\n"+
"Roof access only, use elevator to reach parking garage. \n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find an invoice for $2000 in batteries?\n");
say(tp + "folds up a piece of paper and puts it in their pocket\n");
return 1;
}
listen(){
write("You hear a little bird chirping a happy song\n");
say(tp + "whistles a little ditty\n");
return 1;
}
