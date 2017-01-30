/*
 *  The MOB Guild Object
 *
 */

#include "/players/languilen/closed/ansi.h"
#include "mob.h"

static mapping minfo = ([]);    /*  Mobsters personal information  */
static mapping guns = ([]);     /*  The guns owned and how loaded they are  */
string gunlist;          /*  A saveable list of guns and loaded ammo  */
string minfo_data;       /*  A saveable list of personal information  */

int restore_member();
int save_member();

void set_mtitle(int i);
int query_mtitle();
void set_family(string str);
string query_family();

/* mapping minfo = ([ "mtitle":0, "family":0, "gun":0, "load":0, "icer":0, "iced":0, "graft":0, "muffle":0, "made":0, "retired":0 ]);
*/


id(str){
   return str == "guild_object" || str == "GUILD_OB" || str == "guild_ob" ||
          str == "mob_ob" || str == "MOB_OB";
}

short() {
     string msg;

     switch(query_gun()){
            case "22":{
                      msg = "A .22 caliber luger";
                      break;
            }
            case "38":{
                      msg = "A .38 special";
                      break;
            }
            case "45":{
                      msg = "A nickle plated .45";
                      break;
            }
            case "44":{
                      msg = "A .44 magnum";
                      break;
            }
            case "silencer":{
                      msg = "A silenced .22";
                      break;
            }
            case "thomson":{
                      msg = "A tommy gun";
                      break;
            }
            default:{
                      msg = 0;
                      break;
            }
     }
     return msg;
}

void long() {
   write(
"Type 'mhelp' for more information.\n");
}

query_auto_load(){ return AUTOLOAD; }

void init(){
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         if(!restore_member()){
            write("Could not restore stats.  Creating new mobster...\n");
            save_member();
            restore_member();
         }
         if(TP->query_level() > 20){
            if((string)TPRN == "languilen" || (string)TPRN == "cosmo"){
	      /*  TP->set_guild_rank(15);  */
               set_mtitle(7);
               set_family("all");
            } else {
               set_mtitle(6);
               set_family("all");
            }
         }
         if(TP->query_level() < 20){
            TP->set_guild_name(GUILDNAME);
            if(!TP->query_guild_rank()) TP->set_guild_rank(1);
         }

         if(minfo["family"]){                    /*  Family Cmds  */
            if( query_mtitle() > 6 ){   /*  Guild Wiz Cmds  */
            }

            if( query_mtitle() > 5 ){   /*  Guest Wiz Cmds  */
                add_action("mlog_cmd", "mlog");
            }

            if( query_mtitle() > 4 ){   /*  Godfather Cmds  */
                add_action("make_cmd", "make");
                add_action("retire_cmd", "retire");
            }

            if( query_mtitle() > 3 ){   /*  Don Cmds  */
                add_action("contract_cmd", "contract");
            }

            if( query_mtitle() > 2 ){   /*  Lieutenant Cmds  */
                add_action("account_cmd", "account");
                add_action("feast_cmd", "feast");
                add_action("plate_cmd", "plate");
            }

            if( query_mtitle() > 1 ){   /*  Hitman Cmds  */
                add_action("contracts_cmd", "contracts");
            }

            /*  Soldier Cmds  */
            add_action("fam_cmd","fam");
            add_action("ice_cmd","ice");
            add_action("unice_cmd","unice");
         }  /*  End Family Cmds  */

         /*  Wiseguy Cmds  */
         if( TP->query_guild_rank() > 6 || query_mtitle() > 4 ){
             add_action("driveby_cmd", "driveby");
             add_action("blackmail_cmd","blackmail");
         }

         /*  Mafioso Cmds  */
         if( TP->query_guild_rank() > 5 || query_mtitle() > 4 ){
             add_action("concrete_cmd", "concrete");
             add_action("smash_cmd","smash");
             add_action("spray_cmd","spray");
         }

         /*  Goodfella Cmds  */
         if( TP->query_guild_rank() > 4 || query_mtitle() > 4 ){
             add_action("kidnap_cmd", "kidnap");
             add_action("molotov_cmd","molotov");
         }

         /*  Racketeer Cmds  */
         if( TP->query_guild_rank() > 3 || query_mtitle() > 4 ){
             add_action("trophy_cmd", "trophy");
         }

         /*  Muscle Cmds  */
         if( TP->query_guild_rank() > 2 || query_mtitle() > 4 ){
             add_action("block_cmd", "block");
             add_action("butt_cmd", "butt");
             add_action("protect_cmd", "protect");
         }

         /*  Thug Cmds  */
         if( TP->query_guild_rank() > 1 || query_mtitle() > 4 ){
             add_action("garrote_cmd", "garotte");
         }

         /*  Bullie Cmds  */
         add_action("mhelp_cmd", "mhelp");
         add_action("save_member", "msave");
         add_action("dest_guild_ob", "un_guild");
         add_action("mwho_cmd", "mwho");
         add_action("mob_cmd", "mob");
         add_action("intimidate_cmd", "intimidate");
         add_action("bash_cmd", "bash");
         add_action("eyeball_cmd", "eyeball");
         add_action("guns_cmd", "guns");
         add_action("pull_cmd", "pull");
         add_action("load_cmd", "load");
         add_action("pack_cmd", "pack");
         add_action("shoot_cmd", "shoot");

      }
   }
}

save_member(){
     string path;
     path = GUILDSAVE+(string)ENVOB->query_real_name();
     minfo_data = GUILD_D->save_minfo(minfo);
     gunlist = GUILD_D->save_guns(guns);
     save_object(path);
     tell_object(ENVOB, "Saving guild stats!\n");
     return 1;
}

restore_member(){
     string path;
     if(!ENVOB){ return 1; }
     path = GUILDSAVE+(string)ENVOB->query_real_name();
     if(!restore_object(path)){
        return 0;
     } else {
         tell_object(ENVOB, "Restoring guild stats.\n");
     }
     minfo = GUILD_D->load_minfo(minfo_data);
     guns = GUILD_D->load_guns(gunlist);
     return 1;
}

get(){ return 1;}
drop(){ return 1;}

dest_guild_ob(){
    write("Guild obj destroyed...\n");
    destruct(this_object());
    return 1;
}

/*  guild vars  */

set_mtitle(i){
     if(!minfo["mtitle"]){
        minfo = (["mtitle":i]);
        return;
     }
     minfo["mtitle"] = i;
}
query_mtitle(){
     return minfo["mtitle"];
}

set_family(str){
     minfo["family"] = str;
}
query_family(){
     return minfo["family"];
}

add_graft(i){
     minfo["graft"] += i;
}
query_graft(){
     return minfo["graft"];
}
set_iced(i){
     minfo["iced"]=i;
}
query_iced(){
     return minfo["iced"];
}
set_made(){
     minfo["made"] = 1;
}
query_made(){
     return minfo["made"];
}
query_muffle(){
     return minfo["muffle"];
}
set_muffle(){
     if(!minfo["muffle"]) minfo["muffle"] = 0;
     if(!minfo["muffle"]) minfo["muffle"] = 1;
     else minfo["muffle"] = 0;
}
set_retired(i){
     minfo["retired"]=i;
}
query_retired(){
     return minfo["retired"];
}
set_icer(string str){
     minfo["icer"]=str;
}
query_icer(){
     return minfo["icer"];
}
set_gun(string str){           /*  To set pulled gun  */
     minfo["gun"] = str;
}
string query_gun(){                   /*  To Find the pulled gun  */
     return minfo["gun"];
}
add_guns(string str){          /*  To add a gun to the list of guns owned  */
     if(!guns){
        guns = ([str:0]);
     } else { guns += ([str:0]); }
}
save_guns_ammo(){                   /*  Saves the new amount of ammo to the list  */
     guns[query_gun()] = minfo["load"];  /*  used when packing the gun  */
}
query_guns(string str){        /*  See if specific gun is in our list  */
     if( member_array(str, keys(guns)) >-1 ) return 1;
     return 0;
}
mapping query_all_guns(){      /*  Returns all the guns and ammo owned  */
     return guns;
}
query_guns_ammo(string gun){   /*  Returns the ammo of a stored gun  */
     return guns[gun];         /*    used with pull <gun>  */
}
add_ammo(int i){               /*  Alters the ammo level of the current gun  */
     minfo["load"] += i;
}
query_ammo(){        /*  Returns the ammo level of the current gun  */
     return minfo["load"];
}

/*  Commands  */

/*
 *  Mob G-Wep Abilities
 */

guns_cmd(str){ return (int)GUILD_D->guns_cmd(str); }
pull_cmd(str){ return (int)GUILD_D->pull_cmd(str); }
load_cmd(str){ return (int)GUILD_D->load_cmd(str); }
pack_cmd(str){ return (int)GUILD_D->pack_cmd(str); }
shoot_cmd(str){ return (int)GUILD_D->shoot_cmd(str); }
spray_cmd(str){ return (int)GUILD_D->spray_cmd(str); }

/*
 *  Mob Combat Abilities
 */

bash_cmd(str){ return (int)GUILD_D->bash_cmd(str); }
butt_cmd(str){ return (int)GUILD_D->butt_cmd(str); }
garrote_cmd(str){ return (int)GUILD_D->garrote_cmd(str); }
smash_cmd(str){ return (int)GUILD_D->smash_cmd(str); }
molotov_cmd(str){ return (int)GUILD_D->molotov_cmd(str); }
driveby_cmd(str){ return (int)GUILD_D->driveby_cmd(str); }

/*
 *  Mob Title Abilities
 */

make_cmd(str){ return (int)GUILD_D->make_cmd(str); }
retire_cmd(str){ return (int)GUILD_D->retire_cmd(str); }
assign_cmd(str){ return (int)GUILD_D->assign_cmd(str); }
accoount_cmd(str){ return (int)GUILD_D->account_cmd(str); }
feast_cmd(str){ return (int)GUILD_D->feast_cmd(str); }
plate_cmd(str){ return (int)GUILD_D->plate_cmd(str); }
contract_cmd(str){ return (int)GUILD_D->contract_cmd(str); }
contracts_cmd(str){ return (int)GUILD_D->contracts_cmd(str); }
ice_cmd(str){ return (int)GUILD_D->ice_cmd(str); }
unice_cmd(str){ return (int)GUILD_D->unice_cmd(str); }

/*
 *  Mob Grafting Abilities
 */

intimidate_cmd(str){ return (int)GUILD_D->intimidate_cmd(str); }
block_cmd(str){ return (int)GUILD_D->block_cmd(str); }
blackmail_cmd(str){ return (int)GUILD_D->blackmail_cmd(str); }
kidnap_cmd(str){ return (int)GUILD_D->kidnap_cmd(str); }
protect_cmd(str){ return (int)GUILD_D->protect_cmd(str); }

/*
 *  Mob Misc Abilities
 */

mlog_cmd(str){ return (int)GUILD_D->mlog_cmd(str); }
mhelp_cmd(str){ return (int)GUILD_D->mhelp_cmd(str); }
mwho_cmd(){ return (int)GUILD_D->mwho_cmd(); }
mob_cmd(str){ return (int)GUILD_D->mob_cmd(str); }
fam_cmd(str){ return (int)GUILD_D->fam_cmd(str); }
eyeball_cmd(str){ return (int)GUILD_D->eyeball_cmd(str); }
bagman_cmd(str){ return (int)GUILD_D->bagman_cmd(str); }
trophy_cmd(str){ return (int)GUILD_D->trophy_cmd(str); }
concrete_cmd(str){ return (int)GUILD_D->concrete_cmd(str); }

/*
 *  Mob Atmosphere Abilities
 */







