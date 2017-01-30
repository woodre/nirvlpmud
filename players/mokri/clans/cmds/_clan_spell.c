#include "../defs.h"

int main(string str)
{
   string me_mess, them_mess, target_mess, spell_alias, damage_type;
   int spell_id, spell_cost, spell_delay;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   damage_type = (string)C_OBJ->query_damage_type();
   me_mess = (string)C_OBJ->query_spell_mess_me();
   them_mess = (string)C_OBJ->query_spell_mess_room();
   target_mess = (string)C_OBJ->query_spell_mess_them();
   spell_alias = (string)C_OBJ->query_spell_alias();
   spell_id = (int)C_OBJ->query_spell_id();
   spell_cost = (int)C_OBJ->query_spell_cost();
   spell_delay = (int)C_OBJ->query_spell_delay();
   write("Clan Spell:\n"+
      "Spell type        ");
   if(spell_id == 1)
      write("Damage\n");
   else
      write("Heal\n");
   write("Spell name        " + spell_alias + "\n"+
      "Spell cost        " + spell_cost + "\n"+
      "Spell delay       " + spell_delay + "\n");
   if(spell_id == 1)
      write("Damage type       " + capitalize(damage_type) + "\n");
   write("Caster message    " + me_mess + "\n"+
      "Target message    " + target_mess + "\n"+
      "Room message      " + them_mess + "\n");
   return 1;
}
