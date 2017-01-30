#include "../defs.h"

int Tend;

/* prototype declaration */
string get_number(int i);

void long()
{
    write(
      "Dark tendrils of shadow creep and crawl along your body,\n"+
      "slithering up and down you, sometimes lashing out at\n"+
      "nothingness around you.\n");
}

void extra_look()
{
    if(this_player() == environment())
	write("Slithering tendrils of "+(!random(2) ? HIK : HIW)+"shadow"+NORM+" surround you.\n");
    else 
	write((string)environment()->QN + " is surrounded by slithering "+(!random(2) ? HIK : HIW)+"shadows"+NORM+".\n");
}


id(str) { return str == "tendrils" || str == "shadowy tendrils" ||
    str == "fallen_tendril_armor";
}

drop() { return 1; }

get() { return 1; }

void set_tendrils(int x) { Tend = x; }

int tendrils() 
{
    int i;
    int w,s;
    int num, ret;
    string does, does2, how, how2, what;
    string number;
    string color;
    object nmy;

    if(!(nmy = (object)USER->query_attack()))
	return 0;

    if(!random(5))
	return 0;

    w = (int)USER->query_attrib("wil");
    s = (int)USER->query_attrib("ste");	

    if(Tend > 10)
	Tend = 10;

    if(!random(2))
	color = HIW;
    else
	color = HIK;

    if(!random(5))
    {
	if(random(100) < 40)
	{
	    switch(random(14))
	    {
	    case 0:
		tell_object(USER,
		  "\nTendrils of "+color+"living shadow"+NORM+
		  " whip about you, furiously trying to\n"+
		  "protect their master.\n\n");
		tell_room(environment(USER),
		  "\nTendrils of "+color+"living shadow"+NORM+" whip about "+
		  (string)USER->QN+", furiously trying to\n"+
		  "protect their master.\n\n", ({ USER }));
		break;
	    case 1:
		tell_object(USER,
		  "\nDark whisps of "+color+"shadow"+NORM+" push "+
		  (string)nmy->QN+" back.\n\n");
		tell_room(environment(USER),
		  "\nDark whisps of "+color+"shadow"+NORM+" push "+
		  (string)nmy->QN+" back.\n\n", ({ USER }));
		break;
	    case 2:
		tell_object(USER,
		  "\nYou leap to the side as "+color+"shadowy tendrils"+NORM+
		  " deflect\n"+(string)nmy->QN+"'s incoming attack.\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" leaps to the side as "+
		  color+"shadowy tendrils"+NORM+" deflect\n"+
		  (string)nmy->QN+"'s incoming attack.\n\n", ({ USER }));
		break;
	    case 3:          
		tell_object(USER,
		  "\nYou stand calm amid a dancing storm of "+color+
		  "shadowy tendrils"+NORM+".\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" stands calm amid a dancing storm of "+
		  color+"shadowy tendrils"+NORM+".\n\n", ({ USER }));
		break;
	    case 4:
		tell_object(USER,
		  "\nYou point at "+(string)nmy->QN+". "+color+
		  "Shadows"+NORM+" lash out and sidetrack\n"+
		  (string)nmy->QN+"'s attack.\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" points at "+(string)nmy->QN+
		  ". "+color+"Shadows"+NORM+" lash out and sidetrack\n"+
		  (string)nmy->QN+"'s attack.\n\n", ({ USER }));
		break;
	    case 5:
		tell_object(USER,
		  "\nYou rise into the air atop slender "+color+
		  "tendrils of shadow"+NORM+".\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" rises into the air atop slender "+color+
		  "tendrils of shadow"+NORM+".\n\n", ({ USER }));
		break;
	    case 6:
		tell_object(USER,
		  "\nYou leap back out of "+nmy->QN+"'s attack. Tendrils of\n"+
		  color+"shadow"+NORM+" rush to the ground to cushion your fall.\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" leaps back out of "+nmy->QN+
		  "'s attack. Tendrils of\n"+color+"shadow"+NORM+
		  " rush to the ground to cushion "+
		  (string)USER->query_possessive()+" fall.\n\n", ({ USER }));
		break;
	    case 7:
		tell_object(USER,
		  "\nYou hover above the ground on strands of wavering "+
		  color+"shadow"+NORM+".\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" hovers abve the ground on strands of wavering "+
		  color+"shadow"+NORM+".\n\n", ({ USER }));
		break;
	    case 8:
		tell_object(USER,
		  "\nAloft tendrils of "+color+"shadow"+NORM+", you glare at "+ 
		  (string)nmy->QN+",\ncalmly confident come any danger.\n\n");
		tell_room(environment(USER),
		  "\nAloft tendrils of "+color+"shadow"+NORM+", "+
		  (string)USER->QN+" glares at "+(string)nmy->QN+",\n"+
		  "calmly confident come any danger.\n\n", ({ USER }));
		break;
	    case 9:
		tell_object(USER,
		  "\nYou calmly glide forward on living "+color+"shadow"+NORM+".\n\n");
		tell_room(environment(USER),
		  "\nYou watch as "+(string)USER->QN+
		  " calmly glides forward on living "+color+"shadow"+NORM+".\n\n", ({ USER }));
		break;
	    case 10:
		tell_object(USER,
		  "\nYou are launched into the air by "+color+"shadowy tendrils"+NORM+
		  ", landing\nfurther away.  You stare narrowly at "+
		  (string)nmy->QN+".\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" is launched into the air by "+color+
		  "shadowy tendrils"+NORM+", landing\nfurther away.  "+
		  capitalize((string)USER->query_pronoun())+" stares narrowly at "+
		  (string)nmy->QN+".\n\n", ({ USER }));
		break;
	    case 11:
		tell_object(USER,
		  "\nYou clench your fists and grit your teeth as you will\n"+
		  color+"living shadow"+NORM+" to beat back the attack of "+
		  (string)nmy->QN+".\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" clenches "+(string)USER->query_possessive()+
		  " fists and grits "+(string)USER->query_possessive()+
		  " teeth as "+(string)USER->query_pronoun()+" wills\n"+color+
		  "living shadow"+NORM+" to beat back the attack of "+
		  (string)nmy->QN+".\n\n", ({ USER }));
		break;
	    case 12:
		tell_object(USER,
		  "\nYou point at "+(string)nmy->QN+", sending tendrils of "+color+
		  "shadow"+NORM+"\nleaping forward in your defense.\n\n");
		tell_room(environment(USER),
		  "\n"+(string)USER->QN+" points at "+(string)nmy->QN+
		  ", sending tendrils of "+color+"shadow"+NORM+
		  "\nleaping forward in "+(string)USER->query_possessive()+
		  " defense.\n\n", ({ USER }));
		break;
	    case 13:
		tell_object(USER,
		  "\nTendrils of "+color+"shadow"+NORM+
		  " lash out from you, whistling through the air.\n\n");
		tell_room(environment(USER),
		  "\nTendrils of "+color+"shadow"+NORM+" lash out from "+
		  (string)USER->QN+", whistling through the air.\n\n", ({ USER }));
		break;
	    }
	}

	for(i = 0; i < Tend; i ++) /* works like homing in on a target, chances increase */
	{                          /* progressively and as tendrils before them hit */
	    if(i < 2) /* first two get get 10 to 24% chance to hit */
	    {
		if(random(100) < ((w / 3) + random(s / 3)))
		    num += 1;
	    }
	    else if(i < 5) /* next 3 get get 15 to 49% chance to hit */
	    {               
		if(random(100) < ((w / 2) + random(s / 2) + (num * 5)))
		    num += 1;
	    }
	    else if(i < 8) /* next 3 get get 20 to 65% chance to hit */
	    {               
		if(random(100) < (((w * 2) / 3) + random(s / 2) + (num * 5)))
		    num += 1;
	    }
	    if(i < Tend) /* last ones get get 30 to 89% chance to hit */
	    {
		if(random(100) < ((w + random(s / 2) + (num * 5))))
		    num += 1;
	    }
	}

	switch(random(4))
	{
	case 0: does = "lash out";  does2 = "lashes out"; break;
	case 1: does = "whip outward"; does2 = "whips outward"; break;
	case 2: does = "fly out"; does2 = "flies out"; break;
	case 3: does = "circle out"; does2 = "circles out"; break;
	}
	switch(random(4))
	{
	case 0: how = "wrap around"; how2 = "wraps around"; break;
	case 1: how = "jar"; how2 = "jars"; break;
	case 2: how = "whip about"; how2 = "whips about"; break;
	case 3: how = "encircle"; how2 = "encircles"; break;
	}
	switch(random(4))
	{
	case 0: what = ", nearly bringing them to the ground!"; break;
	case 1: what = ", confusing them."; break;
	case 2: what = "."; break;
	case 3: what = " tripping them up."; break;
	}

	if(num < 1) return 0;

	ret = 1 + random(num);	

	num = 1 + num + random(num);

	if(num < 2)
	{
	    tell_object(USER,
	      "A tendril of "+color+"shadow"+NORM+" "+does2+" from you and "+
	      how2+" "+(string)nmy->QN+""+what+"\n\n");
	    tell_room(environment(USER),
	      "A tendril of "+color+"shadow"+NORM+" "+does2+" from "+(string)USER->QN+
	      " and "+how2+" "+(string)nmy->QN+""+what+NORM+"\n\n", ({ USER }));
	}
	else
	{
	    number = get_number(num);
	    tell_object(USER,
	      ""+number+" tendrils of "+color+"shadow"+NORM+
	      " "+does+" from you and "+
	      how+" "+(string)nmy->QN+""+what+"\n\n");
	    tell_room(environment(USER),
	      ""+number+" tendrils of "+color+"shadow"+NORM+
	      " "+does+" from "+(string)USER->QN+" and "+
	      how+" "+(string)nmy->QN+""+what+NORM+"\n\n", ({ USER }));
	}

	if(ret > 3)
	    ret = 3;

	return ret;
    }
    return 0;
}


string get_number(int i) 
{
    string *numero;
    numero = ({ "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
      "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", 
      "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
      "Nineteen", "Twenty", });
    return numero[i];
}
