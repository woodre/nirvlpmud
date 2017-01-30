inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define COST 2000
#define MAX 12

/*********************************************************************/
/* the calculated cost for these heals is 2160.  im going to try and */
/* and get them approved for 2000 because of the unique nature of    */
/* the realm and the limited quantity avaliable.                     */
/*********************************************************************/

int quantity;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Ariel Alchemist");
  set_alias("alchemist");
  set_race("ariel");
  set_gender("male");
  set_short("The Ariel Alchemist");
  set_long("The Ariel Alchemist");
  set_level(18);
  set_ac(20);
  set_wc(26);
  set_hp(450);
  set_al(200);
  set_a_chat_chance(20);
  load_a_chat("Ariel Guard says: You will not get away with this!\n");
  load_a_chat("The Ariel Guard calls for help.\n");
  load_a_chat("Ariel Guard fights desperately to save his city.\n");
  load_a_chat("Ariel Guard says: Stop them!\n");
  money = (200);
  message_hit = ({
	"pierces", "'s body with a golden spear",
	"thrusts his spear into", "",
	"swoops down and drops a rock on", "'s head",
	"flies out of", "'s reach",
	"swoops down and stabs", "",
	"flies down and clocks", " on the head with his shield",
	"prods", " with his spear",
  });
  quantity = 8 + random(4);
  call_out("refill", 10+random(100));
}

id(str) {
  return str == "ariel" || str == "alchemist" || str == "ariel_alchemist";
}

long() {
  write(
  "This Ariel specializes in concocting potions and elixers.  His special\n"+
  "formulae produces a poignant liquid with powerful healing properties.\n"+
  "The Ariel Alchemist currently has "+quantity+" potions ready.  He will sell you\n"+
  "one of these healing potions for "+COST+" gold coins.\n");
  return;
}

refill() {
  if(quantity >= MAX) {
	call_out("refill", 200);
	return 1;
  }
  tell_room(environment(this_object()),
	"The Ariel Alchemist brews another potion and bottles it.\n");
  quantity++;
  call_out("refill", 200 + random(400));
  return 1;
}

init() {
  ::init();
  add_action("buy_potion", "buy");
}

buy_potion(str) {
  if(str == "potion") {
	if(!quantity) {
		write("The Ariel says: I don't have anymore potions just yet.\n");
		write("The Ariel says: You will have to wait until I brew more.\n");
		return 1;
	}
	if(this_player()->query_money() < COST) {
		write("You can't afford it.\n");
		return 1;
	}
	write("You buy a potion from the Alchemist.\n");
	say(capitalize(this_player()->query_name())+" buys a potion from the Alchemist.\n");
	move_object(clone_object("players/pavlik/cloudcity/obj/heal_potion"), this_player());
	this_player()->add_money(-COST);
	quantity--;
	return 1;
  }
}

query_cloud_npc() { return 1; }

hit_player(x) {
  if(this_player()->query_npc()) return x;
  return ::hit_player(x);
}

