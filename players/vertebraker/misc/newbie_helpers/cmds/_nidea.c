#include <ansi.h>
int main(string str)
{
   
   if(!str) return 0;
   
  write_file("/players/vertebraker/misc/newbie_helpers/ideas/" + "ideas",
      HIB + ">> " + NORM + ctime()[4..15] + " " + BOLD + pad(capitalize((string)this_player()->query_real_name()), 12) + NORM + " " + str + "\n"+NORM);
   
   write(HIY+"Thank you"+NORM+".\nWe have received your idea.\n"); 
   return 1;
}
