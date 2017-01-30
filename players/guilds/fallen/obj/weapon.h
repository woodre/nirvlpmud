/* This Code is directly adapted from the Power Ranger Guild Weapon.
   Special Thanks to Beck for supplying it. */
#include "/sys/ansi.h"

static status wielded;
static object wielded_by;
static int broke;
static int eff_wc;
static int misses,hits;
static int save_flag,class_of_weapon;
static object hit_func;
static string hit_func_fn;
static string type;
static string *message_hit;
weapon_class(){   return class_of_weapon;  }
hit(attacker){
    if (hit_func)
	return call_other(hit_func,"weapon_hit",attacker);
    return 0;
}
set_class(c){ class_of_weapon = c; }
weapon_breaks(){
    if(broke) return 1;
    return 1;
}
count_misses(){
    misses += 1;
    return 1;
}
count_hit_made(w){
    hits += 1;
    eff_wc=((hits-1)*eff_wc + w)/hits;
    return 1;
}
query_broke(){  return broke; }
query_pro_weapon(){ return 1; }
query_wear(){   return 0; }
add_wear(arg){
    misses = 0;
    hits = 0;
}
fix_weapon(){
    if(!broke) {
	return 0;
    }
    broke = 0;
    return 1;
}
re_break(){ 
    broke = 1;
    return 1;
}

set_hit_func(ob){
    string junka,junkk;
    hit_func = ob;
    if(sscanf(file_name(ob),"%s#%s",junka,junkk) == 2)
	hit_func_fn = "/"+junka;
    else
	hit_func_fn = "/"+file_name(ob);
}

query_hit_func(){ return hit_func; }


wfmsgs(object n){
    int x;
    string y, f;
    x = random(8);
    if(!n) return;
    switch(x)
    {
    case 0:
	y = "Shadows cut through the room!";
	break;
    case 1:
	y = "Shadows slash through the air!";
	break;
    case 2:
	y = "Shadows fly through the weakened "+n->query_name()+"!";
	break;
    case 3:
	y = "Shadows lash across the room into "+n->query_name()+"!";
	break;
    case 4:
	y = "Shadows annihilate the weakened "+n->query_name()+"!";
	break;
    case 5:
	y = "Shadows whip into the weakened "+n->query_name()+"!";
	break;
    case 6:
	y = "Shadows pour through the room!";
	break;
    case 7:
	y = "A flurry of shadows pummels the weakened "+n->query_name()+"!";
	break;
    }
    f = "\n\t"+y+"\n\n"+NORM;
    if(!random(2))
    {
	tell_object(USER, BOLD+BLK+f);
	tell_room(environment(USER), BOLD+BLK+f, ({ USER }));
    }
    else
    {
	tell_object(USER, HIW+f);
	tell_room(environment(USER), HIW+f, ({ USER }));
    }
}

vigor_msgs(){
    int r;
    string msg1,msg2, nm, nm2, blah, nmp, nmo;
    nm2 = (string)NAME;
    nmo = (string)USER->query_possessive();  /*  his her  */
    nmp = (string)USER->query_objective();   /*  him her  */
    blah = (string)USER->query_pronoun();    /*  he she  */
    nm = capitalize(nm2);
    r = random(11);
    switch(r)
    {
    case 0:
	msg1 = nm+" dodges swiftly as shadows trail behind "+nmp+".\n";
	msg2 = "You dodge swiftly as shadows trail behind you.\n";
	break;
    case 1:
	msg1 = "The shadows shift suddenly as "+nm+" darts quickly forward.\n";
	msg2 = "The shadows shift suddenly as you dart quickly forward.\n";
	break;
    case 2:
	msg1 = nm+" moves with extreme vigor.\n";
	msg2 = "You move with extreme vigor.\n";
	break;
    case 3:
	msg1 = nm+"'s movements seem driven by the shadows.\n";
	msg2 = "Your movements seem driven by the shadows.\n";
	break;
    case 4:
	msg1 = nm+" moves with the strength of the shadows behind "+nmp+".\n";
	msg2 = "You move with the strength of the shadows behind you.\n";
	break;
    case 5:
	msg1 = "Light and darkness seem to twist as "+nm+" moves.\n";
	msg2 = "Light and darkness seem to twist as you move.\n";
	break;
    case 6:
	msg1 = "Light and darkness seem to bend as "+nm+" moves.\n";
	msg2 = "Light and darkness seem to bend as you move.\n";
	break;
    case 7:
	msg1 = nm+"'s movements seem to distort the light and darkness.\n";
	msg2 = "Your movements seem to distort the light and darkness.\n";
	break;
    case 8:
	msg1 = "The strength of the shadows pulses through "+nm+".\n";
	msg2 = "The strength of the shadows pulses through your body.\n";
	break;
    case 9:
	msg1 = nm+" seems driven by the shadows around "+nmp+".\n";
	msg2 = "Shadows drive you body to fight harder.\n";
	break;
    case 10:
	msg1 = "Shadows trail behind "+nm+" as "+blah+" moves.\n";
	msg2 = "Shadows trail behind you as you move.\n";
	break;
    }

    if(!random(2))
    {
	tell_room(environment(USER), HIW+msg1+NORM, ({ USER }));
	tell_object(USER, HIW+msg2+NORM);
    }

}

proficiency_hit(ob){
    int one,two,three,four, r, base;
    string nm, nm2, msg1, msg2, nmy, nmy2, nmo, nmp,blah;
    object atk;

    if(endurance < 0)
	USER->add_spell_point(-1);

    /* Focus ability increases wc.  */
    if(duration)
    {
	atk = USER->query_attack();
	base = 4+random(focus)+random(2);
	if(atk)
	{
	    if(present("weaken_counter", atk))  /* weaken */
	    {
		base += 4;
		if(vigor)             /* vigor + weaken */
		    base += 1;
	    }
	    if(atk->ringed())      /* web */
		base += 3+random(4);
	}

	if(!random(2))
	{
	    message_hit=({
	      BOLD+BLK+"annihilated"+NORM, " with a shadow blast",
	      HIW+"destroyed"+NORM, " with shadow force",
	      "smashed", " with fists of shadows",
	      "crushed", " with fists of shadows",
	      "blasted", " with the shadows",
	      "hit", " with a shadow strike",
	      "grazed", " with a shadow blast",
	      "grazed", "",
	    });
	}
	else {
	    message_hit=({
	      BOLD+BLK+"annihilated"+NORM, " with an explosion of shadows",
	      HIW+"obliterated"+NORM, " with a torrent of shadows",
	      "focused the shadows against", "",
	      "lashed shadows into", "",
	      "whipped", " with a flail of shadows",
	      "struck", " with a shadow blast",
	      "hit", " with a shadow blast",
	      "grazed", "",
	    });
	}
    }
    if(duration <= 0)
    {
	message_hit=({
	  "massacre"," to small fragments",
	  "massacre"," to small fragments",
	  "smashed"," with a bone crushing sound",
	  "hit"," very hard",
	  "hit"," hard",
	  "hit","",
	  "grazed","",
	  "tickled"," in the stomach",
	});
	base = 3;
    }

    if(light_check() || endurance <= 0 || duration <= 0) return base;

    one = random(4);
    two = random(7);
    three = random(10);
    four = random(14);
    nm2 = (string)NAME;
    nmo = (string)USER->query_possessive();  /*  his her  */
    nmp = (string)USER->query_objective();   /*  him her  */
    blah = (string)USER->query_pronoun();    /*  he she  */
    nm = capitalize(nm2);
    if(atk)
    {
	nmy = (string)atk->query_name();
	nmy2 = (string)atk->query_objective();
    }
    else
    {
	nmy = nmo+" enemy";
	nm2 = "him";
    }

    /* low armor increases fighting ability and sp regen */
    if(random((int)USER->query_ac()) == 0)
    {
	USER->add_spell_point(1);
	base += 2;
    }

    if(vigor)                     /* vigor */
    {
	vigor_msgs();
	base += vigor_bonus;
    }

    if(!one)
    {
	r = random(13);
	switch(r)
	{
	case 0:
	    msg1 = "Dark shadows swirl around "+nm+".\n";
	    msg2 = "Dark shadows swirl around you.\n";
	    break;
	case 1:
	    msg1 = "Dark shadows rise up around "+nm+".\n";
	    msg2 = "Dark shadows rise up around you.\n";
	    break;
	case 2:
	    msg1 = "Dark shadows flit across the room.\n";
	    msg2 = msg1;
	    break;
	case 3:
	    msg1 = "Dark shadows dance across "+nm+".\n";
	    msg2 = "Dark shadows dance across you.\n";
	    break;
	case 4:
	    msg1 = nm+" beckons as the shadows come alive.\n";
	    msg2 = "You beckon as the shadows come alive.\n";
	    break;
	case 5:
	    msg1 = nm+" waves a hand as shadows rise up.\n";
	    msg2 = "You wave a hand as shadows rise up.\n";
	    break;
	case 6:
	    msg1 = "A dark shadow drifts through the room.\n";
	    msg2 = msg1;
	    break;
	case 7:
	    msg1 = nm+" grins as shadows rise up around "+nmp+".\n";
	    msg2 = "You grin as shadows rise up around you.\n";
	    break;
	case 8:
	    msg1 = nm+" casts a wave of shadows over the room.\n";
	    msg2 = "You cast a wave of shadows over the room.\n";
	    break;
	case 9:
	    msg1 = "Light and darkness swirl around "+nm+".\n";
	    msg2 = "Light and darkness swirl around you.\n";
	    break;
	case 10:
	    msg1 = nm+" beckons as light and darkness envelop "+nmp+".\n";
	    msg2 = "You beckon as light and darkness envelop you.\n";
	    break;
	case 11:
	    msg1 = "Light and darkness cascade over "+nm+".\n";
	    msg2 = "Light and darkness cascade over you.\n";
	    break;
	case 12:
	    msg1 = "Shadows pulsate over "+nm+"'s body.\n";
	    msg2 = "Shadows pulsate over your body.\n";
	    break;
	}
	if(!random(2))
	{
	    tell_room(environment(USER), BOLD+BLK+msg1+NORM, ({ USER }));
	    tell_object(USER, BOLD+BLK+msg2+NORM);
	}
	else
	{
	    tell_room(environment(USER), msg1, ({ USER }));
	    tell_object(USER, msg2);
	}
	base += 6;
    }
    else if(!two && (random(100000+guild_exp) < guild_exp))
    {
	r = random(7);
	switch(r)
	{
	case 0:
	    msg1 = nm+" waves a hand...\n"+
	    "The shadows curl up around "+nmp+".\n"; 
	    msg2 = "You wave a hand as the shadows curl up around you.\n";
	    break;
	case 1:
	    msg1 = nm+" bows "+nmo+" head and whispers softly...\n"+
	    "The shadows converge on "+nmy+", weakening "+nmy2+".\n"; 
	    msg2 = "You bow your head and whisper softly...\n"+
	    "The shadows converge on "+nmy+", weakening "+nmy2+".\n"; 
	    break;
	case 2:
	    msg1 = BOLD+BLK+"The shadows pulse violently.\n"+NORM;
	    msg2 = msg1;
	    break;
	case 3:
	    msg1 = BOLD+BLK+nm+" spins about as the shadows encircle "+nmp+".\n"+NORM;
	    msg2 = BOLD+BLK+"You spin about as the shadows encircle you.\n"+NORM;
	    break;
	case 4:
	    msg1 = BOLD+BLK+"Shadows wrap around "+nm+"'s hands.\n"+NORM;
	    msg2 = BOLD+BLK+"Shadows wrap around your hands.\n"+NORM;
	    break;
	case 5:
	    msg1 = nm+" is lifted up by the shadows as "+blah+" fights.\n";
	    msg2 = "As you fight you are lifted up by the shadows.\n";
	    break;
	case 6:
	    msg1 = BOLD+BLK+nm+" cackles as the shadows encircle "+nmp+".\n"+NORM;
	    msg2 = BOLD+BLK+"You cackle as the shadows encircle you.\n"+NORM;
	    break;
	}
	tell_room(environment(USER), msg1, ({ USER }));
	tell_object(USER, msg2);
	base += 14;
    }
    else if(!three && (random(2000000+guild_exp) < guild_exp))
    {
	r = random(5);
	switch(r)
	{
	case 0:
	    msg1 = nm+" bends "+nmo+" head and whispers a soft chant...\n"+
	    "A torrent of shadows pours through the room.\n";
	    msg2 = "You bend your head and whisper a soft chant...\n"+
	    "A torrent of shadows pours through the room.\n";
	    USER->add_spell_point(4);
	    base += 2;
	    tell_room(environment(USER), msg1, ({ USER }));
	    tell_object(USER, msg2);
	    break;
	case 1:
	    msg1 = nm+" bends "+nmo+" head and whispers a soft chant...\n"+
	    nmy+" is knocked back by a wave of dark shadows!\n";
	    msg2 = "You bend your head and whisper a soft chant...\n"+
	    nmy+" is knocked back by a wave of dark shadows!\n";
	    tell_room(environment(USER), msg1, ({ USER }));
	    tell_object(USER, msg2);
	    base += 16;
	    break;
	case 2:
	    msg1 = nm+" bends "+nmo+" head and whispers a soft chant...\n"+
	    nm+" is wrapped in a dark veil of shadows.\n";
	    msg2 = "You bend your head and whisper a soft chant...\n"+
	    "You are wrapped in a dark veil of shadows.\n";
	    USER->add_spell_point(6);
	    base += 2;
	    tell_room(environment(USER), msg1, ({ USER }));
	    tell_object(USER, msg2);
	    break;
	case 3:
	    msg1 = nm+" bends "+nmo+" head and whispers a soft chant...\n"+
	    "The shadows spin wildly about the room!\n";
	    msg2 = "You bend your head and whisper a soft chant...\n"+
	    "The shadows spin wildly about the room!\n";
	    tell_room(environment(USER), msg1, ({ USER }));
	    tell_object(USER, msg2);
	    base += 12;
	    break;
	case 4:
	    msg1 = BOLD+BLK+nm+
	    " is wrapped in shadows as anger fills "+nmp+".\n"+NORM;
	    msg2 = BOLD+BLK+
	    "You are wrapped in shadows as anger fills you.\n"+NORM;
	    USER->add_spell_point(4);
	    base += 2;
	    tell_room(environment(USER), msg1, ({ USER }));
	    tell_object(USER, msg2);
	    break;
	}
    }
    else if(!four && (random(3000000+guild_exp) < guild_exp))
    {
	if(!random(2))
	    USER->add_spell_point(10+random(8));
	else 
	{
	    if(atk && atk->query_hp() > 19)
		atk->hit_player(10+random(11));
	    else
		base += 16;
	}
    }
    if(present("weaken_counter", atk) && (!one || !two || !three || !four &&
	base > 20) && !random(3))
	wfmsgs(atk);
    if(USER->query_real_name() == "zeustest")
	tell_object(find_player("zeus"), "base: "+base+", ");
    return base;
}

query_message_hit(tmp) {
    string *mess;
    if(tmp > 35)
	mess = ({message_hit[1],message_hit[0]});
    else if(tmp > 26)
	mess = ({message_hit[3],message_hit[2]});
    else if(tmp > 19)
	mess = ({message_hit[5],message_hit[4]});
    else if(tmp > 13)
	mess = ({message_hit[7],message_hit[6]});
    else if(tmp > 7)
	mess = ({message_hit[9],message_hit[8]});
    else if(tmp > 4)
	mess = ({message_hit[11],message_hit[10]});
    else if(tmp > 1)
	mess = ({message_hit[13],message_hit[12]});
    else if(tmp == 1)
	mess = ({message_hit[15],message_hit[14]});
    return mess;
}

