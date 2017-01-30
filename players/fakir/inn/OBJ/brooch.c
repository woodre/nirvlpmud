inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("brooch");
   set_short("A jeweled brooch");
   set_long(
   "A delicate silver brooch inlaid with small jewels of\n"+
   "different colors and sizes.  It sparkles in your hand.\n");
   set_weight(1);
   set_value(600);
}

