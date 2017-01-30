#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()  /* player name  */

id(str) { if(str == "orb" || str == "burnished orb") return 1; }
get() { return 1; }
short() { return "A burnished Orb"; }
query_value() { return 1000; }
query_save_flag() { return 1; }
long() { write(
	"This beautiful burnished Orb dances with the life of the fire\n"+
	"inside just waiting to be released.  All one must do is offer\n"+
	"it as a sacrifice to reap the rewards of their efforts..\n");
	}

reset(arg) {
  if(arg) return;
}

init() {
  add_action("Offer","offer"); }

Offer(str) {
object ob,pet_in_game;
if(present("shaman",environment(environment(this_object())))) {
  write("The Orb hums, 'The Shamans magic is too powerful to overcome!\n");
  return 1; }
if(!str) { write("The fire whispers: What do you offer, mortal?\n");
	return 1; }

if(!present("riverfire",environment(environment(this_object())))) {
  write("The God of Fire is not present.....\n"); return 1;}
else {
if(str == "orb" || str == "burnished orb") {
  pet_in_game = find_living("demon_pet");
if(pet_in_game) {
    write("The God of Fire whispers, 'There is already one such pet\n"+
	"in the game, you'll have to try again later or eliminate\n"+
	"the current demon.....'\n");
    return 1; }

  ob = clone_object("players/eurale/Keep/NPC/demon_pet.c");
  move_object(ob,environment(this_player()));
  ob->set_oowner(this_player());
  write("The flames of the river begin to grow and take on the shape\n"+
	"of the Devil's face.....  The flames whisper to you...\n\n"+
	"To attest to your skill and bravery, I am sending one of my\n"+
	"own to assist you in your hunt.  You and only you will it\n"+
	"obey.... Now go before I change my mind.....\n\n");
  say("The flames flare up....\n");
  destruct(this_object());
  return 1; }
return 1; }
}
