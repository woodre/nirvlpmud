#include "/players/dune/closed/guild/DEFS.h"

int NUMATTACKS;
int basexp;
int beltlevel;
int chiplevel;

string seq1list,seq2list,seq3list,seq4list;

id(str){ return str == "ci"; }
short(){ return "Cybernetic Implants"; }
long(){
  write("Cybernetic Implants. blah blah blah.\n");
}
get(){ return 1; }
drop(){ 
  if(environment() && environment()->is_player()){
    if((int)environment()->query_exp() < basexp){
      basexp = (int)environment()->query_exp(); 
    }
  }
  return 1;
}

reset(){
  NUMATTACKS = 5;
  seq1list = "chop chop chop chop chop";
  seq2list = "parry thrust dodge dodge";
}

init(){
    add_action("seq1","seq1");
    add_action("seq2","seq2");
    add_action("seq3","seq3");
    add_action("seq4","seq4");
}

seq1(){
  doit(seq1list);
  return 1;
}

seq2(){ 
  doit(seq2list);
  return 1;
}

doit(str){
int i,a;
string commandlist;
  commandlist = explode(str," ");
  for(i=0,a=NUMATTACKS;i<a;i++){
    command(commandlist[i],this_player());
  }
return 1;
}

set_beltlevel(i){ beltlevel = i; }
set_chiplevel(i){ chiplevel = i; }

query_beltlevel(){ return beltlevel; }
query_chiplevel(){ return chiplevel; }
