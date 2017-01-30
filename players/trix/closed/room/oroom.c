inherit "room/room";
#include "/players/boltar/things/esc.h"
string host,guest;
int a;

reset(arg) {
    if(arg) return;
    set_light(1);
    dest_dir = ({ "/players/trix/closed/room/bedroom.c","leave"});
}
long() {
        write( "This is a comfortable and wide fluffy bed, it makes you think of candid soft\n"+
               "clouds. Many pillows lay here and there around you.\n"+
               "    There is one obvious exit: leave.\n");
       }
short()
  { if(environment(this_player())==this_object()||present("u2numb",environment(this_player())))
     return "A large and fluffy bed";
    else
    {
     if (a) {a=0;return "The shop";} 
     else {a=1;return "The town council [south]";}
    }
  }
init()
{
::init();
if(this_player()->query_real_name()!="trix"&&this_player()->query_real_name()!=host&&this_player()->query_real_name()!=guest)
   {
     log_file("trix.ie",call_other(this_player(),"query_real_name")+"\ttried bed  at "+ctime(time())+"\n");
         tell_room("/room/church",
         capitalize(this_player()->query_real_name())+" arrives, being kicked "+
         "in the ass.\n");
         move_object(this_player(),"/room/church");
     write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m You are not permitted to enter!"+esc+"[0m"+"\n");
         return 1;
       }
     add_action("setguest","setguest");
     add_action("sethost","sethost");
}
sethost(str)
{ host=str;
  write("Host: "+host+".\n");
  return host;
}
setguest(str)
{ guest=str;
  write("Guest: "+guest+".\n");
  return guest;
}
queryppl()
{   return host+","+guest;
}

