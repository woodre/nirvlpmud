/*
 * Shardak guild - (tm) Dragnar/John
 * Advancement room is (c) Balowski/Rasmus, April 3rd 1995.
 * log:
 * 950415 corrected xp calc in advance() again
 * 950421 use ROOM
 * 2000 verte greatly increased xp needed, fixed typo
 */
#include "/players/balowski/lib.h"
#include "../macros.h"
#include "../def.h"
#include "../tasks.h"
#include "/players/vertebraker/ansi.h"

inherit ROOM;

void
create ()
{
    ::create();

    set_short("Altar");
    set_long("\
The floor here is a mixture of dark brown stone tiles. In the farthest\n\
wall, scores of yellow wax candles are burning in the recesses of the \n\
rock. It is rather cramped here, mainly due to the low opening leading \n\
into this natural hollow from the east. There is a massive, grey, stone \n\
slab that is shaped like an altar.\n");
    set_items(([ 
	({ "altar", "slab", "stone" }):"\
The rough stone altar is littered with runic inscriptions, except for\n\
the "+RED+"blood"+NORM+" stained top surface which is blank and smooth.\n",
	({ "floor", "tiles" }):"\
The tiles on the floor are cut from porphyry, stone in hues "+HIY+"brown"+NORM+"\n\
to dark "+HIR+"red"+NORM+" born in the volcanoes millions of years ago.\n",
	({ "candles", "recesses", "wall" }):"\
"+YEL+"Yellow"+NORM+" wax candles are guttering in every recess of the wall.\n",
    ({ "rock", "hollow", "here" }):"\
The very room has been hollowed out of the rock by some great force.\n",
    ({ "opening", "east" }) : "\
The low opening that led to this room opens up above you.\n",
    ]));
    set_exits(([
	"east" : PATH + "grotto",
	]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

void
reset(int arg)
{
    object priest;

    ::reset(arg);

    if (!present("priest", this_object())) {
	priest = clone_object(PATH + "priest");
	priest->move_player("in#" + file_name(this_object()));
    }
}

void
init()
{
    ::init();
    add_action("trials", "trials");
    add_action("hint", "hint");
    add_action("advance", "advance", 3);
    add_action("title", "title");
}

status
trials()
{
    object          guild;
    int             solved;

    guild = present(GUILD_ID, this_player());
    if (guild) {
	write("Unsolved tasks:\n");
	if ((int) guild->query_solved(CORPSE_TASK) == 0)
	    write("Provide a fresh corpse for the Priest.\n");

	if ((int) guild->query_solved(TELEPORT_TASK) == 0)
	    write("Provide teleportation to the Merchant.\n");

        if ((int) guild->query_solved(FLAMES_TASK) == 0)
            write("Light an eternal torch from the "+HIY+"E"+YEL+"t"+RED+"e"+HIR+"r"+YEL+"n"+HIY+"a"+HIR+"l"+NORM+" Flame and bring it to the Pyromancer.\n");
	if ((int) guild->query_solved(AVENGER_TASK) == 0)
	    write("Retrieve the Holy Avenger.\n");

	if ((int) guild->query_solved(DRAGON_TASK) == 0)
	    write("Tame the Dragon Keeper's beast.\n");

	if ((int) guild->query_solved(CHILD_TASK) == 0)
	    write("Sacrifice your child to Shardak.\n");

    } else
	write("Intruder, Be Gone!\n");
    return 1;
}

status
hint (string str)
{
    int             n;
    if (str && sscanf(str, "%d", n)) {
	if (n >= 1 && n <= 8) {
	    write("\
Find the tutor within the guild domain and say \"What is your task?\"\n");
	    return 1;
	}
    }
    notify_fail("Supply a number between 1 and 8.\n");
    return 0;
}

int
get_next_exp (int level)
{
    switch (level)
    {
	  case 1: return 0;
        case 2: return 49192;
        case 3: return 228568;
        case 4: return 640000;
        case 5: return 1376345;
        case 6: return 2554280;
        case 7: return 4345672;
        case 8: return 6456782;
    }
}

string
get_next_title (int level)
{
    switch (level) {
        case 1: return "the Shardak Novitiate";
        case 2: return "the Initiate of Hellfire";
        case 3: return "the Apostle of Shardak";
        case 4: return "the " + BOLD + BLK + "Necrolyte" + NORM;
        case 5: return "the Summoner of " + BOLD + BLK + "Dragons" + NORM;
        case 6: return "the " + BOLD + BLK + "Head Assassin" + NORM;
        case 7: return "the Controller of " + HIR + "Dragonbreath" + NORM;
        case 8: return "the " + BOLD + "GateKeeper of the UnderWorld" + NORM;
        case 50..100: return "a Magus of Shardak";
        default: return "the Servant of Shardak";
    }
}

string
get_next_class_title (int level)
{
  switch (level) {
       case 26: return "the "+ BOLD +"Warrior of Shardak" + NORM;
       case 27: return "the "+ RED +"Assassin of Shardak" + NORM;
       case 28: return "the "+ RED +"Berzerker" + NORM;
       case 41: return "the "+ BOLD +"Warlord of Shardak" + NORM;
       default: return 0;
       }
}

status
title (string str)
{
    object titles;
    if(str)
    if (str == "class"){
     if (!present(GUILD_ID, this_player())) {
	write("Intruder, Be Gone!\n");
	return 1;
    }
    str = get_next_class_title((int) present(GUILD_ID, this_player())->GuildClass());
    if(str == 0){ write("Your class does not have a title available.\n"+     
                        "Type 'title' for a title.\n");
                  return 1;
                  }
    this_player()->set_title(str);
    write("Your rightful title has been restored. You now are:\n");
    write(this_player()->short() + ".\n");
    if (titles = present("titles", this_player()))
       titles->add_title(str);
    return 1;
    }     
    else return 0;
    if (!present(GUILD_ID, this_player())) {
	write("Intruder, Be Gone!\n");
	return 1;
    }

    str = get_next_title((int) this_player()->query_guild_rank());
    this_player()->set_title(str);
    write("Your rightful title has been restored. You now are:\n");
    write(this_player()->short() + ".\n");
    if (titles = present("titles", this_player()))
      titles->add_title(str);
    return 1;
}

advance ()
{
    int             spare,      /* experience not used */
		    needed,     /* spare xp needed for next guild level */
		    level;      /* regular level of player */
    object          guild;      /* guild object */
    string          name, title;

    guild = present(GUILD_ID, this_player());
    if (!guild) {
	write("Intruder, Be Gone!\n");
        level = 50;
	this_player()->add_hit_point(-(level+level));
        shardak_death(this_player());
	return 1;
    }
    if((status)this_player()->query_ghost())
      return 0;
    
    if ((int) this_player()->query_guild_rank() >= 8) {
	write("You have already reached the highest possible level.\n");
	return 1;
    }
    /* get the level of the player */
    level = (int) this_player()->query_level();

    /* wizards must find other ways */
    if (level >= 20) {
	write("Players only.\n");
	return 1;
    }

    /* get free amount of exp */
    spare = ((int)this_player()->query_exp() - (int)guild->QueryBaseXp(0));

    /* get the next guild level of the player */
    level = 1 + (int) this_player()->query_guild_rank();

    /* get experience needed for advancing one guild level */
    needed = get_next_exp(level) -
	     (int) this_player()->query_guild_exp();

if(this_player()->query_extra_level() < 1 && this_player()->query_level() < 21)
  spare = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",this_player()->query_level()-1);
if(this_player()->query_extra_level() > 0 && this_player()->query_level() < 21)
  spare = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
    if (spare < needed) {
	/* need more xp */
	write("\
You are not yet ready to be filled with the power of Shardak. You\n\
must amass " + (needed - spare) +
	      " more experience points before you can advance in rank.\n");
    } else {
	object titles;

	/* move reg xp -> guild xp, increase guild rank */
	this_player()->add_exp(-needed);
	this_player()->add_guild_exp(needed);
	this_player()->add_guild_rank(1);

      guild->save_me();

	/* give message to person and all guild members */
	write("\
You place your hands upon the smooth surface of the altar and\n\
whisper the arcane inscription cut in it. There is a crackle of\n\
electricity from your mildly sweating palms as you feel your\n\
experience drain away and wisdom fill your mind in return.\n");
	say(this_player()->query_name() + " places " +
	    possessive(this_player()) +
	    " hands upon the altar and mutters a few words.\n");
	title = get_next_title(level);
	name = (string) this_player()->query_name();
	this_player()->set_title(title);

	CHANNELD->broadcast(name + " has advanced to rank " + level + ".\n",
			    0, "{Servants}");
	CHANNELD->broadcast(name + " is now " + name + " " + title + ".\n",
			    0, "{Servants}");

	if (titles = present("titles", this_player())) {
	    titles->remove_title(get_next_title(level - 1));
	    titles->add_title(title);
	}
    }
    return 1;
}

void
long(string arg)
{
    if(!arg || arg == "altar")
    {
      object ob;
      ::long(arg);
      if((ob = this_player()) && ob->query_ghost())
        write("You may \"pray\" at the altar to revive.\n");
      return;
    }
    ::long(arg);
}
