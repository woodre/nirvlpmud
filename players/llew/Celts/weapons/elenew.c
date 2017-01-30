#include "/players/llew/closed/ansi.h"
#define user environment(this_object())
#define name name_of_weapon

inherit "obj/weapon";
int retdam;
string atta_name;

reset(arg) {
   ::reset(arg);
   if(arg)return;
   set_id("staff");
   set_name(HIY+"Elemental Staff"+NORM);
   set_class(18);
   set_weight(3);
   set_value(3000);
   set_alt_name("staff");
   set_hit_func(this_object());
   set_alias("elemental staff");
   set_short(HIY+"Elemental Staff"+NORM);
   set_long("A long oak staff which controls the elements.\n"+
                "Intense runes shine forth brightly.  If intelligent\n"+
                "enough, you may be able to control the elements.\n");
   set_info("This staff belongs to a master Druid of the forest of\n"+
               "Gwynedd.  Much control of your physical, mental,\n"+
               "and spiritual environment is needed to master the\n"+
               "forces of the weapon.\n");
}

weapon_hit(attacker) {
   int whack;
   int Int;
   atta_name=attacker->query_name();
   if(random(100) > 64 ) {
      if(user->query_real_name() == "druid" || user->query_attrib("int") > random(23)) {
         switch(random(13)) {
            case 0:  FIRE(); break;
            case 1:  ICE(); break;
            case 2:  EARTH(); break;
            case 3:  ELECTRICITY(); break;
            case 4:  AIR(); break;
            case 5:  CHAOS(); break;
            case 6:  LAW(); break;
            case 7:  TIME(); break;
            case 8:  LIGHT(); break;
            case 9:  DARKNESS(); break;
            case 10:  WATER(); break;
            case 11:  STEAM();  break;
            case 12:  ACID(); break;
         }

      }
      else {
         write("You fail to control the "+name+"!!\nYour mental power is drained.\n");
         Int=random(8)+random(8)+random(8)+3;
         if(user->query_spell_point() < Int) {
            write("Pain pounds into your skull!\nForces of great power tear at your mind!\n");
            write(HIR);
            user->raise_intelligence(-1);
            write(NORM);
            write("The backlash flings the staff from your hands!\n");
            command("drop elemental staff",user);
            return 0;
         }
         user->add_spell_point(-Int);
         user->hit_player(Int/2);
         return 0;
      }
      retdam+=10;
      if(user->query_spell_point() < retdam/4) {
         write("The "+name+" saps at your life.\n");
         user->hit_player((retdam/3)-user->query_spell_point());
         user->add_spell_point(-user->query_spell_point());
      }
      if(attacker->query_hp() < retdam) attacker->heal_self(-attacker->query_hp());
      else attacker->hit_player(retdam);
      user->add_spell_point(retdam/4);
      return 7;
   }
   return 0;
}



FIRE() {
   write(HIR+"FIRE "+NORM+"courses down the "+name+" and engulfs "+atta_name+
      "\nThe stench of burning flesh makes you gag.\n");
   say(HIR+"FIRE "+NORM+"courses down the "+name+"and engulfs "+atta_name+
      "\nThe stench of burning flesh makes you gag.\n");
   retdam=15;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("Some of the flames burn your hands.\n");
      user->hit_player(retdam);
   }
}

ICE() {
   write("The "+name+"quviers for a moment as "+HIB+"ICE"+NORM+" shoots forward"+
      "to impale "+atta_name+".  "+atta_name+" bleeds from numerous cuts.\n");
   say("The "+name+"quviers for a moment as "+HIB+"ICE"+NORM+" shoots forward"+
      "to impale "+atta_name+".  "+atta_name+" bleeds from numerous cuts.\n");
   retdam=10;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("Some of the shards veer towards you.\n");
      user->hit_player(retdam);
   }

}

EARTH() {
   write("The "+GRN+"EARTH"+NORM+" quakes beneath "+atta_name+" at the calling of the "+
      name+".\n"+atta_name+" fights to gain recovery.\n");
   say("The "+GRN+"EARTH"+NORM+" quakes beneath "+atta_name+" at the calling of the "+
      name+".\n"+atta_name+" fights to gain recovery.\n");
   retdam=12;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("The ground rumbles beneath your feet.\n");
      user->hit_player(retdam);
   }

}

ELECTRICITY() {
   write("Energy pulses through the "+name+" as intensely blinding "+HIY+"LIGHTNING"+NORM+
      " chars "+atta_name+".\n");
   say("Energy pulses through the "+name+" as intensely blinding "+HIY+"LIGHTNING"+NORM+
      " chars "+atta_name+".\n");
   retdam=18;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("The staff zaps back at you.\n");
      user->hit_player(retdam);
   }

}

AIR() {
   write("The "+name+" summons strong currents of "+CYN+"AIR"+NORM+" to squeeze the life"+
      "from "+atta_name+".\n"+atta_name+" struggles to break free.\n");

   say("The "+name+" summons strong currents of "+CYN+"AIR"+NORM+" to squeeze the life"+
      "from "+atta_name+".\n"+atta_name+" struggles to break free.\n");
   retdam=8;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("Currents push you backwards.\n");
      user->hit_player(retdam);
   }

}

CHAOS() {
   write(atta_name+" begins to moan deeply...\n"+
      "Tendrils of pure "+RED+"C"+BOLD+"H"+HIW+"A"+RED+"O"+NORM+RED+"S"+NORM+" form, "+
      "ripping flesh apart, liquifying, and solidifying matter in constant change.\n"+
      atta_name+" appears to explode and reform in the same moment.\n");
   say(atta_name+" begins to moan deeply...\n"+
      "Tendrils of pure "+RED+"C"+BOLD+"H"+HIW+"A"+RED+"O"+NORM+RED+"S"+NORM+" form, "+
      "ripping flesh apart, liquifying, and solidifying matter in constant change.\n"+
      atta_name+" appears to explode and reform in the same moment.\n");
   retdam=20;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("Your body feels like it is being torn apart.\n");
      user->hit_player(retdam);
   }

}

LAW() {
   write(name+" hums ominouly, calling the forces of LAW holding "+atta_name+".  "+
      "Frozen to the molecule, stopped in perfect immotion, "+atta_name+" struggles to clutch sanity.\n");
   say(name+" hums ominouly, calling the forces of LAW holding "+atta_name+".  "+
      "Frozen to the molecule, stopped in perfect immotion, "+atta_name+" struggles to clutch sanity.\n");
   retdam=11;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("You freeze...\n");
      user->hit_player(retdam);
   }

}

TIME() {
   write("All "+YEL+"TIME "+NORM+"slows to trickle...\n"+
      atta_name+" begins aging at a terrifying rate.  Brittle bones crack loudly when the "+name+
      " connects.\n");
   say("All "+YEL+"TIME "+NORM+"slows to trickle...\n"+
      atta_name+" begins aging at a terrifying rate.  Brittle bones crack loudly when the "+name+
      " connects.\n");
   retdam=9;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("You weaken from the aging.\n");
      user->hit_player(retdam);
   }

}

LIGHT() {
   write("Blinding white "+BOLD+"LIGHT"+NORM+" erupts from the end of "+name+" obliterating"+
      " all in it's path.\n");
   say("Blinding white "+BOLD+"LIGHT"+NORM+" erupts from the end of "+name+" obliterating"+
      " all in it's path.\n");
   retdam=13;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("You are momentarily blinded.\n");
      user->hit_player(retdam);
   }

}

DARKNESS() {
   write("Intense black "+BOLD+BLK+"DARKNESS"+NORM+"  rises from the ground.\n"+
      "It melds around "+atta_name+" and all is briefly silent...\n"+
      atta_name+" screams:  AAARRRRRRGGGGGGHHHHHH!!!!!!!!!!\n");
   say("Intense black "+BOLD+BLK+"DARKNESS"+NORM+"  rises from the ground.\n"+
      "It melds around "+atta_name+" and all is briefly silent...\n"+
      atta_name+" screams:  AAARRRRRRGGGGGGHHHHHH!!!!!!!!!!\n");
   retdam=14;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("Demons gather your soul...\n");
      user->hit_player(retdam);
   }

}

WATER() {
   write(name+" drains the "+BLU+"WATER"+NORM+" from "+atta_name+"'s body"+
      "leaving it parched and gasping helplessly.\n");
   say(name+" drains the "+BLU+"WATER"+NORM+" from "+atta_name+"'s body"+
      "leaving it parched and gasping helplessly.\n");
   retdam=9;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("You feel dehydrated.\n");
      user->hit_player(retdam);
   }

}

STEAM() {
   write("Humid searing clouds of "+HIC+"STEAM"+NORM+" boil the flesh and blood of "+atta_name+
      ".\n");
   say("Humid searing clouds of "+HIC+"STEAM"+NORM+" boil the flesh and blood of "+atta_name+
      ".\n");
   retdam=11;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("The cloud drifts back to you.\n");
      user->hit_player(retdam);
   }

}

ACID() {
   write(name+" hisses loudly as a spray of "+HIG+"ACID"+NORM+" fries "+atta_name+
      ".  Black putrid skin flakes off worsening the sulfruic stench in the air.\n");
   say(name+" hisses loudly as a spray of "+HIG+"ACID"+NORM+" fries "+atta_name+
      ".  Black putrid skin flakes off worsening the sulfruic stench in the air.\n");
   retdam=16;
   if(user->query_real_name() != "druid" && user->query_attrib("wil") > random(22)) {
      write("You skin melts away.\n");
      user->hit_player(retdam);
   }

}
