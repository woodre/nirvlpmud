#include "std.h"
reset(arg){
   if(!arg){
      set_light(1);
   }
}

init(){
      add_action("exit_church","church");
}
exit_up(){
   object this,life;
   this=this_player();
   life=present("soul-undead",this);
   if(life->guild_level()<10)
     { notify_fail("Upper floor is for guild leaders and commanders.\n");
       return 0;
     }
   call_other(this,"move_player","up#players/trix/closed/guild/gcroom");
   return 1;
}
exit_shop(){
   call_other(this_player(), "move_player",
      "shop#room/shop");
   return 1;
}

exit_west(){
   call_other(this_player(), "move_player",
    "west#players/hurtbrain/guildent");
   return 1;
}

exit_down(){
   call_other(this_player(), "move_player",
    "down#players/hurtbrain/closed/guild/uheart");
   return 1;
}

exit_post() {
   call_other(this_player(), "move_player",
      "post#/room/post");
   return 1;
}

exit_pub(){
   call_other(this_player(), "move_player",
      "pub#room/pub2");
   return 1;
}

exit_church(){
   call_other(this_player(), "move_player",
      "church#room/church");
   return 1;
}
exit_lockers(){
   call_other(this_player(), "move_player",
      "lockers#players/catwoman/tl");
   return 1;
}
exit_hotel(){
   call_other(this_player(), "move_player",
      "hotel#players/boltar/hotel/hotel");
   return 1;
}
exit_daycare(){
   call_other(this_player(), "move_player",
      "hotel#players/boltar/sprooms/daycare");
   return 1;
}
short(){ return "A dark Crypt"; }
long(){ write(""+
      "    You are in a dark crypt, shelter of the undead souls, where\n"+
      "nobody else can intrude.  Ancient magical runes are engraved all\n"+
      "over the smooth walls cut from stone.  They tell about the\n"+
      "history of this powerful breed, born from the depths of the\n"+
      "earth thousands of years ago as priests and servants of a\n"+
      "primordial evil God, whose name has never been pronounced.\n"+
      "The prophecies tell that one day He will awake from His long\n"+
      "sleep, destroy the unfaithfuls, and give His breed the world to\n"+
      "rule it in His name for eternity.\n"+
      "Some stairs cut in the stone lead up to another room.\n"+
      "The only exit is : church\n");
}
healfaster(){
   object this;
    return 1;
/* What is this shit? NO FREE HEALS!!!!q _Bp */
   this=first_inventory(this_object());
   while(this){
      if(find_player(this->query_real_name())){ this->heal_self(0); }
      this=next_inventory(this);
      call_out("healfaster",1);
   }
   return 1;
}
