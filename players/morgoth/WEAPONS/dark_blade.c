/*
Increased weight to 4 from 2 because of the description.
Increased wc to 16 from 9 because of the description.
-Feldegast 10-6-00
*/
inherit "obj/weapon";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("dark blade");
  set_alias("blade");
  set_short("Dark Blade");
  set_long("A very heavy and very large blade.  It is made from the\n"+
           "same alloy as the dark armor.\n");
  set_value(200);
  set_weight(4);
  set_class(16);
}
