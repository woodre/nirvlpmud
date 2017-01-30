#include <ansi.h>

inherit "/players/vertebraker/closed/std/fake_armor";

reset(arg){
  ::reset(arg);
  if(arg || root()) return;
  set_id("surcoat of sand");
  set_alias("surcoat");
  set_short(YEL+"Surcoat of Sand"+NORM);
  set_long("\
A long vest adequate for wearing over one's armor.\n\
It swirls with energy.\n");
  set_weight(1);
  set_value(0);
  set_wear_msgs(({
    "You throw $me$ over your shoulders.\n",
    " throws $me$ over their shoulders.\n" }));
  set_remove_msgs(({
    "You remove $me$.\n",
    " removes $me$.\n" }));
  set_type("surcoat");
  call_out("fake_beat",2);
}

drop() {
  if(this_player() && this_player()->query_real_name()=="dp"){
    return 0;
  }
  else {
    return 1;
  }
}

get(){
  return !drop();
}

fake_beat(){
  object user, room, atk;
  int dmg;
  string msg;
  
  if(!random(5) && 
     (user=environment()) && (room=environment(user)) &&
     (atk=(object)user->query_attack())){
     
     dmg = 5+random(15);
     
     switch(dmg){
     
     case 1..5:
      msg = "Sand sprays from around "+user->query_name()+"!";
      break;
     case 6..10:
      msg = "Sharp pebbles fall all around "+atk->query_name()+"!";
      break;
     case 11..15:
      msg = "Rocks tumble down from the heavens onto "+atk->query_name()+"!";
      break;
    case 16..20:
      msg = "A gigantic BOULDER falls on "+atk->query_name()+"'s head!";
      break;
    }
    
    tell_room(room,YEL+".o0o."+NORM+msg+YEL+".o0o.\n"+NORM);
    atk->hit_player(dmg, "other|earth");
  }
  call_out("fake_beat", 2);
}
    
