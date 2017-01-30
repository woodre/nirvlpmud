#include "/players/quicksilver/666/include/std.h"

inherit MONSTER;

reset(arg) {
   if(!arg) {
      set_name("trafaelwyr");
      set_alias("hermit");
      set_short("Trafaelwyr the hermit");
      set_long("Trafaelwyr smiles with compassion as he realizes you are an adventurer.  He\n"+
         "appears to be a resident of these woods--quite the typical hermit.  His is a\n"+
         "simple life of being truly in tune with nature and himself.  By his friendly\n"+
         "smile, you can tell he would be willing to assist you.\n");
      set_race("human");
      set_wc(22);
      set_ac(30);
      set_hp(1000);
      set_level(20);
      set_talking_object(TO);
	  enable_commands();
      set_living_name("trafaelwyr");
   }
   ::reset(arg);
   return 1;
}

init() {
     ::init();
}

catch_msg(str) {
     string tn, temp;
     object tp;
     
     if((sscanf(str, "%s %s", tn, temp) == 2) && (tp = find_player(lower_case(tn)))) {
          if(temp[0..6] == "arrives") {
               if(!other_living(tp)) memote(capitalize(name) + " glances up as you enter his home.", 3);
               msay("Welcome, " + capitalize(tp->query_name()) + "." + (other_living(tp) ? "\n" : "  I have been expecting you.\n"), (other_living(tp) * 2) + 6);
               return 1;
          }
          if((temp[0..4] == "says:") || (temp[0..4] == "asks:")) {
               if(sscanf(str, "%shi%s", tn, temp) || sscanf(str, "%sHi%s", tn, temp) || sscanf(str, "%shello%s", tn, temp) || sscanf(str, "%sHello%s", tn, temp)) {
                    command("say Greetings, " + capitalize(tp->query_name()) + ".  How may I help you?\n", TO);
                    return 1;
               }
               if(sscanf(str, "%shelp%s", tn, temp) || sscanf(str, "%sHelp%s", tn, temp) || sscanf(str, "%stree%s", tn, temp) || sscanf(str, "%sovergrow%s", tn, temp) || sscanf(str, "%strap%s", tn, temp)) {
                    memote(capitalize(name) + "'s eyes brighten and consider you carefully.\n", 4);
                    msay("So, you are new to these parts?  " + ((tp->query_level() > 17) ? 
                      "There is probably little here in the forest that would be of interest to you.  Niurin, possibly...  You would never find me going to that vile place, though."
                      : "You should probably stick to the forest, but use caution.  If you are in need of equipment, you could travel to Niurin, but it is a very rough place.") + "\n", 10);
                    if(!present("machete", tp)) {
                         memote(capitalize(name) + " turns to rummage through some items in a large chest.\n", 14);
                         msay("Here, take this machete.  It may prove useful out in the forest.\n", 30);
                         call_out("give_machete", 31, tp);
                    }
                    return 1;
               }
          }
          
     }
     return 1;
}

give_machete(ob) {
     object machete;
     
     if(environment(ob) != ENVTO) return;
     machete = clone_object(WEAPON_DIR + "machete");
     if(transfer(machete, ob)) {
          msay("Hmm, it seems you are unable to carry it.  I will put it here on the table for you to pick up later.\n");
          move_object(machete, ENVTO);
     } else memote(capitalize(name) + " hands the machete to you.\n");
     return 1;
}
