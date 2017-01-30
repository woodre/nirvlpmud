inherit "obj/armor";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("amulet");
  set_alias("watcher_amulet");
  set_short("A strangely-designed amulet");
  set_long(
"A small metal amulet strung onto a long leather thong.  The design on the\n"+
"amulet itself looks almost like the peace sign, except that the crossing\n"+
"lines are bent into curves instead of meeting at a point, and there are\n"+
"eight dots arranged around the inner sign at equal intervals.\n");
  set_type("amulet");
  set_ac(0);
  set_value(0);
}
