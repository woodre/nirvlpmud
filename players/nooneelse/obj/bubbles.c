/*
  bubbles.c - a bubble pipe
  modified for junk channel only. -Bp
*/

inherit "/obj/treasure";

init() {
  ::init();

  add_action("blow_bubbles", "blow");
}

blow_bubbles(str) {
  object obj;
  string who;
  int i;

  if (!str || str!="bubbles") return 0;
  /* send one to everyone except people in the editor */
  who=users();
  for (i=0; i<sizeof(who); i++) {
    if (!in_editor(who[i])) {
   if (who[i]->on_channel("junk"))
      tell_object(who[i],
        "As you look up, you see several huge, transparent bubbles floating\n"+
        "around in the air.\n");
    }
  }
  call_out("bubbles_2", 6);
  return 1;
}

bubbles_2() {
  object obj;
  string who;
  int i;

  who=users();
  for (i=0; i<sizeof(who); i++) {
    if (!in_editor(who[i])) {
   if (who[i]->on_channel("junk"))
      tell_object(who[i],
        "A four foot tall bubble drifts toward you and hangs there for a "+
        "moment.\n");
    }
  }
  call_out("bubbles_3", 6);
  return 1;
}

bubbles_3() {
  object obj;
  string who;
  int i;

  who=users();
  for (i=0; i<sizeof(who); i++) {
    if (!in_editor(who[i])) {
   if (who[i]->on_channel("junk"))
      tell_object(who[i],
        "The bubble drifts over and pops quietly as it "+
        "touches you on the nose.\n");
    }
  }
  return 1;
}


reset(arg) {
  if (arg) return 0;

  set_id("bubble pipe");
  set_alias("pipe");
  set_short("A bubble pipe");
  set_long("A bubble pipe.  Use: blow bubbles\n"+
           "\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(10);
  set_weight(1);
}
