#include "../defs.h"
#include "../ansi.h"

string me_mess, them_mess, target_mess, spell_alias, damage_type;
string *damage_types_list;
int spell_id, spell_cost, spell_delay;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("clan_spell_builder");
   set_long("There is no clan_spell_builder here.\n");
}

get_help()
{
   write("Spell messages help.\n\n"+
      "You may use the following switches in your strings:\n"+
      "%newline%      Hard return. Next text is on a new line.\n"+
      "%TPN%          Casters name\n"+
      "%TP_POS%       Casters possessive (his/her)\n"+
      "%TP_PRO%       Casters pronoun (he/she)\n"+
      "%CTP_POS%      Casters possessive capitalized (His/Her)\n"+
      "%CTP_PRO%      Casters pronoun capitalized (He/She)\n"+
      "%AKN%          Targets name\n"+
      "%AK_POS%       Targets possessive (his/her)\n"+
      "%AK_PRO%       Targets pronoun (he/she)\n"+
      "%AKP_POS%      Targets possessive capitalized (His/Her)\n"+
      "%AKP_PRO%      Targets pronoun capitalized (He/She)\n\n"+
      "The following color switches are available:\n"+
      "%red%          "+RED+"Red\n"+NORM+
      "%green%        "+GRN+"Green\n"+NORM+
      "%yellow%       "+YEL+"Yellow\n"+NORM+
      "%blue%         "+BLU+"Blue\n"+NORM+
      "%magenta%      "+MAG+"Magenta\n"+NORM+
      "%cyan%         "+CYN+"Cyan\n"+NORM+
      "%white%        "+WHT+"White\n"+NORM+
      "%black%        "+BLK+"Black\n"+NORM+
      "%hi red%       "+HIR+"Hi red\n"+NORM+
      "%hi green%     "+HIG+"Hi green\n"+NORM+
      "%hi yellow%    "+HIY+"Hi yellow\n"+NORM+
      "%hi blue%      "+HIB+"Hi blue\n"+NORM+
      "%hi magenta%   "+HIM+"High magenta\n"+NORM+
      "%hi cyan%      "+HIC+"High cyan\n"+NORM+
      "%hi white%     "+HIW+"High white\n"+NORM+
      "%hi black%     "+HIBLK+"High black\n"+NORM+
      "%bold%         "+NORM+BOLD+"Bold\n"+NORM+
      "%normal%       "+NORM+"Normal\n"+NORM+
      "%underline%    "+U+"Underline\n\n"+NORM+
      "To use, simply replace the switch with what you would like to\n"+
      "see. Example (assuming player 'mokri' is casting the spell on a 'beano'):\n"+
      "Message to give to caster\n"+
      "  You cast your %red%SPELL%normal% on %AKN%.\n"+
      "  Displays: You cast your "+RED + "SPELL" + NORM + " on Beano.\n\n"+
      "Message to give to target\n"+
      "  %TPN% casts %TP_POS% %red%SPELL%normal% on you.\n"+
      "  Displays: Mokri casts his "+RED + "SPELL" + NORM + " on you.\n\n"+
      "Message to give to rest of room\n"+
      "  %TPN% casts %TP_POS% %red%SPELL%normal% on %AKN%.\n"+
      "  Displays: Mokri casts his "+RED + "SPELL" + NORM + " on Beano.\n\n");
   return 1;
}

save_spell(string str)
{
   object *us;
   int x;
   if(str != "y" && str != "Y" && str != "yes" && str != "Yes")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      destruct(this_object());
      return 1;
   }
   
   C_OBJ->set_spell_alias(spell_alias);
   C_OBJ->set_spell_delay(spell_delay);
   C_OBJ->set_spell_mess_me(me_mess);
   C_OBJ->set_spell_mess_room(them_mess);
   C_OBJ->set_spell_mess_them(target_mess);
   C_OBJ->set_spell_id(spell_id);
   C_OBJ->set_spell_cost(spell_cost);
   if(spell_id == 1)
      C_OBJ->set_damage_type(damage_type);
   write("Spell written.\n");
   us = users();
   for(x = 0; x < sizeof(us); x++)
   {
      if(us[x]->query_clan_name() == CNAME)
         {
         if(present("clan_object",us[x]))
            destruct(present("clan_object",us[x]));
         move_object(clone_object(TOP_DIR + "object"),us[x]);
       }
   }
   destruct(this_object());
   return 1;
}

set_them_mess(string str)
{
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(str == "h")
      {
      get_help();
      write("Message to give to rest of room\nType 'h' for help\n] ");
      input_to("set_them_mess");
      return 1;
   }
   if(strlen(str) < 1 && them_mess) str = them_mess;
   if(!str || strlen(str) < 1)
      {
      write("Try again.\nMessage to give to rest of room\nType 'h' for help\n] ");
      input_to("set_them_mess");
      return 1;
   }
   
   them_mess = str;
   write("Spell has following values:\n"+
      "Spell type        ");
   if(spell_id == 1)
      write("Damage\n");
   else
      write("Heal\n");
   write("Spell name        " + spell_alias + "\n"+
      "Spell cost        " + spell_cost + "\n"+
      "Spell delay       " + spell_delay + "\n");
   if(spell_id == 1)
      write("Damage Type       " + damage_type + "\n");
   write("Caster message    " + me_mess + "\n"+
      "Target message    " + target_mess + "\n"+
      "Room message      " + them_mess + "\n\n"+
      "Save and update spell? (y/n) > ");
   input_to("save_spell");
   return 1;
}

set_target_mess(string str)
{
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(str == "h")
      {
      get_help();
      write("Message to give to target\nType 'h' for help\n] ");
      input_to("set_target_mess");
      return 1;
   }
   if(strlen(str) < 1 && target_mess) str = target_mess;
   if(!str || strlen(str) < 1)
      {
      write("Try again.\nMessage to give to target\nType 'h' for help\n] ");
      input_to("set_target_mess");
      return 1;
   }
   
   target_mess = str;
   write("Message to give to rest of room\n");
   if(them_mess && strlen(them_mess) > 0)
      write("Hit enter for '" + them_mess + "'.\n");
   write("Type 'h' for help\n] ");
   input_to("set_them_mess");
   return 1;
}

set_me_mess(string str)
{
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(str == "h")
      {
      get_help();
      write("Message to give to caster\nType 'h' for help\n] ");
      input_to("set_me_mess");
      return 1;
   }
   if(strlen(str) < 1 && me_mess) str = me_mess;
   if(!str || strlen(str) < 1)
      {
      write("Try again.\nMessage to give to caster\nType 'h' for help\n] ");
      input_to("set_me_mess");
      return 1;
   }
   
   me_mess = str;
   write("Message to give to target\n");
   if(target_mess && strlen(target_mess) > 0)
      write("Hit enter for '" + target_mess + "'.\n");
   write("Type 'h' for help\n] ");
   input_to("set_target_mess");
   return 1;
}

set_damage_type(string str)
{
   int x;
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(strlen(str) < 1 && damage_type) str = (member(damage_types_list,damage_type) + 1) + "";
   if(!str || sscanf(str,"%d",x) != 1 || x < 1 || x > sizeof(damage_types_list))
      {
      write("Please select a number between 1 and " + sizeof(damage_types_list) +".\nDamage type\n] ");
      input_to("set_damage_type");
      return 1;
   }
   
   damage_type = damage_types_list[(x-1)];
   write("Message to give to caster\n");
   if(me_mess && strlen(me_mess) > 0)
      write("Hit enter for '" + me_mess + "'.\n");
   write("Type 'h' for help\n] ");
   input_to("set_me_mess");
   return 1;
}

set_spell_delay(string str)
{
   int x;
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   if(strlen(str) < 1 && spell_delay) str = spell_delay + "";
   if(!str || sscanf(str,"%d",spell_delay) != 1 || spell_delay < 1 || spell_delay > 10)
      {
      write("Please select a number between 1 and 10.\nSpell delay (in seconds)\n] ");
      input_to("set_spell_delay");
      return 1;
   }
   
   if(spell_id == 1)
      {
      write("Damage type\n");
      if(damage_type && strlen(damage_type) > 0)
         write("Hit enter for '" + damage_type + "'.\n");
      for(x = 0; x < sizeof(damage_types_list); x++)
      write((x+1) + ". " + capitalize(damage_types_list[x]) + "\n");
      write("] ");
      input_to("set_damage_type");
      return 1;
   }
   
   write("Message to give to caster\n");
   if(me_mess && strlen(me_mess) > 0)
      write("Hit enter for '" + me_mess + "'.\n");
   write("Type 'h' for help\n] ");
   input_to("set_me_mess");
   return 1;
}

set_spell_cost(string str)
{
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(strlen(str) < 1 && spell_cost) str = spell_cost + "";
   if(!str || sscanf(str,"%d",spell_cost) != 1 || spell_cost < 0 || spell_cost > 80)
      {
      write("Please select a number between 1 and 80.\nSpell point cost of spell\n] ");
      input_to("set_spell_cost");
      return 1;
   }
   
   write("Spell delay (in seconds)\n");
   if(spell_delay > 0)
      write("Hit enter for '" + spell_delay + "'.\n");
   write("] ");
   input_to("set_spell_delay");
   return 1;
}

set_spell_alias(string str)
{
   string tmp;
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(sscanf(str,"%s %s",str,tmp) == 2)
      {
      write("Spell name may only be one word.\nTry again.\nName of spell\n] ");
      input_to("set_spell_alias");
      return 1;
   }
   if(strlen(str) < 1 && spell_alias) str = spell_alias;
   if(!str || strlen(str) < 1)
      {
      write("Try again.\nName of spell\n] ");
      input_to("set_spell_alias");
      return 1;
   }
   
   spell_alias = str;
   write("Spell point cost of spell\n");
   if(spell_cost > 0)
      write("Hit enter for '" + spell_cost + "'.\n");
   write("] ");
   input_to("set_spell_cost");
   return 1;
}

int set_spell_id(string str)
{
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   if(str != "1" &&  str != "2")
      {
      write("Type is either '1' for damage, or '2' for heal. Please try again.\n] ");
      input_to("set_spell_id");
      return 1;
   }
   
   if(sscanf(str,"%d",spell_id) == 1);
   write("Name of spell\n");
   if(spell_alias && strlen(spell_alias) > 0)
      write("Hit enter for '" + spell_alias + "'.\n");
   write("] ");
   input_to("set_spell_alias");
   return 1;
}
start_spell()
{
   if(!C_OBJ || !C_OBJ->query_leader(TP->query_real_name()))
      {
      destruct(this_object());
      return 0;
   }
   
   me_mess = C_OBJ->query_spell_mess_me();
   them_mess = C_OBJ->query_spell_mess_room();
   target_mess = C_OBJ->query_spell_mess_them();
   spell_alias = C_OBJ->query_spell_alias();
   spell_id = C_OBJ->query_spell_id();
   spell_cost = C_OBJ->query_spell_cost();
   spell_delay = C_OBJ->query_spell_delay();
   damage_type = C_OBJ->query_damage_type();
   damage_types_list = ({ "dark","earth","electric","evil","fire","good","ice","laser","light","magical","mental","physical","poison","sonic","water","wind" });
   write("Spell editor. Once you set the type of spell, it cannot be changed.\n"+
      "All other aspects of the spell may be edited later.\n"+
      "You may type '~q' at any time to abort.\n\n");
   if(!spell_id)
      {
      write("Set type of spell.\n  1. Damage\n  2. Heal\n] ");
      input_to("set_spell_id");
   }
   else
      {
      write("Name of spell\n");
      if(spell_alias && strlen(spell_alias) > 0)
         write("Hit enter for '" + spell_alias + "'.\n");
      write("] ");
      input_to("set_spell_alias");
   }
   return 1;
}
