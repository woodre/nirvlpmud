/*
 * Attempt to make a generic monster with a couple of extra abilities
 * by Balowski, Nirvana '95
 * Purpose: save a little mem and several objects
 * 950827       created
 */
#include "/players/balowski/lib.h"
inherit BASE;
inherit "obj/monster";

static status   BusyGet;
static object   CallBack;

void
reset(int arg)
{
    monster::reset(arg);
    base::reset(arg);
}

string
query_name()
{
    return cap_name;
}

/*
 * First thing is to detect when a player hands me something
 * (or it could be that I pick something up myself)
 * do a callback to evGotObject with (item, giver)
 */
status
add_weight(int w)
{
    if (BusyGet)
        return 0;
    if (BusyGet = (status) ::add_weight(w))
        call_out("evGotObject", 1, this_player());
    return BusyGet;
}

void
evGotObject(object giver)
{
    if (CallBack)
        CallBack->evGotObject(first_inventory(this_object()), giver);
    BusyGet = 0;
}

/*
 * Provide some funkier attacks
 * Only problem with plain wield() is that it writes "Ok."
 * Still I should take care that stop_wield is performed
 * in room do: monster->wield(), and hit(opponent) is called every round
 * just set_wc afterwards
 */
void
wield(object weapon)
{
    if (!weapon)
        weapon = previous_object();
    if (name_of_weapon)
        stop_wielding();
    name_of_weapon = weapon;
    weapon_class = (int) weapon->weapon_class();
}

/*
 * I don't want the boring chat arrays getting spewed out in hb
 * Spell message is no longer necessary when wield is used
 * Just call back in heartbeat
 */
void
heart_beat()
{
    if (!heal_start) {
       call_out("autoheal_monster", heal_intv);
       heal_start = 1;
    }
     
    already_fight = 0;

    /* If there is none here test_if_any_here will turn of heat_beat */
    if (!test_if_any_here()) {
        set_heart_beat(0);
        return;
    }

    if (kill_ob && present(kill_ob, environment())) {
        if (random(2))
            tell_object(kill_ob, query_name() +
                        " is approaching you with murder in " +
                        query_possessive() + " eyes.\n");
        else {
            attack_object(kill_ob);
            kill_ob = 0;
        }
        return;
    }
    attack();

    if (attacker_ob && whimpy && hit_point < max_hp/5)
        run_away();

    if (random_pick && random(100) < random_pick)
        pick_any_obj();
}

void
autoheal_monster()
{
    heal_self(heal_rate);
    if (hit_point < max_hp || spell_points < max_spell)
        call_out("autoheal_monster", heal_intv);
    else
        heal_start = 0;
}

void
add_spell_point(int x)
{
    if ((spell_points += x) > max_spell)
	spell_points = max_spell;
}

/*
 * I'd rather process the tell's myself
 * This is quite crude, watch out for those circular calls
 * ya know, catching tell from myself and then saying something
 */
void
catch_tell(string msg)
{
    if (CallBack)
        CallBack->evHeardMsg(msg);
}

/*
 * the original init sucks, this sucks a little less *grin*
 * use set_aggressive(50) to get the usual aggressiveness
 */
void
init()
{
    if (this_player() && !this_player()->query_npc())
        set_heart_beat(1);
    if (init_ob && init_ob->monster_init(this_player()))
        return;
    if (attacker_ob)
        set_heart_beat(1);
    if (random(aggressive) > (int) this_player()->query_attrib("ste"))
        kill_ob = this_player();
}

/*
 * Very important function :)
 * Just a single function for setting things up
 */
void
setCallBack(object o)
{
    CallBack = objectp(o) ? o : previous_object();
}

void
setGhost(status fl)
{
    ghost = fl;
}

mixed
second_life()
{
    /* return !0 to prevent destruct */
    if (dead_ob) {
	string err; mixed x;
	/* danger-zone, I better catch */
	err = catch(x = (mixed) dead_ob->monster_died(this_object()));
	if (!err) return x;
    }
}

int
query_attrib(string attr)
{
    return (int) query_level();
}

/* some punks access set_hp/sp to deal damage */
/* only allow hp lowering before I am moved somewhere */
void
set_hp(int x)
{
    if (x < hit_point && environment()) return;
    max_hp = hit_point = x;
}

void
set_sp(int x)
{
    if (x < spell_points && environment()) return;
    max_spell = spell_points = x;
}

/*int query_sp() { return spell_points;}*/

/* other things I do not appreciate done to my monsters */
void
attacked_by(object ob)
{
    if (ob != this_object()) ::attacked_by(ob);
}

void
attack_object(object ob)
{
    if (ob != this_object()) ::attack_object(ob);
}

/*
 * Super set level. Sets hp/sp/ac/wc according to rules
 * spell_points are not in rules, but they are set to the same as hps
 */
void
set_level(int l)
{
    if (l < 1) return;
    ::set_level(l);
    
    switch (l) {
     case  1: set_hp(15);  set_wc(5);  set_ac(3); break;
     case  2: set_hp(30);  set_wc(6);  set_ac(3); break;
     case  3: set_hp(45);  set_wc(7);  set_ac(4); break;
     case  4: set_hp(60);  set_wc(8);  set_ac(4); break;
     case  5: set_hp(75);  set_wc(9);  set_ac(5); break;
     case  6: set_hp(90);  set_wc(10); set_ac(5); break;
     case  7: set_hp(105); set_wc(11); set_ac(6); break;
     case  8: set_hp(120); set_wc(12); set_ac(7); break;
     case  9: set_hp(135); set_wc(13); set_ac(7); break;
     case 10: set_hp(150); set_wc(14); set_ac(8); break;
     case 11: set_hp(165); set_wc(15); set_ac(9); break;
     case 12: set_hp(180); set_wc(16); set_ac(9); break;
     case 13: set_hp(195); set_wc(17); set_ac(10); break;
     case 14: set_hp(210); set_wc(18); set_ac(11); break;
     case 15: set_hp(225); set_wc(20); set_ac(12); break;
	
     case 16: set_hp(400); set_wc(22); set_ac(13); break;
     case 17: set_hp(425); set_wc(24); set_ac(14); break;
     case 18: set_hp(450); set_wc(26); set_ac(15); break;
     case 19: set_hp(475); set_wc(28); set_ac(16); break;
     default: set_hp(l*25); set_wc(3*l >> 1); set_ac(l - 3); break;
    }
    set_sp((int) query_hp());
}

void
set_env(string s, mixed x)
{
    switch (s) {
     case "msgout" : msgout = x; break;
     case "msgin"  : msgin = x; break;
     case "mmsgout": mmsgout = x; break;
     case "mmsgin" : mmsgin = x; break;
    }
}
