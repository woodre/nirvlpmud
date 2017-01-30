#include "/players/boltar/things/esc.h"
 
id(str) { return str == "sphere"; }
short() { return "Sphere of Mass Destruction [$"+(this_player()->query_hp())+".1K] "+
	esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m[New & Improved!]"+esc+"[0m"+
	" [Release Six]";
	}
get() { return 1; }
query_value() { return 100000; }
long() { write("This is a "+esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mglowing"+esc+"[0m"+
	"object of great power.\n");
	write("It is used to 'disc' players, or even 'execute' them.\n");
	write("You can also go 'nuclear' with the sphere, and hit everything in the room.\n");
	write("On the other hand, 'Nuclear' kills anything in the room, player regardless.\n");
	write("'Disc'onnecting players dests them, executing them kills them by\n"+
	"dropping a nasty litte thermonuclear device in their inventory.\n"+
	"Bagging them imprisons them in a convienent portable prison,\n"+
	"and separates them from their worldly belongings.\n");
	}
init() {
	if(this_player()->query_level() < 39) {
	  destruct(this_object());
	  return 1;
	  }
	add_action("snuff","disc");
	add_action("execute","execute");
	add_action("nuclear","nuclear");
	add_action("total_death","Nuclear");
	add_action("bag","bag");
	}
snuff(arg) {
	object ob;
	ob=find_player(arg);
	if(!ob) {
	  write("The sphere cries: That player is not logged in.\n");
	  return 1;
	  }
	write("The sphere says: Summoning Martian...\n");
	tell_object(ob, "You see a small, saucer-shaped ship drop from the sky.\n");
	tell_object(ob, "A small green creature deboards the ship and points a tiny\n"+
	  "little ray gun at you.\n");
	tell_object(ob, "He smiles, and says: "+esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mFuck you."+esc+"[0m");
	tell_object(ob, "He then proceeds to shoot you with the ray gun.\n");
	destruct(find_living(ob));
	write("The sphere fizzles joyously and says: Done, master.\n");
	return 1;
	}
execute(arg) {
	object ob;
	ob=find_living(arg);
	if(!ob) {
	  write("The sphere sighs and says: That creature is not logged in.\n");
	  return 1;
	  }
	tell_object(ob, "A small nuclear device suddenly shows up in your inventory.\n");
	tell_object(ob, "Suddenly, it detonates.\n\n");
	tell_object(ob, esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mBOOM!"+esc+"[0m");
	call_other(ob, "hit_player", 99999);
	tell_object((environment(ob)), "You see "+(ob->query_name())+" vanish in a small mushroom cloud.\n");
	write("The sphere woggles happily and says: Done, master.\n");
	return 1;
	}
bag(arg) {
	object ob,bag,bag2,coins;
	int cash;
	ob=find_living(arg);
	if(!ob) {
	  write("The sphere frowns and says: That player is not logged in.\n");
	  return 1;
	  }
	write("The sphere says: Bagging player...\n");
	tell_object(ob, "A large, smelly ogre arrives and clubs you on the head.\n");
	tell_object(ob, "You awaken in a different place. You have a headache.\n");
	bag2=clone_object("players/mizan/closed/package.c");
	move_object(bag2, this_player());
	cash=ob->query_money();
	ob->set_pretitle("'NEVER PISS OFF A WIZARD!' shouts");
	ob->set_title("who's head is bleeding profusely (idiot)");
	ob->set_description("got bonked on the head by a huge, smelly ogre");
	coins=clone_object("obj/money");
	coins->set_money(cash);
	move_object(coins, bag2);
	ob->add_money(-cash);
	ob->transfer_all_to(bag2);
	write("The sphere says: Transferring player items...\n");
	bag2->set_short("A UPS package containing all of "+(ob->query_name())+"'s things");
	bag=clone_object("players/mizan/closed/prisonbag.c");
	bag->set_short("A body bag containing the body of "+(ob->query_name())+" (squirming)");
	move_object(bag, this_player());
	move_object(ob, bag);
	write("The sphere flickers happily and says: Done, master.\n");
	say((this_player()->query_name())+" opens a portal and gets a squirming bag from it.\n");
	say("The portal then suddenly disappears.\n");
	say("A UPS man arrives and hands "+(this_player()->query_name())+" a packege.\n");
	return 1;
	}
nuclear() {
object room,ob2,oc2;
object ob,TP;
TP=this_player();
room=environment(TP);
ob=first_inventory(room);
 
write("The sphere does your bidding. It detonates.\n");
say((TP->query_name())+" detonates a small nuclear device!\n");
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
  if(living(oc)) {
    if(oc->query_npc() !=1) {
      say((oc->query_name())+" hits the dirt and escapes harm!\n");
      write("The explosion just misses "+(oc->query_name())+".\n");
        }
    if(oc->query_npc() == 1) {
      write("You watch as "+(oc->query_name())+" was caught standing in ground zero.\n");
      say((oc->query_name())+" gets toasted by the blast and turns into a heap of carbon deposits!\n");
      call_other(oc, "hit_player", 999999);
      TP->heal_self(1000);
      write("The sphere reforms, and cheerfully says: Done, master.\n");
        if(oc && !oc->query_attack()) {
          oc->attack_object(TP); }
        }
   }
}
return 1;
}
total_death() {
object room,ob2,oc2;
object ob,TP;
TP=this_player();
room=environment(TP);
ob=first_inventory(room);
 
write("The sphere cackles gleefully and detonates.\n");
say((TP->query_name())+" detonates a BIG nuclear device!\n");
while(ob) {
        object oc;
        oc=ob;
        ob=next_inventory(ob);
if(living(oc)) {
  write("You watch as "+(oc->query_name())+" gets totally obliterated.\n");
   say((oc->query_name())+" gets fucked up big time!\n");
  call_other(oc, "hit_player", 9999999);
  TP->heal_self(1000);
  write("The sphere reforms, and most exitedly exclaims: Done, master!\n");
    if(oc && !oc->query_attack()) {
      oc->attack_object(TP); }
        }
   }
 
return 1;
}
