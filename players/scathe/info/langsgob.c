/*
 *  The MOB Guild Object
 * 
 */

#include "mob.h"

int mtitle;          /*  soldier, hitman, lieutenant, don, godfather, wiz.  */
string family;        /*  The family name  */
string gun;        /*  The type of gun carried  */

int graft;            /*  Accumulated graft  */

int restore_member();
int save_member();

void set_mtitle(int i);

id(str){
   return str == "guild_object" || str == "GUILD_OB" || str == "guild_ob" ||
          str == "mob_ob" || str == "MOB_OB";
}

short() {
   string msg;

   msg = "A thomson sub-machine gun";
   return msg;
}

void long() {
   write(
"Type 'guild_help' for more information.\n");
}

query_auto_load(){ return AUTOLOAD; }

void init(){
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         if(TP->query_level() < 20){
            TP->set_guild_name(GUILDNAME);
         }
         if((string)TPRN == "languilen" || (string)TPRN == "cosmo"){
            TP->set_guild_rank(15);
            set_mtitle(6);
         }
         if(!restore_member()){
            write("Could not restore stats.  Creating new mobster...\n");
            save_member();
         }
         if(!TP->query_guild_rank()) TP->set_guild_rank(1);
         add_action("guild_help","guild_help");
         add_action("save_member","msave");
         add_action("dest_guild_ob","un_guild");
         add_action("mob_who","mwho");

      }
   }
}

save_member(){
     string path;
     path = GUILDSAVE+(string)ENVOB->query_real_name();
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
     return 1;
}

get(){ return 1;}
drop(){ return 1;}

guild_help(){
    cat(GUILDDIR+"help/basic_help.txt");
    return 1;
}

dest_guild_ob(){
    write("Guild obj destroyed...\n");
    destruct(this_object());
    return 1;
}

/*  guild vars  */

set_mtitle(i){
     mtitle = i;
}
query_mtitle(){
     return mtitle;
}

set_family(str){
     family = str;
}
query_family(){
     return family;
}

add_graft(i){
     graft += i;
}
query_graft(){
     return graft;
}

/*  Commands  */

mob_who(){ return (int)GUILD_D->mob_who(); }



