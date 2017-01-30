inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a path [e, w]");
   long_desc=
     "The road here is paved with gold bricks. A thick white mist hangs\n"+
     "here. The road leads to the east, or back west to the gate.\n";
   items=
   ({
     "mist","Looking into the mist you see the most pleasant scenes of\n"+
            "your life being replayed. You have trouble pulling your gaze\n"+
            "from the mist\n",
     "bricks","These are solid gold bricks. Too bad they can't be pried up\n",
     "road","The road is paved with gold bricks\n",
   });
   dest_dir=
   ({
      "players/sandman/SURR/path5","west",
      "players/sandman/DAYDREAM/path1","east",
   });
}
