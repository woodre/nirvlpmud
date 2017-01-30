/*********************************************************/ 
/*  
/*  Monk Guild Join Room
/*  28 SEP 2002
/*  version 2.01
/*  Updates since last version:
/*      * Cleanup of Code
/*      * Room description update
/*
/*********************************************************/

/*********************************************************/
/*
/*  Inherits and Includes
/*
/*********************************************************/
inherit "room/room";

/*********************************************************/
/*
/*  Global Variables
/*
/*********************************************************/
string WHAT;
string ME;

/*********************************************************/
/*
/* Reset()
/*
/*********************************************************/
reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The Foot of the Black Rock Mountains";
        long_desc=
            "A steep mountain path stretches ahead to the west, up the climbs of.\n"+
            "the Black Rock Mountains. The path looks well worn, but not recently\n"+
            "used. Small, knobby pines and scraggly brush line the path as it\n"+
            "twists up the side of the mountain. The path looks normal, but a\n"+
            "strange mist blocks the view as it jogs west further up. A small sign\n"+
            "stands to the side of the path, written in a steady hand.\n";

        dest_dir=({
            "/players/pain/NEW/tpath7", "east",
        });
        items = ({
            "sign", "*----------------------------------------*\n"+
                    "|                                        |\n"+
                    "|    W A R N I N G   T O   A L L ! !     |\n"+
                    "|                                        |\n"+
                    "|    You have found the hidden path,     |\n"+
                    "|    if this was your intent, then our   |\n"+
                    "|    congratulations, if not, beware!    |\n"+
                    "|    Many have sought this path, few are |\n"+
                    "|    worthy. If you believe you are of   |\n"+
                    "|    the chosen, you may attempt the     |\n"+
                    "|    following:                          |\n"+
                    "|                                        |\n"+
                    "|           join                         |\n"+
                    "|           help ranks                   |\n"+
                    "|                                        |\n"+
                    "|    If you no longer wish to follow the |\n"+
                    "|    the path you may:                   |\n"+
                    "|                                        |\n"+
                    "|           leave                        |\n"+
                    "*----------------------------------------*\n",
            "Mountains#mountains#mountain#Black Rock Mountains",
                    "The Black Rock Mountains rise to the west, their climbs shrouded by a faint mist",
        });
    }
}
/*********************************************************/
/*
/*  Init()
/*
/*********************************************************/
init() {
    ::init();
    add_action("west", "west");
    add_action("help_ranks","help");
    add_action("join_guild", "join");
    add_action("leave_guild","leave");
    add_action("get_robe","register");
}

/*********************************************************/
/*
/*  Functions
/*
/*********************************************************/

/*********************************************************/
/*
/* leave_guild()
/*      Removes the player from the Monk Guild.
/*
/*********************************************************/
leave_guild() {
    string me, name;
    object guild;
    int pgexp, exp, minus, rank, myrank, level, guild_exp, leave_time;
    me = this_player()->query_real_name();
    guild = present("mrobe", this_player());

     if(!guild) {
        write("You are not a member of this Guild.\n");
        return 1;
     }
     rank = guild->query_guild_rank();
     pgexp = this_player()->query_guild_exp();
     this_player()->add_guild_exp(-pgexp);
     this_player()->set_guild_name(0);
     this_player()->set_guild_file(0);
     myrank = this_player()->query_guild_rank();
     this_player()->add_guild_rank(-myrank);
     write("You are now no longer a member of the Guild.\n");
     say(capitalize(me)+" has left the Guild.\n");
     if(this_player()->query_level() < 2000) {
        name = me;
        level = this_player()->query_level();
        guild_exp = guild->query_guild_exp();
        leave_time = ctime(time());
        write_file("/players/pain/closed/guild/PROMOS",
            "\n"+name+"("+level+") quit the Monks - "+leave_time+"\n\n");
    }
    exp = this_player()->query_exp();
    minus = exp/4;
    this_player()->add_exp(-minus);
    destruct(guild);
    WHAT = "quit";
    ME = this_player()->query_real_name();
    tell_members();
    this_player()->set_home("/room/church");
    return 1;
}

/*********************************************************/
/*
/*  join_guild()
/*      Adds the player to the Monk Guild
/*
/*********************************************************/
join_guild() {
    object ob;
    object gary;
    int myrank, myexp;
    string me;
    me = this_player()->query_real_name();

    if(present("mrobe", this_player())) {
        write("You are already a member.\n");
        return 1;
    }

    if(restore_object("players/pain/closed/banned/"+me)) {
        write("You have been banished from the Guild.\n");
        write("If you wish to re-enter you must petition the Guildmasters.\n");
        return 1;
    }

    if(this_player()->query_npc() == 1) {
        write_file("players/pain/closed/guild/CHEAT",
            "\n"+this_player()->query_real_name()+" was dested"+
            ctime()+"\n\n");
        destruct(this_player());
        write("NOPE!");
        return 1;
    }

    if(this_player()->query_guild_exp() > 0) {
        write("You may only be a member of one guild!\n");
        return 1;
    }

    if(this_player()->query_level() < 6) {
        write("You must be at least 6th level to join this guild.\n");
        return 1;
    }

    if(!present("recruit",this_player())) {
        write("You must be recruited by a level 6 or higher monk to join the guild.\n"+
        "Go find one, and see if they will recruit you.\n");   
        return 1;
    }

    move_object(clone_object("players/pain/closed/guild/testobj.c"), this_player());
    ob = present("recruit",this_player());
    destruct(ob);
    myexp = this_player()->query_guild_exp();
    this_player()->add_guild_exp(-myexp);
    this_player()->add_guild_exp(1);
    myrank = this_player()->query_guild_rank();
    this_player()->add_guild_rank(-myrank);
    this_player()->add_guild_rank(1);
    this_player()->set_guild_name("monk");
    write("You have now joined the Guild.\n");
    write("Type 'mhelp dir' for information on your new abilities.\n");
    say(capitalize(me)+" has joined the Guild.\n");
    WHAT = "joined";
    ME = this_player()->query_real_name();
    write_file("/players/pain/closed/guild/PROMOS",
    "\n"+this_player()->query_real_name()+" joined the Monks - "+
    ctime()+"\n\n");
    tell_members();
    return 1;
}

/*********************************************************/
/*
/*  help_ranks(str)
/*      Shows the player the Monk Guild Ranks help file
/*
/*********************************************************/
help_ranks(str) {
    if(str == "ranks") {
        cat("/players/pain/closed/guild/help_ranks");
        return 1;;
    }
}

/*********************************************************/
/*
/*  tell_members()
/*      Informs the Monk Guild members of new happenings
/*
/*********************************************************/
tell_members() {

    object ob, guild, monk;
    int i;
    string me;
    ob = users();

    for(i = 0; i < sizeof(ob); i++) {
        guild = present("mrobe", ob[i]);
        if(guild) {
            tell_object(ob[i],
            "[*Master Monk*]: "+capitalize(ME)+" has "+WHAT+" the Monks!\n");
        }
    }
    return 1;
}

/*********************************************************/
/*
/*  get_robe
/*      Restores a robe to a Monk Guild member if they 
/*      should lose theirs
/*
/*********************************************************/
get_robe() {

    object ob, obj, robe;
    ob = this_player();
    
    if(present("mrobe", ob)) {
        write("You already have a Monk Robe!\n"); 
        return 1; 
    }
    if(ob->query_guild_name() == "monk") {
        robe = clone_object("players/pain/closed/guild/testobj");
        move_object(robe, ob);
        write("You are given new robes!\n"+
            "Welcome back!\n");
        command("mend", ob);
        return 1;
    } 
    else {
        write("You are not a member of this guild!\n");
        return 1;
    }
}

/*********************************************************/
/*
/*  west()
/*      Moves the player west if he/she is in the Monk
/*      Guild
/*
/*********************************************************/
west() {

    if(present("mrobe", this_player())) {
        move_object(this_player(), "players/hawkeye/closed/guild/guild_room.c");
        say(capitalize(this_player()->query_real_name())+ " arrives.\n");
        command("look", this_player());
        return 1;
    }

    write("SSSSSLAAAMM!\n"+
        "When you try and set your feet upon the sacred ground\n"+
        "of the Monk's guild, you are sizzled by a bolt of\n"+
        "lightening from the sky!\n");
    say(capitalize(this_player()->query_real_name())+" got struck by "+
        "a bolt of\nlightening when they foolishly tried to enter the "+
        "sacred\nGuild hall of the Monks!\n");
    return 1;
}
