/*
 * The Travelers Guild Object
 * Created by languilen for Nirvana.
 * Last changed
*/

#include "guilddefs.h"

static object mod;

int restore_member();
void save_member();

id(str){ 
   return str == "trav_ob" ||
   str == "TRAV_OB" || str == "implant";
}

short() {
   string msg;
   msg = "A cereberal implant";
   return msg;
}

long() {
     write(
"    The implant is a small metal rectangle located just behind the\n\
right ear.  It enables you to link with your module.  Type 'thelp' for\n\
more information.\n");
}

query_auto_load(){ return AUTOLOAD; }

init_arg() {
   if(restore_member()){
      write("Restoring Travel info...\n");
   } else {
      save_member();
      write("Guild info created.\n");
   }
   return;
}

void init(){
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         if(TP->query_level() < 20){
            TP->set_guild_name(GUILDNAME);
            TP->set_title( (string)GUILD_D->query_guild_title() );
         }
         add_action("guild_help","thelp");
         add_action("dest_guild_ob","un_guild");
         add_action("guild_cmd"); add_xverb("");
         add_action("update_member"); add_verb("tsave");
      }
   }
}

void save_member(){
     save_object(GUILDSAVE+ENVOB->query_real_name());
     if(mod){
        mod->save_module();
        write("Module information saved.\n");
     }
     write("Travel information saved.\n");
}

restore_member(){
     string file;
     file=GUILDSAVE+(string)TP->query_real_name();
     if(restore_object(file)){ return 1; } else { return 0; }
}
update_member(){
     save_member();
     restore_member();
     return 1;
}

get(){ return 1;}
drop(){ return 1;}

guild_cmd(str){ return (int)GUILD_D->guild_cmd(str); }

guild_help(){
    cat(GUILDDIR+"basic_help.txt");
    return 1;
}
dest_guild_ob(){
    write("Guild obj destroyed...\n");
    destruct(this_object());
    return 1;
}

/*  guild vars  */

/*  Module Related Functions   */

object query_mod(){
       if( !mod ){ mod = clone_object( MODULE ); }
       return mod;
}

/*
 * The Travelers Timed attacks.
*/

timeslice_ticker(){}
     
