#include <ansi.h>
#include "/players/mishtar/defs.h"

inherit "/players/vertebraker/closed/std/room";

int shield;
int cloak;
int locked;

reset (arg)
{
	if(!present("notice"))
{
      move_object(clone_object("players/llew/Other/misc/obituary.c"), this_object());
}
	if(arg) return;
	set_light(1);
	set_long("\n"+HIK+"An Obsidian Dragons Lair"+NORM+
		"\nThis is a large, well trampled clearing encircled by tall, twisted\n"+
		"trees and small, leafless bushes with sharp barbed needles.  The\n"+
		"wind rustles softly through the underbrush creating a soft murmur\n"+
		"of torment and pain as it brushes past withered tree limbs.  In a\n"+
		"corner of the clearing is a small, dark pool surrounded by smooth\n"+
		"rocks.  An eerie feeling of being watched pervades the clearing as\n"+
		"a pair of large glowing orbs appear in the darkness of the shadows.\n"+
		"A soft hiss of scales slithering across dry leaves can barely be\n"+
		"heard over the forests tormented screams.  Moments later, a large\n"+
		"obsidian dragon slowly fades into view in the middle of the clearing.\n");

	add_item("light","The small motes of light are just enough to barely illuminate \n"+
		"the clearing");
	add_item("orbs","A pair of golden orbs inset with sparkling onyx irises study the clearing");
	add_item("shadows","The shadows almost seem alive as they dance across the clearing, \n"+
		"absorbing what little light sprinkles down through the trees");
	add_item("trees","These once majestic trees have withered and died becoming twisted, \n"+
		"leafless grey skeletons that moan in torment as the wind blows through \n"+
		"their broken limbs");
	add_item("bushes","The leaves have withered and fallen away from these bushes \n"+
		"leaving behind barbed branches stained a deep crimson that seem to grasp \n"+
		"and claw at anything that comes within their reach");
	add_item("pool","The pool is filled with inky black ichor that seems to absorb light \n"+
		"and radiates an almost palable evil");
	add_item("rocks","These smooth obsidian rocks seem to have been crudely carved to \n"+
			"meld as an interlocking ring around the pool");
	add_item("dragon","The great bulk of the ancient dragon almost consumes the whole \n"+
		"clearing in which it resides.  Its great wings stretch lazily as \n"+
		"it scans the surroundings with its large glowing yellow eyes. \n"+
		"The few motes of light that sprinkle down through the dense canopy \n"+
		"sparkle and shimmer across the great dragon's irridescent black \n"+
		"scales");

	add_smell("main","The scent of rotting leaves, moldy bark, and a hint of brimstone \n"+
		"permeate the clearing");
	add_smell("pool","The pool smells of stagnant and fetid swamp water and mold");
	add_smell("trees","The twisted, dying trees smell of moldy bark and slow decay");
	add_smell("bushes","The scent of decay and mold hangs about the bushes mixed \n"+
		"the sweet smell of long dried blood");

	add_touch("pool","The pool gurgles and bubbles and burns like acid");
	add_touch("rocks","The rocks are smooth and slick with a soft black mold that is fed \n"+
		"by the pool");
	add_touch("trees","The decayed bark crumbles to power and the insects beneath scramble \n"+
		"for cover farther up the tree's trunk");

	add_listen("wind","The soft tormented moan of the trees can be heard on the wind");
	add_listen("main","The clearing is devoid of sound except for the tormented moan of \n"+
		"trees caused by the breeze from the dragon's breath and shifting \n"+
		"wings as it slumbers");

	add_exit("/room/church","church");
	add_exit("/room/post","post");
	add_exit("/players/saber/ryllian/portal","portal");
	add_exit("/room/adv_guild","advance");
	add_exit("/players/mishtar/areas/erethor/room/egate","erethor");
}

init()
{
	::init();
	if(TPRN != OWNER && shield == 1)
{
	write("A large, ancient "+BLU+"azure"+NORM+" dragon sweeps\n");
    write("you up in its claws and with a great beat of its wings, \n");
	write("carries you elsewhere.\n");
    TP->move_player("room/church");
}
	add_action("do_exits","church");
	add_action("do_exits","post");
	add_action("do_exits","portal");
	add_action("do_exits","advance");
	add_action("do_exits","erethor");
  
	if(TPRN==OWNER)
{
    add_action("shields","shields");
    add_action("cloak","cloak");
    add_action("locks","locks");
    add_action("scry","scry");
    add_action("gaze","gaze"); 
    add_action("invite","invite");
	add_action("kiss_off","kissoff");
}
}
short()
{
	string str;
	if(cloak)
{
    switch(random(6))
{
      case 0: str=GRN+"Daboria Swamp"+NORM; break;
      case 1: str=YEL+"Kaisuruvi Desert"+NORM; break;
      case 2: str=GRN+"Shalamori Forest"+NORM; break;
      case 3: str=HIK+"Trevaskar Mountains"+NORM; break;
      case 4: str=YEL+"Plains of Verogeth"+NORM; break;
	  case 5: str=HIK+"Cortarvak Caverns"+NORM; break;
}
	return str;
}
	else
{
    return str=HIK+"An Obsidian Dragons Lair"+NORM;
}
}

realm()
{
  if(locked) return "NT";
}

shields()
{
	if(TPRN!=OWNER) return 0;
	if(shield)
{
    write("You deactivate the shields.\n");
    shield=0;
    return 1;
}
	else
{
    write("You activate the shields.\n");
    shield=1;
    return 1;
}
}

cloak()
{
	if(TPRN!=OWNER) return 0;
	if(cloak)
{
    write("You deactivate the cloak.\n");
    cloak=0;
    return 1;
}
	else
{
    write("You activate the cloak.\n");
    cloak=1;
    return 1;
}
}

locks()
{
	if(TPRN!=OWNER) return 0;
	if(locked)
{
    write("You unlock the exits.\n");
    locked=0;
    return 1;
}
	else
{
    write("You lock the exits.\n");
    locked=1;
    return 1;
}
}

scry(string str)
{
	object person,ob,special;
	if(!str)
{
    write("Usage: scry <living>.\n");
    return 1;
}
	person=find_player(str);
	if(!person)
	    person=find_living(str);
	if(!person)
{
    write(str+" can not be found.\n");
    return 1;
}
	say(TPN+" gazes into the pool.\n");
	write("You gaze into the pool and see: \n");
	person->long();
	special=first_inventory(person);
	while(special)
{
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str)
	    write(extra_str+".\n");
    special=next_inventory(special);
}
	write(capitalize(person->query_pronoun())+" is carrying: \n");
	ob = first_inventory(person);
	while (ob)
{
    string sh;
    sh = call_other(ob, "short");
    if (sh)
	    write(sh + ".\n");
	    ob = next_inventory(ob);
}
  return 1;
}

gaze(string str)
{
	object person;
	object ob;
	if(!str)
{
    write("Usage: gaze <living>\n");
    return 1;
}
	person=find_player(str);
	if(!person)
	    person=find_living(str);
	if(!person)
{
    write(str+" can not be found.\n");
    return 1;
}
	say(TPN+" gazes into the pool.\n");
	write("You gaze into the pool and see: \n");
	environment(person)->long();
	ob = first_inventory(environment(person));
	while (ob)
{
    string sh;
    sh=ob->short();
    if(sh)
		write(sh + ".\n");
		ob=next_inventory(ob);
}
  return 1;
}

invite(str)
{
	object person,invite;
	if(!str)
{
    write("Usage: invite <living>\n");
    return 1;
}
	person=find_player(str);
	if(!person)
		person=find_living(str);
	if(!person)
{
    write(str+" can not be found.\n");
    return 1;
}
	if(shield) shields();
	write("You send a huge "+BLU+"azure"+NORM+" dragon after "+capitalize(str)+".\n");
	say("Mishtar whispers softly to a huge "+BLU+"azure"+NORM+" dragon and it flies away.\n");
	invite = "/players/mishtar/items/dinvite.c";
	move_object(invite,person);
	command("ansreq",person);
    return 1;
}

/* Exits */
do_exits(string verb)
{
	string aroom,dest;
	if(locked)
{
    write("A threatening hiss from the shadows prevents you from leaving.\n");
    say(TPN+" is frozen in place by a threatening hiss from the shadows.\n");
    return 1;
}
	if(verb == "church"){ aroom = "/room/church"; dest = "Church"; }
	else if(verb == "post"){ aroom = "/room/post"; dest = "Post Office"; }
	else if(verb == "portal"){ aroom = "/players/saber/ryllian/portal"; dest = "Chamber of Portals";}
	else if(verb == "advance"){ aroom = "/room/adv_guild"; dest = "Adventurer's Guild"; }
	else if(verb == "erethor"){ aroom = "/players/mishtar/areas/erethor/room/egate.c"; dest = "Erethor"; }
	else { write("Where did you want to go?\n"); }

	tell_object(TP,"You hop on the back of an "+GRN+"emerald "+NORM+"dragon and fly to the "+dest+".\n");
	say(TPN+" hops on the back of an "+GRN+"emerald "+NORM+"dragon and flies to the "+dest+".\n");
	move_object(TP,aroom);
	say(TPN+" arrives on the back of an "+GRN+"emerald "+NORM+"dragon.\n");
	command("look",TP);	
	return 1;
}
/*An eject command for workrooms by Mishtar*/
int kiss_off(string str){
	string aroom, name;
	object who;
	aroom = "/room/vill_green.c";
	if(!str){ write("Kick out who?\n"); return 1;}
	if(!present(str, ENVTP)){ write(CPS+" is not in your room.\n"); return 1;}
	if(sscanf(str,"%s",name));
	who = find_player(name);
	if(str != OWNER){
		write("\nA giant "+BLU+"azure"+NORM+" dragon swoops down, captures "+FPN+" in its claws "+
			"and carries them away!\nYou kick "+FPN+" out of your room!\n");
		tell_room(aroom,"\nA giant "+BLU+"azure"+NORM+" dragon flies by and drops "+FPN+" out of"+
			" the sky from a great height!\n");
		move_object(who,aroom);
		tell_object(who, "\nA giant "+BLU+"azure"+NORM+" dragon swoops down, captures you in its"+
			" claws and carries you away!\n"+TPN+" has kicked you out of "+TPP+" lair!\n"+
			"You have been moved to "+(string)environment(who)->short()+".\n");
		say("\nA giant "+BLU+"azure"+NORM+" dragon swoops down, captures "+FPN+" in its claws "+
			"and carries them away!\n"+TPN+" has kicked "+FPN+" out of "+TPP+" room!\n");
		return 1;}
	}