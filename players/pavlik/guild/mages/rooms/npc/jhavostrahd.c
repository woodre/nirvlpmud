#include "/players/pavlik/guild/mages/macs2"
inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Jhavostrahd");
 set_alias("jhavostrahd");
 set_short("Jhavostrahd the Sage");
 set_long(
 "Jhavostrahd is a severely old man who has dedicated his life\n"+
 "to the pursuit of knowledge.  His long white beard flows down to\n"+
 "his knees.  A metal cap covers his balding head and there\n"+
 "is always a book in his hand.\n");
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
    say("Jhavostrahd says:  You are not ready for more training.\n");
    return 1;
  }

  if(stat == "int" || stat == "intel" || stat == "intelligence") {
    if(PAV->stat_limit("int")) return 1;
    what = "Intelligence";
  }
  else if(stat == "pow" || stat == "power") {
    if(PAV->stat_limit("pow")) return 1;
    what = "Power";
  }
  else {
    say("Jhavostrahd says:  I cannot train you in "+stat+".\n");
    say("Jhavostrahd says:  I will train your "+CYN+"intelligence"+NORM+
    " or "+CYN+"power"+NORM+".\n");
    return 1;
  }
  write(
  "Jhavostrahd says: You do well to excerise the mind, student.  Your\n"+
  "mind is the key to many doors beyond which lies untold powers.\n");
  say(ME+" trains his "+what+" under Jhavostrahd's tutelage.\n");

  amt = PAV->stat_increase_amount("wis");

  write("Your "+what+" increases "+amt+"%.\n");
  if(what == "Intelligence") guild->raise_intelligence(amt);
  if(what == "Power") guild->raise_power(amt);
  guild->add_training_sessions(-1);

  return 1;
}

