#define FILE "/players/feldegast/closed/tool/invitation.c"
int do_cmd(string str) {
  object invite;
  object invitee;
  notify_fail("Usage: invite <player>\n");
  if(!str) return 0;
  invitee=find_player(str);
  if(!invitee) return 0;
  write("You invite "+capitalize(str)+" to "+environment(this_player())->short()+".\n");
  tell_object(invitee,this_player()->query_name()+" invites you to "+environment(this_player())->short()+".\n");
  invite=clone_object(FILE);
  invite->set_place(environment(this_player()));
  invite->set_inviter(this_player()->query_name());
  move_object(invite,invitee);
  return 1;
}
