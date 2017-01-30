inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a dirt path [nw,ne,s]");
   long_desc=
   "This is a dark densly packed forest. The trees are crooked and bent,\n"
+  "intertwining with each other to block out the sun. the path continues\n"
+  "to the northeast, or south back to the main road.\n";
   items=
   ({
     "dirt path", "Little used dirt path",
     "trees","Tall knarled trees that seem to move when your back is turned",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/mstreet2","south",
     "players/sandman/ASGARD/EVIL/dpath2","northeast",
   });
}
