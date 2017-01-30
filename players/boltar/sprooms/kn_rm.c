#include "std.h"
object knight,chainmail,blade;
   /* This is the knight room from kanteles, for me as a player the demon
   * blade was one of the best and most creative weapons in the game
   * so I have recreated here.
  */

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
   if (!knight || !living(knight)) {
       knight = clone_object("obj/monster");
       call_other(knight, "set_name", "knight");
       call_other(knight, "set_short", "A black knight is here");
       call_other(knight, "set_whimpy");
       call_other(knight, "set_al",- 600);
       call_other(knight, "set_hp",666);
       call_other(knight, "set_wc",25);
       call_other(knight, "set_ac", 9);
       call_other(knight, "set_aggressive", 1);
       call_other(knight, "set_level", 19);
     move_object(knight, this_object());
     chainmail = clone_object("obj/armor");
        call_other(chainmail, "set_ac",4);
        call_other(chainmail, "set_alias","armor");
        call_other(chainmail, "set_type","armor");
        call_other(chainmail, "set_alias","mail");
        call_other(chainmail, "set_name", "chainmail");
        call_other(chainmail, "set_value", 800);
        call_other(chainmail, "set_short", "A death black chainmail");
        call_other(chainmail, "set_weight",4);
        move_object(chainmail, knight);
        blade = clone_object("obj/weapon");
    call_other(blade, "set_name", "A black demon blade");
    call_other(blade, "set_short", "A black demon blade");
    call_other(blade, "set_hit_func", this_object());
    call_other(blade, "set_alt_name", "blade");
    call_other(blade, "set_value",5000);
    call_other(blade, "set_wield_func", this_object());
    call_other(blade,"set_alias","sword");
    move_object(blade, knight);
    }
 }

ONE_EXIT("players/boltar/lv1/k_ent.c", "north",
          "knights room",
   "This is a rather small room.  The walls are painted the darkest black\n"+
   "you have ever seen. In the corner appears to be someone's bed as well as \n"+
   "a desk and a chair, all done in the same color black.\n", 1)

wield(weap) {
    int alig,evil;
    alig = call_other(this_player(),"query_alignment");
    if(alig > 0) {
        write("The blade gives you an electric jolt.\n");
        write("The blade don't like you, you're too stinking good.\n");
        call_other(this_player(),"hit_player",20);
        return 0;
        } else {
        if (evil ==0) {
            evil =1;
            call_other(this_player(),"add_alignment",-10);
            write("You feel more evil.\n");
            }
        return 1;
        }
}

weapon_hit(attacker) {
    int alig,dam;
    alig = call_other(attacker,"query_alignment");
    if(alig > 0){
	dam = random(25);
	if(dam < 10)
	    return dam;
	if(dam < 15)
	    write("The blade flashes.\n");
	else if(dam < 20)
	    write("The blade flashes happily.\n");
	else if(dam < 24)
	    write("The blade flashes happily, and gives out a happy cry.\n");
	else if(dam == 24) {
	    write("The blade flashes happily, and you can feel its evil might.\n");
	    tell_room(this_object(),
		      "The black demon blade flashes !\n");
	    call_other(this_player(),"heal_self",random(10));
	    write("You feel stronger.\n");
	    dam = dam + random(20);
	    if (dam == 43) {
		write("And the blade flashes.\n");
		call_other(this_player(),"heal_self",random(10));
		write("You feel stronger.\n");
		tell_room(this_object(),
			  "The black demon blade flashes, and gives out a happy cry.\n");
	    }
	}
	return dam;
    }
    dam = random(15);
    return dam;
}
