#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/euka/Def.h"
inherit EROOM;

reset(arg){
object vines;
  if(arg){ get_monsters(); return; }
  short_desc = GRN+"An Euka Tree"+OFF;
  long_desc = "Needs to be written.\n";
  dest_dir = ({
  EPATH+"efta1.c","west",
  EPATH+"efta3.c","south",
  EPATH+"eftaa.c","up",
  EPATH+"ef4.c","down",
  EPATH+"efta2.c","northeast",
   });
  set_light(1);
  get_monsters();
}

get_monsters(){
int i;
  i=0;
  while(random(2) && i <3) {
    move_object(clone_object(EPATH+"NPC/kawolla.c"),this_object());
    i++;
  }
  if(random(3)==1){
    move_object(clone_object(EPATH+"NPC/jibper.c"),this_object());
  }
  i=0;
  while(random(4) == 1 && i < 2) {
    move_object(clone_object("/players/wocket/graveyard/niblet.c"),this_object());
    i++;
  }
}

init(){
  ::init();
  add_action("swing","swing");
}

swing(str){
string dest;
  if(!str){
    notify_fail("Which direction would you like to swing?\n");
    return 0;
  }
  if((str != "southwest" && str != "southeast")){
    notify_fail("You may not swing in that direction.\n");
    return 0;
  }
  if(TP->query_local_weight() > random(100)){
  if(str == "southwest") dest = EPATH+"ef5.c";
  else
  dest = EPATH+"ef11.c";
  write(HIG+"\nYou grab ahold of the nearest vine and swing "+str+".\n"+OFF);
  write("The vine breaks and you fall to the ground.\n\n");
  say(TPN+" grabs ahold of the nearest vine and swings "+str+".\n");
  say("You see "+TPN+" fall to the ground as the vine breaks.\n");
  move_object(TP,dest);
  command("glance",TP);
  TP->hit_player(random(50));
  say(TPN+" falls into the room from above.\n");
  return 1;
  }
  if(str == "southwest") dest = EPATH+"eftb.c";
  else
  dest = EPATH+"eftd.c";
  write(HIG+"\nYou grab ahold of the nearest vine and swing "+str+".\n\n"+OFF);
  say(TPN+" grabs ahold of the nearest vine and swings "+str+".\n");
  move_object(TP,dest);
  command("glance",TP);
  say(TPN+"swings in and falls as "+TP->query_subjective()+" lets go of the vine.\n");
  return 1;
}

