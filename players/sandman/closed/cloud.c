inherit "room/room";

init() {
   ::init();
   add_action("read","read");
}

read(str) {
   if(str == "sign") {
   cat("/players/sandman/KRIL/CORAL/sign1");
   return 1;
   }
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("valley of the secrets");
   long_desc=
     "There are many places in the Dream Lord's realm. Some ordinary, some\n"
+    "horrific, some fantastic, but each the reflection of reality, a dream.\n"
+    "You stand now in the very first of these reflections ever to be.\n"
+    "The first dream to be envisioned in the mind of the creator himself.\n"
+    "This is the dream of the 7 secrets of creation, and with this dream\n"
+    "came the creation of all things. Surrounding the valley floats soft\n"
+    "ethereal clouds. At the four points of the compass, huge stone spires\n"
+    "rise up through the clouds. Atop these spirals stand statues of the\n"
+    "four heralds of God guarding the secrets with cold resolve.\n"
+    "The center of the valley is spanned by a sprawling green field. The\n"
+    "grass as soft and fresh as if it were the first day of creation.\n"
+    "A choir of angels hover around the edge of the valley, singing endless\n"
+    "praise to the first and last dream. In the center of the field stands\n"
+    "a small simple altar of rough granite. Surrounding the altar are seven\n"
+    "precious stones glowing softly as if they were alive.\n";
   items=
   ({
   "clouds","These clouds circle the green valley, running off into the\n"
           +"horizon as far as you can see. They sparkle with a pure inner\n"
           +"radiance\n",
   "spires","These spires look to be made of light grey granite. They rise\n"
            +"up through the clouds at the points of the compass.\n",
   "statues","These are exquisite life size statues of the four heralds of\n"
             +"God. Raphel to the west, Auriel to the east, Michael to the\n"
             +"south, and Gabriel to the North.",
   "altar","The altar is made of a simple granite. Small wild flowers of all\n"
           +"colors grow around it, and age old vines crawl up its base. A\n"
           +"single violet lies atop of the altar.\n",
   "stones","Seven stones ring the alter, each glowing softly with thier own\n"
            +"color. Each holding one of the secrets of creation.\n",
   "field","The green grass of the field is intermingled with small wild\n"
           +"flowers dotting the green landscape with dots of color.\n",
   });
   dest_dir=
   ({
     "players/sandman/KRIL/CORAL/square1","north",
     "players/sandman/KRIL/SURR/scoral","south",
   });
}
