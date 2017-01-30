inherit "/obj/treasure.c";

void reset(int arg)
{
  set_id("wand");
  set_short("Waving Wand");
  set_long("A wand for waving. <wave> to use it.\n");
}
void init()
{
  add_action("cmd_wave","wave");
  add_action("cmd_wave2","wave2");
}
status cmd_wave(string str)
{
  write("You wave the wand and feel silly.\n");
  say((string)this_player()->query_name()+" waves a wand.\n");
  return 1;
}
static cmd_wave2(string str)
{
  write("You have the wand and feel REALLY silly.\n");
  say((string)this_player()->query_name()+" waves a wand.\n");
  return 1;
}
