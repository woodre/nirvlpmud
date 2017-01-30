#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/e_forest/Def.h"
inherit EROOM;

reset(arg){
object vines;
  if(arg){ get_monsters(); return; }
  short_desc = GRN+"An Euka Tree"+OFF;
  long_desc = "Needs to be written.\n";
  dest_dir = ({
  EPATH+"eftb3.c","east",
  EPATH+"eftb2.c","west",
  EPATH+"eftb4.c","south",
  EPATH+"eftbb.c","up",
  EPATH+"ef6.c","down",
  EPATH+"eftb1.c","northwest",
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
  if((str != "east" && str != "northeast" && str != "southeast")){
    notify_fail("That is not a direction you can swing.\n");
    return 0;
  }
  if(TP->query_local_weight() > random(100)){
  if(str == "east") dest = EPATH+"ef12.c";
  else{
    if(str == "southeast") dest = EPATH+"ef7.c";
    else
    dest = EPATH+"ef5.c";
  }
  write("\nYou grab ahold of the nearest vine and swing "+str+".\n");
  write("The vine breaks and you fall to the ground.\n\n");
  say(TPN+" grabs ahold of the nearest vine and swings "+str+".\n");
  say("You see "+TPN+" fall to the ground as the vine breaks.\n");
  move_object(TP,dest);
  command("glance",TP);
  TP->hit_player(random(50));
  say(TPN+" falls into the room from above.\n");
  return 1;
  }
  if(str == "east") dest = EPATH+"eftd.c";
  else{
    if(str == "southeast") dest = EPATH+"eftc.c";
    else
    dest = EPATH+"efta.c";
  }
  write(HIG+"\nYou grab ahold of the nearest vine and swing "+str+".\n\n"+OFF);
  say(TPN+" grabs ahold of the nearest vine and swings "+str+".\n");
  move_object(TP,dest);
  command("glance",TP);
  say(TPN+" swings in and falls as "+TP->query_subjective()+" lets go of the vine.\n");
  return 1;
}

