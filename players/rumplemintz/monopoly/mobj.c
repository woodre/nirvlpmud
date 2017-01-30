/* mobj.c
 * Monopoly player object..  if you update this while playing, it will remove
 * you from the game.  (because of destructor) 
 * Make sure that destructor works with your mud lib.  Also, you might want
 * to look at how it handles netdeads, because sometimes the add_actions
 * of objects given to netdeads are in the wrong order, and you can't
 * re-enter the game.  (big pain)
 */
#include "path.h"

object binob;

object player;
string name;   /* player name for netdead */
string gamename;
int cash;
string square;
int *houses;  /* houses for each board space (see #defines in path.h) */
int turn;     /* turn that we are we on */
int doubles;  /* number of doubles */
int in_jail;
int out_of_jail;  /* number of get out of jail free cards */
int lock;     /* keep us from going (while waiting for card) */

init() {
  if(environment(this_object())!=TP) return;
  if(!gamename) return;
  if(player && TP==player) return;
  if(TP->query_real_name()!=name) return;  /* not them */
  write("You're back!  You re-enter the game of Monopoly\n");
  SHOUT(NAME+" re-enters the game\n");
  add_bin();
  player=TP;
}

add_bin() { add_action("chk_bin","",1); }


start_game(gname,who) {
  int i;

  gamename=gname;
  player=who;
  name=player->query_real_name();
  cash=START_CASH;
  houses=allocate(SQSZ);
  for(i=0;i<SQSZ;i++) houses[i]=UNOWNED;
  add_action("chk_bin","",1);
  say(query_cname()+" enters a game of monopoly.\n");
  move_object(TP,PATH+"_go");
  say(query_cname()+" shows up for a game of monopoly.\n");
  square=file_name(environment(TP));
}

#define BANKRUPTMESS "You are bankrupt!\n" \
 +"You must either exit the game or make some money (mortgage, sell, etc..)\n"
/* querys and sets */
query_player() { return player; }
query_cname() {  /* doesn't use name because it might not be set */
    if(in_jail) return capitalize(player->query_real_name())+" (jail)";
    return capitalize(player->query_real_name());
}
query_cash() { return cash; }
set_cash(to) { cash=to; }
add_cash(i) {
  cash+=i;
  if(cash<0) {
    if(i<0) {
      tell_object(player,BANKRUPTMESS);
      SHOUT(query_cname()+" goes bankrupt!\n");
    } else {
      tell_object(player,"You are still bankrupt!\n");
      SHOUT(query_cname()+" is still bankrupt!\n");
    }
  }
}
query_house(i) { return houses[i]; }
set_house(i,j) { houses[i]=j; }
query_square() { return square; }
set_square(loc) { square=loc; }
query_gamename() { return gamename; }
query_turn() { return turn; }
incturn() {
  object *pl;
  int i;

  turn++;
  pl=MAIN->query_players(gamename);
  if(sizeof(pl)<2) return;
  for(i=0;i<sizeof(pl);i++) if(pl[i]->query_turn()!=turn) return 1;
  write("++You can take your next turn after this one.\n");
  SHOUT("++You can take your next turn.\n");
}
query_doubles() { return doubles; }
clear_doubles() { doubles=0; }
incdoubles() { return ++doubles; }
set_lock() { lock=1; }
clear_lock() { lock=0; }
query_in_jail() { return in_jail; }
set_in_jail(to) { in_jail=to; }
query_out_of_jail() { return out_of_jail; }
add_out_of_jail(x) { out_of_jail+=x; }
query_worth() {
  int tot,i,tmp;
  
  tot=0;
  for(i=0;i<SQSZ;i++)
    if(houses[i]>=MORTGAGED) {
      if(houses[i]==MORTGAGED) tot+=MAIN->square_file(i)->query_price()/2;
      else {
        tot+=MAIN->square_file(i)->query_price();
        if(houses[i]>OWNED && houses[i]<=5)
          tot+=houses[i]*MAIN->square_file(i)->query_housecost();
      }

    }
  return tot+cash;
}


#define BANKRUPT ({"roll","use"})
/* bin */
chk_bin(arg) {
  string func;

  if(lock) WRITE("You have to wait until you pick up the card.\n");
  binob=MBIN->ping();  /* load main so we can do function_exists */

  func="m_"+query_verb();
  if(function_exists(func,binob))
    if(cash>=0 || member_array(query_verb(),BANKRUPT)==-1)
      return call_other(binob,func,arg);
    else
      WRITE(BANKRUPTMESS);
  return 0;
}

/* object stuff */
short(){
  if(TP==player && query_verb()=="i") add_bin();  /* we lost bin (netdead?) */
  return "Monopoly Object.  $"+cash;
}
extra_look() {
return "\n.-------------------------------------.\n"
        +".--** Currently Playing Monopoly! **--.\n"
        +".-------------------------------------";
}
long(){
  write(short()+"\n");
  write("Type 'help monopoly' or 'help topics' for help\n");
  return 1;
}
id(str) {
  return str=="mobj" || str=="__mobj" || str=="__mobj"+gamename
      || str=="monopoly";
}
get() { return 0; }
drop() { return 1; }
destructor() {
  catch(mydestructor());
}
mydestructor() {
  if(!find_object(MAIN)) WRITE("Cannot find: "+MAIN+"\n");
  if(MAIN->remove_player(TP))
    write("You leave the game of monopoly.\n");
  return 1;
}


