string called_from_ip,name,guild_name;
int level,guild_exp,ex_lv,experience,guild_rank;
long() { write("searcher\n"); }
short() { return "searcher"; }
id( str ) {
        if(str=="qgm") return 1;
        return 0;
}
init(){
    add_action("set_search","search");
    add_action("address","address");
}
address()
{ write("Addr: "+called_from_ip+"\n");
  return 1;
}
set_search(str) {
  if(!str) return;
  if(!restore_object("players/"+str)) {
    name="<noone>";
    return 1;
  }
  return 1;
}
get() { return 1; }
drop() { return 0; }
