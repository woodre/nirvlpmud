/* Note: This doesn't work even remotely, but I thought it was worth a try. */
#include "/players/feldegast/defines.h"
inherit "obj/treasure";

reset(arg) {
  set_id("wand");
  set_short("A short, black wand");
  set_long("A magic wand for testing wizard stuff.\nWave the wand to use it.\n");
  set_weight(1);
  set_value(1000);
}
init() {
  add_action("cmd_wave","wave");
  add_action("regen","regen");
  add_action("cmd_test", "loot");
  add_action("blah", "blah");
}
static duh() {
  return 1;
}
regen() {
  int i;
  int r;
  int total;
  for(i=0; i < 100; i++) {
  r=random(20)*2;
  if(r < 20) r=20;
  for(; r > 0; r--) {
    if(random(4)) total+=1+random(2);
  }
  }
  write("Average regen(over 100 tests) = "+(total/100)+"\n");
  return 1;
}

blah(str) {
  mapping mip;
  mip="/obj/exp_store"->query_map();
  write("Gaston: "+mip["Gaston"]+"\n");
  write("Feldetest: "+mip["Feldetest"]+"\n");
  return 1;
}

loot() {
  int coins;
  if(!random(2)) coins+=1600;
  if(!random(2)) coins+=1600;
  if(!random(2)) coins+=1600;
  if(!random(2)) coins+=1600;
  coins+=600;
  if(!random(2)) coins+=500;
  if(!random(2)) coins+=500;
  if(!random(2)) coins+=750;
  if(!random(2)) coins+=500;
  if(!random(2)) coins+=500;
  return coins;
}

cmd_test() {
  int i,total;
  for(i=0; i < 1000; i++)
    total+=loot();
  total/=1000;
  write("Avg. Loot = "+total+"\n");
  return 1;
}
