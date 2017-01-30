#include <ansi.h>

/******************************************************************************
 * Program: courage_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object (shadow)
 * Created: September 2014 by Karash
 *
 * Purpose: The shadow object cast upon target NPC when the courage spell is cast on them.
 * 
 * History:
 *          
 ******************************************************************************/


#define TO this_object() 
#define ENV environment


object brave;
int time;

do_shadow(object ob) {
  if(!ob) return;
  brave = ob;
  shadow(brave, 1);
  return 1; }

set_time(num) {
  time = 10*num;
  call_out("stop_shad",time); }

stop_shad(){
  done();
  if(brave)
  shadow(brave,0);
  destruct(TO);
}

  
short() {
 return brave->short()+","+BLU+" **"+NORM+HIB+"BRAVE"+NORM+BLU+"**"+NORM;
}

brave() { return 1; }

done() {
  if(brave && ENV(brave)) {
  tell_room(ENV(brave),
    CYAN+brave->query_name()+" regains insight as the spell dissipates."+NORM+"\n");
  return 1; }
  return; }

move_player(){
  tell_room(ENV(brave),
  brave->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(brave),
  brave->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(brave),
  brave->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(brave),
  brave->query_name()+" tries to move but is compelled to stay...\n");}

  