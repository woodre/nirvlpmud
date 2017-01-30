#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";
int collectable;
reset(arg){
  ::reset(arg);
  if (arg) return;
set_collectable(1);
set_name("trident");
set_alt_name("collectable_obj");
set_alias("icebrand");
set_short(""+BOLD+""+BLK+"Chu'Sarth Trident"+HIB+" [Icebrand]"+NORM+"");
set_long(
  "  Looking at this wicked weapon you see a spectre of what the\n"+
  "owner must have been like. Cold, deadly, and evil. The weapon\n"+
  "is covered with a light frost which never seems to diminish,\n"+
  "even at the touch of warmth.\n");

set_type("trident");  
set_class(17);
set_weight(3);
set_value(200);
set_hit_func(this_object());
}

init(){
    ::init();
    if(present("collectable_obj_fire")){
    	write("The Trident Shatters as it comes too close to a weapon of flame!\n");
    	destruct(this_object());
    	return 1;
    	}
     }
set_collectable(int n){ collectable = n; }
query_collectable(){ return collectable; }

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(19);

if(W>16)  {
  say("\t\t"+BOLD+""+BLK+""+user+"'s Trident summons forth a powerful\n\n"+
      ""+HIB+"                             CYCLONE OF FROST "+NORM+"\n\n"+
      "\t"+BOLD+""+BLK+"which engulf's its victim with tendrils of pure pain!"+NORM+"\n");

  write(
  "\t\t"+BOLD+""+BLK+"Your Trident summons forth a"+NORM+"\n\n"+
  ""+HIB+"                        CYCLONE OF FROST"+NORM+"\n\n"+
  "\t"+BOLD+""+BLK+" which engulf's your foe with tendrils of pure pain!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s trident drives into it's victim slamming them with"+
  " shards of "+HIB+"ICE!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Trident drives into your foe sending shards of"+HIB+" ICE"+NORM+""+
  ""+BOLD+""+BLK+" digging into their flesh!"+NORM+"\n");
  return 3;
   }
return;
}
