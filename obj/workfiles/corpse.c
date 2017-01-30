#ifndef LDMUD /* In preparation for conversion - Rumplemintz */
object *attackers;
string *ids;

#define DECAY_TIME	100

string name,info;
int corpse_level,decay,killtime;
int mhp,wc,ac;
static string shortdesc,longdesc,killer;

prevent_insert() {
    write("The corpse is too big.\n");
    return 1;
}

init() {
#if 0 /* Rumplemintz */
    add_action("search"); add_verb("search");
#else
  add_action("search", "search");
#endif
    if(!name)
      set_name("noone");
}

reset(arg) {
    if(arg) return;
    if(!root())
    set_heart_beat(1);
    ids = ({ });
}

set_name(n)
{
    name = n;
    decay = DECAY_TIME;
}

short() {
    if(!name)
    set_name("noone");
    if (decay < 20)
	return "the somewhat decayed remains of " + capitalize(name);
    if(!shortdesc)
    return "corpse of " + capitalize(name);
    else return shortdesc;
}

long() {
    if(!longdesc)
    write("This is the dead body of " + capitalize(name) + ".\n");
    else write(longdesc +"\n");
}

id(str) {
    if(!ids) ids = ({ });
    return str == "corpse" || str == "corpse of " + name ||
        str == "remains" || (member_array(str, ids) > -1);
}

heart_beat()
{
    decay -= 1;
    if (decay > 0)
	return;
   move_stuff(this_object());
    destruct(this_object());
}

can_put_and_get() { 
    if(killer && this_player()) {
    if(killer && killer != this_player()->query_real_name())
    if(decay + 2 > killtime && present(killer,environment())) {
      write("You are blocked from the corpse by "+
        capitalize(killer)+".\n");
      return 0;
    }
    }
    return 1; 
}

search(str)
{
    object ob;
    if (!str || !id(str))
	return 0;
    if(killer && killer != this_player()->query_real_name())
      if(decay + 3 > killtime && present(killer,environment())) {
        write("You are blocked from the corpse by "+
          capitalize(killer)+".\n");
      return 1;
    }
    write("You search " + str + ", and find:\n");
    say(call_other(this_player(), "query_name") + " searches " + str + ".\n");
    if ( ! search_obj(this_object()))
    {
	write("\tNothing.\n");
    }
    else
    {
	write("\n");
    }
    return 1;
}

search_obj(cont)
{
    object ob;
    int total;
    string item;

    if (!call_other(cont, "can_put_and_get"))
	return 0;
    ob = first_inventory(cont);
    while(ob) {
	total += 1;
	item = call_other(ob, "short");
	write(item + ", ");
	ob = next_inventory(ob);
    }
    return total;
}

get() {
    if(killer && killer != this_player()->query_real_name()) 
    if(decay + 3 > killtime && present(killer,environment())) {
      write("You are blocked from the corpse by "+
        capitalize(killer)+".\n");
      return 0;
    }
    return 1;
}

query_weight() {
    return 5;
}
set_corpse_level(arg) {
          corpse_level = arg;
           return 1;
}
set_level(arg) { return set_corpse_level(arg); }
heal_value() {
int heal;
     heal = 9*corpse_level/10;
return heal;
}
query_name() { return name; }
query_corpse_level() { return corpse_level; }
move_stuff(cont) {
object hob,ob;
    ob = first_inventory(cont);
    while(ob) {
       hob=next_inventory(ob);
       move_object(ob,environment(cont));
       ob=hob;
    }

return 1;
}
set_short(arg) { shortdesc = arg; }
set_long(arg) {longdesc = arg; }
set_info(s){ info = s; }
query_info(){ return info; }

add_id(str) { if(!ids) ids = ({ });
    ids += ({ str }); }

is_corpse() { return 1; }

add_decay(x) { decay += x; }

query_attackers() { return attackers; }
set_attackers(x) { attackers=x; }

query_decay() { return decay; }
set_killer(str) {
   killtime = decay; 
   killer = str; 
}

set_mhp(arg) { mhp=arg; }
set_ac(arg) { ac = arg; }
set_wc(arg) { wc = arg; }
query_mhp() { return mhp; }
query_ac() { return ac; }
query_wc() { return wc; }
query_killer(){ return killer; }

#else
/*
 * obj/corpse
 *
 * A decaying corpse, it is created automatically when a player or monster
 * dies.
 * Rumplemintz@Nirvana
 */

#pragma strong_types

#include <persistence.h>  // on chance that a player leaves a corpse full of
                          // items
#include <describe.h>
#include <event.h>
#include <gender.h>
#include <message.h>

#define DECAY_TIME      300
#define STANDARD_WEIGHT 5

inherit "basic/plural";
inherit "complex/container";

private string name, race;
private int decay, weight;

int prevent_insert() {
  write("The corpse is too big.\n");
  return 1;
}

private void dont_insert_things(mapping e, string type, int prio) {
  if (e[E_RECIPIENT] != this_object())
    return;
  cancel_event();
  message("Tsk tsk tsk. Forget that. A corpse is no container.\n", e[E_AGENT]);
}

string corpse_short() {
  if (decay < 2)
    return "the somewhat decayed remains of " + name;
  if (query_gender() == GND_PLURAL)
    return "corpses of " + name;
  else
    return "corpse of " + name;
}

string corpse_long() {
  if (query_gender() == GND_PLURAL)
    return "These are the dead bodies of " + name + ".\n");
  else
    return "This is the dead body of " + name + ".\n");
}

void set_gender(int g) {
  if (g != GND_PLURAL)
    g = GND_NEUTER;
  return plural::set_gender(g);
}

void create() {
  container::create();
  if (clonep())
    call_out(#'destruct, 60, this_object());
}

void configure() {
  container::configure();
  set_persistence("obj/corpse", PER_KEEP_VARS,
      ({ ({ "name", "set_name", "query_original_name" }), "decay",
         "weight", "gender" }));
  remove_persistent_variable("short");
  set_short(#'corpse_short);
  set_long(#'corpse_long);
  set_id(({ "corpse", "remains" }));
  name = "noone";
  decay = 2;
  weight = STANDARD_WEIGHT;
}

void set_name(string n) {
  if (n) {
    name = n;
    add_id("corpse of " + lower_case(n));
  }
}

string query_race() {
  return race;
}

void set_race(string r) {
  if (LIB_RACE->query_is_known_race(r))
    race = r;
}

void set_decay(int d) {
  decay = d;
}

int query_decay() {
  return decay;
}

void decay() {
  decay -= 1;
  if (decay > 0) {
    call_out("decay", 20);
    if (decay == 1)
      set_plural();
    return;
  }
  destruct(this_object());
}

varars status can_put_and_get(string cid, object insert) {
  return 1;
}

// This is necessary as there is code that tries to move things into
// corpses using the efun 'transfer' and without this, transfer fails
status add_encumbrance(int enc) {
  return 1;
}

int search(string str) {
  object ob, *obs;

  if (!id(str))
    return 0;
  message(({ ({ M_SAY, M_PL_THE, M_PL_VERB, "search",
                M_OBJECT, M_ME_THE, "." }),
             ({ M_WRITE, "You search ",M_OBJECT,M_ME_THE,", and find:" }) }));
  message(capitalize(make_list(describe_list(can_put_and_get() &&
                                          all_inventory(this_object()) || ({ }),
                                          ARTICLE_A),
                               "nothing")) + ".\n");
  return 1;
}

int apply_action(string action, int level, mapping arg) {
  switch(action) {
  case "search":
    if (arg[E_TARGET] == this_object())
      return search(arg[E_ID]);
    return 0;
  }
  return 0;
}

int query_weight() {
  return weight;
}

string query_original_name() {
  return name;
}

void set_weight(int i) {
  if (intp(i))
    weight = i;
}

int prevent_move() {
  return !clonep();
}

void notify_move(object from, mixed to) {
  if (!from) {
    listen_event("put", 900, #'dont_insert_things);
    call_out("decay", DECAY_TIME);
    remove_call_out(#'destruct);
  }
}

#endif /* LDMUD */
