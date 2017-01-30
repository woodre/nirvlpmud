#include "/players/pain/color.h"
#define COWL present("p_g_ob",this_player())
#define MAN "/players/pain/NEW/druid/manpages/"
#define a_mod COWL->query_a_mod()
#define c_mod COWL->query_c_mod()
#define member this_player()
#define m_gl this_player()->query_guild_rank()
#define m_gxp this_player()->query_guild_exp()
#define tpn this_player()->query_name()
#define tps this_player()->query_sp()
#define poss this_player()->query_possessive()
#define proom environment(this_player())
#define train_fail "You do not have the training to cast this spell.\n"
#define spirit_fail "You do not have the spirit points for this.\n"
#define init_chant "You begin to chant quietly, concentrating on your wounds\n"
#define cure "You ask for God's help in healing your "+how+" wounds.\n"
#define ucure "You ask for God's help in healing "+target+"'s "+how+" wounds\n"
#define p_cure tpn+" prays for your "+how+" wounds.\n"
#define g_msg "God envelops you in His love, healing your wounds.\n"


dwho() {
int count,
    rank,
    invis,
    i,
    x;

object cowl,
       gob,
       ob;

string name,
       quiet,
       location;

ob = users();
i = 0;
invis = 0;

write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
write(" Name:           Quiet:          Rank:     Location:\n");
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");

for( x = 0; x < sizeof(ob); x += 1) {
if(present("p_g_ob",ob[x])) {
	name = capitalize(ob[x]->query_real_name());
	if(ob[x]->query_invis() > 0) { invis = 1; }
	gob = present("p_g_ob",ob[x]);
	if(gob->query_muffs()) { quiet == "yes"; }
	else quiet = "no";

        rank = ob[x]->query_guild_level();

		location = environment(ob[x])->short();

        if(invis > 0) { write("*"); }
        else write(" ");
        count = strlen(name);
        count = 19 - count;
        write(name);
        while(count > 0) {
                write(" ");
                count = count - 1;
        }
        count = strlen(quiet);
        count = 18 - count;
        write(quiet);
        while(count > 0) {
                write(" ");
                count = count - 1;
        }
        if(rank > 9) { write(rank); }
        else write(" "+rank);
        write("     ");
        write(location+"\n");
        i = i + 1;
}
}
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
write(" * indicates the Druid is invisible.\n");
write(" Druids Currently Logged in: "+i+"\n");
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
}


dtalk(str) {
int x;
object ob;
object cowl;
if(!str){
        write("And what pray-tell would you like to share with the "+
              "rest of the druids??\n");
        return 1;
}
ob = users();
for( x = 0; x < sizeof(ob); x += 1) {
if(present("p_g_ob", ob[x])){
cowl = present("p_g_ob", ob[x]);
if(cowl->query_muffs() == 0 && cowl->query_color() == 0){
	tell_object(ob[x],GREEN+"</*\\>"+END+tpn+": "+str+"\n");
}
if(cowl->query_muffs() == 0 && cowl->query_color() == 1){
	tell_object(ob[x],"</*\\>"+tpn+": "+str+"\n");
}
}
}
return 1;
}



demote(str) {
int x;
object ob,
       cowl;

if(!str) {
        write("And what pray-tell would you like to emote to the "+
              "rest of the druids??\n");
        return 1;
}
ob = users();
for( x = 0; x < sizeof(ob); x += 1) {
if(present("p_g_ob",ob[x])) {
cowl = present("p_g_ob",ob[x]);
if(cowl->query_muffs() == 0 && cowl->query_color() == 0) {
	tell_object(ob[x],GREEN+"</*\\>"+END+tpn+" "+str+"\n");
}
if(cowl->query_muffs() == 0 && cowl->query_color() == 1) {
	tell_object(ob[x],"</*\\> "+tpn+" "+str+"\n");
}
}
}
return 1;
}



/*
        This is the function that is called when a druid wants to
        heal either another player or him/herself.

        the c_mod is the level of training that the druid as obtained
        in the healing arts.
*/

cure_f(str) {
        string how;
        string who;
        object target;

if(!str){
        write("You may either cure light, cure medium, "+
              "cure serious or cure critical. \n");
        }
sscanf(str, "%s %s", how, who);
if(how != "light" && how != "medium" && how != "serious" && how != "critical") {
	write("You can only cure light, medium, serious or critical wounds.\n");
		return 1;
}
        if(!who) {
                if(how == "light" && c_mod < 5) {
                   write(train_fail);
                   return 1;
                }
                if(how == "light" && c_mod > 4) {
                   if(tps < 4) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps >3) {
                        write(init_chant);
                        write(cure);
                        write(g_msg);
                        this_player()->add_sp(-4);
                        this_player()->add_hp(2+random(8));
                        return 1;
                   }
                }
                if(how == "medium" && c_mod < 10) {
                   write(train_fail);
                   return 1;
                }
                if(how == "medium" && c_mod > 9) {
                   if(tps < 16) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 15) {
                        write(init_chant);
                        write(cure);
                        write(g_msg);
                        this_player()->add_sp(-15);
                        this_player()->add_hp(12+random(8));
                        return 1;
                   }
                }
                if(how == "serious" && c_mod < 15) {
                   write(train_fail);
                   return 1;
                }
                if(how == "serious" && c_mod > 14) {
                   if(tps < 28) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 27) {
                        write(init_chant);
                        write(cure);
                        write(g_msg);
                        this_player()->add_sp(-50-random(c_mod));
                        this_player()->add_hp(20+random(c_mod));
                        return 1;
                   }
                }
                if(how == "critical" && c_mod < 20) {
                   write(train_fail);
                   return 1;
                }
                if(how == "critical" && c_mod > 19) {
                   if(tps < 40) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 39) {
                        write(init_chant);
                        write(cure);
                        write(g_msg);
                        this_player()->add_sp(-70-random(c_mod));
                        this_player()->add_hp(30+2*random(c_mod));
                        return 1;
                   }
                }
        }
        target = present(who,environment(this_player()));
        if(!target) {
                write("The player must be present in order for "+
                      "your cure to take effect.\n");
                return 1;
        }
        if(how == "light" && c_mod < 5) {
                   write(train_fail);
                   return 1;
                }
                if(how == "light" && c_mod > 4) {
                   if(tps < 4) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps >3) {
                        write(init_chant);
                        write(ucure);
                        tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-4);
                        target->add_hp(2+random(8));
                        return 1;
                   }
                }
                if(how == "medium" && c_mod < 10) {
                   write(train_fail);
                   return 1;
                }
                if(how == "medium" && c_mod > 9) {
                   if(tps < 16) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 15) {
                        write(init_chant);
                        write(ucure);
                        tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-15);
                        target->add_hp(12+random(8));
                        return 1;
                   }
                }
                if(how == "serious" && c_mod < 15) {
                   write(train_fail);
                   return 1;
                }
                if(how == "serious" && c_mod > 14) {
                   if(tps < 28) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 27) {
                        write(init_chant);
                        write(ucure);
                        tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-50-random(c_mod));
                        target->add_hp(20+random(c_mod));
                        return 1;
                   }
                }
                if(how == "critical" && c_mod < 20) {
                   write(train_fail);
                   return 1;
                }
                if(how == "critical" && c_mod > 19) {
                   if(tps < 40) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 39) {
                        write(init_chant);
                        write(cure);
                        tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-70-random(c_mod));
                        target->add_hp(30+2*random(c_mod));
                        return 1;
                   }
                }
write("Oh crap.. tell Pain you got message mcure1.0\n");
return 1;
}

/*
        This is the function definition for the chill touch attack spell
        for the Druids

        note that a_mod is the attack spell modifier

*/

ctouch(str) {
   object attack;
   string a_name;
   int roll;
   if(a_mod < 5) {
        write(train_fail);
        return 1;
   }
   if(!str) {
      write("Whom do you wish to grasp?\n");
      return 1;
   }
   attack = present(str,environment(member));
   if(!attack) {
      write("That monster is not in the room!\n");
      return 1;
   }
   if(attack->query_npc() == 0) {
      write("You cannot grasp another player!\n");
      return 1;
   }

   if(tps < 40) {
        write(spirit_fail);
        return 1;
   }
   member->add_sp(-40-a_mod/2);
   a_name = attack->query_name();
   write("You reach out to grasp "+a_name+".\n");
   say(tpn+" grasps "+a_name+" with an icy hand.\n");
   roll = a_mod+random(70);
   if(roll < 20 && m_gl < 3) {
      tell_room(proom, a_name+" is chilled by "+tpn+"'s grasp.\n");
      a_name->hit_player(7);
      return 1;
   }
   if(roll < 20 && m_gl < 5) {
      tell_room(proom, tpn+" freezes "+a_name+" with an icy grasp.\n");
      a_name->hit_player(12);
      return 1;
   }
   if(roll < 20 && m_gl < 8) {
      tell_room(proom, a_name+" quivers under "+tpn+"'s grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 20 && m_gl > 7) {
      tell_room(proom, a_name+"'s flesh freezes at "+tpn+"'s icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 50 && m_gl < 3) {
      tell_room(proom, tpn+" freezes "+a_name+" with an icy grasp.\n");
      a_name->hit_player(12);
      return 1;
   }
   if(roll < 50 && m_gl < 5) {
      tell_room(proom, a_name+" quivers under "+tpn+"'s grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 50 && m_gl < 8) {
      tell_room(proom, a_name+"'s flesh freezes at "+tpn+"'s icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 50 && m_gl > 7) {
      tell_room(proom, a_name+" is thrown back by "+tpn+"'s icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 85 && m_gl < 3) {
      tell_room(proom, a_name+" quivers at "+tpn+"'s icy grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 85 && m_gl < 5) {
      tell_room(proom, a_name+"'s flesh freezes at "+tpn+"'s icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 85 && m_gl < 8) {
      tell_room(proom, a_name+" is thrown back by "+tpn+"'s icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 85 && m_gl > 7) {
      tell_room(proom, a_name+"'s soul is frozen by "+tpn+"'s icy grasp.\n");
      a_name->hit_player(30);
      return 1;
   }
   if(roll < 101 && m_gl < 3) {
      tell_room(proom, a_name+"'s flesh freezes at "+tpn+"'s icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 101 && m_gl < 5) {
      tell_room(proom, a_name+" is thrown back by "+tpn+"'s icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 101 && m_gl < 8) {
      tell_room(proom, a_name+"'s soul is frozen by "+tpn+"'s icy grasp.\n");
      a_name->hit_player(30);
      return 1;
   }
   if(roll < 101 && m_gl > 7) {
      tell_room(proom, tpn+" devestates "+a_name+" with an icy grasp!\n");
      a_name->hit_player(20+random(a_mod));
      return 1;
   }
}







lightning(str) {
   object attack;
   string a_name;
   int roll;

   if(m_gl < 3) {
      write("You must attain a higher level in the Clan to cast this.\n");
      return 1;
   }

   if(!str) {
      write("Who do you wish to strike with lightning?\n");
      return 1;
   }

   attack = present(str,environment(member));
   if(attack->query_npc() == 0) {
      write("You cannot use this spell on a player!\n");
      return 1;
   }
   if(tps < 45) {
      write("You need more spell points to cast this.\n");
      return 1;
   }
   write("You look up to the skies and begin to call upon the power of\n"+
         "nature in your attempt to destroy "+attack->query_name()+".\n");
   say(tpn+" looks up into the sky and begins to call upon the power of\n"+
       "nature to destroy "+attack->query_name()+".\n");
   roll = random(10);
   if(roll < 3) {
        tell_room(environment(this_player()), "Lightning weakly flashes "+
                  "overhead, and barely manages to\nsinge "+
                  attack->query_name()+"'s hair.\n");
        attack->add_hp(-(roll+(1+random(2))*a_mod));
        return 1;
   }
   if(roll < 7) {
        tell_room(environment(this_player()),"Lightning flashes overhead "+
                  "illuminating the battle briefly before\nstriking "+
                  attack->query_name()+".\n");
        attack->add_hp(-(roll+(2+random(1))*a_mod));
        return 1;
   }
   tell_room(environment(this_player()),"Lightning flashes brilliantly "+
             "overhead, lighting up the entire area\nbefore striking "+
             attack->query_name()+" to the ground.\n");
  attack->add_hp(-(roll+3*a_mod));
   return 1;
}

/*
        This is the function definition for the Rain Nature Spell
        for the Druids

        note a_mod is the attack spell modifier
*/

rain() {
   object attack;
   string a_name;
   int roll;

   if(a_mod < 10) {
      write(train_fail);
      return 1;
   }

   if(member->query_attack() == 0) {
      write("You must be in battle to use this spell.\n");
      return 1;
   }

   if(tps < 35) {
      write(spirit_fail);
      return 1;
   }

   attack = member->query_attacker();
        if(attack->query_npc() == 0) {
      write("You can not call for a rain storm on a player.\n");
      return 1;
   }

   a_name = attack->query_name();
   write("You call for a Rain Storm from Mother Nature.\n");
   say(tpn+" calls for a Rain Storm from Mother Nature.\n");
   member->add_sp(-50-a_mod/2);
   roll = a_mod+random(70);
   if(roll < 30 && m_gl < 4) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" on the arm.\n");
      a_name->hit_player(10);
      return 1;
   }
   if(roll < 30 && m_gl < 7) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" on the leg.\n");
      a_name->hit_player(13);
      return 1;
   }
   if(roll < 30 && m_gl > 7) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" on the forehead.\n");
      a_name->hit_player(18);
   }
   if(roll < 70 && m_gl < 4) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" on the leg.\n");
      a_name->hit_player(13);
      return 1;
   }
   if(roll < 70 && m_gl < 7) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" on the forehead.\n");
      a_name->hit_player(18);
      return 1;
   }
   if(roll < 70 && m_gl > 7) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" on the neck.\n");
      a_name->hit_player(22);
      return 1;
   }
   if(roll < 101 && m_gl < 4) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" in the forehead.\n");
      a_name->hit_player(18+random(a_mod));
      return 1;
   }
   if(roll < 101 && m_gl < 7) {
      tell_room(proom, a_name+"'s weapon slips and nicks "+a_name+" in the neck.\n");
      a_name->hit_player(22+random(a_mod));
      return 1;
   }
   if(roll < 101 && m_gl > 7) {
      tell_room(proom, a_name+"'s eyes grow large as "+a_name+"'s weapon slips "+
            "and\n nicks"+a_name+" in the groin!\n");
      a_name->hit_player(25+random(a_mod));
      return 1;
   }
}

/* meld with your surroundings */
meld() {
   if(tps < 20) {
      write("You need more spell points to cast this.\n");
      return 1;
   }

   this_player()->add_sp(-20);
   write("As you meld with the surrounding nature, you begin to feel\n"+
      "stronger. You feel the power of Nature coursing through you.\n");
   say(tpn+" melds with Nature and appears stonger.\n");
   this_player()->add_hp(20);
   return 1;
}
/* end meld */

guild_title() {
   if(m_gl == 1) {
      member->set_title("the initiate Druid");
      return 1;
   }
   if(m_gl == 2) {
      member->set_title("the apprentice Druid");
      return 1;
   }
   if(m_gl == 3) {
      member->set_title(", Nature's apprentice");
      return 1;
   }
   if(m_gl == 4) {
      member->set_title("a Druid of the First Order");
      return 1;
   }
   if(m_gl == 5) {
      member->set_title("a Druid of the Second Order");
      return 1;
   }
   if(m_gl == 6) {
      member->set_title("a Druid of the Third Order");
      return 1;
   }
   if(m_gl == 7) {
      member->set_title("a Druid of the Fourth Order");
      return 1;
   }
   if(m_gl == 8) {
      member->set_title("an initiate to the Inner Circle");
      return 1;
   }
   if(m_gl == 9) {
      member->set_title("an apprentice to the Inner Circle");
      return 1;
   }
   if(m_gl == 10) {
      member->set_title("a member of the Inner Circle");
      return 1;
   }
   if(m_gl > 10) {
      member->set_title("the Master of Nature");
      return 1;
   }
}

manual(str) {
if(!str) { cat("/players/pain/NEW/druids/manpages/druid_info"); return 1; }

if("/players/pain/NEW/druids/manpages/"+str) {
	cat("/players/pain/NEW/druids/manpages/"+str);
	return 1;
}
else write("There is no page in the manual for "+BOLD+GREEN+str+END+"\n");
return 1;
}

skills() {
int temp;
int nlvl;
int nglvl;
string a_skill;
string c_skill;

if(this_player()->query_level() < 21) {
temp = call_other("/room/adv_guild","get_next_exp",this_player()->query_level());
nlvl = temp - this_player()->query_exp();

nglvl = (m_gl*17500) - m_gxp;
}

if(a_mod < 6) { a_skill = "Poor"; }
if(a_mod > 5 && a_mod < 11) { a_skill = "Mediocre"; }
if(a_mod > 10 && a_mod < 16) { a_skill = "Good"; }
if(a_mod > 15) { a_skill = "Excellent"; }

if(c_mod < 6) { c_skill = "Poor"; }
if(c_mod > 5 && c_mod < 11) { c_skill = "Mediocre"; }
if(c_mod > 10 && c_mod < 16) { c_skill = "Good"; }
if(c_mod > 15) { c_skill = "Excellent"; }

write("\n");
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n");
write("   Druid Level: "+m_gl+"   Title: "+member->query_title()+"\n\n");
if(this_player()->query_level() < 21) {
write("   Experience to next Level: "+nlvl+"\n");
write("   Experience to next Druid Level: "+nglvl+"\n");
}
write("Druid Skills:\n\n");
write("     Attack Spell Skill: "+a_skill+"\n");
write("       Cure Spell Skill: "+c_skill+"\n\n");
write("Regular Stats:\n\n");
write("          Stamina: "+this_player()->query_attrib("sta")+"\n");
write("         Strength: "+this_player()->query_attrib("str")+"\n");
write("            Magic: "+this_player()->query_attrib("mag")+"\n");
write("     Intelligence: "+this_player()->query_attrib("int")+"\n");
write("            Piety: "+this_player()->query_attrib("pie")+"\n");
write("       Will Power: "+this_player()->query_attrib("wil")+"\n");
write("             Luck: "+this_player()->query_attrib("luc")+"\n\n");
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n");

}
