#include "/players/maledicta/ansi.h"
#define EV environment()
#define QN query_name()
#define EA +BOLD+"Dark Aura"+NORM+
inherit "players/maledicta/weapon/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("aura");
set_short(BOLD+"Dark Aura"+NORM);
set_long(
"The Dark Aura is what appears to be a cloud of darkness.  At the center\n"+
"the aura is pure darkness, and it gets lighter as it radiates out.  The\n"+
"aura is constantly writhing about, almost as though it is alive.  To be\n"+
"able to harness the power of the aura, one would need to be a master of\n"+
"magic, and of an incredibly evil nature.  The aura is infinitely strong.\n");
set_type("aura");  
set_class(12);
set_weight(1);
set_value(0);
message_hit=({
    "unleashed the energy of the "EA" on","",
    "unleashed the energy of the "EA" on","",
    "focused the energy of the "EA" on","",
    "focused the energy of the "EA" on","",
    "focused the energy of the "EA" on","",
    "released the energy of the "EA" on","",
    "released the energy of the "EA" on","",
  });
add_special_fun("/players/maledicta/weapon/powers/neutral_slayer.c");
add_special_fun("/players/maledicta/weapon/powers/witchhunter.c");
add_special_fun("/players/maledicta/weapon/powers/fire.c");
add_special_fun("/players/maledicta/weapon/powers/mana_drain.c");
add_special_fun("/players/maledicta/weapon/powers/mana.c");
add_special_fun("/players/maledicta/weapon/powers/poison.c");
add_special_fun("/players/maledicta/weapon/powers/health.c");
add_special_fun("/players/maledicta/weapon/powers/lawful_slayer.c");
add_special_fun("/players/maledicta/weapon/powers/evil.c");

set_no_break(1);
set_hit_func(this_object());
}

extra_look()
{
  if(environment()->is_player()){
        if(environment()->query_weapon() == this_object()) return 
        "A "+BOLD+"Strange Darkness "+NORM+"swirls around "+EV->QN+"'s fist";
  }
}

get(){ if(this_player())
       if(this_player()->query_real_name() != "revenge") return 0;
       return 1; 
     }


weapon_hit(attacker){
if(random(100) < 25) return 10;
return 6;
}
