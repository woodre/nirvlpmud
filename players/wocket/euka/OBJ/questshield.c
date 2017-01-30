#include "/players/wocket/closed/ansi.h"
inherit "obj/armor.c";
int is_polished;

id(str){ return (str == "shield" || str == "mirrored shield" || str == "euka_quest_shield"); }
short(){
string str;
  if(is_polished)
  str = "A "+HIC+"mirrored"+OFF+" shield";
  else
  str = "A mud covered shield";
  if(worn)
  str += " (worn)";
  return str;
}

long(){
  if(is_polished){
  write("A hugh mirrored shield.  This shield protects most of your body\n"+
        "when you hold it up.  Its mirrored reflection glimmers in the\n"+ 
        "light.  It is very heavy.\n");
  }
  else{
  write("A hugh shield.  This shield protects most of your body\n"+ 
        "when you hold it up.  Dried mud covers most of its tarnished\n"+
        "body.  It is very heavy.\n");
  }
}

reset(arg){
  if(arg) return;
  set_ac(2);
  set_name("shield");
  set_type("shield");
  set_weight(7);
}

query_value(){
 if(is_polished) return 1000;
   return 150;
}

set_polish(i){  is_polished = i; }
query_polish(){ return is_polished; }

