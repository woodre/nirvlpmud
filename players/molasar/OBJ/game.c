

int item0,item1,item2,item3,item4,item5,item6,item7,item8,item9;
int item10,item11,item12,item13,item14,item15,item16,item17,item18,item19;
int item20,item21,item22,item23,item24,item25,item26,item27,item28,item29;
int play, playa, playb, playc;
string me;

id(str) { return str == "machine"; }

short() { return "A gambling machine"; }

long() { 
   write("A grambling machine where you can win (or lose) hard-earned money.\n");
   write("Type play to begin.\n");
   write("Note:  A small fee of 10 gp is required.\n");
}

init() {
   add_action("play","play");
}

play() {
   me = this_player()->query_name();
   if(this_player()->query_money() < 10) {
     write("You do not have enough money to play!\n");
     return 1;
   }
   this_player()->add_money(-10);
   play = random(10);
   playa = random(11);
   playb = random(11);
   playc = random(11);
   if(play < 3 && playa == playb && playa == playc) {
     write("You just won 500 gold coins!\n");
     say(capitalize(me)+" just won 500 gold coins.\n");
     this_player()->add_money(500);
     return 1;
   }
   if(play < 3 && playa == playb) {
     write("You just won 200 gold coins!\n");
     say(capitalize(me)+" just won 200 gold coins.\n");
     this_player()->add_money(200);
     return 1;
   }
   if(play < 3 && playb == playc) {
     write("You just won 100 gold coins!\n");
     say(capitalize(me)+" just won 100 gold coins.\n");
     this_player()->add_money(100);
     return 1;
   }
   if(play < 3 && playa == playc) {
     write("You just won 200 gold coins!\n");
     say(capitalize(me)+" just won 200 gold coins!\n");
     this_player()->add_money(200);
     return 1;
   }
   write("Too bad....you lost....try again later.\n");
   say(capitalize(me)+" lost 10 gold coins.\n");
   return 1;
}

