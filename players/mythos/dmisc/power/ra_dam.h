#define TEK this_player()->query_name()
ra_dam(int n) {
string dork,null;
string waka;
string ichi,ni,san;
  if(n < 0) n = -n;
  sscanf(previous_object(),"%s#%s",dork,null);
  if(dork != "players/mythos/dmisc/power/play" &&
     dork != "players/mythos/dmisc/power/pluck" &&
     dork != "players/mythos/dmisc/power/mon") {
     destruct(previous_object());
     return 1; }
  if(living(this_object())) waka = this_object()->query_name();
  else waka = environment(this_object())->query_name();
  if(n < 2) { 
    ichi = TEK+" misses.";
    ni = "Your attack fades before doing any damage.";
    san = TEK+" misses you.";
  } else 
    if(n < 5) {
      ichi = waka+" dodges some of the attack from "+TEK+".";
      ni = "Your target dodges some of attack.";
      san = "You dodge some of "+TEK+"'s attack.";
    } else 
      if(n < 10) {
        ichi = TEK+"'s attack blasts into "+waka+"!";
        ni = "The attack blasts into "+waka+"!";
        san = TEK+"'s attack blasts into you!";
      } else 
        if(n < 20) {
          ichi = waka+" is smashed backwards by "+TEK+"'s attack!";
          ni = waka+" is smashed backwards by your attack!";
          san = "You are smashed backwards by "+TEK+"'s attack!";
        } else 
          if(n < 30) {
            ichi = "Energy from "+TEK+" "+RED+"blasts"+NORM+" into "+waka+"!";
            ni = RED+"Bloodlust"+NORM+" fills you as you blast energy into "+
                    waka+"!";
            san = "Energy from "+TEK+" "+RED+"blasts"+NORM+" into you!";
          } else {
              ichi = "Raw "+BLU+"energy"+NORM+" from "+TEK+" tears into "+
                     waka+"!";               
              ni = "Raw "+BLU+"energy"+NORM+" tears into "+waka+"!"; 
              san = "Raw"+BLU+" energy"+NORM+" from "+TEK+" tears into you!";
          }
  nanda(ichi+"\n",this_player());
  tell_object(this_player(),ni+"\n");
  if(living(this_object())) tell_object(this_object(),san+"\n");
  else tell_object(environment(this_object()),san+"\n");
  if(living(this_object())) hit_point -= n;
  else environment(this_object())->add_hit_point(-n);
  if(living(this_object())) {
    if(!attacker_ob) hit_player(1);
  }
  else if(!environment(this_object())->query_attack()) 
      environment(this_object())->hit_player(1);   
 if(living(this_object())) { if(hit_point < 0) hit_point = 0; }
return 1; }

nanda(string nani,object left) {
object mina;
int v,hh;
 hh = 0;
   if(living(this_object())) hh = 1;
   if(hh) mina = all_inventory(environment(this_object()));
   else mina = all_inventory(environment(environment(this_object())));
   for(v=0;v<sizeof(mina);v++) {
     if(!hh) if(mina[v] != environment(this_object())) hh = 1;
     if(living(mina[v]) && mina[v] != left && hh) {
       tell_object(mina[v],nani); }
       hh = 1;}
}
