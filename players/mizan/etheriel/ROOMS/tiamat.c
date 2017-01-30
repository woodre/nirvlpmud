inherit "/players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Center of Mass";
long_desc="\tA cold, sweeping sense of death sweeps up your spine, as\n"+
"  you feel half there already. Caught in the grip of a massive gravity\n"+
"  crunch, you stare up and before you lies the most incredible monstrosity\n"+
"  of a dragon that you have ever seen...\n";
}

ekg(str) { 
  write_file("/players/mizan/logs/TIAMAT", "**" + (this_player()->query_name()) + "** " + query_verb()+ " " + str + "\n");

  return 0;
}

init() {
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
   add_action("ekg", "", 3");
#endif
  ::init();
}
extra_reset() {
  object_names=({
    "players/mizan/closed/tiamat6.c"
  });
  ::extra_reset();
}
