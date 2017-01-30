
/*
 * BLESS (2/11/94)
 * Increases chance of hit and damage
 * Cost 50 sp 
 */

bless() {
   int bless;

   if(this_player()->query_attack())
     notify_fail("You cannot cast this during combat.");
   if(previous_object()->query_spell_blessed())
     notify_fail("You are already blessed!");
   if(!verify_use("spell", 0, 50))
     return 1;
   TELL("A white light appears over "+
            capitalize(this_player()->query_name())+"'s head.\n");
   write("A feeling of warmth spreads through your soul.\n");
   write("You are now blessed.\n");
   previous_object()->set_bless_time(time());  
   bless = this_player()->query_attrib("pie")/2;
   bless += random(this_player()->query_level()/3);
   if(bless > 20)
     bless = 20;
   previous_object()->set_blessed(bless);
   return 1;
}
