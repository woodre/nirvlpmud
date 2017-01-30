#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short("A place to remember");
   set_long(
      "Winding around some bushes is a path that leads in to an open courtyard.\n"+
      "A granite tablet resting on a large bounder stands in the center of the\n"+
      "courtyard.  A long pole with old glory flying high can be seen to the\n"+ 
      "north.  Velvet rails about two feet high circle the boulder.  Stone\n"+
      "benches line the outside of this abode.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "An ashy odor is in the air.\n");
   add_property("NF");
   items = ({
         "some bushes", "Neatly trimmed bushes that line the path",
         "bushes", "Neatly trimmed bushes that line the path",
         "path", "Polished marble stones leading directly to a large boulder",
         "open courtyard", "An open space where the public is allowed to come and reflect on there thoughts",
         "courtyard", "An open space where the public is allowed to come and reflect on there thoughts",
         "abode", "An open space where the public is allowed to come and reflect on there thoughts",
         "granite tablet", "A platform with three brass plates mounted on top of it",
         "tablet", "A platform with three brass plates mounted on top of it",
         "writing", "You can't seem to understand the writing on plate1.  Maybe you could read them?",
         "three brass plates", "A smooth surface with writing etched into it.  You might be able to 'read' the plates",
         "brass plates", "A smooth surface with writing etched into it.  You might be able to 'read' the plates",
         "plates", "A smooth surface with writing etched into it.  You might be able to 'read' the plates",
         "large boulder", "The largest part of the foundation to world trade center one that survived the attacks.\n"+
         "A tablet has been attached to the top of it that you might want to check out",
         "boulder", "The largest part of the foundation to world trade center one that survived the attacks.\n"+
         "A tablet has been attached to the top of it that you might want to check out",
         "long pole", "A pole that reaches into the sky.  Old glory flys high at its top",
         "pole", "A pole that reaches into the sky.  Old glory flys high at its top",
         "old glory", "A symbol that people around the world love and fear", 
         "velvet rails", "An strand of rope dressed in velvet used to keep people from damaging the granite tablet",
         "rails", "An strand of rope dressed in velvet used to keep people from damaging the granite tablet",
         "stone benches", "Seats for the tired who have come here to reflect on the past",
         "benches", "Seats for the tired who have come here to reflect on the past"});
   
   dest_dir = ({
         "/room/farmroad2.c", "out",
         "/players/puppy/mem/2.c", "down"});
   return 1;
}

init()
{
   ::init();
   add_action("blah", "read");
   add_action("blah1", "read");
   add_action("blah2", "read");
   add_action("blah3", "read"); }

blah(str) {
   if(str == "plate" || str == "plates"){
      write("Would you like to read plate1, plate2 or plate3?\n");
      return 1; }
}

blah1(str) {
   if(str == "plate1") {
      "/closed/wiz_soul"->more("/open/puppy/mem/names1");
      return 1; }
}

blah2(str) {
   if(str == "plate2") {
      "/closed/wiz_soul"->more("/open/puppy/mem/names2");
      return 1; }
}

blah3(str) {
   if(str == "plate3") {
      "/closed/wiz_soul"->more("/open/puppy/mem/names3");
      return 1; }
}
