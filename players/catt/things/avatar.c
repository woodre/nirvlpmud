#define MACROS_FINGER "Macros the master black sorceror (black knight)\n"+\
      "Level:          18\n"+\
      "Guild name: Demon Summoners\n"+\
      "Player Killer:  Yes\n"+\
      "Last called at: Not logged off.\n"+\
      "Age: 2 months 5 days 16 hours 22 minutes 53 seconds\n"
#define DARGOTH_FINGER "Dargoth the soldier of fortune (white knight)\n"+\
      "Level:          15\n"+\
      "Guild name: Warrior\n"+\
      "Player Killer:  No\n"+\
      "Last called at: Not logged off.\n"+\
      "Age: 1 month 2 days 3 hours 16 minutes 29 seconds\n"
#define REA_FINGER "Rea the black witch (black knight)\n"+\
      "Level:          19\n"+\
      "Guild name: Assassins\n"+\
      "Player Killer:  Yes\n"+\
      "Last called at: Not logged off.\n"+\
      "Age: 6 months 2 days 10 hours 32 minutes 29 seconds\n"
#define DEFAULT_FINGER "Not Done Yet"

#define MACROS_SHORT "Macros the master black sorceror (black knight)"
#define DARGOTH_SHORT "Dargoth the soldier of fortune (white knight)"
#define REA_SHORT "Rea the black witch (black knight)"
#define DEFAULT_SHORT soul+" the souless"

#define MACROS_LONG "Macros the master black sorceror (black knight)\n"+\
      "Macros makes you wonder if you should have ever been born.\n"+\
      "Macros is a valheru, 5 feet 10 inches tall, 150 lbs.\n"+\
      "Macros can fight other players.\n"+\
      "Macros is carrying:\n"+\
      "Macros' quicktyper.\n"+\
      "Amulet of the sky. (worn)\n"+\
      "Robe of the deathless magi. (worn)\n"+\
      "Ring of spellweaving.(worn)\n"+\
      "Sightblinders staff of necromancy. (wielded)\n"
#define DARGOTH_LONG "Dargoth the soldier of fortune (white knight)\n"+\
      "Dargoth looks like conan the barbarian on steriods.\n"+\
      "Dargoth is a human, 7 feet 2 inches tall, 310 lbs. \n"+\
      "Dargoth cannot fight other players.\n"+\
      "Dargoth is carying:\n"+\
      "Dargoth's quicktyper.\n"+\
      "Platemail of Thunder. (worn)\n"+\
      "Boots of speed. (worn)\n"+\
      "Gloves of frost. (worn)\n"+\
      "Spirit shield. (worn)\n"+\
      "Malac's warhammer. (wielded)\n"
#define REA_LONG "Rea the black witch (black knight)\n"+\
      "Rea is covered in a deep black robe that absorbs the light.\n"+\
      "Rea is difficult to see but looks roughly 5 feet 4 inches tall\n"+\
      "108 lbs.\n"+\
      "Rea can fight other players.\n"+\
      "Rea is carrying:\n"+\
      "Robe of the chaotic night. (worn)\n"+\
      "Ring of the Asp. (worn)\n"+\
      "Boots of shadow walking. (worn)\n"+\
      "Elder assassins dagger. (wielded)\n"+\
      "Wand of death. \n"
#define DEFAULT_LONG " "

#define MACROS_DESTMESS "I am not that easily destroyed little one"
#define DARGOTH_DESTMESS "Don't bother with that little one."
#define REA_DESTMESS "I think you need a bigger stick."
#define DEFAULT_DESTMESS "Don't bother trying that again."

#define MACROS_FRYMESS "Large demons tear Macros to pieces."
#define DARGOTH_FRYMESS "Dargoth dissipates into a fine mist."
#define REA_FRYMESS "A dark shadow forms behind Rea and swallows her."
#define DEFAULT_FRYMESS soul+" falls to the ground in a pile of dust."

#define MACROS_MOVEMESS "strides "
#define DARGOTH_MOVEMESS "stalks "
#define REA_MOVEMESS "slinks slyly "
#define DEFAULT_MOVEMESS "walks "

#define MACROS_FOLLOWMESS "Macros chases after "
#define DARGOTH_FOLLOWMESS "Dargoth flies after "
#define REA_FOLLOWMESS "Rea shadows "
#define DEFAULT_FOLLOWMESS " "

#define MACROS_FOLLOWMESS2 "Macros chases after you."
#define DARGOTH_FOLLOWMESS2 "Dargoth flies after you."
#define REA_FOLLOWMESS2 "Rea flows out of the shadows."
#define DEFAULT_FOLLOWMESS2 "You are being followed."

#define MACROS_TELEMESS "Macros teleports to "
#define DARGOTH_TELEMESS "Dargoth flings himself at "
#define REA_TELEMESS "Rea jumps into the shadows towards "
#define DEFAULT_TELEMESS "The avatar teleports to "

inherit "obj/monster";
object owner, soul, shadow;
string destmessage, frymessage, movemessage, followmessage;
string followmessage2, teleportmessage;
reset(arg) {
   ::reset(arg);
   if(arg) {
      if(!owner) fry();
      return;
   }
   set_name("soul");
   set_short("A blank soul");
   set_long("A blank soul\n");
   set_level(1);
   set_hp(10000);
   set_wc(1);
   set_ac(2500);
   enable_commands();
}
init() {
   add_action("soul_finger","finger");
   add_action("dest","destruct");
   add_action("dest","Destruct");
   add_action("dest","dest");
   add_action("dest","update");
}
dest() {
   write(soul+" says: I cannot allow you to destroy me!\n");
   say(destmessage+"\n");
   return 1;
}
fry() {
   say(frymessage+"\n");
   destruct(this_object());
   return 1;
}
soulemote(str) {
   say(capitalize(soul)+" "+str+"\n");
   tell_object(find_living(owner), "-->"+soul+" emotes: "+str+"\n");
   return 1;
}
soulecho(str) {
   say(str+"\n");
   tell_object(find_living(owner), "--> "+soul+" echoes: "+str+"\n");
   return 1;
}
dir(str) {
   if(!str) {
      tell_object(find_living(owner), "--> "+soul+" wants a direction first.\n");
      return 1;
   }
/* Commented out due to duplicated movement emotes.
   say(soul+" "+movemessage+"\n");
*/
   command(str, this_object());
   slook();
   return 1;
}
soulto(str) {
   object target;
   target = find_player(str);
   say(teleportmessage+"\n");
   move_object(this_object(), environment(target));
   tell_object(find_living(owner), soul+" teleports to: "+str+"\n");
   slook();
   return 1;
}
ssay(str) {
   say(soul+" says: "+str+"\n");
   tell_object(find_living(owner), "--> "+soul+" says: "+str+"\n");
   return 1;
}
stell(str) {
   string who, what;
   object who1;
   if(sscanf(str, "%s %s", who, what) == 2) {
      who1 = find_player(who);
      tell_object(who1, soul+" tells you: "+what+"\n");
      tell_object(find_living(owner), "--> "+soul+" tells "+who+": "+what+"\n");
      return 1;
   }
   tell_object(find_living(owner), "--> "+soul+" tells you: Ooops. Mistell.\n");
   return 1;
}
slook() {
   object home;
   home = environment(find_living(owner));
   move_object(find_living(owner), environment(this_object()));
   command("look", find_living(owner));
   move_object(find_living(owner), home);
   return 1;
}
catch_tell(str2) {
   object target;
   string s1;
   tell_object(find_living(owner), "--> "+str2+"\n");
   target = this_object()->query_attacker();
   if(target) {
      target->stop_fight();
      this_object()->stop_fight();
      target->stop_fight();
   }
   return 1;
}
soul_finger(str) {
   if(!str) return 0;
   if(str == "macros") {
      tell_object(this_player(), MACROS_FINGER);
      tell_object(find_living(owner), "--> "+soul+
         " tells you: I have been fingered.\n");
      return 1;
   }
   if(str == "dargoth") {
      tell_object(this_player(), DARGOTH_FINGER);
      tell_object(find_living(owner), "--> "+soul+
         " tells you: I have been fingered.\n");
      return 1;
   }
   if(str == "rea") {
      tell_object(this_player(), REA_FINGER);
      tell_object(find_living(owner), "--> "+soul+
         " tells you: I have been fingered.\n");
      return 1;
   }
   if(str == this_object()->query_real_name()) {
      tell_object(this_player(), DEFAULT_FINGER);
      tell_object(find_living(owner), "--> "+soul+
         " tells you: I have been fingered.\n");
   return 1;
   }
   this_player()->command("finger", str);
   return 0;
}
soul_shadow(str) {
   if(!str) return 0;
   if(str == "off") {
      shadow = 0;
      remove_call_out("follow");
      return 1;
   }
   if(shadow = find_player(str)) {
      tell_object(find_living(owner), "--> "+soul+" is following: "+shadow->query_real_name()+".\n");
      call_out("follow", 1);
      return 1;
   }
   return 0;
}
follow() {
   if(environment(this_object()) != environment(shadow)) {
      tell_room(environment(this_object()), followmessage+
                shadow->query_real_name()+"\n");
      tell_object(shadow, followmessage2+"\n");
      move_object(this_object(), environment(shadow));
   }
   call_out("follow", 1);
}
set_owner(str) {
   if(!str) return 0;
   owner = str->query_real_name();
   tell_object(find_living(owner), "You are now "+soul+"'s master.\n");
   return 1;
}
set_avatar(str) {
   if(!str) return 0;
   set_name(str);
   soul = capitalize(this_object()->query_real_name());
   if(str == "macros") {
      set_short(MACROS_SHORT);
      set_long(MACROS_LONG+"\n");
      destmessage = MACROS_DESTMESS;
      frymessage = MACROS_FRYMESS;
      movemessage = MACROS_MOVEMESS;
      followmessage = MACROS_FOLLOWMESS;
      followmessage2 = MACROS_FOLLOWMESS2;
      teleportmessage = MACROS_TELEMESS;
      return 1;
   }
   if(str == "dargoth") {
      set_short(DARGOTH_SHORT);
      set_long(DARGOTH_LONG+"\n");
      destmessage = DARGOTH_DESTMESS;
      frymessage = DARGOTH_FRYMESS;
      movemessage = DARGOTH_MOVEMESS;
      followmessage = DARGOTH_FOLLOWMESS;
      followmessage2 = DARGOTH_FOLLOWMESS2;
      teleportmessage = DARGOTH_TELEMESS;
      return 1;
   }
   if(str == "rea") {
      set_short(REA_SHORT);
      set_long(REA_LONG+"\n");
      destmessage = REA_DESTMESS;
      frymessage = REA_FRYMESS;
      movemessage = REA_MOVEMESS;
      followmessage = REA_FOLLOWMESS;
      followmessage2 = REA_FOLLOWMESS2;
      teleportmessage = REA_TELEMESS;
      return 1;
   }
   if(str) {
      set_short(DEFAULT_SHORT);
      set_long(DEFAULT_LONG+"\n");
      destmessage = DEFAULT_DESTMESS;
      frymessage = DEFAULT_FRYMESS;
      movemessage = DEFAULT_MOVEMESS;
      followmessage = DEFAULT_FOLLOWMESS;
      followmessage2 = DEFAULT_FOLLOWMESS2;
      teleportmessage = DEFAULT_TELEMESS;
      return 1;
   }
   return 0;
}

