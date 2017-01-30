#include <event.h>
#include <combat.h>

inherit BASIC_ATTACK;
inherit BASIC_DEFENSE;

status modify_event(mapping e, string t, int p) {
  switch (t) {
  case "attack":
  case "begin_attack":
  case "defense":
  case "begin_defense":
    return
      !!(BASIC_ATTACK::modify_event(e,t,p) + 
         BASIC_DEFENSE::modify_event(e,t,p));
  }
  return 0;  // Coogan, 26-Mar-2011
}

status handle_event(mapping e, string t, int p) {
  switch (t) {
  case "attack":
  case "begin_attack":
    return BASIC_ATTACK::handle_event(e,t,p);
  case "defense":
  case "begin_defense":
    return BASIC_DEFENSE::handle_event(e,t,p);
  case "damage":
    return BASIC_ATTACK::handle_event(e,t,p);
  }
  return 0;  // Coogan, 26-Mar-2011
}

status react_event(mapping e, string t, int p) {
  switch (t) {
  case "begin_attack":
  case "attack":
    return BASIC_DEFENSE::react_event(e,t,p);
  case "begin_defense":
  case "defense":
    return BASIC_ATTACK::react_event(e,t,p);
  }
  return 0;  // Coogan, 26-Mar-2011
}
