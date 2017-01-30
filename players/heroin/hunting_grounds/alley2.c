inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(5);
}
if (!present("cord")) move_object(clone_object("/players/heroin/hunting_grounds/cord.c"), this_object());
short_desc="Dark alley   ";
items=({
"label" , "The label reads: For indoor use only. Exposure to outdoor\n elements such as rain, fog, etc commonly found in regions such as London.\n Exposure could be fatal.\n",
"cord" , "It appears to be a extension cord.  The cord leads off\n to the north.  You think to yourself this gets weirder by the minute\n But oh well, its just a game, right?  As you examine the cord more \n carefully you realize that thereis a label left on the cord.  Must be brand-spankin' new..",
"walls", "The walls of city seem to close in on you..\n It could be just your imagination but the walls seem to be \n leading you along.  You see that whatever it was that left the scrapes earlier\n also followed this path..You suddenly realize that the scrapes\n on the wall at this location form a shape..as you follow\n the lines the shape becomes clearer......\n   --------->>>  \n  You begin to wonder whose tracking who now?"});
dest_dir=({
"/players/heroin/hunting_grounds/alley.c","east",
"players/heroin/hunting_grounds/jacked_up.c","north",});
long_desc =
"You have reached the end of the alley..You look around only to find\n"+
"yourself    -umph-  ..What the HELLLLLLLLLLL?\n"+
"The world has gone black and all you can hear is somebody whistling\n"+
"the theme song to Andy Griffith show..You panic and yell out -HELP-\n"+
"You feel hand cover your mouth and a man whispers: shhhhhhhhh, hush\n"+
"little baby, don't you cry..Relax I am just doing my job.\n"+
"You mumble: What damn job???\n"+
"The man replies: I do the measurements for the stuffing\n"+
"You exclaim: What stuffing???\n"+
"The man giggles: I prepare all of Angst's trophys for mounting\n"+
"and with the holiday season quickly approaching, I need to get crackin\n"+
"You would want us to fall behind now, would you?\n"+
"you reply humbly : No, I guess not\n"+
"The man says: Good, Now hold still..and use your other senses\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("kill","kill");
   add_action("read","read");
   add_action("search","search");
}
kill(str){
object test;
test=(present("counter", this_player()));
if (test) {test->inc_count();}
}
search(){
write("Plugged into an unknown source is a extension CORD..this cord\n was never went for outdoor use..so be careful its hot..OUCH too late!!!\n");
say(tp + "screams in agony--HELP ME \n");
return 1;
}
smell(){
write("Something's burning-SNIFF SNIFF..Shit its you..KILL THE CORD\n");
say (tp + "turns and sniffs his burning ass.\n");
say (tp + "says: can u sniff your own butt?\n");
return 1;
}
listen(){
write("In the distance, you could swear you hear someone selling\n popcorn and beer.  Sounds like its coming from the north.\n");
say(tp + "begins to drool and rub his tummy\n");
return 1;
}

