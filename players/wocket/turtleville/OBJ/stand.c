#include "/players/wocket/closed/ansi.h"

/* Added by Feldegast 5/29/99 */
#define SAVE_FILE "/players/wocket/turtleville/OBJ/stand"

/* Added by Snow 5/99 */
#define MAXONUM 50
#define MAXTNUM 50
#define ROTTENCHANCE 15
#define DELAY 100
int tnum;
int onum;
int tprice;
int price;

short(){ return HIG+"A fruit stand"+NORM; }

id(str){ return str == "stand" || str == "fruit stand" || str == "a fruit stand";}

long(){
  write("A little fruit stand.  Small wooden boards have been nailed\n"+
    "together, slightly crooked to one another.  A large painted sign\n"+
"looms overhead.  A small tin rests on one side while piles\n"+
"of oranges are stacked up on the other.\n");
/* Feldegast 5/29/99 */
    write(BOLD+"There are "+(50-onum)+" oranges remaining.\n"+OFF);
    write(BOLD+"There are "+(50-tnum)+" tomatos remaining.\n"+OFF);
return 1;
}
init(){
  add_action("buy","buy");
   add_action("newlook","look");
  add_action("newlook","l");
  add_action("read","read");
}

int newlook(string str){
if(str == "at sign"){
write("The writing of a three year old decorates this rickety sign.\n"+
  "You might want to 'read' what it says.\n");
return 1;
}
if(str == "at tin"){
write("It is a small coffee tin with a slit cut in the lid.\nSome money is inside.\n");
return 1;
}
if(str == "at oranges"){
write("They are bright orange like oranges should be.  They look\n"+
 "ripe and very nutritious.\n");
return 1;
}
if(str == "at tomatos"){
write("They are bright red like tomatos should be.  They look ripe and\n"+
      "very nutritious.\n");
return 1;
}
if(str == "boards"){
write("They weren't lined up with one another when nailed together giving\n"+
  "the stand a crooked wobble, but enough nails were used to make\n"+
  "it indestructable.\n");
return 1;
}
return 0;
}

int read(string str){
  if(str != "sign"){
  notify_fail("What would you like to read?\n");
  return 0;
}
write("The sign reads:\n"+HIR+"\toRanG3s fOR saL3\n\t     1500 cOiNs/pEr\n"+NORM+
      HIR+"\tTomATos fOR saLE\n\t 1047 cOins/p3r\n"+NORM);
if(onum == MAXONUM){
  write("Another sign reads:\n"+HIR+"\tGon3 tO get moR3 oRanG3s!\n"+OFF);
}
if(tnum == MAXTNUM){
  write("Another sign reads:\n"+HIR+"\tGon3 tO gEt moR3 TomATos!\n"+OFF);
}
return 1;
}

int buy(string str){
int cost;
string file,what;
object orange;
object tomato;
if(!str){
  notify_fail("What would you like to buy?\n");
  return 0;
}
if(str != "orange" && str != "tomato"){
  notify_fail("Only oranges and tomatos are for sale.\n");
  return 0;
}
/* Added by Snow 5/99 */
switch(str){
case "orange":
  if(onum >= MAXONUM){
    notify_fail("There are no oranges left in the stand.\n");
    write_file("/players/wocket/std/standlog",
      ctime(time())+" "+this_player()->query_real_name()+"\n");
    return 0;
  }
  what = "n orange"; cost = 1500; file = "/players/wocket/std/orange.c";
  break;
case "tomato":
  if(tnum >= MAXTNUM){
    notify_fail("There are no tomatos left in the stand.\n");
    write_file("/players/wocket/std/standlog",
      ctime(time())+" "+this_player()->query_real_name()+"\n");
    return 0;
  }
  what = " tomato"; cost = 1047; file = "/players/wocket/std/tomato.c";
  break;
} 
  if(this_player()->query_money() < cost){
  notify_fail("You do not have enough money to buy a"+what+".\n");
  return 0;
}
if(!this_player()->add_weight(1)){
  notify_fail("You can not carry a"+what+".\n");
  return 0;
}
write("You put "+cost+" coins in the tin.\n");
write("You pick up a"+what+".\n");
say(this_player()->query_name()+" drops some money in the tin.\n");
say(this_player()->query_name()+" picks up a"+what+"\n");
orange = clone_object(file);
if(!random(ROTTENCHANCE)){
  orange->set_rotten(1);
  move_object(orange,this_player());
  }
  else
  move_object(orange,this_player());
  this_player()->add_money(-cost);
  if(what == " tomato") tnum++;
  else onum++;
  if(tnum == MAXTNUM)
    call_out("resupply",DELAY,1);
  if(onum == MAXONUM)
    call_out("resupply",DELAY,0);
  return 1;
  }

/* Added by Feldegast 5/29/99 */
reset(arg)
{
  if(arg)
  {
    return;
  }
  if(!restore_object(SAVE_FILE)){
    tnum=0;
    onum=0;
  }
    tnum-=random(30);
   if(tnum < 0) tnum =0;
    onum-=random(30);
   if(onum < 0) onum=0;
}

remove_object(prev)
{
  save_object(SAVE_FILE);
}

resupply(i){
switch(i){
  case 0:
  tell_room(environment(this_object()),"A small boy runs in, dropping off a new shipment of oranges.\n");
    onum-=(10+random(30));
  if(onum<0) onum = 0;
  break;
  case 1:
   tell_room(environment(this_object()),"A small boy runs in, dropping off a new shipment of tomatos.\n");
    tnum-=(10+random(30));
  if(tnum<0) tnum = 0;
  break;
}
}
