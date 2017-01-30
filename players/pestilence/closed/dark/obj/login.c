#include "/players/pestilence/ansi.h"

main(str) {
  if(!str){write("Where do you want to login? (church/guild)\n"); return 1;}
  if(str == "church") {this_player()->set_home("/room/church.c"); }
  if(str == "guild") {this_player()->set_home("/players/pestilence/closed/dark/room/hall.c"); }
 write("<"+HIK+"Dark Order"+NORM+"> Your login position has been changed.\n");
  return 1;
}