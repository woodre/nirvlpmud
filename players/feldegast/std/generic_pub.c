/*
Filename: /players/feldegast/std/generic_pub.c
Author: Feldegast/CAS
Description: Generic pub
Created: 1/4/00
*/
#include "/players/feldegast/defines.h"
inherit "/players/feldegast/std/room.c";

string proprietor;

string *name; /* As it appears on the menu */
mixed *id; /* An array of string id's for each item */
string *msg1; /* write */
string *msg2; /* say */
int *cost;
int *heal;
int *intox;
string *type; /* "intox" "stuff" "soak" */

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  name=({ });
  id=({ });
  msg1=({ });
  msg2=({ });
  cost=({ });
  heal=({ });
  intox=({ });
  type=({ });
}

void init() {
  ::init();
  add_action("cmd_order","order");
  add_action("cmd_order","buy");
  add_action("cmd_list","list");
}

void add_item(string n,string *i,string m1,string m2,int c,int h,int x,string t) {
  name+=({ n });
  id+=({ i });
  msg1+=({ m1 });
  msg2+=({ m2 });
  cost+=({ c });
  heal+=({ h });
  intox+=({ x });
  type+=({ t });
}

void set_prop(string str) {
  proprietor=str;
}

int cmd_list(string str) {
  int i,size;
  write("\t   Item                     Price\n");
  write("\t----------------------------------\n");
  size=sizeof(name)+1;
  for(i=1; i < size; i++)
    write("\t"+pad(i+". ",4)+pad(name[i-1],25)+cost[i-1]+"\n");
  write("\n");
  return 1;
}

int cmd_order(string str) {
  int index;
  string *ids;
/* If there is a vendor, and it isn't present, do nothing. */
  if(proprietor && !present(proprietor,this_object()))
    return 0;

  if(!str) {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }

  if(sscanf(str,"%d",index)==1)
    index--;
  else {
    ids=id[index];
    if((index=member_array(str,ids)) != -1) {
      notify_fail("That is not an item you can buy.\n");
      return 0;
    }
  }
  if(index < 0 || index > sizeof(name)-1) {
    notify_fail("That is not an item you can buy.\n");
    return 0;
  }
  if((int)this_player()->query_money() < cost[index]) {
    write("You cannot afford that.\n");
    return 0;
  }
  switch(type[index]) {
    case "intox": if((int)this_player()->query_intoxination() > this_player()->query_level()+3) {
                    write("You cannot drink any more!\n");
                    return 1;
                  } else this_player()->drink_alcohol(intox[index]);
                  break;
    case "soak" : if(this_player()->query_soaked() + intox[index] > (int)this_player()->query_level() * 8) {
                    write("You can't drink anything else!\n");
                    return 1;
                  } else this_player()->eat_food(intox[index]);
                  break;
    case "stuff": if(this_player()->query_stuffed() + intox[index] > (int)this_player()->query_level() * 8) {
                    notify_fail("You are too full!\n");
                    return 0;
                  } else this_player()->drink_soft(intox[index]);
                  break;
    default: write("Invalid item.\n");
             return 1;
  }
  write(msg1[index]);
  say((string)this_player()->query_name()+msg2[index]);
  this_player()->heal_self(heal[index]);
  this_player()->add_money(-cost[index]);
  return 1;
}
  