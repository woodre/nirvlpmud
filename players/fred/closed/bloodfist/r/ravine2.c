inherit "room/room";       /* ravine2 */

reset(arg){
 if(!arg){

  set_light(0);
  long_desc=
"  This isolated ravine is very hidden within the mountains.  It winds\n"+
"along a very narrow path to the north from here.  To the south it opens\n"+
"up beyond the edge of the mountains.  The dark sky overhead is a mass\n"+
"of blowing sand.  There are various small rocks scattered across the\n"+
"dry, hard ground.  It is increadibly warm here as the hot wind whips\n"+
"down through the ravine.\n";
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
  dest_dir=({  "/players/fred/closed/bloodfist/r/ravine1.c", "north",
               "/players/zeus/desert/r/ec4.c",               "south",  });
 }
}

short(){ return "inculta creperum"; }

void init(){
  ::init();
  "/players/zeus/desert/OBJ/desert_daemon.c"->load_npcs();
}
