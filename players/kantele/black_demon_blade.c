#pragma strong_types

inherit "obj/weapon";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("blade");
  set_alt_name("demon blade");
  set_alias("black demon blade");
  set_class(15);
  set_short("A black demon blade");
  set_long("An evil black demon blade.\n");
  set_value(1000);
  set_hit_func(this_object());
}

status
wield(object weapon) {
  int align, evil;
  align = (int)this_player()->query_alignment();
  if (align > 0) {
    write("The blade gives you an electric jolt.\n");
    write("The blade don't like you, you're too stinking good.\n");
    this_player()->add_hp(-20);
    return 1;
  } else {
    if (evil == 0) {
      evil = 1;
      this_player()->add_alignment(-4);
      write("You feel more evil.\n");
      ::wield("blade");
    }
    return 1;
  }
}

int
weapon_hit(object attacker) {
  int align, dam;
  align = (int)this_player()->query_alignment();
  if (align > 0) {
    dam = random(25);
    if (dam < 10)
      return 0;
    if (dam < 15)
      write("The blade flashes.\n");
    else if (dam < 20)
      write("The blade flashes happily.\n");
    else if (dam < 24)
      write("The blade flashes happily, and gives out a happy cry.\n");
    else if (dam == 24) {
      write("The blade flashes happily, and you can feel its evil might.\n");
      tell_room(environment(this_player()),
        "The black demon blade flashes !\n");
      this_player()->heal_self(random(10));
      write("You feel stronger.\n");
      dam = dam + random(20);
      if (dam == 63) {
        write("And the blade flashes.\n");
        this_player()->heal_self(random(10));
        write("You feel stronger.\n");
        tell_object(environment(this_player()),
          "The black demon blade flashes, and gives out a happy cry.\n");
      }
    }
    return dam;
  }
  dam = random(15);
  return dam;
}
