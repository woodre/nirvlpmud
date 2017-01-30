#include "/players/maledicta/ansi.h"
#define USER environment()

int uses;

short(){ return HIR+"Bandages ["+HIW+uses+HIR+"]"+NORM; }

long(){
 write(
 "This is a roll of bandages which are used to help out\n"+
 "someone trained in first aid.  If you do not have first\n"+
 "aid training, they are useless to you.\n");
 return 1;
 }

id(str){ return str == "first_aid_bandages_prof" || str == "bandages"; }

reset(arg){
  if(arg) return;
  uses = 3;
  }

used(){ 
uses -= 1; 
if(!uses){
 tell_object(environment(),
 "You use up the last of the bandages.\n");
 environment()->recalc_carry();
 destruct(this_object());
 return 1;
 } 
}

set_uses(int i){ uses = i; }
query_uses(){ return uses; }

query_weight(){ 
if(uses) return 1;
else return 0;
}

get(){ return 1; }

query_value(){ return uses * 20; }

query_save_flag(){ return 1; }
