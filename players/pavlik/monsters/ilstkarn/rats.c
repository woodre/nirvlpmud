inherit "obj/monster";
#include "/players/pavlik/closed/colors.h"
#define ME capitalize(this_object()->query_attack()->query_name())

int rats, last_rats;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Rat");
   set_race("rat");
   set_alias("rats");
   set_short("A horde of rats");
   set_level(20);
   set_hp(500);
   set_al(-100);
   set_wc(15);
   set_ac(20);
   set_aggressive(0);
   enable_commands();
   set_dead_ob(this_object());
   rats = 50;
   last_rats = 50;
}

id(str) {
  return str == "rats" || str == "horde" || str == "ilstkarn_monster";
}

short(){
  if(rats < 2) return "A single rat";
  else if(rats < 6) return "A few rats ("+rats+")";
  else if(rats < 11) return "A group of rats ("+rats+")";
  else if(rats < 26) return "A pack of rats ("+rats+")";
  else if(rats < 41) return "A mob of rats ("+rats+")";
  else return "A horde of rats ("+rats+")";
}

long(){
  if(rats < 2) write(
  "A lone rat boldly tries to chew off your foot!\n");
  else write(
  this_object()->short()+".  "+rats+" rats attack in a rabid frenzy!\n"+
  "A digusting yellow froth bubbles from their little mouths and\n"+
  "they crawl over each other in a chaotic mass of furry bodies and\n"+
  "snapping jaws in an attempt to chew off your feet!\n");
}

query_rats(){ return rats; }
add_rats(i){ rats = rats + i; }

heart_beat(){
  int num, ran;
  object room;
  object attk;
  ::heart_beat();

  if(this_object()->query_attack()){
  room = environment(this_object());
  for(num=0; num<(rats/10); num++){
     ran = random(7);
     if(ran == 0) tell_room(room,
     CYN+"> "+NORM+"A large rat emerges from the pack and scratches "+ME+"'s leg.\n"+NORM);
     else if(ran == 1) tell_room(room,
     CYN+"> "+NORM+"A rat sinks his sharp teeth into "+ME+"'s hand!\n"+NORM);
     else if(ran == 2) tell_room(room,
     CYN+"> "+NORM+"A rat bites deep into "+ME+"'s flesh!\n"+NORM);
     else if(ran == 3) tell_room(room,
     CYN+"> "+NORM+"A rat claws its way up "+ME+"'s leg.\n"+NORM);
     else if(ran == 4) tell_room(room,
     CYN+"> "+NORM+"A rat shreds "+ME+"'s flesh with its tiny teeth.\n"+NORM);
     else if(ran == 5) tell_room(room,
     CYN+"> "+NORM+"Yellow froth bubbles from the rats mouth.\n"+NORM);
     else if(ran == 6) tell_room(room,
     CYN+"> "+NORM+"The rats eyes glow with rabid madness.\n"+NORM);
  }

  this_object()->query_attack()->hit_player(random(rats));

  rats = this_object()->query_hp()/10;

  if(random(3)==1) {
    tell_room(room, this_object()->short()+" snap thier jaws viscously!\n");
  }

  if(rats < last_rats){
     ran = random(4);
     if(ran == 0) tell_room(room,
     HIB+ME+" crushes a rabid rat under his foot.\n"+NORM);
     else if(ran == 1) tell_room(room,
     HIB+"A rat squeals loudly, and dies.\n"+NORM);
     else if(ran == 2) tell_room(room,
     HIB+ME+" kills a rat.\n"+NORM);
     else if(ran == 3) tell_room(room,
     HIB+"Another rat's corpse litters the floor.\n"+NORM);
  }

  if(random(9) == 3){
    tell_room(room,
    CYN+"More rats skitter out of the walls and join the group!\n"+NORM);
    rats = rats + random(6);
  }

  last_rats = rats;

  }
}


monster_died(){
 object obj;

 tell_room(environment(this_object()),
 HIB+"* "+NORM+"All the rats have been killed!\n");

 destruct(present("corpse", environment(this_object())));

 return 0;
}

