#include "/players/feldegast/defines.h"
inherit "obj/treasure.c";

void reset(int arg) {
  set_id("wand");
  set_alias("tool");
  set_long("A tool for making monsters attack each other.\nUsage: attack <mon1> <mon2>\n");
  set_short("A monstrous wand");
  set_weight(1);
  set_value(0);
}

void init() {
  add_action("cmd_attack","attack");
}

int cmd_attack(string str) {
  string name1, name2;
  object mon1, mon2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",name1,name2)!=2) return 0;
  mon1=present(name1,environment(TP));
  mon2=present(name2,environment(TP));
  if(!mon1 || !mon2) {
    write("That monster is not present.\n");
    return 1;
  }
  write("You force "+name1+" and "+name2+" to attack each other.\n");
  mon1->attack_object(mon2);
  mon2->attack_object(mon1);
  return 1;
}
