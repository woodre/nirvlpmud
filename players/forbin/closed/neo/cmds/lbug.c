#define REP "/players/forbin/closed/neo/obj/reporter"

int main(string str, object gob, object player) {

  string typ;
  
  typ = "bug";
  
  if(str && find_player(str)) {
    return 0;
  }
  
  if(strlen(str) < 2) {
    write("You forgot to enter your \""+typ+"\", doofus!\n");
    return 1;
  }
  
  write("Okay, recording "+typ+".\n");
  
  call_other(REP, "add_"+typ, (string)this_player()->query_real_name(), (string)this_player()->query_real_name(), str);

  return 1;
}
