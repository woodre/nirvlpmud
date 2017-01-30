inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int wheater;
int dooropen;
realm() { return "NT"; }
reset(arg) {
wheater = 1;
    if(arg) return;
     set_smell(BOLD+"The stench of rotting flesh is in the air."+NORM);
     set_search(BOLD+"Looking very closely, you notice some odd cracks in the wall.."+NORM);
set_light(0);
long_desc=
"This cold damp basement does not look fit for human habitation.\n"+      
"The walls are made of large grey bricks, and the floor is just plain\n"+
"cement.  Boxes of junk are scattered all over the place, and animal\n"+
"pelts are hanging from the exposed floor joints.  A large hot water\n"+
"heater sits in the corner, not far from a steel door.  A staircase leads\n"+
"back upstairs.\n";
short_desc=(BOLD+"Basement"+NORM);

items = ({
"staircase","A narrow wooden staircase, which leads upstairs.  There are\n"+
                  "a few broken steps, but it's still climbable",
"walls","They are made of large, grey, unpainted brick.  One of the walls has\n"+
                "a pentagram on it.",
"floor","The dirty, grey, cement floor.  It is littered with boxes of junk",
"pentagram","A star inside of a circle.  It has been drawn in blood",
"boxes","Cardboard boxes filled with all kinds of junk.  Most of them\n"+
           "are taped up.  Upon closer inspection, you notice a body hidden\n"+
            "behind a pile of boxes",
"junk","Cardboard boxes filled with all kinds of junk.  Most of them\n"+
           "are taped up.  Upon closer inspection, you notice a body hidden\n"+
            "behind a pile of boxes",
"floor joints","This is the underside of the first floor.  A proper ceiling was never\n"+
               "installed.  The wooden beams are filled with cobwebs",
"beams","Wooden beams which are used to support the first floor",
"cobwebs","Cobwebs have formed in the floor joints",
"bricks","Large grey bricks, used for the basement walls",
"pelts","Dozens of racoon, beaver, skunk, and squirrel pelts are hanging from the\n"+
            "exposed floor joints.  They look as if they were recently skinned",
"body","This is the naked dead body of an elderly man.  It is a little bloated\n"+
              "and discolored.  Maggots have infested an open wound in the chest,\n"+
              "as well as the mouth and eye sockets",
"door","This is a sturdy steel door, with only a metal latch on it",
"latch","A plain metal latch.  It is used to open the door",
"cracks","These cracks look like the outline of an entrance.  Maybe if you pushed\n"+
                "the wall real hard, you could find out what this is",
});
dest_dir = ({
 "/players/jenny/house/rooms/cellar","west",
});

}
init() { 
    ::init(); 
   this_player()->set_fight_area();
if(random(35) < 3 && wheater < 2 && TPL < 20) {
call_out("scalded",5);
wheater = 2;
return 1; }
add_action("staircase","climb");
add_action("door","open");
add_action("tunnel","push");
add_action("heater","look");
add_action("heater","l");
add_action("heater","examine");
add_action("heater","exa");
}
staircase(arg) {
if(!arg) {return 0;}
if(arg == "staircase" | arg == "the staircase" | arg == "stairs" | arg == "the stairs") {
write("You climb the stairs.\n");
TP->move_player("up the stairs#players/jenny/house/rooms/kitchen.c");
return 1; }
}
door(arg) {
if(!arg) {return 0; }
if(arg == "door" | arg == "the door") {
write("You turn the latch and open the door.\n");
say(TPN+" turns the latch and opens the door.\n");
call_other("/players/jenny/house/rooms/traproom.c", "dooropen = 2");
return 1 ;}}
tunnel(arg) {
if(!arg) {return 0;}
if(arg == "wall" | arg == "the wall") {
if(random(STRSTAT) < 6) {write("You push the wall with all your might, but nothing happens.\n"); return 1;}
write("This section of the wall begins to rotate, allowing you to enter some sort of tunnel.\n");
say(TPN+" pushes the wall and a secret tunnel is revealed.\n");
TP->move_player("into a tunnel#players/jenny/house/rooms/tunnel1.c");
return 1; }}
heater(arg) {
if(!arg) {return 0;}
if(arg == "at heater" | arg == "at hot water heater" | arg == "heater" | arg == "hot water heater") {
if(wheater < 2) {write("A large white hot water heater.\n"); return 1;}
if(wheater > 1) {write("The shattered remains of an exploded hot water heater.\n"); return 1;}}}
scalded() {
ENVTP->hit_player(30+random(15));
write("The hot water heater bursts, spraying you with scalding water.\n");
say("The hot water heater bursts, spraying you with scalding water.\n");
return 1; }
