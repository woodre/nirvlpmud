
id(str){  return  str == "caller"; }
short() {  return "The Inquisition Caller"; }
long(){
     write("type 'inquire <player>' to call an inquisition.\n");
}

get(){ return 1; }
init(){
     add_action("inquire","inquire");
     add_action("summon","summon");
}

inquire(str){
     object sandman, deathmonger, player;
     object handcuffs, sandcloak, deathcloak;
     string who;
     sandman = find_player("sandman");
     deathmonger = find_player("deathmonger");
     player = find_player(str);
     handcuffs = clone_object("players/deathmonger/MISC/handcuffs");
     sandcloak = clone_object("players/deathmonger/MISC/sand_cloak");
     deathcloak = clone_object("players/deathmonger/MISC/death_cloak");
     tell_object(player, 
     "You have been summoned to the High Court of Inquisitions.\n"+
     "Sandman and Deathmonger preside over the court.\n");
     move_object(sandman, "players/deathmonger/MISC/inq_room");
     move_object(deathmonger, "players/deathmonger/MISC/inq_room");
     move_object(player, "players/deathmonger/MISC/inq_room");
     tell_object(sandman,
     this_player()->query_real_name()+" has called for an inquisition.\n");
     tell_object(deathmonger,
     this_player()->query_real_name()+" has called for an inquisition.\n");
      move_object(handcuffs, player);
      move_object(sandcloak, sandman);
      move_object(deathcloak, deathmonger);
      tell_room("players/deathmonger/MISC/inq_room",
        "The court will now come to order.\n");
}
