/*  This is one of three files related to an autloading engagement ring.
 *  this one does not autoload, it merely allows the player to propose
 * to someone.  That's done using an invis object that dests iteself
 * after two minutes.  If the person accepts, ering.c is cloned, and does
 * autoload, using init_arg() to keep track of who the intended is.
 * As far as I know, this object is finished now.
 */
inherit "obj/treasure";
#define ERING_PATH "players/illarion/wedding/ering"
#define PROPOSE "players/illarion/wedding/proposal_ob"
#include "/players/illarion/dfns.h"

object worn_by;

reset(int arg) {
  if(arg) return;
  
  set_id("ring");
  set_short("A "+BOLD+"diamond"+NORM+" engagement ring");
  set_long(
"A slim silver band set with a beautifully sparkling diamond, a\n"+
"proclimation that the wearer is someone's beloved and intended in\n"+
"marriage.  To ask for your beloved's hand, use propose <name>.\n");
}
drop(int s) {
  return 1;
}
init() {
  ::init();
  add_action("cmd_wear","wear");
  add_action("cmd_remove","remove");
  add_action("cmd_propose","propose");
}
void check_wear() {
  object ob;
  if(!worn_by) return;
  if(!(ob=environment(this_object())) || ob!=worn_by) {
    worn_by=0;
    return;
  }
}
short() {
  check_wear();
  return ::short()+(worn_by?" (worn)":"");
}
cmd_wear(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Wear what?\n");
  check_wear();
  if(worn_by) {
    write("You already wear it!\n");
    return 1;
  }
  write("You slip on the engagement ring.\n");
  say(TPN+" slips on an engagement ring.\n");
  worn_by=TP;
  return 1;
}
cmd_remove(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Remove what?\n");
  check_wear();
  if(!worn_by) {
    write("You aren't wearing it.\n");
    return 1;
  }
  write("You slip off the engagement ring.\n");
  say(TPN+" takes off an engagement ring!\n");
  worn_by=0;
  return 1;
}
cmd_propose(string str) {
  object ob,proposee;
  if(!str || !(proposee=present(str,environment(TP))))
    FAIL("Propose to who?\n");
  if(!proposee->query_real_name())
    FAIL("That is not a player.\n");
  write("You ask "+proposee->query_name()+" for "+proposee->query_possessive()+
        " hand in marriage.\n");
  tell_object(proposee,TPN+" has asked for your hand in marriage.\n"+
              "To accept and wear "+TP->query_possessive()+" ring, type "+
              "accept_proposal.\n");
  say(TPN+" asks "+proposee->query_name()+" for "+proposee->query_possessive()
         +" hand in marriage.\n");
  ob=clone_object(PROPOSE);
  ob->set_proposer(TP,this_object());
  move_object(ob,proposee);
  return 1;
}
proposal_accepted(object proposer,object proposee) {
  object env,ob;
  if(!proposer || !proposee) return;
  if(!(env=environment(proposer))) return;
  if(!present(proposee,env)) {
    tell_object(proposee,"You must be in the same room.\n");
    tell_object(proposer,"You must be in the same room.\n");
    return;
  }
  tell_object(proposer,
    "You slip the ring on "+proposee->query_name()+"'s finger.\n");
  tell_object(proposee,
    proposer->query_name()+" slips an enagagement ring on your finger.\n");
  tell_room(env,
    proposer->query_name()+" slips an enagement ring onto "+
    proposee->query_name()+"'s finger.\n",({TP,proposee}));
  ob=clone_object(ERING_PATH);
  ob->set_fiance(proposer->query_real_name(),proposee);
  move_object(ob,proposee);
  destruct(this_object());
  return 1;
}
