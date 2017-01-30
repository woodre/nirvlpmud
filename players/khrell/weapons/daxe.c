#include "/players/khrell/define.h"
inherit "/obj/weapon.c";
object ob;
int limit = 5;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("axe");
   set_alias("axe");
   set_short("The Axe of Khorne");
   set_long(
      "This is one of the infamous axes of the blood god Khorne. Countless lives\n"+
      "have been taken and endless skulls sent to the throne of the chaos god. The\n"+
      "cold brass haft sends frenzied throughts of eternal bloodletting and battle \n"+
      "flooding your mind.  The great double axe head bears many dark runes that hurt\n"+
      "your eyes and send you to the brink of bloodlust and endless slaughter.\n");
   set_weight(2);
   set_class(20);
   set_value(3500);
   set_type("axe");
message_hit = ({
        RED+"cut"+NORM," on the arm",
        RED+"cleaved"+NORM," on the chest",
        RED+"chopped"+NORM," over the head",           
        RED+"slashed"+NORM," in the groin",
        RED+"gashed"+NORM," in the ribs",
        RED+"hacked"+NORM," on the leg",
        RED+"slashed"+NORM," in the stomach"
        });
   set_hit_func(this_object());
}
init() {
   ::init();
}