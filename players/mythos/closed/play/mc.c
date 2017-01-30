#include "/players/mythos/closed/ansi.h"
string email;
string name;
int level, ex_lv;

id(str) { return str == "mc" || str == "mailcheck"; }

short() { return "mailcheck"; }

long() { write("An mailcheck object.\n"+
        "Usage: mc [letter]\n"+
                   "            'all' for all\n");
        }

drop() { return 1;}
get() { return 0; }

init() {
if(this_player()->query_level() < 21) destruct(this_object());
  add_action("mc","mc");
}

mc(str) {
string type,what;  
string files;
string host, ip;
string let;
string nnamed,named,nam;
string nm;
int om;
int k,j,l,i;
om = 0;
  if(!str) { write("Usage: ipg [type] [string] [letter]\n"+
                   "types being 'n' for name\n"+
                   "            'i' for ip #\n"+
                   "            'h' for hostname\n"+
                   " if letter is blank the default will be\n"+
                   " the players dir \n");  return 1; }
  if(sscanf(str,"%s %s",type,what) != 2) return 0;
  let = 0;
  if(sscanf(str,"%s %s %s",type,what,let) != 3) {
     let = 0;
     sscanf(str,"%s %s",type,what);
  }
  if(type != "n" && type != "name" && type != "i" && type != "ip" &&
     type != "h" && type != "hostname") return 0;
  nnamed = host = ip = "nulled";
  nam = "nulled";
  if(type == "n" || type == "name") {
  if(!restore_object("players/"+what)) { 
    nm = explode(what,"");
    if(!restore_object("pfiles/"+nm[0]+"/"+what)){
    tell_object(this_player(),"That player does not exist.\n");
    return 1; }
  }
  nnamed = what;
  host = hostname;
  ip = called_from_ip;
  write(
  "\n<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
  write(
  "Person: "+RED+nnamed+NORM+"\tHost: "+RED+host+NORM+"\tIP: "+RED+ip+NORM);
  write("\n");
  }
  if(type == "i" || type == "ip") {
    ip = what;
    hostname = "nulled";
    write(
  "\n<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
 write("IP: "+RED+ip+NORM);
  write("\n");
  }
  if(type == "h" || type == "hostname") {
    host = what;
    ip = "nulled";
   write(
  "\n<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
  write("HOSTNAME: "+RED+host+NORM);
  write("\n");
  }
  if(!let) files = get_dir("/players/");
  else files = get_dir("/pfiles/"+let+"/");
  write(
  "............................"+let+"............................\n");
  for(k=0;k<sizeof(files);k++) {
   named = explode(files[k],".");
    if(!let) restore_object("players/"+named[0]);
    else restore_object("pfiles/"+let+"/"+named[0]);
      if(host == hostname || ip == called_from_ip && !om) {
        tell_object(this_player(),capitalize(name)); 
        if(strlen(name) < 8) tell_object(this_player(),"\t");
        tell_object(this_player(),"\tLEVEL: "+level+"+"+ex_lv); 
        if(level > 19) write(BLU+"       WIZ"+NORM);
        tell_object(this_player(),"\n");
         if(type == "n" || type == "name" && named[0] == what) om = 1;
      }
  }
  tell_object(this_player(),"\n");
  write(
  "<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
return 1; }
