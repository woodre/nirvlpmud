
get(){ return 1; }
id(){ return "ear" || "combo"; }
int combo;
short(){ return "A rabbit ear"; }
query_combo(){ return combo; }
long(){
     write("A rabbit ear.  There appears to be something written on it.\n");
}
init(){
     add_action("read", "read");
     combo = random(1000);
}

read(str){
   if(str == "ear"){
     write("The combination is "+combo+"\n");
     return 1;}
}
