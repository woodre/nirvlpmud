#include "/players/mokri/define.h"
#define DEVCHAN "/players/mokri/cybers/obj/device_chan"

object owner;
string oname;
int time_left;
int pk;
inherit "/obj/treasure.c";
string *people;

send_message(string str)
{
   DEVCHAN->check_all_here();
   DEVCHAN->device_channel(str);
   return 1;
}

reset(int arg) {
   if(arg) return;
   set_id("listening_device_thingy");
   set_long("There is no listening_device here.\n");
}

get()
{
   write("That is not here.\n");
   return 0;
}

init()
{
   add_action("deactivate_device","deactivate_device");
   if(ENV(TO) && owner && time_left)
      {
      
      if(!find_player(oname)) 
         {
         DEVCHAN->remove_device(TO);        
         destruct(TO);
      }
      if(TP->query_level() < 20)
         {
         if(!people)
            people = ({ });
         people += LOWER(TPRN);
         if(!pk || (pk && TP->query_pl_k()))
            send_message(BLU+"["+NORM+"Listening Device"+BLU+"]"+NORM+" "+CAP(TPRN)+" ENTERS "+ENV(TO)->short()+".\n");
      }
   }
}

check_here()
{
   DEVCHAN->check_all_here();
}


timer()
{
   time_left -= 1;
   check_here();
   if(time_left < 1)
      {
      
      tell_object(owner,GRN+"["+NORM+"Listening Device"+GRN+"]"+NORM+" Listening Device destructs itself from "+ENV(TO)->short()+".\n");
      DEVCHAN->remove_device(TO);
      destruct(TO);
      return 1;
   }
   call_out("timer",1);
}


deactivate_device()
{
   if(TP != owner) return 0;
   write("You deactivate the listening device.\n");
   DEVCHAN->remove_device(TO);
   destruct(TO);
   return 1;
}

set_owner(object who)
{
   owner = who;
   oname = owner->query_real_name();
}
set_time_left(int tl) { time_left = tl; }
set_pk(int p) { pk = p; }
add_people(pe) { people += pe; }
remove_people(pe) { people -= pe; }
set_oname(on) { oname = on; }

query_pk() { return pk; }
query_time_left() { return time_left; }
query_owner() { return owner; }
query_people() { return people; }
query_oname() { return oname; }
