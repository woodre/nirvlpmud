#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A chrysanthemum");
   set_long("A full flower with a bright yellow center, surrounded by thin, pointed, red petals.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "chrysanthemum" || str == "flower"; }

