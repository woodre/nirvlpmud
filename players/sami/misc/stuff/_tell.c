#include "/players/mokri/define.h"
#include "/players/data/ansi2.h"
#include "/players/data/defs.h"


main(string str)
{
   string name, mess;
   object who;

   if(!str)
      {
      write("Tell who what?\n");
      return;
   }

   if(sscanf(str,"%s %s",name,str) != 2)
      {
      write("Tell who what?\n");
      return;
   }

   who = find_player(name);
   if(!who)
      {
      write("I don't see that person anywhere...\n");
      return 1;
  }

   if(this_player()->query_gender() == "male")
 mess = "\n<-"+this_player()->query_name()+" tells you: "+str+"\n";
   write(""+this_player()->query_name()+" tell you: "+str+" \n");

   if(this_player()->query_gender() != "male")
      mess = "\n<-"+this_player()->query_name()+" tells you: "+str+"\n";
   write(""+this_player()->query_name()+" tells you: "+str+"\n"; \n");


   tell_object(who,mess);
   write("You tell " + CAP(name) + ": " + str + "\n");
   who->add_tellhistory(mess);
   who->Replyer(this_player()->query_real_name());
   return 1;
}
