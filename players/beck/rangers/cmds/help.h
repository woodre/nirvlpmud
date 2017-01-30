ranger_help(str){
if(!str){
write(""+
"********************Power Rangers**********************************\n"+
"\n"+
"The Power Rangers guild is based loosely on the Fox TV show.\n"+
"It should be considered a 'good' guild, where teamwork is the\n"+
"main objective.  In this guild any weak link will be amplified.\n"+
"This guild is designed as a role playing guild. The experience\n"+
"cost is very high, but I do not disclose the exact numbers to\n"+
"players.\n"+
"Please see the following topics for much more information.\n"+
"\n"+
"     Topics:\n"+
"               Morphed   Unmorphed   Both   Training   Power\n"+
"               Practice   Combat   Spells   Quests   Conduct\n"+
"               Gym   Teleport  Pk                           \n"+
"\n"+
"To see information on a topic: type 'ranger' and the topic name.\n"+
"");
return 1;
}
if(str == "training"){
write(""+
"*************************Power Ranger Training***********************\n"+
"\n\n"+
"Training for the Power Rangers guild differs slightly from that of \n"+
"any other guild.  There is no set place for training to take place.\n"+
"Training is done by seeking out select NPC's and looking at them.\n"+
"You will be prompted for a reply which is in (). Usually the \n"+
"response will be yes.\n"+
"There are 4 types of training: Karate Levels, Offense, Defense, and\n"+
"Skills.  There are 10 Karate Levels: Basic, White, Yellow, Orange, \n"+
"Red, Green, Blue, Purple, Brown, Black.  These are viewed by looking\n"+
"at yourself.  Offensive and Defensive skills are learned one at a\n"+
"time is a specific sequence.  If you have the skill offense and \n"+
"defense, you may see what you have already learned.  Overall skills\n"+
"are listed in these help files, by when you can use them (morphed, \n"+
"unmorphed, both).  Any skill designated with ($) you must learn\n"+
"before you can use it.\n"+
"For the most part, Training does not have to take place in any\n"+
"particular order.  No training depends on the other 3 types.\n"+
"Also training in this guild is completely separated from player\n"+
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
"unmorph      Free    Unmorphs a ranger.\n"+
"teleport     25  ($) Teleports a ranger to special rooms.\n"+
"armor        2/r ($) Metallic armor combat bonus.  [Toggled]\n"+
"weapon       2/r ($) Get your weapon.  [Toggled]\n"+
"lamp         Free($) Turn on/off your Helmet lamp. [Toggled]\n"+
"jet          Free($) A speedster with maximum 5 commands.\n"+
"                     (jet e,s,out,ne,w)\n"+
"battlezord       ($) Calls personal battlezord (pet).\n"+
"             100 + 30/karate level (when in Command Center).\n"+  
"             200 + 60/karate level (when elsewhere).\n"+
"megazord     Free($) Calls the thunder megazord.\n"+
"thunderzord  100 ($) Calls personal thunderzord.\n"+
"                     (used immediatly after 'megazord')\n"+
"blaster      50  ($) Calls the Ranger Power Blaster.\n"+
"** All numbers are rated in guild power  **\n"+
"** You can not kill good monsters while morphed!!!   **\n"+
"");
return 1;
}
if(str == "unmorphed"){
write(""+
"Availible commands while unmorphed:\n"+
"morph       100    Morphs a ranger.\n"+
"teleport    50 ($) Teleports a ranger to special rooms.\n"+
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
"ranger          Free    Ranger help files.\n"+
"power           Free    Check guild power level.\n"+ 
"generate <amt> <amt>($) Changes <amt> spell points to power points.\n"+
"                        (Not 1:1 ratio though)\n"+
"donate <object> Free($) Changes an object to a percentage of its value\n"+
"                        into power points.\n"+
"time            Free    Check time until reboot.\n"+
"dkick <person>  20  ($) Kick an opponent alongside <person>.\n"+
"study <thing>   Free($) Find out if an enemy is good or bad.\n"+
"lead            20  ($) Take the lead while in battle.\n"+
"offense         Free($) Check your offensive moves you can practice.\n"+
"defense         Free($) Check your defensive moves you can practice.\n"+
"train           Free($) Convert Golds Gym training to Ranger training.\n"+
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
"");
return 1;
}
if(str == "practice"){
write(""+
"*********************Guild Practice********************************\n"+
"\n\n"+
"Practice is a key element of the power rangers guild.\n"+
"Much of training will require a minimum amount of practice.\n"+
"There are 3 types of practice:  Overall, Offense, Defense.\n"+
"Overall practice is attained several ways.  All of it is done\n"+
"by actually doing something else, basically by using your\n"+
"skills.  The greatest way to improve overall practice is by\n"+
"engaging in combat and donating power to the guild.\n"+
"Offense and Defense practice take place in two ways.  One is \n"+
"by using the manual practice command with the syntax\n"+ 
"  'practice <skill> on <living being>'  \n"+
"The commands 'offense' and 'defense' give a list of availible\n"+
"skills to practice.  The manual practice will improve the\n"+
"particular skill you have chosen as well as your overall practice.\n"+
"Offensive and Defensive practice also occurs automatically when\n"+
"in combat.  If you see a message while in battle for a particular\n"+
"move, you will get practice for that manuver as well as overall\n"+
"practice.  These messages only will appear once you have reached\n"+
"at least your Basic Karate Level.\n"+
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
"Rather is is designed for role playing atmosphere purposes.\n"+
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
"Power Rangers are able to increase their combat abilities through\n"+
"the use of Golds Gym.  For Power Rangers only there will be a way\n"+
"to convert the training done there to guild training.\n"+
"To do this you must join the Gym normally and workout normally.\n"+
"By using the 'train' command, Golds Gym that applies to Power Rangers\n"+
"is automatically converted to a form useful to your combat abilities.\n"+
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
"The cost is 25 power points while morphed or 50 power points\n"+
"while unmorphed.\n"+
"Locations:\n"+
"   command center   Power Ranger Command Center\n"+
"   church           Village Church of Nirvana\n"+
"   park             Angel Grove Park\n"+
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
