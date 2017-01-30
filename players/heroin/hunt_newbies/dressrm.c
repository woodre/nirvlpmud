inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("frank")) move_object(clone_object("/players/heroin/hunt_newbies/frankg.c"), this_object());
short_desc="A Dressing Room";
items=({
"change", "change"});
dest_dir=({
"players/heroin/hunt_newbies/LIVE.c","stage"});
long_desc=
"You wander backstage and enter a dressing room. As you walk in\n"+
"you cant believe your eyes.  In front of you stands, Kathy Lee's \n"+
"hubby in leotards...Man what a day: first, Kathy Lee and now Frank\n"+
"You put your hands together and thank Angst.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("Nothing here but dust and lint.\n");
say(tp + "sneezes.\n");
return 1;
}
listen(){
write("You hear Angst's faint cackle off in the distance.\n");
say(tp + "listens attentively.\n");
return 1;
}
