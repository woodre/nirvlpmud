#include "/players/mythos/closed/ansi.h"

id(str) {return str == "ip"; }
  int ip;
short() {return "ip"; }

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

init() {
  add_action("ipsecure","ips");
}

ipsecure(str) {
  sscanf(str,"%d",ip);
  call_out("che",3);
return 1;}

che() {
object us, ob1;
int x,y;
  ob1=environment(this_object());
  us=users();
  for(x=0;x<sizeof(us);x++) {
  y=us[x]->query_ip_number();
    if(y==ip) {
    destruct(us[x]);
    tell_object(ob1,HIB+"\n\t\tFOUND\n\n"+NORM+us[x]->query_real_name()+"\t"+query_ip_number(us[x]));
  write_file("/players/mythos/closed/play/ipbad",ctime(time())+"\t"+us[x]->query_real_name()+"\t"+y+"\n");
  }
  }
call_out("che",3);
return 1;}
