#include "defs.h"
#include "ansi.h"

void remove_files(string str)
{
   string *files, *dir_list;
   int x, a;
   dir_list = ({ str + "/hall/saves", str + "/hall", str });
   if(file_size(TOP_DIR + str) != -2) return;
   for(a = 0; a < sizeof(dir_list); a++)
   {
      if(file_size(TOP_DIR + dir_list[a] + "/") == -2)
         {
         files = get_dir(TOP_DIR + dir_list[a] + "/");
         for(x = 0; x < sizeof(files); x++)
         rm(TOP_DIR + dir_list[a] + "/" + files[x]);
         rmdir(TOP_DIR + dir_list[a]);
       }
   }
}

int query_clan_exists(string str)
{
   if(file_size(TOP_DIR + lower_case(str)) == -1) return 0;
   return 1;
}

int add_clan(string str)
{
   if(!TP->valid_name(str)) return 0;
   if(query_clan_exists(str))
      {
      write("Clan name already exists.\n");
      return 0;
   }
   
   mkdir(TOP_DIR + str);
   mkdir(TOP_DIR + str + "/hall");
   mkdir(TOP_DIR + str + "/hall/saves");
#ifndef __LDMUD__
   cp(TOP_DIR + "hall_rooms/templates/main.c",TOP_DIR + str + "/hall/main.c");
#else
   copy_file(TOP_DIR + "hall_rooms/templates/main.c",TOP_DIR + str + "/hall/main.c");
#endif
   return 1;
}

int remove_clan(string str)
{
   if(!query_clan_exists(str)) return 0;
   remove_files(str);
   return 1;
}

int in_clan_hall(object whom, string clan)
{
   string *tmp1, *tmp2;
   int x, is_there;
   if(!whom || !clan) return 0;
   is_there = 0;
   
   if(whom && environment(whom))
      {
      is_there = 1;
      tmp1 = explode(TOP_DIR + clan + "/hall","/");
      tmp2 = explode("/" + file_name(environment(whom)),"/");
      if(sizeof(tmp1) > sizeof(tmp2)) return 0;
      for(x = 0; x < sizeof(tmp1); x++)
      {
         if(tmp1[x] != tmp2[x]) is_there = 0;
      }
   }
   
   return is_there;
}

string modify_spell_message(string str, object other)
   {
   mapping conversions;
   mixed my_keys;
   string *temp;
   int x;
   if(!TP) return "";
   if(!other) other = (object)TP->query_attack();
   conversions = ([ ]);
   conversions["%TPN%"] = (string)TP->query_name();
   conversions["%TP_POS%"] = (string)TP->query_possessive();
   conversions["%TP_PRO%"] = (string)TP->query_pronoun();
   conversions["%CTP_POS%"] = capitalize((string)TP->query_possessive());
   conversions["%CTP_PRO%"] = capitalize((string)TP->query_pronoun());
   if(other)
      {
      conversions["%AKN%"] = capitalize((string)other->query_name());
      conversions["%AK_POS%"] = (string)other->query_possessive();
      conversions["%AK_PRO%"] = (string)other->query_pronoun();
      conversions["%AKP_POS%"] = capitalize((string)other->query_possessive());
      conversions["%AKP_PRO%"] = capitalize((string)other->query_pronoun());
   }
   conversions["%red%"] = RED;
   conversions["%green%"] = GRN;
   conversions["%yellow%"] = YEL;
   conversions["%blue%"] = BLU;
   conversions["%magenta%"] = MAG;
   conversions["%cyan%"] = CYN;
   conversions["%white%"] = WHT;
   conversions["%black%"] = BLK;
   conversions["%hi red%"] = HIR;
   conversions["%hi green%"] = HIG;
   conversions["%hi yellow%"] = HIY;
   conversions["%hi blue%"] = HIB;
   conversions["%hi magenta%"] = HIM;
   conversions["%hi cyan%"] = HIC;
   conversions["%hi white%"] = HIW;
   conversions["%hi black%"] = HIBLK;
   conversions["%bold%"] = BOLD;
   conversions["%normal%"] = NORM;
   conversions["%underline%"] = U;
   conversions["%newline%"] = "\n";
   my_keys = keys(conversions);
   for(x = 0; x < sizeof(my_keys); x++)
   {
      if(strlen(str) >= strlen(my_keys[x]))
         {
         if(extract(str,0,strlen(my_keys[x])-1) == my_keys[x])
            str = conversions[my_keys[x]] + extract(str,strlen(my_keys[x]));
       }
      
      if(strlen(str) >= strlen(my_keys[x]))
         {
         if(extract(str,strlen(str)-strlen(my_keys[x])) == my_keys[x])
str = extract(str,0,strlen(str)-strlen(my_keys[x])-1) + conversions[my_keys[x]];
       }
       
      temp = explode(str,my_keys[x]);
      
      if(sizeof(temp) > 1) str = implode(temp,conversions[my_keys[x]]);
   }
   
   return str + NORM;
}
