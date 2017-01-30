pick(string str,int chance) {
object targ,bag;
int gotten;
 if(!str) { write("pick <name>\n"); return 1; }
 targ = present(str,etp);
 if(!targ) { write("That is not here to pick pocket.\n"); return 1; }
 if(!living(targ)) { write("That is not a living thing.\n"); return 1; }
 if(find_player(str) == targ) {
    write("Can not be used on a player.\n"); return 1; }
 if(chance < random(100)) {
    write("You are discovered in your attempt to pick pocket!\n");
    say(capitalize(tpn)+" trips and falls flat on "+tp->query_possessive()+
    " face.\n");
    targ->attack_object(tp);
    targ->set_wc(targ->query_wc() + 1 + random(10));
 return 1; }
 if(!targ->query_money()) {
    write("You discover to your disappointment that the mark has no money.\n");
 return 1; }
 if(bag = present("money_bag",tp)) {}
 else bag = clone_object("/players/mythos/myth/thief/spells/money_bag.c");
 gotten = 1+random(targ->query_money());
 bag->add_coin(gotten);
 move_object(bag,tp);
 write("You pick "+gotten+" coins off "+capitalize(str)+
       " and put it in your money bag\n"+
       "Money bag contains: "+bag->query_coin()+" coins\n"+
       "You have :"+tp->query_money()+" coins.\n");
return 1; }
  