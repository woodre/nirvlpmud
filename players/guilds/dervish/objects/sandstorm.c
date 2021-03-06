#include "/players/snow/dervish/def.h"
inherit "/obj/treasure.c";
int time;
object owner;

reset (arg) {

 set_id(SANDSTORM);
 set_alias("sandstorm");
 set_short(YELLOW+"A large Sandstorm"+OFF);
 set_long(
 "  A large Sandstorm that slowly sweeps the area damaging anything in it's path.\n");
 if(!root()) {
 call_out("whip", 15);
 call_out("do_emote", 15);
 }
}

init() {
  ::init();
  if( this_player() && this_player() == owner )
    add_action( "vanish_sandstorm","vanish" );
}

get() { return; }

set_time(amt){
  time = amt*3;
  call_out("vanish", time);
  }

set_owner( object who ) { owner = who; }

vanish(){
  tell_room(environment(this_object()),BOLD+RED+"\tThe Sandstorm loses it's energy and scatters into the open air.\n"+OFF);
  destruct(this_object());
}

vanish_sandstorm(string str) {
  if(!str || !id(str) )
    return 0;
  if( this_player() == owner ) {
    tell_room( environment(), this_player()->query_name()+" waves "+this_player()->query_possessive()+" hand and the Sandstorm "+BOLD+RED+"dissipates"+OFF+".\n"); 
    destruct( this_object() );
    return 1;
  }
}

do_emote(){
  string what;
  switch(random(5)){
   case 0:   what = "The Sandstorm swirls around the room.\n"; break;
   case 1:   what = "The Sandstorm whips sand into your face.\n"; break;
   case 2:   what = "Some debris is sucked into the Sandstorm.\n"; break;
   case 3:   what = "Large debris is tossed across the room from the Sandstorm's power.\n"; break;
   case 4:   what = "The Sandstorm builds up force.\n"; break;
   }
  tell_room(environment(this_object()), what);
  call_out("do_emote", random(30));
 }

whip(){
  object peep, next_peep;
  if(!environment()) return;
    peep = first_inventory(environment(this_object()));
  if(!environment(this_object())) return;
  tell_room(environment(this_object()),
       BOLD+YELLOW+"\tThe Sandstorm releases some of it's energy!\n"+OFF);
  while(peep) {
     next_peep = next_inventory(peep);
     if(living(peep) && !peep->is_player() && !peep->id("clan_wall_blocker_obj") ){
     peep->hit_player(10+random(10), "other|earth");
     }
     peep = next_peep;
    }
  call_out("whip", random(30));  
 }
  
long() { 
  string str;
  str = long_desc;
  if( this_player() && this_player() == owner )
    str = str + "You have the ability to 'vanish sandstorm'\n";
  write(str); 
}
