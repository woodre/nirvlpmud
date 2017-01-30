#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure.c";

int lightnum,bitenum;
reset(arg){
  if(arg) return;
set_id("cigar");
set_short("A cigar");
set_long("This is a cuban cigar.\n");
set_weight(1);
}

init(){
  add_action("light","light");
  add_action("bite","bite");
  add_action("puff","puff");
}

bite(str){
  if(str != "cigar"){
notify_fail("What would you like to bite?\n");
return 0;
}
  if(bitenum == 1){
notify_fail("The end of this cigar is already bitten.\n");
return 0;
}
  write("You bite off the end of the cigar.\n");
  say(this_player()->query_name()+" bites off the end of a cigar.\n");
  bitenum = 1;
return 1;
}
light(str){
  if(str != "cigar"){
notify_fail("What would you like to light?\n");
return 0;
}
  if(lightnum == 1){
notify_fail("Your cigar is already lite.\n");
return 0;
}
  if(bitenum != 1){
notify_fail("Your cigar hasn't had the end bitten off yet.\n");
return 0;
}
  write("You light your cigar.\n");
  say(this_player()->query_name()+" lights a cigar.\n");
  lightnum = 1;
return 1; 
}

puff(str){
  if(str != "cigar"){
notify_fail("What would you like to puff?\n");
return 0;
}
  if(lightnum != 1){
notify_fail("Your cigar hasn't been lighted yet.\n");
return 0;
}
  write("PUFF PUFF\nYou puff on your cigar.\nPUFF PUFF\n");
  say(this_player()->query_name()+" puffs on a cigar.\n");
return 1;
}

remove_object(){
  tell_object(find_player("wocket"),"destruct\n");
}
