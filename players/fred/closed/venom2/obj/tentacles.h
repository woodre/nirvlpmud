/********************************************************************
*************  Tentacles - The other white meat *********************
********************************************************************/

assign_tentacles(int i, string str){
string woo;
if(!str) woo = "none";
else woo = str;
	if(tentacles[i]){
		tell_object(USER,
		"Reassigning "+tentacles[i]+" for "+capitalize(woo)+".\n");
	}
	else{ tell_object(USER, "Assigning tentacle "+(i + 1)+" to "+capitalize(woo)+".\n"); }
	if(woo == "burnoff" || woo == "regeneration"){
		tell_object(USER, "A tentacle retreats into your body to perform its work...\n");
	}
	tentacles[i] = woo;
}

total_tentacles(str){
	int i;
	int total;
	for(i = 0; i < 10; i++){
      if(total_ar() > i){ total += 0; } 
		else if(tentacles[i] == str){ total += 1; }
	}
	return total;
}

tent_list(){
	write("Your Tentacles are assigned to the following locations:\n");
	list_tentacles();
	write("Use, 'link tentacles' to see help on this topic.\n");
	return 1;
}

list_tentacles(){
	int i;
	for(i = 0;  i < 10; i++){
      if(total_ar() > i){
      tell_object(USER, COLOR+(i+1)+NORM+"]  "+BOLD+"UNAVAILABLE"+NORM+"\n"); }
		else if(!tentacles[i]) tell_object(USER, COLOR+(i+1)+NORM+"]  "+BOLD+"Unassigned"+NORM+"\n");
		else tell_object(USER, COLOR+(i+1)+NORM+"]  "+HIB+tentacles[i]+NORM+"\n");
	}
}

in_assign_tentacles(str){
	int which,var1,var2;
	string towhat;
	int i,diff;
	
	if(!str){
		write("Assign tentacle # to <task>  -or-\n"+
			"Assign tentacles # through # to <tasks>\n"+
		COLOR+"Tasks:"+NORM+"\n");
                if(control > 2) write("    "+HIG+"Burnoff"+NORM+"\n");
		if(control > 5) write("    "+HIG+"Regeneration"+NORM+"\n");
		write("    "+HIG+"Attack"+NORM+"\n");
		write("    "+HIG+"Defend"+NORM+"\n\n");
		write(BOLD+"For a listing of tentacle allocations, type 'tentacles'."+NORM+"\n");
		return 1;
	}

	
	if(sscanf(str, "tentacle %d to %s", which, towhat) == 2){
			if(which < 1 || which > 10){ write("Tentacle # must be between 1 and 10.\n"); return 1; }
			if(towhat == "attack"){  assign_tentacles(which - 1, towhat); return 1; }
			else if(towhat == "defend"){ assign_tentacles(which - 1, towhat); return 1; }
                        else if(towhat == "burnoff" && control > 2){ assign_tentacles(which - 1, towhat); return 1; }
			else if(towhat == "regeneration" && control > 5){ assign_tentacles(which - 1, towhat); return 1; }
			else if(towhat == "none"){ assign_tentacles(which - 1, 0); return 1; }
			else{ write("That task is unavailable. Type 'assign' to see a list.\n"); return 1; }
			return 1;
	      }		

	if(sscanf(str, "tentacles %d through %d to %s", var1, var2, towhat) == 3){
			if(var1 < 1 || var1 > 10){ write("Tentacles #'s must be between 1 and 10.\n"); return 1; }
			if(var2 < 1 || var2 > 10){ write("Tentacles #'s must be between 1 and 10.\n"); return 1; }
			if(var1 > var2){	write("1st number must be lower than the 2nd.\n"); return 1; }
			
                        if(towhat == "burnoff" && control > 2){
				for(i = var1 - 1; i < var2; i++){
					assign_tentacles(i, towhat);
				}
         return 1;
			}
			else if(towhat == "regeneration" && control > 5){
				for(i = var1 - 1; i < var2; i++){
					assign_tentacles(i, towhat);
				}
         return 1;
			}
			else if(towhat == "none"){
				for(i = var1 - 1; i < var2; i++){
					assign_tentacles(i, 0);
				}
         return 1;
			}
			else if(towhat == "attack"){
				for(i = var1 - 1; i < var2; i++){
					assign_tentacles(i, towhat);
				}
         return 1;
			}
			else if(towhat == "defend"){
				for(i = var1 - 1; i < var2; i++){
					assign_tentacles(i, towhat);
				}
         return 1;
      	}
			else{ write("That task is unavailable. Type 'assign' to see a list.\n"); return 1; }

			write("That task is unavailable. Type 'assign' to see a list.\n");
			return 1;
		}
	write("That task is unavailable. Type 'assign' to see a list.\n"); 
	return 1;
}


/************************************************************************
**********  Tentacle Attack and Defense Functions ***********************
*************************************************************************
************************************************************************/

attack_tentacles(){
	int boo,yah,x,tot;
	string how,how2;
	
       if(!ATT) return; /* by verte */
	boo = total_tentacles("attack");
	
	if(hypermode) boo += random((boo*3) / 5) + 1;
	else if(boo > 14) boo = 14;
	
	if(boo > 5 && random(100) < 30){
		switch(random(20) + 1){
			case 20:
			tell_room(environment(USER),
			UN+" hovers over the ground on strands of wavering "+BOLD+"Dark Matter..."+NORM+"\n");
			break;
			case 19:
			tell_room(ENVU,
			UN+" peers down at "+UP+" opponent from atop "+BOLD+"Dark Matter Tentacles"+NORM+".\n");
			break;
			case 18:
			tell_room(ENVU,
			UN+" stands amid waving tentacles of "+BOLD+"Dark Matter"+NORM+".\n");
			break;
			case 17:
			tell_room(ENVU,
			UN+" narrows "+UP+" eyes as "+UPR+" closes ground with "+ATTN+".\n");
			break;
			case 16:
			tell_room(ENVU,
			"Aloft tentacles of "+BOLD+"Dark Matter"+NORM+", "+UN+" stands confident in the face\nof danger.\n");
			break;
			case 15:
			tell_room(ENVU,
			UN+" glides forward to battle "+ATTN+", aloft tentacles of "+BOLD+"Darkness..."+NORM+"\n");
			break;
			case 14:
			tell_room(ENVU,
			UN+" walks calmly amid the chaos of the moment, battling "+ATTN+" to the death.\n");
			break;
			case 13:
			tell_room(ENVU,
			UN+" points at "+ATTN+" and sends tendrils of "+BOLD+"Dark Matter"+NORM+"\nleaping forward.\n");
			break;
			case 12:
			tell_room(ENVU,
			UN+" is launched into the air by "+UP+" tentacles and lands near "+ATTN+".\n");
			break;
			case 11:
			tell_room(ENVU,
			"Tentacles lash out from "+UN+" as "+UPR+" stares at "+ATTN+".\n");
			break;
			case 10:
			tell_room(ENVU,
			UN+" raises "+UP+" hands to the sky as "+BOLD+"Dark Matter"+NORM+" leaps from his\nback toward "+ATTN+".\n");
			case 9:
			tell_room(ENVU,
			UN+" clenches "+UP+" fists as "+UPR+" commands "+BOLD+"Dark Matter"+NORM+" to lash\nout at "+ATTN+".\n");
			break;
			case 8:
			tell_room(ENVU,
			UN+" rises into the air on "+BOLD+"Dark Matter"+NORM+" tendrils as "+UPR+" glares\nat "+ATTN+".\n");
			break;
			case 7:
			tell_room(ENVU,
			UN+"'s tentacles lash out, whistling through the air...\n");
			break;
			case 6:
			tell_room(ENVU,
			UN+" glides forward on "+BOLD+"Dark Matter"+NORM+" wings.\n");
			break;
			case 5:
			tell_room(ENVU,
			UN+"'s "+BOLD+"Dark Matter Wings"+NORM+" unfurl and separate into tendrils of\ncharging death.\n");
			break;
			case 4:
			tell_room(ENVU,
			"You feel a chill as "+UN+"'s eyes "+COLOR+"blaze"+NORM+" with power.\n", ({USER}));
			break;
			case 3:
			tell_room(ENVU,
			UN+" dances with the rhythm of "+UP+BOLD+" dark tendrils"+NORM+" as "+UPR+" moves in\non "+ATTN+".\n");
			break;
			case 2:
			tell_room(ENVU,
			UN+"'s "+BOLD+"Dark Matter Tentacles"+NORM+" fill the room with chaos and motion.\n");
			break;
			case 1:
			tell_room(ENVU,
			"You watch as "+UN+" calmly glides forward on "+BOLD+"Dark Matter"+NORM+" Tendrils...\n", ({USER}));
			break;
		}
	}
	yah = 0;
	
	/*  Increasing chance to hit with the tentacles
	as each is done.  Think of it like honing in on a target by shot tracing.         */
	for(x = 0; x < boo; x++){
		if(x < 3){         /* Starting out bad for the first 3, 21 to 26% hit chance */
			if(random(100) < combat + USER->query_attrib("wil")){
				tot += random(combat) + 3;
				yah += 1;
			}
		}
		else if(x < 6){  /*  Next 3 have a 22 to 32% chance of hitting     */
			if(random(100) < combat * 2 + USER->query_attrib("wil")){
				tot += random(combat) + 3;
				yah += 1;
			}
		}
		else if(x < 9){  /*  Next 3 -  43 to 58% chance to hit */
			if(random(100) < combat * 3 + USER->query_attrib("wil") * 2){
				tot += random(combat) + 3;
				yah += 1;
			}
		}
		else{    /* Last ones - 46 to 76% chance to hit */
			if(random(100) < combat * 6 + USER->query_attrib("wil") * 2){
				tot += random(combat) + 3;
				yah += 1;
			}
		}
	}
	switch(random(5) + 1){
		case 5: how = "Impale"; how2 = "Impaled"; break;
		case 4: how = "Strike"; how2 = "Struck"; break;
		case 3: how = "Hit"; how2 = "Hit"; break;
		case 2: how = "Devastate"; how2 = "Devastated"; break;
		case 1: how = "Slice"; how2 = "Sliced"; break;
	}
	
	if(!yah) return tot;
	else if(yah < 2){
		tell_object(USER,
			COLOR+"["+NORM+BOLD+"Tentacles"+NORM+COLOR+"]"+NORM+""+
		"  A tentacle lashes out and "+how+"s "+ATTN+"!\n");
		tell_object(ATT,
		"You are "+how2+" by a "+BOLD+"Dark Matter"+NORM+" Tentacle from "+UN+"!\n");
	}
	else{
		tell_object(USER,
			COLOR+"["+NORM+BOLD+"Tentacles"+NORM+COLOR+"]"+NORM+""+
		"  "+get_number(yah)+" "+BOLD+"Dark Matter Tentacles"+NORM+" lash out and "+how+" "+ATTN+"!\n");
		tell_object(ATT,
		"You are "+how2+" by "+get_number(yah)+" "+BOLD+"Dark Matter"+NORM+" Tentacles from "+UN+"!\n");
	}
	if(hypermode) tot += 15;
	return tot;
}


defense_tentacles(){
	int boo,yah,i;
	string h,hh,hhh,h2,hh2;
	
	boo = total_tentacles("defend");
	if(ATT)
	if(boo > 3 && random(100) < 40){
		switch(random(10) + 1){
			case 10:
			tell_room(ENVU,
			UN+"'s Tentacles whip about furiously to defend their owner!\n");
			break;
			case 9:
			tell_room(ENVU,
			UN+"'s "+BOLD+"Dark Matter"+NORM+" tentacles wrap around "+ATTN+"'s arms and legs and wrestle\nwith them!\n");
			break;
			case 8:
			tell_room(ENVU,
			UN+"'s tentacles push "+ATTN+" back.\n");
			break;
			case 7:
			tell_room(ENVU,
			UN+"'s "+BOLD+"Dark Matter"+NORM+" tendrils fly forward and partially deflect the incoming attack\nfrom "+ATTN+"!\n");
			break;
			case 6:
			tell_room(ENVU,
			UN+" leaps to the side as tendrils partially deflect the incoming attack!\n");
			break;
			case 5:
			tell_room(ENVU,
			UN+" stands calm amid a dancing storm of "+BOLD+"Dark Matter"+NORM+" Tentacles.\n");
			break;
			case 4:
			tell_room(ENVU,
			UN+" rises into the air atop tentacles of "+BOLD+"Dark Matter..."+NORM+"\n");
			break;
			case 3:
			tell_room(ENVU,
			UN+" points at "+ATTN+".  Tentacles lash out and sidetrack "+ATTN+"'s attack!\n");
			break;
			case 2:
			tell_room(ENVU,
			UN+"'s tentacles confuse "+ATTN+" with their hypnotic defensive dance.\n");
			break;
			case 1:
			tell_room(ENVU,
			UN+" sneers at "+ATTN+"'s feeble attack and commands "+UP+" tendrils forward.\n");
			break;
		}
	}
	for(i = 0; i < boo; i ++){
		if(i < 2){
			if(random(100) < control + USER->query_attrib("wil")){
				yah += 2;
			}
		}
		else if(i < 5){
			if(random(100) < (control *2) + USER->query_attrib("wil")){
				yah += 2;
			}
		}
		else if(i < 8){
			if(random(100) < (control * 3) + USER->query_attrib("wil")){
				yah += 2;
			}
		}
		if(i < 11){
			if(random(100) < (control * 3) + USER->query_attrib("wil") * 2){
				yah += 2;
			}
		}
	}
	
	switch(random(4) + 1){
		case 4: h = "lash out";  h2 = "lashes out"; break;
		case 3: h = "whip outward"; h2 = "whips outward"; break;
		case 2: h = "fly out"; h2 = "flies out"; break;
		case 1: h = "circle out"; h2 = "circles out"; break;
	}
	switch(random(4) + 1){
		case 4: hh = "wrap around"; hh2 = "wraps around"; break;
		case 3: hh = "jar"; hh2 = "jars"; break;
		case 2: hh = "whip about"; hh2 = "whips about"; break;
		case 1: hh = "encircle"; hh2 = "encircles"; break;
	}
	switch(random(4) + 1){
		case 4: hhh = ", nearly bringing them to the ground!"; break;
		case 3: hhh = ", confusing them."; break;
		case 2: hhh = "."; break;
		case 1: hhh = " tripping them up."; break;
	}
	
	if(yah < 1) return 0;
	else if(yah < 2){
		if(ATT)
      tell_object(USER,
			BOLD+"["+NORM+COLOR+"Defend"+NORM+BOLD+"] "+NORM+""+
		" A "+BOLD+"Dark Matter"+NORM+" Tentacle "+h2+" and "+hh2+" "+ATTN+""+hhh+"\n");
      if(ATT)
		tell_room(USER,
		BOLD+UN+"'s tentacle "+h2+" and "+hh2+" "+ATTN+""+hhh+NORM+"\n",({USER}));
	}
	else{
      if(ATT)
		tell_object(USER,
			BOLD+"["+NORM+COLOR+"Defend"+NORM+BOLD+"] "+NORM+""+
		" "+capitalize(get_number(yah))+" Dark Matter Tentacles "+h+" and "+hh+" "+ATTN+""+hhh+"\n");
      if(ATT)
		tell_room(USER,
		BOLD+UN+"'s tentacles "+h+" and "+hh+" "+ATTN+""+hhh+NORM+"\n",({USER}));
	}
	return yah;
}


get_number(int i){
	string *numero;
	numero = ({ "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
			"Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
	"Twenty", "Twenty-One", "Twenty-Two", "Twenty-Three", "Twenty-Four", "Twenty-Five",
   "Twenty-Six", "Twenty-Seven", "Twenty-Eight", "Twenty-Nine", "Thirty", });
	return numero[i];
}



/* rewritten by verte 6.23.01 */
total_ar()
{
    object ob;
    int subtract;
    ob = first_inventory(USER);
    while(ob)
    {
      if(ob->is_armor())
      {
        if(ob->query_type() == "misc" || ob->query_type() == "boots" ||
           ob->query_type() == "ring" || ob->query_type() == "helmet" ||
           ob->query_type() == "shield" || ob->query_type() == "amulet")
        { 
          if(ob->query_worn()) subtract += 1;
        }
        else if(ob->query_type() == "armor" && ob->query_worn())
          subtract += 2;
      }
      ob = next_inventory(ob);
    }
    return subtract;
}


check_attackers(){
	object ob;
	ob = first_inventory(environment(USER));
	while(ob) {
		if(ob->query_attack() == USER){ return 1; }
		ob = next_inventory(ob);
	}
	return 0;
}
