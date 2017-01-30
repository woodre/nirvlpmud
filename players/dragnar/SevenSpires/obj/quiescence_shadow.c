#include <ansi.h>

/******************************************************************************
 * Program: quiescence_shadow.c
 * Path: /players/dragnar/SevenSpires/obj/
 * Type: shadow
 * Created: September 2014 by Karash
 *
 * Purpose: The shadow object cast upon target NPC to block movement.
 * 
 * History:
 *          07/22/2015 - Gnar
 *            Stolen from Karash's updates to the nightshade area. 
 ******************************************************************************/
#define TO this_object() 
#define ENV environment

object frenzy;

do_shadow(object ob) {
  if(!ob) return;
  frenzy = ob;
  shadow(frenzy, 1);
  set_heart_beat(1);
  return 1; }

stop_shad(){
  done();
  if(frenzy)
  shadow(frenzy,0);
  destruct(TO);
}

short() {
 return frenzy->short()+HIB+" **"+NORM+BLU+"QUIESCENT"+HIB+"**"+NORM;
}

frenzy() { return 1; }

done() {
  if(frenzy && ENV(frenzy)) {
  tell_room(ENV(frenzy),
    BLU+frenzy->query_name()+" begins to move again as the spell dissipates."+NORM+"\n");
  return 1; }
  return; }

move_player(){
  tell_room(ENV(frenzy),
  HIB+frenzy->query_name()+" tries to move but is unable.\n"+NORM);}

move_object(){
  tell_room(ENV(frenzy),
  HIB+frenzy->query_name()+" tries to move but is unable.\n"+NORM);}

run_away(){
  tell_room(ENV(frenzy),
  HIB+frenzy->query_name()+" tries to move but is unable.\n"+NORM);}

movement(){
  tell_room(ENV(frenzy),
  HIB+frenzy->query_name()+" tries to move but is unable.\n"+NORM);}

  
