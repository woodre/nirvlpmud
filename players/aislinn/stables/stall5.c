#include "std.h"

object crook;
 
#undef EXTRA_RESET 
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!crook || !living(crook)) {
  object gloves, boots, saddlebags;
    crook=clone_object("obj/monster");
    call_other(crook,"set_name","player");
    call_other(crook,"set_alias","crook");
    call_other(crook,"set_level",16);
    call_other(crook,"set_hp",500);
    call_other(crook,"set_wc",20);
    call_other(crook,"set_ac",12);
    call_other(crook,"set_al",-270);
    call_other(crook,"set_short","A crooked Polo player");
    call_other(crook,"set_long",
      "A Polo player looks warily at you.  He is not too tall, but looks\n" +
      "strong and mean.  He is wearing some nice riding boots, some \n" +
      "riding gloves and is carrying saddlebags over his shoulder.\n",1);
    move_object(crook,this_object());
    gloves=clone_object("obj/armor");
    call_other(gloves,"set_name","gloves");
    call_other(gloves,"set_alias","riding gloves");
    call_other(gloves,"set_short","A pair of leather riding gloves.");
    call_other(gloves,"set_long",
      "A pair of finely made, suede riding gloves.  There are light brown\n" +
      "in color, there is a fringe along the outside edge and the palms\n" +
      "are reinforced.\n");
    call_other(gloves,"set_value",70);
    call_other(gloves,"set_weight",1);
    call_other(gloves,"set_ac",1);
/*
    call_other(gloves,"set_type","glove");
Chg'd for nirvana */
    call_other(gloves,"set_type","gloves");
    transfer(gloves,crook);
    call_other(crook,"init_command","wear gloves");
    boots=clone_object("obj/armor");
    call_other(boots,"set_name","boots");
    call_other(boots,"set_alias","riding boots");
    call_other(boots,"set_short","A finely tooled pair of riding boots.");
    call_other(boots,"set_long",
      "A pair of riding boots which are somewhat worn, but still have\n" +
      "plenty of use left in them.\n");
    call_other(boots,"set_ac",1);
    call_other(boots,"set_value",700);
    call_other(boots,"set_weight",2);
/*
    call_other(boots,"set_type","boot");
Chgd for nirvana -Bp
*/
    call_other(boots,"set_type","boots");
    transfer(boots,crook);
    call_other(crook,"init_command","wear boots");
    saddlebags=clone_object("players/aislinn/objects/saddlebags");
    call_other(saddlebags,"set_id","saddlebags");
    call_other(saddlebags,"set_alias","bag");
    call_other(saddlebags,"set_short","leather saddlebags");
    call_other(saddlebags,"set_long",
      "Leather saddlebags which look like they would hold alot.\n");
    call_other(saddlebags,"set_weight",2);
    call_other(saddlebags,"set_value",30);
    move_object(saddlebags,crook);
    }
}
ONE_EXIT("players/aislinn/stables/stable3", "east",
	 "Tack Room",
    "This is a stall which has been converted to serve as a tack room.\n" +
    "There are 2 chairs and a small table in one corner, with a whip\n" +
    "which is in the process of being repaired on top of the table.  A\n" +
    "collection of ribbons and awards line on wall, and a small bed is\n" +
    "nearly buried under a pile of reins and harnesses.\n" +
    "    \n", 1)
