/*
File: phantasm.c
Author: Feldegast @ Nirvana.mudservices.com
Date: 6/03/2001
Description:
  A pet for crystal mages.  Little or no offensive power, but it makes a
decent distraction.  It does not play well with other pets, so the player
will have to choose between this pet or a generic pet or a wocket pet.
The only advantage this pet has over those is that it heals faster, and
looks cooler.  Note: Regenerating drains the owner's sps.
*/

#include "../defs.h"

inherit MONSTER;

object master;

void pet_check();

string short()
{
  string color;
  string prefix;

  switch(random(12))
  {
    case 0: color = HIW; break;
    case 1: color = HIB; break;
    case 2: color = HIR; break;
    case 3: color = HIY; break;
    case 4: color = HIG; break;
    case 5: color = BOLD+BLK; break;
    case 6: color = WHT; break;
    case 7: color = RED; break;
    case 8: color = BLU; break;
    case 9: color = YEL; break;
    case 10: color = GRN; break;
    case 11: color = BLK; break;
  }

  switch(random(5))
  {
    case 0: prefix = "Phantasmal"; break;
    case 1: prefix = "PHANTASMAL"; break;
    case 2: prefix = "PhAnTAsMaL"; break;
    case 3: prefix = "pHaNtaSmAl"; break;
    case 4: prefix = "PHanTAsmAL"; break;
  }
  return color + prefix + " Monster" + NORM;
}

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("phantasm");
  set_alias("monster");
  set_alt_name("pet");
  set_short(HIC+"Phantasmal Monster"+NORM);
  set_long(
    "This strange, etheriel creature seems to change shape when you're not\n"+
    "looking.  Its large gaping maws, filled with rows of sharp teeth,\n"+
    "seem to alternately grimace, leer, and grin wickedly.  Its venomous\n"+
    "claws change from six, to seven, to a hundred.  Its eyes change from\n"+
    "milky white, to pulsing bloodshot red, and then to alien, faceted eyes\n"+
    "that dissect all they see.  It is a walking, floating, stomping horror\n"+
    "derived from the petty terrors of the imagination.\n"
  );
  set_level(12);
  set_wc(3);
  set_ac(7);
  set_hp(150);
  set_can_kill(1);
  set_chat_chance(1);
  load_chat("The phantasmal monster gibbers and moans.\n");
  load_chat("The phantasmal monster growls and spits.\n");
  load_chat("The phantasmal monster howls and screams.\n");
  load_chat("The phantasmal monster hovers.\n");
  set_dead_ob(this_object());
}

void init()
{
  ::init();
  if(master && TP == master)
  {
    add_action("cmd_command", "phantasm");
    add_action("cmd_disbelieve", "disbelieve");
  }
  pet_check();
}

void heart_beat()
{
  ::heart_beat();
  if(!master || master->query_dead())
  {
    say(short() + " vanishes as his master's belief in him disappears.\n");
    if(money)
    {
      object moola;  
      moola = clone_object("/obj/money.c");
      moola->set_money(money);
      move_object(moola, environment());
    }
    destruct(this_object());
    return;
  }

  if(hit_point + 5 < max_hp && (int)master->query_sp() > 1)
  {
    if(!random(4))
      tell_object(master, MAG+"You expend some mental energy maintaining the phantasm's illusion.\n"+NORM);
    master->add_spell_point(-1);
    hit_point += 5;
    if(hit_point > max_hp) 
      hit_point = max_hp;
  }

  if(!present(master, environment()))
  {
    say(short()+" leaves.\n");
    move_object(this_object(), environment(master));
    say(short()+" arrives.\n");
  }
}  

void set_master(object ob)
{
  master = ob;
}

object query_owner()
{
  return master;
}

int cmd_command(string str)
{
  object targ;
  string targname;
  
  if(!str) {
    write("The "+short()+" glares at you balefully.\n");
    return 1;
  }
  if(sscanf(str, "attack %s", targname) == 1)
  {
    targ = present(targname, environment(this_player()));
    if(!targ)
    {
      write("The "+short()+" glares at you balefully.\n");
      return 1;
    }
    if((int)targ->is_player() || !valid_attack(targ))
    {
      write(short() + " can't attack "+(string)targ->query_name()+".\n");
      return 1;
    }
    attacked_by(targ);
    tell_room(environment(),
      short() + " bares its fangs and extends its claws as it rushes at " 
      + (string)targ->query_name() + "!\n");
    return 1;
  }
}

int cmd_disbelieve(string str)
{
  if(!id(str)) return 0;
  write("You cease to believe in "+short()+".\n");
  say(short()+" slowly fades away and finally ceases to exist.\n");
  destruct(this_object());
  return 1;
}

void monster_died(object ob)
{
  tell_room(environment(), short()+" vanishes as belief in it wanes.\n");
}

void pet_check()
{
  object ob, next;
  if(!environment()) return;
  if(!master) destruct(this_object());
  ob = first_inventory(environment());

  while(ob)
  {
    next = next_inventory(ob);
    if(ob!=this_object() && ((int)ob->is_pet() || (int)ob->id("pet")) && (object)ob->query_owner() == master)
    {
      tell_room(environment(), short() + " swells up to twice its size, opens up its vast maw and GROWLS\n"+
            "at "+(string)ob->short()+".  "+(string)ob->query_name()+" runs away!\n");
      destruct(ob);
    }
    ob = next;
  }
}
