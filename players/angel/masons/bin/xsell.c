#include "defs.h"

status main(string str, int glevel) {

  notify_fail("Sorry, this command disabled for legality reasons.\n-Earwax\n");
  return 0;
/*
     if(guild_rank < 3) {
       write("You must have a guild ranking of 3 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", item) != 1) {
       write("Useage:  xsell <item>\n");
       return 1;
     }
     itemob = present(item, this_player());
     if(!itemob) {
       write("You do not have a "+item+".\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 10) {
       write("You are too low on power.\n");
       return 1;
     }
     call_other(this_player(),"add_spell_point", -10);
     val = call_other(itemob, "query_value");
     if(val == 0) {
       write("The dragon flies in and looks at the "+item+".\n");
       write("The dragon says:  That "+item+" has no value.\n");
       say("A small dragon flies in and looks at a "+item+" in "+
           capitalize(this_player()->query_name())+"'s inventory.\n");
       say("The dragon speaks to "+capitalize(this_player()->query_name())+
           " in a foreign tongue.\n");
       return 1;
     }
     if(val > 1500) {
       val = 1500;
     }
     say("A small dragon appears and snatches a "+item+" from "+
         capitalize(this_player()->query_name())+"'s inventory.\n");
     say("Then disappears only to come back and give "+
         capitalize(this_player()->query_name())+" some money.\n");
     say("The dragon flies away.\n");
     write("A small dragon appears and takes the "+item+" to the shop.\n");
     write("The dragon returns and gives you "+val+" gold coins.\n");
     write("The small dragon flies away.\n");
     call_other(this_player(),"add_money", val);
     destruct(itemob);
     return 1;
*/
}
