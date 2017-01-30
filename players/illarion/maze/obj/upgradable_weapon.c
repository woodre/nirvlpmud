#include "/players/illarion/dfns.h"
#define MASTER MAZEOBJ+"wep_daem"
#define TYPE wep_stats[0]
#define HANDS wep_stats[1]
#define QUALITY wep_stats[2]
#define EXPERIENCE wep_stats[3]
#define ENHANCEMENT wep_stats[4]
#define MATERIAL wep_stats[5]
#define COLOR wep_stats[6]
#define GEM wep_stats[7]
#define RUNE wep_stats[8]
#define WEPNAME wep_stats[9]

inherit "/obj/weapon.c";

mixed *wep_stats;

/* wep_stats contains information about the weapon
   Much of this information can be modified by the player
0: type
1: hands required
2: quality (wc)
3: experience
4: enhancement
5: material
6: color(s)
7: gem/element
8: rune
9: name

   see wep_daem.c for more information
*/

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  wep_stats=allocate(10);
  wield_func=MAZEOBJ+"shieldcheck";
}

string locker_arg() {
  if(!wep_stats) return "";
  return implode(wep_stats,"^^^");
}

set_name(str) {
  WEPNAME=str;
  return ::set_name(str);
}

set_type(str) {
  TYPE=str;
  return ::set_type(str);
}

set_class(cls) {
  QUALITY=cls;
  return ::set_class(cls);
}

query_stats() {
  return wep_stats;
}

set_stats(stats) {
  wep_stats=stats;
  call_other(MASTER,"setup_weapon",stats);
}

void locker_init(string str) {
  if(str) {
    call_other(MASTER,"process_locker_init",str);
  }
}

two_handed() {
  return HANDS==2;
}

id(str) {
  if(HANDS==2 && str=="notarmor" && wielded && previous_object()->query_type()=="shield")
    return 1;
  return ::id(str);
}

hit(object targ) {
  EXPERIENCE++;
  return call_other(MASTER,"weapon_hit",wielded_by,targ,wep_stats);
}