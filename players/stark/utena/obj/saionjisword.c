inherit "obj/weapon.c";
#include "/players/stark/defs.h"
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("katana");
set_alias("sword");
set_short("Katana");
set_long(
"The Katana that used to be the pride and joy of the President of the Kendo \n"+
"Club.  Saionji's Katana is simple and strong, with a fine grip on it.  Great \n"+
"time and care has been put into keeping of this sword.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(18);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);

if(W>11)  {
  say(
" "+this_player()->query_name()+" raises "+attacker->query_possessive()+" Katana high into the air\n"+
"     and "+HIW+"S L A M S"+NORM+" it down into the shoulder of "+attacker->query_name()+"\n");
  write(
" You raise your Katana high into the air\n"+
"     and "+HIW+"S L A M"+NORM+" it down into the shoulder of "+attacker->query_name()+"\n");
  return 3;
   }

if(W==11)  {
  say(
" "+this_player()->query_name()+" lunges forward and stabs "+this_player()->query_possessive()+" blade into "+attacker->query_name()+"\n");
  write(
" You lunge forward and stab your blade into "+attacker->query_name()+"\n");
  return 3;
   }

if(W==10)  {
  say(
" "+this_player()->query_name()+" cackles maniacly and slashes randomly at "+attacker->query_name()+"\n");
  write(
" You cackle maniacly and slash randomly at "+attacker->query_name()+"\n");
  return 2;
   }
return;
}


