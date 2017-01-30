#include <ansi.h>
#include <security.h>
#include "defs.h"


inherit "/obj/guilds/guild_slave";

#include "lib/slaveData.h"
#include "lib/aliases.h"
#include "lib/varKeys.h"
#include "lib/udata.h"
#include "lib/body_parts.h"


void reset(status arg)
{
   if(arg) return;
   fill_in_data();
   ::reset(arg);
   MASTER->clear_statics(me);
   if(!root()) call_out("fake_beat", 2);
}


string a_or_an(string str) { return (string)"/obj/simul_efun"->a_or_an(str); }
status id(string str)
{
  if((int)ENV()->query_level() < CREATE)
  {
    if(str == "hp_regen_object") return 1;
    if(str == "sp_regen_object") return 1;
    if(str == "no_spell") return 1;
    if(str == "no_pet")   return 1;
/*
    if(str == "guild_death_object")  return 1;
*/
    if(str == "dark_sight_object")  return 1;
    if(str == "no_mini")  return 1;
    if(query_var(V_RLEG) || query_var(V_LLEG))
      if(str == "run_object")  return 1;
    if((int)ENV()->query_guild_rank() <= 2)
      if(str=="notarmor") return 1;
  }
  return (::id(str) || str == "life");
}

void init_arg(string x)
{
  if(!TP->query_undead_shadow())
  {
    object ob;
    ob = clone_object(OBJDIR+"player_shadow");
    ob->start_shadow(TP);
    TP->add_player_id("undead");
    set_var(V_SHADOW, ob);
  }
}

void remove_object()
{
  object ob;
  if(ob=query_var(V_SHADOW))
    ob->end_shadow();
}

status restore_me(string path)
{
  MASTER->clearStatics(me);
  return ::restore_me(path);
}

void extra_look()
{
  object e, tp;
  
  if((e = ENV()) == (tp = TP))
  {
    write("You are a rotting "+(query_var(V_PRIOR_RACE)?CAP(query_var(V_PRIOR_RACE)):"human")+".\n");
    if(query_var(V_HEAD))
      write("You are missing your "+BOLD+"HEAD"+NORM+"!\n");
    if(query_var(V_LARM))
      write("Your "+BOLD+"left arm"+NORM+" is gone.\n");
    if(query_var(V_RARM))
      write("Your "+BOLD+"right arm"+NORM+" has been torn off.\n");
    if(query_var(V_LLEG))
      write("Your "+BOLD+"left leg"+NORM+" has been ripped"+
            " from your body.\n");
    if(query_var(V_RLEG))
      write("Your "+BOLD+"right leg"+NORM+
            " is no longer there...\n");
  }
  else
  {
    write((string)ENV()->QN+" is a rotting "+(query_var(V_PRIOR_RACE)?CAP(query_var(V_PRIOR_RACE)):"human")+".\n");
    if(query_var(V_HEAD))
      write((string)ENV()->QN+" is missing "+possessive(ENV())+" "+
            BOLD+"HEAD"+NORM+"!\n");
    if(query_var(V_LARM))
      write((string)ENV()->QN+"'s "+BOLD+"left arm"+NORM+
            " is gone.\n");
    if(query_var(V_RARM))
      write((string)ENV()->QN+"'s "+BOLD+"right arm"+NORM
        +" has been torn off.\n");
    if(query_var(V_LLEG))
      write((string)ENV()->QN+"'s "+BOLD+"left leg"+NORM+
      " has been ripped"+" from "+possessive(ENV())+" body.\n");
    if(query_var(V_RLEG))
      write((string)ENV()->QN+"'s "+BOLD+"right leg"+NORM+
      " is no longer there...\n");
  }
}

void fake_beat()
{
  object obj, env, pob;

  if(!(obj=ENV()))
    return destruct(this_object());
  else if(interactive(obj) && (env=ENV(obj)) && !obj->query_ghost() &&
           (int)obj->QL < CREATE)
  {
    if(!random(((int)obj->QA("luc")/5+(int)obj->QGR)*400))
    {
      tell_object(obj, "\n\
  Your "+HIK+"Undead Soul"+NORM+" takes its toll on your body...\n");
      tell_room(ENV(obj), (string)obj->QN + " looks somehow weaker.\n", ({obj}));
      obj->lower_attrib();
    }
    if((int)obj->QGR > random(30))
    {
      obj->add_stuffed(-(1+random((int)obj->QGR/2)));
      obj->add_soaked(-(1+random((int)obj->QGR/2)));
    }
    MASTER->rot_objs(({obj,obj}));
    set_var(SPELL_DELAY, 0);
    while(pob = (object)MASTER->query_poison(obj))
    {
      tell_object(obj, GRN+"\
You feel something strange enter your body...\n\
Your "+HIK+"undead energy"+NORM+GRN+" destroys it instantly.\n"+NORM);
      tell_room(env,
  (string)obj->QN + " briefly looks ill, then shakes it off.\n",
       ({obj}));
      destruct(pob);
    }
    if(obj->query_infuse())
      if(random((int)obj->QA("luc")) < random(40))
      {
        tell_object(obj, "\n\
The infusion "+HIR+"burns"+NORM+" through your body...\n");
        tell_room(env,
(string)obj->QN + "'s skin "+RED+"burns"+NORM+" and snaps.\n",
        ({obj}));
        obj->HP(16-((int)obj->QGR), "other|good");
      }
  }
  call_out("fake_beat", 2);
}


int do_special(object myOwner)
{
  tell_object(myOwner, GRN+"Your "+NORM+HIK+"undead energy"+NORM+
                 GRN+" kills the pain of an invading toxin.\n"+NORM);
}

void init()
{
  object e, rm, ob;
  ::init();
  if(!(e=ENV()))
    return;
  if(!e->query_guild_rank()) e->set_guild_rank(1);
  if(!e->QueryArmor(TO))
    e->RegisterArmor(TO,({"other|poison",0,100,"do_special"}));
}

void mini_dest(string str)
{
  tell_object(ENV(), "\
As an Undead, you cannot belong to the "+str+".\n");
}

status call_pet()
{
  object c;

  if((c=CALLER) && c->is_pet())
  {
    tell_room(ENV(c), (string)c->short()+ " \
looks "+HIR+"very scared"+NORM+" of "+(string)ENV()->QN+".\n"+
(string)c->QN+" runs far away...\n");
    destruct(c);
    return 1;
  }
}

int deHeal(int x)
{
    return -(x - (int)ENV()->QGR/2);
}

int query_sp_regen()
{
  object e;
  if((e = environment()) && (int)e->query_sp() > -50)
  {
    if(!random(30))
      tell_object(e,"You feel your magic energy decaying...\n");
    return deHeal(4);
  }
}

int query_hp_regen()
{
  object e;
  if((e = environment()) && (int)e->query_hp() > 7)
  {
    if(!random(30))
      tell_object(e, "You feel your health decaying...\n");
    return deHeal(4);
  }
}

void undead_death()
{
  object c, e, dood;
  if(!MASTER) tell_object(find_player("vertebraker"), "NO MASTER\n");
  if(!(dood = ENV()))
    return;
  else
  {
    string tag;
    if(!(e=ENV(dood)) || !(c = present("corpse", e)))
      return;
    tag = "";
    if(query_var(V_HEAD))
      tag = "decapitated";
    if(query_var(V_LARM) || query_var(V_RARM))
      tag = (tag==""?"armless":tag+", armless");
    if(query_var(V_LLEG) || query_var(V_RLEG))
      tag = (tag==""?"legless":tag+", legless");
    if(tag != "")
      tag += " ";
    c->set_short(CAP(a_or_an(tag))+" "+tag+"body of an Undead "+
      (string)MASTER->retrieve_title(dood)+NORM);
    add_attribute("UndeadCorpse", c);
  }
  set_var(V_HEAD, 0);
  set_var(V_LLEG, 0);
  set_var(V_RLEG, 0);
  set_var(V_RARM, 0);
  set_var(V_RLEG, 0);
}

int do_run(string str)
{
  string what;
  if(query_var(V_LLEG) || query_var(V_RLEG))
  {
    if(query_var(V_LLEG) && query_var(V_RLEG))
      write("\nYou can't run, you don't have any legs!\n\n");
    else if(!query_var(V_LLEG) || !query_var(V_RLEG))
      write("\nYou can't run, you only have one leg!\n\
[Don't even think about hopping.]\n");
  }
  return 1;
}
