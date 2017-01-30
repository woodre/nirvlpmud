inherit "room/room";
reset(arg) {
  if(arg) return ;
  set_light(1);
  short_desc = "Taco Bell";
  long_desc  =
 "In an act of desperation, it appears you made a run for the border.\n"
+"You are standing in a small fast food joint, apparently serving 'mexican'\n"
+"(by some fools standards) food. If you are brave enough to eat here, then\n"
+"the commands are: list food, buy <item>.\n";
  dest_dir   =
  ({
  "players/wizardchild/mall/entry", "east"
  });
  move_object(clone_object("players/wizardchild/mall/tbseller"),this_object());
}
