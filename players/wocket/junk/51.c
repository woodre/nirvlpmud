#include "/players/wocket/closed/ansi.h"
#define DECK1 ({ "a-s","a-c","a-h","a-d","k-s","k-c","k-h","k-d",})
#define DECK2 ({ "q-s","q-c","q-h","q-d","j-s","j-c","j-h","j-d",})
#define DECK3 ({ "10-s","10-c","10-h","10-d","9-s","9-c","9-h","9-d",})
#define DECK4 ({ "8-s","8-c","8-h","8-d","7-s","7-c","7-h","7-d",})
#define DECK5 ({ "6-s","6-c","6-h","6-d","5-s","5-c","5-h","5-d",})
string *DECK;
string *SHUFFLEDDECK;
string *players;
string p1cards,p2cards,p3cards,p4cards;
int turn;
int is_playing;
int score; 
id(str){ return (str == "table" || str == "51" || str == "51 table"); }

short(){
int i,a;
string msg;
  msg = "A 51 table";
  if(players[0] != "empty"){ 
    msg += " with ";
    switch(sizeof(players)){
      case 4: msg += capitalize(players[0])+", "+capitalize(players[1])+", "+
                       capitalize(players[2])+" and "+capitalize(players[3]);
        break;
      case 3: msg += capitalize(players[0])+", "+capitalize(players[1])+" and "+
                       capitalize(players[2]);     
        break; 
      case 2: msg += capitalize(players[0])+" and "+capitalize(players[1]);          
        break;
      case 1: msg += capitalize(players[0]);
        break;
    }
    msg += " sitting around it";
  }
  return msg;
}


long(){ write("table blah blah 51 blah blah\n");
        if(is_playing){
         write("Current Score: "+score+"\n"+
              "Current Turn: "+capitalize(players[turn])+"\n");
        }
}

reset(){
  DECK = DECK1+DECK2+DECK3+DECK4+DECK5;
  turn = 0;
  is_playing = 0;
  p1cards = p2cards = p3cards = p4cards = players = ({});
  players = allocate(4);
  players[0] = "empty";
}

init(){
  add_action("show_deck","show_deck");
/*add_action("shuffle_deck","shuffle");*/
  add_action("deal_cards","deal");
  add_action("show_hand","show");
  add_action("play_card","play"); 
  add_action("put","put");
  add_action("kick_table","kick");
}

exit(){
  tell_object(find_player("wocket"),"Exit called\n");
}

kick_table(str){
  if(!str || str != "table"){ 
    notify_fail("What would you like to kick?\n");
    return 0;
  }
  write("You kick the table, scattering all the cards, and ruining the game for everyone.\n");
  say(this_player()->query_name()+" kicks the table, scattering all the cards, and ruins the game for everyone.\n");
  reset();
  return 1;
}

put(str){
int one,two;
 if(!str){
   notify_fail("What would you like to put?\n");
   return 0;
 }
 if(sscanf(str,"%s %s",one,two)==2){
   if(one == "card"){
     command("play "+two,this_player());
     return 0;
   }
 }
 notify_fail("What would you like to put?\n");
 return 0;
}

show_deck(){
int i;
int a;
  for(i=0,a=sizeof(DECK);i<a;i++){
    write(get_card_long(SHUFFLEDDECK[i])+"\n"); 
  }
  return 1;
}

shuffle_deck(){
int i;
string *old_deck,*new_deck;
  old_deck = DECK;
  new_deck = ({});
  while(sizeof(old_deck)){
    i = random(sizeof(old_deck));
    new_deck += old_deck[i];
    old_deck -= old_deck[i];
  }
  SHUFFLEDDECK = new_deck;
return 1;
}

get_card_long(card){
string value,suit;
string longvalue,longsuit;
sscanf(card,"%s-%s",value,suit);
switch(value){
  case "a": longvalue = "Ace"; break;
  case "k": longvalue = "King"; break;
  case "q": longvalue = "Queen"; break;
  case "j": longvalue = "Jack"; break;
  case "10": longvalue = "10"; break;
  case "9":  longvalue = "9"; break;
  case "8":  longvalue = "8"; break;
  case "7":  longvalue = "7"; break;
  case "6":  longvalue = "6"; break;
  case "5":  longvalue = "5"; break;
}
switch(suit){
  case "s": longsuit = BOLD+BLK+"Spades"+OFF; break;
  case "c": longsuit = BOLD+BLK+"Clubs"+OFF; break;
  case "h": longsuit = HIR+"Hearts"+OFF; break;
  case "d": longsuit = HIR+"Diamonds"+OFF; break;
}
  card = "the "+longvalue+" of "+longsuit;
  return card;
}

deal_cards(str){
int i,b,a;
string p1,p2,p3,p4;
string overkill; 
string *testplayers; 
  if(!str){
    notify_fail("Who would you like to deal the cards to?\n");
    return 0;
  }
  if(is_playing){
    notify_fail("A game is already in progress.\n");
    return 0;
  }
  str = str+" blah";
  players[0] = this_player()->query_real_name();
  sscanf(str,"%s %s %s %s",players[1],players[2],players[3],overkill);
  i = 3;
  while(!players[i]){
     players -= players[i];
     i--;
  }
  for(b=0,a=sizeof(players);b<a;b++){
    testplayers = players;
    testplayers -= players[b];
    if(member_array(players[b],testplayers) != -1){
      write("You can not deal to the same person twice.\n");
      reset();
      return 1;
    }
    if(!find_player(players[b])){
      write(capitalize(players[b])+" is not a player.\n");
      reset();
      return 1;
    }
    if(environment(find_player(players[b])) != environment()){
      write(capitalize(players[b])+" is not here to deal to.\n");
      reset();
      return 1; 
    }
  }
  write("You deal the cards.\n");
  say(this_player()->query_name()+" deals out the cards.\n");
  shuffle_deck();
  if(sizeof(players) > 3){
    p4cards = SHUFFLEDDECK[0..4];
    SHUFFLEDDECK -= SHUFFLEDDECK[0..4];
  }
  if(sizeof(players) > 2){
    p3cards = SHUFFLEDDECK[0..4];
    SHUFFLEDDECK -= SHUFFLEDDECK[0..4];
  }
  if(sizeof(players) > 1){
    p2cards = SHUFFLEDDECK[0..4];
    SHUFFLEDDECK -= SHUFFLEDDECK[0..4];
  }
  p1cards = SHUFFLEDDECK[0..4];
  SHUFFLEDDECK -= SHUFFLEDDECK[0..4];
  is_playing = 1;
  return 1;
}

show_hand(){
int i,a;
string *cards;
  i = member_array(this_player()->query_real_name(),players);
  if(i == -1){
    notify_fail("You have no cards to look at.\n");
    return 0;
  }
  cards = whos_cards(i);
  for(i=0,a=sizeof(cards);i<a;i++){
    write("["+(i+1)+"]  "+get_card_long(cards[i])+"\n");
  }
return 1;
}

play_card(selection){
int card_number;
string value,suit;
int v;
string *cards;
  if(this_player()->query_real_name() != players[turn]){
    notify_fail("It is not your turn.\n");
    return 0;
  } 
  cards = whos_cards(turn);  
  sscanf(selection,"%d",card_number);
  if(!card_number){
    notify_fail("You must play one of the cards in your hand.\n");
    return 0;
  }
  if(card_number < 1 || card_number > sizeof(cards)){
    notify_fail("You must play one of the cards in your hand.\n");
    return 0;
  }
  card_number--;
  sscanf(cards[card_number],"%s-%s",value,suit);
  switch(value){
    case "k": v = 3; break;
    case "q": v = 2; break;
    case "j": v = 1; break;
    case "9": v = 0; break;
    case "8": v = 8; break;
    case "7": v = 7; break;
    case "6": v = 6; break;
    case "a": if(score > 40) 
              v = 1;
            else
              v = 11; break;  
    case "5":  if(score > 46)
               v = -5;
             else
               v = 5; break;
    case "10": if(score > 41)
               v = -10;
             else
               v = 10; break;
    default: value = value;
  }
  write("You play "+get_card_long(cards[card_number])+".\n");
  say(this_player()->query_name()+" plays "+get_card_long(cards[card_number])+".\n");
  score = score + v;
  tell_room(environment(),"The score is now: "+score+"\n");
  if(score > 51){
    write("YOU LOSE!!\n");
    say(this_player()->query_name()+" LOSES!!\n");
    reset();
    return; 
  }
  cards -= cards[card_number];
  if(sizeof(SHUFFLEDDECK) != 0){
    cards += SHUFFLEDDECK[0];
    write("You draw "+get_card_long(SHUFFLEDDECK[0])+".\n");
    SHUFFLEDDECK -= SHUFFLEDDECK[0];
  }
  set_cards(turn,cards);
  turn++;
  if(turn == sizeof(players)){
    turn = 0;
  }
  say("It is now "+capitalize(players[turn])+"'s turn.\n");
  write("It is now "+capitalize(players[turn])+"'s turn.\n");
  return 1;
}

whos_cards(i){
  switch(i){
    case 0: return p1cards; break;
    case 1: return p2cards; break;
    case 2: return p3cards; break;
    case 3: return p4cards; break;
  }
}

set_cards(i,*cards){
  switch(i){
    case 0: p1cards = cards; break;
    case 1: p2cards = cards; break;
    case 2: p3cards = cards; break;
    case 4: p4cards = cards; break;
  }
  return 1;
}