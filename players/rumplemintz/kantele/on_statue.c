
#include "std.h"
int eyes;
object diamond,shagath;


id(str) {
return str == "diamond" || str =="eye" || str == "eyes" || str=="statue";
        }

#undef EXTRA_INIT
#define EXTRA_INIT add_action("get_diamond"); add_verb("pry");

#undef EXTRA_RESET
#define EXTRA_RESET\
eyes =2;\

#undef EXTRA_LONG
#define EXTRA_LONG\
    if (eyes == 1)\
write("The Statue of Kali looks at you with one diamond eye.\n");\
    if (eyes == 2)\
write("The Statue of Kali looks at you with two burning diamond eyes.\n");\
    if (eyes == 0)\
write("The Statue of Kali looks at you with two empty eye sockets.\n");\

ONE_EXIT("players/kantele/behind_altar","down",
         "You are on the statue",
         "You are on the statue, cou can climb down.\n",1)

get_diamond(arg) {
    if (eyes > 0 && arg =="of eye" || eyes > 0 && arg =="of eyes") {
       eyes = eyes-1;
       write("you pry of a diamond eye.\n");
say(call_other(this_player(), "query_name") + " pryes of a diamond eye.\n");
       diamond  = clone_object("obj/treasure");
       call_other(diamond, "set_id", "diamond");
       call_other(diamond, "set_short", "A huge glittering diamond");
       call_other(diamond, "set_weight", 1);
       call_other(diamond, "set_value", random(2000));
       call_other(diamond, "set_alias", "gem");
       move_object(diamond, this_object());
       if (eyes == random(3)) {
           summon_avatar();
           }
      return 1;
       }
}


summon_avatar() {
if (!shagath || !living(shagath)) {
shagath  = clone_object("obj/monster");
call_other(shagath, "set_name", "shagath");
call_other(shagath, "set_alias", "avatar");
call_other(shagath, "set_level",19);
call_other(shagath, "set_al", -300);
call_other(shagath, "set_short", "Shagath the avatar of Kali is here");
call_other(shagath, "set_wc",30);
call_other(shagath, "set_ac",5);
call_other(shagath, "set_aggressive", 1);
call_other(shagath, "set_chance",40);
call_other(shagath, "set_spell_mess1",
     "Shagath throws Hellfire at you.");
call_other(shagath, "set_spell_mess2",
     "You are hit by the Hellfire");
call_other(shagath, "set_spell_dam",60);
move_object(shagath, behind_altar);
}
write("You are shaken down from the statue !\n");
call_other(this_player(), "move_player", "X#players/kantele/behind_altar");
tell_room(behind_altar,"The Whole Temple shakes You can feel the Wreath of Kali !\n");
tell_room(behind_altar,"Shagath the avatar of Kali arrives in a puff of smoke !\n");
}
