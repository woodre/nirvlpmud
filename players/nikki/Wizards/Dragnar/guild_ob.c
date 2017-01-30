#include "/players/dragnar/guild/defs/def.h"
#define MASTER "/players/dragnar/guild/shardak_master.c"
#define SAVE_PATH "players/dragnar/guild/stats/"
int             rank, guild_class, pkills, color_flag;
string          wstmsg;
static string   checker, dragwho;
static int      follow_flag, muffled, drag_flag;
static object   trackwho;

id(str)
{
    return str == "guild_object" || str == "shardak_mark" || str == "mark";
}

query_auto_load()
{
    return "players/dragnar/guild/mark:";
}

reset()
{
    set_heart_beat(1);
    call_out("hb", 2);
}

short()
{
    return 0;
}

extra_look()
{
    return capitalize(RN) + " has the Mark of Shardak carved into " +
	   user->query_possessive() + " right hand";
}

long()
{
    write("\
This is the mark that you recieved when you joined the members of\n\
the underworld.  Type 'info' to see the powers it gives you.\n");
}

drop()
{
    return 1;
}

get()
{
    return 1;
}

query_value()
{
    return 0;
}

set_muffled(mf)
{
    muffled = mf;
}

set_color(cl)
{
    color_flag = cl;
}

set_follow(fl)
{
    follow_flag = fl;
}

set_trackwho(tw)
{
    trackwho = tw;
}

set_guild_class(cs)
{
    guild_class = cs;
}

set_pkills(ks)
{
    pkills = ks;
}

set_wstmsg(msg)
{
    wstmsg = msg;
}

set_drag(DN)
{
    drag_flag = DN;
}

set_dragwho(tp)
{
    dragwho = tp;
}

heart_beat()
{
    if (att) {
	command("monitor", user);
    }
}

hb()
{
    if (follow_flag == 1) {
	if (!present(trackwho, environment(user))) {
	    move_object(user, environment(trackwho));
	    command("look", user);
	}
    }
    if (drag_flag == 1) {
	if (!present(find_player(dragwho), environment(user))) {
	    move_object(find_player(dragwho), environment(user));
	    command("look", find_player(dragwho));
	}
    }
    call_out("hb", 3);
}

init()
{
    this_player()->set_guild_name("shardak");
    restore_me();
    add_action("shardak1","shardak1");
    add_action("darken", "darken");
    add_action("save_me", "gsave");
    add_action("restore_me", "restore");
    add_action("color", "color");
    add_action("info", "info");
    add_action("angel_tell", "gt");
    add_action("angel_emote", "ge");
    add_action("angel_who", "gw");
    add_action("angel_tell_silence", "gts");
    add_action("others", "others");

    if ((int) this_player()->query_guild_rank() >= 1) {
        add_action("monitor", "monitor");
        add_action("score", "sc");
        add_action("scan", "scan");
        add_action("drain", "drain");
        add_action("dagger", "dagger");
        add_action("guild_shield", "shield");
    }
    if ((int) this_player()->query_guild_rank() >= 2) {
        add_action("tell", "tell");
        add_action("track", "track");
		add_action("set_light_on", "light");
        add_action("equil", "equil");
        add_action("toggle", "toggle");
        add_action("title", "title");
        add_action("junk", "junk");
    }
    if ((int) this_player()->query_guild_rank() >= 3) {
        add_action("no_fight", "no_fight");
        add_action("slayer", "slayer");
        add_action("heal", "heal");
        add_action("send", "send");
        add_action("waste_msg", "waste_msg");
        add_action("waste", "waste");
    }
    if ((int) this_player()->query_guild_rank() >= 4) {
        add_action("summon", "summon");
        add_action("dragon", "dragon");
        add_action("morph", "morph");
    }
    if ((int) this_player()->query_guild_rank() >= 5) {
        add_action("drag", "drag");
        add_action("check", "check");
        add_action("wand", "wand");
    }
}

check()
{
    write("Dragwho is set to " + dragwho + ".\n" +
	  "Drag_flag is set to " + drag_flag + ".\n");
    return 1;
}

query_pkills()
{
    return pkills;
}

query_muffled()
{
    return muffled;
}

query_color_flag()
{
    return color_flag;
}

query_guild_class()
{
    return guild_class;
}

query_follow()
{
    return follow_flag;
}

query_wstmsg()
{
    return wstmsg;
}

query_drag()
{
    return drag_flag;
}

    shardak1() {
        MASTER->shardak1();
	return 1;
    }
dragon()
{
    MASTER->dragon();
    return 1;
}

angel_emote(str)
{
    MASTER->angel_emote(str);
    return 1;
}

info()
{
    MASTER->info();
    return 1;
}

equil()
{
    MASTER->equil();
    return 1;
}

dagger(str)
{
    MASTER->dagger(str);
    return 1;
}

angel_tell(str)
{
    MASTER->angel_tell(str);
    return 1;
}

angel_who()
{
    MASTER->angel_who();
    return 1;
}

monitor()
{
    MASTER->clarknm();
    return 1;
}

guild_shield(str)
{
    MASTER->shield(str);
    return 1;
}

slayer(str)
{
    MASTER->slayer(str);
    return 1;
}

tell(str)
{
    MASTER->tell(str);
    return 1;
}

score()
{
    MASTER->score();
    return 1;
}

color()
{
    MASTER->color();
    return 1;
}

angel_tell_silence()
{
    MASTER->angel_tell_silence();
    return 1;
}

track(str)
{
    MASTER->track(str);
    return 1;
}

summon()
{
    MASTER->summon();
    return 1;
}

morph(str)
{
    MASTER->morph(str);
    return 1;
}

darken()
{
    MASTER->darken();
    return 1;
}

others()
{
    MASTER->others();
    return 1;
}

drain()
{
    MASTER->corpse_heal();
    return 1;
}

no_fight()
{
    MASTER->calm();
    return 1;
}

toggle(str)
{
    MASTER->toggle(str);
    return 1;
}

title(str)
{
    MASTER->title(str);
    return 1;
}

heal(str)
{
    MASTER->heal(str);
    return 1;
}

send(str)
{
    MASTER->send(str);
    return 1;
}

waste_msg(str)
{
    MASTER->waste_msg(str);
    return 1;
}

waste(str)
{
    MASTER->waste(str);
    return 1;
}

junk(str)
{
    MASTER->do_sell(str);
    return 1;
}

scan(str)
{
    MASTER->scan(str);
    return 1;
}

wand(str)
{
    MASTER->wand(str);
    return 1;
}

drag(str)
{
    MASTER->drag(str);
    return 1;
}

save_me()
{
    string          file;

    file = SAVE_PATH + RN;
    if (!save_object(file)) {
	tell_object(user, "Error in saving guild stats!\n");
	return 1;
    } else {
	tell_object(user, "Saving guild stats.\n");
	return 1;
    }
}

restore_me()
{
    if (!user) {
	return 0;
    }
    tell_object(user, "Restoring guild stats...\n");
    restore_object(SAVE_PATH + RN);
    return 1;
}

set_light_on()
{
    set_light(1);
    return 1;
}

/*
 * Small section for tasks
 */
#define LOGMASTER "players/dragnar/guild/log_master"

int		solved;		/* bit field with solved tasks */
				/* easy for computers to interpret ;-) */

int
query_solved(int mask)
{
    return solved & mask;
}

void
add_solved(int task)
{
    if (LOGMASTER->log_task(task, previous_object()))
	solved |= task;
}
