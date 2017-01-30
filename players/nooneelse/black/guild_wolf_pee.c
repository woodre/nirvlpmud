/*
  guild_wolf_pee.c - what can i say.  i got bored!
*/

int duration_timer;

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  enable_commands();
  set_heart_beat(1);
}

heart_beat() {
  duration_timer++;
  if (duration_timer==300) destruct(this_object());
}

short() { return "A puddle of yellowish water"; }

long() {
  write(short()+" that has a sharp acidic odor.\n");
  if (this_player()->query_real_name()=="nooneelse")
    write("   [Timer till pee goes away="+duration_timer+" (300)]\n");
}

get() {
  write("Pick up a puddle of pee?  I think not!\n");
  return;
}

id(str) { return str=="puddle" ||
                 str=="wolf piss" ||
                 str=="wolf_piss" ||
                 str=="guild_wolf_piss" ||
                 str=="wolf_pee" ||
                 str=="guild_wolf_pee" ||
                 str=="piss"; }
