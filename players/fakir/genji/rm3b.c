#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Crystal Oblong (Lucent)";
long_desc =
"   An oblong crystal wall glows lucent with a soft light.  Within the wall,\n"+
"a fierce hump-backed fighter is held captive.  He holds a small sphere in\n"+
"his left hand, and it glows bright blue.  He stares out from the wall with\n"+
"bloodshot eyes and watches your every movement.  A delicate oblong 'crystal'\n"+
"floats in the center of the room.  Four doors glide in random motion about\n"+
"the oblong wall.\n";

items = ({
"room",    "An oblong room with walls of transparent crystal",
"fighter", "A very fierce hump-backed being with thick arms and legs",
"wall",    "A single oblong wall of transparent crystal which surrounds you on all sides",
"sphere",  "A round sphere the size of a small fruit which glows bright blue",
"crystal", "A magic oblong crystal. It shimmers with a dim light.\n"+
           "A few brave souls have attempted to 'invoke' the crystal",
"doors",   "Oblong openings which glide about the wall in random directions",
"eyes",    "Oval in shape and bloodshot red from the anger of being trapped",
});

dest_dir = ({
"/players/fakir/genji/rm5c","door1",
"/players/fakir/genji/rm3c","door2",
"/players/fakir/genji/rm2c","door3",
"/players/fakir/genji/rm6c","door4",
});
}
init()  {
  ::init();
    add_action("invoke_crystal","invoke");
}
invoke_crystal(arg)  {
if(!arg || arg != "crystal") {
notify_fail(CYAN+"Try to invoke the crystal.\n"+OFF);
return 0; 
}
if(found==0) { write("\nA high pitched voice sings:\n\n"+
                     CYAN+"     'You have somehow defeated the warrior from the wall.\n\n"+
                     "      I shall reward you.  To cross the great gulf, you\n\n"+
                     "      will need the wings taken from a myrraddrals back.'\n"+OFF);  
return 1; }
if(present("digger",this_object())) {
write("\nA high pitched voice sings:\n\n"+
                     CYAN+"     'You must kill this fighter before you ask for another.'\n"+OFF);
return 1;
}
write("\nA high pitched voice sings:\n\n"+
                     CYAN+"     'You have invoked my crystal. I shall\n\n"+
                     "      release a warrior from the oblong wall.'\n"+OFF);  
move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
found=found-1; 
return 1; 

}



