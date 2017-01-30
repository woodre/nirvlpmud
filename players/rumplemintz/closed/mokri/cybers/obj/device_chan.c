#include "/players/mokri/define.h"
object *devices;

device_channel(string str)
{
   int x;
   object *us;
   
   us = users();
   
   for(x = 0; x < sizeof(us); x++)
   {
      if(present("guild_implants",us[x]) && present("guild_implants",us[x])->query_device_channel())
         tell_object(us[x],str+"\n");
   }
   
   return 1;
}


check_all_here()
{
   int x, a;
   object plyr;
   object *devcopy;
   string *people_copy;
   
   devcopy = devices;
   for(a = 0; a < sizeof(devcopy); a++)
   {
      
      if(!devcopy[a])
         {
         destruct(devices[a]);
         return;
       }
      if(!find_player(devcopy[a]->query_oname())) {
         destruct(devcopy[a]);
         return;
       }
      people_copy = devcopy[a]->query_people();
      
      for(x = 0; x < sizeof(people_copy); x++)
      {
         plyr = find_player(people_copy[x]);
         if(!plyr || !present(plyr,ENV(devices[a])))
            {
            if(!devcopy[a]->query_pk() || (devcopy[a]->query_pk() && plyr->query_pl_k()))
               device_channel(MAG+"["+NORM+"Listening Device"+MAG+"]"+NORM+" "+CAP(people_copy[x])+" LEFT "+ENV(TO)->short()+".\n");
            devcopy[a]->remove_people(people_copy[x]);
            return 1;
          }
       }
   }
}

add_device(dev) { 
   if(!devices) devices = ({ });
   devices += dev; }
remove_device(dev) { devices -= dev; }

query_devices() { return devices; }
