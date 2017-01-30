id(str) { return str=="can" || str==short(); }

short() { return "A can of whoop ass"; }

whoop(str)
{
   object who;
   who = find_player(str);
   if(!who) return 0;
   if(in_editor(who))
      {
      write("That wiz is editting.  Leave em alone.\n");
      return 1;
   }
   write("The lid of the can opens up, and a little gnome jumps out.\n");
   write("He runs off, and you feel that somehow he's gonna whoop someone's ass.\n");
   tell_object(who,"A little gnome comes in.  Boy is he cute.\n");
   tell_object(who, "He tugs on your leg, so you bend down to see what he wants.\n");
   tell_object(who,"In a blurring frenzy, he runs around behind you as you bend over, and whoops\n");
   tell_object(who, "your ass, then runs away before you can catch him and teach him a lesson.\n");
   tell_object(who, "Ouch.  You ass is sore now from that whooping.\n");
   tell_room(environment(who),who->query_name()+" just got "+who->query_possessive()+" ass whooped by a gnome!\n");
   return 1;
}

help(str)
{
   if(id(str))
      {
      write("Type 'whoop <who>'.\n");
      return 1;
   }
   return 0;
}

long()
{
   write("This is a can of whoop ass.\n");
}

init()
{
   add_action("help","help");
   add_action("whoop","whoop");
}

get() { return 1; }
