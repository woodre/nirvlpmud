inherit "/players/jenny/room";
#include "/players/jenny/define.h"
query_no_fight() { return 1; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"The gently flowing water in the stream makes a pleasant sound."+NORM);
     set_smell(BOLD+"The fresh country air smells very nice."+NORM);
long_desc=
"You are standing in the middle of a grassy field of gently\n"+
"rolling hills.  A small stream meanders through the landscape,\n"+
"with a small wooden bridge crossing it.  A life sized statue of\n"+
"Dreamspeakr stands before you, and a large white monument\n"+
"sits behind it.\n";
items = ({
"field","A beautiful field of gently flowing hills.  A small stream meanders\n"+
            "through the landscape",
"landscape","A beautiful field of gently rolling hills.  A small stream meanders\n"+
                    "through, with a wooden bridge crossing it",
"hills","The gently rolling hills are covered with grass, and a few trees",
"grass","Freshly cut grass covers the rolling hills",
"trees","Several large trees dot the landscape",
"stream","A small stream, not more than a foot or two deep, meanders through\n"+
              "the valleys, between the hills",
"bridge","A small wooden bridge was built over the stream for people to\n"+
              "walk across.  It is about 5 feet wide, and has hand rails",
"statue","A large bronze statue of Dreamspeakr stands before you.  There is a\n"+
               "plaque at the base",
"plaque","A bronze plaque is on the base of the statue.  It has engraved writing\n"+
               "that you could read",
"monument","A large white domed building, which serves as a monument to\n"+
                     "Dreamspeakr.  It has wooden double doors that you could enter",
"doors","These are beautiful darkly stained wooden doors.  You could enter them",
});

dest_dir = ({
 "/room/forest9","back",
});
}
short() {
return "A grassy field"; }
init() { 
    ::init(); 
     add_action("plaque","read");
     add_action("monument","enter");
}


plaque(arg) {
if(!arg) { notify_fail("What would you like to read?\n"); }
if(arg == "plaque" || arg == "the plaque" || arg == "writing") {
write(BOLD+
"Devoted forever to the memory of the lady Dreamspeakr.  The heavens\n"+
"beckoned their angel to return to them once more on September 25, 2000.\n"+
"She is missed, but not nearly as much as she is loved."+NORM+"\n");
return 1;}}
monument(arg) {
if(!arg) { return 0; }
if(arg == "door" | arg == "the door" | arg == "doors" | arg == "the doors" | arg == "monument") {
write("You open the doors and walk into the monument.\n");
TP->move_player("into the monument#players/jenny/memorial/monument.c"); 
return 1;}}
