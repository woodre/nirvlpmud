#include "DEF.h"
 
nset(str) {
string who,what;
int num;
object ob;

if(!str) { write("nset <who> <what> <num> \n"); return 1; }
sscanf(str,"%s %s %d",who,what,num);
if(!find_player(who)) {
  write("Not logged on...\n"); return 1; }

if(what == "money") {
  find_player(who)->add_money(num);
  write("MONEY of "+who+" altered by "+num+".\n");
  return 1; }
if(what == "exlev") {
  find_player(who)->set_extra_level(num);
  write("EXTRA LEVEL of "+who+" set to "+num+".\n");
  return 1; }
if(what == "level") {
  find_player(who)->set_level(num);
  write("LEVEL of "+who+" set to "+num+".\n");
  return 1; }
if(what == "frog") {
  find_player(who)->frog_curse(num);
  write("FROG CURSE of "+who+" set to "+num+".\n");
  return 1; }
if(what == "exp") {
  find_player(who)->add_exp(num);
  write("EXPERIENCE of "+who+" altered by "+num+".\n");
  return 1; }
if(what == "gexp") {
  find_player(who)->add_guild_exp(num);
  write("GUILD EXPERIENCE of "+who+" altered by "+num+".\n");
  return 1; }
if(what == "hps") {
  find_player(who)->add_hit_point(num);
  write("HIT POINTS of "+who+" altered by "+num+".\n");
  return 1; }
if(what == "sps") {
  find_player(who)->add_spell_point(num);
  write("SPELL POINTS of "+who+" altered by "+num+".\n");
  return 1; }
tell_object(TP,
  "You feel the sensation of stupidity... try again!\n");
return 1;
}
