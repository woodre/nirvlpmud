#define LINE write(pad("",40,'=')+"\n")
main(){
   int i;
   mixed victims;
   victims = previous_object()->QMKVictims();
   if(!victims)
       return 0;
   LINE;
   write(pad("Victims:",24)+"Number of kills:\n");
   LINE;
   for(i=0; i<sizeof(victims); i++){
      write(pad(victims[i],31)+victims[i+1]+"\n");
      i = i+1;
   }
   write("              Score: "+previous_object()->QMKScore()+"\n");
   LINE;
   return 1;
}
