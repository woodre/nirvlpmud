/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Main
//  Function:     Heal
//  Create Date:  2005.03.22
//  Last Edit:    2005.03.22 -Forbin
//  Notes:        
//   -4 use heal that splits 12 tox: 6 soak, 6 stuff  
//   -heals for 50 hps each use [33 'heal pts']
//   -heals for 133 total 'heal pts'
//   -COST= 1350 - figured as below:
//    (12*4)/((50*4)*2/3) = .36 => .35 -> 10 * ((50*4)*2/3) = 1330 -> 1350
//  Notable Changes:
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
#define SOAKPER  (USOAK*100)/(USER->query_max_soak())
#define STUFFPER (USTUFF*100)/(USER->query_max_stuff())
#define INTOXPER (UINTOX*100)/(USER->query_max_intox())
#define C NORM+CYN

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mongie");
  add_alias("berries");
  add_alias("berry");
  add_alias("mongie berries");
  add_alias("mongie berry");
  add_alias("day-old mongie berries");
  add_alias("day-old berries");
  add_alias("day-old");
  set_short(C+"Day-old Mongie Berries"+N);
  set_long("\n");
  set_type("berries");
  set_msg("Juice runs down the side of your mouth as you bite into the berry.\n");
  set_msg2(" eats a day-old Mongie berry.\n");
  add_cmd("eat");
  add_cmd("use");
  set_heal(50,0);
  set_charges(4);
  set_soak(6);
  set_stuff(6);
  set_value(300);
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
    return "Day-old "+C+"Mongie"+N+" berries "+C+">"+HIW+charges+C+"<"+N;
  }
  else return "Day-old "+C+"Mongie"+N+" berries";
}


long() { 
  write(
    "  Pale blue and mishappen, these Mongie berries are wrinkled and\n"+
    "quite frankly look a little old.  They have a slightly sickly-sweet\n"+
    "smell to them, almost like molasses.  They have a taste like sour\n"+
    "apples and week old strawberries.\n");
  if(charges == 1) {
    write(
      "There is "+C+charges+N+" berry left.\n"+
      "To heal yourself: 'use' or 'eat' the berry.\n");
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
