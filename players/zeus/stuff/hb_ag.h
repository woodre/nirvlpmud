object envir;
object ack;
int q,qq,kkk;

heart_beat() {
  ::heart_beat();
  if(!environment()) return;
     if(!query_attack()) {
     if(!random(10)) {
       envir = 0;
       ack = allocate(10);
       qq = 0;
        kkk = 0;
        envir = all_inventory(environment(this_object()));
      for(q=0;q<sizeof(envir);q++) { 
       if(envir[q]->is_player()) {
          ack[qq] = envir[q];
          qq++; }
      }
      q = 0;
        while(q<sizeof(ack) && !kkk) {
           if(ack[q] && !random(5)) {
              attack_object(ack[q]);
              kkk = 1;
           }
        q++; } 
      }
  } else if(query_attack() && query_attack() == this_object()) {
    heal_self(100000); }
}
