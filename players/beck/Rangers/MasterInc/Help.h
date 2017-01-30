ranger_help(str){
   write("********************Power Rangers**********************************\n");
   if(!str){
      write(""+
         "\n"+
         "The Power Rangers guild is based loosely on the Fox TV show.\n"+
         "It should be considered a 'good' guild, where teamwork is the\n"+
         "main objective.  In this guild any weak link will be amplified.\n"+
         "This guild is designed as a role playing guild. The experience\n"+
         "cost is very high, but I do not disclose the exact numbers to\n"+
         "players. \n"+
         "Please see the following topics for much more information.\n"+
         "\n"+
         "     Topics:\n"+
         "               Morphed   Unmorphed   Both   Training   Power\n"+
         "               Practice   Combat   Spells   Quests   Conduct\n"+
         "               Gym   Teleport  Pk                           \n"+
         "\n"+
         "To see information on a topic: type 'ranger <topic>'.\n"+
         "");
      return 1;
   }
   if(str == "training"){
      write(""+
         "*************************Power Ranger Training***********************\n"+
         "\n\n"+
         "Training for the Power Rangers guild differs slightly from that of \n"+
         "any other guild.  There is no set place for training to take place.\n"+
         "Training is done by seeking out select NPC's .\n"+
         "If you meet the requirements for a skill the trainer ask you to learn.\n"+
         "You will be prompted for a reply which will be 'yes'.\n"+
         "There are 4 types of training: Karate Belts, Offense, Defense, and\n"+
         "Skills.  There are 9 Karate Levels: White, Yellow, Orange, \n"+
         "Red, Green, Blue, Purple, Brown, Black.  These are viewed by looking\n"+
         "at yourself or with 'rsc'.  Offensive and Defensive skills are learned one at a\n"+
         "time in a specific sequence.  If you have the skill 'offense' and \n"+
         "'defense', you may see what you have already learned.  Overall skills\n"+
         "are listed in these help files, by when you can use them (morphed, \n"+
         "unmorphed, both).  Any skill designated with ($) you must learn\n"+
         "before you can use it.\n"+
         "You can also see a list of your known skills by typing 'skills'.\n"+
         "Training in this guild is completely separated from player\n"+
         "levels. A 5th level player could have max guild stats, as well \n"+
         "as a 19th level player could have none.\n"+
         "All the training currently will take place in my (Beck) area, but\n"+
         "in the future it will not be limited to this.  Anywhere in Nirvana\n"+
         "you may find the oppritunity to train.\n"+
         "");
      return 1;
   }
   if(str == "morphed"){
      write(""+
         "Availible commands while morphed:\n"+
         "unmorph      Free($) Unmorphs a ranger.\n"+
         "teleport     60  ($) Teleports a ranger to special rooms.\n"+
         "armor        2/combat round\n"+
         "                 ($) Metallic armor combat bonus.  [Toggled]\n"+
         "weapon       9-25/combat round\n"+
         "                 ($) Get your weapon.  [Toggled]\n"+
         "blast        22-158\n"+
         "                 ($) Use your Personal Blaster in combat\n"+
         "pack         20  ($) Enables your Power Pack to store items\n"+
         "lamp         Free($) Turn on/off your Helmet lamp. [Toggled]\n"+
         "jet          Free($) A speedster with maximum 5 commands.\n"+
         "                     (jet e,s,out,ne,w)\n"+
         "zord             ($) Calls personal battlezord (pet).\n"+
         "             100 + 30/karate level (when in Command Center).\n"+  
         "             200 + 60/karate level (when elsewhere).\n"+
         "megazord     1000($) Calls the thunder megazord.\n"+
         "blaster      50  ($) Calls the Ranger Power Blaster.\n"+
         "** All numbers are rated in guild power  **\n"+
         "** You can not kill good monsters while morphed!!!   **\n"+
         "");
      return 1;
   }
   if(str == "unmorphed"){
      write(""+
         "Availible commands while unmorphed:\n"+
         "morph       100-300\n"+
         "               ($) Morphs a ranger.\n"+
         "ninja       40 ($) Turns a ranger into a ninja.\n"+
         "teleport    80 ($) Teleports a ranger to special rooms.\n"+
         "** All numbers are rated in guild power  **\n"+
         "** You do not have a speedster while unmorphed, and may not use one.**\n"+
         "");
      return 1;
   }
   if(str == "both"){
      write(""+
         "Availible commands anytime:\n"+
         "rt              Free($) Ranger talk channel.\n"+
         "rte             Free($) Ranger emote channel.\n"+
         "rwho            Free($) Ranger who list.\n"+
         "rtm             Free    Toggles the guild channel on or off.\n"+
         "rsc             Free    Ranger stats.\n"+
         "ranger          Free    Ranger help files.\n"+
         "power           Free    Check guild power level.\n"+ 
         "generate <amt> <amt>($) Changes <amt> spell points to power points.\n"+
         "                        (Not 1:1 ratio though)\n"+
         "donate <object> Free($) Changes an object to a percentage of its value\n"+
         "                        into power points.\n"+
         "time            Free    Check time until reboot.\n"+
         "aid             20  ($) Allows you to fight an enemy another ranger\n"+
         "                        is already fighting regardless of alignment.\n"+
         "                        This will also teleport you to the other ranger.\n"+
         "                        if you are not in the same room for the \n"+
         "                        normal teleport cost.\n"+
         "study <thing>   Free($) Find out if an enemy is good or bad.\n"+
         "lead            20  ($) Take the lead while in battle.\n"+
         "skills          Free($) Check the skills you can use.\n"+
         "offense         Free($) Check your offensive moves you can practice.\n"+
         "defense         Free($) Check your defensive moves you can practice.\n"+
         "teach           Free($) Allows high level players to teach skills.\n"+
         "** All numbers are rated in guild power  **\n"+
         "");
      return 1;
   }
   if(str == "power"){
      write(""+
         "**************************Guild Power******************************\n"+
         "\n\n"+
         "Guild Powers are not used from spell points as in other guilds.\n"+
         "Instead there is a pool of points used by every member of the guild.\n"+
         "All guild powers are supported by this pool.\n"+
         "It will be the members of the guild own responsibility to maintain the\n"+
         "power levels.  If the pool drops below 0 no members powers will work.\n"+
         "It will take teamwork from all members to properly maintain the\n"+
         "Guild Power levels.\n"+
         "Players can add to the pool by donating their own sps (not 1:1),\n"+
         "or by donating objects for a percentage of their value in gold.\n"+
         "The guild power level is reset to 0 at every reboot.\n"+
         "Combat powers such as weapon, armor, and blast can only be used to\n"+
         "an amount equal to what that individual has donated.\n"+
         "All power still goes to and comes from the pool, but individual amounts\n"+
         "availible for combat use are recorded and displayed in 'rsc'.\n"+
         "");
      return 1;
   }
   if(str == "practice"){
      write(""+
         "*********************Guild Practice********************************\n"+
         "\n\n"+
         "Practice is a key element of the power rangers guild.\n"+
         "Much of training will require a minimum amount of practice.\n"+
         "There are 3 types of practice:  Skill, Combat, and Martial Arts.\n"+
         "Skill practice is attained by using your skills (ie generate, jet,\n"+
         "morph, etc...)\n"+
         "Combat skill is obtained by engaging in combat.\n"+
         "Martial Arts practice take place in two ways.  One is \n"+
         "by using the manual practice command with the syntax\n"+ 
         "  'practice <skill> on <living being>'  \n"+
         "Note:  Manual practice only is effective a small percentage of time.\n"+
         "   Thus spamming these is not of much use.\n"+
         "The commands 'offense' and 'defense' give a list of availible\n"+
         "skills to practice.  The manual practice will improve the\n"+
         "particular skill you have chosen as well as your overall practice.\n"+
         "Martial Arts practice also occurs automatically when\n"+
         "in combat.  If you see a message while in battle for a particular\n"+
         "move, you will get practice for that manuver as well as overall\n"+
         "practice.  These messages only will appear once you have reached\n"+
         "at least your White Belt Karate Level.\n"+
         "");
      return 1;
   }
   if(str == "combat"){
      write(""+
         "***************************COMBAT***********************************\n"+
         "\n\n"+
         "Combat is the Primary ability of the Power Rangers Guild.\n"+
         "There are a few key differences between the Rangers and any other\n"+
         "guild.\n"+
         "The main difference is that Power Rangers never have a need for \n"+
         "Armor or Weapons.  In fact they cant use them.  \n"+
         "A Power Ranger is equipped with the only weapon and armor they\n"+
         "need, automatically at the point they login to Nirvana.\n"+
         "Power Rangers can engage in combat anytime, but they receive special\n"+
         "bonuses if they are morphed.  There is a bonus for just being morphed\n"+
         "as well as an 'armor' function bonus, and a 'weapon' bonus.\n"+
         "The 'armor' and 'weapon' commands only add small bonuses that require\n"+
         "power points each round of combat.  Do NOT think that without them\n"+
         "you have no weapon or armor (I need to clarify once again that these\n"+
         "are only small bonuses).\n"+
         "To improve your combat ability you should train Karate Levels, Offense,\n"+
         "Defense, and obtain the 2 skills listed above.\n"+
         "Power Rangers cannot initially attack a good creature while morphed.\n"+
         "");
      return 1;
   }
   if(str == "spells"){
      write(""+
         "******************************SPELLS**********************************\n"+
         "\n\n"+
         "Power Rangers have no spell use capability.  They may not use \n"+
         "the standard game spells, and there are no guild spells.\n"+
         "There is no guild healing spell either.\n"+
         "Power Rangers are designed to be completely hand to hand combat\n"+
         "oriented.\n"+
         "");
      return 1;
   }
   if(str == "quests"){
      write(""+
         "****************************QUESTS************************************\n"+
         "\n\n"+
         "At this time there are no special guild quest that you will partake in.\n"+
         "The only thing you need to do is seek out the people you need to train\n"+
         "with.  That is not really questing as it is not at all hard to do.\n"+
         "Rather it is designed for role playing atmosphere purposes.\n"+
         "");
      return 1;
   }
   if(str == "conduct"){
      write(""+
         "*******************************CONDUCT********************************\n"+
         "\n\n"+
         "As a member of the Power Rangers I expect you will conduct yourself\n"+
         "in a manner and role in accordance to the guild.  The Power Rangers\n"+
         "are 'good' and I expect for players to assume that role while using\n"+
         "their Power Ranger character.\n"+
         "I will not tolerate evil acts by guild members, which include, but is\n"+
         "not limited to things such as: personal verbal abuse to any player or\n"+
         "wizard, extensive lack of cooperation with other guild members (using\n"+
         "guild resources without giving back, and refusing to help other guild\n"+
         "members --> showing or telling how to do things.  I frown on not \n"+
         "partying with other guild members, but will tolerate it), \n"+
         "any act that discredits the guild or its members.\n"+
         "The punishment for such offenses is automatic removal from the guild\n"+
         "and loss of all experience invested in it.\n"+
         "");
      return 1;
   }
   if(str == "gym"){
      write(""+
         "*******************************GOLDS GYM*******************************\n"+
         "\n\n"+
         "Power Rangers are able to maintain their skills through\n"+
         "the use of Golds Gym.  \n"+
         "If you don't continue training you may not be able to use some\n"+
         "skills until training resumes.\n"+
         "");
      return 1;
   }
   if(str == "teleport"){
      write(""+
         "******************************Teleporting****************************\n"+
         "\n\n"+
         "Teleporting is one of the major abilities of the Power Rangers.\n"+
         "To teleport you must first find and learn the teleport skill.\n"+
         "When you have learned it you type 'teleport <location>'.\n"+
         "The cost is 40 power points while morphed or 70 power points\n"+
         "while unmorphed.\n"+
         "Locations:\n"+
         "   command center   Power Ranger Command Center\n"+
         "   church           Village Church of Nirvana\n"+
         "   park             Angel Grove Park\n"+
         "   megaship         Power Ranger Astro Megaship (Space only)\n"+
         "   <name>           By entering the name of another Power Ranger\n"+
         "                    currently logged in as the location, you\n"+
         "                    teleport directly to the room they are in.\n"+
         "                    This also includes the NPC rangers (Tommy, etc.)\n"+
         "");
      return 1;
   }
   if(str == "pk"){
      write(""+
         "*********************Player Killing*********************************\n"+
         "\n\n"+
         "The Power Rangers are allowed to set their Player Killing if they\n"+
         "choose to do so.  \n"+
         "Be aware there is no protected guild hall, so if you set PK\n"+
         "There is NOWHERE to hide.\n"+
         "I also expect that player killers would only attack those who are\n"+
         "in 'evil' guilds.\n"+
         "");
      return 1;
   }
}

