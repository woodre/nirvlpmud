
/*
 * DECK OF MANY THINGS (3/19/94)
 * Each card drawn can be advantageous or disasterous
 * Initially get 2 draws from the deck.
 * Player must be 15th level to draw a card!
 * Cards:  sun    -  gain 50,000 exp
 *         star   -  raise one attribute by 2 points
 *         gem    -  gain 10,000 gp
 *         skull  -  Must fight Death, to the death [death.c]
 *         ruin   -  Lose all money and possessions
 *         jester -  Gain 10,000 exp or 2 more draws (player's choice)
 *         fool   -  Lose 50,000 exp
 *         idiot  -  Lose 1-4 intelligence points.  Draw again
 *         donjon -  Player is trapped in a Donjon  [donjon.c]
 */

object drawer;

#define TELL(x) tell_room(environment(drawer), x)
#define CME capitalize(drawer->query_name())

int draws;
object cards;

reset(arg) {
   if(arg)
     return;
   draws = 2;
   extra_reset();
}

id(str) { return str == "deck"; }

get() { return 1; }

query_value() { return draws*5000; }

extra_reset() {
   cards = allocate(9);
   cards = ({ "sun", "star", "gem", "skull", "ruin", "jester", "fool",
              "idiot", "donjon" });
}

short() { return "A deck of many things ("+draws+" draws left)"; }

long() {
   write("\n");
   write("*** WARNING *** WARNING *** WARNING *** WARNING ***\n\n");
   write("This is a very powerful deck.  It can be very benificial\n");
   write("to the person who draws the cards from it or it can \n");
   write("bring about your death.\n");
   write("If you choose to draw a card you do so at your own risk.\n");
   write("Under no circumstance will the outcome of the draw\n");
   write("be reversed.       -Molasar\n");
}

init() {
   add_action("draw","draw");
}

draw() {
   int n;
   if(this_player()->query_level() < 15) {
     write("You are too low a level to use this item.\n");
     return 1;
   }
   if(!draws) {
     write("You have no more draws left.  The deck disappears.\n");
     destruct(this_object());
     return 1;
   }
   drawer = this_player();
   n = random(sizeof(cards));
   get_card(cards[n]);
   return 1;
}

get_card(str) {
   if(!str) {
     write("Error:  No card passed!\n");
     return 1;
   }
   draws -= 1;
   TELL(CME+" draws a card from a deck.\n");
   write("\nYou draw the "+capitalize(str)+" card.\n");
   if(str == "sun") sun_card();
   if(str == "star") star_card();
   if(str == "gem") gem_card();
   if(str == "skull") skull_card();
   if(str == "ruin") ruin_card();
   if(str == "jester") jester_card();
   if(str == "fool") fool_card();
   if(str == "idiot") idiot_card();
   if(str == "donjon") donjon_card();
   return 1;
}

sun_card() {
   write("You feel more experienced!\n");
   drawer->add_exp(50000);
   return 1;
}

star_card() {
   int n;
   n = 0;
   if(drawer->query_attrib("str") <= 18)
     drawer->raise_strength(2);
   else
     if(drawer->query_attrib("int") <= 18)
        drawer->raise_intelligence(2);
   else
     if(drawer->query_attrib("ste") <= 18)
       drawer->raise_stealth(2);
   else
     if(drawer->query_attrib("wil") <= 18)
       drawer->raise_will_power(2);
   else
     if(drawer->query_attrib("sta") <= 18)
       drawer->raise_stamina(2);
   else
     if(drawer->query_attrib("mag") <= 18)
       drawer->raise_magic_aptitude(2);
   else
     if(drawer->query_attrib("luc") <= 18)
       drawer->raise_luck(2);
   else
     if(drawer->query_attrib("pie") <= 18)
       drawer->raise_piety(2);
   else {
     write("Unable to raise any of your attributes.  Draw again.\n");
     draws += 1;
   }
   return 1;
}

gem_card() {
   this_player()->add_money(10000);
   write("You gain some money!\n");
   return 1;
}

skull_card() {
   object death;
   write("Death appears before you!  A fight to the death!\n");
   death = clone_object("players/molasar/rowan/magic/obj/death");
   death->set_target(drawer->query_real_name());
   move_object(death, environment(drawer));
   death->attack_object(drawer);
   return 1;
}

ruin_card() {
   int money;
   object invob, next_invob;

   money = drawer->query_money();
   drawer->add_money(-money);
   invob = first_inventory(drawer);
   while(invob) {
     next_invob = next_inventory(invob);
      if(!invob->id("ND") && !invob->drop() && invob != this_object())
       destruct(invob);
     invob = next_invob;
   }
   write("All your wealth and possessions disappear.\n");
   return 1;
}

jester_card() {
   write("You can gain [a] 10,000 exp or [b] two additional draws: ");
   input_to("jester_answer");
   return 1;
}

jester_answer(str) {
    if(str != "a" && str != "b") {
     write("You can gain [a] 10,000 exp or [b] two additional draws: ");
     input_to("jester_answer");
     return 1;
   }
   if(str == "a") {
     write("You gain experience!\n");
     drawer->add_exp(10000);
     return 1;
   }
   if(str == "b") {
     write("You gain two additional draws.\n");
     draws += 2;
     return 1;
   }
}

fool_card() {
   write("You lose experience!\n");
   drawer->add_exp(-50000);
   return 1;
}

idiot_card() {
   int n;
   n = 1 + random(4);

   write("You lose intelligence!\n");
   write("You may draw again.\n");
   drawer->raise_intelligence(-n);
   draws += 1;
   return 1;
}

donjon_card() {
   write("You are imprisoned!\n");
   move_object(drawer, "/players/molasar/rowan/magic/obj/donjon");
   call_other("/players/molasar/rowan/magic/obj/donjon", "set_start_time", 1);
   return 1;
}

