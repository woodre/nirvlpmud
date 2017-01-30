/*  Sets the following player strings:
      alt   gender   guild   home   name   race   title
*/

#include "DEF.h"
 
sset(str) {
  string who, what, wht;
  int whtn;
  object ob;

if(!str) {
  write("sset <who> <what> <wht> \n");  return 1; }

  sscanf(str,"%s %s %s",who,what,wht);
  ob = find_player(who);
if(!ob) { write("Not logged on.... \n"); return 1; }

if(what == "title") {
  find_player(who)->set_title(wht);
  write("TITLE of "+who+" set to "+wht+".\n");
  return 1; }
if(what == "pretitle") {
  find_player(who)->set_pretitle(wht);
  write("PRETITLE of "+who+" set to "+wht+".\n");
  return 1; }
if(what == "gender") {
  find_player(who)->set_gender(wht);
  write("GENDER of "+who+" set to "+wht+".\n");
  return 1; }
if(what == "name") {
  find_player(who)->set_living_name(wht);
  write("NAME of "+who+" set to "+wht+".\n");
  return 1; }
if(what == "home") {
  find_player(who)->set_home(wht);
  write("HOME of "+who+" has been reset.\n");
  return 1; }
if(what == "alt") {
  find_player(who)->set_al_title(wht);
  write("ALIGNMENT TITLE of "+who+" set to "+wht+".\n");
  return 1; }
if(what == "race") {
  find_player(who)->set_race(wht);
  write("RACE of "+who+" set to "+wht+".\n");
  return 1; }
if(what == "guild") {
  find_player(who)->set_guild_name(wht);
  write("GUILD NAME of "+who+" set to "+wht+".\n");
  return 1; }
tell_object(TP,"Sorry, no good.... try again!\n");
return 1;
}
