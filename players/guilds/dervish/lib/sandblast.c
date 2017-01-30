#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
  object shld, ob;
  int obwc, obac;
  int saved_ac;
  int modifier;

  modifier = (int)User->query_extra_level();
  modifier = modifier / 20;
  if(User->query_level() < 19  || User->query_extra_level() < 10) {
    write("You are not high enough level to sandblast yet.\n");
    return 1; }
  if(User->query_ghost()) {
    write("You cannot sandblast while you are a ghost.\n");
    return 1; }
  if(User->query_sp() < 70) {
    write("You lack the energy to sandblast.\n"); return 1; }
  if(User->query_attrib("pie") < 20) {
    write("You lack in faith.\n"); return 1; }
  if(environment(User)->query_no_fight()) {
    write("You can't use that ability in this room.\n"); return 1; }
  if(PO->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
  if(!str && !User->query_attack()) { write("Sandblast what?\n"); return 1; }
  if(!str) ob = (object)User->query_attack();
  if(!ob) ob = present(str, environment(User));
  if(!ob || !present(ob, environment(User)) ) {
    write("You can't see "+str+".\n"); return 1; }
  if(!living(ob)) {
    write("You cannot sandblast inanimate objects.\n"); return 1; }
  if(ob->is_player()) {
    write("You cannot sandblast players.\n"); return 1; }
/* Prevent players from triggering the spell on a monster that's
 * below 15% health and already fighting someone else.
 * Illarion 10/30/02
 */
  if(ob) if(!PO->check_dervish_attack(ob)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  write(BOLD+YELLOW+"\tYou shudder with the power of the Sand!\n"+
        "\tStreams of glowing particles whip into "+
        ob->query_name()+"!\n\n"+OFF+OFF);
  say("\t"+BOLD+YELLOW+User->query_name()+" shudders with power!\n"+
            "\tStreams of glowing particles whip into "+
            ob->query_name()+"!\n\n"+OFF+OFF);
  ob->hit_player(random(40) + 30, "other|earth");
  /* PO->set_spell_delay(random(50)+20);
  */
/*
 if(ob && !present("derv_ac_mod", ob))
 {
  ob->set_ac(ob->query_ac()-(saved_ac=(User->query_extra_level()/20)));
 }
*/
  PO->set_spell_delay(120-
   ((int)User->query_attrib("wil"))
   -((int)User->query_attrib("pie"))
   -((int)User->query_attrib("mag"))
   -((int)User->query_extra_level()/4));
  User->add_spell_point(-(random(40)+30));
/* Added by Illarion to fix a death bug 10/30/02
 */
  if(ob)
    if(!User->query_attack()) User->attack_object(ob);
  if(ob)
    if(!ob->query_attack()) ob->attack_object(User);
 if(ob)
 if(!present("derv_ac_mod", ob))
 {
  shld=clone_object("/players/guilds/dervish/objects/verte_sb");
  shld->set_dose(modifier);
  move_object(shld, ob);
 }
  return 1; }