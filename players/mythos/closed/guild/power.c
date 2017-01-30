/**  Object which contains all spells  **/

#include "/players/mythos/closed/guild/def.h"

/**  Powers  **/

#include "/players/mythos/closed/guild/spells/sac.h"
#include "/players/mythos/closed/guild/spells/dfollow.h" 
#include "/players/mythos/closed/guild/spells/dwho.h"  
#include "/players/mythos/closed/guild/spells/dscore.h" 
#include "/players/mythos/closed/guild/spells/chill_shield.h"
#include "/players/mythos/closed/guild/spells/nightmare_min.h"
#include "/players/mythos/closed/guild/spells/dismiss.h"
#include "/players/mythos/closed/guild/spells/mesmerize.h" 
#include "/players/mythos/closed/guild/spells/dblood.h"  
#include "/players/mythos/closed/guild/spells/myst.h"
#include "/players/mythos/closed/guild/spells/identify.h"
#include "/players/mythos/closed/guild/spells/terror.h"
#include "/players/mythos/closed/guild/spells/cold_shield.h"
#include "/players/mythos/closed/guild/spells/darkness.h"  
#include "/players/mythos/closed/guild/spells/nightmare_maj.h"
#include "/players/mythos/closed/guild/spells/distraction.h"  
#include "/players/mythos/closed/guild/spells/empower.h" 
#include "/players/mythos/closed/guild/spells/true_darkness.h" 
#include "/players/mythos/closed/guild/spells/demon_bind.h"  
#include "/players/mythos/closed/guild/spells/grand_circle.h"  
#include "/players/mythos/closed/guild/spells/gate.h"
#include "/players/mythos/closed/guild/spells/chaos.h"
#include "/players/mythos/closed/guild/spells/drain.h" 
#include "/players/mythos/closed/guild/spells/imbue.h"  
#include "/players/mythos/closed/guild/spells/shape_change.h"  
#include "/players/mythos/closed/guild/spells/ward.h"
#include "/players/mythos/closed/guild/spells/cold_area.h"
#include "/players/mythos/closed/guild/spells/shatter.h"  
#include "/players/mythos/closed/guild/spells/dwhip.h" 
#include "/players/mythos/closed/guild/spells/true_banish.h"
#include "/players/mythos/closed/guild/spells/reverse.h"
#include "/players/mythos/closed/guild/spells/siphon.h"
#include "/players/mythos/closed/guild/spells/night.h"
#include "/players/mythos/closed/guild/spells/cause_miss.h"
#include "/players/mythos/closed/guild/spells/knowing.h" 
#include "/players/mythos/closed/guild/spells/power_word.h"
#include "/players/mythos/closed/guild/spells/simulacrum.h"
#include "/players/mythos/closed/guild/spells/imagery.h" 
#include "/players/mythos/closed/guild/spells/spirit_meld.h"  
#include "/players/mythos/closed/guild/spells/weather.h" 
#include "/players/mythos/closed/guild/spells/devil_pact.h"
#include "/players/mythos/closed/guild/spells/demon_pact.h"
#include "/players/mythos/closed/guild/spells/demon_spell.h"  
#include "/players/mythos/closed/guild/spells/tidal_flare.h"
#include "/players/mythos/closed/guild/spells/flare.h"
#include "/players/mythos/closed/guild/spells/creeping_doom.h"
#include "/players/mythos/closed/guild/spells/duplicate.h"
#include "/players/mythos/closed/guild/spells/replicate.h"
#include "/players/mythos/closed/guild/spells/flash_fire.h"
#include "/players/mythos/closed/guild/spells/ownership.h"
#include "/players/mythos/closed/guild/spells/remove_ownership.h"
#include "/players/mythos/closed/guild/spells/withering_hand.h"

dlead(str) {
object ob;
if(!str || str == tpn) { 
write("Usage: dlead <name>\n");
write("Spell dispelled.\n"); return 1;}
if(present(str, environment(this_player()))) {
     tp->add_spell_point(-10);
     ob=clone_object("/players/mythos/amisc/forest/ask.c");
     ob->set_asker(this_player()->query_real_name());
     move_object(ob,find_player(str));
     return 1;}
     write("Who do you wish to lead?\n");
return 1;} 
   
dfeed() {
int damage;
if(scrp < 20) { write("The darkness calls for a sacrifice.\n"); return 1;}
  if(!(tp->query_attack())) {write("You may only use this during combat.\n"); return 1;}
  if(!((tp->query_attack())->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;}
    if(qtf > 8) {
  damage = random(2 * qtf); }
    else { damage = random(8); }
  if((tp->query_attack())->query_hp() < damage) {
    say(capitalize(tpn)+"'s eyes glow with an unholy blue flame!\n");
    say("You are filled with....\n");
    write("You intensify the fear in your victim, until it has become....\n");
    tell_room(environment(tp),BOLD+"\n"+
          "            <-------   DREAD   ------>\n"+NORM);
    tell_room(environment(tp),capitalize((tp->query_attack())->query_name())+
    " screams in terror and pain!\n");
    (tp->query_attack())->hit_player(damage*2);
    tp->heal_self(1);
    write("You feel invigorated.\n");
  return 1;}
  write(capitalize((tp->query_attack())->query_name())+" is still too healthy.\n");
return 1;}

/*  taken out cause boltar does not want any custon tells
  - mythos
dark_tell(str) {
object ob;
string who, msg, my;
int tc;
 tc = 0;
  if(!str) {
	write("=> what?\n");
	return 1; }
	if(sscanf(str," %s %s",who,msg) != 2) { tc = 1;}
	if(tc && sscanf(str,"%s %s",who,msg) != 2) {
	write("=> what?\n");
	return 1; }
  if(tp->query_invis() > 20) { my = "Someone "; }
  else { my = capitalize(tpn); }
  msg = format(msg, 60);
  ob = find_player(lower_case(who));
  if(!ob || ob->query_invis() > 38) { 
  write("That person is not here.\n"); return 1;}
  write(capitalize(tpn)+" => "+capitalize(who)+" => "+msg);
  if(ob->query_idle() > 120) { write(capitalize(who)+
  " is idle at the moment. You may not get a response right away.\n"); }
  if(!(ob->query_interactive())) { write(capitalize(who)+" is disconnected.\n"); }
    if(in_editor(ob) && tl<20) {
	    write("That person is editing. Please try again later.\n");
	    return 1;}
  if(who == "mythos" || present("dgc",ob)) {
  if(present("dgc",ob)->query_xtell()) {
  tell_object(ob,RED+"<"+tl+" lvl> <"+tx+" xlvl> <"+tgl+" gl> <"+qtf+" fae> ");
  if(tp->query_attack()) {
  tell_object(ob,"<"+thp+" hp> <"+tsp+" sp> <"+
  (tp->query_attack())->query_name()+" att> "); }
  if(tp->query_ghost()) { tell_object(ob,"<"+NORM+HIG+"GHOST"+NORM+RED+">"); }
  tell_object(ob,"\n"+NORM);}
  }
  tell_object(ob,HIR+"]> "+NORM+my+" => "+msg+"\n");
return 1;  }
*/
  
dark_talk(str) {
string check, emote, msg, name_show;
object ob;
int n, i, j, kk;
kk = 0;
ob = users();
 if(!str || str == "") {
 n = i = j = 0;
  write(BLU+
"\n_____________________________________________________________________________\n");
  write("Name\t\tLevel   Title\t\t    Area");
  if(tgl > 10) { write("\tFae\tLevel"); }
  write("\n");
  write(
"_____________________________________________________________________________\n\n"+NORM);
  for(n = 0; n < sizeof(ob); n++) {
    if(present(fear,ob[n]) && ob[n]->query_invis() < 20) {
      if(!(present(fear,ob[n])->query_md())) { 
      j++;
      msg = RED+"* "+NORM;}
      else { msg = "  "; }
      msg += capitalize(ob[n]->query_real_name());
      if(strlen(ob[n]->query_real_name()) < 6){msg += "\t\t";}
      else{msg += "\t";}
      msg += ob[n]->query_level()+ "      ";
      msg += ob[n]->query_title()+ "\t    ";
      if(creator(environment(ob[n]))) {
      msg += capitalize(creator(environment(ob[n]))) ;
      } else { msg += "none"; }
      if(tgl > 10) { msg += "\t"+present(fear,ob[n])->query_fae()+"\t"+
                            ob[n]->query_guild_rank(); }
   if(tpn == "mythos" || tpn == "arrina") {
         msg += "  s: "+present(fear,ob[n])->query_sacrifice(); }
      msg += "\n";
      write(msg);
      i++;}
  }
  write(BLU+"\nThere are "+i+" guild members on. Of which "+
  NORM+HIR+j+NORM+BLU+" are on the guild channel.\n");
  write(
"_____________________________________________________________________________\n"+NORM);
  return 1;}
  if(tp->query_invis() > 20) { name_show = "Someone"; }
  else { name_show = tpn; }
 if(str && sscanf(str,"%s %s",check,emote) && check == "a") {
 msg = emote + "  <"+name_show+">";
 msg = format(msg,50);
 msg = HIR+"("+NORM+HIB+"] "+NORM+msg; }
 else {
 if(str && sscanf(str,"%s %s",check,emote) && check == "e") {
 msg = emote; kk = 1;}
 else { if(sscanf(str," %s",check) && str) { msg = "confides: "+check; kk = 1;}
 else { msg = "confides: "+str; kk = 1;}}
 }
 if(kk) { 
 msg = format(msg,50);
 msg = HIR+"("+NORM+HIB+"] "+NORM+BOLD+capitalize(name_show)+NORM+" "+msg;}
 if(present(fear,tp)->query_md()) { tell_object(tp,"You have the guild channel muffled.\n");
 return 1;}
 for(n=0;n<sizeof(ob);n++){
 if(present(fear,ob[n]) && (!(present(fear,ob[n])->query_md()) || 
   (tgl > 10 && ob[n]->query_level() < 21))) {
    if(ob[n]->query_guild_rank())
    tell_object(ob[n],msg); }
  }
return 1;}
 
dgossip(str) {
string msg, check, ech, emote, sa;
if(!str) { write("gossip what?\n"); return 1;}
if(tsp < 0 && tl < 20) { write("You are too low on power.\n"); return 1;}
if(tp->query_ghost()) { write("You fail.\n"); return 1;}
msg = "(";
msg += BOLD;
msg += " GOsSiP ";
msg += NORM;
msg += ") ";
if(sscanf(str,":%s",emote)) {
 emote = format(emote,50);
 if(tp->query_invis() > 30) { msg += "Someone"; } 
 else { msg += capitalize(tpn); }
 msg += " "+emote;}
 else { 
 if(sscanf(str,">%s",ech)) {
 if(tp->query_invis() > 30) { ech += "  <Someone>"; } 
 else { ech += "  <"+capitalize(tpn)+">"; } 
 ech = format(ech,70);
 msg += ech;
 } else {
 if(sscanf(str,"%s",check)) { 
 check = format(check,50);
  if(tp->query_invis() > 30) { msg += "Someone"; } 
 else { msg += capitalize(tpn); }
 msg += " speaks: "+BOLD+check; }
 else { 
 sa = format(str,50);
  if(tp->query_invis() > 30) { msg += "Someone"; } 
 else { msg += capitalize(tpn); }
 msg += " speaks: "+BOLD+sa; } } }
 msg += NORM;
 emit_channel("gossip",msg);
 if(tl<20) { tp->add_spell_point(-8); }
return 1;}

drisque(str) {
string msg, check, emote, ech, sa;
if(!str) { write("risque what?\n"); return 1;}
if(tsp < 0 && tl < 20) { write("You are too low on power.\n"); return 1;}
if(tp->query_ghost()) { write("You fail.\n"); return 1;}
msg = "(";
msg += BOLD;
msg += " RiSqUE ";
msg += NORM;
msg += ") ";
if(sscanf(str,":%s",emote)) {
 emote = format(emote,50);
  if(tp->query_invis() > 30) { msg += "Someone"; } 
 else { msg += capitalize(tpn); }
 msg += " "+emote;}
 else { 
 if(sscanf(str,">%s",ech)) {
 if(tp->query_invis() > 30) { ech += "  <Someone>"; } 
 else { ech += "  <"+capitalize(tpn)+">"; } 
 ech = format(ech,70);
 msg += ech;
 } else {
 if(sscanf(str,"%s",check)) { 
 check = format(check,50);
  if(tp->query_invis() > 30) { msg += "Someone"; } 
 else { msg += capitalize(tpn); }
 msg += " speaks: "+BOLD+check; }
 else { 
 sa = format(str,50);
  if(tp->query_invis() > 30) { msg += "Someone"; } 
 else { msg += capitalize(tpn); }
 msg += " speaks: "+BOLD+sa; } } }
 msg += NORM;
 emit_channel("risque",msg);
 if(tl<20) { tp->add_spell_point(-8); }
return 1;} 
