inherit "obj/monster";
#define CHIPS present("casino chips",this_player())

string *bets;
int game_on;

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("guy");
   set_alias("roulette");
   set_level(15);
   set_wc(15);
   set_ac(30);
   set_al(350);
   set_short("The Roulette Guy");
   set_long(
      "This here is the Roulette Guy.\n"+
      "Read 'rhelp' for help!\n");
   set_dead_ob(this_object());
}

init() {
   add_action("rhelp","rhelp");
   add_action("bet","bet");
}

rhelp() {
   write("Roulette Help\n\n"+
      "You may place a bet by typing 'bet [amount] [type]'.\n"+
      "Amount must be at least 100 chips, and type may\n"+
      "be either a color (red or black) or a number (1 - 36).\n\n"+
      "Examples: To bet 2000 chips on the color red, you would\n"+
      "          type: bet 2000 red\n"+
      "          To bet 500 chips on the number 24, you would\n"+
      "          type: bet 500 24.\n");
   return 1; }

query_bet(string who) {
   int x, bet;
   string name, type;
   
   for(x = 0; x < sizeof(bets); x++) {
      if(sscanf(bets[x],"%s_%d_%s",name,bet,type));
      if(name == who) return bet; }
   return 0; }

monster_died() {
   int bet, x;
   string who, tmp;
   object person;
   
   for(x = 0; x < sizeof(bets); x++) {
      if(sscanf(bets[x],"%s_%s",who,tmp));
      bet = query_bet(who);
      person = find_player(who);
      if(person) {
         if(present("casino chips",person)) {
            tell_object(person,"The roulette guy hands you your chips back as he dies.\n");
            present("casino chips",person)->add_chip_value(bet); } } }
   remove_call_out("finish_game");
   return 1; }

bet(arg) {
   int amt, num;
   string who;
   
   if(!CHIPS) {
      write("The roulette guy tells you: You must purchase some chips to play.\n");
      return 1; }
   
   if(!arg || sscanf(arg,"%d %s",amt,arg) != 2) {
      write("The roulette guy tells you: Please read 'rhelp' for help!\n");
      return 1; }
   
   if(sscanf(arg,"%d",num));
   if(arg != "red" && arg != "black" && (num < 1 || num > 36)) {
      write("The roulette guy tells you: Please read 'rhelp' for help!\n");
      return 1; }
   
   if(amt < 100) {
      write("Minimum bet is 100 chips.\n");
      return 1; }
   
   if(amt > CHIPS->query_chip_value()) {
      write("You are too poor you cheap bum!\n");
      return 1; }
   
   who = this_player()->query_name();
   who = lower_case(who);
   if(query_bet(who)) {
      write("You already have a bet riding on this!\n");
      return 1; }
   
   write("You place a bet of "+amt+" chips.\n");
   
   if(!game_on) {
      say("The roulette guy says: Place your bets!\n");
      bets = ({ });
      game_on = 1; 
      call_out("finish_game",10); }
   
   CHIPS->add_chip_value(-amt);
   bets += ({ lower_case(this_player()->query_name())+"_"+amt+"_"+arg });
   
   return 1; }

finish_game() {
   int x, land, bet, tmp;
   string color, who, type;
   object them;
   
   land = random(36)+1;
   color = "black";
   if(land%2) color = "red";
   tell_room(environment(this_object()),"The roulette guy spins the wheel.\n"+
      "The ball spins around and around and lands on "+land+" "+color+".\n");
   for(x = 0; x < sizeof(bets); x++) {
      if(sscanf(bets[x],"%s_%d_%s",who,bet,type));
      them = find_player(who);
      if(them) {
         if(sscanf(type,"%d",tmp));
         if(type == color || tmp == land) {
            tell_object(them,"The roulette guy tells you: You won!\n");
            if(tmp == land) bet *= 36;
            if(type == color) bet *= 2;
            if(!present("casino chips",them))
               tell_object(them,"The roulette guy tells you: You no longer have your chip tray with you.\n"+
               "No sale!\n");
            if(present("casino chips",them)) {
               tell_object(them,"The roulette guy hands you your winnings.\n");
               present("casino chips",them)->add_chip_value(bet);
            } }
         if(bet == query_bet(who))
            tell_object(them,"The roulette guy tells you: You lost!\n"); } }
   
   game_on = 0;
   bets = ({ });
   return 1; }
