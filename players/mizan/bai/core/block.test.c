/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */
#include "living.h"
#include "clean.c"
#define EMOTER(a,b,c) (string)call_other("/obj/user/parse_emote","parse_emote",a,b,c)
#define ANSI(x) (string)call_other("/obj/monitor","replace_ansi",x)
#define NONPHYS 30000/20000


/*
 * The heart beat is always started in living.h when we are attacked.
 */

string short_desc, long_desc, alias, alt_name, race, hbflag,info;
object kill_ob;
string *message_hit;
int my_tot_wc, my_tot_ac;

int heal_start;
int heal_rate;
int heal_intv;


object dead_ob;
object init_ob;


int spell_chance, spell_dam_mon;
string spell_mess1, spell_mess2;
object me;
static int give_count;

string spell_type;

static int res, pac, pwc;

static string armor_special, weapon_special;

mixed *armor_params;
mixed *weapon_params;

mixed *spells;
static status readied;
status multi_cast;
int saved_hr, saved_hi;
int saved_wc, saved_ac;

/* suggested/inspired by forbin.  added by illarion 5 dec 2004 */
string corpse_short,corpse_long,corpse_name;
string death_emote;

/* [2006.06.30] Forbin -implemeted multiple ids */
string *multipleIds;


valid_attack(ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
    return (!call_other(ob, "query_npc", 0));
}

reset(arg)
{
    if (arg)
    {
        return 1;
    }
    is_npc = 1;
    /* Only let this monster kill other monsters if specifically allowed. */
    enable_commands();
    if (!pac && !pwc) {
    }
    me = this_object();
    message_hit=( {
        "massacre"," to small fragments",
        "smashed"," with a bone crushing sound",
        "hit"," very hard",
        "hit"," hard",
        "hit","",
        "grazed","",
        "tickled"," in the stomach"
    });
}


short() {
    object ob;
    string temp_short;

    if (attacker_ob)
        temp_short = short_desc + " (Fighting "+(attacker_ob == this_player() ? "YOU!" : (string)attacker_ob->query_name())+")";
    else temp_short = short_desc;
    if (this_player() && (ob=present("sight_short_modifier", this_player())))
    {
        return (string)ob->modify_short(temp_short);
    }
    return temp_short;
}


long() {
    write (long_desc);
    if (hit_point < max_hp/10) {
        write(cap_name+" is in very bad shape.\n");
        return;
    }
    if (hit_point < max_hp/5) {
        write(cap_name+" is in bad shape.\n");
        return;
    }
    if (hit_point < max_hp/2) {
        write(cap_name+" is somewhat hurt.\n");
        return;
    }
    if (hit_point < max_hp - 20) {
        write(cap_name+" is slightly hurt.\n");
        return;
    }
    write(cap_name+" is in good shape.\n");
}

id(str) {
    /* 07/12/06 Earwax: this is hosing somehow, adding these checks */
    if (!str) return 0;
    /* [2005.06.30] Forbin -modified to support multiple ids */
    if (!multipleIds) multipleIds = ( { });
    return str == alt_name || str == name || str == alias ||
           str == race || member_array(str, multipleIds) > -1;
}

heart_beat()
{
    int c;

    if (!this_object()) return;

    dam_taken_this_round=0;
    age += 1;


    already_fight = 0;

    /* If there is none here test_if_any_here will turn of heat_beat */
    if (!test_if_any_here())
    {
        set_heart_beat(0);
        return;
    }

    if (kill_ob && present(kill_ob, environment(this_object()))) {
        if (random(2) == 1)
            return;   /* Delay attack some */
        attack_object(kill_ob);
        kill_ob = 0;
        return;
    }


    if (attacker_ob && present(attacker_ob, environment(this_object())) &&
            spell_chance > random(100)) {
        say(spell_mess1 + "\n", attacker_ob);
        tell_object(attacker_ob, spell_mess2 + "\n");
        attacker_ob->hit_player(random(spell_dam_mon), spell_type);
    }
    attack();

}

can_put_and_get(str)
{
    if (!str)
        return 0;
    return 1;
}


/*
 * Call the following functions to setup the monster.
 * Call them in the order they appear.
 */

set_name(n) {
    name = n;
    set_living_name(n);
    cap_name = capitalize(n);
    if (!short_desc)
        short_desc = cap_name;
    if (!long_desc)
        long_desc = "You see nothing special.\n";
    /*    move_object(clone_object("obj/soul"), this_object()); */
    /* why is this here?? */
    if (!message_hit)
        message_hit=( {"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});
}

/* Optional */
set_alias(a) {
    alias = a;
}
query_alias() {
    return alias;
}
/* Optional */
set_race(r) {
    race = r;
}
/* optional */
set_hp(hp) {
    max_hp = hp;
    hit_point = hp;
}
/* optional */
set_ep(ep) {
    experience = ep;
}
/* optional */
set_al(al) {
    /* Limit alignment to keep wizards from making their monsters worth
       much too much */
    if (al > 1000)
        al = 1000;
    if (al < -1000)
        al = -1000;
    alignment = al;
}
/* optional */
set_short(sh) {
    short_desc = sh;
    if (!long_desc)
        long_desc = short_desc + "\n";
}
/* optional */
set_long(lo) {
    long_desc = lo;
}
/* optional */

set_wc(wc) {
    if (!saved_wc) {
        saved_wc = wc;
        my_tot_wc = wc;
    }
    else {
        if (wc > my_tot_wc) my_tot_wc = wc;
    }
    pwc=wc;
    weapon_class=wc;
    set_weapon_params("physical", pwc, weapon_special);
}

set_weapon_special(special2) {
    weapon_special = special2;
    set_weapon_params("physical",pwc, weapon_special);
}
/* optional */
set_ac(ac)
{
    if (!saved_ac) {
        saved_ac = ac;
        my_tot_ac = ac;
    }
    else {
        if (ac > my_tot_ac) my_tot_ac = ac;
    }
    pac=ac;
    armor_class=ac;
    set_armor_params("physical", pac, res, armor_special);
}
set_res(res1)
{
    res=res1;
    set_armor_params("physical",pac,res,armor_special);
}

set_armor_special(special1) {
    armor_special = special1;
    set_armor_params("physical",pac,res,armor_special);
}

/* pre-dtypes
set_wc(wc) { weapon_class = wc; }
set_ac(ac) { armor_class = ac; }
*/
/*
 * Now some functions for setting up spells !
 */
/*
 * The percent chance of casting a spell.
 */
set_chance(c) {
    spell_chance = c;
}
/* Message to the victim. */
set_spell_mess1(m) {
    spell_mess1 = m;
}
set_spell_mess2(m) {
    spell_mess2 = m;
}
set_spell_dam(d) {
    spell_dam_mon = d;
}

/* Set the frog curse. */
set_frog() {
    frog = 1;
}

/* Set the whimpy mode */
set_whimpy() {
    whimpy = 1;
}

/*
 * Force the monster to do a command. The force_us() function isn't
 * always good, because it checks the level of the caller, and this function
 * can be called by a room.
 */
init_command(cmd) {
    command(cmd);
}












set_dead_ob(ob)
{
    dead_ob = ob;
}

second_life()
{
    if (dead_ob)
        call_other(dead_ob,"monster_died",this_object());
}



dumpa(str)
{
    string foo;
    if (sscanf(str, "players/%s", foo)) return 0;
    if (!str)
        str = "MONSTER_DUMP";
    save_object(str);
}

set_init_ob(ob)
{
    init_ob = ob;
}


init() {
    int ste,atc;

    if (this_player() == me)
        return;
    if (dead_ob)
        if (call_other(dead_ob,"monster_init",this_object()))
            return;
    if (attacker_ob) {
        set_heart_beat(1); /* Turn on heart beat */
    }
    if (this_player() && !call_other(this_player(),"query_npc")) {
        set_heart_beat(1);
    }
}

set_info(str) {
    info = str;
}
set_hbflag(str) {
    hbflag = str;
}
query_hbflag() {
    return hbflag;
}
query_info() {
    return info;
}


set_heal(hr, hi) {
    if (hr < 0) return;
    if (hi < 0) return;
    if (!saved_hr) saved_hr=hr;
    if (!saved_hi) saved_hi=hi;
    heal_rate = hr;
    heal_intv = hi;
}
set_alt_name(n) {
    alt_name = n;
}
set_gender(str) {
    gender = str;
}
query_race() {
    return race;
}
set_message_hit(arr) {
    message_hit=arr;
}
query_message_hit(tmp) {
    string *mess;
    mess = ( {message_hit[1],message_hit[0]});
    if (tmp < 30) {
        mess = ( {message_hit[3],message_hit[2]});
    }
    if (tmp < 20) {
        mess = ( {message_hit[5],message_hit[4]});
    }
    if (tmp < 10) {
        mess = ( {message_hit[7],message_hit[6]});
    }
    if (tmp < 5) {
        mess = ( {message_hit[9],message_hit[8]});
    }
    if (tmp < 3) {
        mess = ( {message_hit[11],message_hit[10]});
    }
    if (tmp == 1) {
        mess = ( {message_hit[13],message_hit[12]});
    }
    return mess;
}
given_me_junk(objg) {
    if (give_count < 2) return;
    give_count += 1;
    move_object(objg,environment(this_object()));
    write(cap_name+" drops "+objg->query_short()+"\n");
    return 1;
}

set_armor_params(style,class,res2,special2) {
    string cat, subcat;
    int i,s;
    if (!armor_params) armor_params = ( { });
    if (sscanf(style, "%s|%s",cat,subcat) !=2) {
        if (style != "physical" && style != "magical") style = "physical";
    }
    else if (cat != "other") style = "physical";
    if (member_array(style,armor_params) != -1) {
        for (i=0; i<sizeof(armor_params); i++) {
            if (style == armor_params[i]) {
                armor_params[i+1] = class;
                armor_params[i+2] = res2;
                armor_params[i+3] = special2;
                if (this_object())
                    this_object()->RegisterArmor(this_object(), armor_params );
                return;
            }
        }
    }
    armor_params += ( {style,class,res2,special2});
    if (this_object())
        this_object()->RegisterArmor(this_object(), armor_params );
}

set_weapon_params(style,class,special2) {
    string cat, subcat;
    int i,s;
    if (!weapon_params) weapon_params = ( { });
    if (sscanf(style, "%s|%s",cat,subcat) !=2) {
        if (style != "physical" && style != "magical") style = "physical";
    }
    else if (cat != "other") style = "physical";
    if (member_array(style,weapon_params) != -1) {
        for (i=0; i<sizeof(weapon_params); i++) {
            if (style == weapon_params[i]) {
                weapon_params[i+1] = class;
                weapon_params[i+2] = special2;
                if (this_object())
                    this_object()->RegisterWeapon(this_object(), weapon_params );
                return;
            }
        }
    }
    weapon_params += ( {style,class,special2});
    this_object()->RegisterWeapon(this_object(), weapon_params );
}

/* Returns damage potential (wc) for all registered weapons, with
   additional weight for non-physical damage:
   25% bonus for magical
   50% bonus for other non-physical
*/
query_damage_potential() {
    int tot_dam_pot;
    int s,s2,i;
    object *weps;
    mixed *params;
    int class;
    string style;
    if (!Weapons)
        return (saved_wc?saved_wc:query_wc());
    weps=keys(Weapons);
    s2=sizeof(weps);
    while (s2--)
        if (weps[s2] && (params=Weapons[weps[s2]]) && !weps[s2]->no_exp_effect()) {
            s=sizeof(params);
            weapon_class=0;
            for (i=0; i<s; i+=3) {
                style=params[i];
                class=params[i+1];
                if (style=="physical"||weps[s2]->is_weapon())
                    continue;
                else if (style == "magical")
                    tot_dam_pot += (5*class/4);  /* 25% bonus for magical damage type */
                else
                    tot_dam_pot += (3*class/2);  /* 50% bonus for other styles */
            }
        }
    return tot_dam_pot;
}

/* Returns defensive potential (ac) for all registered armor,
   50% less potential for magical
   75% less potential for other non-physical
*/
query_defense_potential() {
    int tot_def_pot;
    int s,s2,i;
    mixed *params;
    object *armors;
    int class;
    string style;
    if (!Armors)
        return (saved_ac?saved_ac:query_ac());
    armors=keys(Armors);
    s2=sizeof(armors);
    while (s2--)
        if (armors[s2] && (params=Armors[armors[s2]]) && !armors[s2]->no_exp_effect()) {
            s=sizeof(params);
            for (i=0; i<s; i+=4) {
                style=params[i];
                class=params[i+1];
                if (armors[s2]->is_armor())
                    continue;
                if (style=="physical")
                    tot_def_pot += class;
                else if (style == "magical")
                    tot_def_pot += (class/2);
                else
                    tot_def_pot += (class/4);
            }
        }
    return tot_def_pot;
}


query_heal_rate() {
    return heal_rate;
}
query_heal_intv() {
    return heal_intv;
}
query_spell_chance() {
    return spell_chance;
}
query_spell_dam() {
    return spell_dam_mon;
}

set_ghost(x) {
    ghost = x;    /* verte 9.20.01 */
}
query_long() {
    return long_desc;    /* verte 3.17.02 */
}

query_message_hit_array() {
    return message_hit;
}

set_spell_type(x) {
    spell_type=x;
}

mixed *query_spell_info(string name) {
    int x,s;
    if (!spells)
        return 0;
    s=sizeof(spells);
    for (x=0; x<s; x++)
        if (spells[x][0]==name)
            return spells[x];
    return 0;
}

mixed *query_spells() {
    int s;
    string *spnames;
    if (!spells)
        return 0;
    s=sizeof(spells);
    spnames=allocate(s);
    while (s--)
        spnames[s]=spells[s][0];
    return spnames;
}

/* Redid this part because calling m_decode in /obj/monitor
   directly would eat the #s from the string */
string process_ansi(string str) {
    string *words,as;
    int s;
    if (!str)
        return 0;
    words=explode(str,"$");
    s=sizeof(words);
    while (s--)
        if (as=ANSI(words[s])) {
            words[s]=as;
        }
    return implode(words,"");
}

varargs status add_spell(string name, string mess_target, string mess_room,
                         int chance, mixed damage, mixed type, status hit_all_attackers,
                         string ex_fun, object ex_ob) {
    mixed *nspell;
    if (!name)
        return 0;
    if (chance <= 0 || chance > 100)
        return 0;
    if (!spells)
        spells=( {});
    if (query_spell_info(name))
        return 0;
    nspell=allocate(9);
    nspell[0]=name;
    nspell[1]=process_ansi(mess_target);
    nspell[2]=process_ansi(mess_room);
    nspell[3]=chance;
    if (intp(damage))
        nspell[4]=( {"1-"+damage});
    else if (stringp(damage))
        nspell[4]=( {damage});
    else if (pointerp(damage)) {
        int s;
        s=sizeof(damage);
        while (s--) {
            if (intp(damage[s]))
                damage[s]="1-"+damage[s];
            else if (!stringp(damage[s]))
                damage[s]="1-0";
        }
        nspell[4]=damage;
    } else
        return 0;
    if (!type)
        nspell[5]=( {"physical"});
    else if (stringp(type))
        nspell[5]=( {type});
    else if (pointerp(type))
        nspell[5]=type;
    else
        return 0;
    if (sizeof(nspell[4])!=sizeof(nspell[5]))
        return 0;
    nspell[6]=hit_all_attackers;
    if (ex_fun) {
        nspell[7]=ex_fun;
        if (ex_ob && objectp(ex_ob))
            nspell[8]=ex_ob;
        else
            nspell[8]=this_object();

    } else {
        nspell[7]=0;
        nspell[8]=0;
    }
    spells+=( {nspell});
    return 1;
}

status remove_spell(string name) {
    mixed *rspell;
    if (!spells)
        return 0;
    rspell=query_spell_info(name);
    if (rspell) {
        spells-=( {rspell});
        return 1;
    }
    return 0;
}

status set_multi_cast(status x) {
    if (x)
        multi_cast=1;
    else
        multi_cast=0;
}

int *rand_dam(string *idam) {
    int *ndam;
    int s,x,y,t;
    int min,max,num_dice,side_dice;
    s=sizeof(idam);
    ndam=allocate(s);
    for (x=0; x<s; x++) {
        if (sscanf(idam[x],"%d-%d",min,max)==2)
            if (max>min)
                ndam[x]=min+random(max-min+1);
            else
                ndam[x]=0;
        else if (sscanf(idam[x],"%dd%d+%d",num_dice,side_dice,t)==3 ||
                 sscanf(idam[x],"%dd%d",num_dice,side_dice)==2) {
            for (y=0; y<num_dice; y++)
                t+=random(side_dice+1);
            ndam[x]=t;
        } else
            ndam[x]=0;
    }

    return ndam;
}

status check_attacking_me(object ob) {
    return (object)ob->query_attack()==this_object();
}

status check_player_target(object ob) {
    return (int)ob->is_player();
}

status check_non_player_target(object ob) {
    return !check_player_target(ob);
}


attack() {
    if (spells && attacker_ob) {
        object room;
        room=environment();
        if (room && present(attacker_ob,room)) {
            int spchance,s,x;
            s=sizeof(spells);
            if (multi_cast) {
                for (x=0; x<s; x++) {
                    if (attacker_ob) {
                        spchance=random(100)+1;
                        if (spchance<spells[x][3])
                            execute_spell(spells[x],room);
                    }
                }
            } else {
                int chance_total;
                spchance=random(100)+1;
                chance_total=0;
                for (x=0; x<s; x++) {
                    if (spchance > chance_total && spchance <= spells[x][3]+chance_total) {
                        execute_spell(spells[x],room);
                        break;
                    } else if (room) {
                        chance_total+=spells[x][3];
                    }
                }
            }
        }
    }
    if (this_object())
        ::attack();
}

int avg_dam(string dstr) {
    int min,max,num_dice,side_dice,t;
    if (sscanf(dstr,"%d-%d",min,max)==2) {
        if (max>min) {
            return (min+((max-min)/2));
        } else
            return 0;
    } else if (sscanf(dstr,"%dd%d+%d",num_dice,side_dice,t)==3 ||
               sscanf(dstr,"%dd%d",num_dice,side_dice)==2) {
        min=t;
        max=min+num_dice*side_dice;
        min+=num_dice;
        return min+((max-min)/2);
    } else
        return 0;
}

int query_spell_exp() {
    int x,y,s,ss;
    int extra_exp_tot;
    int extra_exp_round;
    int chance_total;
    int spells_used;
    int bonus;
    s=sizeof(spells);
    if (!spells || !sizeof(spells))
        return 0;
    chance_total=0;
    extra_exp_tot=0;
    for (x=0; x<s; x++) {
        extra_exp_round=0;
        ss=sizeof(spells[x][4]);
        /* Calculate total damage with a bonus for non-physical */
        for (y=0; y<ss; y++) {
            if (spells[x][5][y]=="physical")
                extra_exp_round+=avg_dam(spells[x][4][y]);
            else
                extra_exp_round+=avg_dam(spells[x][4][y])*NONPHYS;
        }
        switch (spells[x][6]) {
        default:
            bonus=100;
            break;
        case 1:
            bonus=120;
            break; /*extra exp for area attacks */
        case 3:
        case 4:
            bonus=110;
            break; /*for limited area attacks */
        case 2:
            bonus=80; /*Less than standard for alt_attacker */
        }
        extra_exp_round+=(extra_exp_round*bonus/100-extra_exp_round);

        /* Average damage is spell avg damage*chance in multicast mode */
        if (multi_cast)
            extra_exp_tot+= (extra_exp_round * spells[x][3] / 100);
        else {
            chance_total+=spells[x][3];
            extra_exp_tot+=extra_exp_round;
        }
        if (chance_total>=100)
            break;
    }
    if (multi_cast)
        return extra_exp_tot;
    else /* In non multi-cast motive the chance is cumulative not averaged */
        return extra_exp_tot * chance_total / 100 / x;
}

query_total_level() {
    return level;
}

set_corpse_short(str) {
    corpse_short=str;
}
query_corpse_short() {
    return corpse_short;
}
set_corpse_long(str) {
    corpse_long=str;
}
query_corpse_long() {
    return corpse_long;
}
set_corpse_name(str) {
    corpse_name=str;
}
query_corpse_name() {
    return corpse_name;
}
set_death_emote(str) {
    death_emote=str;
}
query_death_emote() {
    return death_emote;
}
perform_death_emote() {
    string emote;
    object room;
    if (death_emote && (room=environment()) && this_player()
            && (emote=EMOTER(death_emote,this_object(),this_player())))
        tell_room(room,format(emote));
}

/* [2006.06.30] Forbin -added SetMultipleIds & QueryMultipleIds to support
                        multiple ids */
void SetMultipleIds(string *x)
{
    multipleIds = x;
}

string * QueryMultipleIds()
{
    return multipleIds;
}

query_saved_wc() {
    return saved_wc;
}
query_saved_ac() {
    return saved_ac;
}
query_saved_hr() {
    return saved_hr;
}
query_saved_hi() {
    return saved_hi;
}


/*
 * Pavlik - 10/21/2005
 */
mixed query_armor_params(string dtype)
{
    int i;
    if (!dtype)
    {
        return armor_params;
    }
    for (i=0; i<sizeof(armor_params); i+=4)
    {
        if (armor_params[i] == dtype)
        {
            return ( armor_params[i], armor_params[i+1], armor_params[i+2], armor_params[i+3] );
        }
    }
    return 0;   /* what do we return if no match was found? */
}

int query_armor_class(string dtype)
{
    int i;
    if (!dtype)
    {
        return 0; /* return 0, or maybe just return physical? */
    }
    for (i=0; i<sizeof(armor_params); i+=4)
    {
        if (armor_params[i] == dtype)
        {
            return armor_params[i+1];
        }
    }
    return 0;   /* no matching dtype: return 0, or maybe just return physical? */
}

int query_armor_res(string dtype)
{
    int i;
    if (!dtype)
    {
        return 0; /* return 0, or maybe just return physical? */
    }
    for (i=0; i<sizeof(armor_params); i+=4)
    {
        if (armor_params[i] == dtype)
        {
            return armor_params[i+2];
        }
    }
    return 0;   /* no matching dtype: return 0, or maybe just return physical? */
}



void load_default_attribs(int x)
{
    /* nothing for now */
}

void load_stats(int w, int a, int h)
{
    set_wc(w);
    set_ac(a);
    set_hp(h);
}

void
set_level(int tmp)
{
    int z, tmpAc, n;

    level = tmp;
    if (!experience)
    {
        experience = (int)"/room/adv_guild"->query_cost(tmp-1);
    }
    if (!heal_intv)
    {
        heal_intv = ((level < 12) ? 120 : 35);
        heal_rate = 2;
    }
    if (!saved_hi)
    {
        saved_hi=heal_intv;
    }
    if (!saved_hr)
    {
        saved_hr=heal_rate;
    }
    if (!message_hit)
    {
        message_hit=( {"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});
    }

    switch (tmp)
    {
    case 1..14:
        switch (tmp)
        {
        case 1..2:
            tmpAc=3;
            break;
        case 3..4:
            tmpAc=4;
            break;
        case 5..6:
            tmpAc=5;
            break;
        case 7:
            tmpAc=6;
            break;
        case 8..9:
            tmpAc=7;
            break;
        case 10:
            tmpAc=8;
            break;
        case 11..12:
            tmpAc=9;
            break;
        case 13..14:
            tmpAc=tmp-3;
            break;
        }
        load_stats((4 + tmp), (tmpAc), (tmp * 15));
        break;

    case 15..20:
        z = (20 - (tmp));
        load_stats((30 - (z * 2)), (17 - z), (500 - (50 * z)));
        break;

    case 21:
        load_stats(34, 19, 600);
        break;

    case 22..25:
        z = (25 - (tmp));
        load_stats((44 - (z * 2)), (23 - z), (1000 - (100 * z)));
        break;

    case 26:
        load_stats(46, 24, 1200);
        break;

    case 27:
        load_stats(48, 25, 1500);
        break;

    case 28:
        load_stats(52, 26, 1800);
        break;

    case 29:
        load_stats(55, 28, 2000);
        break;

    case 30:
        load_stats(60, 30, 2500);
        break;
    }

    load_default_attribs(tmp);

    if (!hit_point)
    {
        set_hp(50 + (level - 1) * 8);
    }
}


void remove_object(object caller) {
    destruct(this_object());
}
query_save_flag() {
    return 1;
}

