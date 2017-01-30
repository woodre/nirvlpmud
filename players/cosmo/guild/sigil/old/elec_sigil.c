#include "/players/maledicta/ansi.h"
#define MASTER "/players/cosmo/guild/sigil/sigil_master.c"
#define USER environment(this_object())
#define level USER->query_level()
#define extralevel USER->query_extra_level()

string location;
int powerlevel;

id(str){ return str == "sigil" || str == "mal_sigil_new" || str == "elec_sigil"; }

short(){ return 0; }

long(){ 
string pmess;
  write(HIY+"_._._._._._._._._._._._//////"+NORM+YEL+"|"+NORM+
        HIY+"\\\\\\\\\\\\_._._._._._._._._._._._"+NORM+"\n");
  write(
    "   Imprinted on your "+location+" is the symbol of Electrical\n"+
    "   Energy. It glows with a soft yellow light. You can\n"+
    "   do any of the following to use its power:\n\n"+
    "      "+HIY+"set_power"+NORM+"............Sets the power you wish to\n"+ 
    "                           pour into invoking the sigil.\n"+
    "      "+HIY+"electricity"+NORM+"("+HIY+"el"+NORM+")......Invokes the power of the\n"+
    "                           sigil into a killing spell.\n");
  if(USER->query_extra_level() > 14)
    write("      "+HIY+"cone"+NORM+"("+HIY+"co"+NORM+
          ").............Fires a deadly cone of Electricity\n"+
          "                           at two attackers.\n\n");
  write("Use "+HIY+"set_power"+NORM+" alone to see a listing of possible\n"+
        "settings.\nTo remove the sigil type: remove_sigil\n");
  pmess = MASTER->query_pmess();
  write("Power is currently set at "+HIY+capitalize(pmess)+NORM+".\n");
  write(HIY+"_._._._._._._._._._._._\\\\\\\\\\\\"+NORM+YEL+"|"+NORM+
        HIY+"//////_._._._._._._._._._._._"+NORM+"\n");
  return;
}

drop() {return 1;}
get() {return 0;}

query_auto_load(){ 
  return "/players/maledicta/closed/sigils/elec_sigil.c:"+location+"#"+powerlevel;
}

extra_look(){
  return USER->query_name()+" has a glowing "+HIY+"yellow"+NORM+
         " sigil on "+USER->query_possessive()+" "+location+"";
}

init_arg(str){
string locale;
int pl;
  sscanf(str,"%s#%d",locale,pl);
  location = locale;
  powerlevel = pl;
}

init(){
  if(!environment()) return;
  if(!powerlevel) powerlevel = 3;
  if(MASTER->guild_check()){
    tell_object(environment(),
      "Your guild powers interfere with the sigils...It vanishes.\n");
    destruct(this_object());
    return 1;
  }
  add_action("power_set","set_power");
  add_action("invoke_elec","electricity");
  add_action("invoke_elec","el");
  add_action("cone_att","cone");
  add_action("cone_att","co");
  add_action("ditch_it","remove_sigil");
  if(level > 14) add_action("new_sc","score", 2);
}

power_set(str){ powerlevel = MASTER->power_set(str); return 1; }
ditch_it(){ MASTER->ditch_it(); return 1; }
new_sc(){ MASTER->new_sc(); return 1; }
static invoke_elec(str) { MASTER->invoke_spell(str); return 1; }
static cone_att() { MASTER->cone_att(); return 1; }

set_slocale(str){ location = str; return 1; }

/**************** Test Functions only ******************/
set_num(int i){ 
  powerlevel = i;
  return 1;
}

set_locale(str){
  tell_object(USER, "location set to "+str+".\n");
  location = str;
  return 1;
}
/********************************************************/

/* Info used by Master object */
query_plevel() { return powerlevel; }
query_location() { return location; }
query_type() { return "electric"; }
