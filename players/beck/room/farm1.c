inherit "room/room";
reset(arg){
   set_light(1);
   short_desc=("Farmland");
   long_desc=
   "This is a large field of farmland.  On the eastern side is a cornfield.\n"+
   "On the western side of the road is for cabbage.  The road appears to be\n"+
   "well used by the farmers that go into Angel Grove to sell thier goods at\n"+
   "the farmers market.  To the south you see a more heavily wooded area.  To\n"+
   "the southeast is a small mountain, and to the north in the distance you\n"+
   "can see the ocean.  A city is east of here.\n"+
   "",
   items=
   ({
         "cornfield","A field of mature butter and sugar corn",
         "cabbage","Some fresh heads of cabbage are growing in the ground here",
         "mountain","A small mountain that appears to solid rock.  You think\n"+
         "you see something unusual on top",
         "ocean","Although it is a ways away, the ocean appears to be very calm",
         "city","A town with a large population.  You believe it to be Angel Grove",
    });
   dest_dir=
   ({
         "players/beck/room/crossroads.c","south",
    });
   if(!present("tractor", this_object())){
      move_object(clone_object("/players/beck/object/tractor.c"), this_object());
   }
}
