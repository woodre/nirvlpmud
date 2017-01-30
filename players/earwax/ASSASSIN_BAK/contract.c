id(str) { return str == "contract"; }
short() {return "Assassin Contract"; }
string as, cont, vict;
object ass;
int level;
long() {
     write("This contract hereby requires "+as+" to assassinate "+vict+"\n");
     write("as specified in this document.\n");
     write("All payments are in advance.\n");
     write("Cost:  "+level*1000+" gold coins.\n");
     write("Type 'sign' to contract, 'drop contract' to nullify.\n");
}
drop(){
     write("You decide to reconsider the contract.\n");
     destruct(this_object());
     return 1;
}

set_victim_level(v) {level = v; }
set_assassin(a) {as = a;}
set_victim(vic) {vict = vic;}
set_contractor(con) { cont = con; }
can_put_and_get(){ return 0; }
init(){
     add_action("sign","sign");
}

sign(){
     int treasury;
     if(this_player()->query_money() < level*1000){
       write("The demon slaps you on the side of the head and says,\n");
       write("'You don't have enough money for this assassination'.  He \n");
       write("tears up the contract and flies away, angrily.\n");
       destruct(this_object());
       return 1;
     }
     this_player()->add_money(-level*1000);
     write("You sign the contract.\n");
     write("The demon flies away, carrying the signed contract and the mo\n");
     write("money the assassination will cost.  You will not be dissatisfi-\n");
     write("fied.  Have a nice day :)\n");
     ass = find_player(lower_case(as));
     tell_object(ass, cont+" has signed the contract.\n");
     tell_object(ass,
       "A demon returns, giving you "+level*1000*7/10+" gold coins,\n"+
       "taking the rest for the guild commission.\n");
     ass->add_money(level*1000*3/10);
     restore_object("players/deathmonger/ASSASSIN/coffer");
     treasury += level *1000/7;
     save_object("players/deathmonger/ASSASSIN/coffer");
      write_file("/players/deathmonger/ASSASSIN/CONTRACTS",
         cont+" contracted "+as+" to assassinate "+vict+"\n");
     destruct(this_object());


     return 1;
}
