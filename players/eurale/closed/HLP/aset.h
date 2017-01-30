#include "DEF.h"

aset(str) {
string who, what;
object ob;

if(!str) { write("aset <who> <what> \n"); return 1; }
sscanf(str,"%s %s",who,what);
if(!find_player(who)) { write("Not logged in...\n"); return 1; }

if(what == "scrime") {
  find_player(who)->set_crime();
  write("CRIME of "+who+" is "+HIR+"SET"+NORM+".\n");
  return 1; }
if(what == "ccrime") {
  find_player(who)->clear_crime();
  write("CRIME of "+who+" is "+HIC+"CLEARED"+NORM+".\n");
  return 1; }
if(what == "preg") {
  find_player(who)->set_pregnancy(TPRN);
  write(capitalize(who)+" is now PREGNANT.\n");
  return 1; }
if(what == "cpreg") {
  find_player(who)->clear_pregnancy();
  write(capitalize(who)+" is NO LONGER PREGNANT.\n");
  return 1; }
if(what == "birth") {
  find_player(who)->child_birth();
  write("You forced "+who+" to give BIRTH.\n");
  return 1; }
tell_object(TP,"No matches found.... try again!\n");
return 1;
}
