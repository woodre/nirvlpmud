#include <ansi.h>

object *attackers;
string *ids;

#define DECAY_TIME	100

string name,info;
int corpse_level,decay,killtime;
int mhp,wc,ac;
int exp_worth;
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
    if( this_player() && this_player()->query_level() > 50 )
      write("\tCorpse Level: "+corpse_level+"\n\
\tDecay       : "+decay+"\n\
\tExp Worth   : "+exp_worth+"\n\
\tHeal Value  : "+heal_value()+"\n");
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

destruct_inventory(object obj) {
  int i, siz;
  object next_ob;
  object *ob;

  if( !obj )
    obj = this_object();

  ob = all_inventory(obj);

  for( i=0, siz = sizeof(ob); i < siz; i++ ) {
    /** Destroy contents of a bag **/
    if( ob[i]->can_put_and_get() )
      destruct_inventory( ob[i] );

    destruct(ob[i]);
  }
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

/**************************************
 Added by Gnar for Prestige, testing
 concept for now.
***************************************/
#if 1
remove_object() {
  int skill;
  object tp,gold;

  if( !environment() )
    return;

  tp = this_player();

  if( tp ) {
    skill = tp->query_prestige_skill("gold");
    if( skill ) {
      gold = clone_object( "/obj/money" );
      gold->set_money(1+random(100 * skill));
      move_object( gold, environment(tp) );
      tell_object( tp, HIY+"Your prestige has brought forth extra wealth!\n"+NORM);
      tell_room( environment(tp), HIY+tp->query_name()+"'s prestige has blessed "+tp->query_possessive()+" wealth!\n"+NORM, ({tp}) );
    }
    /* tell_object( tp, "Corpse dested.\n" ); */
  }
}
#endif

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

set_exp_worth( int amt ) { 
  exp_worth = amt; 
  if( exp_worth < 0 )
    exp_worth = 0;
}
int query_exp_worth() { return exp_worth; }
