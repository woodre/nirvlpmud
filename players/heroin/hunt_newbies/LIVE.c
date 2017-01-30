inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";

reset (int arg) {
if (!arg){
set_light(1);
}
if (!present("kathy")) move_object(clone_object("/players/heroin/hunt_newbies/kathyl.c"), this_object());
if(!present("regis")) move_object(clone_object("/players/heroin/hunt_newbies/regis.c"), this_object());
short_desc="LIVE with Regis and Kathy Lee";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/newb_ent.c","tv",
"players/heroin/hunt_newbies/dressrm.c","backstage"});
long_desc=
"You clicked the channel and ended up here, but where's here?  You\n"+
"pause and get your bearings to find yourself in the middle of a stage\n"+
"You think about it..Hey Wait I am on LIVE with those annoying a-holes\n"+
"Regis and Kathy Lee.  You turn around and notice that there is a studio\n"+
"audience so they must be filming.  The thought of killing these two\n"+
"in front of several million viewers brings a smile to your face: \n"+
"If Angst is watching, you are sure he'ld be proud.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
object ob;
if (i == 0) {
write("You find some left-over salmon from last weeks show.\n");
say(tp + "asks you: do you like the smell of tuna?\n");
ob = clone_object("/players/heroin/hunt_newbies/salmon");
move_object(ob, this_player());
i++;
return 1;}
write("There is no more piggy.\n");
return 1;
}
listen(){
write("You hear applause--oh the audience was just cued.\n");
say(tp + "takes a bow and says: Thank you.\n");
return 1;
}
