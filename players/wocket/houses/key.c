#include "/players/wocket/closed/ansi.h"
#define TPRN this_player()->query_real_name()

string housename;
id(str){ return (str == "housekey" || str == "key");} 
short(){ return "Key to the house of "+housename; }
long(){ write("not done yet"); }

init(){
}


set_housename(str){ housename = str; }
query_housename(){ return housename; }

save_key(){
  save_object("players/wocket/houses/members/"+TPRN);
  return 1;
}

refresh_key(){
  restore_object("players/wocket/houses/members/"+TPRN);
  return 1;
}
