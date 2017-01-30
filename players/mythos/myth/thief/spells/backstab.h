#define SPCOST 30
backstab(string str,int chance) {
object targ;
int bsdam;
 if(!str) { write("bst <name>\n"); return 1; }
 targ = present(str,etp);
 if(!targ) { write("That is not here to backstab.\n"); return 1; }
 if(!living(targ)) { write("That is not a living thing.\n"); return 1; }
 if(find_player(str) == targ) {
    write("Can not be used on a player.\n"); return 1; }
 if(chance < random(100)) {
    write("You are discovered in your attempt to backstab!\n");
    say(capitalize(tpn)+" trips and falls flat on "+tp->query_possessive()+
    " face.\n");
    targ->attack_object(tp);
    targ->set_wc(targ->query_wc() + 5 + random(30));
 return 1; }
 if(tsp < SPCOST) { write("You do not have enough sp.\n"); return 1; }
 tp->add_spell_point(-SPCOST);
 tell_room(etp,
 capitalize(tpn)+" steps out from the shadows and backstabs "+
 targ->query_name()+"!\n");
 if(chance/10 > random(100)) { 
   targ->heal_self(-(targ->query_hp())); 
   tell_room(etp,"Blood gushes out from"+targ->query_name()+
                 "'s mouth.\ntarg->query_name()+" stumbles....\n");
   bsdam = 50; }
   else bsdam = chance;
   targ->hit_player(bsdam);
   if(targ) { targ->attack_object(tp);
              targ->set_wc(targ->query_wc() + 5 + random(20)); }
return 1; }
  