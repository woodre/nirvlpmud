#include "/players/forbin/define.h"
#include "/players/forbin/hyperion/ruins/angel_inherit.c"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(1000) + 3000);
set_name("cleaver");
set_alt_name("collectable_obj_ice");
set_alias("icebrand");
set_short(""+BOLD+""+BLK+"Chu'Sarth Cleaver"+HIW+" ["+HIC+"Icebrand"+HIW+"]"+NORM+"");
set_long(
  "  Looking at this cruel weapon you see a spectre of what the\n"+
  "owner must have been like. Cold, deadly, and evil. The weapon\n"+
  "is covered with a light frost which never seems to diminish,\n"+
  "even at the touch of warmth.\n");

set_type("ring");  
set_class(16);
set_weight(1);
set_value(200);
set_hit_func(this_object());
}

init(){
  ::init();
  if(present("collectable_obj_fire")) {
    write("The Cleaver Shatters as it comes too close to a weapon of flame!\n");
    destruct(this_object());
    return 1;
  }
  add_action("collect_reward", "collect");
  add_action("cannotdo", "wield");
  add_action("cannotdo", "unwield");
  add_action("unwear", "unwear");
  add_action("unwear", "remove");
}

cannotdo() {
  write("What?\n"); return 1; 
}

wear(string str) {
  if(!id(str)) return 0;
  this_object()->wield("str");
  ::wield();
}

unwear(string str) {
  if(!id(str)) return 0;  
  this_object()->stopwield("str");
  ::stopwield();
}
  
weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(19);

if(W>16)  {
  say("\t"+BOLD+""+BLK+""+user+" holds the cleaver before"+
      " "+this_player()->query_objective()+" summoning forth a\n\n"+
      ""+HIC+"                             CYCLONE OF FROST "+NORM+"\n\n"+
      "\t\t"+BOLD+""+BLK+"which engulf's its victim with tendrils of pure pain!"+NORM+"\n");

  write(
  "\t"+BOLD+""+BLK+"Holding the cleaver before you, you summon forth a"+NORM+"\n\n"+
  ""+HIC+"                        CYCLONE OF FROST"+NORM+"\n\n"+
  "\t\t"+BOLD+""+BLK+" which engulf's your foe with tendrils of pure pain!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Cleaver drives into it's victim slamming them with"+
  " shards of "+HIC+"ICE!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Cleaver drives into your foe sending shards of"+HIC+" ICE"+NORM+""+
  ""+BOLD+""+BLK+" digging into their flesh!"+NORM+"\n");
  return 3;
   }
return;
}

int wield(string arg) {
  status wield_flag;
  status x;
  wield_flag = wielded;
  x = (int)::wield(arg);
  if(!wield_flag && wielded) {
    this_player()->RegisterArmor(this_object(), ({ "physical", 2, 0, "spec_def" }));   
  }
  return x;
}

int stopwield(string arg) {
  status wield_flag;
  status x;
  wield_flag = wielded;
  x = (int)::stopwield(arg);
  if(wield_flag && !wielded) {
    this_player()->RemoveArmor(this_object());
  }
  return x;
}

drop() {
  this_object()->stopwield("str");
  ::drop();
}

give() {
  this_object()->stopwield("str");
  ::give();
}

query_worn() { return wielded; }

spec_def(owner){
      tell_object(owner,  HIW+"\tTEST TEST TEST TEST.\n"+NORM+NORM);
      if(this_player() && this_player()!=owner)
         write("This is the room Test.\n");
      return 2+random(9);
}