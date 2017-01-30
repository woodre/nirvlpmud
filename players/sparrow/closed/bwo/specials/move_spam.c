#include <ansi.h>

int main(object atk) {
  string *ms1;
  string *ms2;
  string *ms3;
  string *initiate;
  string *addition;
  string *ranColor;
  string moveSpam;
  string moveSpam2;
  int ms1N, ms2N, ms3N;
  int myRank, ran, bon;
  ms1 = ({"Evil", "Sinful", "Atrocious", "Baneful", "Corrupt", "Damnable", "Depraved", "Destructive", "Execrable", "Foul", "Hateful", "Heinous",
              "Hideous", "Loathsome", "Maleficent", "Malevolent", "Malicious", "Malignant", "Nefarious", "Obscene", "Pernicious", "Rancorous",
			  "Repugnant", "Revolting", "Spiteful", "Venomous", "Vicious", "Vile", "Wicked", "Wrathful", "Demonic", "Cacodemonic", "Devilish", 
			  "Diabolic", "Malefic", "Sinistral", "Tortured", "Venal", "666", "Cackling", "Unholy", "Burning", "Immolated", "Insane", "Raging",
			  "10,000", "Double", "Souless", "Bloodthirsty", "Insatiable", "Murderous"});
  ms2 = ({"Archfiend", "Beast", "Fiend", "Goblin", "Hellion", "Imp", "Incubus", "Spirit", "Rogue", "Succubus", "Vampire", "Maiden", "Hag", "Corpse",
              "Familiar", "Daeva", "Devil", "Titan", "Ghoul", "Ogre", "Wight", "Willow", "Wraith", "Zombie", "Ghoul", "Revenant", "Soul", "Giant", "Wolf",
			  "Vermin", "Murderer", "Sparrow", "Raven", "Vulture", "Madman", "Shadow", "Master", "Slave", "Parasite", "Death" });
  ms3 = ({"Hand", "Twist", "Touch", "Punch", "Gouge", "Thrust", "Hold", "Essence", "Knee", "Kick", "Roundhouse", "Heel", "Claw", "Scratch", "Breath",
              "Attack", "Fury", "Kung-Fu", "Slap", "Forehead", "Headbutt", "Bite", "Glare", "Blow", "Tackle", "Throw", "Vengeance", "Assault", "Jab", "Cross",
			  "Hook", "Uppercut", "Dropkick", "Jolt", "Hold", "Combination", "Style", "Elbow", "Chop", "Submission", "Stomp", "Pummel", "Rage", "Tecnique", "Style"});
  ms1N = sizeof(ms1);
  ms2N = sizeof(ms2);
  ms3N = sizeof(ms3);  
  /* array containing messages that initiate the tecnique */
  initiate = ({"leaps high into the air and performs","twists to the side and initiates","suddenly appears and performs","comes out of nowhere with","screams in ecstasy while performing","lunges forward suddenly with","deftly delivers","channels the power of dark into","counters swiftly with","retaliates smartly with","dodges to the side and performs","drives forward with","lands multiple blows with","unleashes hell by performing","sprays the room with blood from","inflicts terrible pain with","causes grievious wounds with","cackles with delight after landing","imposes the will of the Night with"});
  /* array containing message that tie one tecnique into another */
  addition = ({"followed immediately by","before switching to","then sommersaults into","and finishes with","coupled with","then without missing a beat performs","leading into"}); 
  /* array containing color values */
  ranColor = ({RED,MAG,CYN,WHT,BOLD,HIK,HIB,HIC});
  myRank = (int)this_player()->query_guild_rank();
  /* Damage is calculated as such.
      Base damage  = 10 + Rank*2 (12 minimum 40 maximum)
	 Bonus damage = 1 pt for each str point above 20, 0-10
	 1 pt for every 3 points piety over 15 0-5 
	 If they pass a luck check (random(50) <= luc) then they get a bonus of (random(luck))/2 0-15
	 12-----------------70
	 min                     max
	 
	 20% chance of a double attack combination for 50% more damage
	 18---------------105
	 min                   max
	 */
  ran = 10 + myRank*2;
  bon = (int)this_player()->query_attrib("str");
  bon = bon - 20;
  if(bon > 0) { ran = ran + bon; }
  bon = (int)this_player()->query_attrib("pie");
  bon = bon - 15;
  bon = bon/3;
  if(bon > 0) { ran = ran + bon; }
  bon = (int)this_player()->query_attrib("luc");
  if(bon > random(50)) {
    bon = random(bon)/2;
	ran = ran + bon;
  }
  bon = 0;
  if(random(5) > 0) {
    /* single attack */
    if(ran == 0) { ran = 1; }
    moveSpam = ms1[random(ms1N)]+" "+ms2[random(ms2N)]+" "+ms3[random(ms3N)];  
	tell_room(environment(this_player()),
	  this_player()->query_name()+" "+initiate[random(sizeof(initiate))]+" "+ranColor[random(8)]+moveSpam+NORM+"!\n");
  }
  else {
    /* double penetration */
    ran = ran*2;
    if(ran == 0) { ran = 1; }
      moveSpam = ms1[random(ms1N)]+" "+ms2[random(ms2N)]+" "+ms3[random(ms3N)];
	  moveSpam2 = ms1[random(ms1N)]+" "+ms2[random(ms2N)]+" "+ms3[random(ms3N)];
	  tell_room(environment(this_player()),
        this_player()->query_name()+" "+initiate[random(sizeof(initiate))]+" "+ranColor[random(8)]+moveSpam+NORM+"\n"+addition[random(sizeof(addition))]+ranColor[random(8)]+" "+moveSpam2+NORM+"!\n");
  }
  this_player()->add_sp(-(5+random(myRank)));
  return ran;
  }
  