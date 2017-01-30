inherit "obj/weapon.c";

#define AMOUNT_OF_MAGIC 2

int magic_left;
status first_wield;

long() {
   write("You see an ancient, combat-scarred axe.  It's handle is covered\n");
   write("with strange inscriptions and runes.  The well-balanced blade\n");
   write("feels like it could do some major damage.\n");
   if (magic_left>0 && !first_wield) {
      
      write("The mystical weapon has a bright magical glow!\n");
      write("The magic glow seems to be fading.\n");
   }
   if (magic_left<0) {
      write("The runes seem to have been burnt out.  You can barely read them.\n");
   }
}
query_value() {
   if(magic_left>0) {
      return 100000;
   }
   return 5000;
}
out_of_magic() { 
   write ("Suddenly you hear the horrible wail of a thousand souls!!!\n");
   say("Suddenly you hear the horrible wail of a thousand souls!!!\n");
   write("The runes on your axe glow madly in a myriad of colors!\n");
   write("You see the last of the axe's magic streak out and hit your target.\n");
   say("A bolt of magic streaks out from "+this_player()->query_name()+"'s axe!\n");
   write("The skies echo with thunder.  BOOOOOMMM!!!\n");
   say ("The skies echo with thunder.  BOOOOOMMM!!!\n");
   set_name("heavy battle axe");
   set_short("a heavy battle axe");
   call_out("all_gone",0);
}

all_gone() {
   tell_object(environment(),"As the axe reverts back to normal form, you see smoke rise up\n");
   tell_object(environment(),"from the runes on the handle.\n");
}

reset(arg) {
   if(!arg) {
      ::reset(arg);
      set_name("heavy battle axe");
      set_alt_name("battle axe");
      set_alias("axe");
      set_short("a heavy battle axe");
      set_class(17);
      set_weight(5);
      set_hit_func(this_object());
      magic_left = AMOUNT_OF_MAGIC;
      first_wield = 1;
   }
}

weapon_hit(attacker) {
   if(call_other(environment(this_player()), "realm") == "enterprise") {
      write("The axe suffers an anachronism and falls to the floor!\n");
      write("This axe can't be used on the Enterprise.\n");
      transfer(present("heavy battle axe",this_player()),
         environment(this_player()));
      return 0;
   }
   if(magic_left < 0 ) return 0;
   if(magic_left == 0 ) {
      out_of_magic();
      magic_left--;
      return 2000;
   }
   if(random(3) > 0) return 0;
   write("A bolt of lightning shoots from the sky.  KRAAAACK!\n");
   write("You feel the Axe's POWER!!!\n");
   say("A bolt of lightning shoots from the sky.  KRAAAACK!\n");
   magic_left--;
   return 33;
}

wield(str) {
   if(!id(str)) return 0;
   if(environment() != this_player()) return 0;
   if (wielded) {
      write("You're already wielding it!\n");
      return 1;
   }
   if(first_wield) {
      write("What's this???  The axe suddenly changes form!\n");
      write("It begins to glow in your hands.\n");
      set_name("battle axe of power");
      set_short("Battle Axe of Power");
      first_wield = 0;
   }
   if (magic_left) {
      write("The axe's magic courses through your body!\n");
      write("You feel AWESOME!!\n");
   }
   wielded_by = this_player();
   call_other(this_player(),"wield",this_object());
   wielded = 1;
   return 1;
}
