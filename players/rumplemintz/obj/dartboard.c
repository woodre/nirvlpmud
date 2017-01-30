inherit "obj/treasure";
int num_darts;
object eyes;
int num_dart;
reset(arg){
   refresh_desc();
   if(arg) return;
   set_short("A Dartboard");
   num_dart=0;
   set_id("dartboard");
   set_long("A dartboard... whaddya expect?!?\n");
   set_weight(0);
   set_value(0);
}
get(){write("It is attached to the wall.\n"); return 0;}
long(){write("A dartoboard... whaddya expect?!?\n");}

refresh_desc(){
   set_short("Dartboard with "+query_dart()+" darts stuck in it");
   return;}

set_dart(arg){num_dart=query_dart()+arg;
   if(num_dart>100){num_dart=100;}
   refresh_desc();}
query_dart(){return num_dart; refresh_desc();}
