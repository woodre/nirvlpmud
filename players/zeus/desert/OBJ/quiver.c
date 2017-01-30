inherit "obj/treasure.c";
int c;

reset(arg){
  if(arg) return;
  c = 20+random(15);
}

short(){ return "A quiver of "+c+" arrows"; }

long(){
  write(    
    "This is a finely crafted quiver holding "+c+" arrows.\n"+
    "Each arrow is very well made and has a sharp metal tip.\n"); }

weight(){ return 1; }

query_value(){ return 110; }

id(str){ return str == "quiver" || str == "zeus_quiver"; }

query_arrows(){ return c; }
use_arrow(){ c--; }
