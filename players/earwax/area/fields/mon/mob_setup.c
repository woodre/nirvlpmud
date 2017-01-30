#include "../defs.h"
inherit WAXFUNS;

  int wield_weapons(object ob) { ob->init_command("wield weapon"); }
/* =========================================================================
 * Lieutenant
 * =========================================================================
*/
object make_lt() {
  object ob, ob2;

  ob = clone_object("/obj/monster.c");

  ob->set_name(GRN+"Lt. Pettibritches"+NORM+NORM);
  ob->set_alias("lt");
  ob->set_race("guard");
  ob->set_level(16);
  ob->set_gender("male");
  ob->set_al(0);
  ob->set_can_kill(1);
  ob->set_short("Lt. Pettibritches of the "+ENG);
  ob->set_long(line_wrap("This Lieutenant (or L.T. for short), is actually a fairly hard worker.  His last name is 'Pettibritches' and is on a small name tag on the front of his uniform.  He's not an intimidating physical presence, at roughly 5'9 and 170 lbs after eating a big meal, but he's been well-trained considering his humble military occupation."));

  ob2 = clone_object(OPATH+"wallet");
  ob2->set_money(750);
  move_object(ob2,ob);
  
  ob2 = clone_object("/obj/weapon");
  ob2->set_id("sword");
  ob2->set_name("An Officer's Sword");
  ob2->set_alt_name("sword");
  ob2->set_short("An officer's sword");
  ob2->set_long(line_wrap("This is an officer's sword.  It's not specific to the officer's in the "+ENG+", it's just a sword that was bought at the place they all get theirs from.\n"));
  ob2->set_type("sword");
  ob2->set_weight(2);
  ob2->set_class(10);
  ob2->set_value(500+random(500));
  ob2->set_wc(10);
  move_object(ob2, ob);
  ob->init_command("wield sword");
  ob->set_wc(22);
  ob->set_ac(14);

  ob->set_chat_chance(15);
  ob->set_a_chat_chance(20);
  ob->load_chat("Lt. Pettibritches fills out some paperwork.\n");
  ob->load_chat("Lt. Pettibritches checks some beano-reports.\n");
  ob->load_chat("The Lt. looks around.\n");
  ob->load_chat("The Lieutenant rubs his eyes.\n");
  ob->load_chat("The Lieutenant decides against waking the Captain.\n");
  ob->load_chat("Lt. Pettibritches hollers 'Sergeant, I'm under attack!'\n");
  ob->load_a_chat("Lt. Pettibritches tries to remember his combat training.\n");
  ob->load_a_chat("Lt. Pettibritches whips his sword around his head Conan-style.\n");
  ob->load_a_chat("Lt. Pettibritches calls some cadence: 'They say that in the army, ...'\n");
  ob->load_a_chat("'The food is mighty fine.  Chicken jumped off the table, \n");
  ob->load_a_chat("'started marching time.'\n");
  return ob;
}


/* =========================================================================
 * Captain
 * =========================================================================
*/
object make_capt() {
  object ob, ob2;

  ob = clone_object("/obj/monster.c");

  ob->set_name(GRN+"Captain"+NORM+NORM);
  ob->set_alias("captain");
  ob->set_race("guard");
  ob->set_level(17);
  ob->set_gender("male");
  ob->set_al(0);
  ob->set_can_kill(1);
  ob->set_short("Captain Ghettochicken "+ENG);
  ob->set_long(line_wrap("Captain Ghettochicken (so-called because he looks like a pigeon) is a career guardsman.  He's been in the "+GRN+"Earwaxian National Guard"+NORM+NORM+" for twelve years, and attained a rank that anybody with real drive normally attains in four.  He greatly prefers sitting in the officer quarters daydreaming about becoming a general instead of doing anything to get himself into that position..\n"));

  ob2 = clone_object(OPATH+"wallet");
  ob2->set_money(1000+random(100));
  move_object(ob2,ob);

  ob2 = clone_object("/obj/weapon");
  ob2->set_id("sword");
  ob2->set_name("An Officer's Sword");
  ob2->set_alt_name("sword");
  ob2->set_short("An officer's sword");
  ob2->set_long(line_wrap("This is an officer's sword.  It's not specific to the officer's in the "+ENG+", it's just a sword that was bought at the place they all get theirs from.\n"));
  ob2->set_type("sword");
  ob2->set_weight(2);
  ob2->set_class(12);
  ob2->set_value(1000+random(100));
  move_object(ob2, ob);
  ob->init_command("wield sword");
  ob->set_wc(24);
  ob->set_ac(14);

  ob->set_chat_chance(15);
  ob->set_a_chat_chance(20);
  ob->load_chat("The captain bellows, 'That Lieutenant had better not bother me!'\n");
  ob->load_chat("The captain tries to get some sleep.\n");
  ob->load_chat("The captain comes up with brilliant ways to avoid working.\n");
  ob->load_chat("The captain scratches himself.\n");
  ob->load_a_chat("The captain bellows 'Where are all my guards?!?'\n");
  ob->load_a_chat("The captain cries, 'Someone bring me a can of whoopass!'\n");
  ob->load_a_chat("The captain yells, 'Don't you know who I am?  I'm the captain!'\n");
  ob->load_a_chat("The captain tries to delegate this combat off on a subordinate.\n");

  return ob;
}


/* =========================================================================
 * Sergeant
 * =========================================================================
*/
object make_sgt() {
  object ob, ob2;

  ob = clone_object("/obj/monster.c");

  ob->set_name(GRN+"Sergeant"+NORM+NORM);
  ob->set_alias("sergeant");
  ob->set_race("guard");
  ob->set_level(15);
  ob->set_gender("male");
  ob->set_al(0);
  ob->set_can_kill(1);
  ob->set_short("A Sergeant in the "+ENG);
  ob->set_long(line_wrap("The desk sergeant has been in the "+GRN+"Earwaxian National Guard"+NORM+NORM+" for a long time, to earn his desk and right to yell at the corporals and privates under him.  Unfortunately, during that time, he's done little but move papers from one pile to another.  Even so, he's a little bit tougher than your average corporal.\n"));

  ob2 = clone_object(OPATH+"wallet");
  ob2->set_money(400+random(200));
  move_object(ob2,ob);

  ob2 = clone_object("/obj/weapon");
  ob2->set_id("sword");
  ob2->set_name("An NCO Sword");
  ob2->set_alt_name("sword");
  ob2->set_short("A Non-Commisioned Officer's sword");
  ob2->set_long(line_wrap("This is an non-commissioned-officer's sword.  It's basically just an slightly better balanced longsword than the regular troops carry in the "+ENG+".\n"));
  ob2->set_type("sword");
  ob2->set_weight(2);
  ob2->set_class(9);
  ob2->set_value(400+random(200));
  move_object(ob2, ob);
  ob->init_command("wield sword");
  ob->set_wc(20);
  ob->set_ac(12);

  ob->set_chat_chance(15);
  ob->set_a_chat_chance(20);
  ob->load_chat("The sergeant bellows, 'I'd better not see any beanos out there.'\n");
  ob->load_chat("The sergeant looks through some papers.\n");
  ob->load_chat("The sergeant leans back and almost falls off his chair.\n");
  ob->load_chat("The sergeant cleans a few flecks of rust off his sword.\n");
  ob->load_chat("The sergeant scratches his head, wondering what he isn't forgetting to do.\n");
  ob->load_chat("The sergeant grumbles something about the '@#%$@#% Marines.'\n");
  ob->load_a_chat("The sergeant opens up a tiny can of whoopass!\n");
  ob->load_a_chat("The sergeant cries, 'You know, I almost went into the Marines.'\n");
  ob->load_a_chat("The sergeant whines, 'Fighting is too much effort, let's do paperwork instead.'\n");
  ob->load_a_chat("The sergeant tries to hide under his desk.\n");

  return ob;
}

/* =========================================================================
 * Corporal
 * =========================================================================
*/
object make_cpl() {
  object ob, ob2;

  ob = clone_object("/obj/monster.c");

  ob->set_name(GRN+"Corporal"+NORM+NORM);
  ob->set_alias("corporal");
  ob->set_race("guard");
  ob->set_level(14);
  ob->set_gender("male");
  ob->set_al(0);
  ob->set_can_kill(1);
  ob->set_short("A Corporal in the "+ENG);
  ob->set_long(line_wrap("A slovenly, bad-mannered "+GRN+"Earwaxian National Guardsman"+NORM+NORM+" returns your gaze with blatant disgust.  Although he has slightly more authority than a private, he's still pretty much at the bottom of the totem pole, especially in the ENG.  He rules his privates with an iron fist, mainly because it means less work for him to do.  Plus, he just enjoys having someone to push around.\n"));

  ob2 = clone_object(OPATH+"wallet");
  ob2->set_money(300+random(300));
  move_object(ob2,ob);

  ob2 = clone_object("/obj/weapon");
  ob2->set_id("sword");
  ob2->set_name("Longsword");
  ob2->set_alt_name("sword");
  ob2->set_short("A Longsword");
  ob2->set_long(line_wrap("This is a sword that belonged to a corporal in the "+ENG+".\n"));
  ob2->set_type("sword");
  ob2->set_weight(2);
  ob2->set_class(8);
  ob2->set_value(300);
  move_object(ob2, ob);
  ob->init_command("wield sword");
  ob->set_wc(18);
  ob->set_ac(11);


  ob->set_chat_chance(10);
  ob->set_a_chat_chance(20);
  ob->load_chat("The corporal hollers, 'Where are my privates!?!'\n");
  ob->load_chat("The corporal grumbles something about 'weekend warriors.'\n");
  ob->load_chat("The corporal ponders on ways to get out of his work.\n");
  ob->load_chat("The corporal reminisces about the good old days of doing nothing.\n");
  ob->load_a_chat("The corporal screams, 'Privates ATTACK!'\n");
  ob->load_a_chat("The corporal grunts in fatigue as he lifts his sword.\n");
  ob->load_a_chat("The corporal slaps at you ineffectually.\n");
  ob->load_a_chat("The corporal grumbles about not receiving combat pay for this.\n");

  return ob;
}

/* =========================================================================
 * Private
 * =========================================================================
*/
object make_pvt() {
  object ob, ob2;

  ob = clone_object("/obj/monster.c");

  ob->set_name(GRN+"Private"+NORM+NORM);
  ob->set_alias("private");
  ob->set_race("guard");
  ob->set_level(13);
  ob->set_gender("male");
  ob->set_al(0);
  ob->set_can_kill(1);
  ob->set_short("A Private in the "+ENG);
  ob->set_long(line_wrap("A slovenly, overweight "+GRN+"Earwaxian National Guardsman"+NORM+NORM+" leers back at you.  His camouflage blouse is tattered and patched almost beyond recognition, and the rest of his uniform is just as bad.  Obviously this one joined the National Guard for the easy paycheck and low chance of every actually having to do anything.\n"));

  /* Cash */
  ob2 = clone_object(OPATH+"wallet");
  ob2->set_money(300+random(200));
  move_object(ob2,ob);

  /* Weapon */
  ob2 = clone_object("/obj/weapon");
  ob2->set_id("sword");
  ob2->set_name("Longsword");
  ob2->set_alt_name("sword");
  ob2->set_short("A Longsword");
  ob2->set_long(line_wrap("This is a sword that belonged to a private in the "+ENG+".\n"));
  ob2->set_type("sword");
  ob2->set_weight(3);
  ob2->set_class(7);
  ob2->set_value(200);
  move_object(ob2,ob);
  ob->init_command("wield sword");
  ob->set_wc(17);
  ob->set_ac(10);

  ob->set_chat_chance(10);
  ob->set_a_chat_chance(20);
  ob->load_chat("The private whines, 'I was supposed to only have to work one weekend a month!\n");
  ob->load_chat("The private asks, 'Are beanos really as fierce as they say?'\n");
  ob->load_chat("The private scratches himself.\n");
  ob->load_chat("The private asks, 'You think we'll really have to fight beanos?'\n");
  ob->load_a_chat("The private whines, 'They never said I'd have to fight anyone!'\n");
  ob->load_a_chat("The private gripes, 'I don't get paid enough for this crap.'\n");
  ob->load_a_chat("The private adjusts himself for battle.\n");
  ob->load_a_chat("The private looks around for a can of whoop-ass.  He doesn't find it.\n");
  return ob;
}

string get_warcry(int level) {
  return GRN+"almost wets himself, but leaps to the attack!\n"+NORM+NORM;
}

