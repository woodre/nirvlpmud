static status FatalityTemp;
string *Fatality;
int MKChampion;

SFatalityTemp(){ FatalityTemp = 1; }


Fatality(){
   int damage;
   string name;
   object attk;
   if(!FatalityTemp)
      return;
   if(!environment(this_object())->query_attack())
      return;
   attk = environment(this_object())->query_attack();
   name = attk->query_name();
   damage = QMKScore()/20;
   attk->hit_player(damage);
   if(!attk || attk->query_ghost()){
      tell_room(environment(environment(this_object())), FatalityMess(name));
      FatalityTemp = 0;
      return;
   }
   if(!MKChampion)
      FatalityTemp = 0;
   return;
}

FatalityMess(string name){
   if(!Fatality)
      return "You perform a fatality on "+name+"\n";
   return Fatality[0]+" "+name+" "+Fatality[1]+"\n";
}

