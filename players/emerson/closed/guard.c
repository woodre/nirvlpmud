inherit "obj/monster";

int stay;
string master_name, controller, attack_string;
object soul, master, guard, victim;

set_master(arg) {
  master = arg;
  master_name = master->query_name();
  return 1;
}

query_master() {
  return master;
}

reset(x) {
  if (!x) {
    set_name("bodyguard");
    set_alias("guard");
    attack_string = " says: Yes, mortal";
    set_gender(1);
    set_level(1);
    stay = 0;
    set_short("A non-defined bodyguard is here");
    set_long(
         "A bodyguard that has not been set up.\n");
    guard = this_object();
    set_heart_beat(1);
    enable_commands();
  }
  ::reset(x);
}

catch_tell(str) {
  object subject;
  if (!master)
  {
    if (sscanf(str, "%s whispers to you: rejoin", subject) == 1)
    {
      if (subject == master_name)
      {
        master = this_player();
        return 1;
      }
    }
    else
      return;
  }
  if (sscanf(str, master->query_name() + " tells you: %s\n", subject))
  {
    str = master->query_name() + " says: " +
lower_case(this_object()->query_name()) +
    ", " + subject + "\n";
  }

  if (sscanf(str, master->query_name() + " whispers to you: %s\n", subject))
  {
    str = master->query_name() + " says: " +
lower_case(this_object()->query_name()) +
    ", " + subject + "\n";
  }
  controller = master->query_name() + " says: " +
  lower_case(this_object()->query_name()) + ", ";

  if (sscanf(str, controller + "drop %s\n", subject) == 1)
  {
    call_out("do_drop", 1, subject);
    return 1;
  }
   if (str == controller + "stay\n")
  {
    stay = 1;
    return 1;
  }
   if (str == controller + "follow\n")
  {
    stay = 0;
    return 1;
  }
  if (sscanf(str, controller + "get %s\n", subject) == 1)
  {
    call_out("do_get", 1, subject);
    return 1;
  }
  if (sscanf(str, controller + "kill %s\n", subject) == 1)
  {
    call_out("do_kill", 1, subject);
    return 1;
  }
  if (sscanf(str, controller + "%s\n", subject) == 1)
  {
    call_out("do_it", 1, subject);
    return 1;
  }
}
do_it(str) {

  if (command(str, guard))
    return 1;
  else
  {
    tell_room(environment(guard), guard->query_name()
    + " looks confused.\n");
  }
}

do_drop(str) {
  object item;

  if (item = present(str, this_object()))
  {
    tell_room(environment(this_object()), this_object()->query_name() +
    " drops " + item->query_name() + ".\n");
    transfer(item, environment(this_object()));
  }
  else
  {
    tell_room(environment(this_object()), this_object()->query_name() +
    " looks confused.\n");
  }
}

warn() {
  tell_room(environment(this_object()), this_object()->query_name() +
  " says: The hour is at hand, master. In five minutes, I leave.\n");
}

cut() {
  tell_room(environment(this_object()), this_object()->query_name() +
  " waves farewell.\n");
  tell_room(environment(this_object()), this_object()->query_name() +
  " has left.\n");
  detonate(this_object());
}

detonate(arg) {
  destruct(arg);
}
do_get(str) {
  object item;

  if (item = present(str, environment(guard)))
  {
    if (item->get())
    {
      tell_room(environment(this_object()), this_object()->query_name() +
      " takes " + item->query_name() + ".\n");
      transfer(item, this_object());
    }
    else
    {
      tell_room(environment(this_object()), this_object()->query_name() +
      " cannot seem to take that.\n");
    }
  }
  else
  {
    tell_room(environment(this_object()), this_object()->query_name() +
    " looks confused.\n");
  }
}

do_kill(str) {
  object subject;
  if(file_name(environment(this_player())) == "room/church") {
     write("Mercenary says: I cannot attack in the church!\n");
     return 1;
   }
  if (subject = present(str, environment(this_object())))
  {
/*--------------added by hawkeye(5-5-94)-------------------*/
if(subject->query_npc() == 0) {
write("Mercenary says: I cannot attack players!\n");
return 1;
}
      tell_room(environment(this_object()), this_object()->query_name() +
      attack_string + ".\n");
      this_object()->attack_object(subject);
    }
    else
    {
      tell_room(environment(this_object()), this_object()->query_name() +
      " does nothing.\n");
    }
}

heart_beat() {
  if (!master)
  {
    set_heart_beat(0);
    return 1;
  }
  if (environment(this_object()) == environment(master)) {
    if (call_other(master, "query_attack")) {
       victim = call_other(master, "query_attack");
       if (victim == this_object()) { victim = master; }
       if (!call_other(this_object(), "query_attack")) {
           tell_room(environment(this_object()),
           this_object()->query_name() + " joins in the fray.\n");
      if (!call_other(this_object(), "query_attack"))
      { attack_object(victim); }
        }
    }
  }
  if (!(environment(this_object()) == environment(master))) {
    if (!stay)
    {
    tell_room(environment(this_object()),
    this_object()->query_name() + " follows after " +
    master->query_name() + ".\n");
    move_object(this_object(), environment(master));
    tell_room(environment(this_object()),
    this_object()->query_name() + " arrives.\n");
    move_object(master, environment(master));
    }
 }
  ::heart_beat();
}
