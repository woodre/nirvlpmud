#include "../defs.h"
#define MAX_DESC_LINES 10
string long_desc;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("clan_long_builder");
   set_long("There is no clan_long_builder here.\n");
}

int build_long(string str)
{
   string *tmp;
   if(!C_OBJ || !C_OBJ->query_leader(TP->query_real_name()))
      {
      destruct(this_object());
      return 0;
   }
   
   if(!str) str = "";
   if(str == "**")
      {
      if(!long_desc)
         {
         write("Long description blank. Aborting.\n");
         destruct(this_object());
         return 1;
      }
      
      write("Setting long description to:\n" + (string)call_other(TOP_DIR + "funcs","modify_spell_message",long_desc, this_player()) + "\n");
      C_OBJ->set_clan_long(long_desc);
      destruct(this_object());
      return 1;
   }
   
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(this_object());
      return 1;
   }
   
   long_desc += str + "\n";
   tmp = explode(long_desc,"\n");
   if(sizeof(tmp) >= MAX_DESC_LINES)
      {
      write("Maximum length numbers reached.\n");
      build_long("**");
      destruct(this_object());
      return 1;
   }
   else
      {
      write("] ");
      input_to("build_long");
   }
   return 1;
}

start_long()
{
   if(!C_OBJ || !C_OBJ->query_leader(TP->query_real_name()))
      {
      destruct(this_object());
      return 0;
   }
   
   long_desc = "";
   write("Input description, one line at a time.\nUse '**' on a blank line to finish, and ~q to abort.\n] ");
   input_to("build_long");
   return 1;
}
