/*
Clothing object
Feldegast@Nirvana
3-29-2000
This is the main clothing object, namely what is seen in the player's
description.  When any single item of clothing is dropped, a clothing
object is cloned.
*/
#include "/players/feldegast/defines.h"
#define CLOTHING "/players/feldegast/std/clothing.c"

string *desc;
string *name;
int *value;
mixed *type;

void reset(int arg) {
  if(!arg) {
    desc=({ });
    name=({ });
    value=({ });
    type=({ });
  }
}

void add_item(string d, string n, int v, string *t) {
  desc+=({ d });
  name+=({ n });
  value+=({ v });
  type+=({ t });
}

int remove_item(string n) {
  int i;
  i=member_array(n,name);
  if(i != -1) {
    desc-=({ desc[i] });
    name-=({ name[i] });
    value-=({ value[i] });
    type-=({ type[i] });
    return 1;
  }
  return 0;
}

int id(string str) {
  return str=="clothing_object";
}

string extra_look() {
  string str;
  int size;
  object a, e;
  size=sizeof(desc);
  if((a = this_player()) && (e = environment()) && (e == a)) {
    str="You";
    if(size > 0) {
      str+=" are wearing ";
      for(size-=1; size >= 0; size--) {
        str+=desc[size];

        if(size!=0) str+=", ";
        if(size==1) str+="and ";
      }
    }
    else
      str+=" are completely naked";    
  }  
  else {
    str=capitalize((string)environment()->query_name());
    if(size > 0) {
      str+=" is wearing ";
      for(size-=1; size >= 0; size--) {
        str+=desc[size];
  
        if(size!=0) str+=", ";
        if(size==1) str+="and ";
      }
    }
    else
      str+=" is completely naked";
  }
  return str;
}

string query_auto_load() {
  string str;
  int i;
  str="/players/feldegast/std/clothes.c:";

  for(i=0; i < sizeof(desc); i++) {
    str+=desc[i];
    str+="$"+name[i];
    str+="$"+value[i]+"$";
    str+=implode(type[i],"*");
    str+="&";
  }
  return str;
}

void init_arg(string str) {
  string *it,*ite;
  string d,n,v1,*t;
  int v2;
  int i;
  it=explode(str,"&");
  for(i=0; i < sizeof(it); i++) {
    if(it[i])
   {
    ite=explode(it[i],"$");
    if(sizeof(ite) != 4) {
      write("There was a difficulty loading your clothing. (Oops!)\n");
      return;
    }
    d=ite[0];
    n=ite[1];
    v1=ite[2];
    t=explode(ite[3],"*");
    sscanf(v1,"%d",v2);
    add_item(d,n,v2,t);
    }
  }
}

int drop() { return 1; } /* Can't be dropped */
int get() { return 0; } /* Can't be picked up */

void init() {
  add_action("cmd_remove","remove");
  add_action("cmd_drop","drop");
}

int cmd_remove(string str) {
  object item;
  int i;
  i=member_array(str,name);
  if(i != -1) {
    item=clone_object(CLOTHING);
    item->set_id(name[i]);
    item->set_short(desc[i]);
    item->set_value(value[i]);
    item->set_type(type[i]);
    move_object(item,this_player());
    write("You remove "+desc[i]+".\n");
    say(capitalize((string)this_player()->query_pronoun())+
                   " removes "+desc[i]+".\n");
    remove_item(str);
    return 1;
  }
  notify_fail("You are not wearing a "+str+".\n");
  return 0;
}

int cmd_drop(string str) {
  object item;
  int i;
  i=member_array(str,name);
  if(i != -1) {
    item=clone_object(CLOTHING);
    item->set_id(name[i]);
    item->set_short(desc[i]);
    item->set_value(value[i]);
    item->set_type(type[i]);
    move_object(item,environment(this_player()));
    write("You remove "+desc[i]+" and then drop it on the ground.\n");
    say(capitalize((string)this_player()->query_pronoun())+
                   " removes "+desc[i]+" and drops it on the ground.\n");
    remove_item(str);
    return 1;
  }
  notify_fail("You are not wearing a "+str+".\n");
  return 0;
}

int test_type(string *test) {
  int i,j,k;
  for(i=sizeof(test)-1; i >= 0; i--) {
    for(j=sizeof(type)-1; j >= 0; j--) {
      if(member_array(test[i],type[j])!=-1) {
        write("You are already wearing "+desc[j]+".\n");
        return 1;
      }
    }
  }
  return 0;
}
