#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

     set_name("rainmaker");
     set_alias("rainmaker");
     set_short(HIB+"Rainmaker"+NORM);
     set_long(
	"A traditional ceremonial instrument made from dried cactus, \n"+
        "thorns and pebbles.  As you move it, the pebbles inside \n"+
        "dance around to create the water sound.  The Anasazi shaman \n"+
        "used it to conjure rain and good fortune on the tribe.  It \n"+
        "might make a good weapon also.  \n");
     set_type("staff");
     set_class(17);
     set_weight(3);
     set_value(1000);
     set_hit_func(this_object());
}

  weapon_hit(attacker){
     int W;
       object theroom;
       theroom=environment(wielded_by);
     W = random(11);
     if(W>8)  {
       tell_room(theroom,"\n");
       tell_room(theroom,"Large "+HIB+"HAILSTONES"+NORM+" fall from the sky as the "+HIB+"RAINMAKER"+NORM+" vibrates and sings.\n");
       tell_room(theroom,"\n");
       tell_room(theroom,HIW+"         `       *      `    *     `     *     `     *\n");
       tell_room(theroom,    "            `        *    `      *    `     *\n");
       tell_room(theroom,    "              *       `    *      `    *     `  *\n");
       tell_room(theroom,    "           `       *    `      *     `     *     ` *\n");
       tell_room(theroom,    "                `       *     `     *     `    *\n");
       tell_room(theroom,    "          `    *      `      *   `       `  *    `   *\n");
       tell_room(theroom,    "             `       *      `      *    `      *\n");
       tell_room(theroom,    "             `    *   `     *    `       *       `     *\n");
       tell_room(theroom,"\n"+NORM);
       return 7;
   }

    if(W>5)  {
       tell_room(theroom,"\n");
       tell_room(theroom,"A strong"+HIB+" RAINSTORM "+NORM+"breaks loose as the "+HIB+"RAINMAKER"+NORM+" finds its mark...\n");
       tell_room(theroom,"\n");
       tell_room(theroom,"\n");
       tell_room(theroom,RED+"         T   H   U   N   D   E   R         B   O   O   M   S\n");
       tell_room(theroom,"\n"+NORM);
       return 0;
   }

    if(W>2)  {
       tell_room(theroom,"\n");
       tell_room(theroom,"The "+HIB+"RAINMAKER"+NORM+" jingles and the "+HIB+"GODS of the Anasazi"+NORM+" become angered.\n");
       return -1;
   }
}

/* Added by Snow 7/99 */
two_handed() { return 1; }
