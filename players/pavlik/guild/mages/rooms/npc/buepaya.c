#include "/players/pavlik/guild/mages/macs2"
inherit "/obj/monster";
#define POS this_player()->query_possessive()
reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Buepaya");
 set_alias("buepaya");
 set_short("Buepaya the Serene");
 set_long(
 "Before you is a short wrinkled old woman.  She sits cross-legged\n"+
 "on the floor and slowly breathes the incense that fills the\n"+
 "air around you.  You can't help to be overcome be a calmness\n"+
 "and serenity when in her prescence.\n");
 set_level(100);
 set_ac(80);
 set_wc(80);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}


catch_tell(str) {
  string junk, junk2;
  string stat, what;
  int amt;

  if(sscanf(str, "%s says: train %s\n", junk, stat) != 2)
    return;
 
  if(!guild->query_training_sessions()) {
    say("Buepaya says:  You are not ready for more training.\n");
    return 1;
  }

  if(stat == "wis" || stat == "wisdom") {
    if(PAV->stat_limit("wis")) return 1;
    what = "Wisdom";
  }
  else if(stat == "wil" || stat == "will" || stat == "will power") {
    if(PAV->stat_limit("wil")) return 1;
    what = "Will Power";
  }
  else {
    say("Buepaya says:  I cannot train you in "+stat+".\n");
    say("Buepaya says:  I will train your "+CYN+"wisdom"+NORM+
    " or "+CYN+"will power"+NORM+".\n");
    return 1;
  }
  write(
  "Buepaya says: Sit with me, student.  Magic is only as powerful\n"+
  "as the mind that wields it.  Clear your thoughts and feel the\n"+
  "mind of the universe about you.\n");
  say(ME+" trains "+POS+" "+what+" under Buepaya's tutelage.\n");

  amt = PAV->stat_increase_amount("wis");

  write("Your "+what+" increases "+amt+"%.\n");
  if(what == "Wisdom") guild->raise_wisdom(amt);
  if(what == "Will Power") guild->raise_will_power(amt);
  guild->add_training_sessions(-1);

  return 1;
}

