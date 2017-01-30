#define DAEMON "/players/maledicta/templar/gdaemon.c"

#include "/players/maledicta/ansi.h"
inherit "players/vertebraker/closed/std/monster.c";

object gold;
object hate;

reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("gate");
set_alt_name("big_ol_gate");
set_race("none");
set_level(1);
set_hp(12500);
set_ac(30);
set_wc(0);
set_dead_ob(this_object());
no_exp_value = 1; /* Har */
}

init(){
  add_action("nogo", "enter");
  }

nogo(){
  if(DAEMON->gate2() == 2){ write("The gates are closed and locked!\n"); return 1; }
  }

short(){ 
if(DAEMON->gate2() == 2)
return HIB+"THE CASTLE GATE "+HIW+"("+HIB+"CLOSED"+HIW+")"+NORM;
else
return HIB+"THE CASTLE GATE "+HIW+"("+HIB+"OPEN"+HIW+")"+NORM;
}

long(){
 write("This is the main castle gate of Fortress Stone. It can be\n"+
       "killed if you want in badly enough.  Although, it looks as\n"+
       "though it can take a LOT of damage.\n");
 return 1;
 }

heart_beat(){ 
 if(hit_point < max_hp && !random(3)) hit_point += 1; 
 }

query_templar_guard(){ return 1; }

monster_died() {
object corpse;
if(query_attack()){
   write_file("/players/maledicta/templar/logs/GATE2",
   query_attack()->query_name()+" "+ctime(time())+".\n");
   }
tell_room(environment(),
HIR+"\n\nThe Castle Gates fall under the onslaught!!!\n\n"+NORM);
DAEMON->set_gate2_condition(0);
if(corpse = present("corpse", environment())){
 destruct(corpse);
 }
send();
return 1;
}

send() {
   object list;
   object cross;
   int i;
   list = users();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
          HIR+"(Templar War) A Castle Gates have fallen!"+NORM+"\n");
       }
   }
}
