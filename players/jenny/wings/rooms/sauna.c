inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("brendan shanahan"))  {
if(random(10) > 1) {
MOCO("/players/jenny/wings/mobs/players/shanahan.c"),this_object()); }}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"Your body starts to sweat a little more as you take in\n"+
                                    "a breath of the hot air."+NORM);
long_desc=
"The sauna feels very warm and cozy.  The hot air makes your pores\n"+      
"break into a sweat.  The walls are made of cedar paneling, as is the\n"+
"ceiling.  The floor is made of cedar planks.  A top and bottom row of\n"+
"benches run along the back and far side walls.  Next to the door is\n"+
"a wooden barrel with large rocks in it.\n";
items = ({
"benches","Two rows of wooden benches are along the back and far side walls.\n"+
                   "They are made of cedar, and have wet spots where people were\n"+
                    "recently sitting",
"walls","The brown walls are made up of cedar paneling.  There is a bucket\n"+
              "hanging from a hook on the wall over the barrel",
"hook","A plain brass hook sticking out of the wall.  There is a bucket hanging\n"+
              "from it",
"bucket","An empty tin bucket hangs from a hook over the barrel of rocks",
"ceiling","The ceiling is made up of cedar paneling",
"floor","Cedar planks run vertically from the front of the sauna to the back",
"barrel","A wooden half barrel is built into the wall.  It is filled with rocks",
"rocks","Large, very hot rocks fill up the wooden barrow.  Something inside\n"+
               "of it must keep them heated",
"planks","Cedar planks run vertically from the front of the sauna to the back",
"door","This thick wooden door looks as if it were made out of half logs,\n"+
             "which run vertically",
"wet spots","There are a few large round wet spots on the benches",
});
dest_dir = ({
 "/players/jenny/wings/rooms/whp","out",
});
}
short() {
return BOLD+"Sauna"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
