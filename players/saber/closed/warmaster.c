
/*
 * WARMASTER (4/6/94)
 * Trains Bards so they can increase their weapon proficiency.
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("armitage");
   set_alias("warmaster");
   set_alt_name("paladin");
   set_short("Armitage, the Warmaster of Paladins");
   set_long("Armitage is clad in full plate mail and wielding a huge\n"+
      "broadsword. His stance is that of a combat veteran: calm, but\n"+
      "poised to strike at the slightest hint of trouble.\n"+
      "He was be assigned by the Lord Molasar, Guildmaster of Paladins,\n"+
      "to train the faithful Bards of the Mighty Saber so that they\n"+
      "might join ranks and vanquish the villainy which is threatening\n"+
      "to overrun the realm of Nirvana.\n"+
      "COMMANDS: train, change, join alliance\n");
   set_level(20);
   set_ac(10);
   set_wc(30);
   set_hp(500);
   set_aggressive(0);
   set_al(450);
   ::reset();
}

init() {
   add_action("join","join");
   add_action("change","change");
   add_action("train","train");
   ::init();
}

/* The highest weapon proficiency a Bard can have */
#define MAX_WP 10

/* The cost for training */
#define COST 500

/* If you wish to log training, define the following */
#define LOG_TRAINING
#define LOG_PATH "/players/sandman/paladin/log/"

train() {
   object guild;
   int pro, lvl;
   
   guild = present("instrument", this_player());
   if(!guild) {
     write("Armitage looks you over carefully.\n");
     write("Armitage says: You are not a Bard! Be on your way!\n");
     return 1;
   }
   pro = guild->query_weapon_pro("sword");
   if(pro >= MAX_WP) {
     write("Armitage says: You have all the training I can give you.\n");
     write("               It is time you went out into the world and\n");
     write("               used your new skills for the good of mankind.\n");
     return 1;
   }
   lvl = this_player()->query_level();
   if(pro >= (lvl + 4)) {
     write("Armitage says: You must go out and gain experience with the\n");
     write("               skills I have already taught you before you\n");
     write("               can learn more.\n");
     return 1;
   }
   if(this_player()->query_money() < COST) {
     write("Armitage says: You do not have enough money!\n");
     return 1;
   }
   this_player()->add_money(-COST);
   write("Armitage accepts the training fee of "+COST+" gp.\n");
   guild->set_weapon_pro("sword", (pro+1));
   write("After an intensive practice routine with Warmaster Armitage\n");
   write("you are exhausted and your bones ache. Even though it was\n");
   write("strenuous work you still feel elation at the increase of\n");
   write("your weaponry skills.\n");
#ifdef LOG_TRAINING     
   write_file(LOG_PATH+"train", 
      capitalize(this_player()->query_real_name())+" advanced sword"+
      " proficiency to "+(pro+1)+" => "+ctime(time())+"\n");
#endif     
   return 1;
}

/* Filename of the shadowing object */
#define SHADOW "/players/sandman/paladin/obj/weap_sh"

join(str) {
   object guild, all_obj;

   if(!str || str != "alliance") 
     return;
   if(!present("guild_medal", this_player()) && 
                !present("instrument",this_player())) {
    write("Armitage says: This alliance is between the Bards and Paladins!\n");
     write("               You are neither. Be gone!\n");
     return 1;
   }
   if(present("alliance_obj", this_player())) {
     write("Armitage gives you a puzzled look.\n");
     write("Armitage says: You are already a member of the Alliance!\n");
     return 1;
   }
   all_obj = clone_object("players/saber/closed/bards/coat_of_arms");
   move_object(all_obj, this_player());
   command("ale has joined the Alliance!", this_player());
   return 1;
}

change(str) {
   object shadow, weapon;
   
   if(!str) {
     write("Armitage says: What weapon would you like me to change?\n");
     return 1;
   }
   weapon = present(str, this_player());
   if(!weapon) {
     write("Armitage looks you over carefully.\n");
     write("Armitage says: You have no "+str+"!\n");
     return 1;
   }
   if(!weapon->weapon_class()) {
     write("Armitage gives you an odd look.\n");
     write("Armitage says: That is not a weapon!\n");
     return 1;
   }
   if(weapon->query_pro_weapon()) {
     write("Armitage examines the "+str+", then hands it back to you.\n");
     write("Armitage says: That weapon has already been changed.\n");
     return 1;
   }
   write("Armitage takes your weapon and utters a prayer.\n");   
   shadow = clone_object(SHADOW);
   shadow->start_weapon_shadow(weapon);
   write(weapon->short()+" glows brightly.\n");
   write("Armitage hands the "+str+" back to you.\n");
   write("Armitage says: Your weapon will be more powerful now.\n");
   return 1;
}

