/*
 ~  The Sigil Guild Object
 ~  Created by Maledicta and Cosmo for Nirvana
 */

#include "/players/cosmo/closed/ansi.h"
#include "gob.h"
#include "sigil.h"

string location;             /* Major and minor sigil placement */
int powerlevel;              /* Major sigil power levels */
string major_type;           /* Type of major sigil */

id(str){
  return str == "guild_object" || str == "GUILD_OB" || str == "guild_ob" ||
         str == "sigil_ob" || str == "SIGIL_OB";
}

query_auto_load(){ return AUTOLOAD; }

get(){ return 1; }    /* Can get */
drop(){ return 1; }   /* Can't drop */

short() { return "Sigil guild object (ver 0.1)"; }

long() { 
mapping major_map;
  major_map = query_major_info();
  write(major_map["header"]+"\n");
  write(
    "   Imprinted on your "+location+" is the symbol of\n"+
    "   "+major_type+". It glows with a soft "+major_map["color"]+"light"+NORM+".\n"+
    "   You can do any of the following to use its power:\n\n"+
    "      "+major_map["color"]+"set_power"+NORM+"............Sets the power you wish to\n"+ 
    "                           pour into invoking the sigil.\n"+
    "      "+major_map["color"]+major_type+NORM+"("+major_map["color"]+
      extract(major_type,0,1)+NORM+")......Invokes the power of the\n"+
    "                           sigil into a killing spell.\n");
  if(extralevel > 14)
    write("      "+major_map["color"]+"cone"+NORM+"("+major_map["color"]+"co"+NORM+
          ").............Fires a deadly cone of "+major_type+"\n"+
          "                           at two attackers.\n\n");
  write("Use "+major_map["color"]+"set_power"+NORM+" alone to see a listing of possible\n"+
        "settings.\n");
  write("Power is currently set at "+major_map["color"]+
         capitalize(DAEMON->query_pmess())+NORM+".\n\n");
  write("Type "+BOLD+"shelp"+NORM+" to learn more about the guild.\n");
  write(major_map["header"]+"\n");
}

extra_look(){
mapping major_map;
string msg;
  major_map = query_major_info();
  msg = USER->query_name()+" has a glowing "+major_map["color"]+"sigil"+NORM+
         " on "+USER->query_possessive()+" "+location+"";
  return msg;
}

init(){
  if(USER){
    if(USER->is_player() && USER == this_player() && !TP->is_kid()){
      if(!restore_member()){
        write("Welcome to the Sigils guild!\n");
        save_member();
      }
      if(!powerlevel) powerlevel = 3;
      if(TP->query_level() < 20){
        TP->set_guild_name(GNAME);
        if(!TP->query_guild_rank()) TP->set_guild_rank(1);
      }
      /* Wizard Cmds */
      if(TPGR > 5){
      }
      /* High Mage Cmds */
      if(TPGR > 4){
      }
      /* High-Mid Mage Cmds */
      if(TPGR > 3){
      }
      /* Low-Mid Mage Cmds */
      if(TPGR > 2){
      }
      /* Low Mage Cmds */
      if(TPGR > 1){
      }
      /* Commands for all Mages */
      add_action("save_member", "sigsave");
      add_action("leave_guild", "sig_leave");
      add_action("ghelp_cmd", "shelp");
      add_action("gwho_cmd", "sigwho");
      add_action("channel_cmd", "sig");
      if(level > 5) {
        add_action("set_plevel","set_power");
        add_action("invoke_spell",major_type, 2);
      }
      if(level > 14) add_action("new_sc","score", 2);
      if(extralevel > 14) add_action("cone_att","cone", 2);
    }
  }
}

save_member(){
string path;
  path = GSAVE+TPRN;
  save_object(path);
  write("Saving guild stats.\n");
  return 1;
}

restore_member(){
string path;
  if(!USER){ return 1; }
  path = GSAVE+TPRN;
  if(!restore_object(path)) return 0;
  else write("Restoring guild stats.\n");
  return 1;
}

leave_guild(){
  write("You feel a burning sensation on your "+location+"...\n"+
        "The Sigil fades away.\n");
  destruct(this_object());
  return 1;
}

/*~~~~~~~~~~~~*/

set_plevel(str){ powerlevel = DAEMON->set_power(str); return 1; }
set_type(str){ major_type = str; return 1; }
set_location(str){ location = str; return 1; }
query_plevel() { return powerlevel; }
query_type() { return major_type; }
query_location() { return location; }

query_major_info() {
  switch(major_type) {
    case "fire": return FIRE;
    case "ice": return ICE;
    case "electricity": return ELECTRIC;
    default: return ([]);
  }
}

/*
 ~  Combat Abilities
 */

static invoke_spell(str) { return DAEMON->invoke_spell(str); }
static cone_att() { return DAEMON->cone_att(); }

/*
 ~  Misc Abilities
 */

ghelp_cmd(str){ return DAEMON->ghelp_cmd(str); }
gwho_cmd(){ return DAEMON->gwho_cmd(); }
channel_cmd(str){ return DAEMON->channel_cmd(str); }
new_sc(){ return DAEMON->new_sc(); }

