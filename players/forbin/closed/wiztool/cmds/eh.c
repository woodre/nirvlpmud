/*  allows easy edit of room you are standing in  */

#include "/players/forbin/define.h"

main() {
  string where;
  string one,two;
  where = file_name(environment(this_player()));
  if(sscanf(where,"%s#%s",one,two) == 2) where = one;
  command("ed /"+where+".c",this_player());
  return 1; 
}