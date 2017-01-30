#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TO this_object()
#define TPN this_player()->query_name()
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("cattle prod");
set_alias("prod");
set_short(HIY+"Solar powered"+NORM+" cattle prod");
set_long(
  "This solar-powered cattle prod was developed to make animals\n"+
  "mind their masters.  All one need do is [prod <name>] to get\n"+
  "the animals attention.  Near the end of the handle is a small\n"+
  "warning label that one should probably read.\n");
set_type("polearm");  /*  sword/knife/club/axe/bow/polearm  */
  set_class(6);
  set_weight(1);
  set_value(7000);
}

init() {
  ::init();
  move_object(clone_object("players/eurale/OBJ/cattle_prod"),
    environment(TO));
  destruct(TO);
  add_action("prod","prod");
  add_action("read","read");
}

prod(str) {
object ob;
if(!str) { write("Prod who?\n"); return 1; }
  ob = present(str,environment(TP));
if(!ob) ob = present(str,TP);

if(!ob) {
  write("You cannot prod "+capitalize(str)+" when they aren't present.\n");
  return 1; }

if(ob->is_player()) {
  write("You touch the prod to "+capitalize(str)+" and realize that\n"+
	"they are a player.  The prod sizzles in your hand reminding\n"+
	"you of your mistake....\n");
  say(TPN+" touches the prod to "+capitalize(str)+" by mistake.\n");
  write_file("/players/eurale/Wep/Prod_log",
    ctime(time())+"     "+TP->query_real_name()+" prodded "+
    capitalize(str)+".\n");
  TP->hit_player(80 + random(20));
  TP->add_spell_point(-20);
  return 1; }

if(ob->query_npc()) {
if(TP->query_money() < 100) {
  write("Your cattle prod fizzles and sputters...\n"); return 1; }
if(TP->query_spell_point() < 20) {
  write("Your cattle prod tingles slightly and stops...\n");
  return 1; }
if(TP->query_guild_name() == "rangers") {
  write("The prod spits and sputters and finally dies out.\n");
  return 1; }
  write("You reach out with the cattle prod and poke "+capitalize(str)+
	".\n");
  say(TPN+" pokes "+capitalize(str)+" with "+
    TP->query_possessive()+" cattle prod.\n");
  tell_room(environment(TP),
    capitalize(str)+" screams and turns to attack "+TPN+".\n");
  if(living(ob)) ob->attack_object(TP);
  call_other(TP,"add_money",-100);
  call_other(TP,"add_spell_point",-20);
  return 1; }
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "label" || str == "warning label") {
  write(HIR+"WARNING:"+NORM+"\n"+
	"This product is for use on NPCs only.  Any other use is\n"+
	"expressly forbidden and must be done at the users risk.\n"+
	"No reimbursement of any kind will be rendered if the\n"+
   "user misuses this tool.  You are responsible for your own\n"+
   "actions and I will not listen to whiners who did NOT read\n"+
   "and adhere to this warning.      -Eurale\n");
  return 1; }
}
