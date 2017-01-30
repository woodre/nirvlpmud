#include "/players/maledicta/ansi.h"
#define USER environment()
#define ATT USER->query_attack()
#define USERN USER->query_name()
#define USERPOS USER->query_possessive()
#define USERPRO USER->query_pronoun()
#define USEROBJ USER->query_objective()
#define ATTPOS ATT->query_possessive()  /* his her */
#define ATTPRO ATT->query_pronoun()     /* he she  */
#define ATTOBJ ATT->query_objective()   /* him her */
#define ATTN ATT->query_name()

query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }

int block;

id(str){
   return str == "cape" || str == "shoulder cape" || str == "dragon_cape";
}

query_auto_load(){ return "/players/maledicta/closed/saladin.c:"; }


short(){
   return RED+"Shoulder Cape of Dragonkind"+NORM+" (worn)";
}

long(){
   write(
   "This is a dark red shoulder cape that stretches over your left arm and\n"+
   "down to your knee. It is decorated with small sapphires around the\n"+
   "trim, with gold designs surrounding them.  It holds the dead spirits of\n"+
   "an entire race of Desert Dragons that once ruled the homeland of the\n"+
   "Dervish.  With their power you can 'conjure' the forces within.\n");
   return 1;
   }

init(){
  add_action("conjure_it", "conjure");
  }

conjure_it(str){
   object target;
	string msg,msg2,msg3;
	int damage,spamount;
	string wep,where,how;
   string hh;
   string hhh;
   string how1;
	if(USER->query_ghost()) return 0;
   if(USER->query_extra_level() < 5) return 0;
	if(USER->query_spell_dam()) return 1;
	if(USER->query_sp() < 25){
		tell_object(USER,
		"You are too weak to conjure the dragon forces.\n");
		return 1;
	}
	if(!USER->query_attack()){
		tell_object(USER, "You are not fighting!\n");
		return 1;
	}
	target = ATT;
   spamount = 25;
	damage = random(33) + 12;
 if(random(100) < 20){  
   switch(random(4) + 1){
     case 4:
     tell_object(USER,
     "You stretch forth your arms...\n"+
     "The Cape of Dragonkind billows out before you, its edges glowing brightly...\n\n"+
     "                      "+BOLD+"-[ "+HIY+"D"+NORM+BOLD+" ] - [ "+HIY+"E"+NORM+BOLD+""+
     " ] - [ "+HIY+"S"+NORM+BOLD+" ] - [ "+HIY+"E"+NORM+BOLD+" ] - [ "+HIY+"R"+NORM+BOLD+" ] - [ "+HIY+""+
     ""+HIY+"T"+NORM+BOLD+" ] -"+NORM+"\n"+
     "                               "+YEL+"P      O      W      E      R"+NORM+"\n\n"+
     "Ripping sand fills the room and tears down "+ATTN+"!\n");
     tell_room(environment(USER),
	  "Saladin stretches forth his arms...\n"+
     "The Cape of Dragonkind billows out before him, its edges glowing brightly...\n\n"+
     "                      "+BOLD+"-[ "+HIY+"D"+NORM+BOLD+" ] - [ "+HIY+"E"+NORM+BOLD+""+
     " ] - [ "+HIY+"S"+NORM+BOLD+" ] - [ "+HIY+"E"+NORM+BOLD+" ] - [ "+HIY+"R"+NORM+BOLD+" ] - [ "+HIY+""+
     ""+HIY+"T"+NORM+BOLD+" ] -"+NORM+"\n"+
     "                               "+YEL+"P      O      W      E      R"+NORM+"\n\n"+
     "Ripping sand fills the room and tears down "+ATTN+"!\n", ({ USER }));
     command("mon", USER);
     break;
     case 3:
     tell_object(USER,
     BOLD+"You grasp the edge of your shoulder cloak and twirl...\n"+
     "Spectral Dragon Wings Spread out and encircle you..."+NORM+"\n\n"+
     "            "+HIG+"- "+HIW+"S   L   I   C   E"+HIG+" -"+NORM+"\n\n"+
     BOLD+ATTN+" cries out as shadowy wings rip into "+ATTOBJ+"!"+NORM+"\n");     
     tell_room(environment(USER),
     "Saladin grasps the edge of his shoulder cloak and twirls...\n"+
     "Spectral Dragon Wings spread forth and encircle him...\n"+
     "            "+HIG+"- "+HIW+"S   L   I   C   E "+HIG+"-"+NORM+"\n"+
     ATTN+" cries out as shadowy wings rip into "+ATTOBJ+"!\n", ({ USER }));
     command("mon", USER);
     break;
     case 2:
     tell_object(USER,
     HIW+"You point at "+ATTN+"...\n"+
     "Your cloak flows forward and opens wide...\n"+
     "             "+RED+"~ ~ ~~ "+HIR+"* "+NORM+BOLD+"FIERY BREATH"+HIR+" * "+NORM+RED+"~~ ~ ~\n"+
     "                          "+NORM+HIW+ATTN+" is engulfed!"+NORM+"\n");
     tell_room(environment(USER),
     "Saladin point at "+ATTN+"...\n"+
     "His cloak flows forward and opens wide...\n"+
     "             "+RED+"~ ~ ~~ "+HIR+"* "+NORM+BOLD+"FIERY BREATH"+HIR+" * "+NORM+RED+"~~ ~ ~\n"+
     "                          "+NORM+HIW+ATTN+" is engulfed!"+NORM+"\n", ({ USER }));
     command("mon", USER);
     break;
     case 1:
     tell_object(USER,
     "You close your eyes and summon forth the fury of the Dragons!\n\n"+
     HIW+"    <  < <  "+HIR+"C  L  A  W  "+HIW+"> >  < "+HIR+"<<>>"+HIW+" >  < <  "+HIR+"C  L  A  W "+HIW+" > >  >\n\n"+
     NORM+"  Spectral claws lash out and rend "+ATTN+" to bloody bits!\n");
     tell_room(environment(USER),
     "Saladin's eyes close as he summons forth the fury of the Dragons!\n\n"+
     HIW+"    <  < <  "+HIR+"C  L  A  W  "+HIW+"> >  < "+HIR+"<<>>"+HIW+" >  < <  "+HIR+"C  L  A  W "+HIW+" > >  >\n\n"+
     NORM+"  Spectral claws lash out and rend "+ATTN+" to bloody bits!\n", ({USER}));
     command("mon", USER);
     break;
     }
}
else{
   switch(damage){
     case 40..1000: hh = HIR+"D E V A S T A T E D"+HIW; break;
     case 34..39: hh = HIR+"~ RAVAGED ~"+HIW; break;
     case 28..33: hh = RED+"BROKEN"+HIW; break;
     case 24..27: hh = RED+"Struck Down"+HIW; break;
     case 16..23: hh = "Struck"; break;
     case 1..15: hh = "Hit"; break;
     default: hh = "hit"; break;
     }

   switch(random(4) + 1){
    case 4:
     hhh = ATTN+" is "+hh+" by Spectral Dragon Claws";
     break;
    case 3:
     hhh = ATTN+" is "+hh+" by the Strength of the Dragon";
     break;
    case 2:
     hhh = ATTN+" is "+hh+" by Draconian Soul Energy";
     break;
    case 1:
     hhh = ATTN+" is "+hh+" by a cone of Spectral Dragon Breath";
     break;
    }
   switch(random(5) + 1){
   case 5:
    how1 = USERN+" rises up on spectral wings and points at "+ATTN+"...";
    break; 
   case 4:
    how1 = USERN+" twirls about conjuring the spirits of Dragons...";
    break;
   case 3:
    how1 = USERN+" cries out, \""+NORM+"COME TO ME AND OBEY!"+NORM+"\"";
    break;
   case 2:
    how1 = USERN+" crackles with Draconian Might as he beckons heavenward...";
    break;
   case 1:
    how1 = USERN+" motions towards "+ATTN+", calling forth the Spirit of the Drake...";
    break;
    }
tell_room(environment(USER),
   HIW+how1+NORM+"\n"+
   HIW+hhh+NORM+"!\n");
 }  

	msg = "";
	msg2 = "";
	msg3 = "";
	USER->spell_object(ATT, HIG+"Conjuration"+NORM, damage, spamount,
	msg, msg2, msg3);
	return 1;
}
