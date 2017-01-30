
reset(arg){
  if(arg) return;
}

id(str){
  return str == "hide" || str == "alligator hide";
}

long(){
 write(
 "The beaten hide of what was once a very large alligator.\n"+
 "This tough hide would make an excellent pair of boots if\n"+
 "you could find someone to craft them for you.\n");
}

short(){ return "An alligator hide"; }

get(){ return 1; }

query_weight(){ return 0; }

query_value(){ return 20; }
