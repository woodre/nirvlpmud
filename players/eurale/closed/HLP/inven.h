#include "DEF.h"
 
inven(str) {
  object who, obj, tmp;
  int x;
  string one, two, three;

if(!find_living(str)) {
  write(capitalize(str)+" is not on the MUD.\n");
  return 1; }

who = find_living(str);
obj = first_inventory(who);
tmp = 0;

  while(obj) {
    if(tmp != 0) {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp = 0; }
    write(obj);
    write(" : ");
    x = 0;
    if(obj->short()) { write(obj->short()); x=1; }
    if(obj->query_name()&& x == 0) { write(obj->query_name()); x = 1; }
    if(obj->query_id()&& x == 0) { write(obj->query_id()); x = 1; }
    if(x == 0) { write("* INVISIBLE *"); }
    write("\n");
    if(sscanf(obj,"%s/closed/%s#%s",one,two,three) == 3&& two == "goof") {
      tmp = obj; }
    obj = next_inventory(obj);
  }
  write("Done.\n");
  return 1;
}
