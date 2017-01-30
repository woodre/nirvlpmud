inherit "room/room";

init() {
   ::init();
   add_action("read","read");
}

read(str) {
   if(str == "sign") {
   cat("/players/sandman/ASGARD/SIGN2");
   return 1;
   }
}

reset(arg) {
   if(arg) return;
   set_light(1);
    short_desc = "a street";
   long_desc=
    "The main street runs east and west here. To the north is a dirt path\n"
+   "leading to a dense forest. To the south is a store. Rising up to the\n"
+   "east is a tall solitary mountain peek. In the center of the road is\n"
+   "sign.\n";
   items=
   ({
     "dirt path","a small dirt path, It looks very old",
     "store","Grinbale Lmt. trading company",
     "sign","It is a nice sign, perhaps you should 'read' it",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/EVIL/dpath1","north",
     "players/sandman/ASGARD/shop","south",
     "players/sandman/ASGARD/mstreet3","east",
     "players/sandman/ASGARD/mstreet1","west",
   });
}
