#include "/players/pavlik/closed/colors.h"

short(){ return "An Askeonwood Table"; }

long(){
  write(
  "The origins of this ancient artifact are unknown but is has\n"+
  "been discovered that the Askeonwood contains powerful magic\n"+
  "within its grain.  The Mage's have held council around this\n"+
  "table for countles centuries.\n"+
  "The table feels warm to your touch.\n");

  return;
}

query_weight(){ return 1000; }

query_value(){ return 0; }

drop(){ return 1; }

reset(arg){
  if(arg) return;
}

id(str){
  return str == "table" || str == "askeon-wood"  ||
    str == "askeon wood" || str == "askeon" || str == "wood";
}


