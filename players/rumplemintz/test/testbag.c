/*
 * Test Bag - infinite bag - do not use
 */

inherit "/obj/container";

void
reset(status arg)
{
  if (arg)
    return;
  set_name("bag");
  set_short("An illegal bag");
  set_long("An illegal bag of holding.\n");
  set_weight(0);
  set_value(-1);
  set_max_weight(1000000);
}

status
query_save_flag()
{
  return 1;
}
