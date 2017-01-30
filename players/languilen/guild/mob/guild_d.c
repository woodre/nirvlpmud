/*
 *  The Mob guild daemon.
 */

#include "/players/languilen/closed/ansi.h"
#include "mobdefs.h"

static mapping graft;
static int mobtime;
string graftlist;

void load_master();
void save_master();
void start_timer();

id(str){ return str == "master" || str == "mob_master"; }
short(){
     return "The Mob guild's master object";
}
void long(){
     write("This is the master object for the mob guild.\n\
Do NOT Touch it!\n");
}

reset(arg){
     if(arg) return;

     load_master();
     if(!graft) graft = ([]);
     if(!graftlist) graftlist = "";
     start_timer();
     move_object(this_object(), "/players/languilen/workroom.c");
     return;
}

init(){
     if(TPRN == "languilen" || TPRN == "cosmo"){
        add_action("kill_master","kill_master");
     }
}

get(){ return 0; }

/*  Mob Atmosphere Abilities  */

/* #include "power/atmosphere.h" */

/*
 *  Mob Combat Abilities:
 *
 *  bash_cmd(string str)
 *  butt_cmd(string str)
 *  garrote_cmd(string str)
 *  smash_cmd(string str)
 *  molotov_cmd(string str)
 *  driveby_cmd(string str)
 */

#include "power/bash.h"
#include "power/butt.h"
#include "power/garrote.h"
#include "power/smash.h"
#include "power/molotov.h"
#include "power/driveby.h"

/*
 *  Mob G-Wep Abilities
 *
 *  guns_cmd(string str)
 *  pull_cmd(string str)
 *  load_cmd(string str)
 *  pack_cmd(string str)
 *  shoot_cmd(string str)
 *  spray_cmd(string str)
 */

#include "power/guns.h"
#include "power/pull.h"
#include "power/load.h"
#include "power/pack.h"
#include "power/shoot.h"
#include "power/spray.h"

/*
 *  Mob Title Abilities
 *
 *  make_cmd(string str)
 *  retire_cmd(string str)
 *  assign_cmd(string str)
 *  account_cmd(string str)
 *  feast_cmd(string str)
 *  plate_cmd(string str)
 *  contract_cmd(string str)
 *  contracts_cmd(string str)
 *  ice_cmd(string str)
 *  unice_cmd(string str)
 */

#include "power/make.h"
#include "power/retire.h"
#include "power/assign.h"
#include "power/account.h"
#include "power/feast.h"
#include "power/plate.h"
#include "power/contract.h"
#include "power/contracts.h"
#include "power/ice.h"
#include "power/unice.h"

/*
 *  Mob Grafting Abilities
 *
 *  intimidate_cmd(string str)
 *  block_cmd(string str)
 *  blackmail_cmd(string str)
 *  kindnap_cmd(string str)
 *  protect_cmd(string str)
 *
 *  -- Graft Utility Functions--
 *  int find_graft(object who)
 */

#include "power/intimidate.h"
#include "power/block.h"
#include "power/blackmail.h"
#include "power/kidnap.h"
#include "power/protect.h"
#include "power/graft.h"

/*
 *  Mob Misc Abilities
 *
 *  mlog_cmd(string str)
 *  mhelp_cmd(string str)
 *  mwho_cmd(string str)
 *  mob_cmd(string str)
 *  fam_cmd(string str)
 *  eyeball_cmd(string str)
 *  bagman_cmd(string str)
 *  trophy_cmd(string str)
 *  concrete_cmd(string str)
 *
 *  --filters for the various who lists--
 *
 *  int filter_invis(object who)
 *  int filter_mob(object who)
 *  int filter_fam(object who)
 */

#include "power/mlog.h"
#include "power/mhelp.h"
#include "power/mwho.h"
#include "power/mob.h"
#include "power/fam.h"
#include "power/eyeball.h"
#include "power/bagman.h"
#include "power/trophy.h"
#include "power/concrete.h"
#include "power/misc.h"

/*
 *   Family graft handling functions.
 *   These keep track of all of the families graft pools.
 *
 *   int query_graft(string family)
 *   void add_graft(string family, int amount)
 *   mapping query_all_graft()
 */

query_graft(string family){
     if(!graft[family]) return 0;
     return graft[family];
}

add_graft(string family, int amount){
     if( member_Array(family,keys(graft))<0 ) graft += ([family:amount]);
     else graft[family] += amount;
}

mapping query_all_graft(){
     return graft;
}

/*
 *  Utility Functions
 *
 *  string ability_check(string, int)   -This is a check for players trying
 *    -  to use any guild power that requires graft.  It tests for
 *    -  retirement, on ice and enough graft.  It should be called from
 *    -  every ability that consumes graft (which is almost everything).
 *    -  It returns an appropriate error string or "" if there is none.
 */

string ability_check(string who, int cost){
       while(TPGO->query_iced()){
             return "You can't do that! "+TPGO->query_icer()+" has got you on ice!\n";
       }
       while(TPGO->query_retired()){
             return "Relax!  Enjoy the ocean and those boat drinks with the little\numbrellas.  You're retired!\n";
       }
       while(cost>TPGO->query_graft()){
             return "You don' got the juice to do that!  Go put the squeeze on sombody!\n";
       }
       return "";
}

/*
 *   Functions to translate the mobsters guild object variables
 *   to and from mappings into saveable string lists.
 *
 *   mapping load_minfo(string minfo_data)
 *   string save_minfo(mapping minfo)
 *   mapping load_guns(string gunlist)
 *   string save_guns(mapping guns)
 *   load_graft()
 *   save_graft()
 */

mapping load_minfo(string minfo_data){
     mapping minfo;

     minfo = ([]);

     if ( sscanf(minfo_data,"%s#%s#%s#%d#%s#%d#%d#%d#%d#%d", MOB_INFO ) != 10) {
         write("corrupted data!  Please mail Cosmo or Languilen.\n");
     }
     return minfo;
}

string save_minfo(mapping minfo){
     if(!minfo) minfo = ([ "mtitle": 0, "family": 0, "gun": 0, "load": 0, "icer": 0, "iced": 0, "graft": 0, "muffle": 0, "made": 0, "retired": 0 ]);
     return implode( ({ MOB_INFO }), "#" );
}

mapping load_guns(string gunlist){
     mapping guns;
     int ii;
     string ss;
     guns = ([]);

     while(strlen(gunlist)>3){
        if(sscanf(gunlist,"%s#%d#%s", ss, ii, gunlist)!=3){
           if(sscanf(gunlist,"%s#%d#", ss, ii)!=2){
              write("Gunlist read error!\n");
           }
        }
        guns += ([ ss: ii ]);
     }
     return guns;
}
string save_guns(mapping guns){
     int i;
     string *list;
     string gunlist;
     list = ({});
     gunlist ="";

     if(!guns) return gunlist;

     i=0;
     list = keys(guns);
     while(sizeof(list)>i){
          gunlist += list[i]+"#"+guns[list[i]]+"#";
     i++;
     }
     return gunlist;
}


load_graft(){
     int ii;
     string ss;
     object oob;
     graft = ([]);

     if(!graftlist || graftlist == "") return;
     while(strlen(graftlist)>3){
        if(sscanf(graftlist,"%s#%d#%s", ss, ii, graftlist)!=3){
           if(sscanf(graftlist,"%s#%d#", ss, ii)!=2){
              oob = find_player("languilen");
              if(oob) tell_object( oob, "Graftlist read error!\n");
              return;
           }
        }
        graft += ([ ss: ii ]);
     }
     return;
}
save_graft(){
     int i;
     string *list;
     string graftlist;
     list = ({});
     graftlist ="";

     if(!graft) return;

     i=0;
     list = keys(graft);
     while(sizeof(list)>i){
          graftlist += list[i]+"#"+graft[list[i]]+"#";
     i++;
     }
     return;
}

/*
 *   Mob timer functions.
 *
 *   int query_timer()
 *   void start_timer()
 *   void stop_timer()
 *   void mob_timer()
 */

int query_timer(){
     return mobtime;
}
start_timer(){
     if(!mobtime) mobtime = 0;
     call_out("mob_timer",3);
}
stop_timer(){
     remove_call_out("mob_timer");
     remove_call_out("mob_timer");
}
mob_timer(){
     remove_call_out("mob_timer");
     mobtime++;
     call_out("mob_timer",3);
}

/*
 *   Master object functions.
 *
 *   void shutdown()
 *   void load_master()
 *   void save_master()
 */

kill_master(){
     save_master();
     stop_timer();
     destruct(this_object());
     return 1;
}

load_master(){
     string path;

     path = GUILDSAVE+"master";
     restore_object(path);
     load_graft();
     return;
}
save_master(){
     string path;

     path = GUILDSAVE+"master";
     save_graft();
     save_object(path);
     return;
}


