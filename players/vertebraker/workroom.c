inherit "/room/room";

void reset(status arg)
{
  if(arg) return;

  ::reset(arg);
  set_light(1);

  set_short("A very dusty workroom");
  set_long("A very dusty workroom.\nThere are crumpled papers all over the floor.\n");
  dest_dir=({ "/room/adv_inner", "wizhall", });
}
