/*
 * proposal_ob.c  -  object to let a person respond to a proposal without
 *                the abuse potential of input_to
 */
 
inherit "obj/clean";
#define TP this_player()
#define TPN this_player()->query_name()
object proposer,ring_ob;

short() { return 0; }
drop() { return 1; }
id(str) { return str=="proposal_ob"; }
set_proposer(object ob1,object ob2) {
  proposer=ob1;
  ring_ob=ob2;
  call_out("end_proposal",120);
}
end_proposal() {
  object env;
  if((env=environment(this_object()))) {
    tell_object(env,"The time for the proposal has run out.\n");
    if(proposer)
      tell_object(proposer,"The time for the proposal has run out.\n");
  }
  destruct(this_object());
  return;
}
init() {
  add_action("accept_proposal","accept_proposal");
}
accept_proposal() {
  if(!proposer) {
    write("Your suitor has vanished.\n");
    return 1;
  }
  if(!ring_ob) {
    write("The ring has vanished somehow.\n");
    return 1;
  }
  write("You accept "+proposer->query_name()+"'s proposal of marriage.\n");
  tell_object(proposer,TPN+" has accepted your offer of marriage.\n");
  ring_ob->proposal_accepted(proposer,TP);
  destruct(this_object());
  return 1;
}
