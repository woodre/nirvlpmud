/*  Okay, this requires 4 dragons scales: id() = shardak_dragon_scale
    + 1.5k coins.   Nice fire resistance.  */


#include "/players/maledicta/ansi.h"
#define USER environment()

inherit "obj/armor";

reset(arg){
 if(arg) return;
 ::reset(arg);

set_id("dragonplate");
set_name("plate");
set_alias("dragonplate");
set_short(RED+"Dragon"+HIW+"plate Armor"+NORM);
set_long(
  "  This is a lightweight set of fullplate armor\n"+
  "made from the scales of a red dragon.  It is\n"+
  "covered with shards of dragon teeth, offering\n"+
  "offensive as well as considerable defensive\n"+
  "potential.\n");
set_ac(4);
set_params("other|fire", 2, 12, "fire_special");
set_type("armor");
set_weight(2);
set_value(1000);
}

fire_special(owner){
if(USER->query_guild_name() != "shardak") return 0;
if(!random(10)){
  tell_object(USER,
  HIW+"Your "+NORM+RED+"Dragonplate"+HIW+" resists the fire!\n"+NORM);
  return 2005;
  }
return 0;
}	

