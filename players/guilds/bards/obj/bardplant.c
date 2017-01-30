#include "/players/guilds/bards/def.h"

object victim,owner;
int power;

string short() {
  return HIG+"The Devil's Snare "+NORM+(victim?"[afflicting "+NAME(victim)+"]":"");
}

status id(string str) {
  return str=="plant" || str=="snare" || str=="bard_plant_obj";
}

void long() {
  if(!victim)
    return destruct(this_object());
  write("A thorny, somehwat evil-looking plant, made entirely of vines\n"+
        "wrapped around "+NAME(victim)+"\n");
}

afflict_target() {
  object room;
  int damage;
  if(!random(2)) {
    room=environment();
    if(!room || power <= 0 || !victim || !present(victim,room) || !owner || !present(owner,room) || 
     owner->query_attack() != victim || !present("bard_storm_obj",room)) {
      if(room)
        tell_room(room,"\nThe Devil's Snare withers and vanishes!\n");
      destruct(this_object());
      return;
    }
    damage=1+random(5);
    if(damage > (int)victim->query_hp())
    damage=(int)victim->query_hp()-1;
    victim->do_damage(({damage}),({"other|poison"}));
    tell_room(room,"The Devil's Snare injects its venom into "+NAME(victim)+".\n");
    power-=20;
  }
  call_out("afflict_target",2);
}

void start(object target, object caster, int pow) {
  victim=target;
  owner=caster;
  power=pow;
  afflict_target();
}

