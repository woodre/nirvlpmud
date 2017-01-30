inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("Crewmem")) move_object(clone_object("/players/heroin/hunting_grounds/crewmem.c"), this_object());
if (!present("Crewmem")) move_object(clone_object("/players/heroin/hunting_grounds/crewmem.c"), this_object());
if (!present("Crewmem")) move_object(clone_object("/players/heroin/hunting_grounds/crewmem.c"), this_object());
if (!present("Crewmem")) move_object(clone_object("/players/heroin/hunting_grounds/crewmem.c"), this_object());
if (!present("Crewmem")) move_object(clone_object("/players/heroin/hunting_grounds/crewmem.c"), this_object());
short_desc="Crew's Quarters";
items=({
"chamber","This is a sleep chamber for deep space travel. It \n resembles a coffin in shape. Maybe if the shit hit the fan, \n you could feign death."});
dest_dir=({
"/players/heroin/hunting_grounds/corr1.c","south",
"players/heroin/hunting_grounds/controlrm.c","east"});
long_desc=
"This appears to a sleep chamber of some kind.  The room has\n"+
" a series of chambers in the middle of the room and benches on\n"+
"the outside.  This must be where the crew sleeps when traveling.\n"+
"The room look s clean and unused, not surprising since all anyone\n"+
"ever does here is sleep.  However, today this room is a filled with\n"+
"crew members.  They looked really freaked out.  It looks like they\n"+
"are trying to barricade the door to the east.  They appear to scared\n"+
"to the point that they might shoot at anything..or anyone!\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test =(present("counter",this_player()));
if (test) { test->inc_count();}
}
search(){
write("You find a note. It reads: turn_key to talk to mother\n");
say(tp + "says: Be quiet! I am reading\n");
return 1;
}
listen(){
write("You hear the sound of something ramming the east door\n");
say(tp + "looks toward the east\n");
return 1;
}
