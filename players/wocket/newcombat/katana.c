#include "/players/wocket/closed/ansi.h"
#include "defs.h"


object att;
object attwep;
object me;
int cmd;
int targetzone;
int opp_targetzone;
int attdefnum;
int opp_attdefnum;
int health;
int delay;
int dam;
int opp_dam;
int can_counter,counterdelay;

id(str){ return (str == "w_duelingwep" || str == "katana"); }
short(){ return HIR+"A wooden practice katana"+OFF; }
long(){
 write(HIR+"Commands:\n\n"+
           "Thrust          <up,down,left,right>\n"+
           "Jab             <up,down,left,right>\n"+
           "Slash           <left,right,down>\n"+
           "Counter         <up,down,left,right>\n"+
           "Block           <up,down,left,right>\n"+
           "Parry           <up,down,left,right>\n"+
           "Dodge           <left,right,down>\n"+
           "Jump            <up>\n"+
           "\n"+
           "rekatana\n"+
           "stop\n"+
           "attack\n"+
           "\n"+OFF);
}


get(){ return 1; }

init(){
  add_action("thrust","thrust");
  add_action("jab","jab");
  add_action("hack","hack");
  add_action("slash","slash");
  add_action("counter","counter");
  add_action("parry","parry");
  add_action("dodge","dodge");
  add_action("jump","jump");
  add_action("block","block");
  add_action("attack","attack");
  add_action("fightstop","stop");
  add_action("rekatana","rekatana");
  me = environment(this_object());
  health = 50;
}

heart_beat(){
int damage;
string adv; 
  if(att && environment(att) != environment(me)){
    stop_fight();
    attwep->stop_fight();
  }
  if(delay == 2){
  tell_object(me,"You are feeling "+get_health()+".\n");
  tell_object(att,ME_N+" is looking "+get_health()+".\n");
    if(opp_attdefnum){
      if(!attdefnum || attdefnum < 6){
        damage = (opp_dam/2)+random(opp_dam/2);
        adv = get_adv(damage);
        tell_object(me,att->query_name()+HIR+" hits"+OFF+" you with a "+HIR+adv+OFF+" "+get_type()+".\n");
        tell_object(att,"You "+HIR+"hit "+OFF+me->query_name()+" with your "+HIR+adv+OFF+" "+get_type()+".\n");  
      }
      if(attdefnum == 6){
        if(targetzone == opp_targetzone){
          tell_object(me,"You parry the "+get_type()+".\n");
          tell_object(att,me->query_name()+" parries the "+get_type()+".\n");
          can_counter = 1;
          counterdelay = 1;
        }
        else{
          say("You move to parry but run into the "+get_type()+"\n");
          damage = (opp_dam/2)+random(opp_dam/2);
        }
      }
      if(attdefnum == 7){
        if(targetzone != opp_targetzone){
          if(targetzone == 1){
            tell_object(me,"You jump over the "+get_type()+".\n");
            tell_object(att,ME_N+" jumps over your "+get_type()+".\n");
          } else {
            tell_object(me,"You dodge the attack.\n");
            tell_object(att,me->query_name()+" dodges the attack.\n");
          }
        }
        else{
          if(targetzone == 1){
            tell_object(me,"You jump into the "+get_type()+".\n");
            tell_object(att,ME_N+" jumps into your "+get_type()+".\n");
          } else {
            say("You move to dodge but get hit by the attack.\n");
            damage = (opp_dam/2)+random(opp_dam/2);
          }
        }
      }
      if(attdefnum == 8){
        if(targetzone == opp_targetzone){
          tell_object(me,"You block the "+get_type()+".\n");
          tell_object(att,ME_N+" blocks your "+get_type()+".\n");
          damage = ((opp_dam/2)+random(opp_dam/2))/4;    
          can_counter = 1;
          counterdelay = 1;
        } else {  
          tell_object(me,"You partially deflect of the "+get_type()+".\n");
          tell_object(att,ME_N+" partially deflect your "+get_type()+".\n");
          damage = ((opp_dam/2)+random(opp_dam/2))/2;
          can_counter = 1;
          counterdelay = 1;
         }
       }
    }  
  health = health - damage;
  if(health < 1){
    tell_object(me,BOLD+"You are knocked unconcious.\nYou have been defeated.\n"+OFF);
    tell_object(att,BOLD+"You have knocked "+me->query_name()+" unconcious.\nYou are victorious.\n"+OFF);
    stop_fight();
  }
  cmd--;
  if(cmd < 0){
    tell_object(me,"You stand ready to fight again.\n");
    cmd = 0;  
  }  
  opp_attdefnum = 0;
  if(counterdelay) counterdelay --;
  else
  can_counter = 0;
  attdefnum = 0;
  delay = 0;
  }
delay ++;
}

attack(str){
object ob;
  if(!str){
    notify_fail("Who would you like to attack?\n");
    return 0;
  }
  ob = find_player(str);
  if(!ob){
    notify_fail("That person is not here to attack.\n");
    return 0;
  }
  if(environment(ob) != environment(this_player())){
    notify_fail("That person is not here to attack.\n");
    return 0;
  }
  attwep = present("w_duelingwep",ob);
  if(!attwep){
    notify_fail("That person is not prepared to spar with you.\n");
    return 0;
  }
  att = ob;
  tell_object(att,ME_N+" screams, \"En Gaurde!\"\n"+ME_N+" leaps to attack you.\n");
  tell_object(me,"You scream, \"En Gaurde!\"\nYou leap to attack "+ob->query_name()+".\n");
  set_heart_beat(1);
  attwep->set_hb(1);
  attwep->set_att(this_player());
  return 1;
}

thrust(str){
  if(!cmd_ok()) return 0;
  switch(str){
    case "up":    targetzone = 1;  break;      
    case "down":  targetzone = 2;  break;
    case "left":  targetzone = 3;  break;
    case "right": targetzone = 4;  break;
    default:      targetzone = 0;  str = "straight";
  }
  write("You thrust "+str+" at "+att->query_name()+".\n");
  tell_object(att, me->query_name()+" thrusts "+str+" at you.\n");
  attdefnum = 1;
  cmd = 2;
  dam = 15;
  call_other(attwep,"set_attack",attdefnum,targetzone,dam);
  return 1;
}

jab(str){
  if(!cmd_ok()) return 0;
  switch(str){
    case "up":    targetzone = 1;  break;      
    case "down":  targetzone = 2;  break;
    case "left":  targetzone = 3;  break;
    case "right": targetzone = 4;  break;
    default:      targetzone = 0;  str = "straight";
  }
  write("You jab "+str+" at "+att->query_name()+".\n");
  tell_object(att, me->query_name()+" jab "+str+" at you.\n");
  attdefnum = 2;
  cmd = 1;
  dam = 10;
  call_other(attwep,"set_attack",attdefnum,targetzone,dam);
  return 1;
}

slash(str){
  if(!cmd_ok()) return 0;
  switch(str){
    case "down":    targetzone = 1;  break;
    case "left":    targetzone = 3;  break;
    case "right":   targetzone = 4;  break;
    default:        targetzone = 1;  str = "down";
  }
  write("You begin to slash "+str+" at "+ATT_N+".\n");
  tell_object(att,ME_N+" begins to slash "+str+" at you.\n");
  attdefnum = 4;
  cmd = 1;
  dam = 15;
  call_other(attwep,"set_attack",attdefnum,targetzone,dam);
  return 1;
}

counter(str){
  if(!cmd_ok()) return 0;
  if(!can_counter){
    notify_fail("You are not in a possition to counter attack\n");
    return 0;
  }
  switch(str){
    case "up":    targetzone = 1; break;
    case "down":  targetzone = 2; break;
    case "left":  targetzone = 3; break;
    case "right": targetzone = 4; break;
    default:      targetzone = 0; str = "straight";
  }
  cmd = 1;
  dam = 25;
  attdefnum = 5;
  can_counter = 0;
  write("You counter attack "+str+" at "+ATT_N+".\n");
  tell_object(att,ME_N+" counter attacks "+str+" at you.\n");
  call_other(attwep,"set_attack",attdefnum,targetzone,dam);
  return 1;
}

parry(str){
  if(!cmd_ok()) return 0;
  switch(str){
    case "up":    targetzone = 1; break;
    case "down":  targetzone = 2; break;
    case "left":  targetzone = 3; break;
    case "right": targetzone = 4; break;
    default:      targetzone = 0; str = "straight";
  }
  attdefnum = 6;
  cmd = 1;
  tell_object(me,"You move to parry "+str+".\n");
  tell_object(att,ME_N+" moves to parry "+str+".\n");
  return 1;
}

dodge(str){
  if(!cmd_ok()) return 0;
  if(!str){
    notify_fail("Which direction are you going to dodge?\n");
    return 0;
  }
  switch(str){ 
    case "down":  targetzone = 2; break;
    case "left":  targetzone = 3; break;
    case "right": targetzone = 4; break;
    default:      notify_fail("That is not a direction you can dodge.\n");
                  return 0;
  }
    write("You move to dodge "+str+".\n");
    tell_object(att,me->query_name()+" moves to dodge "+str+".\n");
  attdefnum = 7;
  cmd = 1;
  return 1;
}

jump(){
  if(!cmd_ok()) return 0;
  targetzone = 1;
  write("You prepare to jump up.\n");
  tell_object(att,ME_N+" prepares to jump up.\n");
  attdefnum = 7;
  cmd = 1;
  return 1;
}

block(str){
  if(!cmd_ok()) return 0;
  switch(str){
    case "up":    targetzone = 1; break;
    case "down":  targetzone = 2; break;
    case "left":  targetzone = 3; break;
    case "right": targetzone = 4; break;
    default:      targetzone = 0; str = "forward";
  }
  write("You move "+str+" to block an attack.\n");
  tell_object(att,ME_N+" moves "+str+" to block an attack.\n");
  attdefnum = 8;
  cmd = 1;
  return 1;
}

rekatana(){
  move_object(clone_object("/players/wocket/NEWcombat/katana.c"),environment(this_object()));
  write(HIR+"rekatana...\n"+OFF);
  destruct(this_object());
  return 1;
}

fightstop(){
  write("You call a stop to the fight.\n");
  tell_object(att,me->query_name()+" calls a stop to the fight.\n");
  stop_fight();
}

stop_fight(){  
 if(att)
    attwep->clear_att();
  clear_att();
 return 1;
}

cmd_ok(){
  if(!att){
    notify_fail("You are not attacking anyone.\n");
    return 0;
  }
  if(cmd){
    notify_fail("You are already doing something this round.\n");
    return 0;
  }
return 1;
}


set_attack(int i,a,c){
  opp_attdefnum = i;
  opp_targetzone = a;
  opp_dam = c;
}

set_att(ob){ 
  att = ob;
  attwep = present("w_duelingwep",att);
}

clear_att(){
  att = 0;
  attwep = 0;
  set_heart_beat(0);
}

set_hb(i){
  set_heart_beat(i);
}

get_type(){
  switch(opp_attdefnum){
  case 1: return "thrust"; break;
  case 2: return "jab";    break;
  case 3: return "hack";   break;
  case 4: return "slash";  break;
  case 5: return "counter attack"; break;
  default: return "unknown";
  }
}

get_adv(i){
  switch(i){
  case 1..5:    return "light"; break;
  case 6..10:   return "weak"; break;
  case 11..19:  return "strong"; break;
  case 20..28:  return "painful"; break;
  case 29..40:  return "massive"; break;
  default:      return "devistating"; break;
  }
}

get_health(){
  switch(health){
  case 1..5:    return "horrible"; break;
  case 6..10:   return "very hurt"; break;
  case 11..20:  return "hurt"; break;
  case 21..30:  return "weary"; break;
  case 31..40:  return "slightly weary"; break;
  case 41..45:  return "fine"; break;
  case 46..50:  return "healthy"; break;
  }
}
query_health(){
  return health; 
}