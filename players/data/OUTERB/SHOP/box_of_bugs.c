

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("bugs");
  add_alias("box");
  add_alias("bugs");
  set_short("A box with bugs");
  set_long("A box with some bugs in it, you feel revolted, but it may be filling, just 'eat' a bug.\n");
  set_type("eat");
  set_msg("You take a bug out of the box, and choke it down barely able to hold it in.\n");
  set_msg2(" takes a bug out of a box and swallows it without chewing.\n");
  add_cmd("eat");
  set_heal(30,30); /* hp,sp */
  set_charges(3);
  set_stuff(12);
  set_value(200); /* This is per charge */
}
