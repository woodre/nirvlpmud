inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_long(
   " The fine cloak of Shairo Jacor. The cloak constantly changes\n"+
   "colors to fit it's surroundings.  Made from maijan skin, it\n"+
   "is very protective.  The color changing effect comes from the\n"+
   "mages of Sivart inverting a weave of spirit and light energy.\n");
  set_type("misc");
  set_ac(2);
  set_weight(2);
  set_value(2000);
}
short()
{
  string blah;
  int x;
  x = random(5);
  switch(x)
  {
   case 0:
     blah = HIR;
     break;
   case 1:
     blah = HIY;
     break;
   case 2:
     blah = HIW;
     break;
   case 3:
     blah = HIB;
     break;
   case 4:
     blah = BLU;
     break;
   }
   if(worn)
      return "A "+blah+"Color-changing cloak"+NORM+" (worn)";
   else
      return "A "+blah+"Color-changing cloak"+NORM;
}
