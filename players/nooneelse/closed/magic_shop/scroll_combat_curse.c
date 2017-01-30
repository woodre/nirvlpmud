/*
  scroll_combat_curse.c - the read/activation mechanism was inspired by boltar's
                          scrolls on nirvana
*/

int scroll_value;
string scroll_type, scroll_target;
object target_obj;

init() {
  add_action("read",       "read");
  add_action("read",       "examine");
  add_action("activate",   "activate");
}

read(str) {
  if (!str || !id(str)) return 0;
  long();
  return 1;
}

activate(str) {
  int target_hp;
  object obj;
  if (!str) return;
  scroll_target=0;
  sscanf(str, scroll_type+" on %s", scroll_target);
  if (!scroll_target) {
    write("But, "+capitalize(str)+" isn't here.\n");
    return 1;
  }
  target_obj=present(scroll_target, environment(this_player()));
  if (!target_obj) {
    write("But, "+capitalize(scroll_target)+" isn't here.\n");
    return 1;
  }
  if (!target_obj->query_npc()) {
    write("This can only be used on monsters.\n");
    return 1;
  }
  if (target_obj->query_level()>=21 && this_player()->query_level() < 21) {
    write("You can't activate the scroll on a wizard!\n");
    return 1;
  }
  if (this_player()->query_level() < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write("You can't damn a player that hasn't set player-killer!\n");
    return 1;
  }
  if (this_player()->query_level() < 21 &&
      !target_obj->query_npc() &&
      !my_player()->query_pl_k()) {
    write("You can't damn a player unless you set player-killer!\n");
    return 1;
  }
  write("The scroll begins to glow.\n");

  /* do curse stuff */

  if (scroll_type=="death") {
    write("For a moment, you see the figure of someone in a hooded "+
          "black cloak,\n"+
          "carrying a huge scythe, appear and touch "+
          capitalize(scroll_target)+".\n"+
          "As the cloaked figure fades away, "+
          capitalize(scroll_target)+"\n"+
          "screams in agony and falls.\n"+
          "The scroll crumbles to dust.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        "A moment later, you see the figure of someone in a hooded black\n"+
        "cloak, carrying a huge scythe, appear and touch "+
        capitalize(scroll_target)+".\n"+
        "As the cloaked figure fades away, "+capitalize(scroll_target)+
        " screams in agony and falls.\n", this_player());
    target_hp=target_obj->query_hp()/4;
    target_obj->hit_player(target_hp);
    destruct(this_object());
    return 1;
  }

  if (scroll_type=="fear") {
    write("For a moment, nothing seems to happen, then "+
          capitalize(scroll_target)+" screams in\n"+
          "horror and runs away!\n"+
          "The scroll crumbles to dust.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        "A moment later, "+capitalize(scroll_target)+" screams in terror\n"+
        "and runs away.\n", this_player());
    target_obj->run_away();
    destruct(this_object());
    return 1;
  }

  if (scroll_type=="paralysis") {
    write("For a moment, nothing seems to happen.  Then, as "+
          capitalize(scroll_target)+"\n"+"tries to move, "+
          target_obj->query_pronoun()+" looks puzzled.\n"+
          "The scroll crumbles to dust.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        "For a moment, nothing seems to happen.  Then, as "+
        capitalize(scroll_target)+"\n"+" tries to move, "+
        target_obj->query_pronoun()+" looks puzzled.\n", this_player());
    obj=clone_object("players/nooneelse/closed/magic_shop/paralyze_curse");
    obj->do_paralyze(scroll_target);
    move_object(obj, target_obj);
    destruct(this_object());
    return 1;
  }

  if (scroll_type=="force cube") {
    write("For a moment, nothing seems to happen.  Then, a shimmering cube\n"+
          "starts to form around "+capitalize(scroll_target)+".\n"+
          "As "+capitalize(scroll_target)+" tries to move, "+
          target_obj->query_pronoun()+" looks puzzled.\n"+
          "The scroll crumbles to dust.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        "For a moment, nothing seems to happen, then, a shimmering cube\n"+
        "starts to form around "+capitalize(scroll_target)+".\n"+
        "As "+capitalize(scroll_target)+" tries to move, "+
        target_obj->query_pronoun()+" looks puzzled.\n", this_player());
    obj=clone_object("players/nooneelse/closed/magic_shop/force_cube_curse");
    move_object(obj, target_obj);
    obj->start_curse(scroll_target);
    destruct(this_object());
    return 1;
  }

  if (scroll_type=="silence") {
    write("For a moment, nothing seems to happen, then, as "+
          capitalize(scroll_target)+"\n"+
          " tries to speak, they look puzzled.\n"+
          "The scroll crumbles to dust.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        "For a moment, nothing seems to happen, then, as "+
        capitalize(scroll_target)+"\n"+
        " tries to speak, they look puzzled.\n", this_player());
    obj=clone_object("players/nooneelse/closed/magic_shop/silence_curse");
    obj->start(target_obj);
    move_object(obj, target_obj);
    destruct(this_object());
  }

  if (scroll_type=="firestorm") {
    write(capitalize(scroll_target)+" shrieks in agony as the scroll "+
          "bursts into flame\n"+
          "and hurls itself on them.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        capitalize(scroll_target)+" shrieks in agony as the scroll "+
        "bursts into flame\n"+
        "and hurls itself on them.\n", this_player());
    target_obj->hit_player(60);
    destruct(this_object());
    return 1;
  }

  if (scroll_type=="icestorm") {
    write(capitalize(scroll_target)+" shrieks in agony as the scroll "+
          "turns into a sheet\n"+
          "of ice, which shreds into thousands of incredibly sharp shards, "+
          "then\n"+
          "hurls itself on them.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        capitalize(scroll_target)+" shrieks in agony as the scroll "+
        "turns into a sheet\n"+
        "of ice, which shreds into thousands of incredibly sharp shards, "+
        "then\n"+
        "hurls itself on them.\n", this_player());
    target_obj->hit_player(60);
    destruct(this_object());
    return 1;
  }

  if (scroll_type=="lightning") {
    write(capitalize(scroll_target)+" shrieks in agony as the scroll "+
          "becomes a jagged bolt\n"+
          "of electricity and hurls itself at them.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        capitalize(scroll_target)+" shrieks in agony as the scroll "+
        "becomes a jagged bolt\n"+
        "of electricity and hurls itself at them.\n", this_player());
    target_obj->hit_player(50);
    destruct(this_object());
    return 1;
  }
  return 1;
}

reset(arg) { return 0; }

query_save_flag() { return 1; }

short() { return "A scroll"; }

long() {
  if (scroll_type=="death" ||
      scroll_type=="fear" ||
      scroll_type=="paralysis" ||
      scroll_type=="force cube" ||
      scroll_type=="silence") {
    write("This scroll seems to have a curse spell on it.\n"+
          "You can't make out most of the words, but you do see\n"+
          "that it puts a "+capitalize(scroll_type)+" curse on someone.\n\n"+
          "To activate it, type:  activate "+scroll_type+" on <who>\n");
    return 1;
  }
  if (scroll_type=="firestorm" ||
      scroll_type=="icestorm" ||
      scroll_type=="lightning") {
    write("This scroll seems to have a spell on it.\n"+
          "You can't make out most of the words, but you do see\n"+
          "that it blasts someone with a "+capitalize(scroll_type)+
          " spell.\n\n"+
          "To activate it, type:  activate "+scroll_type+" on <who>\n");
    return 1;
  }
  write("This scroll is screwed up!  Destructing it now!\n");
  destruct(this_object());
  return 1;
}

query_value() { return scroll_value; }
query_weight() { return 1; }

set_scroll_value(arg) { scroll_value=arg; }
set_scroll_type(arg) { scroll_type=arg; }

get() { return 1; }
drop() { return 0; }

id(str) {
  return str=="scroll" ||
         str==scroll_type+" scroll" ||
         str=="combat scroll" ||
         str=="curse scroll" ||
         str=="scroll_combat_curse";
}
