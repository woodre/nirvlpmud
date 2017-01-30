#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 0;
set_light(-1);

short_desc = "Ter'angreal of Glass (Shadowed)";
long_desc =
"   Suspended within a circular room of shadowed glass,  your vision is\n"+
"cloudy and distorted.  Figures struggle to escape from within the glass\n"+
"wall surrounding you, but seem unable to do so.  A dry, grey mist swirls\n"+
"about your feet and small fingers of a darker grey attempt to climb your\n"+
"legs...grasping for a hold upon your armor.  A 'ter'angreal' of glass hangs\n"+
"cracked and without light in the center of the room.  One circular doorway\n"+
"(Door2) is stuck open within the glass wall, leading into utter darkness.\n"+
"Four other doors open and close, leading into rooms with light.\n";

items = ({
"room",    "A circular room with walls of shadowed glass",
"figures", "Huge snake-like beings, with coiled tails and multiple arms",
"warriors","Tall and well built, wearing no armor but thier skin of scales",
"mist",    "It almost seems to have a life force of some kind, and you fear it",
"fingers", "Grasping at your legs, they attempt to climb higher",
"wall",    "Circular in design, with no corners nor seams. It is made of shadowed glass",
"ter'angreal",  "A ter'angreal of glass, once full of magic and light.\n"+
                "It is now cracked and broken, its magic gone or lost.",
"glass",   "Without the magic light from the circle, it is now dark and full of mist",
"doorway", "The door stands open and reveals only black darkness beyond",
"doors",   "They open and close like a camera lens into rooms beyond your sight",
});

dest_dir = ({
"/players/fakir/genji/rm5e","door1",
"/players/fakir/genji/rm2e","door2",
"/players/fakir/genji/rm4e","door3",
"/players/fakir/genji/rm1c","door4",
"/players/fakir/genji/rm5a","door5",
});
}
init()  {
  ::init();
    add_action("strike_terangreal","strike");
}
strike_terangreal(arg)  {
if(!arg || arg != "ter'angreal") {
notify_fail("\nA sad voice crys:\n\n"+
           GREEN+"'Try striking the ter'angreal instead.'\n"+OFF);
return 0; 
}
if(found==0) { tell_room(this_object(),"\nA sad voice crys:\n\n"+
               GREEN+"     'The ter'angreal has been cracked and broken.  It has\n\n"+
                     "      no power to free warriors from the wall of glass.'\n"+OFF);  
return 1; }

}



