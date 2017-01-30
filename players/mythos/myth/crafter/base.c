#include "/players/mythos/myth/crafter/def.h"
inherit "players/mythos/myth/base";
string rom_room;
static string ram_room;
static int romw,ramw;

id(str) { return str == "crob" || str == "crafter_tools" ||
                 str == "tools" || str == "MYTHOSSYSOBJ"; }
                 
query_auto_load() { return "/players/mythos/myth/crafter/base.c:"; }

short() { return "Crafter's Tools"; }

long() {
   write("\n");
   write("myth_help will bring up the help files\n");
}

reset(arg) {
::reset(arg);
  if(arg) return;
  whatob = "crafter";
  rom_room = allocate(MAXROM);
  rom_room[0] = "players/mythos/enterence";
  rom_room[1] = "Chamber of Realms";
  rom_room[2] = "players/saber/";
  rom_room[3] = "The Black Chamber - GoPortal";
  ram_room = allocate(MAXRAM);
  ramw = 0;
  romw = 4;
}

init() {
::init();
  if(tp == ep) {
    call_out("preventer",5);
  }
}

preventer() {
  if(!ep) return 1;
  if(ep->query_wc() > MAXWC) ep->set_wc(MAXWC);
  if(ep->query_ac() > MAXAC) ep->set_ac(MAXAC);
call_out("preventer",10);
return 1; }

query_rom(int n) { if(n != -1) return rom_room[n]; else return rom_room;}
query_ram(int n) { if(n != -1) return ram_room[n]; else return ram_room;}
query_ramw() { return ramw; }
query_romw() { return romw; }
set_ramw(n) { ramw = n; }
set_romw(n) { romw = n; }
set_rom(int n,string where) {
int q;
  if(n != -1) {
  if(!where) rom_room[n] = 0;
  else rom_room[n] = where;
  } else for(q=0;q<MAXROM;q++) rom_room[q] = 0;
  gsave(); 
}
set_ram(int n,string where) {
  if(n != -1) {
  if(!where) ram_room[n] = 0;
  ram_room[n] = where;
  } else for(q=0;q<MAXRAM;q++) ram_room[q] = 0;
  gsave(); 
}

/* POWER material */
