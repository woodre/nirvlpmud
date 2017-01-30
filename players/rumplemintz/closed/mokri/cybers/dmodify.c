#include "/players/mokri/define.h"

/*
* returns a damage modifier for cyberninjas, based on stats
   * and guild levels.
* NOTE: an enhancement at a cost of 160k credits (1 credit == 1 coin)
*       must be purchased by the guild member to be able to
*       gain these modifiers.
   */

int modify_damage() {
   int modifier;
   
   /* stats that will figure into our formula */
   int int_modify, ste_modify, dex_modify, luc_modify;
   
   /* guild variables that will fit into our formula */
   int honor, attack_mode, art_level;
   
   
   /* return 0 if not a cyber, don't have the implant, or are not PK */
      if(!present("guild_implants",TP) || !present("guild_implants",TP)->query_neural_link() || !TP->query_pl_k())
      {
      return 0;
   }
   
   /* set variables */
   int_modify = (int)TP->query_attrib("int");
   ste_modify = (int)TP->query_attrib("ste");
   dex_modify = (int)TP->query_attrib("dex");
   luc_modify = (int)TP->query_attrib("luc");
   
   honor = (int)present("guild_implants",TP)->query_honor();
   attack_mode = (int)present("guild_implants",TP)->query_attack_mode();
   art_level = (int)present("guild_implants",TP)->query_art_level();
   
   /* start building the modifier */
      modifier = int_modify / 6;
   modifier += ste_modify / 6;
   modifier += dex_modify / 10;
   modifier += luc_modify / 10;
   
   /* randomize it! */
   modifier = random(modifier) + 3;
   
   /* build on guild variables */
   modifier += honor / 10;
   modifier += art_level;
   
   /* modify */
      modifier = random(modifier) + 1;
   
   /* cut in half if in 'normal' mode, cut into 1/4 if in 'stealth' mode */
      if(attack_mode == 0) modifier /= 2;
   if(attack_mode == 2) modifier /= 4;
   
   modifier += 1;
   
   return modifier;
}
