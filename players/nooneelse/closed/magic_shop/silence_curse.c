/*
  silence_curse.c - This is a curse that the player can't get rid of
                    that prevents them from shouting, telling & screaming.
*/

short() { return "A sore throat"; }

long() { write("How can you look at a curse ?\n"); }

drop() { return 1; }

init() {
  add_action("do_silence", "say");
  add_action("do_silence", "tell");
  add_action("do_silence", "whisper");
  add_action("do_silence", "scream");
  add_action("do_silence", "shout");
  add_action("do_silence", "gossip");
  add_action("do_silence", "equip");
  add_action("do_silence", "risque");
  add_action("do_silence", "junk");
}

do_silence() {
  if (query_verb()=="tell" || query_verb()=="say" || query_verb()=="whisper" ||
      query_verb()=="gossip" || query_verb()=="equip" ||
      query_verb()=="risque"|| query_verb()=="junk")
    write("You can't talk with a sore throat!\n");
  if (query_verb()=="scream") write("You can't scream with a sore throat!\n");
  if (query_verb()=="shout") write("You can't shout with a sore throat!\n");
  say(this_player()->query_name()+" makes croaking sounds.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  call_out("destruct_this", 900);
}

destruct_this() {
  if (environment(this_object()))
    tell_object(environment(this_object()), "Your throat feels better.\n");
  destruct(this_object());
  return;
}


id(str) { return str=="silence_curse" || str=="curse"; }
