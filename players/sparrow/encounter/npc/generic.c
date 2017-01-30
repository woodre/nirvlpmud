/*****************************************************************************
 *      File:                   generic.c
 *      Function:               Base Generic Monster File for Encounter
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2011 Sparrow
 *                              All Rights Reserved.
 *      Source:                 02/27/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/
 #include "/sys/ansi.h"
 inherit "/obj/monster";
 int role,status;
 reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("generic");
    set_alias("monster");
    set_short(HIG+"Generic Encounter Monster"+NORM+" v0."+HIR+"1"+NORM);
    set_race( "monster");
    set_long("This is a generic encounter monster. If you see this long description\n"+
             "then an error has occurred. Please flee the Encounter and report the\n"+
             "error to Sparrow.\n");
    set_level(1);
    set_ac(1);
    set_wc(1);
    set_hp(1);
    set_al(0);
    set_aggressive(0);
  }
}

int set_encounter_role(int x) {
  if(!x) return;
  this_object()->role = x;
  return 1;
}

int set_encoutner_status(int x) {
  if(!x) return;
  this_object()->status = x;
  return 1;
}

int query_encounter_role() {
  return this_object()->role;
}

int query_encounter_status() {
  return this_object()->status;
}