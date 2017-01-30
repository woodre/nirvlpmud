/* The heal part of this object was approved by Boltar on 6-26-96. */


#include "/players/llew/closed/ansi.h"
inherit "obj/treasure";

int size;
int anger;

reset(arg) {
   if(arg) return;
   anger=0;
   size=1;
   set_id("crystal fragment");
   set_alias("fragment");
   set_weight(1);
   set_save_flag(1);
   switch(random(3)) {
   case 0:
      set_short("A glowing " + HIC + "blue" + NORM + " crystal fragment");
      set_value(400);
      set_info("blue");
      break;
   case 1:
      set_short("A glowing " + HIG + "green" + NORM + " crystal fragment");
      set_value(0);
      set_info("green");
      break;
   case 2:
      set_short("A glowing " + RED + "red" + NORM + " crystal fragment");
      set_value(0);
      set_info("red");
      break;
   }
}

long() {
   string long_desc;
   switch(anger) {
      case 0: long_desc="The demon looks irritated.\n"; break;
      case 1: long_desc="The demon looks irritated.\n"; break;
      case 2: long_desc="The demon looks perturbed.\n"; break;
      case 3: long_desc="The demon looks a little aggressive.\n"; break;
      case 4: long_desc="The demon is snorting dangerously.\n"; break;
      case 5: long_desc="The demon fumes in anger.\n"; break;
      case 6: long_desc="The demon froths and rampages maniacally inside its confinemnt.\n"; break;
      case 7: long_desc="The demon is throwing itself against the crystal cage.\n"; break;
      case 8: long_desc="The demon is enraged beyond all reckoning.\nThe crystal has cracks running its length.\n"; break;
      case 9: long_desc="The demon is Fury incarnate.\n"; break;
   }
   if(query_info() == "blue") {
      if(size<5) {write("The blue crystal warms your whole body as you hold it in your hands.\n"+
         "It looks like a smaller portion of a larger crystal.\n"); return;}
      else {write("The crystal warms your whole body as you hold it in your hands.\n"+
         "It glows brightly against the darkness, and may be able to banish it.\n"); return;}
   }
   if(size==1 && query_info() == "red") {
      write("The red crystal pulsates with evil.\n"+
      "It looks like a smaller portion of a larger crystal.\n"); return;
   }
   if(size==2 && query_info() == "red") {
      write("A dull red glow pulsates from the center of the\n"+
      "red crystal.  Inside a demon resides, trapped in torturous\n"+
      "bondage.  It's ravenous look towards you shivers your soul.\n"+
      "To touch it is to gain it's power, and it's price.\n"+long_desc); return;
   }
   if(size < 3 && query_info() == "green") {
      write("The green crystal sparkles with energy.\n"+
      "It looks like a smaller portion of a larger crystal.\n"); return; }
   if(size==3 && query_info() == "green") {
      write("The green crystal glows with warm light.  Sparkles of life giving\n"+
      "energy twinkle inside.  Hold it to gain it's life, and to set it free.\n");
      return;
   }
}

init() {
   object *frag;
   int x;
   add_action("banish","banish");
   add_action("touch","touch");
   add_action("hold","hold");
   if(size != 5 && query_info() == "blue") {
      frag=all_inventory(environment(this_object()));
      for(x=0;sizeof(frag)>x;x++) {
         if(frag[x]->query_info() == "blue" && frag[x] != this_object() && frag[x]->query_size() != 5) {
            size += frag[x]->query_size();
            say("The two parts of the blue crystal meld together.\n");
            write("The two parts of the blue crystal meld together.\n");
            destruct(frag[x]);
            set_value(size * 300);
            if(size>4) {
               size=5;
               say(HIC+"The crystal shines brightly as it it made whole again.\n"+NORM);
               write(HIC+"The crystal shines brightly as it is made whole again.\n"+NORM);
               set_short("A small " + HIC + "blue" + NORM + " crystal");
               set_alias("crystal");
            }
         }
      }
   }
   if(size != 2 && query_info() == "red") {
      frag=all_inventory(environment(this_object()));
      for(x=0;sizeof(frag)>x;x++) {
         if(frag[x]->query_info() == "red" && frag[x] != this_object() && frag[x]->query_size() != 2) {
            size = 2;
            say("The two parts of the red crystal meld together.\n");
            write("The two parts of the red crystal meld together.\n");
            destruct(frag[x]);
            say(RED+"A great flash burns your eyes as the red crystal becomes whole.\n"+NORM);
            write(RED+"A great flash burns your eyes as the red crystal becomes whole.\n"+NORM);
            set_short("A small " + RED + "red" + NORM + " crystal");
            set_alias("crystal");
         }
      }
   }
   if(size != 3 && query_info() == "green") {
      frag=all_inventory(environment(this_object()));
      for(x=0;sizeof(frag)>x;x++) {
         if(frag[x]->query_info() == "green" && frag[x] != this_object() && frag[x]->query_size() != 3) {
            size += frag[x]->query_size();
            say("The two parts of the green crystal meld together.\n");
            write("The two parts of the green crystal meld together.\n");
            destruct(frag[x]);
            if(size > 2) {
               size=3;
               say(HIG+"Green light blends to form an aura of life.\n"+NORM);
               write(HIG+"Green light blends to form an aura of life.\n"+NORM);
               set_short("A small " + HIG + "green" + NORM + " crystal");
               set_alias("crystal");
            }
         }
      }
   }
}

query_size() { return size; }

banish(str) {
   if(size != 5 || query_info() != "blue") {return 0;}
   if(this_player()->query_name() == "some mist") return deadnoworky("blue");
   if(!str || str != "darkness") {
      notify_fail("Banish what?\n");
      return 0;
   }
   if(!environment(this_player())->dark()) {
      write("The crystal has no effect on any darkness here.\n");
      return 1;
   }
   write("You carefully drop the bright crystal into the engulfing darkness.\n"+
      "Light blasts outward blinding you!\n\n"+
      "The darkness is gone.  Musical energy fills the air all around.\n"+
      "In the place of the darkness floats a long blue crystal sword.\n");
   say(this_player()->query_name()+" carefully drops the bright crystal into the engulfing darkness.\n"+
      "Light blasts outward blinding you!\n\n"+
      "The darkness is gone.  Musical energy fills the air all around.\n");
   move_object(clone_object("/players/llew/closed/crystal/crystal_sword.c"),environment(this_player()));
   environment(this_player())->new_long();
   call_out("des",1);
   return 1;
}

touch(str) {
   object demon,life;
   if(query_info() != "red" || size != 2 || str != "crystal" || !str) return 0;
   if(this_player()->query_name() == "some mist") return deadnoworky("red");
   if(anger==10 || random(80) <= anger) {
      write("The crystal cracks violently and is flung from your hands!\n");
      say("A red glowing crystal is flung from the hands of "+this_player()->query_name()+".\n");
      tell_room(environment(this_player()),"Red light explodes in front of you! Crystal fragments cut into your skin.\n");
      tell_room(environment(this_player()),RED+"\n"+pad("",25)+pad("",30,'~')+"\n"+
            pad("",20)+pad("",15,'~')+pad("",10)+pad("",15,'~')+"\n");
      tell_room(environment(this_player()),pad("",17)+pad("",13,'~')+pad("",5)+HIR+pad("",10,'*')+NORM+RED+pad("",5)+pad("",13,'~')+"\n"+
            pad("",17)+pad("",13,'~')+pad("",5)+HIR+pad("",10,'*')+NORM+RED+pad("",5)+pad("",13,'~')+"\n");
      tell_room(environment(this_player()),pad("",20)+pad("",15,'~')+pad("",10)+pad("",15,'~')+"\n"+
		pad("",25)+pad("",30,'~')+"\n\n\n"+NORM);
      tell_room(environment(this_player()),"A Xetra steps from the light and looks very very upset.\n");
      write("Xetra tells you: Britc tek dri, htuman!  Now you die...\n");
      demon=clone_object("/players/llew/closed/crystal/frag_demon.c");
      transfer(demon,environment(this_player()));
      demon->summoner(this_player());
      call_out("des",1);
      write_file("/players/llew/closed/logs/frag_demon_summon",this_player()->query_name()+
         " level "+this_player()->query_level()+", calls a demon at:  "+ctime(time())+"\n");
      return 1;
   }
   write("You touch the crystal.  The light dims and the pulsing slows.\n");
   write("Your mind is filled with powerful energies, racing to break free.\n");
   say(this_player()->query_name()+" touches a red glowing crystal.\n");
   {
      int spellheal;
      spellheal = this_player()->query_msp()/2;
      if(this_player()->query_sp() > spellheal) spellheal = (spellheal *2) - this_player()->query_sp();
      this_player()->add_spell_point(spellheal);
   }
   life=clone_object("/players/llew/closed/crystal/frag_life.c");
   transfer(life,this_player());
   life->origin(this_object());
   anger++;
   if(anger*5 > random(100)) {
      write("The light of the crystal fades.\nIt crumbles to dust and drifts away.\n");
      call_out("des",1);
   }
   return 1;
}

hold(str) {
   object life;
   if(! str || str != "crystal" || size != 3 || query_info() != "green") {return 0;}
   if(this_player()->query_name() == "some mist") return deadnoworky("green");
   if(!random(33)) {
      write("The green crystal dims and crumbles.\n");
      call_out("des",1);
      return 1;
   }
   write("You hold the glowing warmth in your hands.  The crystal cracks open in your hand.\n"+
      "Green light floats free, passing through your body before dissipating in the air.\n");
      if(this_player()->query_attrib("sta") < 1) return 1;
      if(!random(10)) {
         write(HIG);
         this_player()->raise_stamina(-1);
         write(NORM);
      }
      if(this_player()->query_sp() < 25) {
         write("\nThe green glow about your body fades quickly.\n");
         this_player()->add_spell_point(-this_player()->query_sp());
         call_out("des",1);
         return 1;
      }
      this_player()->add_spell_point(-25);
      write("You feel your body's healing process begin to increase.\n");  
   say(this_player()->query_name()+" holds a green crystal in "+this_player()->query_possessive()+
      " hands.\nGreen light breaks free to envelop "+this_player()->query_possessive()+" body, then slowly\n"+
      "dissipates in the air.\n");
   life=clone_object("/players/llew/closed/crystal/regen.c");
   transfer(life,this_player());
   life->caster(this_player());
   call_out("des",1);
   return 1;
}

des() {
   destruct(this_object());
}

deadnoworky(color) {
   write("Your etheriel appendage passes directly through the "+color+" crystal.\n");
   return 1;
}

