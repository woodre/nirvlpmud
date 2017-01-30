inherit "/obj/treasure.c.rump";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_id(({ "item", "treasure", "tester", "beer" }));
  set_weight(1);
  set_name("beer");
  set_short("A beer");
  set_long(
"A beer that should have id's: item, treasure, tester, beer\n");
  set_value(100);
  set_read("Hi, you're reading me!\n");
}
