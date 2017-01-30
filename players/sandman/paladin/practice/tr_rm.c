
/*
 * TRAINING ROOM
 * Where Paladins can raise their weapon proficiencies
 * and combat modifiers.
 */

/* minimum alignment reguired for training and practicing */
#define MIN_ALIGN 0

/* log training (weapon proficiencies & combat modifiers) */
#define LOG_TRAINING

/* directory for log files */
#define LOGPATH "/players/sandman/paladin/log/"

/* Formats columns nicely */
justify(str, len){return extract(str+"                             ",0,len-1);}

#define MAX_PRO 20              /* maximum weapon proficiency */
#define MAX_MOD 20              /* maximum combat modifier */

reset(arg) {
   if(!arg)
     set_light(1);
}

init() {
   add_action("train","train");
   add_action("practice","practice");
   add_action("maxpractice","maxpractice");
   add_action("maxtrain","maxtrain");
   add_action("south","south");
   add_action("cost_for_training","cost");
}

short() { return "The Paladin Training Room"; }

long() {
   write("You are in the Paladin Training Room.\n");
   write("Here you may raise your combat modifiers and weapon\n");
   write("proficiencies. Training will increase your combat bonus,\n");
   write("while practicing increases your weapon bonus. You can use\n"); 
   write("the commands maxtrain and maxpractice to raise your abilities\n"); 
   write("multiple times.\n");
   write("Commands: train, maxtrain, practice, maxpractice, cost\n");
   write("     There is one obvious exit:  south\n");
}

south() {
   this_player()->move_player("south#players/sandman/paladin/practice/hall");
   return 1;
}

/*
 * For raising combat modifiers
 */

train(str) {
   object guild;
   string what;
   int mod, lvl;
   int cost;

   guild = present("guild_medal", this_player());
   if(!guild) {
     write("You are not a Paladin, you cannot use this command.\n");
     return 1;
   }
   if(!str || sscanf(str, "%s", what) != 1) {
     write("Usage: train <mounted/shield/dual>\n");
     return 1;
   }
   if(what != "dual" && what != "shield" && what != "mounted") {
     write("Usage: train <shield/dual/mounted>\n");
     return 1;
   }
   if(this_player()->query_alignment() < MIN_ALIGN) {
     write("You are too evil to advance as a Paladin.\n");
     return 1;
   }
   lvl = this_player()->query_level(); 
   mod = guild->query_combat_mod(what);
   if(mod >= MAX_MOD) {
     write("Your "+what+" combat modifier is at its maximum.\n");
     return 1;
   }
   if(mod >= (lvl + 4)) {
     write("You must be of a higher level before you can train more.\n");
     return 1;
   }
   cost = get_cost("mod", mod);
   if(this_player()->query_money() < cost) {
     write("You do not have enough money. Cost is "+cost+" gp.\n");
     return 1;
   }
   this_player()->add_money(-cost);
   write("You pay the "+cost+" gp training fee.\n");
   guild->set_combat_mod(what, (mod+1));
   write("Your "+what+" combat modifier is now "+(mod+1)+".\n");
#ifdef LOG_TRAINING     
   write_file(LOGPATH+"train", 
      capitalize(this_player()->query_real_name())+" advanced combat "+
      "modifier <"+what+"> to "+(mod+1)+" => "+ctime(time())+"\n");
#endif     
   guild->save_medal();
   return 1;
}

maxtrain(str) {
   string what;
   object guild;
   int max, mod, i;

   guild = present("guild_medal", this_player());
   if(!guild) {
     write("This command is for Paladins only.\n");
     return 1;
   }
   if(!str || sscanf(str, "%s %d", what, max) != 2) {
     write("Usage: maxtrain <shield/dual/mounted> <amt>\n");
     return 1;
   }
   if(this_player()->query_alignment() < MIN_ALIGN) {
     write("You are too evil to advance as a Paladin.\n");
     return 1;
   }
   if(max > MAX_MOD)
     max = MAX_MOD;
   mod = guild->query_combat_mod(what);
   if(mod >= max) {
     write("You must specify a higher level.\n");
     return 1;
   }
   for(i=mod; i < max; i++)
      train(what);
   return 1;
}

/*
 * For raising weapon proficiencies
 */

practice(str) {
   object guild;
   string what;
   int pro, lvl, cost;

   guild = present("guild_medal", this_player());
   if(!guild) {
     write("You are not a Paladin, you cannot use this command.\n");
     return 1;
   }
   if(!str || sscanf(str, "%s", what) != 1) {
     write("Usage: practice <sword/lance/flail/mace/axe>\n");
     return 1;
   }
   if(what != "sword" && what != "lance" && what != "flail" &&
      what != "mace" && what != "axe") {
     write("Usage: practice <sword/lance/flail/mace/axe>\n");
     return 1;
   }
   if(this_player()->query_alignment() < MIN_ALIGN) {
     write("You are too evil to advance as a Paladin.\n");
     return 1;
   }
   lvl = this_player()->query_level();
   pro = guild->query_weapon_pro(what);
   if(pro >= MAX_PRO) {
     write("Your "+what+" weapon proficiency is at its maximum.\n");
     return 1;
   }
   if(pro >= (lvl + 4)) {
     write("You must be of a higher level before you can practice more.\n");
     return 1;
   }
   cost = get_cost("pro", pro);
   if(this_player()->query_money() < cost) {
     write("You do not have enough money. Cost is "+cost+" gp.\n");
     return 1;
   }
   this_player()->add_money(-cost);
   write("You pay the "+cost+" gp practice fee.\n");
   guild->set_weapon_pro(what, (pro+1));
   write("Your "+what+" weapon proficiency is now "+(pro+1)+".\n");
#ifdef LOG_TRAINING     
   write_file(LOGPATH+"train", 
      capitalize(this_player()->query_real_name())+" advanced weapon "+
      "proficiency <"+what+"> to "+(pro+1)+" => "+ctime(time())+"\n");
#endif     
   guild->save_medal();
   return 1;
}

maxpractice(str) {
   string what;
   object guild;
   int max, pro, i;

   guild = present("guild_medal", this_player());
   if(!guild) {
     write("This command is for Paladins only.\n");
     return 1;
   }
   if(!str || sscanf(str, "%s %d", what, max) != 2) {
     write("Usage: maxpractice <sword/lance/flail/mace/axe> <amt>\n");
     return 1;
   }
   if(this_player()->query_alignment() < MIN_ALIGN) {
     write("You are too evil to advance as a Paladin.\n");
     return 1;
   }
   if(max > MAX_PRO)
     max = MAX_PRO;
   pro = guild->query_weapon_pro(what);
   if(pro >= max) {
     write("You must specify a higher level.\n");
     return 1;
   }
   for(i=pro; i < max; i++)
      practice(what);
   return 1;
}

cost_for_training() {
   int sword, flail, lance, mace, axe;
   int shield, dual, mounted;
   object guild;

   guild = present("guild_medal", this_player());
   if(!guild) {
     write("This command is for Paladins only.\n");
     return 1;
   }
   sword = guild->query_weapon_pro("sword");
   flail = guild->query_weapon_pro("flail");
   lance = guild->query_weapon_pro("lance");
   mace = guild->query_weapon_pro("mace");
   axe = guild->query_weapon_pro("axe");
   shield = guild->query_combat_mod("shield");
   dual = guild->query_combat_mod("dual");
   mounted = guild->query_combat_mod("mounted");
   write(justify("Proficiency",20)+justify("Cost (gp)",10));
     write(justify(" ",10));
     write(justify("Combat Method",25)+justify("Cost (gp)",10)+"\n"); 
   write(justify("===========",20)+justify("=========",10));
     write(justify(" ",10));
     write(justify("=============",25)+justify("=========",10)+"\n");  
   write(justify("Sword:",20)+justify(get_cost("pro",sword),10));
     write(justify(" ",10));
     write(justify("Shield & Sword:",25)+
                               justify(get_cost("mod",shield),10)+"\n");
   write(justify("Flail:",20)+justify(get_cost("pro",flail),10));
     write(justify(" ",10));
     write(justify("Dual Weapons:",25)+
                                 justify(get_cost("mod",dual),10)+"\n");
   write(justify("Lance:",20)+justify(get_cost("pro",lance),10));
     write(justify(" ",10));
     write(justify("Mounted:",25)+justify(get_cost("mod",mounted),10)+"\n");
   write(justify("Mace:",20)+justify(get_cost("pro",mace),10)+"\n");
   write(justify("Axe:",20)+justify(get_cost("pro",axe),10)+"\n");
   return 1;
}

int cost_str;

get_cost(what, str) {
   if(!cost_str){
     cost_str = allocate(20);
        
     cost_str[19]  =    6675;
     cost_str[18]  =    6100;
     cost_str[17]  =    5550; 
     cost_str[16]  =    5025;
     cost_str[15]  =    4525;
     cost_str[14]  =    3950;
     cost_str[13]  =    3500;
     cost_str[12]  =    3075;
     cost_str[11]  =    2675;
     cost_str[10]  =    2300;
     cost_str[9]   =    1950;
     cost_str[8]   =    1625;
     cost_str[7]   =    1325;
     cost_str[6]   =    1050;
     cost_str[5]   =     825;
     cost_str[4]   =     625;
     cost_str[3]   =     450;
     cost_str[2]   =     300;
     cost_str[1]   =     175;
     cost_str[0]   =      75;
   }
   if(what == "pro" && str < MAX_PRO)  /* weapon proficiency */
     return cost_str[str]/5;  /* divide it by the number of weapon types */
   if(what == "mod" && str < MAX_PRO)
     return cost_str[str]/3;    /* divide it by the # of combat methods */
                                /* do not include standard combat method */
   return "AT MAX";
}


