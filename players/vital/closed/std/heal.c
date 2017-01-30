/******************************************************************************
 *  
 *  File:           heal.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/13/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/closed/headers/vital.h"

#define FILE "/players/vital/closed/heal.c"

inherit "/obj/newtreasure";

int hp_heal, sp_heal, charges, value, intox, soak, stuff;

string player_msg, room_msg, type, container, too_full, too_soaked, too_drunk;
string *cmds; /* An array of commands for using this heal */

/***************************************/

void reset(int arg) {
    if(arg) return;
    cmds=({ });
}

void init() {
    int i,s;
    if(!present(TO,TP)) return;
    s=sizeof(cmds);
    for(i=0; i < s; i++) add_action("cmd_heal",cmds[i]);
    add_action("cmd_heals","heals");
    add_action("cmd_heals_all","heals+");
}

int is_heal() { return 1; }
int query_value() { return charges*value; }
int query_save_flag() { if(file_name(TO)==FILE) return 1; }
int generic_object() { return 1; }
string locker_arg() { return ""+charges; }
void locker_init(string arg) {
    if(sscanf(arg,"%d",charges)!=1) {
        write("Object failed to initialize properly.  Destructing.\n");
        destruct(TO);
    }
}

int restore_thing(string str) { restore_object(str); return 1; }
int save_thing(string str) { save_object(str); return 1; }

int query_weight() {
    if(charges > 2)
        return charges/2;
    else return 1;
}

int cmd_heal(string str)
{

  if(!str || TO!=present(str,TP) )
  {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }


  if(stuff && TP->query_stuffed() + stuff > (int)TP->query_level() * 8)
  {
    notify_fail(too_full);
    return 0;
  }

  if(soak && TP->query_soaked() + soak > (int)TP->query_level() * 8)
  {
    notify_fail(too_soaked);
    return 0;
  }

  if(intox && TP->query_intoxination() > TP->query_level()+3)
  {
    notify_fail(too_drunk);
    return 0;
  }

  if(soak)
    TP->drink_soft(soak);

  if(stuff)
    TP->eat_food(stuff);

  if(intox)
    TP->drink_alcohol(intox);

  charges--;

  TP->add_hit_point(hp_heal);
  TP->add_spell_point(sp_heal);

  write(player_msg);
  if(room_msg) say((string)TPN+room_msg);
  if(charges)
  {
    if(charges == 1) write("There is only "+charges+" "+type+" remaining.\n");
    write("There are "+charges+" "+type+"s remaining.\n");
    TP->recalc_carry();
    command("mon",TP);
  }
  else 
  {
    write("You finish off the last "+type+".\n");
    command("mon",TP);
    destruct(TO);
    TP->add_weight(-1);
  }
  return 1;
}

void set_heal(int hp,int sp) { hp_heal=hp; sp_heal=sp; }

void set_charges(int x) { charges=x; }

void set_intox(int x) { intox=x; }

void set_stuff(int x) { stuff=x; }

void set_soak(int x) { soak=x; }

void set_value(int x) { value=x; }

void set_player_msg(string str) { player_msg=str; }

void set_room_msg(string str) { room_msg=str; }

void set_type(string str) {  type=str; }

void set_too_full(string str) { too_full=str; }

void set_too_soaked(string str) { too_soaked=str; }

void set_too_drunk(string str) { too_drunk=str; }

void set_cmds(string *strs) { cmds=strs; }

int query_hp_heal() { return hp_heal; }

int query_sp_heal() { return sp_heal; }

int query_charges() { return charges; }

int query_intox() { return intox; }

int query_stuff() { return stuff; }

int query_soak() { return soak; }

int query_val() { return value; }

string query_player_msg() { return player_msg; }

string query_room_msg() { return room_msg; }

string query_type() { return type; }

string *query_cmds() { return cmds; }

int cmd_heals(string str) {
    mapping heals;
    object ob;
    string *indices;
    int total;
    int i;
    heals=([ ]);
    ob=first_inventory(TP);
    while(ob) {
        if((int)ob->is_heal()) {
            heals[(string)ob->query_short()]+=(int)ob->query_charges();
            total++;
        }
    ob=next_inventory(ob);
    }
    indices=keys(heals);

    write("Heals                         Charges\n");
    write("-------------------------------------\n");
    for(i=0; i < sizeof(indices); i++) {
        write(pad(indices[i],30));
        write(heals[indices[i]]+"\n");
    }
    write("You have "+total+" heals.\n");  
    return 1;
}

/* A deep_inventory version of cmd_heals */
int cmd_heals_all(string str) {
    mapping heals;
    object *inv;
    string *indices;
    int size;
    int i;
    int total;
    heals=([ ]);
    inv=deep_inventory(TP);
    size=sizeof(inv);
    for(i=0; i < size; i++) {
        if(inv[i]->is_heal()) {
            heals[(string)inv[i]->query_short()]+=(int)inv[i]->query_charges();
            total++;
        }
    }
    indices=keys(heals);

    write("Heals                         Charges\n");
    write("-------------------------------------\n");
    size=sizeof(indices);
    for(i=0; i < size; i++) {
        write(pad(indices[i],30));
        write(heals[indices[i]]+"\n");
    }
    write("You have "+total+" heals.\n");  
    return 1;
}
