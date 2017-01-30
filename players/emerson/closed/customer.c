inherit "/players/emerson/closed/FuzzyBeast.c";
reset(arg){
   object gold,pizza;
   if(arg) return;
   set_name("customer");
   set_race("human");
    short_desc=({
    "A hungry customer",
	"An ugly customer",
	"A nerdy looking customer",
	"An annoying customer",
	"A pissed off customer",
	"A satisfied customer",
	"A happy customer",
	"A stuffed customer",
  });
  long_desc=({
	"This customer is too busy eating to even notice you, but it looks like\n" +
	"you will have to kill him to get some pizza.\n",
	"This customer seems to be suffering from a mild case of indegestion you\n" +
	"better get that pizza away from him before it gets serious.\n",
	"This customer looks like he has eaten a few too many pizzas, maybe you\n" +
	"should put him out of his misery.\n",
  });
  ::reset(arg);
   set_level(13);
   set_hp(195);
   set_al(100);
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_whimpy();
   set_chat_chance (4);
    load_chat("The customer drools on the floor.\n");
    load_chat("The customer drops a slice on the floor but eats it anyway.\n");
    load_chat("The customer leaves a big tip for the waitress.\n");
    load_chat("The customer devours another slice of pizza.\n");
   set_a_chat_chance(35);
   load_a_chat("The customer bites you.\n");
   load_a_chat("The customer screams: You bastard!!!\n");
   load_a_chat("The customer knees you in the groin.\n");
   gold=clone_object("obj/money");
   gold->set_money(475+random(50));
   move_object(gold,this_object());
    pizza=clone_object("/players/emerson/heal/pizza.c");
   move_object(pizza,this_object());
}
