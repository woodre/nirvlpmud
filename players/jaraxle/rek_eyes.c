/*
  This item was coded for Rek by Eurale (10.1.02) for turning in nearly 20
  bugs that affected game play.  This item does the following things:

   *allows the user to locate invisible players throughout the mud.  It
    follows the game rules for disclosing locations. (i.e. if the room
    is dark, it shows the location as 'dark room.')

   *it costs 10 sps to use each time a player is found and 5 sps each
    time that no player is found.

   *it is timed so that it may not be used more than once per minute.

  There are already a number of items similar to this throughout the mud.
  I found coding a personal one for Rek to reward him for his contributions
  a reasonable request and well within the balance we are looking for.
*/

inherit "obj/treasure";
#include "/players/eurale/defs2.h"
int time,see;
object who;
string where;

reset(arg) {
  if(arg) return;
see = 1;

set_id("shardak eyes");
set_alias("eyes");
set_short(RED+"Shardak Eyes"+NORM);
set_long(
  "All-seeing Shardak eyes.  To use: 'spy <name>'\n");

set_weight(0);
set_value(1);
}

query_auto_load(){ return "/players/jaraxle/rek_eyes.c:"; }

int drop(){ return 1; }

init() {
  ::init();
/*
  add_action("Spy","spy");
*/
}

Spy(str) {
if(see == 0) {
  write(HIR+"It is too soon for your Shardak eyes to focus again...\n\n"+NORM);
  return 1; }
if(TPSP < 25) { write("You don't have enough magic to do that.\n"); return 1; }
if(!str) { write("Who are you looking for?\n"); return 1; }
  who = find_player(str);
if(!who || who->query_invis() > 19) {
  write("That player doesn't seem to be logged on.\n");
  TP->add_spell_point(-5);
  see = 0;
  time = 0;
  call_out("timer",1);
  return 1; }

  where = call_other(environment(find_player(str)),"short");
if(who->query_level() > 19) {
  write("No wizards.\n");
  return 1; }

write("\n\n"+HIR+"You spy across the mud and discover...\n\n"+NORM);
write(HIR+"     Player:       "+NORM+capitalize(str)+"\n");
write(HIR+"     Location:     "+NORM+where+"\n\n");
TP->add_spell_point(-9-random(3));
see = 0;
time = 0;
call_out("timer",1);
return 1; }

timer() {
if(ETO) {
time++;
  if(time == 30) {
    if(ETO->query_real_name() == "eurale")
      tell_object(ETO,HIR+"Wait time has expired...\n"+NORM);
    see = 1;
  return 1; }
call_out("timer",1); }
return 1; }
