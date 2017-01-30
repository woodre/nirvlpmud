/*
 *  The dream sending ability of the Succubi, version 2.0
 *
 */

dream(str)  {

  string target, mess;

  write("This command is no longer legal.\n- The Managment\n"); return 1;
  if(!str || sscanf(str, "%s %s", target, mess) !=2)  {
    write("Send a dream to who...?\n");
    return 1;
        }

   if(this_player()->query_invis()) { write("Please be visible to dream...\n"); return 1; }
  if(!find_player(lower_case(target)))  {
    write("That player is not within the realms of magic.\n");
    return 1;
        }
    if(find_player(lower_case(target))->query_invis()) {
   write("That person is not within the realms of magic.\n");
  return 1; }

/* added by wizardchild
   players shouldn't have extra tells to wizards
*/
  if(find_player(lower_case(target))->query_level() > 20) {
    write("That person cannot accept a dream.\n");
    return 1;
  }
  if(in_editor(TARGET))  {
    write("That person is editing and may not be sent a dream...\n");
    return 1;
        }
  if(this_player()->query_level() < 21 && find_player(lower_case(target))->query_tellblock()) {
    write("That person is currently blocking all tells.\n"); return 1; }

  tell_object(TARGET, "\n"+
    "* *  A dream like image from "+this_player()->query_name()+" floats"+
    " through your consciousness  * *\n"+
    "* *  "+mess+"  * *\n\n");

  write("* *  You send a dream to "+target+"  * *\n"+
    "* *  The dream was: "+mess+"  * *\n");

  return 1;
        }
