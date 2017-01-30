/*
File: synch_ob.c
Author: Feldegast / Philmore Wunderchez
Date: 9/24/01
Description:
  The "client" object for the synch spell.  Players that've been
synched receive a bonus to their attack if everybody who is synched
is in the same room attacking the same target.
*/

#include "../defs.h"

object master;

string synch_list()
{
  int i,j;
  object *syn;
  string list;

  if(!master)
  {
    tell_object(environment(), "Your synch crystal vanishes!\n");
    destruct(this_object());
    return "";
  }

  syn = (object *)master->query_synch();

  for(i = 0, j=sizeof(syn); i < j; i++)
  {
    if(j > 2 && i==j)
      list += " and";
    if(syn[i] != environment())
      list += " " + (string)syn[i]->query_name();
  }

  return list;
}

void set_master(object ob)
{
  master = ob;
}

int drop()
{
  tell_object(environment(), "Your synch crystal vanishes!\n");
  master->remove_synch(environment());
  destruct(this_object());
  return 0; 
}

int get() { return 0; }

int id(string str)
{
  return str == "crystal_mage_synch_object" ||
         str == "generic_wc_bonus" ||
         str == "synch crystal" ||
         str == "crystal";
}

string short()
{
  string str;
  str = CYN + " -=*=- " + HIW + "Synch Crystal " + NORM + CYN + "-=*=-" + NORM;
  if(this_player() && (int)this_player()->query_level() > 20)
    str += " [" + synch_list() + "]";
  return str;
}

void long()
{
  write("This is a clear, transparent crystal that pulses with sympathetic vibrations.\n"+
        "These sympathetic vibrations enable you to synchronize your attacks with your\n"+
        "companions.  You are synched with "+synch_list()+".\n");
}

void init()
{
  add_action("cmd_leave", "party");
}

int cmd_leave(string str)
{
  if(str == "leave")
    drop();
  return 0;
}

int gen_wc_bonus()
{
  object *syn;
  object att;
  int i, j;

  if(!master || !present("party_object", environment()) )
  {
    tell_object(environment(), "Your synch crystal vanishes!\n");
    destruct(this_object());
    return 0;
  }

  syn = (object *)master->query_synch();

  att = (object) environment()->query_attack();

  if(!att) return;

  for(i = 0, j = sizeof(syn); i < j; i++)
  {
    if(!syn[i] || environment(syn[i]) != environment(environment()) || (object)syn[i]->query_attack() != att)
      return;
  }

  if(!random(10))
  {
     i = random(sizeof(syn));
     tell_object(environment(), "You synchronize your attack with " + (string)syn[i]->query_name()+".\n");
     tell_object(syn[i],        "You synchronize your attack with " + (string)environment()->query_name()+".\n");
     tell_room(environment(syn[i]), 
       (string)environent()->query_name() + " and " + (string)syn[i]->query_name() +
       " attack " + (string)att->query_name() + " in tandem!\n",
       ({ environment(), syn[i] }) );
  }

  return 1;
}

