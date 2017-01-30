#define CASINO "players/boltar/casino/"

reset(arg) {
  if (arg) return;
  set_light(1);
  move_object(clone_object("players/boltar/casino/floor/roulette_guy"), this_object());
}

init() {
    add_action("east","east");
    add_action("west","west");
}

east() {
  call_other(this_player(),"move_player","east#"+CASINO+"floor/casinofloor2");
  return 1;
}
west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"floor/casinofloor4");
  return 1;
}

short() {
    return "Casa de Nirvana, Roulette";
}

long(str) {
if(str=="table" || str=="roulette table")
   write("A large, well made antique roulette table. You wonder if it is\n"+
         "rigged like the one in 'Casablanca'.\n");

if(str) return 0;
write(
       "The deep red carpet on the floor is illuiminated by the\n"+
        "elaborate chandelier that hangs overhead. The white panels\n"+
        "of the ceiling, each decorated by a raised plaster flower in \n"+
        "various pastel shades in its center with gilding along its edges.\n"+
        "A large ornate roulette table dominates this area. The noise\n"+
        "of the slot machines is heard in the distance in this\n"+
        "compartively quiet area. The sound of the ball can be heard\n"+
        "clearly. Dispite the lack of sights and sounds the urge of \n"+
        "quick money at the roulette table is hard to resist.\n");
}

id(str) {
return
str=="table"|| str=="roulette table";
}

