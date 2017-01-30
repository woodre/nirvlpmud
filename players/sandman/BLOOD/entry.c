inherit "room/room";

init() {
   ::init();
   add_action("read","read");
}

read(str) {
   if(str == "sign") {
   cat("/players/sandman/BLOOD/MISC/sign1");
   return 1;
   }
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("wizard's folly");
   long_desc=
   "A smooth gray waste of stone spreads before you. Not natural rock or\n"
+   "even the crafted stone of men, but stone none the less. Smooth and\n"
+  "shinny as if it had been melted by an unimaginable heat, the stone extends\n"
+   "jagged irregular sheets pierced only by the narrow winding road that has\n"
+  "chisled into the ground.\n"
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
