/*
 * /basic/woundable.c
 * this will be inherited by bodyparts which can be wounded. it already
 * inherits damageable because woundable is just a specialization.
 */

#include <event.h>
#include <combat.h>
#include <bodypart.h>

inherit "basic/damageable";

void add_bodypart_data(string name,mixed data);
void subtract_bodypart_data(string name,mixed data);
mixed get_bodypart_data(string name);
object get_user();

int damage_bodypart(int amount);
varargs status deactivate_bodypart(mapping marked);

void add_component(object c);
void remove_component(object c);

object *get_wounds() {
  mixed h;
  h = get_bodypart_data(BT_WOUNDS);
  return h ? h - ({0}) : ({});
}

void add_wound(object wound) {
DEBUG_POINT("chameloid","!!!");
  move_object(wound,this_object());
  add_component(wound);
  add_bodypart_data(BT_WOUNDS,wound);
  wound->inflict_wound();
}

void remove_wound(object wound) {
  remove_component(wound);
  subtract_bodypart_data(BT_WOUNDS,wound);
  wound->dispose_wound();
}

object build_wound(string type,int damage) {
  object wound;
  string wt;
  if (wt = DAMAGE2WOUND(type,damage)) { // which wound is appropriate?
    wound = clone_object(WOUND);
    wound->set_wound_type(wt);
  }
  return wt && wound;
}

void inflict_damage(mapping d) {
  object wound;
  string *types;
  int i,health;
  if (!mappingp(d))
    return;
  for (i = sizeof(types = m_indices(d)); i--; ) { // handle all damage types
    health = damage_bodypart(d[types[i]]); // deal damage to bodypart
    if (health < 0) // bodypart too much damaged?
      deactivate_bodypart(); // yes
    // worth a wound?
    if (d[E_WOUND] = wound = build_wound(types[i],d[types[i]])) 
      send_event("wound",
                 ([ E_AGENT: get_user(),
                    E_OBJECT: wound,
                    E_TARGET: this_object(),
                    E_DAMAGE: d[types[i]],
                    E_DAMAGE_TYPE: types[i] ]),
                 environment(get_user()));
  }
}
