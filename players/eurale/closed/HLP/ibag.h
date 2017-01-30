#include "DEF.h"
 
ibag(str) {
  object who, obj, tmp;
  object obinv;
  int x, i;
  string one, two, three;

if(!str) { write("Usage: ibag <nama>\n"); return 1; }

if(!find_player(str)) {
  write(capitalize(str)+" is not on the MUD.\n");
  return 1; }

if(!present("bag",find_player(str))) {
  write(capitalize(str)+" has NO bag!\n");
  return 1; }

obj = present("bag",find_player(str));
obinv = all_inventory(obj);
tmp = 0;

if(sizeof(obinv) == 0) write("NO items in bag.\n");

for(i=0;i<sizeof(obinv);i++) {
  write(obinv[i]);
  write(" : ");
  x = 0;
  if(obinv[i]->short()) { write(obinv[i]->short()); x = 1; }
    if(obinv[i]->query_name()&& x == 0) { write(obinv[i]->query_name()); x = 1; }
    if(obinv[i]->query_id()&& x == 0) { write(obinv[i]->query_id()); x = 1; }
    if(x == 0) { write("* INVISIBLE *"); }
    write("\n");
    if(sscanf(obinv[i],"%s/closed/%s#%s",one,two,three) == 3&& two == "goof") {
      tmp = obinv; }

}
  write("Done.\n");
  return 1;
}
