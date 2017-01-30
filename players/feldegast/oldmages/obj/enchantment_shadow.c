/*
Base class for enchantments shadow for the Mages Guild
by Feldegast/Chris Smith
1/26/99    -     Weren't we all so young back then?

Spells this will directly support:
siphoning
ownership
charge
cache/tap

Elements:
The idea behind this, is that a mage that has this object in his/her
possession while casting a spell based on an element that this object
has an enchantment for, will receive some sort of bonus.

*/
#include "/players/feldegast/defines.h"
#define AIR 1
#define WATER 2
#define FIRE 3
#define EARTH 4

static object target;

int charges;

int energy;

int element;

string owner_name;

int set_shadow(object ob) {
  if(!shadow(ob,1)) {
    destruct(this_object());
    return 0;
  }
  target=ob;
  return 1;
}

object query_shadow() {
  return this_object();
}

int add_charge(int n) {
  charges+=n;
  if(charges > 100) charges=100;
  return charges;
}

int add_energy(int n) {
  energy+=n;
  if(energy > 100) energy=100;
  return energy;
}

void set_owner_name(string str) {
  owner_name=str;
}

string query_owner_name() {
  return owner_name;
}

/* I love binary arithmetic. */
int query_element(string str) {
  switch(str) {
    case "air"   : return element & AIR==AIR;
    case "water" : return element & WATER==WATER;
    case "fire"  : return element & FIRE==FIRE;
    case "earth" : return element & EARTH==EARTH;
  }
}

void set_element(string str) {
  if(query_element(str)) return;
  switch(str) {
    case "air"   : element+=AIR;
              break;
    case "water" : element+=WATER;
              break;
    case "fire"  : element+=FIRE;
              break;
    case "earth" : element+=EARTH;
              break;
  }
}

string e_color() {
  if(query_element("air")) return CYN;
  else if(query_element("water")) return BLU;
  else if(query_element("fire")) return HIR;
  else if(query_element("earth")) return BOLD+BLK;
  else if(energy > 0) return HIM;
  else return HIB;
}

short() {
  return target->short()+BOLD+"["+NORM+e_color()+"Enchanted"+NORM+BOLD+"]"+NORM;  
}
long(str) {
  target->long(str);
  write(BOLD+"This item is enchanted.\n"+NORM);
}

init() {
  target->init();
  add_action("cmd_tap","tap");
}

id(str) {
  return target->id(str) || str=="enchanted_item";
}

get() {
  if(owner_name && owner_name!=this_player()->query_real_name()) {
    write("The "+target->short()+" burns your hand as you try to pick it up.\n");
    say(TPN+" burns "+TP->query_possessive()+" hand as "+
        TP->query_objective()+" tries to pick up "+target->short()+".\n");
    return 0;
  }
  else return target->get();
}

query_save_flag() {
  return 1;
}

int cmd_tap(string str) { 
  int ammount;
  int max;

  if(!id(str)) {
    notify_fail("Tap what?\n");
    return 0;
  }
  ammount=random(30);
  max=(int)TP->query_msp()-(int)TP->query_sp();
  if(ammount > max) ammount=max;
  if(ammount > energy) ammount=energy;
  if(ammount <= 0) {
    write("The "+short()+" has no more energy!\n");
    return 1;
  }
  write("You tap the "+short()+" for more power.\n");
  TP->add_spell_point(ammount);
  return 1;
}
