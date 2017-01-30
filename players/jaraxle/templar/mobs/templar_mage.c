#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

int spp;


reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;
spp = 400 + random(200);
set_name("gadvey");
set_alias("archmage");
set_alt_name("templar_mage");
set_race("human");
set_gender("male");
set_short("Gadvey da Rulesse, the Templar Archmage");
set_long(
"  The Archmage is dressed in the fine red robes of a magician. The\n"+
"fabric is embroidered with arcane symbols and runes, each stitched in\n"+
"gold thread. He stands tall and seems to be middle-aged, although his\n"+
"robes make it difficult to be certain. A corded belt made of golden\n"+
"threads accentuates his waistline, and a beautifully crafted ring of\n"+
"rubies and diamonds is visible on his finger. You may "+GRN+"ask"+NORM+" him for\n"+
"assistance if he is needed.\n");
set_level(20);
set_hp(800);
set_al(50);
set_wc(50);
set_ac(22);
set_aggressive(0);
set_heart_beat(1);
set_chat_chance(5);
  load_chat("Gadvey asks in a soft voice, 'What is it you need?'\n");
  load_chat("The archmage shuffles some papers.\n");
  load_chat("Gadvey peers out at you from the shadows of his hood.\n");
gold = clone_object("obj/money");
gold->set_money(random(2000) + 1000);
move_object(gold,this_object());
}

init(){
	::init();
	add_action("portal_thing", "portal");
/*	add_action("purchaser", "buy"); */
	add_action("ask_me", "ask");
   add_action("fix", "mend");
   add_action("empower", "empower");
    add_action("block_exit", "up", 1);
}

empower(str){
 int cost;
object wep;
object ob;
      if(!present("KnightInvite", this_player())){
		return 0;
    	}

      if (!str) return 0;
      
    ob=present(str,this_player());
      if(!ob) ob = present(str,this_object());
      if(!ob) {
     write("Gadvey looks around but doesn't see that here.\n");
    return 1;
     }

   if(!ob->weapon_class()){ write("Gadvey says: That is not a weapon.\n"); return 1; }
   
   if(ob->query_wielded()){ 
    write("Gadvey says: You must unwield your weapon first.\n");
    return 1;
    }
   if(ob->query_shadowed()){ write("It is already empowered!\n"); return 1; }
   cost = 3000;
   if(this_player()->query_money() < cost) {
      write("Gadvey says: You do not have enough coins.\n");
        return 1;
        }
    this_player()->add_money(-cost);
    wep = clone_object("/players/jaraxle/templar/obj/wepshad.c");
    wep->add_shadow(ob);
    write(
    "Gadvey takes hold of the "+str+" and pours "+HIY+"magical energies"+NORM+" into it...\n"+
    "The weapon glows brightly for a moment then fades.\n"+
    "Gadvey returns it to your waiting grasp.\n");
    return 1;
   }


fix(str) {
int cost;
object ob;
      if(!present("KnightInvite", this_player())){
		return 0;
    	}

      if (!str) return 0;
      
    ob=present(str,this_player());
      if(!ob) ob = present(str,this_object());
      if(!ob) {
     write("Gadvey looks around but doesn't see that here.\n");
    return 1;
     }
   if(ob->query_wielded()){ 
    write("Gadvey says: You must unwield it first.\n");
    return 1;
    }
   if(!ob->fix_weapon()) {
     write("It is not broken.\n");
     return 1;
    }
    cost = 300;
    if (this_player()->query_money() < cost) {
        ob->re_break();
      write("Gadvey says: You do not have enough coins.\n");
        return 1;
        }
    this_player()->add_money(-300);
    write(
    "Gadvey takes hold of the "+str+" and pours "+HIG+"magical energies"+NORM+" into it...\n"+
    "The weapon is mended completely.\n"+
    "Gadvey returns it to your waiting grasp.\n");
    return 1;
   }

block_exit(){
	if(!present("KnightInvite", this_player())){
		write("Gadvey blocks your entrance up to the castle.\n");
		return 1;
	}
return;
}

query_limited_shadow(){ return 1; }


heal_self(dam) {
  if(dam < 0) {
  tell_room(environment(),
  "The Archmage's shields hold!\n");
  return 1;
  }
  ::heal_self(dam);
  return dam;
}

ask_me(str){
	if(!present("KnightInvite", this_player())){
		return 0;
	}
	if(!str){ 
		write("Ask whom?\n");
		return 1;
	}
if(str == "mage" || str == "archmage" || str == "gadvey" ||
   str == "rulesse"){

write(
"The Archmage nods and says: I am here to assist the Knights Templar\n"+
"in their most worthy of causes. I can aid you with these items of\n"+
"magical nature or with my personal magical abilities:\n"+
"  \n"+
HIY+" portal"+HIW+" <"+HIY+"location"+HIW+">"+NORM+"           Location: church, advance, post, shop\n"+
"  \n"+
HIY+" mend"+HIW+" <"+HIY+"weapon"+HIW+">"+NORM+"               Repair a broken weapon. Cost: 300 coins.\n"+
"  \n"+
HIY+" empower"+HIW+" <"+HIY+"weapon"+HIW+">"+NORM+"            Empowers a weapon to do more damage.\n"+
"                             Cost: 3000 coins.\n"+
"  \n");
return 1;
}
write("Ask whom?\n");
return 1;
}

purchaser(str){
	object scroll;
	if(!present("KnightTemplar", this_player())){
		return 0;
	}
	if(!str){
		write("Buy what?\n");
		return 1;
	}

	if(str == "scroll"){
		if(this_player()->query_sp() < 100){
                   write("The Archmage shakes his head, saying: You don't have the spell points\n"+
				  "necessary for me to drain from you.\n");
			return 1;
		}
		scroll = clone_object("/players/jaraxle/templar/items/scroll.c");
		move_object(scroll, this_player());
		write("The Archmage grabs your hand, draining the necessary power to enchant\n"+
			  "the small parchment.\n"+
			  "He places it in your hand afterward and goes back to studying.\n");
        this_player()->add_spell_point(-100);
		return 1;
	}
	write("Buy what?\n");
	return 1;
}


portal_thing(str){
object portal;
string locale;
if(!present("KnightInvite", this_player())){
	return 0;
}

if(!str){
write("You must choose a location.\n");
return 1;
}


locale = 0;
   if(str == "church"){
      locale = "room/church";
   }
   else if(str == "shop"){
      locale = "room/shop";
	   }
   else if(str == "advance"){
	   locale = "room/adv_guild";
	   }
   else if(str == "post"){
	   locale = "room/post";
   }
   if(locale){
portal = clone_object("players/jaraxle/templar/items/portal.c");
move_object(portal, locale);
write("The Archmage waves his arms and summons forth a ring of magic. You\n"+
    "step through into the portal.\n");
say("A ring of magic appears allowing "+this_player()->query_name()+" to step through.\n");
move_object(this_player(), locale);
command("look", this_player());
return 1;
}
write("Portal to where: church, advance, post, or shop?\n");
return 1;
}





heart_beat(){
int chance;
object mob;
::heart_beat();
chance = random(100);
if(query_attack() && present("fear_link", query_attack()))
   destruct(present("fear_link", query_attack()));
if(query_wc() < 50) set_wc(50);
if(query_ac() < 22) set_ac(22);
   
if(attacker_ob && random(100) < 50) spp += random(5);

if(attacker_ob && random(100) < 70 && spp > 19){
switch(chance){
case 90..1000:
tell_room(environment(),
"The Archmage raises his hands high into the air...\n\n\n"+
"    "+HIB+"A bright flash of Lightning arches downward from the sky\n\n"+
"                 "+NORM+HIY+"SLAMMING"+NORM+"\n"+
"        "+HIB+"                   his opponent!"+NORM+"\n");
attacker_ob->hit_player(random(45) + 20);
spp -= 20;
break;
case 75..89:
tell_room(environment(),
"Gadvey points a finger at his opponent....\n"+
"         "+BOLD+"DEATH"+NORM+" surrounds "+attacker_ob->query_name()+"!\n"+
"   "+attacker_ob->query_name()+" screams in agony!!!\n");
attacker_ob->hit_player(random(30) + 20);
spp -= 18;
break;
case 50..74:
tell_room(environment(),
"The Archmage calls on the forces of the Warrior Spirit....\n\n"+
"     A huge flashing blade appears swinging at "+attacker_ob->query_name()+"...\n\n"+
"  "+attacker_ob->query_name()+" is "+HIR+"STRUCK"+NORM+" by the deadly phantasmic sword!\n");  
attacker_ob->hit_player(random(25) + 20);
spp -= 15;
break;
case 25..49:
tell_room(environment(),
"A freezing wind stirs up from around Gadvey...\n\n"+
"    It strikes out with typhoon force, slamming and freezing "+attacker_ob->query_name()+"!\n");
attacker_ob->hit_player(random(20) + 15);
spp -= 10;
break;
case 0..24:
tell_room(environment(),
BOLD+attacker_ob->query_name()+" is struck by scorching..."+NORM+"\n\n"+
"                       "+HIR+"BURSTS OF FIRE"+NORM+"\n"+
BOLD+attacker_ob->query_name()+" falls to the ground in burning agony!"+NORM+"\n");
attacker_ob->hit_player(random(15) + 10);
spp -= 5;
break;
default:
tell_room(environment(),
BOLD+attacker_ob->query_name()+" is struck by scorching..."+NORM+"\n\n"+
"                       "+HIR+"BURSTS OF FIRE"+NORM+"\n"+
BOLD+attacker_ob->query_name()+" falls to the ground in burning agony!"+NORM+"\n");
attacker_ob->hit_player(random(15) + 10);
spp -= 5;
break;
  }
}
if(hit_point > 0){
if(attacker_ob && random(100) < 5 && hit_point < max_hp/20 && filename(environment()) != "/players/jaraxle/templar/rooms/adv_inner.c"){
tell_room(environment(),
"Gadvey chants loudly and disappears!\n");
move_object(this_object(), "/players/jaraxle/templar/rooms/adv_inner");
  }  
}

if(attacker_ob && random(100) < 30 && !present("cave_mob", environment())){
tell_room(environment(),
"Gadvey holds forth a small scroll and chants softly...\n"+
"    A glowing blue portal opens allowing a creature of the dark to step through!\n");
mob = clone_object("players/jaraxle/cave/mobs/highlevel.c");
move_object(mob, environment());
mob->attack_object(query_attack());
spp -= 100;
  }

if(attacker_ob && present("cave_mob", environment()) && 
   !present("cave_mob", environment())->query_attack()){
   present("cave_mob", environment())->attack_object(query_attack());
   }
 }
	
  	          
