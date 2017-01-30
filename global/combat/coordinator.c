#include <message.h>
#include <limits.h>
#include <combat.h>

inherit "basic/create";

#define TIME 0
#define PLAYER 1

private mixed *waiting_queue;
private mapping coordinated;
private int current_time;

void set_current_time(int t) { current_time = t;    }
void add_current_time(int t) { current_time += t;   }
int get_current_time()       { return current_time; }

int get_waiting_time(object who) {
  int i;

  return
    (i = find_element(waiting_queue[PLAYER],#'==,0,({who}))) >= 0 ? 
    waiting_queue[TIME][i] : -1; 
}

void dont_wait(object who) {
  int i;

  i = find_element(waiting_queue[PLAYER],#'==,0,({who}));
  if (i >= 0) {
    waiting_queue[TIME][i..i] = ({});
    waiting_queue[PLAYER][i..i] = ({});
  }
}

void wait_until(int time, object who) {
  int i;

  dont_wait(who);
  i = find_element(waiting_queue[TIME],#'>,0,({time}));
  if (i >= 0) {
    waiting_queue[TIME][i..i-1] = ({time});
    waiting_queue[PLAYER][i..i-1] = ({who});
  } else {
    waiting_queue[TIME] += ({time});
    waiting_queue[PLAYER] += ({who});
  }
  set_heart_beat(1);
}

status query_coordinating(object ob) {
  return member(coordinated,ob);
}

object *get_coordinated() {
  return m_indices(m_delete(coordinated,0));
}

object current_actor;

varargs mixed handle_heart_beat_error() {
  // don't turn our heart-beat off, just because there was an error
  // it probably wasn't our fault
  if (current_actor)
    current_actor->abort_current_call();
  return 1;
}

int get_max_actions_per_heart_beat() {
  // provisional implementation
  return MAX_ACTIONS_PER_HB;
}

void heart_beat() {
  int t, i;
  mixed h;

  if (sizeof(waiting_queue[TIME])) {
    i = get_max_actions_per_heart_beat();
    while (sizeof(waiting_queue[TIME]) && i &&
           MAX_COST - get_eval_cost() < 100000) {
      t = waiting_queue[TIME][0];
      if (t - get_current_time() > 2000) { // delay action?
        add_current_time(2000);
        break;
      } else {
        i--;
        current_actor = waiting_queue[PLAYER][0];
        waiting_queue[TIME][0..0] = ({});
        waiting_queue[PLAYER][0..0] = ({});
        set_current_time(t);
        if (current_actor)
          current_actor->reach_time(t);
        current_actor = 0;
      }
    }
  } else {
    set_heart_beat(0);
    if (!sizeof(get_coordinated()) &&
        find_call_out("deactivate_coordinator") < 0)
    call_out("deactivate_coordinator",2);
  }
}

void deactivate_coordinator() {
  if (!sizeof(get_coordinated()))
    move_object(this_object(),load_name(this_object()));
}

void start_coordinating(object fighter) {
  if (!query_coordinating(fighter)) {
    coordinated += ([ fighter ]);
    fighter->synchronize(this_object());
  }
  set_heart_beat(1);
}

void stop_coordinating(object fighter) {
  coordinated -= ([ fighter ]);
}

void stop_fight() { 
  map(coordinated, "stop_fighting");
}

void create() {
  if (clonep()) {
    coordinated = ([]);
    waiting_queue = ({ ({}), ({}) });
    move_object(this_object(),load_name(this_object()));
  }
}

void notify_destruct() {
  // destruct all in the pool if we are updated
  if (!clonep())
    map(all_inventory(),#'destruct);
}

status id(string str) {
  if ((str == "combat" ||
       str == "fight") &&
      sizeof(get_coordinated()))
    return 1;
  return str == "coordinator";
}

string *query_id() {
  if (sizeof(get_coordinated()))
    return ({ "combat","fight","coordinator" });
  else
    return ({ "coordinator" });
}

string extra_long() {
  if (sizeof(get_coordinated()))
    return
      "There is a fight going on.\n";
}

string long(string str) {
  mixed h;
  if (sizeof(h = get_coordinated()))
    return
      capitalize(message2string(({h,M_VERB,"are",h," fighting here.\n"})));
}

status prevent_enter(object ob, object from) {
  // only our clones can enter the blueprint
  // no objects can enter the clones
  if (clonep(this_object()) ||
      load_name(ob) != load_name(this_object()))
    return 1;
}

object get_free_coordinator() {
  if (clonep())
    return load_name(this_object())->get_free_coordinator();
  else
    return first_inventory() || clone_object(load_name(this_object()));
}
