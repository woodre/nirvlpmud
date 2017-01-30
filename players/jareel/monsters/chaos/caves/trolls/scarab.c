/* ***************************************************************
*
*************************************************************** */
#include "/players/jareel/ansi.h"
inherit "/obj/monster.c";

  reset(arg){
    ::reset(arg); 
  if(arg) return;

  set_name("scarab");
  set_short("A scarab");
  set_long(
    "A large bug roughly the size of a frog.  It hops and\n"+
    "scurries over the ground as you look at it.  Pincers\n"+
    "close at the head of the beetle, they looks very sharp.\n");
  set_level(6);
  set_hp(60);
  set_wc(50);
  set_ac(6);
  set_aggressive(0);
  set_a_chat_chance(40);
    load_a_chat("Teeth slice into you.\n");
    load_a_chat("The scarab scurries betwen your legs.\n");
    load_a_chat("The scarab screeches.\n");
  set_al(-100);
  ac_bonus += 4; /*For attack*/
  ac_bonus += 4; /*For Follow*/
  }

  init(){
    ::init();
#ifndef __LDMUD__
  add_action("attackme");add_xverb("");
#else
  add_action("attackme", "", 3);
#endif
  }

catch_tell(str){
  string name,dir;
  if(this_player() && (this_player()->is_player())) 
  if(sscanf(str,"%s leaves %s.",name,dir) == 2){
  if(random(8) < 5){
    say("The scarab bounces around.\n");
    command(dir);
} }     }

attackme(){
  if(!attacker_ob && random(15) == 1){
    tell_object(this_player(),"The scarab digs into your skin.\n");
    attacker_ob = this_player();
  }
  return 0;
}
