inherit "players/fred/closed/bloodfist/obj/desert_inherit";
#include "/players/fred/closed/bloodfist/defs.h"
int b;
object npc, trs;

reset(arg){
 if(!arg){

   for(b = 0; b < 3; b++)
   {
     npc = clone_object(DIR+"NPC/skirmisher.c");
     move_object(npc, this_object());
     if(b == 0)
     {
       trs = clone_object(DIR+"eq/hooked_dagger.c");
       move_object(trs, npc);
       command("wield dagger", npc);
     }
     else if(b == 1)
     {
       trs = clone_object(DIR+"obj/alabaster_potion.c");
       move_object(trs, npc);
     }
     else if(b == 2)
     {
       trs = clone_object("/obj/treasure.c");
       trs -> set_alias("key");
       trs -> set_id("rib cage key");
       trs -> set_short("the rib cage key");
       trs -> set_long(
         "This is an old, tarnished looking key that has a very peculiar\n"+
         "design.  The handle of the key resembles a human rib cage that\n"+
         "has been torn open.  It looks like a very unique key.\n");
       trs -> set_weight(2);
       trs -> set_value(286);
       move_object(trs, npc);
     }
   }

  long_desc=
"  You have come to a small tent that has been set up in the middle of\n"+
"the desert.  The wind is blowing strongly through the area, causing\n"+
"the tent to flap violently.  The desert seems to stretch on in every\n"+
"direction from here.  The sky above is a mass of chaotic darkness.\n"+
"    There is one obvious exit: leave\n";
  items=({
  "sky",
"The sky is a luminous mass of dark swirls.  The wind causes it to\n"+
"constantly writhe and shift above you",
  "wind",
"The wind is blowing all around you, blowing the sand which obscures\n"+
"your vision",
  "sand",
"Bits of sand writhe at your feet, as well as fly past your face.  The\n"+
"wind which never seems to stop makes the sand almost seem alive",
  "ground",
"The ground seems so lifeless and dead.  It is hard and flat, lined with\n"+
"dry cracks which run ever so deep.  Life does not seem to have existed\n"+
"here for ages",
  "rocks",
"Small rocks are littered across the ground, mingling with the sand",
  "tent",
"The tent is in poor shape, but looks as though it still provides good\n"+
"protection from the blowing winds of the desert",
  });
 }
}
