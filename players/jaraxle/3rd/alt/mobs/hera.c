
/* Copied from the main Chapel, and modified visually for effect */

#define prompt ("->> ")
#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

string spouse, mate, moo;
int mate_yes, spouse_yes, ceremony_in_progress;
object mate_ob, spouse_ob;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("hera");
     set_alias("hera");
     set_race("God");
     set_short(MAG+"Hera"+NORM+", Goddess of Marriage");
     set_gender("female");
     set_long(
"  Once full of beauty and grace Hera has strangely\n"+
"aged in this trepid chapel.  She can still perform\n"+
"a marriage ceremony to any traveler.  For more\n"+
"information type 'marry help'. \n");

     set_level(20);
     set_hp(650);
     set_al(200);
     set_aggressive(0);
     set_wc(45);
     set_ac(23);
     mate_yes=0;
     spouse_yes=0;
     enable_commands();
}

init() { 
  ::init();
  add_action("marry", "marry");
}

marry(str) {
  if(!str) return 0;
  if(str=="help") {
    if(!efun::query_verb())
      say("\n");
    say(format(MAG+ "Hera says"+NORM+": I will marry you and your beloved for the " +
     "price of a mere 1000 coins. Simply type \"marry <spouse>\", and I will " +
     "perform the ceremony.\n"));
    if(!efun::query_verb())
      say(prompt);
    return 1;
  }
  if(str == this_player()->query_real_name()){
    say (MAG+ "Hera laughs"+NORM+":  You can't marry yourself fool!\n");
    return 1;
  }
  if(str == "guest"){
    say (MAG+ "Hera snickers"+NORM+":  Guest is not worthy of you!\n");
    return 1;
  }
  if(str == "hera"){
    say (MAG+ "Hera falls on the floor laughing"+NORM+":  You fool, Zeus would KILL you!\n");
    return 1;
  }
  if(!present(str)) {
    say(format(MAG+ "Hera says"+NORM+": I'm sorry, but that person isn't here.\n"));
    return 1;
  }
  if(!find_player(str) ) {
      write("You must be in the same room as "+capitalize(str)+".\n");
   return 1; }
   if(find_player(str)->query_invis() > 20){
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
  if(present("wedding ring", this_player()) || present("wedding ring", 
   present(str))) {
    say(format("\n" +MAG+ "Hera says"+NORM+": Only the unmarried may be joined!\n"));
    return 1;
  }
  if(this_player()->query_money() < 1000) {
    say(MAG+ "Hera says"+NORM+": I'm afraid you don't have enough money.\n");
    return 1;
  }
  if(!ceremony_in_progress)
    ceremony(this_player(), present(str));
  else 
    say(format(MAG+ "Hera says"+NORM+": I am already performing a ceremony.\n"));
  return 1;
}

catch_tell(str) {
  string a, b, c;
  if(mate && spouse && (sscanf(str, "%s says:%sdo%s", a, b, c)==3 ||
   sscanf(str, "%s says%syes%s", a, b, c)==3)) {
    if(a==mate) {
      mate_yes=1; 
      }
    if(a==spouse) {
      spouse_yes=1; 
      }
     if(ceremony_in_progress && mate_yes && spouse_yes){
      call_out("pronouncement", 2);
      }
  }
}

ceremony(me, you) {
  if(!mate) {
    mate=me->query_name();
    spouse=you->query_name();
    moo=you->query_real_name();
    mate_ob=me;
    spouse_ob=you;
    ceremony_in_progress=1;
  }

me->add_money(-1000);
  tell_room(environment(), MAG+ "Hera says"+NORM+":  Friends we are gathered here at this hour to\n");
  tell_room(environment(), "celebrate the coming together of two separate lives.\n");
  tell_room(environment(), "\n");
  call_out("ceremony_two", 8);
  return 1;
}

ceremony_two() {
  tell_room(environment(),  MAG+ "Hera says"+NORM+":  We have come to join " + capitalize(mate) + " and " + capitalize(spouse) + "\n");
  tell_room(environment(), "in marriage, to rejoice with them in the making of this very\n");
  tell_room(environment(), "important commitment.\n");
  tell_room(environment(), "\n");
  remove_call_out("ceremony_two");
  call_out("ceremony_three", 8);
  return 1;
}

ceremony_three() {
  tell_room(environment(), MAG+ "Hera continues"+NORM+":  The essence of this commitment is not to be\n");
  tell_room(environment(), "entered into lightly, but rather undertaken with great respect\n");
  tell_room(environment(), "and consideration for both oneself and the one you have chosen\n");
  tell_room(environment(), "to walk the path of life with.\n");
  tell_room(environment(), "\n");
  remove_call_out("ceremony_three");
  call_out("ceremony_four", 12);
  return 1;
}

ceremony_four() {
  tell_room(environment(), MAG+ "Hera says"+NORM+":  The physical union of marriage is one of life's\n");
  tell_room(environment(), "greatest joys, and when this is combined with real friendship\n");
  tell_room(environment(), "and a union of spirit, it is infinitely enhanced.\n");
  tell_room(environment(), "\n");
  remove_call_out("ceremony_four");
  call_out("ceremony_five", 12);
  return 1;
}

ceremony_five() {
  tell_room(environment(), MAG+ "Hera says"+NORM+":  The day-to-day companionship, the pleasure of \n");
  tell_room(environment(), "doing things together, the delight of exchanging experiences,\n");
  tell_room(environment(), "are all a central part of what a man and a woman who care for\n");
  tell_room(environment(), "each other can share.\n");
  tell_room(environment(), "\n");
  remove_call_out("ceremony_five");
  call_out("ceremony_six", 14);
  return 1;
}

ceremony_six() {
  tell_room(environment(), MAG+ "Hera continues"+NORM+":  Marriage symbolizes the intimate sharing\n");
  tell_room(environment(), "of two lives, yet this must not be dim, but enhance each \n");
  tell_room(environment(), "partner's individuality.  A marriage that lasts is one that\n");
  tell_room(environment(), "is maintained with consideration for one another, honesty \n");
  tell_room(environment(), "and loyalty to each other.\n");
  tell_room(environment(), "\n");
  remove_call_out("ceremony_six");
  call_out("ceremony_seven", 16);
  return 1;
}

ceremony_seven() {
  tell_room(environment(), MAG+ "Hera says"+NORM+":  We are here today to celebrate the love which \n");
  tell_room(environment(), capitalize(mate) + " and " + capitalize(spouse) + " have for each other.  Out of their\n");
  tell_room(environment(), "desire to have their marriage be more then a bond between\n");
  tell_room(environment(), "two people they declare that their love is an expression of\n");
  tell_room(environment(), "their commitment to improving the quality of life on Nirvana.\n");
  tell_room(environment(), "Into this state of marriage then, these two people have come\n");
  tell_room(environment(), "together to be joined.\n");
  tell_room(environment(), "\n");
  remove_call_out("ceremony_seven");
  call_out("ceremony_eight", 16);
  return 1;
}

ceremony_eight() {
  tell_room(environment(), "\n");
  tell_room(environment(), MAG+ "Hera says"+NORM+":  Do you, " + capitalize(mate) + ", offer " + capitalize(spouse) + " not only the\n");
  tell_room(environment(), "summer of your life but the autumn, brisk and vibrant?  Do you\n");
  tell_room(environment(), "promise to be a companion worthy of " + capitalize(spouse) + "'s most precious\n");
  tell_room(environment(), "friendship?  Do you " + capitalize(mate) + " pledge your love and compassion\n");
  tell_room(environment(), "in good times and bad, encouragement in sickness and health?  Do\n");
  tell_room(environment(), "you promise to cherish the memories of your individual pasts, and\n");
  tell_room(environment(), "create a new life as you both start this new journey together?\n");
  remove_call_out("ceremony_eight");
  call_out("ceremony_nine", 16);
  return 1;
}

ceremony_nine() {
  tell_room(environment(), "\n");
  tell_room(environment(), MAG+ "Hera says"+NORM+":  Do you, " + capitalize(spouse) + ", offer " + capitalize(mate) + " not only the\n");
  tell_room(environment(), "summer of your life but the autumn, brisk and vibrant?  Do you\n");
  tell_room(environment(), "promise to be a companion worthy of " + capitalize(mate) + "'s most precious\n");
  tell_room(environment(), "friendship?  Do you " + capitalize(spouse) + " pledge your love and compassion\n");
  tell_room(environment(), "in good times and bad, encouragement in sickness and health?  Do\n");
  tell_room(environment(), "you promise to cherish the memories of your individual pasts, and\n");
  tell_room(environment(), "create a new life as you both start this new journey together?\n");
  remove_call_out("ceremony_nine");
  call_out("stop_ceremony", 200);
  return 1;
}

pronouncement() {
  object ring1, ring2;
  log_file("dreamspeakr.marry", mate + " married " + spouse + " " + ctime() + "\n");
  tell_room(environment(), "\n");
  tell_room(environment(), MAG+ "Hera says"+NORM+": Then by the power vested in me by Dreamspeakr the\n");
  tell_room(environment(), "Shaman and the gods of Nirvana, I join you in the bonds of \n");
  tell_room(environment(), "matrimony.\n");
  tell_room(environment(), "\n");
  tell_room(environment(), MAG+ "Hera says"+NORM+": Take these rings as symbols of your enduring\n");
  tell_room(environment(), "affection for one another.\n");
  tell_room(environment(), "\n");
  tell_room(environment(), prompt);
  ring1=clone_object("/players/dreamspeakr/WEDDING/OBJ/wedding_ring.c");
  ring2=clone_object("/players/dreamspeakr/WEDDING/OBJ/wedding_ring.c");
  ring1->set_spouse(spouse_ob->query_real_name());
  ring2->set_spouse(mate_ob->query_real_name());
  ring1->set_married( 2 );
  ring2->set_married( 2 );
  move_object(ring1, present(mate_ob));
  move_object(ring2, present(spouse_ob));
/* Changed from channel msg to channel junk. 7/99  -Snow */
  emit_channel("junk", "\n");
  emit_channel("junk", HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
  emit_channel("junk", HIW+"     "+capitalize(mate) + " and " + capitalize(spouse) +" are joined in marriage!  \n"+NORM);
  emit_channel("junk", HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
  emit_channel("junk", "\n");
  mate=0; spouse=0; ceremony_in_progress=0;
  mate_ob=0; spouse_ob=0; mate_yes=0; spouse_yes=0;
  remove_call_out("stop_ceremony");
  return 1;
}

stop_ceremony() {
  say("\n" +MAG+ "Hera says"+NORM+": Since you have not answered I will " +
   "end the ceremony.\n");
  say(prompt);
  mate=0; spouse=0; ceremony_in_progress=0;
  mate_ob=0; spouse_ob=0; mate_yes=0; spouse_yes=0;
}
