#include "/players/maledicta/ansi.h"
/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";

status ghetto_fix;
int motherfuck;
int nogo;
int no_go;
#define USER environment()
#define ATT USER->query_attack()
#define WEP USER->query_weapon()

reset(arg) {
if(arg) return;
::reset(arg);
no_go = 0;
set_name("bracers");
set_alias("bracers of speed");
set_short("Bracers of Speed");
set_long(
  "  These items appear to be arm guards of heavy material,\n"+
  "however, on further examination they are very lightweight\n"+
  "and yet sturdy.  Symbols of wind and fire are carved upon\n"+  
  "their golden surface, with small flecks of diamond dust\n"+
  "accenting the raised forms.\n");
set_type("bracelet");
set_weight(1);
set_value(20000);
  set_bf_guild_bonus(0, 10);
  set_heart_beat(1); /* uhh these are illegal as fuck */
}

init() {
  ::init();
  add_action("do_atk", "a_completely_ghetto_fix");
}

do_special(owner){
 if(!worn) return 0;
if(!ATT) return;

 if(ATT->query_hp() > 20 && random(100) < 7){
  if(random(500) == 222){ 
  no_go = 1; 
  tell_object(USER, HIY+"Something has happened...\n"+NORM); 
  }
  if(nogo < time()){
 tell_room(environment(USER),
 HIB+USER->query_name()+"'s form "+HIW+"|| |  | "+NORM+BOLD+"blurs"+HIW+""+
 " |  | ||"+HIB+" as "+USER->query_possessive()+" bracers "+HIY+"glow"+HIW+"..."
+NORM+"\n");
 ghetto_fix = 1;
 command("a_completely_ghetto_fix", USER);
  nogo = time();
 ghetto_fix = 0;
   }
 }
return 0;
}

/* Use locker arg to make savable. -Bp dec-2002 
query_save_flag(){ if(no_go) return 1; else return 0; }
*/

locker_arg() {
  string blah;
  blah="-"+no_go+"-";
  return blah;
 }
locker_init(arg) { 
  int blah;
  sscanf(arg,"-%d-",blah);
  no_go = blah;
  }

heh() {
object wepp;
  this_player()->toggle_already_fight(1);
  if(wepp = environment()->query_weapon()) wepp->hit(environment()->query_attack());
  environment()->attack(); }

do_atk()
{
  if(ghetto_fix < 1) return 0;
  heh();
  return 1;
}

heart_beat() {
  motherfuck=0;
}
