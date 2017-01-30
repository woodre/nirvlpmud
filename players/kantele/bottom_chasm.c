#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("You are in the bottom of the chasm");
  set_long(
"You are in the bottom of the chasm, it seems impossible to get out!!\n");
}
