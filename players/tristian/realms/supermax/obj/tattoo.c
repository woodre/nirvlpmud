/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2014 Tristian
//                  All Rights Reserved.
//  Function:     Prison tattoo - sets faction protection
//  Create Date:  2014.04.29
//	 
*/

#include "/players/tristian/lib/ClubFeddefine.h"

int x;
string faction;

reset(arg){
  x = 3;
  if(arg) return;
}

long() {
  write("This is a tattoo that shows your prison faction.  You can 'show' your allegiance to any of the\n"+
        "following factions: "+HIR+"'skinheads'"+NORM+", black"+HIK+"'panthers'"+NORM+", or"+HIM+"'latin'"+NORM+" kings.\n");
}
id(string str) {
  if (x == 0) {
   return str == "skinhead";}
  if (x == 1) {
   return str == "panther";}
  if (x == 2) {
   return str == "latin";}
  if (x == 3) {
   return str == "tattoo";}
  else { 
   return 0;}
}

init() {
 add_action("show","show");
 }

extra_look() {
 if (x == 0) {
  if (this_player() == environment())
    return "You have a tattoo of a swastika on your left arm.";
  else {
    return environment()->query_name() +
       " has a swastika tattoo on " +environment()->query_possessive() + " left arm";}}
 if (x == 1) {
  if (this_player() == environment())
    return "You have a tattoo of a clenched fist inside a circle on your right arm.";
  else {
    return environment()->query_name() +
       " has a clenched fist inside a circle tattoo on " +environment()->query_possessive() + " right arm";}}
 if (x == 2) {
  if (this_player() == environment())
    return "You have a tattoo of a latin kings crown on your chest.";
  else {
    return environment()->query_name() +
       " has a latin kings crown tattoo on " +environment()->query_possessive() + " chest.";}}
if (x == 3) {
  if (this_player() == environment())
    return "You have a tattoo but no faction is set.";
  else {
    return environment()->query_name() +
       " has a tattoo with no faction set";}}
}

show(faction){
if (faction == "skinhead"){ 
   write("You roll up your left sleeve and show off your skin head tattoo.\n");
  x = 0;
return 1;
       }
if (faction == "panther"){
    write("You roll up your right sleeve and show off your black panther tattoo.\n");
  x = 1;
return 1;
    }
if (faction == "latin"){
   write("You rip open your shirt and show off the latin kings tattoo on your chest.\n");
  x = 2;   
return 1;
}
else
return 0;}



get() { return 1; }