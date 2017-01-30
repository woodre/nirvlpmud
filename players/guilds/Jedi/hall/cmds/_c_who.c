#include "../defs.h"
#include "../ansi.h"

main(string str)
{
   
   int x, a;
   object *us;
   string names, my_hp, my_sp, my_money, *colors, *people;
   
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   colors = ({ HIC,HIY });
   
   if(str)
      {
      people = explode(str,",");
      for(x = 0; x < sizeof(people); x++)
      {
         while(extract(people[x],0,0) == " ")
         people[x] = extract(people[x],1);
         while(extract(people[x],strlen(people[x]) - 1) == " ")
         people[x] = extract(people[x],0,strlen(people[x]) - 2);
      }
   }
   
   us = users();
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" +
      HIY+"Name           HP    SP    Money\n"+NORM+
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   a = 0;
   for(x = 0; x < sizeof(us); x++)
   {
      if(!us[x]->is_testchar() && environment(us[x]) && us[x]->query_clan_name() == TP->query_clan_name())
         {
         if(!str || (str && member(people,(string)us[x]->query_real_name()) != -1))
            {
            if(us[x]->query_invis())
               names = "(" + capitalize(us[x]->query_real_name()) + ")";
            else
               names = capitalize(us[x]->query_real_name());
            if(C_OBJ->query_leader(us[x]->query_real_name())) names = "*" + names;
            if(us[x]->query_level() > 19 && !us[x]->query_invis() || us[x]->query_level() < 20)
               {
               if(us[x]->query_level() > 19)
                  {
                  my_hp = "----";
                  my_sp = "----";
                  my_money = "-----";
               }
               else
                  {
                  my_hp = (100 * us[x]->query_hp() / us[x]->query_mhp()) + "%";
                  my_sp = ( 100 * us[x]->query_sp() / us[x]->query_msp()) + "%";
                  my_money = (int)us[x]->query_money();
               }
               write(colors[a % 2] + pad(names,15) + pad(my_hp,-4) + "  " + pad(my_sp,-4) + "  " + pad(my_money,8) + "\n" + NORM);
               a++;
            }
         }
         
       }
   }
   
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" + "* == Clan leader\n");
   return 1;
}
