/*----------------------------------------------------------------------*/
/*      The new and improved daemonized monk guild object               */
/*                                                                      */
/*      Edited and improved by Pain 30 OCT 94                           */
/*      version 1.0                                                     */
/*  version 1.1 cleaned up excess global variables and bullshit add_acs */
/*                                                                      */
/*----------------------------------------------------------------------*/

/*                  INCLUDES, INHERITS and DEFINITIONS                  */
#include "/players/pain/guild/m_defs.h"
inherit "/obj/treasure";

/*      GLOBAL VARIABLES                                                */
int muffled, worn, iquit, color, lsteal;
int mkick,chop,blast,flame,hurl,cash,lightning,tornado,staff;

static string type, protect, special;

static object worn_by;

static mixed *params;

/*      GLOBAL FUNCTIONS                                                */
set_lsteal(str){ lsteal = str; }
set_muffled(mf) { muffled = mf; }
query_muffled() { return muffled; }
set_color(co) { color = co; }
query_color() { return color; }
query_tornado() { return tornado; }
query_hurl() { return hurl; }
query_cash() { return cash; }
query_mkick() { return mkick;}
query_lightning() { return lightning;}
query_chop() { return chop;}
query_staff() {return staff;}
query_blast() {return blast;}
query_flame() { return flame; }
query_worn() { return worn; }
query_worn_by() { return worn_by; }

id(str){ return str == "robe" || str == "mrobe" || str == "robes" || 
    str == "monk robe" || str == "notarmor"; }

query_auto_load() { return "players/pain/guild/testobj.c:"; }

/*      reset()                                                         */
reset(arg) {
    if(arg)
        return;

    set_short("Dark Flowing Robes");
    set_long("Monk Robes\n");
    set_weight(0);
    set_value(0);
    set_alias("mrobe");

    worn = 0;
    mkick = 0;
    chop = 0;
    flame = 0;
    hurl = 0;
    tornado = 0;
    lightning = 0;
    cash = 0;
    blast = 0;
    staff = 0;

    lsteal = 50;
    iquit = 0;

    if(this_player()->query_money() > 40000) {
        this_player()->add_money(-(this_player()->query_money()));
        this_player()->add_money(40000);
    }

    if(this_player()->query_guild_rank() < 1) {
        this_player()->add_guild_rank(1); 
    }
    if(this_player()->query_guild_exp() < 1) {
        this_player()->add_guild_exp(1); 
    }
/*
    this_object()->set_guild_rank(this_player()->query_guild_rank());
    this_object()->set_guild_exp(this_player()->query_guild_exp());
    call_out("hp_monitor", 1);
*/
    call_out("special_attack", 5);
}

drop() {
    return 1;
}

long() {
       write("Type 'help dir' for more info on abilities.\n");
}

get() {
   return 1;
}

init_arg(arg) {

    if(restore_object(DIR)) {
        write("Restoring Guild Stats....\n");
    }
    else {
        save_object(DIR);
        write("Creating Save File....\n");
    }

    if(this_player()->query_level() < 20) {
        cat("/players/pain/guild/int_news");
    }

    this_player()->set_guild_file(0);
    return;
}

init() {
::init();
    add_action("sp_attack","sp_attack");
    add_action("wear","wear");
    add_action("clock","clock");
    add_action("info_sheet","info");
    add_action("speed","speed");
    add_action("balance","balance");
    add_action("tornado_attack","ta");
    add_action("shield","shield");
    add_action("send","send");
    add_action("first_stat","compare");
    add_action("prayer","prayer");
    add_action("lead","lead");
    add_action("aid","aid");
    add_action("purse","purse");
    add_action("hurl","hurl");
    add_action("flame","flame");
    add_action("trip","trip");
    add_action("dtrip","dtrip");
    add_action("gc","gc");
    add_action("touch","touch");
    add_action("mcolor","mcolor");
    add_action("sneak","sneak");
    add_action("learn","learn");
    add_action("view","view");
    add_action("remove_ln","rmve");
    add_action("recruit","recruit");
    add_action("fire_wall","firewall");
    add_action("new_title","new_title");
    add_action("dstrike","dstrike");
    add_action("ice","ice");
    add_action("crush","crush");
    add_action("levitate","levitate");
    add_action("sanc","sanc");
    add_action("mind_blast","mindblast");
    add_action("mind_blast","blast");
    add_action("quit", "quit");
    add_action("battle_who","bw");
    add_action("monk_say","msay");
    add_action("aura","aura");
    add_action("banish", "banish");
    add_action("chain_lightning", "cl");
    add_action("locate_tracer", "chktrace");
    add_action("follow", "follow");
    add_action("summon_swarm", "swarm");
    add_action("teleport", "teleport");
    add_action("locate_player","locate");
    add_action("fixme","fixme");
    add_action("bag", "magbag");
    add_action("guild_title","guild_title");
    add_action("mend_all","mendall");
    add_action("set_starting","setstart");
    add_action("beep_wiz","beep");
    add_action("read_news","news");
    add_action("help_files","mhelp");
    add_action("purge", "purge");
    add_action("monk_who", "mw");
    add_action("raise", "resurrect");
    add_action("chop","chop");
    add_action("cash","cash");
    add_action("gold" ,"gold");
    add_action("ration","ration");
    add_action("escape", "escape");
    add_action("get_staff","staff");
    add_action("nirvana_who","nirw");
    add_action("monk_pet","call");
    add_action("summon_pet","summons");
    add_action("pet_travel","travel");
    add_action("pet_exits","pexits");
    add_action("peteye","psee");
    add_action("pet_attack","attak");
    add_action("stat_monster","status");
    add_action("transfer","transfer");
    add_action("hp_mon","hpmon");
    add_action("peace","peace");
    add_action("heal_spell", "mheal");
    add_action("offering","offer");
    add_action("farsight","farsight");
    add_action("cast_light","cast");
    add_action("donate","$donate");
    add_action("equip_inv","einv");
    add_action("equip_take","etake");
    add_action("equip_put","eput");
    add_action("monk_kick","mkick");
    add_action("register","mend");
    add_action("muffles","mchan");
    add_action("rank","rank");
    add_action("rank","sk");
    add_action ("rank","sco");
    add_action("xsell","tithe");
    add_action("monk_tell","monk");
    add_action("burn","burn");
    add_action("monk_robe0","mr");
    add_action("monk_robe1","mr1");
    add_action("monk_robe2","mr2");
    add_action("monk_robe3","mr3");
    add_action("monk_robe4","mr4");
    add_action("monk_robe5","mr5");
    add_action("monk_robe6","mr6");

    if(this_player()->query_guild_rank() > 19) {
        add_action("gstat","gstat");
        add_action("amend","amend");
        add_action("promote_member","promo");
        add_action("robe", "robe");
        add_action("commander_tell","ct");
        add_action("commander_emote","ce");
        add_action("gxp_member","gxp");
    }
}

/*----------------------------------------------------------------------*/
/*      FUNCTIONS                                                       */
/*----------------------------------------------------------------------*/

save_stats() {
    save_object(DIR);
    write("Guild Stats Saving.......\n");
    write("Done.\n");
    return 1;
}

special_attack(){

    object obj;
    int when;

    obj = environment(this_object());
    when = 25 - obj->query_guild_rank();
    when = 25 - when;
    if(when < 15)  
        when = 15;
    command("sp_attack", obj);
    call_out("special_attack", when);
    return 1;
}

/* -------- MUFFLES -------------- */
muffles(str) {

    if(!str) {
        write("Usage: mchan <on/off>\n");
        return 1;
    }
    if(str == "off") {
        if(muffled == 1) {
            write("You aren't on the Monk Channel.\n");
            return 1;
        } else {
            muffled = 1;
            write("You close the Monk Channel.\n");
            return 1;
        }
    }
    if(str == "on") {
        if(muffled == 0) {
            write("You are already on the Channel.\n");
            return 1;
        } else {
            muffled = 0;
            write("Monk Channel is now open.\n");
            return 1;
        }
    }
}

quit() {

    object trace1,trace2;
	
    if(iquit == 0) {
        while(present("monk_obj",this_player())){
            destruct(present("monk_obj",this_player()));
        }
    iquit = 911;
    save_object(DIR);
    write("Saving guild stats...\n");
    command("quit",this_player());
    return 1;
    }
}

wear(str) {
    object what, ob;
    int ac, res;
    int silently;

    silently = 1;
    if(!str) {
        write("Wear what?\n");
        return 1;
    }

    what = present(str, ETO);
    if(!what) {
        write("No "+str+" present.\n");
        return 1;
    }
    if(str == "robes") {
        if(this_player()->query_guild_rank() < 5) 
            ac = 4;
        if(this_player()->query_guild_rank() >= 5) 
            ac = 8;
        if(this_player()->query_guild_rank() > 8) 
            ac = 11;
        write("You don the Dark Flowing Robes of the Order of the Hidden Path.\n");
        say(ME+" dons the Dark Flowing Robes of the Order of the Hidden Path.\n");
        set_params("physical",ac,res,"do_special");
        ob = call_other(this_player(), "wear", this_object(), silently, type, params);
        if(ob) {
            worn_by = this_player();
            worn = 1;
            return 1;
        }
        return 1;
    }
}
    
set_params(style,class,res2,special2){
   string cat, subcat;
   int i;
   if(!params) params = ({ });
   if(sscanf(style, "%s|%s",cat,subcat) !=2){ 
      if(style != "physical" && style != "magical") style = "physical";
   }
   else if(cat != "other") style = "physical";
   if(member_array(style,params) != -1){
      for(i=0;i<sizeof(params);i++){
         if(style == params[i]){
            params[i+1] = class;
            params[i+2] = res2;
            params[i+3] = special2;
            return;
         }
      }
   } 
   params += ({style,class,res2,special2});
}

short() {

    string tmp_short;

    if (!short_desc)
        return 0;

    if(!this_player()) return short_desc;
        tmp_short = short_desc;

    if (worn)
        return tmp_short + " (worn)";

    return tmp_short;
}

/*      Functions in the daemon object                                   */
sp_attack() { PAIN->sp_attack(); return 1; }
send(str) { PAIN->send(str); return 1; }
clock() {PAIN->clock(); return 1; }
set_starting() { PAIN->set_starting(); return 1; }
info_sheet(str) { PAIN->info_sheet(str); return 1; }
mcolor(str) { PAIN->mcolor(str); return 1; }
first_stat(str) { PAIN->first_stat(str); return 1; }
prayer() { PAIN->prayer(); return 1; }
lead () { PAIN->lead(); return 1; }
tornado_attack(str) { PAIN->tornado_attack(str); return 1; }
aid(str) { PAIN->aid(str); return 1; }
purse(str) { PAIN->purse(str); return 1; }
hurl(str) { PAIN->hurl(str); return 1; }
flame(str) { PAIN->flame(str); return 1; }
trip(str) { PAIN->trip(str); return 1; }
dtrip(str) { PAIN->dtrip(str); return 1; }
gc() {PAIN->gc(); return 1; }
touch(str) { PAIN->touch(str); return 1; }
sneak(str) { PAIN->sneak(str); return 1; }
mon() { PAIN->mon(); return 1; }
learn(str) { PAIN->learn(str); return 1; }
view() { PAIN->view(); return 1; }
remove_ln(str) { PAIN->remove_ln(str); return 1; }
recruit(str) {  PAIN->recruit(str); return 1; }
fire_wall(str) { PAIN->fire_wall(str); return 1; }
shield() { PAIN->shield(); return 1; }
alias_check(str) { PAIN->alias_check(str); return 1; }
do_do(str) { PAIN->do_do(str); return 1; }
swap(str) { PAIN->swap(str); return 1; }
new_title(str) { PAIN->new_title(str); return 1; }
ice(str) { PAIN->ice(str); return 1; }
crush(str) { PAIN->crush(str); return 1; }
levitate() { PAIN->levitate(); return 1; }
sanc() { PAIN->sanc(); return 1; }
mind_blast(str) { PAIN->mind_blast(str); return 1;  }
balance() { PAIN->balance(); return 1; }
battle_who() { PAIN->battle_who(); return 1; }
monk_say(str) { PAIN->monk_say(str); return 1; }
free_speech(str) { PAIN->free_speech(str); return 1; }
banish(str) { PAIN->banish(str); return 1; }
chain_lightning() { PAIN->chain_lightning(); return 1; }
gstat(str) { PAIN->gstat(str); return 1; }
amend(str) { PAIN->amend(str); return 1; }
promote_member(str) { PAIN->promote_member(str); return 1; }
robe(str) { PAIN->robe(str); return 1; }
commander_tell(str) { PAIN->commander_tell(str); return 1; }
commander_emote(str) { PAIN->commander_emote(str); return 1; }
gxp_member(str) { PAIN->gxp_member(str); return 1; }
locate_tracer() { PAIN->locate_tracer(); return 1; }
summon_swarm(str) { PAIN->summon_swarm(str); return 1; }
remove_tracer(str) { PAIN->remove_tracer(str); return 1; }
set_tracer() { PAIN->set_tracer(); return 1; }
teleport() { PAIN->teleport(); return 1; }
locate_player(str) { PAIN->locate_player(str); return 1; }
death_field() { PAIN->death_field() ; return 1; }
fixme() { PAIN->fixme(); return 1; }
bag() { PAIN->bag(); return 1; }
guild_title() { PAIN->guild_title(); return 1; }
mend_all() { PAIN->mend_all(); return 1; }
beep_wiz(str) { PAIN->beep_wiz(str); return 1; }
read_news() { PAIN->read_news(); return 1; }
help_files(str) { PAIN->help_files(str); return 1; }
monk_who() { PAIN->monk_who(); return 1; }
raise(str) { PAIN->raise(str); return 1; }
chop(str) { PAIN->chop(str); return 1; }
cash(str) { PAIN->cash(str); return 1; }
gold(str) { PAIN->gold(str); return 1; }
ration() { PAIN->ration(); return 1; }
escape() { PAIN->escape(); return 1; }
get_staff() { PAIN->get_staff(); return 1; }
nirvana_who() { PAIN->nirvana_who(); return 1; }
monk_pet(str) { PAIN->monk_pet(str); return 1; }
summon_pet() { PAIN->summon_pet(); return 1; }
pet_travel(str) { PAIN->pet_travel(str); return 1; }
pet_exits() { PAIN->pet_exits(); return 1; }
peteye(str) { PAIN->peteye(str); return 1; }
pet_attack(str) { PAIN->pet_attack(str); return 1; }
stat_monster(str) { PAIN->stat_monster(str); return 1; }
transfer(str) { PAIN->transfer(str); return 1; }
peace() { PAIN->peace(); return 1; }
heal_spell(str) { PAIN->heal_spell(str); return 1; }
offering(str) { PAIN->offering(str); return 1; }
farsight(str) { PAIN->farsight(str); return 1; }
cast_light(str) { PAIN->cast_light(str); return 1; }
donate(str) { PAIN->donate(str); return 1; }
equip_inv() { PAIN->equip_inv(); return 1; }
equip_take(str) { PAIN->equip_take(str); return 1; }
equip_put(str) { PAIN->equip_put(str); return 1; }
monk_kick(str) { PAIN->monk_kick(str); return 1; }
register() { PAIN->register(); return 1; }
rank() { PAIN->rank(); return 1; }
xsell(str) { PAIN->xsell(str); return 1; }
monk_tell(str) { PAIN->monk_tell(str); return 1; }
monk_emote(str) { PAIN->monk_emote(str); return 1; }
burn(str) { PAIN->burn(str); return 1; }
monk_robe0() { PAIN->monk_robe0(); return 1; }
monk_robe1() { PAIN->monk_robe1(); return 1; }
monk_robe2() { PAIN->monk_robe2(); return 1; }
monk_robe3() { PAIN->monk_robe3(); return 1; }
monk_robe4() { PAIN->monk_robe4(); return 1; }
monk_robe5() { PAIN->monk_robe5(); return 1; }
monk_robe6() { PAIN->monk_robe6(); return 1; }
