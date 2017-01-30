inherit "room/room";	/*  cave7.c  */
#include "/players/zeus/closed/all.h"
int searched;
object shield, boots, amulet, gauntlet;
object sword, sword2, helm;

reset(arg){
 if(arg) return;

 searched = 0;  /* haven't searched */
 short_desc="A cavern";
 long_desc=
"You stand in the north end of a large chamber deep within the ground.\n"+
"Large jagged rocks jut out from the walls of the room.  Small droplets\n"+
"of water are collecting in the walls and slowly dripping down the walls.\n"+
"There is a pile of old bones sitting in the corner of the room.\n";
 set_light(0);
 items=({
	 "walls",
"The walls of the tunnel are very uneven and many jagged rocks protrude\n"+
"out from them",
	 "tunnel",
"The tunnel is slanting down at a steep angle to the west",
	 "rocks",
"The jagged rocks protrude from the sides of the tunnel.  Many of them\n"+
"have moisture collecting on them",
	 "water",
"Tiny droplets of water are collecting on the rocks and running down\n"+
"the walls",
	 "droplets",
"The tiny droplets of water slowly drip down the walls of the room",
	 "pile",
"It is a pile of old bones.  It looks as though there may be some\n"+
"other things mixed in with them",
	 "bones",
"It is a pile of old bones.  It looks as though there may be some\n"+
"other things mixed in with them",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/cave6.c", "south",
 });
}

void init(){
  ::init();
  add_action("search_cmd", "search");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }

make_boots(){
 boots = CO("/obj/armor.c");
 boots->set_name("boots");
 boots->set_type("boots");
 boots->set_short("A pair of boots");
 boots->set_long(
"This is a simple pair of brown boots.  They are rather worn, and doen't\n"+
"look very nice, but would still protect your feet.\n");
 boots->set_ac(1);
 boots->set_weight(1);
 boots->set_value(100+random(700));
}

make_helm(){
 helm = CO("/obj/armor.c");
 helm->set_name("helmet");
 helm->set_type("helmet");
 helm->set_short("A tarnished helmet");
 helm->set_long(
"This tarnished helmet is decorated with dents and scratches.\n");
 helm->set_ac(1);
 helm->set_weight(1);
 helm->set_value(100+random(700));
}

make_shield(){
 shield = CO("/obj/armor.c");
 shield->set_name("shield");
 shield->set_type("shield");
 shield->set_short("A black shield");
 shield->set_long("This is a simple black shield.\n");
 shield->set_ac(1);
 shield->set_weight(1);
 shield->set_value(100+random(800));
}

make_gauntlet(){
 gauntlet = CO("/obj/armor.c");
 gauntlet->set_name("gauntlet");
 gauntlet->set_type("misc");
 gauntlet->set_short("An iron gauntlet");
 gauntlet->set_long("This is a single, worn iron gauntlet.\n");
 gauntlet->set_value(100+random(500));
 gauntlet->set_ac(2);
 gauntlet->set_weight(1);
}

make_sword(){
 sword = CO("/obj/weapon.c");
 sword->set_name("sword");
 sword->set_short("A dull sword");
 sword->set_long("This is a dull, worn knights sword.\n");
 sword->set_class(18);
 sword->set_value(400+random(500));
 sword->set_weight(1);
}

make_sword2(){
 sword2 = CO("/obj/weapon.c");
 sword2->set_name("blade");
 sword2->set_short("A wicked blade");
 sword2->set_long("This is a very cool looking blade.\n");
 sword2->set_class(17);
 sword2->set_value(100+random(800));
 sword2->set_weight(1);
}

make_amulet(){
 amulet = CO("/obj/armor.c");
 amulet->set_name("amulet");
 amulet->set_type("amulet");
 amulet->set_short("An amulet");
 amulet->set_long("This is a plain looking amulet.\n");
 amulet->set_ac(0);
 amulet->set_value(100+random(300));
 amulet->set_weight(1);
}


status search_cmd(string str){
	int s,t,u,v,w,x,y,z;
	object gold;
	if(!str){
		write("You search the room generally and find nothing.\n");
		say(TP->QN+" searches around.\n");
		return 1;
	}
	if(str == "bones" || str == "pile" || str == "pile of bones"){
		if((int)TP->query_attrib("int") <= 19){
			write("You search the pile of bones and find nothing.\n");
			searched = 1;
			return 1;
		}
		if(searched){
			write("You search the pile of bones and find nothing.\n");
			return 1;
		}
		else {
			s = random(3);
			t = random(3);
			u = random(3);
			v = random(3);
			w = random(3);
			x = random(3);
			y = random(3);
			z = random(3);
			write_file("/players/zeus/log/cave_search", ctime(time())+
			"  "+TP->QRN+" got "+s+", "+t+", "+u+", "+v+", "+w+", "+x+
			", "+y+", "+z+".\n");
			if(!s){ make_boots(); MO(boots, TO);   }
			if(!t){ make_helm(); MO(helm, TO);        }
			if(!u){ make_shield(); MO(shield, TO);     }
			if(!v){ make_gauntlet(); MO(gauntlet, TO); }
			if(!w){ make_sword(); MO(sword, TO);      }
			if(!x){ make_sword2(); MO(sword2, TO);  }
			if(!y){ make_amulet(); MO(amulet, TO);  }
			if(!z){ gold = CO("/obj/money.c");
				gold->set_money(random(4000));
				MO(gold, TO);	}
			if(!s || !t || !u || !v || !w || !x || !y || !z){
			write("You search the pile of bones and find some treasure.\n");
			}
			else { 
			write("You search the pile of bones and find nothing.\n");
			}
			searched = 1;
			return 1;
		}
		return 1;
	}
	else return 0;
	return 1;
}
