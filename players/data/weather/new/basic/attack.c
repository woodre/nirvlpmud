/*
 * attack.c -- written by Ugh Jul-1997
 * this will be inherited by anything that can attack.
 */

#include <event.h>
#include <message.h>

// These functions must be implemented in an object that inherits us
// or an object that is inherited by our inheritor

// this function is called when a defense against our attack us is begun
// Thus, we can react upon such a reaction
void do_begin_defense_reaction(mapping attack);

private string damage2string(int d) {
  switch (d) {
  case 0:
    return "no";
  case 1..10:
    return "almost no";
  case 11..30: 
    return "a bit of";
  case 31..50:
    return "some";
  case 51..70:
    return "a lot of";
  case 71..100:
    return "serious";
  default:
    return "critical";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

private mixed *damage2message(mapping d) {
  int i, j;
  mixed *result, h, tmp;
  object *targets;
  string *parts;
  mapping damage, dam;

  damage = d[E_DAMAGE];
  result = ({});
  for (i = sizeof(targets = d[E_TARGET]); i--; ) {
    tmp = ({});
    dam = damage[targets[i]];
    for (j = sizeof(h=m_indices(dam)); j--; ) {
      tmp += ({ damage2string(dam[h[j]])+" "+h[j] });
    }
    result += 
     ({ message2string(({ make_list(tmp)," damage on ",M_THE,targets[i] })) });
  }
  return make_list(result);
}

// This function gives a message for the damage inflicted by the attack
void do_damage(mapping d) {
  // give a message that describes the damage inflicted
  send_message(({M_THE,M_ARG,E_WEAPON,M_VERB,"do",M_ARG,E_WEAPON," ",})+
                  damage2message(d)+({"."}),d);
}

public status handle_event(mapping e, string t, int p) {
  switch (t) {
  case "damage":
    if (e[E_WEAPON] == this_object()) {
      do_damage(e);
      return 1;
    }
    break;
  }
  return 0;  // Coogan, 26-Mar-2011
}

public status react_event(mapping e, string t, int p) {
  switch (t) {
  case "begin_action":
    if (e[E_TYPE,1] == "defense") {
      if (function_exists("do_begin_defense_reaction")) {
        do_begin_defense_reaction(e);
        return 1;
      }
    }
    break;
  }
  return 0;  // Coogan, 26-Mar-2011
}

// needed by basic/new_weapon, Coogan, 18-Oct-2000
public status modify_event(mapping e, string t, int p) {
  return 0;  // Coogan, 26-Mar-2011
}

