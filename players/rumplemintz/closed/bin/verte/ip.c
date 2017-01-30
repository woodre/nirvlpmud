/* people cmd, style ripped off from 'p' with love by verte */

#include "/players/vertebraker/define.h"

#include "/obj/security.h"

main()
{
   int index; object *all_users; 
   string name, idle, address, hostname;
   int i_secs, i_mins, i_hrs;
   write(HIW+"\t\t\t\tpeople\n\n"+NORM);
   write("   Name         Idle  Address          Hostname\n"+
      "........................................................................\n");
   all_users = users();
   for(index = 0; index < sizeof(all_users); index ++)
   {
      name = CAP(all_users[index]->RN);
      i_secs = query_idle(all_users[index]);
      i_hrs = (i_secs / 3600);
      i_mins = (i_secs / 60);
      if(i_hrs) idle = i_hrs+"h";
      else if(i_mins) idle = i_mins+"m";
      else if(i_secs) idle = i_secs+"s";
      if(!i_secs) idle = "   ";
      address = query_ip_number(all_users[index]);
      hostname = all_users[index]->query_hostname();
      if(all_users[index]->query_level() >= CREATE) name = HIW+pad(name,12)+NORM;
      else name = pad(name,12);
      idle = pad(idle,3);
      address = pad(address,15);
      write(pad(""+(index+1)+"]",4) + name +" "+ idle +"  "+ address
         + "  "+hostname+"\n");
   }
   write("........................................................................\n");
   return 1;
}
