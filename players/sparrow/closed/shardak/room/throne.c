/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950422 - created
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../daemons.h"
#include "../people.h"
#include "../macros.h"
#include <security.h>
#ifndef __FILE__
#define __FILE__ file_name(this_object())
#endif

inherit ROOM;
static object	Shardak;
status Flag_Unlocked; /* Are the exits locked or unlocked? */

void set_unlocked(status arg) { Flag_Unlocked = arg; }

void
create()
{
    ::create();
    set_short("The throne room");
    set_long("\
This is the grand throne room. The domed ceiling is barely visible\n\
high up in the dim light. Your footsteps echo loudly on the black\n\
marble tiles as you approach the throne. The three steps leading up\n\
to the throne are covered with the golden hoard belonging to the\n\
dragon-man sitting upon it, Shardak.\n\
A passage leads west and another one east.\n\
There is a staircase leading down to the senior's room.\n\
A low exit in the southern wall leads back into the tunnel.\n");

    set_exits(([
	"south" : (PATH + "deepdown"), 
	"west" : (PATH + "niches"),
	"east" : this_object(),
        "down" : this_object(),
	]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);

    call_other(PATH + "shardak", "");
    Shardak = find_object(PATH + "shardak");
    move_object(Shardak, this_object());
#ifdef TEMPFIX
  set_unlocked(0);
  "/players/vertebraker/closed/shardak/room/othrone.c"->set_unlocked(0);
#endif
}

mixed
down(string arg)
{
   object gob;

   if (arg) return 0;
   if (Flag_Unlocked) return PATH + "seniorroom";
   if ((gob = present(GUILD_ID, this_player())) &&
       (gob->GuildClass() >= C_SENIOR))
      return PATH + "seniorroom";
   write("You are not allowed in there.\n");
   return 1;
}

mixed
east(string arg)
{
    object      gob;            /* guild object */

    if (arg) return 0;
    if (Flag_Unlocked) return PATH + "lawroom";
    if ((gob = present(GUILD_ID, this_player())) &&
	((int) gob->GuildClass() >= C_LAW))
      return PATH + "lawroom";

    write("You are not allowed in there.\n");
    return 1;
}
	

/*
 * Two additional actions
 */
void
init()
{
    ::init();
    add_action("cmd_worship", "worship");
    add_action("abandon", "abandon");
}

/*
 * Abandon guild *sniff*
 */
static status
abandon(string str)
{
    if (str != "guild")
	return 0;

    write("\
Shardak hisses at you, \"Be aware of the consequences you must suffer\n\
if you confirm your choice. You will lose all powers given to you by\n\
me. You will lose all guild experience you may have amassed. And as a\n\
little extra penalty I will take your life.\"\n\
Confirm your choice with 'yes' : ");
    input_to("confirm");
    return 1;
}

static void
confirm(string str)
{
    int         exp, gxp, rnk;  /* regular exp, guild exp, guild rank */
    object      gob;            /* guild object */

    if (str != "yes") {
	write("You have chosen wisely.\n");
	return;
    }
    if (!(gob = present(GUILD_ID, this_player()))) {
	write("You are not carrying the mark of Shardak.\n");
	return;
    }

    gxp = (int) this_player()->query_guild_exp();
    rnk = (int) this_player()->query_guild_rank();
    exp = (int) this_player()->query_exp();

    if (!intp(gxp) || !intp(rnk) || !intp(exp)) {
	write("Your organism is broken. Contact an arch wizard.\n");
	return;
    }
    write("Shardak hisses, \"I am afraid this may hurt a little.\"\n");
    this_player()->set_guild_name(0);   /* clear guild name */
    this_player()->add_guild_exp(-gxp); /* clear guild experience */
    this_player()->add_guild_rank(-rnk);/* clear guild rank */
    this_player()->set_home(0);         /* clear alternative login room */
    CHANNELD->deregister(gob);          /* remove from member list */
    destruct(gob);                      /* remove the mark of shardak */
					/* remove the guild file */
    rm("/" + SAVE_PATH + this_player()->query_real_name() + ".o");

    if ((int) this_player()->query_level() >= APPRENTICE) {
	write("Wizard are immortals. Skipping final stage.\n");
	return;
    }
    else {
	/* deduct one sixth experience as prescribed by the guild laws */
	/* Note: It is currently one fourth. */

	/* Grab the gold from the player. Equip still goes to corpse */
	int gold;
	gold = (int) this_player()->query_money();
	HOARDD->add_hoard(gold);
	this_player()->add_money(-gold);
#if 0
	this_player()->add_exp(-exp/4);
	this_player()->second_life();
	gob = clone_object("obj/corpse");
	this_player()->transfer_all_to(gob);
	move_object(gob, this_object());
#else
	this_player()->attacked_by(this_object());
	this_player()->hit_player(10000);/* lose one fourth exp */
/* this is out..
	this_player()->add_exp(exp/12);  /* get the desired one sixth */
#endif
	write("Your ghost drifts back to the church.\n");
        if(this_player()) { /* verte 7.18.02 */
	move_object(this_player(), "room/church");
	log_file("GUILD", ctime() + ":\n" +
		capitalize((string) this_player()->query_real_name()) +
		" left the Servants of Shardak. By " + __FILE__ + "\n");
       }
    }
}

/*
 * Makes the obituary nicer..
 */
string
query_real_name()
{
    return "Shardak";
}


void
long(string arg)
{
    if(!arg) { ::long(arg); if(Shardak && present(Shardak)) write(" Shardak is present.\n"); return; }
    else ::long(arg);
}

status page(string arg)
{
    object ob;
    if(ob = find_player(arg)) {
      write("You kneel down and worship the Great Magus " + capitalize(arg) + ".\n");
      tell_object(ob, "\n\n\t" + (string)this_player()->query_name() + " worships you and demands your presence in the Guild Hall.\n\n");
      return 1;
    }
    else return (notify_fail(capitalize(arg) + " is not online.\n"), 0);
}

status cmd_worship(string arg)
{
    if(!id(arg))
      if(arg == "vertebraker" || arg == "vital") return page(arg);
    else  return (write("You kneel in worship of Almighty Shardak.\n"), 1);
}
