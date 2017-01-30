/*  Red Dragon Scales - Worth 1k each. */



inherit "obj/treasure";

#include "/players/jaraxle/ansi.h"





reset(arg){

 if(arg) return;

set_id("dragonscale");

set_alias("shardak_dragon_scale");

set_short(RED+"a dragonscale"+NORM);

set_long(

"This is a large scale from a Red Dragon. It can be\n"+

"sold, or perhaps you might find another use for it.\n");

set_weight(1);

set_value(1000);

}



id(str){ return str == "scale" || str == "dragonscale" || 

                str == "shardak_dragon_scale";  } 



