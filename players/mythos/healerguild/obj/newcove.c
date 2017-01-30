/*
File: newcove.c
Creator: Feldegast
Date: 1/20/01
Description:
  An update of the previous healer spell, which wasn't really 
worth the excessive cost.  The new version starts with a set 
amount of healing, and then stops when the pool is empty.  
Modified from Mythos' original code.
*/
#include "/players/feldegast/closed/ansi.h"

/* Who cast this spell?  For the purpose of allocating xp. */
object caster;

/* Amt. of healing remaining */
int power;

/* Rate of the healing */
int rate;

int id(string str) {
  return str == "cove_reg"; 
}

int drop() { return 1; }
int get() { return 0; }

string short() {
  string str;
  if(this_player() && this_player()->query_level() > 20) {
    str= "Invis: Healer Cove (rate: "+rate+" power: "+power+" caster: ";
    if(caster) str+= (string)caster->query_name()+")";
    else str+="missing)";
    return str;   
  }
}

void reset(int arg) {
  set_heart_beat(1);
}

/*
 Set to pie+level when the spell is cast.  A's theoretical max
 is 60.  Min of 38.
*/
void set_base(int a) {
  if(!power) {
    rate=a/6;   /* Max = 10,  Min = 6   */
    power=a*10; /* Max = 600, Min = 380 */
  } 
  else {
    rate += a/12; /* Max = 5,   Min = 3 */
    if(rate > 10) rate = 10;
    power += a*8; /* Max = 480, Min = 224 */
  }
}

void set_caster(object ob) {
  caster = ob; 
}

void clear() {
  set_heart_beat(0);
  if(environment()) tell_room(environment(),"The aura of healing disappears from the room.\n");
  destruct(this_object());
}

void heart_beat() {
  object *who;
  int h;
  int amt;
  if(!environment()) { set_heart_beat(0); return; }
  who = all_inventory(environment());
  for(h=0; h < sizeof(who); h++) {
    if(query_ip_name(who[h])) { 
      amt = (int)who[h]->query_mhp() - (int)who[h]->query_hp();
      if(amt > 0) {
        if(amt > rate) amt = rate;
        if(amt > power) amt = power;
        who[h]->heal_self(rate);
        if(!random(4))
          tell_object(who[h], HIC+"The aura of healing that surrounds"+
                              " this room makes you feel better.\n"+NORM);
        if(caster) { 
          if(who[h] != caster) caster->add_xp(rate*2); 
        }
        power-=amt; 
        if(power <= 0) { clear(); return; }
      }
    }
  }
}
