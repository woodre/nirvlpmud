#include "/players/forbin/define.h"

status main(string arg) {
  string where, filename;
  object what;
  string one, two;
  if(!arg) {
    where = file_name(environment(this_player()));
    if(sscanf(where, "%s#%s", one, two) == 2) filename = one;
    command("ed /"+filename+".c", this_player());
    return 1; 
  }
  if(present(arg, environment(this_player())))
    what = present(arg, environment(this_player()));
  else if(present(arg, this_player()))
    what = present(arg, this_player());
  else 
    return (notify_fail("There is no "+arg+" present.\n"), 1);
  filename = file_name(what);
  if(sscanf(filename, "%s#%s", one, two) == 2) filename = one;
  command("ed /"+filename+".c", this_player());
  return 1;     
}