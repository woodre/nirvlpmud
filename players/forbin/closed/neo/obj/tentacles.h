/* Prototype Declarations */
query_total_tents();
query_skill();
query_pgcol();
query_hypermode();

string convert_number(int i)
{
	string *numbs;
	numbs = ({ "zero", "one", "two", "three", "four", "five", "six", "seven", 
	           "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
	           "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
	           "nineteen", "twenty", "twenty-one", "twenty-two", "twenty-three", 
	           "twenty-four", "twenty-five", "twenty-six", "twenty-seven", 
	           "twenty-eight", "twenty-nine", "thirty", });
	return numbs[i];
}

int attack_tentacles()
{
	int tents, num, x, hone, dmg, sub, tot;
	int comb, cont, chance;
	string how, how2, what, what2;
	
  if(!((object)environment()->query_attack())) 
    return 0; 
    
	tents = (int)query_total_tents("attack");
	
	if((int)query_hypermode() || !random(10))
    if((int)environment()->query_pl_k())  	 
	    tents += 5 + random((tents * 3) / 2);
	  else
	    tents += random((tents * 3) / 2);
	
	if(tents > 18) 
	  tents = 18;
	
	if(tents > 5 && random(100) < 30)
	{
		switch(random(20))
		{
			case 0:
			  tell_object(environment(),
			    "You hover over the ground on strands of wavering "+
			    HIW+"Dark Matter"+NORM+"...\n");
			  tell_room(environment(environment()),
			    (string)environment()->QN+
			    " hovers over the ground on strands of wavering "+
			    HIW+"Dark Matter"+NORM+"...\n", ({ environment() }) );
			  break;
			case 1:
				tell_object(environment(),
			    "You peer down at your opponent from atop "+
			    HIW+"Dark Matter Tentacles"+NORM+".\n");
			  tell_room(environment(environment()),
			    (string)environment()->QN+
			    " peer down at "+(string)environment()->POS+ 
			    " opponent from atop "+HIW+"Dark Matter Tentacles"+
			    NORM+".\n", ({ environment() }) );
        break;
			case 2:
        tell_object(environment(),
	        "You stand amid wavering tentacles of "+HIW+"Dark Matter"+NORM+".\n");
			  tell_room(environment(environment()),
			    (string)environment()->QN+
			    " stands amid wavering tentacles of "+
			    HIW+"Dark Matter"+NORM+".\n", ({ environment() }) );				
			  break;
			case 3:
        tell_object(environment(),
	        "You narrow your eyes as you close ground with "+
	        (string)environment()->QN+".\n");
			  tell_room(environment(environment()),
			    (string)(environment()->query_attack())->QN+
			    " narrows "+(string)environment()->POS+" eyes as "+
			    (string)environment()->PRO+" closes ground with "+
			    (string)(environment()->query_attack())->QN+
			    ".\n", ({ environment() }) );				
			  break;
			case 4:
			  tell_object(environment(),
			    "Aloft tentacles of "+HIW+"Dark Matter"+NORM+
			    ", you stand confident in the\nface of danger.\n");
			  tell_room(environment(environment()),
			    "Aloft tentacles of "+HIW+"Dark Matter"+NORM+", "+
			    (string)environment()->QN+
			    " stands confident in the\n"+
			    "face of danger.\n", ({ environment() }) );		  
			  break;
      case 5:
        tell_object(environment(),
          "You glide forward to battle "+
          (string)(environment()->query_attack())->QN+ 
				  " aloft tentacles of "+HIW+"Darkness"+NORM+".\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+" glides forward to battle "+
          (string)(environment()->query_attack())->QN+ 
				  " aloft tentacles of "+HIW+"Darkness"+
				  NORM+".\n", ({ environment() }) );
        break;
			case 6:
			  tell_object(environment(),
			    "You walk calmly amid the chaos of the moment, battling "+
			    (string)(environment()->query_attack())->QN+
			    " to the death.\n");
			  tell_room(environment(environment()),
			    (string)environment()->QN+
			    " walks calmly amid the chaos of the moment, battling "+
          (string)(environment()->query_attack())->QN+
          " to the death.\n", ({ environment() }) );
        break;
			case 7:
			  tell_object(environment(),
			    "You point at "+
			    (string)(environment()->query_attack())->QN+
			    " and send tendrils of "+HIW+"Dark Matter"+NORM+
			    "\nleaping forward.\n");
			  tell_room(environment(environment()),
			    (string)environment()->QN+
			    " point at "+
			    (string)(environment()->query_attack())->QN+
          " and send tendrils of "+HIW+"Dark Matter"+NORM+
			    "\nleaping forward.\n", ({ environment() }) );
        break;
			case 8:
				tell_object(environment(),
				  "You are launched into the air by your tentacles and land near "+
				  (string)(environment()->query_attack())->QN+".\n");
			  tell_room(environment(environment()),
			    (string)environment()->QN+" is launched into the air by "+
			    (string)environment()->POS+" tentacles and lands near "+
			    (string)(environment()->query_attack())->QN+
			    ".\n", ({ environment() }) );
        break;
			case 9:
				tell_object(environment(),
				  "Tentacles lash out from you as you stare at "+
				  (string)(environment()->query_attack())->QN+".\n");
				tell_room(environment(environment()),
				  "Tentacles lash out from "+
				  (string)environment()->QN+" as "+
				  (string)environment()->PRO+" stares at "+
				  (string)(environment()->query_attack())->QN+
			    ".\n", ({ environment() }) );
        break;
			case 10:
				tell_object(environment(),
				  "You raise your hands up to the sky as "+HIW+"Dark Matter"+NORM+
				  " leaps from your\nback toward "+
          (string)(environment()->query_attack())->QN+".\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+
				  " raises "+(string)environment()->POS+
				  " hands to the sky as "+HIW+"Dark Matter"+NORM+" leaps from "+
				  (string)environment()->POS+"\nback toward "+
				  (string)(environment()->query_attack())->QN+
			    ".\n", ({ environment() }) );
			  break;
      case 11:
  	    tell_object(environment(),
  	      "You clench your fists as you command "+HIW+"Dark Matter"+NORM+
  	      "to lash\nout at "+
  	      (string)(environment()->query_attack())->QN+".\n");
  	  	tell_room(environment(environment()),
  	  	  (string)environment()->QN+"clenches "+
  	  	  (string)environment()->POS+" fists as "+
  	  	  (string)environment()->PRO+" commands "+
  	  	  HIW+"Dark Matter"+NORM+" to lash\nout at "+
  	  	  (string)(environment()->query_attack())->QN+
			    ".\n", ({ environment() }) );
        break;
			case 12:
			  tell_object(environment(),
			    "You rise into the air on "+HIW+"Dark Matter"+NORM+" tendrils as you glare\n"+
			    "at "+(string)(environment()->query_attack())->QN+".\n");	
				tell_room(environment(environment()),
				  (string)environment()->QN+" rises into the air on "+
				  HIW+"Dark Matter"+NORM+" tendrils as "+
				  (string)environment()->PRO+" glares\n"+
				  "at "+(string)(environment()->query_attack())->QN+
			    ".\n", ({ environment() }) );
        break;
			case 13:
				tell_object(environment(),
				  "Your tentacles lash out, whistling through the air...\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+
				  "'s tentacles lash out, whistling through the air...\n", ({ environment() }) );
        break;
			case 14:
				tell_object(environment(),
				  "You glide forward on "+HIW+"Dark Matter Wings"+NORM+".\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+
				  " glides forward on "+HIW+"Dark Matter Wings"+NORM+".\n", ({ environment() }) );
        break;
			case 15:
				tell_object(environment(),
				  "Your "+HIW+"Dark Matter Wings"+NORM+" unfurl and seperate into tendrils of\n"+
				  "charging death.\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+
				  "'s "+HIW+"Dark Matter Wings"+NORM+" unfurl and seperate into tendrils of\n"+
				  "charging death.\n", ({ environment() }) );
        break;
			case 16:
				tell_object(environment(),
				  "Your eyes "+query_pgcol()+"blaze"+NORM+" with power.\n");
				tell_room(environment(environment()),
				  "You feel a chill as "+
				  (string)environment()->QN+
				  "'s eyes "+query_pgcol()+"blaze"+NORM+" with power.\n", ({ environment() }) );
        break;
			case 17:
				tell_object(environment(),
				  "You dance with the rhythm of your "+NORM+"Dark Tendrils"+NORM+
				  " as you move in\non "+
				  (string)(environment()->query_attack())->QN+".\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+" dances with the rhythm of "+
				  (string)environment()->POS+" "+HIW+"Dark Tendrils "+NORM+
				  "as "+(string)environment()->PRO+" moves in\non"+
				  (string)(environment()->query_attack())->QN+
				  ".\n", ({ environment() }) );
        break;
			case 18:
				tell_object(environment(),
				  "Your "+HIW+"Dark Matter Tentacles"+NORM+" fill the room with chaos and motion.\n");
				tell_room(environment(environment()),
				  (string)environment()->QN+"'s "+HIW+"Dark Matter Tentacles"+NORM+
				  " fill the room with chaos and motion.\n", ({ environment() }) );  
        break;
			case 19:
				tell_object(environment(),
				  "You calmly glide forward on "+HIW+"Dark Matter Tendrils"+NORM+"...\n");
				tell_room(environment(environment()),
				  "You watch as "+(string)environment()->QN+
				  " calmly glides forward on "+HIW+"Dark Matter Tendrils"+NORM+
				  ".\n", ({ environment() }) );  
        break;
		}
	}

/* /////////////////////////////////////////////////////////////////////////
//  Each two tentacles incrimentally has better chances to hit, and any
//  previous tentacle that hits improves the chances later.  Think of it
//  like honing in on a target.  The player never has more than 95% chance
//  of tentacles hitting.
///////////////////////////////////////////////////////////////////////// */	  
	
  chance = hone = sub = dmg = tot = 0;
  
  if((int)query_hypermode())
  {
    comb = ((int)query_skill("combat") / 2);
    cont = ((int)query_skill("control") * 2);
    dmg = ((((int)query_skill("combat") * 3) / 2));    
  }
  else
  {
    comb = ((int)query_skill("combat") / 2);
	  cont = ((int)query_skill("control") * 5);
    dmg = ((int)query_skill("combat") / 2);	  
  }
  
  if(comb < 1)
    comb = 1;
	if(cont < 10)
	  cont = 10;
	  	
	for(x = 0; x < tents; x++)
	{
  	switch(x)
  	{
    	case 0..1:
    	  chance = (((comb * 100) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;
      	break;
    	case 2..3:
    	  chance = (((comb * 125) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;
     	case 4..5:
    	  chance = (((comb * 150) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;
     	case 6..7:
    	  chance = (((comb * 175) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;
     	case 8..9:
    	  chance = (((comb * 200) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;               
     	case 10..11:
    	  chance = (((comb * 225) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
      	break;   
     	case 12..13:
    	  chance = (((comb * 250) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;
     	case 14..15:
    	  chance = (((comb * 275) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;
     	case 16..17:
    	  chance = (((comb * 300) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;
    	default:
    	  chance = (((comb * 100) / 100) + cont + hone);
    	  if((chance <= 95 ? random(100) < chance : random(100) < 95))
    	  {
      	  sub = 1 + random(dmg);
       	  hone += 1 + sub*2;
       	  tot += sub;
       	  num += 1;
    	  }
    	  else
    	    hone -= 1 + random(dmg);
    	    if(hone < 0)
    	      hone = 0;    	    
      	break;       
    }
  }
  
	switch(tot)
	{
  	case 0..5: how = "nick"; how2 = "nicked"; break;
  	case 6..15: how = "hit"; how2 = "hit"; break;
  	case 16..30: how = "strike"; how2 = "struck"; break;
  	case 31..60: how = "slice"; how2 = "sliced"; break;
  	case 61..85: how = "impale"; how2 = "impaled"; break;
  	case 86..10000: how = "devastate"; how2 = "devastated"; break;
	}
	
	switch(random(5))
	{
    case 0: what = "flies"; what2 = "fly"; break;
    case 1: what = "lashes"; what2 = "lash"; break;
    case 2: what = "streaks"; what2 = "streak"; break; 
    case 3: what = "whips"; what2 = "whip"; break;
    case 4: what = "snaps"; what2 = "snap"; break;	
	}
	
	if(!num) 
	  return tot;
	  
	else if(num < 2)
	{
		tell_object(environment(),
			query_pgcol()+"["+HIW+" Tentacles "+query_pgcol()+"]"+NORM+
		  "  A "+HIW+"Dark Matter Tentacle "+NORM+
		  what+" out and "+how+"s "+
		  (string)(environment()->query_attack())->QN+"!\n");
		tell_object((object)(environment()->query_attack()),
		"You are "+how2+" by a "+BOLD+"Dark Matter Tentacle"+NORM+" from "+
		(string)environment()->QN+"!\n");  
	}
	
	else
	{
		tell_object(environment(),
			query_pgcol()+"["+HIW+" Tentacles "+query_pgcol()+"]"+NORM+
		  "  "+CAP(convert_number(num))+" "+HIW+
		  "Dark Matter Tentacles "+NORM+what2+" out and "+how+" "+
		  (string)(environment()->query_attack())->QN+"!\n");
		tell_object((object)(environment()->query_attack()),
		"You are "+how2+" by "+convert_number(num)+" "+BOLD+"Dark Matter Tentacles"+NORM+" from "+
		(string)environment()->QN+"!\n");    	
	}
	
  present("neoobj", environment())->tts(num);
	return tot;
}


int defense_tentacles()
{
  int tents, num, x, hone, sub, tot;
	int comb, cont;
	string h,hh,hhh,h2,hh2;
	
	tents = (int)query_total_tents("defend");
	
  if(!((object)environment()->query_attack())) 
    return 0; 
	
	if(tents > 3 && random(100) < 40)
	{
		switch(random(10))
		{
			case 0:
				tell_object(environment(),
				  "Tentacles whip about, furiously defending you.\n");
				tell_room(environment(environment()),
				  "Tentacles whip about "+
				  (string)environment()->QN+", furiously defending "+
				  (string)environment()->OBJ+".\n", ({ environment() }) );
        break;				
			case 1:
				tell_object(environment(),
				  "Your "+HIW+"Dark Matter Tentacles"+NORM+" wrestle with "+
				  (string)(environment()->query_attack())->QN+"'s arms and legs.\n");
				tell_room(environment(environment()),
          (string)environment()->QN+"'s "+HIW+"Dark Matter Tentacles"+NORM+
          " wrestle with "+(string)(environment()->query_attack())->QN+
				  "'s arms and legs.\n", ({ environment() }) );
        break;				
			case 2:
				tell_object(environment(),
				  "Your "+HIW+"Dark Matter Tentacles"+NORM+" push "+
				  (string)(environment()->query_attack())->QN+" back.\n");
				tell_room(environment(environment()),
          (string)environment()->QN+"'s "+HIW+"Dark Matter Tentacles"+NORM+
          " push "+(string)(environment()->query_attack())->QN+
				  " back.\n", ({ environment() }) );
        break;				
			case 3:
				tell_object(environment(),
				  "Tendrils of "+HIW+"Dark Matter "+NORM+" fly forward and partially deflect the incoming\n"+
				  "attack from "+(string)(environment()->query_attack())->QN+".\n");
				tell_room(environment(environment()),
          (string)environment()->QN+" tendrils of "+HIW+"Dark Matter Tentacles"+NORM+
          " fly foward and partially deflect the incoming\n"+
          "attack from "+(string)(environment()->query_attack())->QN+".\n", ({ environment() }) );
        break;								
			case 4:
				tell_object(environment(),
				  "You leap to the side as tendrils partially deflect the incoming attack.\n");
				tell_room(environment(environment()),
          (string)environment()->QN+" leaps to the side as tendrils partially "+
          "deflect the incoming attack.\n", ({ environment() }) );
        break;								
			case 5:
				tell_object(environment(),
				  "You stand calm amid a dancing storm of "+HIW+"Dark Matter Tentacles"+NORM+".\n");
				tell_room(environment(environment()),
          (string)environment()->QN+" stands calm amid a dancing storm of "+HIW+
          "Dark Matter Tentacles"+NORM+".\n", ({ environment() }) );
        break;								
			case 6:
				tell_object(environment(),
				  "You rise into the air atop tentacles of "+HIW+"Dark Matter"+NORM+".\n");
				tell_room(environment(environment()),
          (string)environment()->QN+" rises into the air atop tentacles of "+HIW+
          "Dark Matter"+NORM+".\n", ({ environment() }) );
        break;								
			case 7:
				tell_object(environment(),
				  "You point at "+(string)(environment()->query_attack())->QN+
				  ".  Tentacles lash out and sidetrack "+
				  (string)(environment()->query_attack())->QN+"'s attack.\n");
				tell_room(environment(environment()),
          (string)environment()->QN+" points at "+
          (string)(environment()->query_attack())->QN+
          ".  Tentacles lash out and sidetrack "+
          (string)(environment()->query_attack())->QN+
          "'s attack.\n", ({ environment() }) );
        break;								
			case 8:
				tell_object(environment(),
				  "Your tentacles confuse "+
				  (string)(environment()->query_attack())->QN+
				  "with their hypnotic dance.\n");
				tell_room(environment(environment()),
          (string)environment()->QN+"'s tentacles confuse "+
          (string)(environment()->query_attack())->QN+
          " with their hypnotic dance.\n", ({ environment() }) );				
        break;
			case 9:
				tell_object(environment(),
				  "You sneer at "+
				  (string)(environment()->query_attack())->QN+
				  "'s feeble attack and command your tendrils forward.\n");
				tell_room(environment(environment()),
          (string)environment()->QN+" sneers at "+
          (string)(environment()->query_attack())->QN+
          "'s feeble attack and commands "+
          (string)environment()->POS+
          " tendrils forward.\n", ({ environment() }) );
        break;				
		}
	}
	
/* /////////////////////////////////////////////////////////////////////////
//  Each two tentacles incrimentally has better chances to hit, and any
//  previous tentacle that hits improves the chances later.  Think of it
//  like honing in on a target.
///////////////////////////////////////////////////////////////////////// */	  
	
	hone = 0;
	sub = 0;
	comb = (int)query_skill("combat");
	cont = ((int)query_skill("control") * 2);
	if(cont < 5)
	  cont = 5;	
	
	for(x = 0; x < tents; x++)
	{
		if(x < 2) /* Tentacles one/two have base 5% to 24% chance to hit */
		{         /* Maximum for one is 24%, maximum for two is 30% */
			if(random(100) < (comb + cont + hone))
			{
				sub = 1 + random(((cont * 7) / 36));
				tot += sub;
				hone += (sub * 2);
				num += 1;
			}
		}
		else if(x < 4) /* Tentacles three/four have base 5% to 32% chance to hit */
		{              /* Maximum for three 42%, maximum for four is 46% */
		  if(random(100) < ((comb * 2) + cont + hone))
	    { 
				sub = 1 + random(((cont * 7) / 36));
				tot += sub;
				hone += (sub * 2);
				num += 1;
			}
		}
		else if(x < 6) /* Tentacles five/six have base 5% to 40% chance to hit */
		{              /* Maximum for five is 58%, maximum for six is 62% */
		  if(random(100) < ((comb * 3) + cont + hone))
	    { 
				sub = 1 + random(((cont * 7) / 36));
				tot += sub;
				hone += (sub * 2);
				num += 1;
			}
		}
		else if(x < 8) /* Tentacles seven/eight have base 5% to 48% chance to hit */
		{              /* Maximum for seven is 74%, maximum for eight is 78% */
		  if(random(100) < ((comb * 4) + cont + hone))
	    { 
				sub = 1 + random(((cont * 7) / 36));
				tot += sub;
				hone += (sub * 2);
				num += 1;
			}
		}					
		else           /* Tentacles nine/ten have base 5% to 64% chance to hit */
		{              /* Maximum for nine is 98%, maximum for ten is 102% */
		  if(random(100) < ((comb * 6) + cont + hone))
	    { 
				sub = 1 + random(((cont * 7) / 36));
				tot += sub;
				hone += (sub * 2);
				num += 1;
			}
		}				
  }
	
	switch(random(4))
	{
		case 0: h = "lash out";  h2 = "lashes out"; break;
		case 1: h = "whip outward"; h2 = "whips outward"; break;
		case 2: h = "fly out"; h2 = "flies out"; break;
		case 3: h = "circle out"; h2 = "circles out"; break;
	}
	switch(random(4))
	{
		case 0: hh = "wrap around"; hh2 = "wraps around"; break;
		case 1: hh = "jar"; hh2 = "jars"; break;
		case 2: hh = "whip about"; hh2 = "whips about"; break;
		case 3: hh = "encircle"; hh2 = "encircles"; break;
	}
	switch(random(4))
	{
		case 0: hhh = ", nearly bringing "+
			            (string)(environment()->query_attack())->OBJ+" to the ground!"; break;
		case 1: hhh = ", confusing "+
			            (string)(environment()->query_attack())->OBJ+"."; break;
		case 2: hhh = "."; break;
		case 3: hhh = " tripping "+
			            (string)(environment()->query_attack())->OBJ+" up."; break;
	}
	
	if(num < 1) 
	  return 0;
	
	else if(num < 2)
	{
		if((object)environment()->query_attack())
		{
		  tell_object(environment(),
		    query_pgcol()+"["+HIW+" Defend "+query_pgcol()+"]"+NORM+"  A "+HIW+"Dark Matter Tentacle "+NORM+
		    h2+" and "+hh2+" "+
		    (string)(environment()->query_attack())->QN+hhh+"\n");
		  tell_room(environment(environment()),
		    (string)environment()->QN+"'s tentacle "+h2+" and "+hh2+" "+
		    (string)(environment()->query_attack())->QN+hhh+
		    "\n", ({ environment() }) );  
		}
}
	else
	{
		if((object)environment()->query_attack())
		{
		  tell_object(environment(),
		    query_pgcol()+"["+HIW+" Defend "+query_pgcol()+"]"+NORM+"  "+CAP(convert_number(num))+
		    " "+HIW+"Dark Matter Tentacles "+NORM+h+" and "+hh+" "+
		    (string)(environment()->query_attack())->QN+hhh+"\n");
		  tell_room(environment(environment()),
		    (string)environment()->QN+"'s tentacles "+h+" and "+hh+" "+
		    (string)(environment()->query_attack())->QN+hhh+
		    "\n", ({ environment() }) );  
     }
	}
	
	tot = 1 + ((tot / 3) + (num / 3));
	
	if(query_hypermode())
	{
    if((int)environment()->query_pl_k())  	 
	    tot += 3;
	  else
	    tot += 1+random(3);
  }	
	
	return tot;
}
