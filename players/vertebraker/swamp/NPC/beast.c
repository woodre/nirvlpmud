/*
* Random Swamp Monster
* Vertebraker@Nirvana April '00
*/

int wander, wander_time;
#include "../define.h"
inherit "/obj/monster";
int dest_yes;
string chat_splat,rem_obj;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_gender("creature");
   set_bullshit(0, 20);
   set_heart_beat(2);
   set_chat_chance(5);
   set_a_chat_chance(10);
   switch(random(7)) {
      case 0: pick_lil(); break;
      case 1: pick_lil(); break;
      case 2: pick_lil(); break;
      case 3: pick_lil(); break;
      case 4: pick_med(); break;
      case 5: pick_med(); break;
      case 6: pick_large(); break; }
   set_dead_ob(TO); }

pick_lil() {
   switch(random(5)) {
      case 0:
      set_short("dragonfly");
      set_name("dragonfly"); set_alias("fly"); set_race("bug"); set_level(1);
      set_long("Often seen buzzing around the swamplands, the\n"+
         "typical dragonfly is about one inch long, with large, fluttering\n"+
         "wings.  It has a small pucker stinger that it uses to \n"+
         "attack small prey.\n");
      set_hp(15); set_wc(5); set_ac(3); chat_splat = "The dragonfly explodes with a *SplaT*!";
      dest_yes = 1; load_chat("The dragonfly buzzes around your head...\n");
      load_chat("'Bzzzzz'\n"); load_chat("The dragonfly swarms around you...\n");
      load_a_chat("The dragonfly stings you!\n"); break;
      case 1:
      set_short("leech");
      set_long("This is a tiny, whitish worm-like creature that feeds on\n"+
         "blood and other wastes.  You have little to fear from it, but\n"+
         "it can be an annoying pest.\n");
      set_name("leech"); set_alias("leach"); set_race("bug"); set_level(1);
      set_hp(15); set_wc(5); set_ac(3); chat_splat = "The leech is pounded into a small amount of goo...";
      dest_yes = 1; load_chat("The leech squirms around....\n");  load_chat("*shlip*  *shlip*\n");
      load_chat("The leech inches toward you....\n"); load_a_chat("The leech draws "+HIR+"BLOOD"+NORM+" from you!\n"); break;
      case 2:
      set_short("a watersnake");
      set_long("Small, slimy, and creepy, this snake has a mean\n"+
         "disposition, but little in the way of offense OR defense.\n"+
         "It is about a foot long, with a beautiful green and yellow\n"+
         "diamond pattern on it.\n");
      set_name("snake"); set_alias("watersnake"); set_race("snake"); set_level(4);
      set_hp(60); set_wc(8); set_ac(4); chat_splat = "The snake shrivels away, leaving only its skin.";
      dest_yes = 1; rem_obj = OBJ_DIR+"snake_skin.c"; load_chat("The snake slithers through the swamp....\n");
      load_chat("The watersnake slithers slowly...\n"); load_a_chat("The snake lashes out at you!\n");
      break;
      case 3:
      set_short("duck");
      set_long("This is a small, beautiful mallard with a bright,\n"+
         "luxurious yellow beak and a light green body.  It cascades\n"+
         "in rhythm with the water.\n");
      set_name("duck"); set_alias("waterfowl"); set_race("bird"); set_level(4);
      set_hp(60); set_wc(8); set_ac(4); chat_splat = "The duck quacks for the last time....";
      dest_yes = 0; rem_obj = OBJ_DIR+"duck_beak.c"; load_chat("The duck quacks!\n");
      load_chat("QUACK QUACK\n"); load_chat("The duck ruffles its tail feathers.\n");
      load_a_chat("The duck tries to waddle away!\n"); break;
      case 4:
      set_short("A blue heron");
      set_long("A blue heron is a small bird of prey in the swamplands,\n"+
         "it catches small fish and insects rather easily, and does not\n"+
         "have many enemies.  It is about a foot and a half long, weighs about\n"+
         "seven pounds, and has sharp talons.\n");
      set_name("heron"); set_alias("blue heron"); set_race("bird"); set_level(7);
      set_hp(105); set_wc(11); set_ac(6); chat_splat = "The heron squaws, and swoops down to the swamp, dead!";
      dest_yes = 0; rem_obj = OBJ_DIR+"heron_talons.c"; load_chat("The heron soars above your head...\n");
      load_chat("The heron dives in!\n"); load_chat("A heron maintains a steady distance...\n");
      load_a_chat("The heron SCRATCHES you with its talons!\n"); break; 
   }
}

pick_med() {
   switch(random(3)) {
      case 0:
      set_short(YEL+"otter"+NORM);
      set_long("This is a cute little brown otter.  It is about three\n"+
         "feet long and weighs around twenty or so pounds.\n"+
         "It has a cute little brown nose, and a small furry tail.\n"+
         "The brown fur is rumored to be worth something to traders.\n");
      set_name("otter"); set_race("animal"); set_level(10);
      set_hp(150); set_wc(14); set_ac(8); chat_splat = "The otter squeaks in a fury, and collapses....";
      dest_yes = 0; rem_obj = OBJ_DIR+"otter_fur.c"; load_chat("The otter twitches its little nose.\n");
      load_chat("The otter races around the swamp.\n"); load_chat("The otter paws at some fish.\n");
      load_a_chat("The otter nibbles at your leg!\n"); break;
      case 1: 
      set_short("A stork"); set_name("stork"); set_race("bird");
      set_long("This is a large, two foot tall stork that feeds mainly\n"+
         "on bluefish and the like.  Its tall legs give it an\n"+
         "advantageous position in the hunt, but also give it\n"+
         "longer strides in case it is being hunted.\n"); set_level(12);
      set_hp(180); set_wc(16); set_ac(9); chat_splat = "The stork tries to run away, but fails.";
      dest_yes = 0; rem_obj = OBJ_DIR+"stork_leg.c"; load_chat("The stork strides into the water.\n");
      load_chat("The stork catches a fish in its mouth and gobbles it down.\n");
      load_a_chat("The stork begins to flap wildly!\n"); break;
      case 2: set_short(GRN+"young alligator"+NORM); set_name("young alligator"); set_alias("alligator");
      set_alt_name("gator"); set_race("animal");
      set_long("This is a small, but still dangerous gator from the\n"+
         "depths of the swamp.  It is learning how to hunt from\n"+
         "its mother before it goes out on its own, but this one\n"+
         "seems to be straggling away from the pack.\n");
      set_level(14); set_hp(210); set_wc(18); set_ac(11);
      set_aggressive(1); chat_splat = "The young alligator breaks a tooth off into the swamp water,\n and then up and dies.";
      dest_yes = 0; rem_obj = OBJ_DIR+"young_tooth.c"; load_chat("The young alligator floats around menacingly...\n");
      load_chat("The young alligator clamps its jaws up and down...\n"); load_a_chat("The small gator rips into your flesh!\n");
      load_a_chat("The small gator tries to bite into you!\n"); break;
   }
}

pick_large() {
   switch(random(2)) {
      case 0:  
      set_short(HIW+"white"+NORM+"-tailed deer");
      set_name("deer"); set_race("animal");
      set_alt_name("white"); set_alias("white deer");
      set_long("A strong looking white-tailed deer, this often grazes\n"+
         "along the banks of the swamp, rather than going inside.. This one\n"+
         "must have wandered away from the pack.  Despite its herbivoric tendencies,\n"+
         "white-tailed deer have been known to put up a small battle with its\n"+
         "small, jutting horns.\n");
      set_level(17); set_hp(425); set_wc(24); set_ac(14);
      chat_splat = "The deer takes the final hit, and then dives face-first into the swamplands.";
      dest_yes = 0; rem_obj = OBJ_DIR+"deer_hide.c"; load_chat("The deer prances around!\n");
      load_chat("The deer glances around furtively.\n"); load_a_chat("\nThe deer "+BOLD+"BUTTS"+NORM+" you with its horns!\n\n");
      break;
      case 1:
      set_short(GRN+"adult alligator"+NORM);
      set_level(21); set_wc(40); set_ac(20);
      set_name("gator"); set_race("animal");
      set_alt_name("alligator"); set_alias("adult");
      set_long(
         "This is a massive, six foot long adult alligator with fearsome\n"+
         "clamping jaws that were designed for locking, ripping, and tearing\n"+
         "away flesh.  It is not very fast, but is incredibly powerful.  It\n"+
         "is large, very scaly, and generally not something you want to meet\n"+
         "in a dark alley.\n");
      chat_splat = "\nThe alligator growls and submerges just beneath the murky waters....\n\n";
      set_hp(500+random(100));
      dest_yes = 0; rem_obj = OBJ_DIR+"gator_tooth.c"; load_chat("The alligator waddles around in the waters....\n");
      load_chat("The alligator growls...\n"); set_aggressive(1);
      load_a_chat("\nThe alligator snaps at you with its jaws!\n\n");
      set_spell_dam(90);
      set_chance(30); 
      set_spell_mess1(
         "\n\n  The crocodile tears into its attacker with\n    its massive jaws,\n "+HIR+"      R  I  P  P  I  N  G  "+NORM+"\n                 flesh away!\n\n\n");
      set_spell_mess2(
         "\n\n  The crocodile tears into you with\n      its massive jaws,\n "+HIR+"      R  I  P  P  I  N  G  "+NORM+"\n                 flesh away!\n\n\n");
      break;
   }
}

monster_died() {
   if(chat_splat) tell_room(USER,chat_splat+"\n");
   if(rem_obj) move_object(clone_object(rem_obj),USER);
   if(dest_yes) destruct(present("corpse",USER));
   return 1; }



heart_beat(){
   ::heart_beat();
   if(wander && !query_attack()) {  
      if(wander_time++ > wander && !random(4)) {
         random_move();  
      } 
   }
}   

void set_bullshit(int chance, int time) {  
   wander = time;  
   set_heart_beat(1); 
}  
