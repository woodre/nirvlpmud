#include <security.h>

int rip(){
  object *usr;
  int i;

  usr=users();

  if (!member(this_player()->query_real_name(), ADMINS) != 1) {
    write("You are not an admin.\n");
    return 1;
  } else
    write("Found your name on the Admin list!\n");
  for (i = 0; i < sizeof(usr); i++) {
    if(file_size("/players/rumplemintz/closed/ipnums-" +
                 usr[i]->query_real_name())
    write_file("/players/rumplemintz/closed/ipnums-" +
               usr[i]->query_real_name()+".o",
               query_ip_number(usr[i]));
    write("The following information was logged: \n"+
          query_ip_number(usr[i])+"\n");
  }
  return 1;
}
