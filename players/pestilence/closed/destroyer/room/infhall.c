#include "/players/pestilence/define.h"
inherit "room/room";

#define num_skill 7
int minexp,expcost,expcost2;
int current;
object guild_ob;
object owner;

reset(arg) {
        if(!present("templar_trainer")){
                owner = clone_object("/players/pestilence/closed/destroyer/mob/kaliz.c");
                move_object(owner, this_object());
        }
        if (arg) return;
        set_light(1);
        long_desc =
        "  This is the training hall of the Destroyers.  Large Stone blocks\n"+
        "sit in the corners of the room.  This part of a complex of the guild hall.\n"+
        "Members of the guild can come here to 'advance' their 'rank'.\n"+
        "The room is rather large and hold many old weapons.\n";
        items = ({
                  "blocks","Large stone blocks, that appear to have been assualted with weapons",
                  "stone blocks","Large stone blocks, that appear to have been assualted with weapons",      
                  "stone","Large stone blocks, that appear to have been assualted with weapons",
                  "cave","A large cave encased in stone",
        });
        
        dest_dir = ({
                        "/players/pestilence/closed/destroyer/room/hall.c","west",
        
});
}

short() {
    return ""+YEL+"Infantry Hall"+NORM+"";
}

init(){
        ::init();
if(this_player())
if(present("warrior_gob", this_player())) return;
        add_action("cost_for_level","cost");
        add_action("train","train");
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }







int next_level;
int valexp;
int next_exp;
int title;
int rankxp;
int combatxp;
int level;
int exp;
object player_ob;
int exp_str;

train(str) {
        if (this_player()->query_guild_name() != ">A.o.P<") {
                write("You do not belong to this guild.\n");
                return 1;
        }
        

        if(!str) {
                write("You must type train infantry.\n");
                return 1;
        }
        if(present("destroyer_ob",this_player())->query_bomb()) {
                write("I'm sorry your already in the explosions group.\n");
                return 1;
        }
        if(!present("templar_trainer", this_object())){
                write("You do not see a trainer here.\n");
                return 1;

        }
        
        if(str=="infantry") {
                guild_ob=present("destroyer_ob",this_player());
                if(!guild_ob) {
                        write("You do not have the proper dna to advance here.\n");
                        return 1;
                }
                current = guild_ob->query_infantry();
                if(current > 9) {
                        write("You have reached the highest infantry level within the Army.\n");
                        return 1;
                }
                expcost = get_rank_exp(current + 1)-get_rank_exp(current);
                if(this_player()->query_extra_level() < 1 && this_player()->query_level() < 21)
                minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",this_player()->query_level()-1);
                if(this_player()->query_extra_level() > 0 && this_player()->query_level() < 21)
                minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);

                if(this_player()->query_level() > 20) minexp = 7000000; 
                if(expcost > minexp) {
                        write("You do not have enough available experience to to advance your infantry.\n");
                        return 1;
                }
                this_player()->add_guild_exp(expcost);
                this_player()->add_exp(-expcost);
                present("destroyer_ob", TP)->add_infantry(1);
                this_player()->save_me();
                command("dsave",this_player());
                command("set_title",this_player());
                write("The trainer holds you down, and injects some enhanced dna into your body.\n"+
                   "Your level advances along with your dna quality.\n");
                say(this_player()->query_name()+" is held down by the trainer, where they are injected with a needle.\n"+
               ""+this_player()->query_name()+" advances level along with dna quality.\n");
                return 1;
        }
 
}

correct_level(player)
{ 
        level = call_other(player, "query_level", 0);

        exp = call_other(player, "query_exp", 0);
        /* Shouldn't "correct" wizards. */
        if (level >= 20)
        return;
        get_level(level);
        while (exp < next_exp) {
                level -= 1;
                get_level(level);
        }
        if (next_level == 20 && call_other("room/quest_room", "count", 0))
        next_level = 19;
        call_other(player, "set_level", next_level);
        call_other(player, "set_title", title);
}

realm() { return "NT"; }

cost_for_level() {
        call_other("room/adv_guild","cost_for_level",0);
        return 1;

}
get_rank_exp(arg) {
        rankxp=allocate(11);
        rankxp[1] = 0;
        rankxp[2] = 275000;
        rankxp[3] = 750000;
        rankxp[4] = 1500000;
        rankxp[5] = 3000000;
        rankxp[6] = 4750000;
        rankxp[7] = 6500000;
        rankxp[8] = 8500000;
        rankxp[9] = 10750000;
        rankxp[10] = 14000000;
        return rankxp[arg];
}
