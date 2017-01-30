/******************************************************************************
 *  
 *  File:           sash.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         Started 9/16/01.
 *  
 *  Notes:			
 *  
 *  Change History: 9/24/01,9/25/01,
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

#define FILE "/players/vital/closed/std/heal.c"

inherit "/obj/armor.c";
inherit FILE;

int hp_heal, sp_heal, charges, value, intox, soak, stuff;

string player_msg, room_msg, type, container, too_full, too_soaked, too_drunk;
string *cmds; /* An array of commands for using this heal */
string short_desc, long_desc, info, name, alias, alt_name;
int save_flag, value, local_weight, wait;
string *ids;


reset(arg) {
  if(arg) return;
  set_name("sash");
  set_alias("belt");
  set_alt_name("silk sash");
  set_short("A silk sash");
  set_long("\
  This is a beautiful sash made from the finest silk. The silk was \n\
collected from the cold worms found in the foot-hills of the Acadie \n\
mountain ranges. The silk is woven by small nano-bots who weave \n\
themselves into the fabric itself that give it several special \n\
properties.\n");
  set_weight(1);
  set_value(2);
  set_heal(-2,-2);
  set_charges(1000);
  set_ac(1);
  set_type("belt");
  set_info("The nanobots are excited by the adrenaline found in the blood-\nstream. At elevated levels such as in battle, they can \neven respond by going into an overload cycle pulling energy \ndirectly from the stomach when you rub it between your fingers.\n");
  set_cmds( ({
    "rub"
  }) );
}

void set_name(string str) { name = str; }

void set_alt_name(string str) { alt_name = str; }

void set_alias(string str) { alias = str; }

void set_value(int v) { value = v; }

void set_info(string str) { info = str; }

void set_weight(int w) { local_weight = w; }

void set_save_flag() { save_flag = 1; }

int get() { return 1; }
int query_weight() { return local_weight; }
string query_info() { return info; }

void init() {
    int i,s;
    ::init();
    if(!present(TO,TP)) return;
    s=sizeof(cmds);
    for(i=0; i < s; i++) add_action("cmd_heal",cmds[i]);
}

int is_heal() { return 1; }
int query_value() { return value; }
int query_save_flag() { if(file_name(TO)==FILE) return 1; }
int generic_object() { return 1; }
string locker_arg() { return ""+1000; }
void locker_init(string arg) {
    if(sscanf(arg,"%d",charges)!=1) {
        write("Object failed to initialize properly.  Destructing.\n");
        destruct(TO);
    }
}

int restore_thing(string str) { restore_object(str); return 1; }
int save_thing(string str) { save_object(str); return 1; }

int cmd_heal(string str) {
    if(!str || TO!=present(str,TP)) {
        notify_fail(capitalize(query_verb())+" what?\n");
        return 0;
    }
    if(!worn) {
	notify_fail("The sash is not currently around your waist so it cannot \nhelp you. Try wearing the sash first.\n");
        return 0;
    }
    if(wait) {
        notify_fail("The sash moves away from your fingers as you reach for it.\n");
        return 0;
    }
    if(!wait) {
        call_out("detox_heal",1);
        wait = random((environment(this_object())->query_level())+1);
        write(player_msg);
    }
    return 1;
}

int detox_heal() {
    object who;
    who = environment(this_object());
    if(who->query_soaked() > 1) who->drink_soft(-1);
    if(who->query_stuffed() > 1) who->eat_food(-1);
    if(who->query_intoxination() > 1) who->drink_alcohol(-1);
    if(!worn) return 1;
    who->add_hit_point(hp_heal);
    who->add_spell_point(sp_heal);
    tell_object(who,"The fabric of the sash ripples and moves around your waist.\n");
    if(room_msg) tell_room(environment(who),(string)who->query_name()+room_msg);
    if(wait) {
        remove_call_out("detox_heal");
        call_out("detox_heal", (random(4) + 1) );
        wait--;
        return 1;
    }
    return 1;
}

void set_heal(int hp,int sp) { hp_heal=hp; sp_heal=sp; }

void set_charges(int x) { charges=x; }

void set_intox(int x) { intox=x; }

void set_stuff(int x) { stuff=x; }

void set_soak(int x) { soak=x; }

void set_player_msg(string str) { player_msg=str; }

void set_room_msg(string str) { room_msg=str; }

void set_type(string str) {  type=str; }

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

