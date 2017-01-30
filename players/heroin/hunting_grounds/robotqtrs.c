inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
/* } */
/* I'm praying that bracket was a typo.
 */
if (!present("robot")) move_object(clone_object("/players/heroin/hunting_grounds/robot.c"), this_object());
short_desc="Robotics Lab";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/corr1.c","north",
"players/heroin/hunting_grounds/cafeter.c","east"});
long_desc=
"This appears to be a lab of some sort.  It looks like it is used\n"+
"for a variety of activities including surgery.  There appears to \n"+
"have been a recent struggle of some sort.  There are bullet holes\n"+
"in the walls and blood splattered everywhere.  You notice the man\n"+
"staring at you suddenly.  Wait- what is that white crap oozing from\n"+
"his forehead.  You begin to doubt this is a man standing in front of\n"+
"you.  Whatever it is..it's going nuts.\n";
}
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
/* this won't work.


add_action("search_corpse","search corpse");
*/
add_action("search","search");
}
search(str) {
if(!str) {
write("While searching about, you accidentally hit a button . A voice\n activates and says: Mother can only be activated by key.\n");
say(tp + " looks at you.\n");
}
if(str == "corpse") return search_corpse();
return 1;
}
kill(str){
object test;
test =(present("counter", this_player()));
if (test) {test->inc_count();}
}

search_corpse(){
write("A note: The key is not currently on the ship.\n");
say(tp + " pokes at the corpse.\n");
return 1;
}
listen(){
write("You hear the blood rushing through your veins.\n");
say(tp + " begins to pant.\n");
return 1;
}
