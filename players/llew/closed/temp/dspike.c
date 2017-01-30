#include "/players/llew/closed/ansi.h"

inherit "obj/armor";

status wielded;
object wielded_by;
string *message_hit;
string notarmor;
status can_remove;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_alias("demonspike");
   set_name(HIR+"Demonspike "+NORM+"Armor");
   set_short(HIR+"Demonspike "+NORM+"Armor");
   set_value(5000);
   set_weight(7);
   set_ac(5);
   set_long("The "+HIR+"Demonspike "+NORM+"Armor pulses deeply with a strange red aura.\n"+
      "Black ooze seeps out of the long deadly spikes protruding\n"+
      "from the horrid plate, dripping with a splattering sizzle\n"+
      "as it hits the ground.  Such is the nature of the armor that\n"+
      "it requires the sacrifice of magical weapons to feed it's hatred\n"+
      "of all things arcane.\n");
   set_type("armor");
   set_save_flag(1);
   message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});
   notarmor="armor";
   can_remove=0;
}

id(str) {
   return 
      str == name ||
      str == alias ||
      str == type ||
      str == notarmor ||
      str == "notweapon";
}

short() { return short_desc; }


query_auto_load() {
   if(query_verb() && query_verb() == "quit") destruct(this_object());
}

init() {
   ::init();
   add_action("get_ob","get");
   add_action("get_ob","take");
   add_action("absorb","absorb");
   add_action("do_remove","Dropspike");
}

get_ob(str) {
   int x;
   int pick;
   object allinv;
   if(!str) {
      write("Get what?\n");
      return 1;
   }
   if(environment() == this_player()) return 0;
   pick=this_player()->pick_up(str);
   if(environment() != this_player()) return pick;
   allinv=all_inventory(this_player());
   for(x=0;x<sizeof(allinv);x++) {
      if(allinv[x]->query_type() == "armor" && allinv[x]->query_worn()) {
         write("As you lift the heavy "+HIR+"Demonspike "+NORM+"Armor it molds itself\n"+
            "to your body, destroying the "+allinv[x]->query_name()+".\n");
         destruct(allinv[x]);
      }
      if(allinv[x] && allinv[x]->armor_class() && allinv[x]->query_worn()) {
         write(capitalize(allinv[x]->query_name())+" is destroyed.\n");
         destruct(allinv[x]);
      }
   }
   command("wear demonspike",this_player());
   if(this_player()->query_weapon()) {
      write("The "+HIR+"Demonspike "+NORM+"Armor forces you to unwield your weapon.\n");
      (this_player()->query_weapon())->stopwield();
   }
   write("A blood rage fills your eyes and your mind with the desire to\n"+
         "kill anything living with your bare hands.\n");
   wielded_by=this_player();
   wielded=1;
   this_player()->wield(this_object(),1);
   notarmor="notarmor";
   can_remove=0;
   short_desc = HIR+"Demon "+NORM+BOLD+"["+NORM+RED+capitalize(this_player()->query_real_name())+NORM+BOLD+"]"+RED+" Spike"+NORM;
   call_out("demon_greet",10);
   return 1;
}

do_remove() {
   can_remove=1;
   command("drop demonspike", this_player());
   if(name != short_desc) {
      write("Destroying "+short_desc+".\n");
      destruct(this_object());
   }
   return 1;
}

long() {
   write(long_desc);
   if(this_player() && this_player()->query_level() > 19) write("\nWizard: remove with \"Dropspike\"\n");
}

drop(str) {
   if(this_player() && (this_player()->query_level() > 19 || can_remove)) {
      write("\n"+"Dropping "+short_desc+".\nPlayers cannot drop.\n");
      this_player()->stop_wielding(this_object(),1);
      wielded_by = 0;
      wielded = 0;
      this_player()->stop_wearing(this_object(),"armor", 1);
      return 0;
   }
   if(query_verb() && query_verb() == "quit") destruct(this_object());
   write("The "+HIR+"Demonspike "+NORM+"Armor won't let go.\n");
   return 1;
}

remove(str) {
   if(!id(str)) return 0;

   if(this_player() && (this_player()->query_level() > 19 || can_remove)) {
      ::remove(str);
   }
   write("The "+HIR+"Demonspike "+NORM+"Armor won't let go.\n");
   return 1;
}

take_off() {
   if(this_player() && (this_player()->query_level() > 19 || can_remove)) {
      ::take_off();
   }
}

weapon_class() {
   return 20;
}

hit(attacker) {
   /* Big neat emote things I'll put 
      in after I get the weapon working. */
}

weapon_breaks() { return 1; }
query_wear() { return worn; }

query_message_hit(tmp) {
  string *mess;
    mess = ({message_hit[1],message_hit[0]});
  if (tmp < 30) {
    mess = ({message_hit[3],message_hit[2]});
  }
  if (tmp < 20) {
    mess = ({message_hit[5],message_hit[4]});
  }
  if (tmp < 10) {
    mess = ({message_hit[7],message_hit[6]});
  }
  if (tmp < 5) {
    mess = ({message_hit[9],message_hit[8]});
  }
  if (tmp < 3) {
    mess = ({message_hit[11],message_hit[10]});
  }
  if (tmp == 1) {
    mess = ({message_hit[13],message_hit[12]});
  }
  return mess;
}

demon_greet() {
   if(wielded_by) {
      tell_object(wielded_by,"\n"+short_desc+" tells you: You are mine!  Now, together we destroy.\n"+
         "                      We are of one soul and I am the mind.\n");
      call_out("demon_greet2",10);
   }
}

demon_greet2() {
   if(wielded_by) {
      tell_object(wielded_by, "\n"+short_desc+" tells you: We must feed on the magic of weapons of destruction.\n");
      call_out("demon_greet3",6);
   }
}

demon_greet3() {
   if(wielded_by) {
      tell_object(wielded_by, "\n"+short_desc+" tells you: Find them and absorb them.  Make me strong...\n");
   }
}
