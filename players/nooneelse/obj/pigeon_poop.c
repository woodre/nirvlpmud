/*
  pigeon_poop.c - what can i say.  i got bored!
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
  if (duration_timer==600) destruct(this_object());
}

short() { return "A blob of sticky white...something"; }

long() {
  write(short()+".\n");
  if (this_player()->query_real_name()=="nooneelse")
    write("   [Timer till poop goes away="+duration_timer+" (600)]\n");
}

get() {
  write("Huh?  You want to pick up a pile of pigeon crap?\n");
  return;
}

id(str) { return str=="pigeon poop" ||
                 str=="wolf_poop" ||
                 str=="poop" ||
                 str=="pile" ||
                 str=="shit"; }

