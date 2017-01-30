#include "/players/boltar/things/esc.h"


 int lightstate;
short()
{
     return "A seven foot pipe with a shower head";
}

query_value()
{
        return 1;
}

query_weight() {   return 30000; }
long()
{
   write("It's one of the showers from the bleachers of old comiskey\n"+
         "park in chicago. It's painted green and has a chain hanging\n"+ 
         "from it. It's standing in an upright position. Maybe you can\n"+
         "pull the chain.\n");  
}

init() {
     add_action("pull", "pull");
}

id(str) {
    return str == "shower" || str == "pipe";
}

pull(str) {
object dirt;
    if (str && str!="chain")
        return 0;
 write("You pull the chain and are showered with water.\n");
 write("You feel alot cleaner, but very wet.\n");
if (this_player()) {
say(call_other(this_player(), "query_name") +
  " Pulls the chain and takes a shower.\n");
  }
 dirt=present("stains",this_player());
 if(dirt) destruct(dirt);
 dirt=present("stains",this_player()); 
 if(dirt) destruct(dirt);
 dirt=present("stains",this_player()); 
 if(dirt) destruct(dirt);
    return 1;
}
