/*   guth10.c    - contains the blacksmith  */

inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

#define COST1 800		/*  wc < 17  */
#define COST2 800		/*  wc 17, 18  */
#define COST3 800		/*  wc > 18  */
#define COST4 500		/*  cost to repair */

int teleport, sales;
object wep, me;

reset(arg){

	 teleport = 0;  if(random(TFL_TLP)) teleport = 1;

     if(!present("gurther")) 
       MO(CO("/players/zeus/realm/NPC/g-blacksmith.c"), TO); 

     if(arg) return;
  sales = 0;
  short_desc="The Fallen Lands";
  long_desc=
"The forest is very open here, allowing the sun to shine down on the\n"+
"ground.  Some bushes are growing sparaticly around the area.  To the\n"+
"east the forest gets much thicker and darker.  A large anvil is sitting\n"+
"next to a large hole, in which a fire is burning.  A wooden sign has\n"+
"been posted next to the anvil.  A path leads east into the forest.\n";
  set_light(1);
  items=({
	  "path",
"A path begins to the east which leads into the forest",
	  "forest",
"The forest is very open here, allowing sunlight to touch every part of it",
	  "sun",
"The golden sun is shining brightly in the sky",
	  "ground",
"The ground is covered in lush green grass that is growing very well.\n"+
"The area is quite flat",
	  "grass",
"Lush green grass is thriving in this part of the forest",
	  "bushes",
"Various plain green bushes are growing around the area",
	  "anvil",
"It is a large metal iron sitting on the grass.  It looks incredibly\n"+
"heavy.  It has numerous black, burnt spots on it",
	  "hole",
"It is a wide hole dug out of the ground.  A strong fire is burning in it",
	  "fire",
"The fire in the hole is burning very strongly.  The flames flicker up\n"+
"into the sky",
	  "sign",
"The wooden sign is poking out of the forest floor",
  });
  dest_dir=({
	 "/players/zeus/realm/taus/guth9.c", "west",
  });
}


void init(){
  ::init();
    add_action("w_dir", "west");
    add_action("e_dir", "east");
    add_action("e_hidden_dir", "east");
    add_action("read_cmd", "read");
    add_action("sharpen_cmd", "sharpen");
    add_action("repair_cmd", "repair");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }

e_hidden_dir(){
  TP->move_player("east#/players/zeus/realm/taus/guth18.c");
  return 1;
}


status read_cmd(string str){
	if(!str) return 0;
	if(str == "sign"){
		write("Welcome to the blacksmiths...\n\n"+
"Weapon sharpening:\t"+COST1+" coins\n"+
"Weapon repair:\t\t500 coins\n\n"+
"NOTE:   Unwield the weapon first.\n\n");
		say(TP->QN+" reads the sign.\n");
		return 1;
	}
	else return 0;
	return 1;
}


fix(){
	int heh;
	heh = random(3);
	TR(environment(me),
		"The blacksmith takes the "+wep->QN+" from "+me->QN+"...\n", ({me}));
	tell_object(me,
		"The blacksmith takes the "+wep->QN+" from you...\n");
	switch(heh){
	case 0:
	TR(environment(me),
		"Using his tools he makes it just like new.\n", ({me}));
	tell_object(me,
		"Using his tools he makes it just like new.\n");
	break;
	case 1:
	TR(environment(me),
		"The blacksmith sharpens the "+wep->QN+" making it good as new.\n", 
		({me}));
	tell_object(me,
		"The blacksmith sharpens the "+wep->QN+" making it good as new.\n"); 
	break;
	case 2:
	TR(environment(me),
		"He quickly works on the "+wep->QN+" until it's just like new.\n", 
		({me}));
	tell_object(me,
		"He quickly works on the "+wep->QN+" until it's just like new.\n"); 
	break;
	}
	TR(environment(me), 
		"\n"+me->QN+" hands the blacksmith some coins.\n", ({ me }));
	wep->set_hits(1);
	wep->set_misses(1);
	sales += 1;
}


status sharpen_cmd(string str){
	me = TP;
	if(!present("blacksmith", environment(me))){
		write("There is nobody here to help you.\n");
		return 1;
	}
	if(!str){
		write("The blacksmith asks: What do you want me to sharpen?\n");
		return 1;
	}
	wep = present(str, me);
	if(!wep){
		write("The blacksmith asks: What do you want me to sharpen?\n");
		return 1;
	}
	if((int)wep->query_broke() == 1){
		write(
	"The blacksmith says: That weapon is broken, I can't sharpen it.\n");
		return 1;
	}
	if((object)me->query_weapon() == wep){
		write("The blacksmith says: You can't be wielding it.\n");
		return 1;
	}
	if((int)wep->weapon_class() < 17){
		if(me->query_money() < COST1){
			write("The blacksmith says:  You don't have enough money!\n");
			return 1;
		}
		TR(environment(me), 
			"\nThe blacksmith says: That's a nice weapon...\n\n");
		fix();
		tell_object(me,
			"\nYou hand the blacksmith "+COST1+" coins.\n");
		me->add_money(-COST1);
		return 1;
	}
	else if((int)wep->weapon_class() > 18){
		if(me->query_money() < COST3){
			write("The blacksmith says:  You don't have enough money!\n");
			return 1;
		}
		TR(environment(me), 
			"\nThe blacksmith says: That's an excellent weapon...\n\n");
		fix();
		tell_object(me,
			"\nYou hand the blacksmith "+COST3+" coins.\n");
		me->add_money(-COST3);
		return 1;
	}
	else if((int)wep->weapon_class() >= 17 && (int)wep->query_class() <= 18){
		if(me->query_money() < COST2){
			write("The blacksmith says:  You don't have enough money!\n");
			return 1;
		}
		TR(environment(me), 
			"\nThe blacksmith says: That's a great weapon...\n\n");
		fix();
		tell_object(me,
			"\nYou hand the blacksmith "+COST2+" coins.\n");
		me->add_money(-COST2);
		return 1;
	}
	else {
		write("The blacksmith asks: What do you want me to sharpen?\n");
		return 1;
	}
	return 1;
}


status repair_cmd(string str){
	me = TP;
	if(!present("blacksmith", environment(me))){
		write("There is nobody here to help you.\n");
		return 1;
	}
	if(!str){
		write("The blacksmith asks: What do you want me to repair?\n");
		return 1;
	}
	wep = present(str, me);
	if(!wep){
		write("The blacksmith asks: What do you want me to repair?\n");
		return 1;
	}
	if(!wep->fix_weapon()){
		write("The blacksmith says: That weapon isn't broken.\n");
		return 1;
	}
	if(TP->query_money() < COST4){
		write("The blacksmith says:  You don't have enough money!\n");
        wep->re_break();
		return 1;
	}
/*	tell_object(me, "You hand the "+wep->QN+" to the blacksmith...\n");  */
	TR(environment(me), "\n"+
		me->QN+" hands "+me->POS+" "+wep->QN+" to the blacksmith...\n"+
		"The blacksmith quickly repairs it and hands it back to "+me->QN+
		".\n\n"+me->QN+" hands the blacksmith some money.\n",
		({me}));
		tell_object(me,
		"\nYou hand the blacksmith "+COST4+" coins.\n");
	TP->add_money(-COST4);
	return 1;
}
