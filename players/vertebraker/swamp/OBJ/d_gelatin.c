#include "../define.h"
inherit ITEM;

reset(arg) {
   if(arg) return;
   set_id("blob");
   set_alias("gelatin");
   set_short("a strange blob of gelatin");
   set_long(
      "Gooey and amorphous, this is a blob of gelatin.  It twinkles\n"+
      "occasionally, and seems to stick when you rub it.\n");
   set_weight(1);
   set_value(3000+random(1000)); }

init() {
   ::init();
   add_action("rub","rub"); }

rub(str) {
   object boots, shadow;
   if(!str) {
      FAIL("Rub your gelatin on what?\n");
      return 0; }
   if(str == "on boots" || str == "boots" || str == "gelatin"
      || str == "gelatin on boots" || str == "gelatin boots")
   {
      boots = present("boots",TP);
      if(!boots || boots->query_type() != "boots") {
        FAIL("Huh? You don't have any boots.\n");
        return 0; }
   shadow = clone_object("/players/vertebraker/swamp/OBJ/boots_shadow");
   write("You rub the gel furiously on your "+boots->short()+".\n");
   say(TPN+" rubs the gelatin furiously on "+possessive(TP)+" "+boots->short()+".\n");
   shadow->start_shadowing(boots);
   TP->add_weight(-1);
   destruct(TO);
   return 1;
   }
}
