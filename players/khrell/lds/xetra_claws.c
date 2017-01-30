/*   This weapon is very very hard to get.  It is on a huge monster in 
   an area where you cannot see any exits in the room.  The monster 
   wanders and summons little ones to help.  Little ones when killed
   have 25% chance of creating two more little ones to attack.  
     The weapon takes away spell points often with nasty thing happening
   if they don't have them.  It also sucks 3 hitpoints every round, hit
   or miss.  I increased the weight as well. <Llew> */

/* converted to two-handed by illarion on 6 dec 2004
   the weapon's description indicates it covers both hands,
   and it's also too powerful to allow offwielding
*/   

#include "/players/llew/closed/ansi.h"

inherit "obj/weapon";

int dazed;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("claws");
   set_name(RED+"Xetra Claws"+NORM);
   set_class(20);
   set_weight(8);
   set_value(5000);
   set_alt_name("xetra claws");
   set_hit_func(this_object());
   set_alias("claws");
   set_short(RED+"Xetra Claws"+NORM);
   set_long("\tThe long black metallic claws of the xetra drip red with\n"+
            "fresh blood.  There is something deep within that brings back\n"+
            "a memory of repulsion, but taking in the dark, thick lifeflow\n"+
            "along the razor claws only leaves a longing for more violence.\n");
   set_message_hit(({HIR+"mutilated"+NORM," to a pulpy red mass",RED+"devastated"+NORM,
         " with blood dripping claws",BOLD+BLK+"slashed"+NORM," spraying the room with blood",
         HIY+"gouged"+NORM," a deep wound",YEL+"sliced"+NORM," cleanly",GRN+"cut"+NORM,"",
         "scratched"," a glancing blow"}));
  set_message_hit(({
  HIR+"mutilated"+NORM, " to a pulpy red mass", /* mas */
  RED+"devastated"+NORM, " with blood dripping claws", /* smash */
  BOLD+BLK+"slashed"+NORM, " spraying the room with blood", /* vh */
  HIY+"gouged"+NORM, " a deep wound", /* hh */
  YEL+"sliced"+NORM, " cleanly", /* h */
  GRN+"cut"+NORM, "", /* tickle */
  "scratched", " a glancing blow", /* graze */
  }));
   dazed=0;
   silentwield=1;
}

/* two-handed code */
two_handed() { return 1; }
id(str) { 
  if(str == "notarmor" && wielded && previous_object() && previous_object()->query_type()=="shield")
    return 1;
  if(str == "notweapon" && (!previous_object() || previous_object()==this_object())) {
    object *inv;
    int s;
    inv=all_inventory(environment());
    s=sizeof(inv);
    while(s--)
      if(inv[s]->query_type()=="shield" && inv[s]->query_worn())
        return 1;
  }
  return ::id(str);
}

display_notarmor_msg() {
  write("You can't handle a shield properly with the xetra claws melded to your hands.\n");
  return 1;
}

display_notweapon_msg() {
  write("You won't be able to use the claws effectively while wearing a shield.\n");
  return 1;
}

long() {
   long_desc="\tThe long black metallic claws of the xetra drip red with\n"+
             "fresh blood.  There is something deep within that brings back\n"+
             "a memory of repulsion, but taking in the dark, thick lifeflow\n"+
             "along the razor claws only leaves a longing for more violence.\n";
   if(environment()==this_player()) {
      long_desc+=wielded?
             "\tThe claws seems to meld themselves to your fingers as if\n"+
             "by magic.  They seem to vibrate constantly, looking for more\n"+
             "blood to feed its ravenous appetite.\n":
             "\tThere doesn't appear to be any way to wield the claws.  If\n"+
             "you could only concentrate enough mental power to meld them to your\n"+
             "hands, you could use the power contained in them.\n";
      long_desc+="\tThe slender claws weigh heavily in your hands and on your\n"+
                 "soul, twisting thoughts toward demonic delusions.  Pain and\n"+
                 "torture and agony run rampant in your mind, and you find it not\n"+
                 "such a bad prospect.\n";
   }
   ::long();
}

init() {
   add_action("wield","meld");
   add_action("stopwield","unmeld");
}
/*
wield(str) {
   if(!str || !id(str))
      return 0;
   if(environment() != this_player()) {
      write("You must get it first!\n");
      return 1;
   }
   if(present("notweapon",this_player())) {
      write("Something is preventing you from melding the claws.\n");
      return 1;
   }
   if(wielded) {
      write("You already have melded the claws.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 10) {
      write("You fail.\n");
      return 1;
   }
   wielded_by = this_player();
   call_other(this_player(), "wield", this_object(),silentwield);
   wielded = 1;
   this_player()->add_spell_point(-10);
   write("The "+name_of_weapon+" magically meld to your hands.\n");
   say(this_player()->query_name()+" melds "+name_of_weapon+".\n");
   return 1;
}
*/

wield(str) {
  int ret;
  silentwield=1;
  ret=::wield(str);
  if(wielded_by==this_player()) {
    this_player()->add_spell_point(-10);
    write("The "+name_of_weapon+" magically meld to your hands.\n");
    say(this_player()->query_name()+" melds "+name_of_weapon+".\n");
    return 1;
  }
  return ret;
}

weapon_breaks(){
   object temp_wield;
   if(broke) return 1;
   tell_object(environment(this_object()), BOLD+"The claws ring with a loud CRACK!\n"+NORM);
   set_class(class_of_weapon/3);
   broke = 1;
   temp_wield=wielded_by;
   temp_wield->stop_wielding();
   temp_wield->wield(this_object(),silentwield);
   return 1;
}

short() {
   string tmp_short;
   tmp_short=short_desc;
    if(this_player())
   if(call_other(this_player(), "query_level", 0) > 30) 
      tmp_short += "  < wc " + class_of_weapon + ","+eff_wc + " >";
   if(broke) tmp_short+=HIR+" ["+NORM+RED+"CRACKED"+BOLD+"]"+NORM;
   if(wielded) tmp_short+=HIR+" ("+NORM+RED+"melded"+BOLD+")"+NORM;
   return tmp_short;
}

weapon_hit(attacker) {
   int whack;
   int x,attint;
   string *mess;
   string attstring;
   whack=random(85) + 15;
   if(broke) return 0;

/*  Note this 3 hitpoint reduction every round.  */
   if(wielded_by)
   wielded_by->add_hit_point(-3); /* changed from hit_player by illarion.  you shouldn't be able to defend against this */
   if(whack > 95) {
      write(GRY+"\n"+pad("",3)+"Focusing your mental power into "+NORM+name_of_weapon+GRY+" you fire red energy!!\n\n"+NORM); 
      say(GRY+"\n"+pad("",12)+this_player()->query_name()+" fires red energy from "+this_player()->query_possessive()+" hand!!\n\n");
      tell_room(environment(this_player()),RED+pad("",14)+pad("",8,'~')+BOLD+pad("",5,'~')+NORM+RED+pad("",14,'~')+BOLD+pad("",5,'~')+NORM+RED+pad("",8,'~')+"\n\n");
      tell_room(environment(this_player()),pad("",6)+pad("",10,'~')+BOLD+pad("",5,'~')+NORM+RED+pad("",8,'~')+BOLD+pad("",10,'~')+NORM+RED+pad("",8,'~')+BOLD+pad("",5,'~')+NORM+RED+pad("",10,'~')+"\n\n");
      tell_room(environment(this_player()),RED+pad("",14)+pad("",8,'~')+BOLD+pad("",5,'~')+NORM+RED+pad("",14,'~')+BOLD+pad("",5,'~')+NORM+RED+pad("",8,'~')+"\n\n"+NORM);
      if(wielded_by->query_sp() < 15) {
         write(BOLD+"Your head fills with rampant energy burning your mind away.\n"+RED);
         if((int)wielded_by->query_attrib("mag") > 1)
         wielded_by->raise_magic_aptitude(-1);
         wielded_by->hit_player(random(20), "magical");
         write(NORM+"\n");
         if(attacker->query_hp() > 30) 
            attacker->hit_player(random(25)+5);
         else attacker->hit_player(attacker->query_hp()-1);
         return 20;
      }
      if(attacker->query_hp() > 30) 
         attacker->hit_player(28);
      else attacker->hit_player(attacker->query_hp()-1);
      return 10;
   }
   if(whack > 90) {
      write("\n"+GRY+pad("",12)+"You gather back with all of your energy.\n\n");
      say  ("\n"+GRY+pad("",18)+this_player()->query_name()+" reels back in might.\n\n");
      write(         pad("",4)+"With all power behind the "+NORM+name_of_weapon+GRY+" you leap forward and impale\n\n");
      say  (         pad("",9)+this_player()->query_name()+" leaps forward with the "+NORM+name_of_weapon+GRY+" to impale\n\n");
      attint=0;
      attstring=attacker->query_name();
      if(strlen(attstring) < 80){ 
         attint=(80-strlen(attstring))/2;
         if(attint > 11) attint -= 8;
         else attint = 4;
      }
      else 
         attstring=NORM+attstring[0..77]+NORM;
      tell_room(environment(this_player()),pad("",attint)+attstring+"\n\n");
      tell_room(environment(this_player()),pad("",19)+GRY+"directly in the "+HIR+"HEART"+GRY+"!\n"+NORM);

      if(attacker->query_hp() > 20)
         attacker->hit_player(20);
      else attacker->hit_player(attacker->query_hp()-1);
      return 10;
   }
   if(whack > 85) {
      x=random(40);
      if(x < 1) {
         write("You missed.\n");
         say(wielded_by->query_name()+" missed.\n");
         return 0;
      }
      mess=query_message_hit(x);
      write("You "+mess[1]+" "+attacker->query_name()+mess[0]+".\n");
      say(wielded_by->query_name()+" "+mess[1]+" "+attacker->query_name()+mess[0]+".\n");
      if(attacker->query_hp() > x) attacker->hit_player(x);
      else attacker->hit_player(attacker->query_hp()-1);
      if(wielded_by->query_sp() < 10) {
         write(HIR+"Your flesh is ripped off by the red glow of the claws and absorbed!\n"+NORM);
         wielded_by->hit_player(random(15), "magical");
         return 0;
      }
      wielded_by->add_spell_point(-random(9));
      return 15;
   }
   if(whack > 80) {
      write(RED+"A red aura surrounds you and fills you with energy.\n"+NORM);
      say(RED+"A red aura surrounds "+wielded_by->query_name()+" filling "+wielded_by->query_objective()+" with energy.\n"+NORM);
      wielded_by->heal_self(random(5) + 1);
      return 5;
   }
   if(whack > 74) {
      int h;
      x=0;
      say(BOLD+wielded_by->query_name()+" becomes Fury and unleashes "+wielded_by->query_objective()+"self at "+attacker->query_name()+"!!\n"+NORM);
      write(BOLD+"You become Fury and unleash all your energy at "+attacker->query_name()+"!!\n"+NORM);
      while(!random(x)) {
         h=random(35);
         if(h < 1) {
            write("You missed.\n");
            say(wielded_by->query_name()+" missed.\n");
            return 0;
         }
         mess=query_message_hit(h+3);
         write("You "+mess[1]+" "+attacker->query_name()+mess[0]+".\n");
         say(wielded_by->query_name()+" "+mess[1]+" "+attacker->query_name()+mess[0]+".\n");
         if(attacker->query_hp() > h) attacker->hit_player(h);
         else attacker->hit_player(attacker->query_hp()-1);
         x++;
      }
      if(wielded_by->query_sp() < x*4) {
         write(BOLD+"The claws tear away from your hands wildly!\n"+NORM);
         say(wielded_by->query_name()+"'s claws tear away from "+wielded_by->query_objective()+" wildly!\n");
         wielded_by->add_spell_point(-wielded_by->query_sp());
  /* this is causing too many weird errors...  - illarion
         command("drop xetra claws",wielded_by);
 */  call_out("get_rid_of_claws",1);
         input_to("dazed");
         dazed=1;
         return -50;
      }
      wielded_by->add_spell_point(-(x+random(x*4)));
      return 10;
   }
   if(whack > 68) {
      write(GRY+"\n"+pad("",6)+"A cloudy, penetrating "+RED+"Bloodlust"+BLK+" blurs your vision.\n\n");
      say(GRY+"\n"+pad("",10)+"A clouded red "+RED+"Bloodlust"+GRY+" fills "+this_player()->query_name()+"'s eyes.\n\n");
      write(pad("",6)+"You thrust the "+NORM+name_of_weapon+GRY+" deep into the abdomen of\n\n");
      say(pad("",4)+this_player()->query_name()+" thrusts the "+NORM+name_of_weapon+GRY+" deep into the abdomen of\n\n");
       attint=0;
      attstring=attacker->query_name();
      if(strlen(attstring) < 80){ 
         attint=(80-strlen(attstring))/2;
         if(attint > 11) attint -= 8;
         else attint = 4;
      }
      else 
         attstring=NORM+attstring[0..77]+NORM;
      tell_room(environment(this_player()),pad("",attint)+attstring+"\n\n");
      tell_room(environment(this_player()),pad("",6)+"spilling forth it's bloody entrails upon the ground.\n"+NORM);
      if(attacker->query_hp() > 17) 
         attacker->hit_player(17);
      else attacker->hit_player(attacker->query_hp()-1);
      return 15;
   }
   if(whack > 64) {
      tell_room(environment(this_player()),GRY+"\n"+pad("",11)+"The "+NORM+name_of_weapon+GRY+" glow with an eery red light...\n\n");
      write(pad("",6)+"With a great roar of "+RED+"Rage"+GRY+" you tear into the "+NORM+YEL+"flesh"+GRY+" of\n\n");
      say(pad("",7)+this_player()->query_name()+" roars with "+RED+"Rage"+GRY+" and tears into the "+NORM+YEL+"flesh"+GRY+" of\n\n");
      attint=0;
      attstring=attacker->query_name();
      if(strlen(attstring) < 80){ 
         attint=(80-strlen(attstring))/2;
         if(attint > 11) attint -= 8;
         else attint = 4;
      }
      else 
         attstring=NORM+attstring[0..77]+NORM;
      tell_room(environment(this_player()),pad("",attint)+attstring+".\n\n"+NORM);
      if(attacker->query_hp() > 15)
         attacker->hit_player(15);
      else attacker->hit_player(attacker->query_hp()-1);
      return 10;
   }
   if(whack > 58) {
      object theroom;
      theroom=environment(wielded_by);
      tell_room(theroom,"\n"+pad("",23)+GRY+"Red light flashes!\n\n"+NORM+RED);
      tell_room(theroom,pad("",26)+pad("",12,'~')+"\n");
      tell_room(theroom,pad("",22)+"~~~~"+BOLD+pad("",12,'~')+NORM+RED+"~~~~\n");
      tell_room(theroom,pad("",20)+"~~"+BOLD+"~~~~~"+NORM+RED+pad("",10,'~')+BOLD+"~~~~~"+NORM+RED+"~~\n");
      tell_room(theroom,pad("",16)+"~~~~"+BOLD+"~~"+NORM+RED+"~~~~ "+pad("",10)+" ~~~~"+BOLD+"~~"+NORM+RED+"~~~~\n");
      tell_room(theroom,pad("",4)+"_______~~~~~~~~"+BOLD+"~"+NORM+RED+"~"+pad("",22)+"~"+BOLD+"~"+NORM+RED+"~~~~~~~~_______\n");
      tell_room(theroom,pad("",11)+"~~~~~~~~"+BOLD+"~"+NORM+RED+"~"+pad("",22)+"~"+BOLD+"~"+NORM+RED+"~~~~~~~~\n");
      tell_room(theroom,pad("",16)+"~~~~"+BOLD+"~~"+NORM+RED+"~~~~ "+pad("",10)+" ~~~~"+BOLD+"~~"+NORM+RED+"~~~~\n");
      tell_room(theroom,pad("",20)+"~~"+BOLD+"~~~~~"+NORM+RED+pad("",10,'~')+BOLD+"~~~~~"+NORM+RED+"~~\n");
      tell_room(theroom,pad("",22)+"~~~~"+BOLD+pad("",12,'~')+NORM+RED+"~~~~\n");
      tell_room(theroom,pad("",26)+pad("",12,'~')+"\n\n"+NORM);
      if(attacker->query_hp() > 24) 
         attacker->hit_player(24);
      else attacker->hit_player(attacker->query_hp()-1);
      return 10;
   }      
   return 0;
}

dazed(str) {
   write("You fail!!!  You are dazed from the claws of the demon.\n");
   if(dazed) {
      input_to("dazed");
      dazed=0;
   }
}
         
get_rid_of_claws() {
  if(environment() && environment(environment()))
    transfer(this_object(),environment(environment()));
}
