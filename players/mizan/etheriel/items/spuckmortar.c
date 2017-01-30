#include "std.h"
int drinks, price;
id(str) { return str == "detonator"; }
reset(arg) {
        if (!arg) drinks = 3;
        price = drinks * 1500; }
long() {
        write("This is a strange looking device that looks something like\n"+
	"a piledriver, made of the same flexible and squishy material that\n"+
	"other Spuck weapons are made of. You have seen the destructive force\n"+
	"of a spuckball exploding in the face of the enemy, and wonder\n"+
	"'That's only a little spuckball. The ones in these thing are BIG'.\n"+
	"The detonator works with the command 'detonate spuckball' and seems\n"+
	"to be reloadable like the other Spuck weapons.\n"+
	"There are ["+drinks+"] big spuckballs left.\n"); }
short() { return "A Spuckball detonator ["+drinks+"]"; }
query_save_flag() { return 1; }
query_value() { return price; }
init() {
	add_action("use","detonate");
	add_action("load","load");
	}

load(str) {
   object ammo;
	if(!str) return 0;
   if(str == "detonator"){
        ammo=present("spuckballs",this_player());
        if(!ammo) {
         write("You don't have any spuckball tubes.\n");
         return 1;
         } 
         destruct(ammo); 
	 this_player()->add_weight(-1);
           drinks=drinks+1;
           write("You pour the spuckballs into the detonator. Somehow all of them clump together\n"+
	   "and form one massive spuckball. There are ["+drinks+"] spuckballs remaining.\n");
           say(capitalize(this_player()->query_name()) + " pours some spuckballs into the detonator.\n");
	   return 1;
         }
 return 0;
}

use(arg){
object tp;
tp = this_player();
  if(!arg || arg != "spuckball"){
        return 0;
} else {
        if(arg == "spuckball"){
	  drinks=drinks - 1;
	  area_attack();
	    if(drinks == 0){
              write("That was the last spuckball.\n");
              say("You notice "+(tp->query_name())+"'s Spuckball detonator is empty.\n");
                }
return 1;
                }
        }
}
get() { return 1; }

query_weight() { return 4; }

area_attack() {
object room,ob2,oc2;
object ob,TP;
TP=this_player();
room=environment(TP);
ob=first_inventory(room);

write("You activate the detonator and see a spuckball get vaporized!\n");
say((TP->query_name())+" detonates a HUGE spuckball!\n");
while(ob) {
        object oc;
        oc=ob;
        ob=next_inventory(ob);
	  if(living(oc)) {
            if(oc->query_npc() !=1) {
say((oc->query_name())+" dodges the hot, gooey muck!\n");
write("You watch as "+(oc->query_name())+" deftly dodges the spuckball flak.\n");
        }
	    if(oc->query_npc() == 1) {
write("You see "+(oc->query_name())+" get plugged by spuckball fragments!\n");
say((oc->query_name())+" is zokked by spuckball plasma!\n");
	    oc->hit_player(7+random(18));
	      if(oc && !oc->query_attack()) {
		oc->attack_object(TP); }
        }
   }
}
return 1;
}
