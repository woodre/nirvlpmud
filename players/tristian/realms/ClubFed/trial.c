guilty()
{
  tell_room(this_object(), 
  "The judge bangs down his gavel and says, 'So entered the plea of Guilty'\n");
  
  call_out("guilty_2", 2, this_player());
}

guilty_2(object ob)
{
  tell_room(this_object(),
    "I will now pass sentence on "+ob->query_name()+".\n"+
    "You shall serve 5 years in the Minimum Security Prison known\n"+
    "as 'Club Fed'\n");
  tell_room(this_object(),
    "The bailiff comes over to "+ob->query_name()+" and hauls "+
    objective(ob)+"off to serve "+possessive(ob)+" sentence.\n",
    ({ ob }));
  tell_object(ob,
    "The bailiff comes over to you and hauls you off to serve your sentence.\n");
  move_object(ob,RMS+"Cell_A_01.c");
  command("look",ob); 
  return 1;
}
