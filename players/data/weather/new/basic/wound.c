/****************************************************************************
      wound.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <combat.h>

#define STATE_TYPE          "type"
#define STATE_STRENGTH      "strength"
#define STATE_SPEED         "speed"
#define STATE_HEALING_RATE  "h_rate"
#define STATE_HEALING_SPEED "h_speed"

inherit "basic/component";    // we'll be a component of the wounded bodypart

private int wound_strength,wound_speed,healing_rate,healing_speed;
private string wound_type;

object
query_bearer() {
  return get_compound() && get_compound()->get_user();
}

string
query_wound_type() {
  return wound_type || "wound";
}

int
query_wound_strength() {
  return wound_strength;
}

int
query_wound_speed() {
  return wound_speed;
}

int
query_healing_rate() {
  return healing_rate;
}

int
query_healing_speed() {
  return healing_speed;
}

status
query_weakening() {
  return (find_call_out("weaken_bearer") != -1);
}

status
query_healing() {
  return (find_call_out("heal_wound") != -1);
}

status
query_inactive() {
  return !(query_weakening() || query_healing());
}

status
query_saveable() {
  return query_inactive();
}

mapping
get_component_state() {
  return ([ STATE_TYPE:          query_wound_type(),
            STATE_STRENGTH:      query_wound_strength(),
            STATE_SPEED:         query_wound_speed(),
            STATE_HEALING_RATE:  query_healing_rate(),
            STATE_HEALING_SPEED: query_healing_speed() ]);
}

void
set_wound_strength(int strength) {
  wound_strength = strength;
}

void
set_wound_speed(int speed) {
  wound_speed = speed;
}

void
set_healing_rate(int rate) {
  healing_rate = rate;
}

void
set_healing_speed(int speed) {
  healing_speed = speed;
}

void
set_wound_type(string str) {
  mapping m;
  wound_type = str;
  m = GET_WOUND(query_wound_type());
  set_wound_strength(m["wound_strength"]);
  set_wound_speed(m["wound_speed"]);
  set_healing_rate(m["healing_rate"]);
  set_healing_speed(m["healing_speed"]);
}

varargs status
get() {
  return 0;
}

varargs status
drop() {
  return 1;
}

void
weaken_bearer() {
  int delay;
  query_bearer()->damage_bodypart(query_wound_strength());
  if (delay = query_wound_speed())
    call_out("weaken_bearer",delay);
}

void
heal_wound() {
  int delay;
  set_wound_strength(query_wound_strength() - query_healing_rate());
  if (query_wound_strength() <= 0)
    get_compound()->remove_wound(this_object());
  else
    if (delay = query_healing_speed())
      call_out("heal_wound",delay);
}

void
stop_wound() {
  remove_call_out("weaken_bearer");
  remove_call_out("heal_wound");
}

void
dispose_wound() {
  destruct(this_object());
}

void
inflict_wound() {
  int delay;
  if (delay = query_wound_speed())
    call_out("weaken_bearer",delay);
  if (delay = query_healing_speed())
    call_out("heal_wound",delay);
}

void
set_component_state(mapping state) {
  set_wound_type(state[STATE_TYPE]);
  set_wound_strength(state[STATE_STRENGTH]);
  set_wound_speed(state[STATE_SPEED]);
  set_healing_rate(state[STATE_HEALING_RATE]);
  set_healing_speed(state[STATE_HEALING_SPEED]);
  inflict_wound();
}
