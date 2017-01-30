#define tp this_player()->query_name()

id(str)
{
	return str == "pool" || str == "water";
}

short()
{
	return "A pool of water";
}

long()
{
	write("A  pool of enchanted water.  You think that if you\n" +
		  "<drink> from it, you may feel a lot better.\n" +
		  "You also have the strong desire to <bathe> in it...\n"+
         "Or, if you are feeling playful, feel free to dunk\n"+
         "someone or splash them.\n");
}

sip_water(str)
{
	if (str == "water" || str == "pool" || str == "from pool") {
		if (!call_other(this_player(), "drink_soft", 25))
			return 0;
		write("You drink from the pool of magic water.\n" +
			  "You feel stronger and your head feels quite clear.\n");
		say(tp + " drink from the magic pool of water.\n");
		call_other(this_player(), "heal_self", 20);
		return 1;
	}
	return 0;
}

init()
{
  add_action("sip_water", "drink");
	add_action("bathe", "bathe");
   add_action("splash", "splash");
   add_action("dunk", "dunk");
}

splash(str){
object splash;
   if(!str){
    write("You splash yourself with water!\n");
    say(this_player()->query_name()+" splashes "+
    this_player()->query_objective()+"self with water!\n");
    return 1;
    }
   splash = present(str, environment(this_player()));
   if(!splash){ write("You do not see them here.\n");
                return 1;
              }
   if(!living(splash)){
      write("You could splash that I suppose.\n");
      return 1;
      }
   write("You playfully splash "+splash->query_name()+" with water!\n");
   say(this_player()->query_name()+" playfully splashes "+
       splash->query_name()+" with water!\n");
   return 1;
   } 


dunk(str){
object splash;
   if(!str){
    write("You dunk yourself under the water!\n");
    say(this_player()->query_name()+" dunks "+
    this_player()->query_objective()+"self under the water!\n");
    return 1;
    }
   splash = present(str, environment(this_player()));
   if(!splash){ write("You do not see them here.\n");
                return 1;
              }
   if(!living(splash)){
      write("You could try to dunk that I suppose.\n");
      return 1;
      }
   write("You playfully dunk "+splash->query_name()+" under the water!\n");
   say(this_player()->query_name()+" playfully dunks "+
       splash->query_name()+" under the water!\n");
   return 1;
   } 


get()
{
	return 0;
}

drop()
{
	return 1;
}

query_weight()
{
	return 100;
}

bathe(str)
{
	object ob;

	if (!str) {
		write
			("You strip off your clothing and step into the pool of water.\n"
			 +
			 "The pool is pleasantly warm, and it feels really good...\n");
		say(tp + " strips off " + this_player()->query_possessive() +
			" clothing and steps into the pool.\n" +
			"Say, that looks like fun...\n");
		return 1;
	}
    ob = present(str, environment(this_player()));
	if (!ob) {
		write(capitalize(str) + " is not here to bathe.\n");
		return 1;
	}
	if(!living(ob)){
		write("You can't bathe that!\n");
		return 1;
	}

	write("You pull " + capitalize(str) +
		  " into the water and begin to bathe " + ob->query_objective() +
		  ".\n");
	say(tp + " pulls " + ob->query_name() +
		" into the pool and begins to bathe " + ob->query_objective() +
		".\n", ob);
	tell_object(ob,
				tp +
				" pulls you into the pool and begins to bathe you!\n");
	return 1;
}
