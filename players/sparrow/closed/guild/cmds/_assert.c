#include "../defs.h"

inherit CMD;

status cmd_assert(string str)
{
  object atk;

  if(str) return 0;

  atk = (object)this_player()->query_attack();

  if(!atk) {
    write("You are not in combat!\n");
    return 1;
  }

  if((object)atk->query_attack()==this_player())
  {
    write((string)atk->query_name()+" is already engaged in direct combat with you!\n");
    return 1;
  }

  if(!need_mana(15)) return 1;



  write("\nYou assert yourself upon "+(string)atk->query_name()+"!\n");
  say("\n"+(string)this_player()->query_name()+" asserts "+objective(this_player())
    +"self upon "+(string)atk->query_name()+"!\n", atk);
  tell_object(atk, "\n"+(string)this_player()->query_name()+" asserts "+objective(this_player())
    +"self upon YOU!\n");

  atk->attack_object(this_player());
  return 1;
}
