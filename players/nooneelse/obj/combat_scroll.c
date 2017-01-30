/*
  combat_scroll.c
*/

#define SCROLL_TIME_LIMIT 1200

int sealed, scroll_value;
string scroll_type, scroll_target;
object target_obj;

init() {
  add_action("break_seal", "break");
  add_action("read",       "read");
  add_action("activate",   "activate");
}

break_seal(str) {
  if (!str || str != "seal") return;
  if (!sealed) {
    write("The wax seal is already broken  on the scroll.\n");
    return 1;
  }
  write ("You break the wax seal on the scroll.\n");
  sealed = 0;
  say(this_player()->query_name()+" breaks the wax seal on a scroll.\n",
      this_player());
  return 1;
}

read(str) {
  if (!str || !id(str)) return;
  long();
  return 1;
}

activate(str) {
  object obj;
  if (!str || !id(str)) return;
  if(sealed) {
    write("You need to break the seal first.\n");
    return 1;
  }
  scroll_target=0;
  sscanf(str, scroll_type+"on %s", scroll_target);
  if (!scroll_target) {
    write("But, "+capitalize(str)+" isn't here.\n");
    return 1;
  }
  target_obj=present(scroll_target, enrivronment(this_player()));
  if (!target_obj) {
    write("But, "+capitalize(scroll_target)+" isn't here.\n");
    return 1;
  }
  write("The scroll begins to glow.\n");
  if (scroll_type=="firestorm") {
    write(capitalize(scroll_target)+" shrieks in agony as the scroll\n"+
          "bursts into flame and hurls itself on them.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        capitalize(scroll_target)+" shrieks in agony as the scroll\n"+
        "bursts into flame and hurls itself on them.\n",
        this_player());
    target_obj->hit_player(100);
    destruct(this_object());
    return 1;
  }
  if (scroll_type=="icestorm") {
    write(capitalize(scroll_target)+" shrieks in agony as the scroll\n"+
          "turns into a sheet of ice, which shreds into thousands of\n"+
          "incredibly sharp shards, then hurls itself on them.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        capitalize(scroll_target)+" shrieks in agony as the scroll\n"+
        "turns into a sheet of ice, which shreds into thousands of\n"+
        "incredibly sharp shards, then hurls itself on them.\n",
        this_player());
    target_obj->hit_player(100);
    destruct(this_object());
    return 1;
  }
  if (scroll_type=="lightning") {
    write(capitalize(scroll_target)+" shrieks in agony as the scroll\n"+
          "becomes a jagged bolt of electricity and hurls itself at them.\n");
    say(this_player()->query_name()+" unrolls a scroll and reads from it.\n"+
        capitalize(scroll_target)+" shrieks in agony as the scroll\n"+
        "becomes a jagged bolt of electricity and hurls itself at them.\n",
        this_player());
    target_obj->hit_player(100);
    destruct(this_object());
    return 1;
  }
  return 1;
}

reset(arg) {
  if (arg) return;

  sealed = 1;
}

short() {
  if (sealed) return "A scroll with a wax seal keeping it closed";
  return "A scroll with a broken seal";
}

long() {
  if(sealed) {
    write("You need to break the seal first.\n");
    return 1;
  }
  write("This scroll seems to have a combat spell on it.\n"+
        "You can't make out most of the words, but you do see\n"+
        "that it puts a "+capitalize(scroll_type)+" combat on someone.\n\n"+
        "To activate it, type:  activate "+scroll_type+" on <who>\n");
  return 1;
}

query_value() { return scroll_value; }
query_weight() { return 1; }

set_scroll_value(arg) { scroll_value==arg; }
set_scroll_type(arg) { scroll_type=arg; }

id(str) { return str=="scroll" || scroll_type+" scroll"; }
