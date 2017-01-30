inherit "obj/treasure";

reset(arg)
{   if (arg) return;
   set_id("cards");
   set_short("A deck of playing cards");
   set_alias("deck");
   set_long(
     "A deck of finely illustrated playing cards.\n");
   set_weight(0);
   set_value(100);
}
