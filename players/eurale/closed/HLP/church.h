#include "DEF.h"
 
church_player(str) {
object ob;
string there;
 
if(!str) { TP->move_player("church#room/church"); return 1; }
ob = find_player(str);
if(!ob) ob = find_living(str);

if(!ob) {
  write (capitalize(str) + " is not online at this time.\n");
  return 1; }

there = environment(ob);
tell_object(ob,"You are escorted to the church.\n");
move_object(ob, "room/church");
tell_room(there, capitalize(str) + " is escorted to the church.\n");
write (capitalize(str) + " is escorted to the church.\n");
return 1;
}
