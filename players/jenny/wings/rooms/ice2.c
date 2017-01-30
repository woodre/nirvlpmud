inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("fedorov"))  {
MOCO("/players/jenny/wings/mobs/players/fedorov.c"),TO); }
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice the penalty box and player's bench off to the east."+NORM);
     set_smell(BOLD+"You take in a breath of the cold air."+NORM);
long_desc=
"This is the ice surface of Joe Louis Arena.  The Detroit Red\n"+      
"Wings play their home games here.  The white ice underneath\n"+
"you is very slippery.  The boards enclosing the rink are topped\n"+
"off by about 4 feet of plexiglass, which gives you a sense of\n"+
"privacy, yet you still know you are being watched.  There is a\n"+
"goal at the north end of the rink.  A blue line stretches across\n"+
"the ice, sixty feet from the goal, and a Red line, 90 feet from\n"+
"the goal, divides the ice surface in half.  Looking up, the first\n"+
"thing to catch your attention is the giant scoreboard.  Your\n"+
"eyes then turn to the 14 banners hanging from the rafters.\n";
items = ({
"bench","A long bench next to the ice surface.  During the games, the\n"+
              "players sit here between shifts.  You could 'enter bench'",
"scoreboard","This is a giant scoreboard which hangs overhead.  It keeps\n"+
                        "track of home and visitor's score, the period, time remaining\n"+
                        "in the period, and penalty times.  It also has advertising on it",
"penalty box","This is small bench next to the ice surface.  Players get\n"+
                        "sent here to serve penalties.  You could 'enter box'",
"box","This is small bench next to the ice surface.  Players get\n"+
                        "sent here to serve penalties.  You could 'enter box'",
"ice","The cold ice underneath you is very slippery.  It has lines and\n"+
          "circles painted on it for hockey games",
"banners","There are 14 banners hanging from the rafters.  Nine are\n"+
                  "to honor the Stanley Cup champions of 1936, 1937, 1943,\n"+
                   "1950, 1952, 1954, 1955, 1997, and 1998.  The other five\n"+
                   "are retired numbers. #1 Terry Sawchuck, #7 Ted Lindsay,\n"+
                   "#9 Gordie Howe, #10 Alex Delvecchio, and #12 Sid Abel",
"rafters","This is the ceiling of Joe Louis Arena.  There are 14 banners\n"+
                "hanging from the rafters",
"lines","There is a red line and a blue line",
"circles","These circles are for faceoffs.  There are two about 30 feet\n"+
               "in front of the goal.  One on each side.  The other is in the\n"+
               "center of the rink",
"boards","These boards enclose the ice surface.  There is advertising\n"+
                "all over them.  About 4 feet of plexiglass is on top of the\n"+
                 "boards",
"plexiglass","This is a clear hard plastic which protects the fans from\n"+
                     "getting hit by pucks, yet still gives them a good view of\n"+
                     "the action",
"goal","The goal is a net which is four feet high and six feet wide.  It has\n"+
             "a red frame, and is held in the ice by two rubber pegs",
"blue line","This is a blue line which stretches across the ice 60 feet from\n"+
                   "the net.  It is used for offsides calls",
"red line","This is a red line which stretches across the ice 90 feet from\n"+
                  "the net.  It is used for icing calls", 

});

dest_dir = ({
"/players/jenny/wings/rooms/ice1","south",
"/players/jenny/wings/rooms/i1","out",
});
}
short() {
return BOLD+WHT+"The ice surface"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("bench","enter");
add_action("box","enter");
add_action("south","south");
add_action("out","out");
}
bench(arg) {
if(!arg) {return 0;}
if(arg == "bench" | arg == "player's bench") {
TP->move_player("onto the bench#players/jenny/wings/rooms/bench2.c");
return 1; }}
box(arg) {
if(!arg) { return 0; }
if(arg == "box" | arg == "penalty box") {
TP->move_player("into the penalty box#players/jenny/wings/rooms/box2.c");
return 1;}}
south() {
if(TP->query_attrib("ste") <  random(28)) {
write("You trip and fall on the "+WHT+"ice"+NORM+".  Ouch!  That hurts\n"+
"the butt.\n"); return 1;}
else {return 0;}}
out() {
if(TP->query_attrib("ste") <  random(28)) {
write("You trip and fall on the "+WHT+"ice"+NORM+".  Ouch!  That hurts\n"+
"the butt.\n"); return 1;}
else {return 0;}
}
