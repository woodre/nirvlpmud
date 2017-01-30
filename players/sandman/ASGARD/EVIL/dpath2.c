inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a dirt path [n,sw]");
   long_desc=
     "The path is narrow and winding here. A dim eiry light filters down\n"
+    "through the trees to illuminate the path. The trees themselves look\n"
+    "to be ancient. They are knarled and twisted together. As you pass\n"
+    "the trees seem to shudder.\n";
   items=
   ({
     "dirt path", "Little used dirt path",
     "trees","Tall knarled trees that seem to move when your back is turned",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/EVIL/dpath4","north",
     "players/sandman/ASGARD/EVIL/dpath1","southwest",
   });
}
