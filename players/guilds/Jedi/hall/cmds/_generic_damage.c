#include "../defs.h"
#include "../ansi.h"

main(string str)
{
   object them;
   int cost, spell_power;
   string me_mess, them_mess, target_mess;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   return 0;
   if(TP->query_ghost())
      {
      write("You're dead. Please lie still.\n");
      return 1;
   }
   
   if(C_OBJ->spell_is_delayed())
      {
      write("You must wait to use this ability.\n");
      return 1;
   }
   
   if(environment(TP)->query_no_fight())
      {
      write("You cannot do that here.\n");
      return 1;
   }
   
   cost = C_OBJ->query_spell_cost();
   
   if(TP->query_sp() < cost)
      {
      write("You do not have enough spell points.\n");
      return 1;
   }
   
   if(!str && TP->query_attack() && present(TP->query_attack(),environment(TP)))
      them = TP->query_attack();
   
   if(!str && !them)
      {
      write("Whom would you like to cast this on?\n");
      return 1;
   }
   
   if(!them)
      them = present(str,environment(TP));
   
   if(!them || (them->query_invis() && them != TP->query_attack()))
      {
      write("Where do you see them?\n");
      return 1;
   }
   
   if(!them->is_player() && !them->query_npc())
      {
      write("Right....\n");
      return 1;
   }

   if(them->is_player())
      {
      if(them->query_level() > 19)
         {
         write("I don't think so.\n");
         return 1;
      }
      
      if(!TP->query_pl_k() && !TP->query_fight_area())
         {
         write("You do not have your PK set.\n");
         return 1;
      }
      
      if(!them->query_pl_k() && !TP->query_fight_area())
         {
         write("They do not have their PK set.\n");
         return 1;
      }
   }
   
   if(!TP->valid_attack(them)) {
      return 1;
   }
   this_player()->attack_object(them);
   spell_power = ((2 * C_OBJ->query_spell_delay()) + random(cost / 2));
   me_mess = (string)C_OBJ->query_spell_mess_me();
   them_mess = (string)C_OBJ->query_spell_mess_room();
   target_mess = (string)C_OBJ->query_spell_mess_them();
   me_mess = call_other(TOP_DIR + "funcs","modify_spell_message",me_mess, them);
   them_mess = call_other(TOP_DIR + "funcs","modify_spell_message",them_mess, them);
   target_mess = call_other(TOP_DIR + "funcs","modify_spell_message",target_mess, them);
   write(me_mess+"\n");
   say(them_mess+"\n",them);
   tell_object(them,target_mess+"\n");
   TP->add_sp(-cost);
   C_OBJ->set_last_spell_time(time());
   them->hit_player(spell_power,C_OBJ->query_damage_type());
   return 1;
}
