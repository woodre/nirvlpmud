/*
 * Bed
 * Doppleganger bed to go along with the 'sleep' command
 *
 * Move the dopple to this object and let a call_out do the healing
 * while he/she is present.
 */

int wake_time;     /* Time to wake up, set through sleep command */
object owner;      /* Dopple who called the sleep command */

/* Prototype */
void wake_up(string str);
int start_healing(object player);

/* Sets and Queries */
object set_owner(object obj) { return owner = obj;            }
object query_owner()         { return owner;                  }

int set_wake_time(int w)  {
  int t;

  t = time();
  w *= 60;
  wake_time = t + w;
}

int query_wake_time() { return wake_time; }

/* Descs and id */
string short() {
  return "A bed" +
         (owner ? " with " + (string)owner->query_name() + " sleeping on it."
                : ".");
}

void long() {
  write("A fluffy comfortable bed. " +
        (owner ? (string)owner->query_name() : "Nobody") +
        " is sleeping on it.\n");
}

int id(string str) { return str == "bed"; }

void reset(int arg) {
  if (arg) return;
}

void init() {
  /* Redirect all verbs through this while sleeping */
#ifndef __LDMUD__
  add_action("stop_cmds"); add_xverb("");
#else
  add_action("stop_cmds", "", 3);
#endif
}

int stop_cmds(string str) {
  if (this_player()->query_level() > 19) return 0;  /* Wizzies can do stuff */
  if (str == "wake" || str == "Wake") {
    wake_up("early");
    return 1;
  } else {
    write("You are sleeping.\n");
    write("The current time is:  " + ctime(time()) + ".\n");
    write("The alarm is set for: " + ctime(wake_time) + ".\n");
    write("\n");
    write("You can wake up early by typing \"wake\" or \"Wake\".\n");
    return 1;
  }
  return 0;
}

void wake_up(string str) {
  if (str == "early") {
    tell_object(owner,
                "You startle from your sleep and sprain your back in the " +
                "process.\n");
    tell_room(environment(this_object()),
              owner->query_name() + " is startled from " +
              owner->query_possessive() + " sleep and jumps as " +
              owner->query_pronoun() + " wakes up.\n");
    move_object(owner, environment(this_object()));
    owner->add_hp( - (wake_time - time())); /* Penalty for waking early */
    if(find_call_out("sleeping")) remove_call_out("sleeping");
    destruct(this_object());
    return;
  }
  tell_object(owner,
              "You awake from a peaceful slumber feeling " +
              ((int)owner->query_hp() >= (int)owner->query_mhp() ? "fully "
                                                                 : "") +
              "rested.\n");
  tell_room(environment(this_object()),
            owner->query_name() + " awakes from a peaceful slumber.\n");
  move_object(owner, environment(this_object()));
  if(find_call_out("sleeping")) remove_call_out("sleeping");
  destruct(this_object());
  return;
}

void start_healing(object obj) {
  owner = obj;
  call_out("sleeping", 2);
}

void sleeping() {
  if ((wake_time <= (int)time()) ||
      ((int)owner->query_hp() >= (int)owner->query_mhp())) {
    wake_up("normal");
  } else {
    tell_object(owner, "ZZZzzzzzz...\n");
    tell_object(owner, "Sleeping for another " +
                (wake_time - time()) + " seconds.\n");
    owner->heal_self(3 + random(3));
    call_out("sleeping", 10);
  }
}

