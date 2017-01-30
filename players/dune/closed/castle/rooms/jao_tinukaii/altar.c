inherit "room/room";
#include "definitions.h"

int kneel;
int mirror;

void init() {
        add_action("search","search");
        add_action("kneel","kneel");
::init();
}

reset(arg) {

  mirror=0;
  kneel=0;
  if(!present("amodezius"))
   move_object(clone_object(CASTLEMONSTER+"/devil_greatera.c"),this_object());

        if(!arg) {
        kneel=0;
        mirror=0;
        set_light(1);
        short_desc="Altar";
        long_desc=
"     Blazing fire and swirling smoke seem to envelope the room.  Huge\n"+
"pedestals which erupt fire circle a heptagram.  A great mirror lies\n"+
"opposite the stairs.  The room glows a strange red hugh, and shadows\n"+
"dance wildly and unrealistically around the charcoal burnt walls.\n"+
"A towering altar of black ebony encases the mirror.  The figure it\n"+
"represents is purely diabolic, with three horns on its head.  The horns\n"+
"are on fire, yet the wood does not burn.\n";

   dest_dir=({
        CASTLEROOM+"/pews.c","south"  ,
            });

   items=({
        "pedestals",
"     The ten foot tall black pedestals shoot billows of flame up at the\n"+
"ceiling.  You can feel the intense heat from where you are standing.\n"+
"The flame comes from an unknown source",
        "mirror",
"     The mirror is embedded in the ebony of the altar.  It glows a faint\n"+
"orange color.  As you look into it, you stand horrified at what you\n"+
"see on the other side.  A horribly evil face stares at your soul.\n"+
"You stand paralyzed at the power and negative force of the being.\n"+
"It speaks in a chilling whipser, 'Kneel before me mortals, and I shall\n"+
"reward you.  But if you defy me, I shall have your puny existances\n"+
"wiped from the face of the land.  I'll make sure your afterlife is\n"+
"spent tortured by hideous beings.'  The image fades, and your muscles\n"+
"relax.\n"+
"     It is very fortunate that this being of immense powers lies on\n"+
"the other side of the portal",
        "altar",
"     The altar nearly touches the charred ceiling.  It is the complete\n"+
"embodiment of evil and the powerful being for which it represents.\n"+
"Huge words are carved into the ebony.  They read the name of death,\n"+
"evil, and destruction;\n"+
"               D   E   M   O   S   A   T   E   R\n"+
"You fear the utter power and enormity of the being.  His presence can\n"+
"be felt, even though he is damned in Hell",
   });
   }   }

search(str) {
  if (!str) {
    write("What do you search?\n");
    return 1;}
  if (str == "mirror") {
    if (mirror==0) {
      write(
"     You search the huge mirror.  As you search, you see a shining\n"+
"mace inside the mirror.  It sparkles with a white glow and floats\n"+
"down to your feet.\n");
      move_object(clone_object(CASTLEOBJECT+"/cursed_mace.c"),this_object());
      mirror=1;
      }
      else {
        write("You peer into an empty void, you soul grows cold.\n");
        }
    return 1;}
  if (str == "altar") {
    write(
"     You search the altar and find nothing, but as you give up, the\n"+
"altar glows a black radiance.  You feel lost inside, and shiver from\n"+
"the cold emptiness you feel.  You touch the altar, and you feel better.\n"+
"The negative energy warms and comforts you.  You feel like you belong\n"+
"to Demosater, yet you still have the strength to pull away.  Yelling\n"+
"in anger you pull yourself away, only to hear a distant laugh.  The\n"+
"emptiness is still there.\n");
    return 1;}
}

int kneel(string str) {
   write("You kneel before the altar of Demosater.\n");
   if (kneel == 0) {
   write(
"     At first, nothing happens, then, you hear a distant bending and\n"+
"cracking of wood.  The altar's head starts moving, then, it speaks:\n"+
"   'Don't you know I don't need you.  You are nothing to me.  Your\n"+
"    foolish act of submission will cost you your life.'\n"+
"The altar then bends back into its original position, and the mirror\n"+
"glows a greenish hugh.  From out of the mirror pounces a disgusting\n"+
"and foul looking devil dog.  But this is no ordinary canine...\n");
     move_object(clone_object(CASTLEMONSTER+"/devil_lesserc.c"),this_object());
     kneel=1;
     }
     else {
       write("Somehow the magic is gone, you kneel in futile submission.\n");
       }
return 1;}
