/*
 *      File:                   fexits.h
 *      Function:               none    
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 10/23/2004
 *      Notes:                  exits for the black forest
 *                              12 current forest rooms
 *      Change History:
 */

#define f13 "/players/hogath/area/forest/f0.c" 
#define f1 "/players/hogath/area/forest/f1.c"
#define f2 "/players/hogath/area/forest/f2.c"
#define f3 "/players/hogath/area/forest/f3.c"  
#define f4 "/players/hogath/area/forest/f4.c"
#define f5 "/players/hogath/area/forest/f5.c"
#define f6 "/players/hogath/area/forest/f6.c"
#define f7 "/players/hogath/area/forest/f7.c"
#define f8 "/players/hogath/area/forest/f8.c"
#define f9 "/players/hogath/area/forest/f9.c"
#define f10 "/players/hogath/area/forest/f10.c"
#define f11 "/players/hogath/area/forest/f11.c"
#define f12 "/players/hogath/area/forest/f11.c"

string get_room(){
  string room;
  switch (random(11)){
    case 1 : room = "f1"; break;
    case 2 : room = "f2"; break;
    case 3 : room = "f3"; break;
    case 4 : room = "f4"; break;
    case 5 : room = "f5"; break;
    case 6 : room = "f6"; break;
    case 7 : room = "f8"; break;
    case 8 : room = "f8"; break;
    case 9 : room = "f9"; break;
    case 10 : room = "f10"; break;    
    case 11 : room = "f11"; break;
    case 0 : room = "f12"; break;
  }
  return room;
}