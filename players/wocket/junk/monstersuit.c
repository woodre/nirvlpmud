/* monstersuit */
#include "/players/wocket/closed/ansi.h"
#define MROOM environment(this_object())
inherit "/obj/monster.c";
object monsterwiz;

id(str){ return str == "monstersuit"; }

short(){
string msg;
  msg = "A giant monster";
  if(this_player()->query_level() > 21){
    if(monsterwiz)
     msg += " ("+HIR+monsterwiz->query_real_name()+OFF+")";
    else
     msg += "suit (empty)";
  }
  return msg;
}

long(){
  write("A monster suit.\n");
}

reset(arg){
if(arg) return;
::reset();
enable_commands();
#ifndef __LDMUD__
  add_action("newfail"); add_xverb("");
#else
  add_action("newfail", "", 3);
#endif
}

heart_beat(){
::heart_beat();
  if(monsterwiz && attacker_ob){
    monitor(); 
  }
}

init(){
::init();
if(this_player()->query_level() > 21){
 if( environment(this_player()) == MROOM ){
   add_action("entermon","zipup");
 }
 if(environment(this_player()) == this_object()){
   add_action("catchall");add_xverb("");
   add_action("look","look");
   add_action("look","l");
   add_action("killemdead","kill");
   add_action("monitor","mon");
   add_action("get_it","get");
/* not done yet 
   add_action("give","give");
   add_action("score","score");
   add_action("say");
*/              
   add_action("exitmon","unzip");
 }
}
}

newfail(){
  notify_fail("");
  return 0;
}

look(str){
object ob;
string obstring,item;
int max;
  if(!str){
    environment()->long();
    ob = first_inventory(environment());
    while(ob){
      obstring = ob->short();
      if(obstring){
        write(obstring+".\n");
        obstring = 0;
      }
      ob = next_inventory(ob);
    }
  }
  /*
   if (sscanf(str, "at %s", item) == 1 |
  */
  return 1;
}

killemdead(str){
  object ob;
  if(!str){
    write("What would you like to kill?\n");
    return 1;
  }
  ob = present(lower_case(str), MROOM );
  if(!ob){
    write("There is no "+str+" here to kill.\n");
    return 1;
  }
  if(!living(ob)){
    write(capitalize(str)+" is not a living thing.\n");
    return 1;
  }
  if(ob == this_object()){
    write("Why would you want your monster to attack itself?\n");
    return 1;
  }
  if(attacker_ob == ob){
    write("You are already attacking "+capitalize(str)+".\n");
    return 1;
  }
  if(!attack_object(ob)){
    write("You can't attack "+capitalize(str)+".\n");
    return 1;
  }
  return 1;
}

monitor(){
string msg;
  msg = HIR+"[monster mon] "+OFF;
  msg += BOLD+"HP "+OFF+hit_point+"/"+max_hp+" ";
  msg += BOLD+"SP "+OFF+spell_points+"/"+max_spell+" ";
  if(attacker_ob){
    msg += BOLD+attacker_ob->query_name()+" "+OFF+attacker_ob->query_hp()+"/"+attacker_ob->query_mhp();
  }
  msg += "\n";
  tell_object(monsterwiz,msg);
  return 1;
}

get_it(str){
object item;
  if(!str){
    write("What would you like to get?\n");
    return 1;
  }
  str = lower_case(str);
  item = present(str,MROOM);
  if(!item){
    notify_fail("That is not here.\n");
    return 0;
  }
move_object(item,this_object());
write("You pick up "+str+".\n");
tell_room(MROOM,name+" picks up "+str+".\n");
return 1; 
}

move_player(str){
::move_player(str);
command("look",monsterwiz);
}

entermon(){
  move_object(this_player(),this_object());
  monsterwiz = this_player();
  write("You step into the monstersuit and zip it up.\n");
  set_heart_beat(1);
  return 1;
}

exitmon(){
  move_object(this_player(),environment(this_object()));
  write("You unzip the monstersuit and step out of it.\n");
  monsterwiz = 0;
  return 1;
}

catch_tell(str){
  if(monsterwiz){
    if(this_player() && (environment(this_player()) == this_object()))
      return;
    else
      tell_object(monsterwiz,str);
  }
}

catchall(str){
  if(command(str,this_object()))
    return 1; 
}
