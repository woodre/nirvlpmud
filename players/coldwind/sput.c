#include "/players/coldwind/define.h"

#define user environment(this_object())->query_name()
inherit "obj/treasure.c";
  string msgs;


id(str){ return str == "gift" || str == "scale"; }
short() ;
long()

{
	write("This is a light measuring scale. It's a gift from Mizan,\n"+
		  "Data and Coldwind. You think if you 'step' on 'scale' you\n"+
		  "can find your weight. \n");
}

reset()
{
	if(!msgs)
	{
		msgs = ({
			"You win a potato!",
			"You smell like cheese.",
			"The world is flat.",
			"I have to scratch myself.",
		});
	}
}

init()
{
	add_action("use_scaler", "step");
}

use_scaler(str){
if(str == "scale")
{
	int i;
	string temp;
	string result;

	/* our random number */
	i = random(650);

	/* if our random number is at a certain range we use a default message */
	if(i < 30)
		temp = "OOOPPS..."+ user +" falls of the scaler.";
		else
	if(i < 100 && i > 50)
		 temp = ""+ user +" steps on the scale.\n"+
		 	  	"The scale reads "+BOLD+ i +NORM+" lb.\n"+
				"The scale gives "+ user +" 1000 coins to buy some food.";
else
	if(i < 150 && i > 100)
		 temp = ""+ user +" steps on the scale.\n"+
		 	  	""+ user +" weighs "+BOLD+ i +NORM+" lb.\n"+
				"The scale for some reason starts to hump "+tp->POS +" leg,\n"+
				"it must has a crush on "+ tp->OBJ +".\n"+
				"Such a lucky bastard!!:)";
				else
if(i < 200 && i > 150)
		 temp = ""+ user +" stands on the scale and checks "+tp->POS +" weight.\n"+
		 	    "The scale reads "+BOLD+ i +NORM+" lb.\n"+
				"AWWW...Nobody is perfect :~(";
	else
if(i < 300 && i > 200)
		 temp = ""+ user +" weighs "+ tp->OBJ +"self on the scale, as it then\n"+
		 "spins..."+ tp->PRO +" wonder when it will stop.\n"+
		 "Finally, the scale stops at "+BOLD+ i +NORM+" lb.";
else
if(i < 400 && i > 300)
		 temp = ""+ user +" steps on the scale to weighs "+ tp->OBJ +"self.\n"+
		 "All the sudden, you hear a loud C R A C K  coming from the scale.\n"+
		 "Just in time, "+ user +" catches that he weighs "+BOLD+ i +NORM+" before the scale\n"+
		 "shatters under "+tp->POS +" feet.";
		 else
if(i < 500 && i > 400)
		 temp = "The scale shows "+BOLD+ i +NORM+" lb when "+ user +" steps on it.\n"+
		 	  	"The scale pushes "+ user +" away and screams: \n"+
				"ONE PERSON AT THE TIME, DAMN IT!!!!";
		 else
		 
if(i < 600 && i > 500)
		 temp = ""+ user +" approaches the scale to find out "+tp->POS +" weight, but\n"+
		        "the scale jumps up and says: HELL NO... I' m not letting a "+BOLD+"600"+NORM+" lb\n"+
				"fat ass on me, go loose some weight first.";
	 
	/* otherwise we generateour random message */
	else
		temp = "The scale is stuck...\n"+
		 "What a crapy gift!";

	/* assembly */
	result = "" + temp + "\n";

	say(result);
	write(result);
	return 1;

}
}
short(){
  string str;
    switch(random(8)) {
      case 0: str=HIW; break;
      case 1: str=HIB; break;
      case 2: str=BLU; break;
      case 3: str=BOLD; break;
      case 4: str=BOLD+BLK; break;
      case 5: str=HIR; break;
	  case 6: str=HIY; break;
	  case 7: str=HIC; break;
      default: str=HIB; break;

 }
    return str+"Bathroom Scale"+NORM;
  }
  