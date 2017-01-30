/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Main
 *  Function:     Heal
 *  Create Date:  2003.07.05
 *  Last Edit:    2004.07.13 -Forbin
 *  Notes:        
 *   -4 use heal that splits 8 tox: 4 soak, 4 stuff  
 *   -heals for 50 hps each use [33 'heal pts']
 *   -heals for 133 total 'heal pts'
 *   -COST= 1900 - figured as below:
 *    (8*4)/((50*4)*2/3) = .24 => .24 -> 14 * ((50*4)*2/3) = 1862 -> 1900
 *  Notable Changes:
 *    -2004.07.13 switched to /obj/generic_heal            
 */

#include "/players/forbin/define.h"
inherit "/obj/generic_heal.c";

#define USER     this_player()
#define USERN    USER->query_name()
#define USERHP   USER->query_hp()
#define USERMHP  USER->query_mhp()
#define USERSP   USER->query_sp()
#define USERMSP  USER->query_msp()
#define UPOS     USER->query_possessive()
#define USOAK    USER->query_soaked()
#define USTUFF   USER->query_stuffed()
#define UINTOX   USER->query_intoxication()
#define SOAKPER  (USOAK*100)/(USER->query_level()*8)
#define STUFFPER (USTUFF*100)/(USER->query_level()*8)
#define INTOXPER (UINTOX*100)/(USER->query_level()+3)
#define C NORM+BLU
#define N NORM

string newshort;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mongie");
  add_alias("berries");
  add_alias("berry");
  add_alias("mongie berries");
  add_alias("mongie berry");
  set_short(C+"Mongie Berries"+N);
  set_long("\n");
  set_type("berries");
  set_msg("Juice runs down the side of your mouth as you bite into the berry.\n");
  set_msg2(" eats a Mongie berry.\n");
  add_cmd("east");
  add_cmd("use");
  set_heal(50,0);
  set_charges(4);
  set_soak(4);
  set_stuff(4);
  set_value(400);
  set_msg_soaked(C+"You are too soaked to use it!"+N);
  set_msg_stuffed(C+"You are too stuffed to use it!"+N);
  set_msg_precharges(C+">"+HIW);
  set_msg_postcharges(C+"<"+N);
  set_type_single("use"); 
  set_empty_msg("");   
}

query_weight() { return 1; }

query_save_flag() { return 1; }

short() { 
  object a, e;
  if(((a = this_player()) && (e = environment()) && (e == a)) 
     || ((a = this_player()) && (a->query_level() >= 40))) { 
    return newshort = C+"Mongie"+N+" berries "+C+">"+HIW+charges+C+"<"+N;
  }
  else return C+"Mongie"+N+" berries";
}


long() { 
  write(
    "  Dark blue and oval shaped, Mongie berries are smooth-skinned like\n"+
    "grapes.  They have a sweet smell like honey mixed with butter, and\n"+
    "they taste a hybrid of a strawberry and an apple.\n");
  if(charges == 1) {
    write(
      "There is "+C+charges+N+" berry left.\n"+
      "To heal yourself: 'use' or 'east' the berry.\n");
  }
  else 
    write(
      "There are "+C+charges+N+" berries left.\n"+
      "To heal yourself: 'use' or 'eat' the berries.\n");
}

show_charges() { }

show_heal_mon() {
  write(C+"          ["+HIW+USERHP+N+C+"|"+N+USERMHP+C+"]-["+HIW+USERSP+N+C+"|"+N+USERMSP+C+"]\n"+N);
  if(SOAKPER > 99)  { write(C+"             ("+N+"soak"+C+"  ["+HIW+SOAKPER+N+C+"%]\n"+N); }
  if(SOAKPER > 9 && SOAKPER < 100)   { write(C+"             ("+N+"soak"+C+"  [ "+HIW+SOAKPER+N+C+"%]\n"+N); }
  if(SOAKPER < 10)  { write(C+"             ("+N+"soak"+C+"  [  "+HIW+SOAKPER+N+C+"%]\n"+N); } 
  if(STUFFPER > 99) { write(C+"             ("+N+"stuff"+C+" ["+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(STUFFPER > 9 && SOAKPER < 100)  { write(C+"             ("+N+"stuff"+C+" [ "+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(STUFFPER < 10) { write(C+"             ("+N+"stuff"+C+" [  "+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(INTOXPER > 99) { write(C+"             ("+N+"intox"+C+" ["+HIW+INTOXPER+N+C+"%]\n"+N); }
  if(INTOXPER > 9 && SOAKPER < 100)  { write(C+"             ("+N+"intox"+C+" [ "+HIW+INTOXPER+N+C+"%]\n"+N); }
  if(INTOXPER < 10) { write(C+"             ("+N+"intox"+C+" [  "+HIW+INTOXPER+N+C+"%]\n"+N); }  
  if(charges == 1) {
    write("There is "+C+charges+N+" more berry left.\n");
  }
  else if(charges == 0) { write(""); }
  else 
    write("There are "+C+charges+N+" more berries left.\n");
  if(!charges) {
    write("You finish off the last berry.\n");
  }
}