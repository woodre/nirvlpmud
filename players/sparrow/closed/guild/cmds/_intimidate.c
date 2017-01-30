#include "../defs.h"

inherit CMD;

status cmd_assert(string str)
{
  object Atk, attacker;

  if(str) return 0;
  Atk = find_object(str)->environment(this_player);
  attacker = (object)this_player()->query_attack();
  

  if(atk) {
    write("You cannot "+HIC+"intimidate"+NORM+" while in combat!\n");
    return 1;
  }

  if((object)Atk->query_attack()==this_player())
  {
    write((string)Atk->query_name()+" is already engaged in direct combat with you!\n");
    return 1;
  }
  // Costs associated with command
  if(this_player()->query_guild_rank() < 3) {
    return 0;
  }
  
  //if(!need_mana(15)) return 1;

  //if(!need_parish(40)) return 1;

 
  write("You raise your right hand towards "+Atk->query_short()+" as your index finger\nextends into a sharp blade.);
  say(this_player()->query_name()+" extends "+this_player()->query_possessive()+" right hand towards "Atk->query_short()+" as "+this_player()->query_possessive()+" index finger\nextends into a sharp blade.);
  call_out("assert1",5);
}

assert1() {
  write("In your left hand appears a newborn fawn. You look up and sneer at "Atk->query_short()+"\n as you slit the fawn's throat!\n");
  say("In "+this_player()->query_possessive()+" left hand appears a newborn fawn. "+this_player()->query_name()+" looks up and sneers at "Atk->query_short()+"\n as "+this_player()->query_subjective()+" slits the fawn's throat!\n");
  call_out("assert2",5);
}

assert2(){
  int tempAlign,tempChange,newAlign;
  write(Atk->query_short()+" screams in rage at your evil deed and lunges for the attack!\n");
  say(Atk->query_short()+" screams in rage at your evil deed and lunges for the attack!\n");
  tempAlign = Atk->query_align();
  tempChange = (1000 - tempAlign)/3;
  newAlign = tempAlign + tempChange;
  Atk->set_alignment(newAlign);
  return;
}

