#include "/players/maledicta/ansi.h"
#define USER environment()

int uses;

short(){ return HIG+"First Aid Kit ["+HIW+uses+HIG+"]"+NORM; }

long(){
 write(
 "  This is a small medical kit that can be used by those\n"+  
 "knowledgable in firstaid.  If you are not, then it is\n"+
 "nothing more than a fine decorative carrying case.\n");
 return 1;
 }

id(str){ return str == "first_aid_kit_prof" || str == "kit"; }

reset(arg){ 
 if(arg) return;
 uses = 3;
 }

used(){ 
uses -= 1; 
if(!uses){
 tell_object(environment(),
 "You use up the last of the first aid kits supplies.\n");
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

query_save_flag(){ return 1; }

get(){ return 1; }

query_value(){ return uses * 20; }

