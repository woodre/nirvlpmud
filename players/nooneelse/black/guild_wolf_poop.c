/*
  guild_wolf_poop.c - what can i say.  i got bored!
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

short() { return "A pile of brown...something"; }

long() {
  write(short()+", that really stinks!  Has a dog been in here?\n");
  if (this_player()->query_real_name()=="nooneelse")
    write("   [Timer till poop goes away="+duration_timer+" (600)]\n");
}

get() {
  write("Huh?  You want to pick up a pile of fresh dog crap?\n");
  return;
}

id(str) { return str=="wolf poop" ||
                 str=="wolf_poop" ||
                 str=="guild_wolf_poop" ||
                 str=="poop" ||
                 str=="pile" ||
                 str=="shit"; }
