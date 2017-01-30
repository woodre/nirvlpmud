inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
  set_id("flowers");
  set_short("A small bed of pretty flowers");
  set_long("This is a bed of flowers.  It would be a shame to try to pick them...\n");
    set_value(10);
    set_weight(1);
}
get()
{
  write("Ouch !! When you tried to pick the flowers they actually bit you !!!\n");
  return;
}
