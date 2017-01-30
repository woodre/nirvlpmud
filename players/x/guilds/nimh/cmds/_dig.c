#include "../x.h"

int cmd_dig(string str)
{ 
 if(str == "hole")
 {
  object hole;
  if(ENVTP->query_nimh_hole())
  {
   write("\
You are already within the earthen tunnels of the\n\
Rats of NIMH.  You cannot dig down any further.\n");
   return 1;
  }
  if((hole=present(HOLE_ID,ENVTP)) && hole->short())
  {
   notify_fail("\
A hole already exists here.\n");
   return 0;
  }
  write("\n\tYou dig furiously...\n\n");
  say((string)TP->QN+" digs furiously at the ground with "+
   possessive(TP)+" paws.\n");
  if(!random(4))
   TR(ENVTP, YEL+"Dirt is thrown all around you!\n"+NORM);
  write("\
As you finish the hole, you hop down into the crevice.\n"+
"A "+HIB+"blue light"+NORM+" shimmers briefly above.\n");
 write("\n\n");
  say((string)TP->QN+" stops digging.\n"+
      (string)TP->QN+" hops down into the hole.\n"+
  "A "+HIB+"blue light"+NORM+" shimmers faintly around the hole.\n");
  MASTER->add_hole(ENVTP);
 if(!hole) {
  hole = CO(N_OBJ+"hole");
  hole->set_location(file_name(ENVTP));
  hole->set_creator((string)TP->RN);
  MO(hole, ENVTP);
}
  MO(TP, hole);
  hole->set_dug(1);
  command("look", TP);
  return 1;
 }
 notify_fail("Usage: 'dig hole'\n");
 return 0;
}
