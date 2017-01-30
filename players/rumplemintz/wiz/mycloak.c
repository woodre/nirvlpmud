#include <ansi.h>

inherit "obj/armor";

void reset(int arg){
   if(arg) return;
  set_short(HIB + "Rump's cloaks" + NORM);
  set_long(HIB + "Rump's " + NORM + "personal armor.\n");
   set_save_flag(0);
   set_params("other|sleaze",0,100,0);  /* Mizan's area */
   set_params("other|manliness",0,100,0); /* Mizan's area */
   set_params("other|blades",0,100,0);  /* Mizan's area */
   set_params("other|radiation",0,100,0); /* Mizan's area */
   set_params("other|cold",0,100,0); /* Mizan's area */
   set_params("other|acid",0,100,0); /* Mizan's area */
   set_params("other|lightning",0,100,0); /* Mizan's area */
   set_params("other|dark",0,100,0);
   set_params("other|light",0,100,0);
   set_params("other|water",0,100,0);
   set_params("other|fire",0,100,0);
   set_params("other|wind",0,100,0);
   set_params("other|earth",0,100,0);
   set_params("other|ice",0,100,0);
   set_params("other|electric",0,100,0);
   set_params("other|laser",0,100,0);
   set_params("other|evil",0,100,0);
   set_params("other|good",0,100,0);
   set_params("other|poison",0,100,0);
   set_params("other|poisen",0,100,0); /* Jareel mispelling poison... */
   set_params("other|physical",0,100,0); /* Jareel again... */
   set_params("other|spirit",0,100,0);   /* Jareel... */
   set_params("other|Jareel",0,100,0);   /* Jareel... */
   set_params("other|electricity",0,100,0); /* Jareel... */
   set_params("other|magical",0,100,0);  /* Jareel... */
   set_params("other|electric|wind",0,100,0); /* Jareel... */
   set_params("other|sonic",0,100,0);
   set_params("other|mental",0,100,0);
   set_params("magical", 0, 100, 0);
   set_params("physical", 0, 100, 0);
   set_ac(1000);
   set_weight(1);
   set_value(60000);
   set_alias("cloaks");
   set_name("cloaks");
   set_type("misc");
   set_arm_light(10);
}
