/*  this file is no longer used */
inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"

reset(arg){

  set_id("zeus_arena_obj");
  set_alias(0);
  set_short(0);
  set_long(0);
  set_weight(0);
  set_value(0);
}
drop(){  return 1; }

void init(){
	::init();
	add_action("move_dir", "north");
	add_action("move_dir", "northeast");
	add_action("east_dir", "east");
	add_action("move_dir", "southeast");
	add_action("move_dir", "south");
	add_action("move_dir", "southwest");
	add_action("move_dir", "west");
	add_action("move_dir", "northwest");
}

check(){  /*
   string z;
   if(environment(ENV) && !sscanf(file_name(environment(ENV)), 
	   "players/zeus/realm/x/r/%s", z))
*/	  destruct(TO);
}

make_monsy(){
	int x;
	object mon;
	string r;
	x = random(10);
	switch(x){
case 0: mon = CO("/players/zeus/realm/x/NPC/beast.c"); break;
case 1: mon = CO("/players/zeus/realm/x/NPC/bandit.c"); break;
case 2: mon = CO("/players/zeus/realm/x/NPC/figure.c"); break;
case 3: mon = CO("/players/zeus/realm/x/NPC/wraith.c"); break;
case 4: mon = CO("/players/zeus/realm/x/NPC/headless.c"); break;
case 5: mon = CO("/players/zeus/realm/x/NPC/zombie.c"); break;
case 6: mon = CO("/players/zeus/realm/x/NPC/demon_large.c"); break;
case 7: mon = CO("/players/zeus/realm/x/NPC/ghoul.c"); break;
case 8: mon = CO("/players/zeus/realm/x/NPC/spider.c"); break;
case 9: mon = CO("/players/zeus/realm/x/NPC/vulture.c"); break;
	}
	r = cow_hide(6);
	MO(mon, r);
	x = random(5);
	switch(x){
case 0: r = "The shadows shift about.\n"; break;
case 1: r = "Something moves among the shadows.\n"; break;
case 2: r = "Something catches your eye.\n"; break;
case 3: r = "You suddenly feel uneasy.\n"; break;
case 4: r = "The forest seems alive.\n"; break;
	}
	TR(environment(mon), r);
}

string cow_hide(int z){
  int x;
  string ya;
  x = random(9);
  switch(x){
    case 0: ya = "players/zeus/realm/x/r/1"; break;
    case 1: ya = "players/zeus/realm/x/r/2"; break;
    case 2: ya = "players/zeus/realm/x/r/3"; break;
    case 3: ya = "players/zeus/realm/x/r/4"; break;
    case 4: ya = "players/zeus/realm/x/r/5"; break;
    case 5: ya = "players/zeus/realm/x/r/6"; break;
    case 6: ya = "players/zeus/realm/x/r/7"; break;
    case 7: ya = "players/zeus/realm/x/r/8"; break;
    case 8: ya = "players/zeus/realm/x/r/9"; break; 
  }
  if(!random(z)/* && TP->query_level() < 21 */&& 
	  !TP->query_ghost())  make_monsy();
  return ya;
}


east_dir(){
   string y,z;
   if(environment(TP) && !sscanf(file_name(environment(TP)), 
	   "players/zeus/realm/x/r/%s", z)){
	   call_out("check", 1);
	   return 0;
   }
  if("/players/zeus/closed/fl_demon.c"->check_demon()) return 1;
  if(TP->query_attack() && !random(3) && !TP->query_ghost()){
	 write("The shadows wrap around you!\n");
	 return 1;
  }
   do {
	   if(!random(5))
		  y = "players/zeus/realm/x/path2";
	   else
          y = cow_hide(1+random(4));
   } while((string)file_name(environment(TP)) == y);
   TP->MP("into the forest..#"+y);
   return 1;
}


move_dir(){
   string y,z;
   if(environment(TP) && !sscanf(file_name(environment(TP)), 
	   "players/zeus/realm/x/r/%s", z)){
	   call_out("check", 1);
	   return 0;
   }
  if("/players/zeus/closed/fl_demon.c"->check_demon()) return 1; 
  if(TP->query_attack() && !random(3)){
	 write("The shadows wrap around you!\n");
	 return 1;
  }
  do   y = cow_hide(1+random(4));
  while((string)file_name(environment(TP)) == y);
   TP->MP("into the forest..#"+y);
   return 1;
}
