#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

string hostname, called_from_ip;
string name;
int level, ex_lv;

id(str) { return str == "ip_grep" || str == "ipgrep"; }

short() { return "ip_grep"; }

long() { write("An ip grep object.\n"+
               " Usage: ipg [type] [string]\n"+
                   "types being 'n' for name\n"+
                   "            'i' for ip #\n"+
                   "            'h' for hostname\n");
        }

drop() { return 1;}
get() { return 0; }

init() {
if(this_player()->query_level() < 21) destruct(this_object());
  add_action("ipg","ipg");
}

ipg(str) {
string type,what;  
string files;
string host, ip;
string nnamed,named,nam;
int k,j,l,i;
  if(!str) { write("Usage: ipg [type] [string]\n"+
                   "types being 'n' for name\n"+
                   "            'i' for ip #\n"+
                   "            'h' for hostname\n");  return 1; }
  if(sscanf(str,"%s %s",type,what) != 2) return 0;
  if(type != "n" && type != "name" && type != "i" && type != "ip" &&
     type != "h" && type != "hostname") return 0;
  nnamed = host = ip = "nulled";
  nam = "nulled";
  if(type == "n" || type == "name") {
  if(!restore_object("players/"+what)) {
    write("That player does not exist.\n");
  return 1; }
  nnamed = what;
  host = hostname;
  ip = called_from_ip;
  write("\n<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
  write("Person: "+RED+nnamed+NORM+"\tHost: "+RED+host+NORM+"\tIP: "+RED+ip+NORM);
  write("\n");
  }
  if(type == "i" || type == "ip") {
    ip = what;
    hostname = "nulled";
    write("\n<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
  write("IP: "+RED+ip+NORM);
  write("\n");
  }
  if(type == "h" || type == "hostname") {
    host = what;
    ip = "nulled";
    write("\n<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
  write("HOSTNAME: "+RED+host+NORM);
  write("\n");
  }
  files = get_dir("/players/");
  write("...........................................................\n");
  for(k=0;k<sizeof(files);k++) {
   named = explode(files[k],".");
    restore_object("players/"+named[0]);
      if(host == hostname || ip == called_from_ip) {
        write(capitalize(name)); 
        if(strlen(name) < 8) write("\t");
        write("\tLEVEL: "+level+"+"+ex_lv); 
        if(level > 19) write(BLU+"       WIZ"+NORM);
        write("\n");
      }
  }
  write("\n");
  write("<<<<<<<---------------"+BLU+"DATABANK FILES"+NORM+"--------------->>>>>>>\n");
return 1; }
