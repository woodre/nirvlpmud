/******************************************
* Filename: Symbol.c             
* 
* Description:
* The main guild object for the Decepticon
* guild.  This is what a player will carry
*
*
* Revision History:
* 
* 7/31/99  Initial Creation
*
*
*******************************************/

string *Forms;
static string Form;
static int Energon;
string Base;

#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Defs.h"
#include "/players/beck/Lib/Resource.c"

id(str){
   return str == "symbol" ||
          str == "guild_object" ||
          str == "decepticon_object";
}

query_auto_load(){ 
   return AUTOLOAD;
}

short(){
   return 0;
}

long(){
   write("The symbol of a Decepticon.\n"+
      "Type 'info' for information.\n"+
      "");
   return 1;
}

extra_look(){
   return "The Symbol of a Decepticon";
}

init_arg(){
   restore_object(SAVEDIR+TP->RNAME);
if(TP->query_level() < 19 || TP->RNAME == "beck"){
   TP->set_guild_name(GUILDNAME);
   ENERGONDAEMON->ADecepticon(TO);
}
}


init(){
   int i;
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         add_action("quit","quit");
         for (i=0; i<sizeof(COMMANDS); i++){
            add_action("DecepticonCommand",COMMANDS[i]);
         }
         Forms = ({"Robot","Jet","Tank",});
      }
   }
}

DecepticonCommand(str){
   string verb;
   verb = GUILDDIR+"Commands/"+capitalize(query_verb())+"";
   return verb->DecepticonCommand(str);
}

get(){
   return 1;
}

drop(){
   return 1;
}

quit(){
   if(ENV(ENVOB)->realm() != "NT")
      ENVOB->set_home(file_name(ENV(ENVOB)));
   else if(Base)
      ENVOB->set_home(Base);
   else
      ENVOB->set_home("/room/church");
   save_object(SAVEDIR+TP->RNAME);
}

SForm(arg){
   Form = arg;
}

QForm(){
   return Form;
}

QForms(){
   return Forms;
}

SBase(string str){
   Base = str;
   save_object(SAVEDIR+TP->RNAME);
}

QBase(){
   return Base;
}
