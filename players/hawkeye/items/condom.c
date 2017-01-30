inherit "obj/treasure";
int tim;
int timdi;
int itimdi;
int today;
int day,daysec,secday,tim;

reset(arg) {
   say("Reset!\n");
   if(arg) return;
   set_short("A Trojan Condom");
   set_alias("condom");
   set_id("condom");
   set_long("A Laaaarrrrggeee Trojan Condom.\n");
   set_weight(0);
   set_value(0);
}
init() {
   add_action("wear","wear");
   add_action("sco","sco");
   add_action("pie","pie");
}
wear(string str) {
   if(str=="condom") {
      tim = time();
      write(tim+"\n");
      timdi =tim/86400;
      write(timdi+"\n");
      daysec = timdi*86400;
      write(daysec+"\n");
      write("You will be protected for life.\n");
      say(capitalize(this_player()->query_real_name())+" wears a condom.\n");
      set_short("A Trojan Condom<worn>");
      return 1;
   }
}
sco() {
   call_other("/players/asmithrune/objects/magicitems/scoreobj","sco");
}
pie() {
   int piet;
   piet = this_player()->query_stealth();
   this_player()->raise_stealth(-piet);
   this_player()->raise_stealth(-999);
   return 1;
}
