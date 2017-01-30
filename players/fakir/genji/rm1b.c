#include "/players/fakir/color.h"
inherit "room/room";
int found;
int rod = 2;

reset(arg) {
  if(arg) return;
found = 1+random(1);
set_light(1);

short_desc = "Ter'angreal of Glass (Lucent)";
long_desc =
"   A single spherical wall of lucent glass encompasses your being.  Images of\n"+
"grotesque scale covered beings, engaged in bloody combat, are trapped within\n"+
"the glass wall.  A single warrior stands out from the rest, his curved sword\n"+
"held in an arm covered with heavy scale plate.  He strains to escape from the\n"+
"imprisoning glass wall.  A lucent 'ter'angreal' of glass glows with a dim light\n"+
"and hangs in the center of the room.  Four circular lens-like doorways open\n"+
"and close within the glass wall, two of which lead into darkness.\n";

items = ({
"room",    "A circular room with walls of lucent glass",
"beings",  "Strangly shaped creatures covered in heavy scales",
"images",  "Fur covered warriors trapped within the glass wall",
"warrior", "Stronger and more fierce than the others, he is obviously the leader",
"wall",    "Circular in design, with no corners nor seams. It is made of lucent glass",
"ter'angreal",  "A magic ter'angreal of glass, created in the age of legends.\n"+
                "Can you resist the urge to 'strike' the 'ter'angreal'?  Perhaps you could 'steal' it\n"+
           "and capture its magic light..but beware that which you steal from the tower",
"glass",   "Enchanted with a strange magic, it glows lucent with a dim light",
"doorways","Small round openings within the glass wall. They open and close\n"+
           "at random.  Two of the doorways open into darkness",
});

dest_dir = ({
"/players/fakir/genji/rm5c","door1",
"/players/fakir/genji/rm2c","door2",
"/players/fakir/genji/rm4c","door3",
"/players/fakir/genji/rm1a","door4",
});
}
init()  {
  ::init();
    add_action("strike_terangreal","strike");
    add_action("steal_terangreal","steal");
}
strike_terangreal(arg)  {
if(!arg || arg != "ter'angreal") {
notify_fail("\nA hoarse voice hisses:\n\n"+
         MAGENTA+"'Try striking the ter'angreal instead.'\n"+OFF);
return 0; 
}

if(rod==2) {write("\nA hoarse voice hisses:\n\n"+
            MAGENTA+"'You cannot strike the ter'angreal. It has been stolen.'\n"+OFF); 
            say("\nA hoarse voice hisses:\n\n"+
            MAGENTA+"'Someone has tried to strike the ter'angrael, but it has been stolen.'\n"+OFF);
return 1;
}
if(found==0) { tell_room(this_object(),"\nA hoarse voice hisses:\n\n"+
             MAGENTA+"     'The magic within the ter'angreal has been spent. It can\n\n"+
                     "      no longer free any warriors from the wall of glass.'\n"+OFF);  
return 1; }
if(present("digger",this_object())) {
write("\nA hoarse voice hisses:\n\n"+
      MAGENTA+"'You must kill this warrior before you can strike the ter'angreal again.'\n"+OFF);
say("\nA hoarse voice hisses:\n\n"+
      MAGENTA+"'Someone has tried to summon another warrior. This warrior must be killed first.'\n"+OFF);
return 1;
}

write("\nA hoarse voice hisses:\n\n"+
        MAGENTA+"'You struck the ter'angreal.  I shall release a warrior!'\n\n"+OFF+
        RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  say("\nA hoarse voice hisses:\n\n"+
      MAGENTA+"'"+this_player()->query_name()+" has struck the ter'angreal. I shall release a warrior!'\n\n"+OFF+
      RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1;  

}

steal_terangreal(arg) {
if(!arg || arg != "ter'angreal") {
notify_fail("A distant voice hisses:\n\n"+
            CYAN+"'Try stealing the ter'angreal instead.'\n"+OFF);
return 0;
}

if(rod==2) {tell_room(this_object(),"\nA distant voice hisses:\n\n"+
                     CYAN+"Try as you may, you cannot steal that which has already been stolen.\n"+OFF);
return 1;
}
if(rod==1) {tell_room(this_object(),"\nA distant voice hisses:\n\n"+
                     CYAN+"You cannot steal the ter'angreal once it has been struck for combat.\n"+OFF);
return 1;
}

write(CYAN+"You steal the ter'angreal. It bonds with your soul, and your eyes "+BOLD+GREEN+"glow"+CYAN+".\n"+OFF);
move_object(clone_object("/players/fakir/genji/OBJ/circle.c"),this_player());
rod=2;
return 1;
}

