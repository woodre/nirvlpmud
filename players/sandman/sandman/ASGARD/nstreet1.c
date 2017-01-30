inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a red brick road [n,s,e]");
   long_desc=
   "This red brick road runs north and south. To the east is a majestic\n"+
   "marble building trimmed in silver. The doors of the building stand\n"+
   "wide open, welcoming all to enter.\n";
   items=
   ({
     "red road","This road is paved with glazed brick",
     "building","As you look closer, You see this building is the Library",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/nstreet2","north",
     "players/sandman/ASGARD/mstreet1","south",
     "players/sandman/ASGARD/LIB/entrance","east",
   });
}
