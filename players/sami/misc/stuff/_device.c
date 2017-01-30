#include "/players/mokri/define.h"
#define DEVCHAN "/players/mokri/cybers/obj/device_chan"

main(string str)
{
   object device;
   
   if(present("listening_device_thingy",ENV(TP)))
      {
      write("There is already a listening device planted here.\n");
      return 1;
   }
   
   if(str && str != "pk")
      {
      write("You may only 'device' or 'device pk'.\n");
      return 1;
   }
   
   device = clone_object("/players/mokri/cybers/obj/listening_device");
   device->set_owner(TP);
   device->set_time_left(100);
   DEVCHAN->add_device(device);
   if(str)
      device->set_pk(1);
   device->timer();
   
   move_object(device,ENV(TP));
   
   write("Device planted.\n");
   
   return 1;
}
