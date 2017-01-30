/****************************************************************************
      wound.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <combat.h>
#include <message.h>
#include <event.h>

#define REACTPRIO (-500)

inherit "basic/id";
inherit "basic/wound";
inherit "basic/description";
inherit "complex/create";

status
id(string str) {
  if (str)
    return id::id(str) || str == query_wound_type() || str == "wound";
}

string
query_name() {
  return description::query_name() || query_wound_type() || "wound";
}

string
short() {
  return 0;
}

varargs string
long(string str) {
  return description::long(str) ||
         LIB_WOUND->get_wound_long(query_wound_type());
}

static void
bearer_weakened() {
  LIB_WOUND->handle_bearer_weakened();
}

static void
wound_inflicted() {
  LIB_WOUND->handle_wound_inflicted();
}

static void
wound_stopped() {
  LIB_WOUND->handle_wound_stopped();
}

static void
wound_healed() {
  LIB_WOUND->handle_wound_healed();
}

static void
wound_healing() {
  LIB_WOUND->handle_wound_healing();
}

static void
weaken_bearer() {
  wound::weaken_bearer();
  bearer_weakened();
}

void
stop_wound() {
  wound::stop_wound();
  wound_stopped();
}

static void
heal_wound() {
  if (query_wound_strength() - query_healing_rate() <= 0)
    wound_healed();
  else
    wound_healing();
  wound::heal_wound();
}

void
inflict_wound() {
  wound::inflict_wound();
  wound_inflicted();
}

void
receive_event(mapping e,string type,int prio) {
  if (prio != REACTPRIO || e[E_AGENT] != query_bearer())
    return;
  switch (type) {
  case "petrify":
    stop_wound();
    break;
  case "depetrify":
    inflict_wound();
    break;
  case "death":
    unlisten_event("death",REACTPRIO);
    unlisten_event("petrify",REACTPRIO);
    unlisten_event("depetrify",REACTPRIO);
    listen_event("resurrection",REACTPRIO);
    break;
  case "resurrection":
    listen_event("death",REACTPRIO);
    listen_event("petrify",REACTPRIO);
    listen_event("depetrify",REACTPRIO);
    unlisten_event("resurrection",REACTPRIO);
    break;
  }
}

void
configure() {
  create::configure();
  listen_event("death",REACTPRIO);
  listen_event("petrify",REACTPRIO);
  listen_event("depetrify",REACTPRIO);
}
