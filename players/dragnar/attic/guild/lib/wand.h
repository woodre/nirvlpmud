#include "/players/dragnar/guild/defs/def.h"
wand(str) {
	     int amount, COIN;
        object wand;
        if(!str) {
        write("How many gold coins to you want to use?\n");
        return 1; }
        if(!sscanf(str, "%d", amount)) {
        write("You must specify the number of gold coins you want to use.\n");
        return 1; }
        if(amount < 1) {
        write("Shardak forbids you to dishonor him by cheating.\n");
        return 1; }
        if(user->query_money() < amount) {
        write("You do not have enough gold coins to sacrifice.\n");
        return 1; }
	     COIN = (amount/10);
        wand=clone_object("/players/dragnar/guild/items/wand.c");
        move_object(wand, this_player());
        wand->set_amt(COIN);
	     write("You summon a Wand of Acid from the depths of hell.\n");
	     say(capname+" summons a Wand of Acid from the depths of hell.\n"+
	     "You cringe in fear.\n");
        this_player()->add_money(-amount);
        return 1;
}       
