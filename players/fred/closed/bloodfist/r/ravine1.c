inherit "room/room";       /* ravine1 */

reset(arg){
 if(!arg){

  set_light(0);
  long_desc=
"  This dark ravine winds through the desolate mountains of the desert.\n"+
"It is pitch black here, and would be very easy to get lost if it was\n"+
"actually possible to deviate from the path.  Both sides of the ravine\n"+
"climb high into the darkness.  Occasional gusts of wind whip down\n"+
"through the ravine, kicking up sand.  It is very hot here.\n";
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
  "path",
"This path leads through the ravine in the mountains",
  "mountains",
"The mountains are all around you, penetrating the endless darkness\n"+
"of the sky",
  "stone",
"The ground is made of dull, brown stone.  It is all very dry and cracked",
  "cracks",
"The ground is lined with small and large cracks",
  });
  dest_dir=({  "/players/fred/closed/bloodfist/r/entrance_out.c", "northwest",
               "/players/fred/closed/bloodfist/r/ravine2.c", "south",  });
 }
}

short(){ return "inculta creperum"; }
