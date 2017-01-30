#define ME this_player()->query_real_name()
#define HP this_player()->query_hp()
#define SP this_player()->query_sp()
#define dance_wait 60
inherit "/obj/monster";

   string dance;
   int dance_next;
reset(arg) {
   ::reset(arg);
   if (!arg) {
  dance = "ready";
        dance_next = time();
  set_name("baron");
     set_alias("baron");
     set_short("The Baron Vonbrichten");
 set_long("The Baron Vonbrichten.  The Baron is a handsome man dressed\n"+
   "in a muchly decorated uniform of some sort.\n");
     set_level(15);
     set_ac(15);
     set_wc(18);
     set_hp(250);
     set_al(-100);
     set_aggressive(0);
     money = (250);
   }
}
catch_tell(str){
  string a,b,c;
   object ob, there;
  there = this_player();
    if(!there)
       return;

 if(sscanf(str, "%s cut in%s",a,b)==2) {

  if(this_player()->query_gender_string() == "male") {
    if(!(present("lady", environment(this_object())))) {
  tell_object(there, "The Baron Vonbrichten scoffs at your impudence!\n"+
      "His cheeks flush with anger.  'You faggoty creep!' he yells.\n"+
      " 'You will die for your insolence!.'  The Baron pulls a Rapier\n"+
      "from its sheath.\n"+
      "     The Baron Vonbrichten Attacks!\n");
         this_object()->attack_object(there);
 say(capitalize(ME)+" just tried to dance with the Baron!\n");
     return 1;
          }
  }
  if(this_player()->query_gender_string() == "female") {

    if(dance_next > time()) {
   tell_object(there, "The Baron apologizes but he is much too tired\n"+
      "dance right now.  He repsectfully declines.\n");
 say(capitalize(ME)+" just got turned down by the Baron!\n");
           return 1;
               }
  tell_object(there, "You step forward towards the couple and\n"+
   "politely ask to cut in.  'But of course Madam!' says the Baron.\n"+
   " 'The pleasure would be mine.'   He takes your hand in his and\n"+
   "draws you into the center of the dance floor.\n");
    tell_object(there, "From somewhere within the ballroom soft\n"+
   "music filters through.  The Baron leads off with slow deliberate\n"+
   "steps that take you all throughout the ballroom\n");
     tell_object(there, "You dance and spin and twirl about the huge\n"+
   "rooms with long elegant strides.\n"+
   "  And in the end, the Baron brings you back to the center...\n"+
   "his steps come to a slow stop, back in the center of the dance\n"+
   "floor.  He kisses your hand, steps back and bows Deeply\n");
     tell_object(there, "He smiles briefly at you then resumes his\n"+
   "ancient dance with the lady of the ball.\n"+
   " The music fades away and the couple once again dances to notes\n"+
   "only they can hear.\n");
  say(capitalize(ME)+" asks the Baron to dance.  He takes her\n"+
  
 "arm and leads her to the dance floor.  Together they dance and\n"+
 "whirl to music only they seem to be able to hear.  Finally they\n"+
 "come back to the center of the room, where the Baron bows to\n"+
 " "+capitalize(ME)+" and fades back into the crowd.\n");
     call_other(there, "add_hit_point", random(HP)*2);
     call_other(there, "add_spell_point", random(SP)*2);
      dance_next = time() + dance_wait;
         return 1;
    }
   }
}
