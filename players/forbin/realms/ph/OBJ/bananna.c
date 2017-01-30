/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Phish - Fee area
//  Function:     Heal
//  Create Date:  2004.09.03
//  Last Edit:    2004.09.03 -Forbin
//  Notes:        
//   -3 use heal of 20 tox: 20 stuff  
//   -heals for 50 hps and 50 sps each use [50 'heal pts']
//   -heals for 150 total 'heal pts'
//   -COST= 1500 - figured as below:
//     (20*3)/(50*3) = 0.40 = 8/pt. = 150*8 = 1200
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
#define C NORM+HIY
#define N NORM

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bananna");
  add_alias("nanner");
  set_short(C+"A bananna"+N);
  set_long("\n");
  set_type("bites");
  set_msg("You take a large bite of the Maillot Jaune bar.\n");
  set_msg2(" takes a bite of an energy bar.\n");
  add_cmd("eat");
  set_heal(50,50);
  set_charges(3);
  set_stuff(20);
  set_value(400);
  set_msg_soaked(C+"You are too soaked to use it!"+N);
  set_msg_stuffed(C+"You are too stuffed to use it!"+N);
  set_msg_precharges(C+"["+HIW);
  set_msg_postcharges(C+"]"+N);
  set_type_single("eat");
  set_empty_msg(""); 
}

query_weight() { return 1; }

query_save_flag() { return 1; }

short() { 
  object a, e;
  if(((a = this_player()) && (e = environment()) && (e == a)) 
     || ((a = this_player()) && (a->query_level() >= 40))) {  
    return C+"A bananna ["+HIW+charges+C+"]"+N;
  }
  else return C+"A bananna"+N;
}

long() { 
  write(
    "  A slender, bright yellow bananna.  It looks very fresh and will\n");
  if(charges == 1) {
    write(
      "heal you when eaten.  There is "+C+charges+N+" more bite left.\n"+
      "To heal yourself: 'eat' the bananna.\n");
  }
  else write(
    "heal you when eaten.  There are "+C+charges+N+" more bites left.\n"+
    "To heal yourself: 'eat' the bananna.\n");
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
    write("There is "+C+charges+N+" more bite left.\n");
  }
  else if(charges == 0) { write(""); }  
  else write("There are "+C+charges+N+" more bites left.\n");
  if(!charges) {
    write("You stuff the last of the bananna into your mouth.\n");
  }
}