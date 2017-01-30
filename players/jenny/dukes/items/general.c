#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int justone;
reset(int arg) {
   if(arg) return;
   set_id("general lee");
   set_alias("general");
   set_short(RED+"The General Lee"+NORM);
   set_long(
      "The General Lee is a souped up 1969 Dodge Charger.  It is\n"+
      "painted bright orange with the number '01' painted onto the\n"+
      "sides.  A confederate flag is painted on the roof, and the horn\n"+
      "plays the first few notes of 'Dixie'.  The doors are welded\n"+
      "shut, so you have to enter through the windows.  The General\n"+
      "can outrun any car in Hazzard county, and can jump over\n"+
      "almost anything that gets in it's way.  This car belongs to Bo\n"+
      "and Luke Duke.  You might try opening the trunk.\n");
   set_value(0);
   set_dest_flag(1);
}
init() { 
   ::init(); 
   add_action("weapon","open");
}
weapon(arg) {
   if(!arg) { return 0; }
   if(present("bo duke") || present("luke duke")) {return 0;}
   if(justone == 2) {write("Someone already cleaned out the trunk.\n"); return 1; }
   if(arg == "trunk" && justone != 2) {
      if(!this_player()->add_weight(3)) {
         write("You can't carry that.\n");
         return 1; }
      write(""+CYN+"You take a bow and arrow from the trunk."+NORM+"\n");
      MOCO("/players/jenny/dukes/items/bow.c"),TP);
justone = 2;
return 1; }
}
get() {write(YEL+"You can't take the General Lee."+NORM+"\n"); }
