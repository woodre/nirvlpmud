inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
    short_desc = "a street";
   long_desc=
      "The broad lane ends abruptly at the foot of a mountain. In the side\n"
+     "of the mountain is a dark ominous hole. Scaling the sides of the\n"
+     "peak are truly monsterous stairs leading up the side of the crag.\n";
   items=
   ({
     "mountain","an emense mountain stretching to the sky",
     "dark hole","a mysterious opening into the bowels of the mountain",
      "stairs","gigantic steps carved into the side of the mountain",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/cave","enter",
     "players/sandman/ASGARD/stairs","climb",
     "players/sandman/ASGARD/mstreet2","west",
   });
}
