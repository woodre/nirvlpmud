call(str) {
int nm,a;
object fun;
  if(!str) { write("call <type of animal>\n"+
                   "Types are:\n");
             for(nm=0;nm<sizeof(animal);nm++) 
             if(!a) { write("          "+animal[nm]); a = 1; }
             else { write("   "+animal[nm]); 
                    if(a == 1) a = 2; else { write("\n"); a = 0; }
                  }
             return 1; }
  if(member_array(str,animal) == -1) {
     write("That is not an animal listed.\n");
  return 1; }
  if(present("myth_essence",tp)) { 
    write("You already have the animal's strength!\n");
    tp->hit_player(50);
    write("Do not ask for more!\n");
  return 1; }
  fun = clone_object("/players/mythos/myth/shape/spells/mon.c");
  fun->set_who(tp);
  fun->set_what(str);
  move_object(fun,etp);
  write("\n");
  fun->attack_object(tp);
return 1; }