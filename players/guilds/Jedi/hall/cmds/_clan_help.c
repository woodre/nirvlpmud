#include "../defs.h"
#include "../ansi.h"

int list_dir(string path)
{
   int x, a, b, longest;
   string file, *files;
   
   files = get_dir(path);
   longest = -1;
   for(x = 0; x < sizeof(files); x++)
   {
      if(strlen(files[x]) + 1> longest)
         longest = strlen(files[x]) + 1;
   }
   
   for(x = 0; x < sizeof(files); x++)
   {
      write(capitalize(files[x]));
      for(a = 0; a < (longest - strlen(files[x])); a++)
      write(" ");
      b++;
      if(b == 4)
         {
         b = 0;
         write("\n");
       }
   }
   return 1;
}

int main(string str)
{
   int x;
   string my_dir, file, *files;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!str)
      {
      write("Clan_help is available on the following items:\n");
      list_dir(TOP_DIR + "docs/help/");
      if(C_OBJ->query_leader(TP->query_real_name()))
         {
         write("\n\nLeader help items:\n");
         list_dir(TOP_DIR + "docs/help_leader/");
      }
      write("\n");
      return 1;
   }
   
   str = lower_case(str);
   my_dir = TOP_DIR + "docs/help/";
   files = get_dir(my_dir);
   x = member(files,str);
   if(x == -1 && C_OBJ->query_leader(TP->query_real_name()))
      {
      if(str == "color" || str == "colors")
         {
         write("While editing certain clan values, you may use\n"+
            "the following switches in your strings:\n"+
            "Switch         Result\n"+
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
            "Simply replace the color switch with what you would like to\n"+
            "display.\n"+
            "Example:\n"+
            "  %red%this is a %blue%BLUE%normal% object would display:\n"+
            "  " + RED + "this is a " + BLU + "BLUE" + NORM + " object.\n"+
            "\n\nFor clan spells, the following switches are available:\n"+
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
      my_dir = TOP_DIR + "docs/help_leader/";
      files = get_dir(my_dir);
      x = member(files,str);
   }
   
   if(x == -1)
      {
      write("No such help file.\n");
      return 1;
   }
   
   file = read_file(my_dir + files[x]);
   write(file + "\n");
   return 1;
}
