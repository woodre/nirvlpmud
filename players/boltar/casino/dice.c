#include "std.h"
int die1, die2, my_bet;
int passed, tot, point;
int winner;

reset(arg) {
  if(arg)
    return;
}

id(str) {
  return  str == "dice";
}

short() {
  return "a pair of dice";
}
long() {
  write("This is a pair of standard-issue casino dice.\n");
  if(die1 == 0 || die2 == 0) {
    write("You haven't rolled them yet.\n");
    return;
  }
  write("They show " + die1 + " and " + die2 +" on their faces.\n");
  return;
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("bet"); add_verb("bet");
  add_action("roll"); add_verb("roll");
  add_action("roll"); add_verb("throw");
  add_action("pass"); add_verb("pass");
#else
  add_action("bet", "bet");
  add_action("roll", "roll");
  add_action("roll", "throw");
  add_action("pass", "pass");
#endif
}


get() {
  my_bet = 0;
  passed = 0;
  die1 = 0;

  winner = 0;
  point = 0;
  return 1;
}

drop() {
  my_bet = 0;
  passed = 0;
  die1 = 0;
  die2 = 0;
  tot = 0;
  winner = 0;
  point = 0;
  return 0;
}

check_bet() {
  call_other(this_player(),"add_money", -my_bet);
  if(call_other(this_player(),"query_money",0) < 0) {
    call_other(this_player(),"add_money",my_bet);
    return 0;
   }
  return 1;
}

bet(arg)
{
  if (!my_bet) {
    if(!arg) {
      write("You need to bet some amount!\n");
      return 1;
    }
    if(sscanf(arg,"%d",my_bet) < 1) {
      write("How much do you want to bet?\n");
      return 1;
    }
    if(my_bet < 0) {
      write("Arizona says:Guy, you try that again, I breaka you face!\n");
 say(call_other(this_player(),"query_name",0) + " looks like he's about to have problems with the bouncer!\n");
      my_bet = 0;
      return 1;
    }
    if(!check_bet()) {

      write("Hey Bozo , broke people don't belong here !\n");
      my_bet = 0;
      return 1;
    }
    write("The croupier takes your money. \nYou have bet "+arg+ " coins.\n");
 say(call_other(this_player(),"query_name",0) + " bet " + arg + " coins.\n");
    die1 = 0;
    die2 = 0;
    passed = 0;
    winner = 0;
    tot = 0;
    point = 0;
    return 1;
  }
  write("You cannot change your bet in the middle of a roll!\n");
  return 1;
}

a_lose() {
my_bet = 0;
  point = 0;
  winner = 0;
  die1 = 0;
  die2 = 0;
  tot = 0;
  passed = 0;
}

a_win() {
  my_bet = (my_bet * winner)/10;
  write("You win "+ my_bet +" coins.\n");
  call_other(this_player(),"add_money",my_bet);
say(call_other(this_player(), "query_name",0) + " won " + my_bet + " coins.\n");
  a_lose();
}

roll(str){
  if(!id(str))
    return 0;
  if(environment() != this_player()) {
    write("You need to get the dice first!\n");
    return 1;
  }
  if(passed) {
    write("You have already passed the dice!\n");
    return 1;

  }
  if(my_bet == 0){
    write("You haven't placed any bet!\n");
    return 1;
  }
  die1 = random(6) +1;
  die2 = random(6) +1;
  tot = die1 + die2;
  if((tot == 2 || tot ==12 || tot == 3) && !point) {
    write("You shot the limit and rolled a "+tot+". You LOSE!\n");
    say(call_other(this_player(),"query_name") +" lost the wad!\n");
    a_lose();
return 1;
  }
  if ((tot == 7 || tot == 11) && !point) {
    winner = 20;
    write("Craps! you rolled a " + tot +". You WIN!\n");
    say(call_other(this_player(), "query_name",0) + " shot craps.\n");
    write("The croupier will give you your winnings in a moment.\n");
 a_win();
    return 1;
  }
  if(tot == 7 || tot == 11) {
    write("You crapped out! You rolled a "+tot+".\n");
    say(call_other(this_player(), "query_name",0) + " crapped out.\n");
    a_lose();
    return 1;
  }
if(tot == point && tot) {
    winner = 15;
    write("You matched your point with a " +tot +". You WIN!\n");
    say(call_other(this_player(),"query_name",0) + " made his point.\n");
    write("The croupier will give you your winnings in a moment.\n");
    a_win();
    return 1;
  }
  if(!point) {
    point = tot;
  }
  write("You rolled a "+tot+".\n");
  write("Your point is "+point+".\n");
  return 1;
}

pass(str) {
  if(!id(str))
    return 0;
  if(environment() != this_player()) {
    write("You need to get the dice first!\n");
    return 1;
  }
  if(passed) {
    write("You have already passed the dice!\n");
    return 1;
  }
  if(my_bet ==0){
    write("You haven't placed any bet!\n");
    return 1;
  }
  passed = 1;
  write("You pass the dice.\n");
  write("The croupier will roll momentarily.\n");
  say(call_other(this_player(), "query_name",0) + " passed the dice.\n");
  write("The house rolls the dice.\n");
  die1 = random(6) +1;
  die2 = random(6) +1;
  write("They come up: " + die1 +" and "+die2+".\n");
  if((die1+die2 == 7) || (die1+die2 == 11)) {
    write("The house crapped out! You WIN!\n");
    say(call_other(this_player(), "query_name",0) + " won by house craps.\n");
    winner = 15;
    a_win();
    return 1;
  }
  write("You lost. The house passed the point.\n");
  write("You get the distinct impression that the croupier is smirking at you.\n");
  say(call_other(this_player(), "query_name",0) + " lost by pass.\n");
  a_lose();
  return 1;
}
query_weight() { return 1; }
