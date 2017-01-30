/*
 * Attempt to make a generic monster with a couple of extra abilities
 * by Balowski, Nirvana '95
 * Purpose: save a little mem and several objects
 * 950827       created
 */
inherit "obj/monster";

static status   BusyGet;
static object   CallBack;

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
    if (init_ob && init_ob->monster_init())
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
