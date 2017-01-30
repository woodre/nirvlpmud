#include "/players/dragnar/guild/defs/def.h"
shield(str) {
        object shieldmax;
        int cost, AC, amount, t_pac;
	     if(!str) {
        write("How strong do you want your shield to be? (1-10)\n");
        return 1; }
	     sscanf(str, "%d", amount);
        if(amount < 1 || amount > 10) {
        write("You must specify a number between 1 - 10.\n");
        return 1; }
        t_pac = this_player()->query_ac();
        if(t_pac > 9) {
        write("You already have sufficiant armor.\n");
        return 1; }
        if((t_pac + amount) > 9) { amount = (10 - t_pac); }
        cost = (amount * 20);
        AC = amount;
        if(usp < cost) {
        write("You do not have enough spell points to sacrifice.\n");
        return 1; }
        shieldmax = clone_object("/players/dragnar/guild/items/shield.c");
        move_object(shieldmax, user);
        shieldmax->set_class(AC);
        shieldmax->set_rank(RANK);
        write("A cloud of darkness surrounds you.\n");
        say("A cloud of darkness suddenly surrounds "+capname+".\n");
        this_player()->add_spell_point(-cost);
        this_player()->set_ac(t_pac + AC);
        return 1;
        }
