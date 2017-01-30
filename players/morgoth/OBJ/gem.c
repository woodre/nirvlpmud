inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("gem");
  set_short("Yarkdred's Gem");
  set_long("This gem is around four inches in diameter.  It is a deep\n"+
           "blue color and is cut in a traditional round shape.\n");
    set_value(10000);
    set_weight(1);
}
