#include <security.h>

int cmd_reset(string str)
{
 object ob;
 if((int)this_player()->query_level() < CREATE)
  return 0;
 if(!str)
 {
  write("Usage: 'reset <file>'\n");
  return 1;
 }
 if(str == "/obj/master" || str == "/obj/master.c" || str == "master" ||
    str == "master.c")
 {
  write("ILLEGAL.\n");
  return 1;
 }
 str = (string)this_player()->valid_read(str);
 if (!str)
 {
  write("Invalid file name.\n");
  return 1;
 }
 ob = find_object(str);
 if (!ob) {
  write("No such object.\n");
  return 1;
 }
 ob->reset();
 write("Object updated.\n");
 return 1;
}
