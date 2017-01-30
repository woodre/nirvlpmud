int MKScore;

Killed(object ob){
   string name;
   if(ob)
      name = ob->query_name();
   else
      return;
   if(environment(environment(this_object()))->MKArea()){
      AMKWins(name);
      CalcMKScore();
      "/players/dragnar/MKScar/daemons/MKRank.c"->Insert(environment(this_object())->query_name(), name);
      save_me();
   }
   else if(ob->is_player()){
      ev_pkill(ob);
   }
   else
      return;
}

CalcMKScore(){
   int i;
   MKScore = ((sizeof(MKVictims)/2)*10);
   for(i=0; i<sizeof(MKVictims); i++){
      if(MKVictims[i+1] > 1)
         MKScore += ((MKVictims[i+1] - 1)*2);
      i = i+1;
   }
}

QMKScore(){
   return MKScore;
}

QMKVictims(){
   return MKVictims;
}
