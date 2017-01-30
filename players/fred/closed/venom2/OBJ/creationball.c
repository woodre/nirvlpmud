/* 
Creation Ball - This is the object that is created by the
createitem spell.  If you are the owner, you can fashion
it into an item.  Wep/Armor: Wc 17-19 & Ac 1-2
*/

inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define USER this_player()
#define COL present("venom_object", this_player())->query_color()

string who;

id(str){ return str == "ball" || str == "creation_ball"; }
short() { return BOLD+"Creation Ball"+NORM; }
long(){
	write(
		"This is a smooth "+BOLD+"Dark Matter Ball"+NORM+".  It can be fashioned into almost any\n"+
		"type of Weapon or Piece of Armor.  For a listing of available shapes\n"+
		"type, 'shapes'.  When you decide, 'shape <form>'\n"+
	"This "+BOLD+"Dark Matter Ball"+NORM+" was created by "+who+"\n");
}

query_value(){ return 100; }
query_save_flag(){ return 1; }


set_who(str){ who = str; }
query_who(){ return who; }



init(){
	add_action("use_sphere", "shape");
	add_action("what_forms", "shapes");
}

what_forms(){
	if(!present("venom_object", this_player())) return 0;
	if(who != this_player()->query_real_name()) return 0;
	if(environment() != this_player()) return 0;
	write(
		"The Dark Matter Ball can be formed into any of the following:\n"+
		"  Weapons - Sword, BattleAxe, Spear, Dagger.\n"+
		"  Armor       - Helmet, Gloves, Cloak, Boots, Shield.\n"+
	"  To use it type 'shape <form>'.\n");
	return 1;
}


use_sphere(str){
	object wep,arm;
	string woot,typeit;
	if(!present("venom_object", this_player())) return 0;
	if(who != this_player()->query_real_name()) return 0;
	if(environment() != this_player()) return 0;
	if(!str){ write("Shape the ball into what? Type 'shapes' to see a list.\n"); return 1; }
	if(str == "sword" || str == "battleaxe" || str == "spear" || str == "dagger"){
		woot = str;
		if(woot == "battleaxe") woot = "battleAxe";
		wep = clone_object("obj/weapon");
		wep->set_id(str);
		wep->set_type(str);
		wep->set_weight(1);
		wep->set_value(500);
		wep->set_short(BOLD+"Dark Matter "+NORM+COL+capitalize(woot)+NORM+"");
		wep->set_long(
			"This weapon has been shaped from "+BOLD+"Dark Matter"+NORM+".\n"+
			"It is a beautiful living "+str+" that is lightweight. It was created by\n"+
		""+capitalize(who)+".\n");
		wep->set_class(17 + random(3));
		wep->set_save_flag(1);
		move_object(wep, environment(this_player()));
		tell_room(environment(this_player()),
		this_player()->query_name()+" places the Dark Matter Ball on the ground and shapes it into a "+str+".\n", ({ this_player() }));
		tell_object(this_player(),
		"You place the Creation Ball on the ground and shape it into a "+str+".\n");
		destruct(this_object());
		return 1;
	}
	else if(str == "helmet" || str == "gloves" || str == "cloak" || str == "shield" || 
           str == "boots"){
		woot = str;
		typeit = str;
		if(typeit == "gloves") typeit = "ring";
		if(typeit == "cloak") typeit = "misc";
		arm = clone_object("obj/armor");
		if(COL) arm->set_short(BOLD+"Dark Matter "+NORM+COL+capitalize(woot)+NORM+"");
		else arm->set_short(BOLD+"Dark Matter "+capitalize(woot)+NORM+"");
		arm->set_id(str);
		arm->set_type(typeit);
		arm->set_weight(1);
		arm->set_value(500);
		arm->set_long(
			"This piece of armor has been shaped from "+BOLD+"Dark Matter"+NORM+".\n"+
			"It is a beautiful living "+str+" that is lightweight. It was created by\n"+
		""+capitalize(who)+".\n");
		arm->set_ac(random(2) + 1);  /* 1-2 AC */
		arm->set_save_flag(1);
		move_object(arm, environment(this_player()));
		if(str == "gloves"){
			tell_room(environment(this_player()),
			this_player()->query_name()+" places the Dark Matter Ball on the ground and shapes it into a pair of "+str+".\n", ({ this_player() }));
			tell_object(this_player(),
			"You place the "+BOLD+"Creation Ball"+NORM+" on the ground and shape it into a pair of "+str+".\n");
		}
		else {
			tell_room(environment(this_player()),
			this_player()->query_name()+" places the Dark Matter Ball on the ground and shapes it into a "+str+".\n", ({ this_player() }));
			tell_object(this_player(),
			"You place the "+BOLD+"Creation Ball"+NORM+" on the ground and shape it into a "+str+".\n");
		}
		destruct(this_object());
		return 1;
	}
	else{
		write("Type 'shapes' to see a listing of available forms.\n");
		return 1;
	}
	return 1;
}



query_weight(){ return 0; }