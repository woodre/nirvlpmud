
#define AMOUNT_OF_CHARGE 5

#define TP this_player()
int value, charge;
object who;
object where;

 
init() {
    add_action("stick", "stick");
    add_action("summon", "summon");
    add_action("send", "send");
}
id(str) {return str=="arrow"; }

get() { return 1; }

short() {
   return "XX75 Easton arrow"; }

long() {
   write("An Easton XX75 Camo arrow.....Tipped with a Rocky Mountain\n"+
      "125 grain razor sharp broadhead.\n");
   write("Usage is `stick <target>'.\n");
   return 1; }

reset(arg) {
   if(arg) return;
   charge = AMOUNT_OF_CHARGE + random(10);
}

/*
init() {
   add_action("stick", "stick");
}
*/
 

stick(str) {
   object victim, owner;
object where;
object who;
   int amt, cost;
   int owner_level;
   owner = this_player();
   victim = find_living(str);
   owner_level = owner->query_level();
   if(!str) {
      write("Who do you wish to stick with this arrow??\n");
      return 1;
   }
   if(str == owner->query_real_name()) {
      write(" The arrow feels slippery in your hands \n" +
         "You feel like you couldnt shoot it\n");
      owner->heal_self(-100);
      return 1;
   }
   if(!victim || !living(victim)) {
      write("That person/thing is not in condition to be hurt by arrow.\n");
      return 1; }
   if(charge == 0) {
      write("The arrow cannot be shot again...\n");
      dest();
      return 1;
   }
   while(charge > 0) {
      charge--;
      if(owner_level < 6) cost = owner_level+6;
      else if(owner_level > 5 && owner_level < 11) cost = owner_level+10;
      else if(owner_level > 10 && owner_level < 16) cost = owner_level+12;
      else if(owner_level > 15 && owner_level < 21) cost = owner_level+14;
      else if(owner_level > 20) cost = 10;
      if(owner_level > 15) {
         amt = owner_level + 30;
         }
      else if(owner_level > 10 && owner_level < 16) {
         amt = owner_level + 20;
         }
      else if(owner_level < 11) {
         amt = owner_level + 10;
         }
      if(owner->query_spell_point() < cost) {
         write("You do not have enough spell points.\n");
         return 1;
         }
      write("You aim the Arrow at " + capitalize(str)+
         "\nand the arrow streaks from your bow straight at your opponent\n"+
         "to strike a mortal wound\n");
      say(capitalize(this_player()->query_real_name())+" aims the arrow " +
         "at "+capitalize(str)+" and the arrow\n"+
         "of pure force streaks towards "+
         this_player()->query_possessive()+
         " opponent.\n");
      victim->attacked_by(owner);
      victim->hit_player(amt);
      owner->add_spell_point(-cost);
      tell_object(victim, capitalize(owner->query_real_name())+
         " hits you with a well aimed XX75 Arrow\n");
      return 1;
   }
   if(charge < 6) value = 35000;
   else if(charge > 5) value = 60000;
}

query_value() { return value; }

query_weight() { return 3; }


dest() {
   this_player()->heal_self(-10);
   write("\n\nThe Arrow suddenly shimmers and vibrates uncontrollably.\n");
   write("Suddenly a bolt of pure energy streaks out of the sky to\n");
   write("To strike you to the ground!  The Arrow has left it's mark upon you!!!\n\n");
   tell_object(environment(this_player()),"The Arrow suddenly"+
      "Strikes its owner with a deep gash!\n");
   tell_object(environment(this_player()),"A bolt of pure energy from the God"+
      "shoots down from the sky to blast "+
      capitalize(this_player()->query_real_name())+"!!!\n");
   destruct(this_object());
   return 1;
}
 
summon(str) {
if (!str) return 0;
who = find_player(str);
if (!who) {
write("Can't find a "+str+" in the world.\n");
return 1;
}
/*
tell_object(who, "You feel lifted by the power of an XX75 arrow\n");
*/
where = environment(who);
move_object(who, environment(TP));
write(str+ " brought at your command\n");
return 1;
}
 
send(str) {
/*
if (!who) return 0;
if (!where) return 0;
tell_object(who, "The arrow returns you where you were\n");
*/
move_object(who, where);
write("Ok, " + str + " is back where he belongs.\n");
return 1;
}
