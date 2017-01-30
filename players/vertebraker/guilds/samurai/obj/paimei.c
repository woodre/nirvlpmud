#include "../def.h"

inherit "/obj/monster";

#define PM HIW+"P"+NORM+"ai "+HIW+"M"+NORM+"ei"
#define HA HIW+"H"+NORM+"a "+HIW+"H"+NORM+"a "+HIW+"H"+NORM+"a"

int sparring,complete;
object spar_obj;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(PM);
  set_alias("pai mei");
  set_alt_name("pai");
  SetMultipleIds(({"mei"}));
  set_race("human");
  set_gender("male");
  set_short(PM);
  set_long(PM+", or literally, "+HIW+"White Eyebrow"+NORM+", is a master of the\n\
Shaolin martial arts, specializing specifically in the Eagle's Claw\n\
and Northern Praying Mantis styles. He has a long "+HIW+"white"+NORM+" beard\n\
and "+HIW+"white"+NORM+" hair tied back into a long ponytail. He gazes\n\
at you with utter contempt.\n");
  set_level(30);
  set_wc(20);
  set_ac(20);
  set_hp(1000);
  set_message_hit(({
    HIR+"MASSACRED"+NORM, " with a "+HIR+"Five Point Exploding Heart Technique"+NORM,
    RED+"SMASHED"+NORM, " with an "+HIY+"Eagle's Claw"+NORM,
    YEL+"Slammed"+NORM, ", opening the "+HIG+"Jade Ring"+NORM,
    GRN+"Devastated"+NORM, ", utilizing the "+BOLD+"Secret Door"+NORM,
    GRN+"Annihilated"+NORM, ", with the Power of "+HIB+"18 Ancestors"+NORM,
    BLU+"Struck"+NORM, ", with the "+HIR+"Fury"+NORM+" of the "+HIW+"Snow Tiger"+NORM,
    CYN+"Hit"+NORM, " with "+HIC+"T'ai Chi"+NORM,
  }));
}

init()
{
  add_action("cmd_spar","spar");
  add_action("cmd_kill","kill");
}

heart_beat()
{
  object atk;
  ::heart_beat();
  if(!complete && (!attacker_ob || !present(attacker_ob, environment()) || attacker_ob->query_ghost()))
  {
    heal_self(1000000);
    sparring = 0;
    spar_obj = 0;
    return;
  }
  if(attacker_ob && random(2))
  {
    already_fight = 0;
    attack();
  }
  if(alt_attacker_ob && (attacker_ob != alt_attacker_ob))
  {
    heal_self(1000000);
    say(PM+" laughs, \""+HA+"\".\n");
    say(PM+" holds up his hand.\n");
    while(atk = attacker_ob)
    {
      stop_fight();
      if(atk)
        atk->stop_fight();
    }
    say(PM+" spits in your face!\n");
    say(PM+" laughs, \"Cheater\".\n");
    sparring = 0;
    spar_obj = 0;
    return;
  }
  if(attacker_ob && !sparring ) {
    heal_self(1000000);
    say(PM+" laughs, \""+HA+"\".\n");
    say(PM+" holds up his hand.\n");
    say(PM+" says, if you want to fight me, you must spar.\n");
    while(atk = attacker_ob)
    {
      stop_fight();
      if(atk)
        atk->stop_fight();
    }
  }
  if(attacker_ob && ((query_hp() * 10 / query_mhp()) <= 2))
  {
    heal_self(1000000);
    complete = 1;
    say(PM+" laughs, \""+HA+"\".\n");
    say(PM+" holds up his hand.\n");
    if( sparring ) 
      call_out("complete", 4);
    while(atk = attacker_ob)
    {
      stop_fight();
      if(atk)
        atk->stop_fight();
    }
  }
}

cmd_spar(str)
{
  int rank;
  int cost;
  
  if(sparring)
  {
    write(PM+" is currently sparring another Samurai.\n");
    return 1;
  }
  if(!TP || TP->query_guild_name() != "samurai")
    return 0;
  rank = TP->query_guild_rank();
  
  if(rank > 9)
  {
    write(PM+" bows to you.\n");
    write(PM+" tells you: You have already completed all your training.\n");
    return 1;
  }
  switch(rank)
  {
    case 1: cost = 350000; break;
    case 2: cost = 562500; break;
    case 3: cost = 1125000; break;
    case 4: cost = 1500000; break;
    case 5: cost = 2500000; break;
    case 6: cost = 3000000; break;
    case 7: cost = 3500000; break;
    case 8: cost = 4500000; break;
    case 9: cost = 5000000; break;
  }
  write(PM+" laughs, \""+HA+"\".\n");
  
  if(TP->query_free_exp() < cost)
  {
    write(PM+" tells you: You need "+cost+" xp to advance to your next rank.\n");
    return 1;
  }
  
  TP->add_exp(-cost);
  spar_obj = TP;
  sparring = 1;
  
  write(PM+" tells you: Let us begin.\n");
  say(PM+" moves into a graceful kata position.\n");
  
  call_out("spar", 4);
  
  return 1;
}

spar()
{
  if(!spar_obj || !present(spar_obj, ENV()))
  {
    sparring = 0;
    spar_obj = 0;
    return;
  }
  else
  {
    say(PM+" laughs, \""+HA+"\".\n");
    say(PM+" moves into an "+HIY+"Eagle's Claw"+NORM+" stance.\n");
    say(PM+" strokes his "+HIW+"white"+NORM+" beard.\n");
    call_out("spar2", 4);
  }
}

spar2()
{
  if(!spar_obj || !present(spar_obj, ENV()))
  {
    sparring = 0;
    spar_obj = 0;
    return;
  }
  else
  {
    say(PM+" smiles diabolically.\n");
    say(PM+" motions at you.\n");
    call_out("spar3", 4);
  }
}

spar3()
{
  if(!spar_obj || !present(spar_obj, ENV()))
  {
    sparring = 0;
    spar_obj = 0;
    return;
  }
  else
  {
    set_wc(20 + spar_obj->query_guild_rank() * 12);
    set_ac(20 + spar_obj->query_guild_rank() * 5);
    set_hp(1000 + spar_obj->query_guild_rank() * 400);
    heal_self(100000);
    say(PM+" attacks!\n");
    attack_object(spar_obj);
  }
}

complete()
{

  if(!spar_obj || !present(spar_obj, ENV()))
  {
    sparring = 0; 
    spar_obj = 0;
#if 0
    tell_room( ENV(), "Complete failed due to no spar_obj or no ENV.\n");
#endif
    return;
  }

  if(spar_obj->query_guild_name() != "samurai") {  
    return; 
  }

  say(PM+" bows to "+spar_obj->query_name()+".\n", spar_obj);
  tell_object(spar_obj, PM+" bows to you.\n");
  spar_obj->add_guild_rank(1);
  command("id :has advanced in the guild!\n", spar_obj);

  sparring = 0; 
  spar_obj = 0;
  complete = 0;

  return 1;
}

cmd_kill(str)
{
   write("You cannot do that here!\n");
   return 1;
}

query_long() { 
  string str;
  str = long_desc;
  if( this_player() && this_player()->query_level() > 40 ) {
    str = str + "Sparring : " + sparring +"\n\
Spar Obj : " + (spar_obj ? spar_obj->query_name() : "None")+"\n";
  }
  return str; 
} 
