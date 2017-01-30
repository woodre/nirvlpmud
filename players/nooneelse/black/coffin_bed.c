/*
  coffin_bed.c - a bed for the vampire's coffins
*/

inherit "obj/treasure";

int on_bed, bed_rumpled;

reset(arg) {
  if (arg) return;

  set_short("A large, soft bed");
  set_weight(666);
  set_value(0);
}

get() { return 0; }

id(str) { return str=="bed"; }

init() {
  add_action("look_at_bed",    "look");
  add_action("look_at_bed",    "examine");
  add_action("lay_on_bed",     "sit");
  add_action("lay_on_bed",     "lay");
  add_action("not_if_laying",  "out");
  add_action("get_out_of_bed", "stand");
  add_action("get_out_of_bed", "get");
  add_action("jump_on_bed",    "jump");
  add_action("make_bed",       "make");
  add_action("throw_pillow",   "throw");
}

look_at_bed(str) {
  string str2;
  if (!str) return 0;
  str2=0;
  sscanf(str, "at %s", str2);
  if (str=="bed" || str2=="bed") {
    write(
      "This is a large, soft bed, covered with the sheerest of silk of\n"+
      "the deepest blood red.  There are two huge pillows covered in the\n"+
      "same silk.");
    if (bed_rumpled)
      write("  The sheets are all rumpled.\n");
    else
      write("  The sheets are smooth and tucked in.\n");
    return 1;
  }
  if (str=="pillow" || str2=="pillow") {
    write("It is a huge, down filled, pillow covered in the\n"+
          "same deep blood red silk as the bed.\n");
    return 1;
  }
  if (str=="pillows" || str2=="pillows") {
    write("They are two huge, down filled, pillows covered in the\n"+
          "same deep blood red silk as the bed.\n");
    return 1;
  }
}

lay_on_bed(str) {
  string str2;
  if (!str) str="on bed";
  str2=0;
  if (str) sscanf(str, "on %s", str2);
  if (str=="down" || str2=="bed") {
    if (on_bed) {
      write("You are already on the bed.\n");
      return 1;
    }
    write("You lay back on the bed with a sigh of comfort.\n");
    say(this_player()->query_name()+
        " lays back on the bed with a sigh of comfort.\n");
    on_bed=1;
    bed_rumpled=1;
    return 1;
  }
}

jump_on_bed(str) {
  string str2;
  str2=0;
  if (!str && on_bed) str="on bed";
  if (!str) return 0;
  sscanf(str, "on %s", str2);
  if (str2=="bed") {
    if (on_bed) {
      write("You stand up on the bed and start jumping up and down,\n"+
            "messing up the sheets.\n");
    }
    else {
      write("You hop up onto the bed and start jumping up and down,\n"+
            "messing up the sheets.\n");
    }
    say(this_player()->query_name()+
        " starts jumping up and down on the bed,\n"+
        "making a mess of the sheets.\n");
    on_bed=1;
    bed_rumpled=1;
    return 1;
  }
}

not_if_laying() {
  if (on_bed) {
    write("You must get out of bed first.\n");
    return 1;
  }
}

get_out_of_bed(str) {
  if (query_verb()=="stand" || str=="up" ||
      str=="out of bed" || str=="off the bed" || str=="off bed") {
    if (!on_bed) {
      write("You aren't on the bed.\n");
      return 1;
    }
    write("You get up out of the bed.\n");
    say(this_player()->query_name()+" gets up out of the bed.\n");
    on_bed=0;
    return 1;
  }
}

make_bed(str) {
  if (str!="bed") return 0;
  write("You take a few moments to straighten the sheets and tuck them in.\n");
  say(this_player()->query_name()+
      "takes a few moments to straighten the sheets and tuck them in.\n");
  bed_rumpled=0;
  return 1;
}

throw_pillow(str) {
  string str2;
  if (str=="pillow") {
    write("You grab a pillow and toss it into the air.\n");
    say(this_player()->query_name()+
        " grabs a pillow and tosses it into the air.\n");
    bed_rumpled=1;
    return 1;
  }
  sscanf(str, "pillow at %s", str2);
  if (str2) {
    if (present(str2, environment(this_player()))) {
      write("You grab a pillow and toss it at "+
            present(str2, environment(this_player()))->query_name()+".\n");
      say(this_player()->query_name()+" grabs a pillow and tosses it at "+
          present(str2, environment(this_player()))->query_name()+".\n");
      bed_rumpled=1;
      return 1;
    }
    else {
      write("You grab a pillow to toss, but can't locate "+str2+".\n");
      say(this_player()->query_name()+
          " grabs a pillow to toss, but can't locate "+str2+".\n");
      bed_rumpled=1;
      return 1;
    }
  }
}
