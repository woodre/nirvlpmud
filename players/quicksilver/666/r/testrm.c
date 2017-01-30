#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("a room..."); 
   set_long("hi."); 
   add_exit("players/quicksilver/workroom","wr"); 
}