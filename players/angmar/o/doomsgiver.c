/* Recode of Doomsgiver - Rumplemintz */
#pragma strong_types

inherit "obj/weapon";

void
reset(status arg) {
  if (arg)
    return;
  set_name("doomsgiver");
  set_alias("angmar_doomsgiver");
  set_short("Doomsgiver");
  set_long(
"This is avery powerful sword.  You feel a magic aura surrounding it.\n" +
"There is something written on it.\n");
/* Changing this until i figure out why everyone has a '0' alignment
  set_class(22);
-- Rumplemintz */
  set_class(4);
  set_value(5000);
  set_weight(5);
  set_read(
"The language is very old.  You can hardly understand it, but the \n" +
"sword seems to have been owned by Angmar himself.\n");
  set_heart_beat(1);
  wielded = 0;
  value = 0;
}
  
void
heart_beat() {
  object plr;
  int al;
  
  if(!wielded) {
     set_heart_beat(0);
     return;
  }
  plr = environment(this_object());
  if (!living(plr)) {
    set_heart_beat(0);
    return;
  }
  al = (int)plr->query_alignment();
  if ((al >- 900) &&
      ((string)this_player()->query_name() != "Rumplemintz")) {
    tell_object(plr,"Your Doomsgiver seems to come alive!\n");
    plr->drop_one_item(this_object());
    say("The Doomsgiver wriggles out of "+plr->query_name()+"'s hands.\n");
    set_heart_beat(0);
  }
}

void
init() {
  ::init();
  add_action("wield", "wield");
}

status
wield(string str) {
  if (((int)this_player()->query_alignment() < 200) ||
      ((string)this_player()->query_name() == "Rumplemintz")) {
    ::wield("doomsgiver");
    set_heart_beat(1);
    return 1;
  }
  write("You can't wield Angmar's sword. Maybe you're not evil enough...\n");
  say(this_player()->query_name()+" failed to wield Doomsgiver\n");
  return 1;
}
