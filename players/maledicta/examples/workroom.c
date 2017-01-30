inherit "room/room";
#include "/players/zeus/closed/all.h"
#define IDLE query_idle(users()[i])


reset(arg){
 if(!arg){

  set_light(1);
  short_desc="Overdose Clinic";
  long_desc="    Welcome to the one and only overdose clinic.\n"+
	  RED+"    -- -== -== =-- --- =-=-= -- --==  =--- =--- =-=- ==-- --\n"+NORM;
  dest_dir=({ 
  "/players/zeus/stuff/workroom2.c", "west",
  "/players/zeus/stuff/workroom3.c", "east",
  });
} }

  void init(){
  ::init();
  add_action("vortex_cmd", "v");
  add_action("clean_cmd", "clean");
  add_action("who_cmd", "zwho");
  add_action("bring_cmd", "bring");
  add_action("church_cmd", "church");
}

status church_cmd(){ TP->MP("church#/room/church.c"); return 1; }

status vortex_cmd(string str){
  if((int)TP->query_level() < 21) return 0;
 if(!str){ write("Usage:  'v <location>' ||  Current Locations:\n\n"+
BOLD+"advance, realm, portal, building, museum\n"+NORM);
return 1; }
  if(str=="advance"){  write("You step through the vortex.\n");
   TP->MP("advance#room/adv_inner");   return 1; }
  if(str=="realm"){  write("You step through the vortex.\n");
   TP->MP("realm#players/zeus/realm/main");   return 1; }
  if(str=="portal"){  write("You step through the vortex.\n");
   TP->MP("portal#players/saber/ryllian/portal.c");   return 1; }
  if(str=="building"){  write("You step through the vortex.\n");
   TP->MP("building#players/cosmo/apt/rooms/lobby.c");   return 1; }
  if(str=="museum"){  write("You step through the vortex.\n");
   TP->MP("museum#players/zeus/museum/entrance.c");   return 1; }
}


status clean_cmd(){
int i, c;
c = 0;
  if((string)TP->query_real_name() != "zeus") return 0;
while(c < 2){
object *wr;
 wr = all_inventory(TO);
  for(i=0; i<sizeof(wr); i++) {
   if(!wr[i]->is_player()){ destruct(wr[i]); }
 }
 c++;
}
 TR(TO, "A rippling shadow passes through the room...\n");
return 1; }



status who_cmd() {
  int i, level, elvl, lvl;
  if((string)TP->query_real_name() != "zeus") return 0;
    write(BOLD+"     The Users of Nirvana        \n"+NORM);
write(RED+"      -- ---- -------- -------- ---- --\n"+NORM);
    for(i = 0; i < sizeof(users()); i++) {
  lvl = (int)users()[i]->query_level();
  elvl = (int)users()[i]->query_extra_level();
  level = lvl + elvl;
  if(users()[i]->query_level() >= 20)
	  write("["+users()[i]->query_level()+"] ");
  if(users()[i]->query_level() < 20){
	  write("["+level+"] ");
  }
  if(users()[i]->query_level() >= 20 && !users()[i]->query_invis())
	  write(HIG);
  if(users()[i]->query_level() >= 20 && users()[i]->query_invis())
	  write(HIR);
  if(users()[i]->query_level() < 20)
	  write(HIW);
  write(users()[i]->query_real_name() +" ");
  write(NORM);
  if(IDLE >= 60)
	  write(MAG+"<"+IDLE / 60+"m & "+IDLE % 60+"s>"+NORM);
write("\n");
}
write(RED+"      -- ---- -------- -------- ---- --\n"+NORM);
  return 1; }


status bring_cmd(string str){
object ob;
  if((string)TP->query_real_name() != "zeus") return 0;
  if(!str){ write("Usage: 'bring <player>'\n"); return 1; }
 ob = find_player(str);
  if(!ob) return 0;
   tell_object(ob,
"A "+BOLD+"black shadow"+NORM+" grips you tightly...\n"+
"\t\t\t\t\t\t\tYou have been summoned.\n");
if(environment(ob)){
   TR(environment(ob), 
	"A "+BOLD+"black shadow"+NORM+" folds in upon "+ob->QN+".\n", ({ ob }));
}
   MO(ob, environment(TP));
   TR(environment(ob), ob->QN+" appears suddenly.\n", ({ ob }));
   write(HIW+"Okay\n"+NORM);
   command("look", ob);
return 1; }

