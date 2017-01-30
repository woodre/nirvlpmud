/*
*      File:             /players/lacar/area/park/obj/ststue_ex.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    
*      Notes:            area
*      Change History:
*/
#include <ansi.h>

id(str) {
  return str=="plaque" || str== "statue";
}


long()
 {
 write("This is a majestic Unicorn dedicated to all the dreamers on\n\
Nirvana and the ones to come. It stands proudly for all those that\n\
put work into their dreams and make them come true!\n\
Lady Of Roses\n\n");
}

short() {
  return ""+HIM+"Unicorn statue"+NORM+"";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "plaque") return 0;
  long();
  return 1;
}