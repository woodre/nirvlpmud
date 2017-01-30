#include "/players/zeus/closed/all.h"
inherit "/obj/monster.c";
int dmg,rounds;
int max;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_level(20);
   set_name("npc");
     SetMultipleIds( ({ "dmg npc", "damage npc", "dmgnpc" }) );
   set_short("A dmg npc");
   set_long(0);
   set_hp(1000);
  set_wc(0);
   set_ac(0);
   set_al(0);
   dmg=0;
   rounds=0;
   
   
   
  move_object(clone_object("/players/snow/WEAPONS/hon_sword"), this_object());
  move_object(clone_object("/players/vertebraker/misc/cj/cj_face"), this_object());  
  move_object(clone_object("/players/dragnar/WalkingDead/armor/swat_vest"), this_object());
  move_object(clone_object("/players/valen/area/catacombs/armors/d_belt"), this_object());
  move_object(clone_object("/players/tallos/7tigers/objects/dragon_legs"), this_object());
  move_object(clone_object("/players/eurale/Chess/OBJ/ring"), this_object());
  move_object(clone_object("/players/zeus/desert/OBJ/cloak"), this_object());
  move_object(clone_object("/players/jareel/armor/humakt/humakt_necklace"), this_object());
  move_object(clone_object("/players/vertebraker/swamp/OBJ/denim_shorts"), this_object());
  move_object(clone_object("/players/angel/area/school/obj/flow_scarf_01"), this_object());
  move_object(clone_object("/players/jenny/wings/items/sblocker"), this_object());
  move_object(clone_object("/players/dragnar/WalkingDead/armor/boots"), this_object());
  move_object(clone_object("/players/jareel/armor/DWARFFORGE/demon/misc"), this_object());
  move_object(clone_object("/players/jareel/armor/DWARFFORGE/demon/amulet"), this_object());
  move_object(clone_object("/players/jareel/armor/DWARFFORGE/demon/earring"), this_object());
  move_object(clone_object("/players/maledicta/cont/rdragon/sbracers"), this_object());
  move_object(clone_object("/players/khrell/armors/skaven/warparmor"), this_object());
  
  command("ready", this_object());
   
      
   
   }
id(str){ return str == "npc"; }
init() {
   ::init();
   add_action("damage","damage");
   add_action("reset_cmd","reset");
   add_action("beat","beat");
}
heart_beat() {
   if(attacker_ob) {
      dmg += 1000-hit_point;
      rounds++;
say("Damage was "+HIG+(1000-hit_point)+NORM+".  Average is "+
HIG+(dmg/rounds)+"."+((dmg-((dmg/rounds)*rounds))*1000)/rounds+NORM+"\n");
write("Damage was "+HIG+(1000-hit_point)+NORM+".  Average is "+
HIG+(dmg/rounds)+"."+((dmg-((dmg/rounds)*rounds))*1000)/rounds+NORM+"\n");
      if((1000-hit_point) > max) max=1000-hit_point;
      heal_self(1000);
   }
  ::heart_beat();
}

damage() {
   if(rounds==0) return 0;
   write("Damage: "+dmg+"\n");
   write("Rounds: "+rounds+"\n");
   write(
"Average: "+(dmg/rounds)+"."+((dmg-((dmg/rounds)*rounds))*1000)/rounds+"\n");
   write("Max: "+max+"\n");
   write("\"reset\" to reset\n");
   return 1;
}
reset_cmd() {
   write("Ok.\n");
   dmg=0;
   rounds=0;
   return 1;
}
beat(str) {
   if(attacker_ob) return 0;
   if(!str) return 0;
   if(present(str) && living(present(str))) {
      attack_object(present(str));
      attack();
   return 1;
   }
}
