#include "/players/fakir/color.h"
inherit "room/room";
int found;
int taken;

reset(arg) {
  if(arg) return;
found = 1+random(0);
set_light(1);

short_desc = "Crystal Oblong (Obscure)";
long_desc =
"   An obscure crystal wall holds several Aiel fighters captive within and they\n"+
"struggle to escape.  One holds a staff and wields it as a weapon of great power.\n"+
"The face of each fighter is veiled with a shoufa, and only stone cold eyes show\n"+
"above the veil.  A delicate oblong 'crystal' floats in the center of the room.\n"+
"Four doors glide in random motion about the wall.\n"; 

items = ({
"room",    "An oblong room with walls of obscure crystal",
"weapon",  "A staff of wood carved from the Avendesora, or 'Tree of Life'",
"staff",   "A staff of wood with runes carved upon its length",
"face",    "Only the eyes can be seen clearly. They\n"+
           "are stone cold and have seen many deaths",
"fighter", "A bit taller than the rest, he holds a staff as a weapon",
"eyes",    "Dark in color and unblinking",
"veil",    "A light colored veil of pure silk",
"shoufa",  "A light colored veil of pure silk, worn just prior to battle",
"fighters","Darkly tanned from the sun of the waste, these warriors are fierce\n"+
           "and loyal to non but themselves.  They will never touch a sword",
"wall",    "A single oblong wall of obscure crystal which surrounds you on all sides",
"crystal", "A magic oblong crystal. It shimmers with a dim light.\n"+
           "You may 'invoke' the crystal if you are a brave fighter",
"doors",   "Oblong openings which glide about the wall in random directions",
});

dest_dir = ({
"/players/fakir/genji/rm5d","door1",
"/players/fakir/genji/rm3d","door2",
"/players/fakir/genji/rm2d","door3",
"/players/fakir/genji/rm6d","door4",
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
  if(present("digger",this_object())) {
    write("\nA high pitched voice sings:\n\n"+
      CYAN+"     'You must kill this Aiel warrior before you try to invoke the crystal again.'\n"+OFF);
    return 1;
  }
  if(found==0) { 
    if(taken == "1") {
    write("\nA high pitched voice sings:\n\n"+
      CYAN+"     'Invoking my crystal will do you no good now.  I have\n\n"+
           "      given more than you deserve already. Now be gone.'\n\n"+OFF);
      return 1;
    }
    write("\nA high pitched voice sings:\n\n"+
      CYAN+"     'To defeat an Aiel is no small accomplishment. I shall\n\n"+
      "      reward you with his weapon, a staff of great power.  I'\n\n"+
      "      lay this weapon at your feet.  Use it well and wisely.'\n\n"+OFF); 
    move_object(clone_object("/players/fakir/genji/WEP/aielstaff.c"),this_object());
    taken="1"; 
    return 1; 
  }
  write("\nA high pitched voice sings:\n\n"+
    CYAN+"     'You have invoked my crystal. I shall release an\n\n"+
    "      Aiel from the oblong wall.  Should you defeat him, you\n\n"+
    "      may invoke my crystal a single time more for the reward.'\n"+OFF);  
    move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
    found=found-1; 
    return 1; 
}