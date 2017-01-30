#include "/players/wocket/closed/ansi.h"
inherit "obj/weapon.c";
object player;

reset(){
  set_id("bow");
  set_short("A rathian bow");
  set_class(8);
  set_weight(3);
  set_value(3000);
  set_hit_func(this_object());
  set_type("bow");
}

init(){
  ::init();
  player = this_player();
}

weapon_hit(att){
int chances;
int damage,damagedelt;
int i,percent;
int a;
object arrows;
  chances = random((player->query_attrib("ste")+player->query_attrib("luc"))/10)+1;
  arrows = present("w_arrows",player);
  if(!arrows){
    tell_object(player,"You have no arrows to fire with your bow!!!\n");
    return 0;
  }
  a = arrows->query_arrows();
  if(a == 0){
    tell_object(player,"You have no arrows to fire with your bow!!!\n");
    return 0;
  }
  if(a < chances) chances = a;
  for(i=0;i<chances;i++){
     percent = (player->query_hp()*10)/player->query_mhp();
     damage = (player->query_attrib("str") * percent)/5;
     damage = random(damage+(damage/2));
     if(att){
       get_firedmsg(att);
       damagedelt = att->hit_player(damage);
       get_msg(damagedelt,att);
       arrows->add_arrows(-1);
     }
     if(player->query_level() > 20){
       tell_object(player,"arrow fired ["+damage+"]["+damagedelt+"]\n");
     }
  }
}

get_firedmsg(object att){
  tell_object(player,"You fire your an arrow at "+att->query_name()+".\n");
  tell_object(att,player->query_name()+" fired an arrow at you.\n");
  player->remote_say(player->query_name()+" fired an arrow at "+att->query_name()+".\n",att);
}

get_msg(int damagedelt,object att){
if(att){
string what,how;
switch(damagedelt){
case 0:   what = "missed"; how = "";
break;
case 1..3:  what = "grazed"; how = "";
break;
case 4..5:  what = "hit"; how = "";
break;
case 6..10: what = "hit"; how = " hard";
break;
case 11..20: what = "hit"; how = " very hard";
break;
case 21..30: what = "smashed"; how = " with a bone crushing sound";
break;
default: what = "massacred"; how = " to small fragments";
}
tell_object(player,"Your arrow "+what+" "+att->query_name()+how+".\n");
tell_object(att,player->query_name()+"'s arrow "+what+" you"+how+".\n");
player->remote_say(player->query_name()+"'s arrow "+what+" "+att->query_name()+how+".\n",att);
}
}