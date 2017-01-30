/*
A spell-casting, healing Archwizard.
03/20/06 Earwax: added check to glar_life() so masterob won't callout
also moved the call_out() to init() from reset()
*/
 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(attacker_ob->query_name())

#include "color.h"
 
inherit "/obj/monster";
 
init() { 
  ::init();
  while(remove_call_out("glar_life") != -1);
  call_out("glar_life",1);
}
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, gold;
ob = clone_object("/players/snow/armor/arch_robes.c");

move_object(ob,this_object());
gold = clone_object("obj/money");
gold->set_money(5000+random(5000));
move_object(gold,this_object());
     set_name("glarvinthal");
     set_short("A friendly wizard");
     set_race("man");
     set_alias("wizard");
     set_long(
"This is a wizened old man who appears to be very happy to see you.\n" +
"He is wearing a shimmering white robe that seems to blend well with \n" +
"his iron grey hair and beard. He looks old and weak but appearances \n" +
"can be deceiving...\n");
     set_level(30);
init_command("wear robe");
     set_ac(random(10)+10);
     set_wc(50);
     set_hp(1000);
/* NEW CODE */
set_ac_bonus(11);
set_wc_bonus(20);
     set_heal(3,2);
     set_al(1000);
     set_aggressive(0);
     set_whimpy();
   money = 6500;
      set_dead_ob(this_object());
  set_chat_chance(3);
  set_a_chat_chance(7);
  load_chat(
"Glarvinthal says: In the east tower lies an Ogre Mage's domain.\n");
  load_chat(
"Glarvinthal says: In the west tower is passage to the Tundra-\n"+
"a realm of snow, rock, ice, and demons.\n");
  load_chat(
"Glarvinthal says: The north tower provides the greatest challenge for both\n"+
"foolish and strong. The evil Icingdeath awaits his next meal.\n");
  load_chat(
"Glarvinthal says: Do not complain if you die. You have been warned.\n");
  load_chat(
"Glarvinthal says: Be careful.. and don't say I didn't warn ya!\n");
  load_a_chat(
"Glarvinthal says: Thought I was a doddering old fool, didja?\n");
   load_a_chat("Glarvinthal says: Take this you little fools!\n");
 
  set_chance(80);
  set_spell_mess1(
"Glarvinthal seems to glow with an internal light...\n"+"\n"+
"He sends a bolt of "+BOLD+"Pure Energy"+OFF+" into his foe!\n");
  set_spell_mess2(
"Glarvinthal glows with an internal light...\n"+"\n"+
"He directs a bolt of "+BOLD+"Pure Energy"+OFF+" into you!\n");
  set_spell_dam(50);
   }
}

monster_died() {
  write_file("/players/snow/closed/q/mon", ctime(time())+" "+
    query_attack()->query_name()+" killed Glarvinthal.\n");
  return 0; }

glar_life() {
  while(remove_call_out("glar_life") != -1);
/*
  if (query_hp() == 1000 && !(query_attack())) return 1;
*/
  if (environment())
    call_out("glar_life",3);
    if(TO->query_hp() < 800) glar_heal();
  if(attacker_ob) {
    if(attacker_ob == this_object()) ponder();
    if(environment(attacker_ob) == environment(TO)) r_spell();
  }
    checkup();
return 1;
}

heal_self(arg) {
  if(arg < 0) arg = -arg;
  ::heal_self(arg); }

ponder() {
  tell_room(environment(this_object()),
    "Glarvinthal stops and scratches his head.\n"+
    " The archwizard says: Now this isn't right.\n");
  this_object()->stop_fight();
  this_object()->heal_self(1000);
  return 1;
}

checkup() {
  if(this_object()->query_wc() < 45) this_object()->set_wc(80);
  return 1;
}
 
glar_heal() {
  int H;
H = random(8)+1;
  if(H > 5) {
    tell_room(environment(TO),
BLUE+"Glarvinthal's wounds seem to magically close!\n"+OFF);
  }
call_other(TO,"heal_self",H);
return 1;
}
 
r_spell() {
  int R;
R = random(10);
  if(R > 5) {
    write("Glarvinthal is wreathed in "+REV_BLUE+"POWER"+OFF+"!\n");
      if(R == 6) {
flame_ball();
return 1;
      }
      if(R == 7) {
lightning_bolt();
return 1;
      }
      if(R == 8) {
vamp_drain();
return 1;
      }
      if(R == 9) {
flame_ball();
lightning_bolt();
return 1;
      }
  }
return 1;
}
 
flame_ball() {
  tell_room(environment(TO),
"Glarvinthal conjures a "+REV_RED+"ball of flame"+OFF+" and sends it "+RED+"burning"+OFF+" at "+MEATN+"!\n");
  tell_room(environment(TO),
"The "+REV_RED+"huge, burning ball"+OFF+" crashes into "+MEATN+"!\n");
call_other(attacker_ob,"hit_player",random(50)+10);
return 1;
}
 
lightning_bolt() {
  tell_room(environment(TO),
"Glarvinthal stretches his hands toward "+MEATN+" and "+BLINK+BOLD+"Lightning"+OFF+OFF+" blasts forth!\n");
  tell_room(environment(TO),"\n"+
"The "+BOLD+"Lightning Bolt"+OFF+" sizzles into "+MEATN+"'s chest!\n");
call_other(attacker_ob,"hit_player",random(50)+15);
return 1;
}
 
vamp_drain() {
  int drain;
drain = random(30)+20;
  tell_room(environment(TO),
"Glarvinthal reaches out and drains "+GREEN+"Life Force"+OFF+" from "+MEATN+"!\n");
  tell_room(environment(TO),"\n"+
MEATN+" is drained of life!\n");
call_other(attacker_ob,"heal_self",-drain);
  tell_room(environment(TO),BLUE+"Glarvinthal appears to grow stronger!\n"+OFF);
call_other(TO,"heal_self",drain);
return 1;
}

catch_tell(string str) {
  string msg;
  if(sscanf(str,"quest%s",msg) || sscanf(str,"%squest%s",msg) ||
     sscanf(str,"%squest",msg) ) {
    call_out("qtell",3,this_player());
    return 1;
  }
  if(sscanf(str,"swords%s",msg) || sscanf(str,"%sswords%s",msg) ||
     sscanf(str,"%sswords",msg) ) {
    call_out("swtell",3,this_player());
    return 1;
  }
  if(sscanf(str,"smith%s",msg) || sscanf(str,"%ssmith%s",msg) ||
     sscanf(str,"%ssmith",msg) ) {
    call_out("smtell",3,this_player());
    return 1;
  }
  return 1;
}

qtell(object ob) {
    tell_object(ob,
      "Glarvinthal whispers to you:\n"+
      "  'Give the three great swords to the smith of darkness.'\n");
    tell_object(ob,
      "  'Fulfill the mighty purpose.'\n"+
       "  'Seek above the trees for your final task.'\n");
  return 1; }

swtell(object ob) {
    tell_object(ob,
      "Glarvinthal whispers to you:\n"+
      "  'The great swords... I know but little.\n");
    tell_object(ob,
      "   One contains a vortex within it. It is known by its weight.\n"+
      "   Another feeds on its wielder to enhance its power.\n"+
      "   The last is a sword of the corrupted flower.\n");
    tell_object(ob,
      "  Explore the worlds of the Vortex and you will find these weapons.'\n");
  return 1; }

smtell(object ob) {
     tell_object(ob,
     "Glarvinthal whispers to you:\n"+
      "  'The smith of darkness may be found in the living realm.\n"+
      "  Ask him to forge you a weapon.\n"+
      "  'He may have a price for his services. I do not know.'\n");
  return 1; }

scrolls_tell(object ob) {
  tell_object(ob, "Glarvinthal whispers to you:\n");
  if(ob->query_guild_name() != "dervish") {
  tell_object(ob, "\tYou have no need of the wisdom of Tar-Nuith.\n");
  return 1; }
  tell_object(ob,
  "\tYou seek the wisdom of Tar-Nuith, do ya?\n"+
  "\tFor eighty thousands of coins, you may buy them.\n"+
  "\tKnow, however, your future may remain uncertain...\n");
  return 1; }

buy_scrolls(str) {
  if(!str) {
    notify_fail("Glarvinthall tells you: buy what?\n"); return 0; }
  if(str == "scrolls" || str == "scroll") {
    if(this_player()->query_money() < 80,000) {
      notify_fail("Glarvinthal tells you: You lack the coinage.\n");
      return 0; }
    this_player()->add_money(-80000);
    move_object(clone_object("/players/snow/dervish/objects/scrolls.c"),
      this_player());
  this_player()->save_me();
  write("Glarvinthal hands you some scrolls.\n");
  return 1; }
  notify_fail("Glarvinthal says: buy what?\n"); return 0; }
