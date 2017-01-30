get() {return 1;}
drop() { return  ; }
short() { return "A Marriage Tool"; }

long() { write("Syntax:  marry <name1> <name2>\n"); }

id(str) { return str == "marrytool"; }

init()
{
   add_action("marry","marry");}

fail()
{
   write("Dufus.\n");
   return 1;}

marry(str)
{
   string name1,name2;
   object who1,who2;
   if(sscanf(str,"%s %s",name1,name2)!=2)
   {
      return fail();
   }
   who1 = find_player(name1);
   who2 = find_player(name2); 
if(!who1 || !who2 ||
      present("wedding ring",who1) ||
      present("wedding ring",who2))
   {
      return fail();
   }
   return pronouncement(who1,who2,name1,name2);}

pronouncement(spouse_ob,player_ob,spouse,player) {
  object ring1, ring2;
  say(format(this_player()->query_name() + " says: Then by the power vested in me by " +
   "Bastion the archmage and the gods of Nirvana, I join you in the bonds " +
   "of matrimony.\n"));
  say(format(this_player()->query_name() + " says: Take these rings " +
   "as symbols of your enduring affection.\n"));
  ring1=clone_object("players/bastion/closed/ring");
  ring2=clone_object("players/bastion/closed/ring");
  ring1->set_spouse(spouse_ob->query_real_name());
  ring2->set_spouse(player_ob->query_real_name());
move_object(ring1,player_ob);
move_object(ring2,spouse_ob);
  log_file("bastion.marry", "Sado married " + spouse + " & " + player + " " +
   ctime() + "\n");
  return 1;
}

