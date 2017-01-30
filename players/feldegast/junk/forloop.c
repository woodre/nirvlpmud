inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("wand");
  set_short("Wand of Repetition");
  set_long("This is the wand of repetition.  You can 'wave' it.\n");
  set_weight(1);
  set_value(1);
}

void init()
{
  add_action("cmd_wave", "wave");
}

int cmd_wave(string str)
{
  int i;
  if(str!="wand")
  {
    notify_fail("Wave what?\n");
    return 0;
  }
  for(i = 0; i < 4 + random(4); i++)
  {
    write("Iteration " + i + "\n");
  }
  return 1;
}
