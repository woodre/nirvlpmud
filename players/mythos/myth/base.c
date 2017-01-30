/*
#include "/players/mythos/myth/def.h"
*/
#define MAXH    20
int level,cxp;
string whatob;
static string cmd, scd;
static int pop,pause;


id(str) { return str == "myth" || str == "MYTHOSSYSOBJ"; }
                 
drop() { return 1; }
get() { return 0; }
query_weight() { return 0;}

reset(arg) {
  if(arg) return;
  level = 1;
  cxp = 0;
  cmd = scd = 0;
  pop = pause = 0;
  call_out("autosave",100);
}

init_arg() {
  if(RO) { cat("/players/mythos/myth/NEWS"); write("\n"); }
  else destruct(this_object());
}

query_prevent_shadow() { return 1; }

init() {
  if(tp == ep) {
    if(!RO) { 
      if(level > MAX) level = MAX;
      if(tpn == "mythos") level = MAX; 
      SO; 
    } else { destruct(this_object()); return 1;} 
    
    /* replacement or overlay of normal actions in game */
    
    add_action("gquit","quit");
    
    /* base guild actions */
    
    add_action("gsave","myth_save");
    add_action("update_me","update_myth");
    add_action("help","myth_help");
    add_action("gline","mhw");
    add_action("guild_leave","leave_myth");
    add_action("second_do","act");
    add_action("pause_act","p_act");
    add_action("stop_act","s_act");
  }
}

help() {
  cat("/players/mythos/myth/HELP");
  write("\n");
}

autosave() {
if(ep) {
  if(epl > 19) return 1;
  SOE;
  tell_object(ep,"Myth stats autosaved....\n"); }
  call_out("autosave",1000);
return 1; }

gquit() {
   gsave();
   if(epl > 20) ep->do_quit(); 
   else { command("save",ep); ep->quit(); }
return 1;}

gsave() {
  SOE;
  tell_object(ep,"Myth stats saved....\n");
return 1;} 

update_me() {
object new;
  SOE;
  tell_object(ep,"Myth Object Updated....\n");
  new = clone_object(BASE);
  obswitch(new,this_object());
  move_object(new,ep);
  destruct(this_object());
return 1;}

obswitch(object one,object two) {
return 1; }

guild_leave() {
  rm("/"+MEM+epn+".o");
  ep->add_exp(-(ep->query_exp()/8));
  command("save",ep);
  tell_object(ep,"You have left your role.\n");
  move_object(ep,"/room/church.c");
  command("look",ep);
  destruct(this_object());
return 1; }

query_level() { return level; }
set_level(int d,int z) { if(d > MAX) level = MAX; else level = d; 
                   if(!z) check_xp(1); gsave();}
add_level(int d) { set_level(level + d); }
                
query_cxp() { return cxp; }
set_cxp(int n,int z) { cxp = n; if(!z) scheck_xp(2); gsave(); }
add_cxp(int n) { set_cxp(cxp + n); }                  

second_do(str) {
  if(!str) { 
  if(pause) write("act <cmd1,cmd2,cmd3, etc>\n");
  else write("Act sequence resumed.\n");
  return 1; }
  if(pop) { write("You are currently acting a sequence.\n");
            return 1; }
   cmd = str;
   set_heart_beat(1);
return 1; }

stop_act() { 
  if(!pop) { write("There is no act sequence to stop.\n");
             return 1; }
  pop = 0;
  cmd = scd = 0;
  write("Act sequence terminated.\n");
return 1; }

pause_act(str) {
if(!pop) { write("There is no act sequence to pause.\n");
             return 1; }
  if(str) sscanf(str,"%d",pause);
  else pause = 5;
  if(pause < 1) pause = 1;
  write("Act sequence paused for "+pause+" hb.\n");
return 1; }

heart_beat() {
string scd2;
  if(!pause) {
    if(cmd) {
      if(sscanf(cmd,"%s,%s",scd,scd2) == 2) {
        tell_object(ep,"Acting: "+scd+"\n");
        command(scd,ep);
        cmd = scd2; }
       else { tell_object(ep,"Acting: "+cmd+"\n"); 
              command(cmd,ep); cmd = 0; scd = 0;}
    } else {
      tell_object(ep,"Act sequence completed.\n");
      pop = 0;
      cmd = 0;
      set_heart_beat(0);
    }
  } else {
  pause = pause - 1;
  if(pause == 0) tell_object(ep,"Act sequence resumed.\n");
  }
}

query_doing() { if(scd) return scd; if(cmd) return cmd; else return 0; }

success(int n,int m) { if(!n) n = 1; if(!m) m = 1; 
                       return (level*n/m > random(100)); }

/* POWER material */

check_xp(int k) { POWER->check_xp(cxp,this_object(),k); return 1; }
gline() { POWER->gline(); return 1; }