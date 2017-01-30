inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   switch(random(6)+1) {
      case 1:
         set_id("lips");
         set_short("Potato lips");
         set_long("The smiling lips of a potato head.  They are plastic.\n");
         break;
      case 2:
         set_id("ear");
         set_short("Potato ear");
         set_long("The funny shaped ear of a potato head.\n");
         break;
      case 3:
         set_id("nose");
         set_short("Potato nose");
         set_long("A long pointy nose of a potato head.\n");
         break;
      case 4:
         set_id("eye");
         set_short("Potato eye");
         set_long("A squinty blue eye of a potato head.\n");
         break;
      case 5:
         set_id("glasses");
         set_short("Potato glasses");
         set_long("Red framed thick reading glasses for a potato head.\n");
         break;
      case 6:
         set_id("hair");
         set_short("Potato hair");
         set_long("Short cropped black hair of a potato head.\n");
         break;
   }
   set_value(75);
   set_weight(1);
   set_dest_flag(1);
}
