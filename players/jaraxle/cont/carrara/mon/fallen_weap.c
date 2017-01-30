#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";
string name;
reset(arg) {
   switch(random(5)){
      case 0 : name = "Gryfin";
      break;
      case 1 : name = "Hawk";
      break;
      case 2 : name = "Talon";
      break;
      case 3 : name = "Vulture";
      break;
      case 4 : name = "Phoenix";
      break;
   }
   ::reset(arg);
   if (arg) return;
   set_name("fall_weap");
   set_alias("sword");
   set_type("sword"); 
   set_short(name+", the longsword "+BLK+BOLD+"[Wrapped in a Shadow]"+NORM);
   set_long("A short sword with a sterling silver blade.\n"+
      "The blade of the sword glows a bright blue\n"+
      "when reflecting the bright rays of the sun.\n");
   set_class(18);
   set_weight(2);
   set_value(2500);
   set_hit_func(this_object());
   message_hit=({""+BLK+BOLD+"slashed"+NORM+""," with their "+name+""+NORM+"","drives their "+name+" into"," ",""+BLK+BOLD+"stabs"+NORM+""," with their "+name+"",""+BLK+BOLD+"cleaves"+NORM+""," with their "+name+"","brings their "+name+" down into"," ","plunges their "+name+" into"," ","sliced"," lightly, with theif "+name+""});
}
weapon_hit(attacker){
}

drop(){ destruct(this_object()); return 1; }
