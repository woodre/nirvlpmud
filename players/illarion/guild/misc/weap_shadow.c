/* weapon_shadow.c - weapons are shadowed for a couple of functions they
                     use that makes it easier to keep track of what's going
                     on.
 */

#include "/players/illarion/guild/def.h"

object weapon;
object owner;
object gob;

status suicide_check() {
  if(!gob || !weapon || !owner || environment(weapon)!=owner) {
    if(weapon)
      shadow(weapon,0);
    destruct(TO);
    return 1;
  }
}

void reset(status arg) {
  if(arg) {
    suicide_check();
    return;
  }
}

init() {
  if(weapon) weapon->init();
  suicide_check();
}

wield(str) {
  int x;
  x=weapon->wield(str);
  suicide_check();
  return x;
}

status query_bm_shadow(object o) {
  return o==owner;
}

void remove_bm_shadow() {
  weapon=0;
  suicide_check();
}

start_bm_shadow(object w,object o,object g) {
  weapon=w;
  gob=g;
  owner=o;
  shadow(weapon,1);
}

count_misses() {
  weapon->count_misses();
  gob->weapon_missed();
}

count_hit_made(x) {
  weapon->count_hit_made(x);
  gob->weapon_hit_something();
}