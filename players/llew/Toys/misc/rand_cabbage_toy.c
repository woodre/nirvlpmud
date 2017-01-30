inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   switch(random(3)+1) {
      case 1:
         set_id("pacifier");
         set_short("A baby pacifier");
         set_long("The plastic pacifier has drool on it.  Ewww...\n");
      case 2:
         set_id("bottle");
         set_short("A baby bottle");
         set_long("The plastic bottle has white paint along the inside.\n");
      case 3:
         set_id("diaper");
         set_short("A baby diaper");
         set_long("The plastic diaper isn't empty.\nYou don't want to know what's inside...\n");
   }
   set_value(50);
   set_weight(1);
   set_dest_flag(1);
}
