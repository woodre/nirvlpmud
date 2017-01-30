inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/RandomMove.c"


reset(arg)
{
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("a tornado");
   set_race("tornado");
   set_short("A tornado (spinning madly)");
   set_level(15);
   set_hp(225);
   set_al(-670);
   set_wc(20);
   set_ac(12);
   set_chance(10);
   set_spell_dam(21);
   set_spell_mess1("The powerful wind knocks something into your stomach! Ooof!");
   set_spell_mess2("A kitchen sink smashes into your head, producing pain.");
   set_chat_chance(20);
   load_chat("The tornado touches down at no where in particular.\n");
   load_chat("The whistling 'Screeeeeeee!' of the wind makes you want to vomit.\n");
   load_chat("A current surge produced by the tornado smacks you in the head! Ouch!\n");
   gold=clone_object("players/mizan/closed/random-item");
   move_object(gold,this_object());
   
   remove_call_out("ingestion");
   call_out("ingestion", random(30));
}

init() 
{
   add_action("get_prev","get");
   add_action("get_prev","take");
   ::init();
}

long() 
{
   if(this_player() && environment(this_player()) == this_object()) 
   {
      write("You are stuck inside the tornado, whirling around with countless\n"+
         "other helpless objects. Quite fearsome, don't you think?\n");
   } else
      write("This is a big, nasty-looking storm. It would be quite bad if\n"+
      "you were somehow sucked into it. Don't linger too long around it!\n"+
      "If you get sucked in don't say I didnt warn you!\n");
}

ingestion() {
   object ob;
   if(!environment(this_object())) { remove_call_out("ingestion"); return 1; }
   ob=first_inventory(environment(this_object()));
   while(ob) {
      object oc;
      oc=ob;
      ob=next_inventory(ob);
      if(living(oc))
         if(living(oc) && 1 == random(5) && oc->query_level() > 5 && oc->query_level() < 21 && oc != this_object()) {
         tell_object(oc, "You are sucked up by the tornado!\n");
         move_object(oc,this_object());
         say((oc->query_name())+" is sucked into the tornado!\n");
         call_out("digestion", random(16));
         return 1;
         }
   }
   
   remove_call_out("ingestion");
   call_out("ingestion", random(10));
   say("The tornado spins out of control!\n");
   return 1;
}

digestion() 
{
   object ob2;
   ob2=first_inventory(this_object());
   while(ob2) {
      object oc2;
      oc2=ob2;
      ob2=next_inventory(ob2);
      if(living(oc2)) {
         if(1 == random(5)) {
            string testo;
            
            if(ob2->is_player())
            write_file("/players/mizan/logs/CREATURE_DIGESTION", 
               "[" + ctime() + "] " + ob2->query_name() + " was flung out of the tornado!\n");
               
            say((oc2->query_name())+" is rocketed clear across the ether-muck!\n" +
               say(oc2->query_name()) + " screams: Aiiiiiiiieeeeee!!!\n");
            testo=call_other("players/mizan/closed/RandomRoomDM.c", "one_random");
            oc2->move_player("screaming and kicking#players/mizan/etheriel/ROOMS/" + testo);
         } 
         say((oc2->query_name())+" is flung into the wild abyss of the unknown.\n");
         
         if(oc2->is_player())
         write_file("/players/mizan/logs/CREATURE_DIGESTION", 
           "[" + ctime() + "] " + ob2->query_name() + " was eaten by a tornado.\n");
         if(oc2) call_other(oc2, "save_me");
         if(oc2) call_other(oc2, "quit");
         if(oc2) call_other(oc2, "do_quit");
         }
   }
   say("The tornado whirrs violently.\n");
   return 1;
}

get_prev(str) {
   if(!str || !present(this_player(), this_object())) return 0;
   write("You cannot get "+str+"!\n");
   return 1;
}

realm() { return "NT"; }

query_realm() { return "NT"; }
