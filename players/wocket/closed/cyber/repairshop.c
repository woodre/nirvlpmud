#include "/players/dune/closed/guild/DEFS.h"
inherit "/players/wocket/std/tvroom.c";

mixed *repaircosts;
string msg;

reset(arg){
  if(arg) return;
  short_desc = BOLD+YELLOW+"CyberNinja Repair Shop"+OFF+" [s]";
  long_desc = ""+
  " not written yet.!\n";
  set_light(1);
  repaircosts = ({ "cybereyes","10000",
                   "organic_converter","5000",
                   "bionics","10000",
                   "blades","10000",
                   "fluxes","10000",
                   "biolight","5000",
                   "emotion_controler","8000",
                   "matter_converter","15000",
                   "subdermal_armor","12000" });
}

init(){
  add_action("register","register");
  add_action("repair","repair");
  add_action("diagnosis","diagnosis");
  add_action("list","list");
}

register(){
  write(
"Services available:\n"+
"\n"+
"repair.................repair a damaged or broken enhancement\n"+
"list...................list of repairable items and credit cost\n"+
"diagnosis..............list broken enhancements\n"+
"\n");
  return 1;
}

list(){
  write(
"Repairs available....\n"+
"ITEM                           PRICE(in @'s)\n"+
"_____________________________________________\n"+
"cybereyes                        10000\n"+
"organic_converter                 5000\n"+
"bionics                          10000\n"+
"blades                           10000\n"+
"fluxes                           10000\n"+
"biolight                          5000\n"+
"emotion_controller                8000\n"+
"matter_converter                 15000\n"+
"subdermal_armor                  12000\n"+
"_____________________________________________\n");
  return 1;
}

diagnosis(){
string str;
msg =  "Status of enhancements are....\n";
msg += "__________________________________\n";
get_broken_str("query_broken_eyes","cybereyes","item_eyes");
get_broken_str("query_broken_corpse","organic_converter","item_corpse");
get_broken_str("query_broken_bionics","bionics","item_bionics");
get_broken_str("query_broken_blades","blades","item_blades");
get_broken_str("query_broken_flux","flux","item_heatflux");
get_broken_str("query_broken_flux","flux","item_magenticflux");
get_broken_str("query_broken_flux","flux","item_electricflux");
get_broken_str("query_broken_emt","emotion_controller","item_emt");
get_broken_str("query_broken_convert","matter_converter","item_convert");
get_broken_str("query_broken_armor","subdermal_armor","item_armor");
msg += "__________________________________\n";
  write(msg);
  return 1;
}

get_broken_str(str,str2,str3){
  if(!call_other(IPTP,str3)) return 0;
  if(call_other(IPTP,str))
    msg += RED+str2+OFF+" (BROKEN)"; 
  else
    msg += str2;
  msg+= "\n";
  return str;
}

repair(str){

  switch(str){
case "cybereyes": 
                  if(IPTP->query_broken_eyes()){ 
                    if(fix("cybereyes")){ 
                      IPTP->set_break_eyes(0); 
                    }
                    return 1;  
                  }
                  break;
case "organic_converter": 
                  if(IPTP->query_broken_corpse()){ 
                    if(fix("organic_converter")){
                      IPTP->set_break_corpse(0);
                    }                   
                    return 1;
                  }
                  break;
default:  notify_fail(RED+BLINK+"ERROR: "+OFF+"That is not something you can repair here.\n"+OFF);
          return 0;
  }
  write("That is not broken.\n");
  return 1;
}

fix(str){
int cost;
  cost = member_array(str,repaircosts)+1;
  if(cost && IPTP->balance() > cost){
    IPTP->addToBalance(-cost);
    write(RED+BLINK+"REPAIRING.....\n"+OFF);
    call_out("emote2",1,this_player());
     return 1;
  }
  else{
    write(RED+BLINK+"ERROR:  "+OFF+"You lack the credits needed for this repair.\n");
    return 0;
  }
}

emote2(obj){
tell_object(obj,"You hear the whirld of hunderds of small droids as they lay you down and repair\n"+
          "your broken enhancement.\n");
call_out("emote3",1,obj);
}

emote3(obj){
tell_object(obj,GREEN+BOLD+"REPAIRING COMPLETE\n"+OFF);
}