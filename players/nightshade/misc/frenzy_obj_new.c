#include <ansi.h>

/******************************************************************************
 * Program: frenzy_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object (shadow)
 * Created: September 2014 by Karash
 *
 * Purpose: The shadow object cast upon target NPC when the frenzy spell is cast on them.
 * 
 * History:
 *          
 ******************************************************************************/
 
#define TO this_object() 
#define ENV environment


object frenzy;
int time;

do_shadow(object ob) {
  if(!ob) return;
  frenzy = ob;
  shadow(frenzy, 1);
  set_heart_beat(1);
  return 1; }

set_time(num) {
  time = 10*num;
  call_out("stop_shad",time); }

stop_shad(){
  done();
  if(frenzy)
  shadow(frenzy,0);
  destruct(TO);
}


heart_beat() 
{

  /** A frenzied creature will do an additional 40% WC of physical damage each round **/
  object fatt;
  int fwc;
  
  fatt = frenzy->query_attack();
  if(fatt)
  {
    fwc = frenzy->query_wc();
	fatt->hit_player(fwc * 4 / 10);
	tell_room(environment(frenzy),fatt->query_name()+" is hit with "+MAG+"extra fury"+NORM+"!\n");

	/* for testing */
	/* tell_room(environment(frenzy),"\n\FRENZY DAMAGE = "+fwc*4/10+"\n\n"); */
  }
}


short() {
 return frenzy->short()+","+MAG+" **"+NORM+HIM+"FRENZIED"+NORM+MAG+"**"+NORM;
}

frenzy() { return 1; }

done() {
  if(frenzy && ENV(frenzy)) {
  tell_room(ENV(frenzy),
    MAG+frenzy->query_name()+" regains focus as the spell dissipates."+NORM+"\n");
  return 1; }
  return; }

move_player(){
  tell_room(ENV(frenzy),
  frenzy->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(frenzy),
  frenzy->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(frenzy),
  frenzy->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(frenzy),
  frenzy->query_name()+" tries to move but is compelled to stay...\n");}

  