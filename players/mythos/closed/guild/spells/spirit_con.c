#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
object ob, con;
int check;
reset(arg) {
  if(arg) return;
    set_id("spirit_control");
    set_alias("control");
    set_short("Spirit_Control");
    set_long("Just command the avatar to do what you wish!  \n"+
             "<only one word commands>\n"+
             "type  com <command>  and avatar_off to turn it off\n"+
             "To attack with the avatar type KILL <name>\n");
    set_weight(0);
    set_value(0);
}
 init() {
   ::init();
   add_action("go","com");
   add_action("know_off","avatar_off");
   add_action("KILL","KILL");
   }
   
drop() { return 1;}
get() { return 0;}

set_con(ob) { con = ob; }
set_pcheck(n) { check = n;}
go(str) {
  if(!str) { write("Usage: com <command>\n"); return 1;}
  if(str == "look") { con->look(); return 1;}
  command(con,str);
return 1;}

know_off() { con->off(); return 1;}

KILL(str) {
object targ;
  if(!str) return 0;
  targ = present(str,environment(con));
  if(!targ) { write("Not there to attack,\n"); return 1;}
  if(!living(targ)) { write("Not something to attack.\n"); return 1;}
  if(!(targ->query_npc()) && !check) { 
  write("Can not attack players at this time!\n");
  return 1;}
  con->attack_object(targ);
  write("Avatar is attacking "+str+"\n");
return 1;}
