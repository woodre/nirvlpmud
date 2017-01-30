id(str) { return str == "ipga"; }

init() { if(this_player()->query_level() < 20) destruct(this_object());
        add_action("ipga","ipga"); }

drop() { return 1; }

ipga(str) {
string type,what;
string moo;
string nm;
int h;
  if(!str) { write("Usage: ipga [type] [string]\n"+
                   "types being 'n' for name\n"+
                   "            'i' for ip #\n"+
                   "            'h' for hostname\n");  return 1; }
  if(sscanf(str,"%s %s",type,what) != 2) return 0;
  moo = ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
          "p","q","r","s","t","u","v","w","x","y","z"}); 
  if(type == "n" || type == "name") {
  if(!restore_object("players/"+what)) { 
    nm = explode(what,"");
    if(!restore_object("pfiles/"+nm[0]+"/"+what)){
    write("That player does not exist.\n");
    return 1; }
  } } 
  call_other("/players/mythos/closed/play/ip_grep.c","ipg",type+" "+what);
  for(h=0;h<sizeof(moo);h++) {
call_other("/players/mythos/closed/play/ip_grep.c","ipg",type+" "+what+" "+moo[h]);
  }
 write("ipga done\n");
return 1; }