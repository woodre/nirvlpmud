#include "/players/jaraxle/ansi.h"

inherit "obj/armor";



reset(arg) {

set_name("shield");

set_alias("dragon shield");

set_short(GRN+"Shield of the "+HIG+"Drake"+NORM);

set_long(

  "  This shield is made from the tough green scales of\n"+

  "a Swamp Dragon.  It is lightweight and capable of\n"+

  "resisting great amounts of damage.\n");

set_ac(1+random(2));

set_type("shield");

set_weight(1);

set_value(1000);

set_params("other|poison", 2, 5, "do_poison");

set_params("other|water", 2, 5, "do_water");

}





	

do_poison(object owner){

    if(!random(3)){

       tell_object(owner,

       "The "+GRN+"Shield of "+HIG+"Drakes"+NORM+" resists the onslaught of "+MAG+"poison"+NORM+"!\n");

       return 0502;

      }

return 0;

}



do_water(object owner){

     if(!random(4)){

        tell_object(owner,

        "The "+GRN+"Shield of "+HIG+"Drakes"+NORM+" absorbs most of the "+HIC+"water"+NORM+" attack!\n");

        return 0502;

        }

return 0;

}

