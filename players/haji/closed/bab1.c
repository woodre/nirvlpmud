object master;
int invis_set;
 
 
id(str) {
   return str == "bauble" || str == "bug";
}
 
get() {
   if (!master || this_player() == master) return 1;
   else {
      tell_object(master,
         "\nA familiar, high-pitched whine goes off in your head.\n");
      tell_object(master,
         " It's the alarm!\n");
      tell_object(master,call_other(this_player(),"query_name") +
         " has taken your bauble!\n");
      return 1;
   }
}
 
init() {
   add_action("squeeze"); add_verb("squeeze");
   add_action("cloak"); add_verb("cloak");
   add_action("talk_spy"); add_verb("say");
   add_action("talk_spy"); add_xverb("\"");
   add_action("talk_spy"); add_xverb("");
   add_action("talk_spy"); add_xverb("'");
   add_action("emote_spy"); add_verb("emote");
   add_action("emote_spy"); add_xverb(":");
}
 
query_weight() { return 1; }
 
query_value() { return 200; }
 
squeeze() {
   if (!master) master = this_player();
   if (this_player() != master) {
      write("It honks.\n");
      return 1;
   }
   else {
      write("   The bauble emits a high pitched whine....\n\n");
      write("The bauble is now YOURS.  It will be your ears and your\n");
      write("ears and your ears alone: the bauble will report to you\n");
      write("what is said in any room it happens to be in.  Of course\n");
      write("you'll have to drop it in the desired room yourself.\n");
      write("   Unfortunately, because it's so small, it can easily\n");
      write("be stolen.  It will, however, sound an alarm which only\n");
      write("you can hear to give you the opportunity to recover it\n");
      write("from the thief.\n");
      write("   You have one more security measure: the object has a\n");
      write("partial cloaking device.  It's not perfect however, and\n");
      write("other people can detect its presence if they know what\n");
      write("they're doing.\n");
      write("   Happy eavesdropping.\n");
      return 1;
   }
}
 
cloak(str) {
   if (this_player() != master) {
      write("Huh?\n");
      return 0;
   }
   else if (str == "on") {
      if (invis_set == 1) {
         write("Cloak already enabled.\n");
         return 1;
      }
      invis_set = 1;
      write("The bauble shimmers and fades away....\n");
      write("   Cloak enabled.\n");
      return 1;
   }
   else if (str == "off") {
      if (invis_set == 0) {
         write("Cloak already disabled\n");
         return 1;
      }
      invis_set = 0;
      write("The air itself coalsces into a solid object...\n");
      write("   Cloak disabled.\n");
      return 1;
   }
   else write("Use 'cloak on' or 'cloak off'.\n");
   return 1;
}
 
talk_spy(str) {
   string gabber, send_stuff;
   gabber = this_player() -> query_name();
   send_stuff = gabber + " says: " + str + "\n";
   say(send_stuff);
   write("You say: " + str + "\n");
   if (master && !present(master)) tell_object(master,"--> " + send_stuff);
   return 1;
}
 
emote_spy(str) {
   string ham, send_stuff;
   ham = this_player() -> query_name();
   send_stuff = ham + " " + str + "\n";
   say(send_stuff);
   write("You emote: " + send_stuff);
   if (master) tell_object(master, "--> " + send_stuff);
   return 1;
}
