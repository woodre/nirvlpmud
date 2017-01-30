inherit "room/room";



reset(arg) {
     if(!present("peasant")) {
move_object(clone_object("players/sandman/KRIL/MON/peasant"), this_object());
     }
     if(!present("merchant")) {
move_object(clone_object("players/sandman/KRIL/MON/merchant"), this_object());
   }
   if(arg) return;
   set_light(1);
   short_desc=("southern square");
   long_desc=
   "You have entered the great south square. Hundreds of people from all\n"
+  "walks of life brush past you on thier way to one place or another. To\n"
+  "the south the great mithril gates stand. To the north the main road\n"
+  "bisects the city. East and west runs the old Wall road.\n";
   dest_dir=
   ({
     "players/sandman/KRIL/CORAL/main1","north",
     "players/sandman/KRIL/CORAL/sgate","south",
     "players/sandman/KRIL/CORAL/wall_e1","east",
     "players/sandman/KRIL/CORAL/wall_w1","west",
   });
}
