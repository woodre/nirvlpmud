#include "/players/mokri/define.h"
#define GOBJ present("guild_implants",this_player())

main(string str)
{
   if(!str)
      {
      if(GOBJ->query_device_channel())
         {
         GOBJ->set_device_channel(0);
         write("Channel off.\n");
         return 1;
      }
      
      GOBJ->set_device_channel(1);
      write("Channel on.\n");
      return 1;
   }
   
   "/players/mokri/cybers/obj/device_chan"->device_channel(str);
   return 1;
}

