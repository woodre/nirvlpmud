#define CASINO "players/boltar/casino/"

reset(arg) {
   if(arg) return;
   set_light(1);
   move_object(clone_object("players/boltar/casino/floor/bj_dealer"), this_object());
}

init() {
    add_action("east","east");
}

east() {
  call_other(this_player(),"move_player","east#"+CASINO+"floor/casinofloor3");
  return 1;
}
west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"floor/casinofloor4");
  return 1;
}

short() {
    return "Casa de Nirvana, Blackjack";
}

long(str) {
if(str=="table" || str=="roulette table")
   write("A large, well made antique blackjack table. The green top has\n"+
         "beautiful 19th centrury style graphics\n");

if(str) return 0;
write(
       "The deep red carpet on the floor is illuiminated by the\n"+
        "elaborate chandelier that hangs overhead. The white panels\n"+
        "of the ceiling, each decorated by a raised plaster flower in \n"+
        "various pastel shades in its center with gilding along its edges.\n"+
        "A large ornate blackjack table dominates this area.\n"+
        "This is a quiet area, where people concentrate on their cards.\n"+ 
        "The quiet concentration of blackjack playing attracts the \n"+
        "smart better who knows that blackjack has the best odds of \n"+
        "any game in the house.\n"); 
}

id(str) {
return
str=="table"|| str=="blackjack table";
}

