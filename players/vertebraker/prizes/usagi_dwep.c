/*
 * This item was made for Usagi as a result of turning in bugs.
 * It is a copy of Jenny's hockey stick with an extra wc point
 * and additional emotes from the currently defunct Nameless Guild.
 * The puck-using ability has been taken out.
 */
#include <ansi.h>
#define TP this_player()
#define TPRN (string)TP->query_real_name()
#define ME TP->query_possessive()
#define MEE TP->query_objective()

inherit "/obj/weapon.c";

object ob;
int limit = 5;
status heh;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("katana");
   set_alias("sword");
   set_short("Katana "+CYN+"* Cold Fire *"+NORM);

   set_long(
   "Mist surrounds you....\nThis is the infusion of the element of air:\nwith all its power and danger.\n");
   set_weight(4);
   set_class(21);
   set_value(0);
   set_type("sword");
   set_hit_func(this_object());
}
init() {
  if(TP && (environment()==TP) && this_player()->query_real_name() != "usagi")
  {
    write("When you touch the weapon, the air seems to turn cold...\nYou feel "+HIB+"COLD DEATH"+NORM+" pass by....\n");
    tell_room(environment(TP), this_player()->query_name()+" drops "+short()+"!\n");
    move_object(this_object(), environment(TP));
    return;
  }
   ::init();
}
weapon_hit(attacker) {
   
   int i, j;
     string mess;
   if(!attacker) return;
   if(heh == 2) return;
   for(i = 0; i < 1 + random(10); i ++)
    {
     switch(random(10)) {
      case 0:
        mess = CYN + "      ******   COLD FIRE   ******\n";
        break;
      case 1: mess = "Cold Fire ENGULFS the ENEMY!\n";
        break;
      case 2: mess = BOLD+(string)TP->query_name()+" feeds upon the soul of his enemy!\n"+NORM;
         break;
      case 3: mess = (string)TP->query_name()+" summons "+HIC+"lightning"+NORM+" from the sky!\n";
         break;
      case 4: mess = short()+" quivers as it hits its foe!\n"; break;
      case 5: mess = BLU+"\n\t\tF    L   A   R   E\n"+NORM; break;
      case 6: mess = (string)TP->query_name()+" goes BERSERK!  Motions are ablur!\n"; break;
      case 7: mess = (string)TP->query_name()+" slices through his enemy's weapons!\n"; break;
      case 8: mess = "The enemy's magic is diminished!\n"+BOLD+"\nDARKNESS floods the room!\n\n"+NORM;
      break;
       case 9: mess = "There is a sudden wrenching in the space of reality!\n"; break;

   }
   if(random(2)) mess += "\n";
   else mess += "\n\n";
   if(random(2)) mess = "\n"+mess;
   tell_room(environment(environment()), mess);
  }
   if(TP && TPRN != "Gordie Howe") {
      if(!heh && !other_sticks(environment()))
         if(random(100) < 33 && limit > 0 && attacker &&
            present(attacker, environment(environment()))) {
         heh ++;
         if(TP)
            TP->attack();
         heh --;
         limit --;
         return 1;}
      else { 
         limit = 5;
         return 3; }}}


query_heh() { return heh; }

other_sticks(oc) {
   object x, y;
  return 0;
   x = first_inventory(oc);
   while(x) {
      y = next_inventory(x);
      if(x->jenny_hockey_stick() && x->query_heh() && (x != this_object()))
         return 1;
      x = y;
   }
}

status jenny_hockey_stick() {
   return 1;
}

status id(string str)
{
  return (::id(str) || str=="air");
}
