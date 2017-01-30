
inherit "obj/treasure";
reset(arg)
  {
   if (arg) return;
   set_id("log");
   set_short("A bulky log");
   set_long("A heavy log, apparently the remains of a fruit tree.Vermin\n"+
     "have eaten the roots and the brittle branches snap away, but the\n"+
     "main trunk is still somewhat sound.\n");
   set_weight(4);
   set_value(0);
   }

