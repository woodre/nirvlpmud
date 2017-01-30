#include <security.h>
#define TEMPFIX 1

/* 
 * Shardak guild - (tm) Dragnar/John
 * Shardak is (c) Balowski/Rasmus, August 4th 1996.
 */
#include "/players/balowski/lib.h"
#include "../macros.h"
#include "../def.h"
#include "../tasks.h"

inherit "/obj/monster";
static object *Intruders, *Victims;

reset(x)
{
    if(x) return;
    ::reset(x);
    set_race("demon");
    set_name("shardak");
    set_short(0);
    set_ghost(0);
    set_no_clean(1);
    set_long("\
Shardak is the harbinger of death.  He is an outcast of the underworld;\n\
sentenced to imprisonment on earth in the form of half man, half dragon.\n\
Dark red scales cover his defined body like a carapace. Three black claws\n\
on each hand provide him with a natural and lethal weapon.\n");
    set_level(25);
    set_ac(35);
    set_wc(140);
     set_hp(20000);
    max_spell = 1000;
    set_al(-1000);	/* ultimate evil */
    set_heal(20, 35);
    set_dead_ob(this_object());
    mmsgout = "disappears behind a sheet of fire";
    mmsgin = "thunders into the room";
    
    Intruders = ({ });
    Victims = ({ });
}

/* ghosts aren't handled that well by living.c and I have an
 * override in my monster thing.. here's another one
 */
string query_name()
{
  if( ghost )
    return "some mist";
  else
    return ::query_name();
#if 0
   return ghost ? "some mist" /* stops fight */
                 : (string) ::query_name();
#endif
}

int monster_died(object me)
{
    string nom;
    int    s;
    object *us, x;

    tell_room(environment(), "\
Shardak's mutilated corpse falls to the ground, but a shimmering image\n\
remains where he just stood.\n");
    set_short("The spiritual remains of Shardak");
    set_long("\
Shardak has been banished from the realm of the living. This frail mist\n\
is all that is left of the dragon-man, and it is slowly disappearing.\n");

    if (query_attack()) nom = (string) query_attack()->query_name();
    call_other(CHANNELD, "broadcast", nom ?
	       ("Shardak was banished from the living by " + nom + ".\n") :
	       "Shardak was inexplicably banished from the living.\n",
	       0, "{Servants}");

    stop_fight();
    stop_fight();
    log_file("SHARDAK", "Shardak died on " + ctime()[4..15] + "\n");
    call_out("hide_me", 10);

    s = sizeof(us = users());

/* /06/17/06 Earwax: at express request/convincing by Fakir, changing
 * this pending Verte's return.  Undefine TEMPFIX in def.h to switch
 * this back to where killing Shardak damages all online guild members.
 * This change merely unlocks all the 'safe rooms' in the guildhall
 * upon his death.
 */
#ifdef TEMPFIX
  "/players/vertebraker/closed/shardak/room/othrone.c"->set_unlocked(1);
  "/players/vertebraker/closed/shardak/room/throne.c"->set_unlocked(1);
#else
    while(s --)
      if((string)(x = us[s])->query_guild_name() == GUILDNAME &&
         servant(x))
      {
        tell_object(x, "\
The death of your master leaves a tear in your soul.\n");
        x->hit_player(400 + random(200), "other|good");
        /* score one for the big dogs ! */
      }
#endif
         

    set_ghost(1);
    return 1;	/* no destruct */
}

void
hide_me()
{
    tell_room(environment(), "The spirit of Shardak vanishes into thin air.\n");
    move_object(this_object(), "/players/vertebraker/workroom");
    this_object()->add_spell_point(-spell_points);
}

void
revive_me()
{
    set_short(0);
    set_long("\
Shardak is the harbinger of death.  He is an outcast of the underworld;\n\
sentenced to imprisonment on earth in the form of half man, half dragon.\n\
Dark red scales cover his defined body like a carapace. Three black claws\n\
on each hand provide him with a natural and lethal weapon.\n");
    heal_self(10000);
    this_object()->add_spell_point(1000);
    
    move_object(this_object(), PATH + "throne");
#ifdef TEMPFIX
  "/players/vertebraker/closed/shardak/room/throne.c"->set_unlocked(0);
  "/players/vertebraker/closed/shardak/room/othrone.c"->set_unlocked(0);
#endif
    tell_room(environment(), "Shardak returns to the realm of the living.\n");
    CHANNELD->broadcast("Shardak speaks: I have returned from banishment.\n",
			0, "{Servants}");
}

void
add_spell_point(int x)
{
    spell_points += x;
    if (query_ghost() && query_sp() >= 1000) {
	ghost = 0;
	call_out("revive_me", 10);
    }
}

void
add_intruder(object who)
{
    if(friend(who) || servant(who)) return;
    if (member_array(who, Intruders) < 0) {
	call_out("warn_intruder", 5, who);
	Intruders += ({ who });
    }
}

void
warn_intruder(object who)
{
    if (!who) return;
    if (!query_ghost()) {
	tell_object(who, "\n\
You hear a strange voice in your head:  Leave immediately or prepare\n\
to fight for your life.\n\n");
    }
    call_out("add_victim", 10, who);
}

void
add_victim(object who)
{
    Victims += ({ who });
    if (sizeof(Victims) == 1) {
	call_out("prowl", 15 + random(10));
    }
}

int
can_hunt(object who)
{
    /* must be a connected player with an environment */
    if (who && interactive(who) && environment(who)) {
	string fname, rname;

	/* must be inside guild */
	fname = file_name(environment(who));
        if (sscanf(fname, PATH + "%s", rname) == 1) {
	    return 1;
	}	
    }
    return 0;
}

void
prowl()
{
	object *vics;
	int i;
    if (!(query_ghost() ||
          (attacker_ob && present(attacker_ob, environment())))) {

#ifndef __LDMUD__
	vics = filter_array(Victims, "can_hunt", this_object());
#else
	vics = filter(Victims, "can_hunt", this_object());
#endif

	if (i = sizeof(vics)) {
	    this_object()->move_player(environment(vics[--i]), "X");
	    this_object()->attacked_by(vics[i]);
	}	  
    }
    call_out("prowl", 8 + random(8));
}

status
query_prevent_shadow()
{
    return 1;
}

void
heart_beat()
{
    ::heart_beat();
}

mixed
stop_fight(mixed y)
{
    object x;
    if((x = this_player()) && (int)x->query_level() <= APPRENTICE)  return 1;
    else return ::stop_fight(y);
}
