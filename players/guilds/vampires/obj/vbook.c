 
#include "/players/eurale/closed/ansi.h"
#define TP this_player()
inherit "obj/treasure";
 
reset(arg) {
  if(arg) return;

set_id("alcoran");
set_alias("book");
set_short(GRY+"large dusty book"+NORM+" on a pedestal");
set_long(
  "This is the "+HIR+"Vampiric Alcoran"+NORM+".  It is an accumulation"+
      " of facts\n"+
  "concerning the Vampire Guild.  You may [read index] to see the\n"+
  "sections inside and then [read <name>] to read specific sections.\n"+
  "This sacred manual has survived centuries.\n");
}
 
init() {
  add_action("read_book","read");
}

read_book(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "index") { write(
  "		"+HIR+"Vampiric Alcoran Sections:"+NORM+"\n\n"+
  "			History\n"+
  "			Admittance\n"+
  "			Advancement\n"+
  "			Guild\n"+
  "			Officers\n"+
  "			Biting\n"+
  "			General\n"+
  "			Coffins\n"+
  "                        Donations\n"+
  "                        Wizards\n"+
  "\n\n");
  return 1; }

if(str == "history" || str == "History") { write(
  "                                "+HIR+"HISTORY"+NORM+"\n"+
  "  Long, long ago in a land called Nirvana, a new guild was formed.\n"+
  "It came into existance through the efforts of a wise and old wizard\n"+
  "named Nooneelse.  The people who chose to become members of this\n"+
  "guild swore a solemn allegiance to the other members that they would\n"+
  "remain vampires for all their days on Nirvana.  The guild prospered\n"+
  "and grew.  Many people joined but unfortunately, many left as well.\n"+
  "This oldest of Nirvana guilds has gone through many changes between\n"+
  "when it was formed and its current state today.  Although not one of\n"+
  "strongest guilds physically, we possess other powers to help us in\n"+
  "our battles throughout this realm.  There is more strength in numbers\n"+
  "than in single individuals and it is this that makes the vampires a\n"+
  "truly unique family.  They have always looked out for one another.\n"+
  "No vampire is alone if they but ask for assistance.  Anyone looking\n"+
  "for a family atmosphere is naturally drawn to the children of the\n"+
  "night.  Those that choose our family are also asked to commit to us\n"+
  "for their entire life on Nirvana.  The cost to leave us, once allowed\n"+
  "in, is a heavy one.  Be it known to all who contemplate joining this\n"+
  "family of darkness, that if you shall ever choose to leave the family\n"+
  "after having joined it, you will "+BOLD+"NEVER"+NORM+
  " be allowed to return.\n\n");
  return 1; }

if(str == "admittance" || str == "Admittance") { write(
  "\n                             "+HIR+"ADMITTANCE"+NORM+"\n"+
  "  Joining the vampire family is often times a slow and tedious process.\n"+
  "In order to become a member, you must find 3 level 17 or higher vampires\n"+
  "who are willing to bite you into the guild.  This may sound easy to\n"+
  "the casual observer but, alas, is quite a detailed procedure.  First,\n"+
  "you must post of your interest and the reasons why on the board that\n"+
  "is located 6 north of Pizza Hut.  Many a prospective vampire has been\n"+
  "turned down when the family was unimpressed by their reasons for wanting\n"+
  "to join.  So, put some thought into it and state your case as best you\n"+
  "can.  Once your desire is known, the family will discuss you and the\n"+
  "impact they feel you will have.  Characters who have displayed less\n"+
  "than appropriate behavior when they play are also often rejected.  If\n"+
  "there are no objections to your joining, the process of obtaining bites\n"+
  "falls back on your shoulders.  Each elligible vamp may make their own\n"+
  "rules before they decide to bite you.  Some will want to party, others\n"+
  "may just talk.  After you obtain your 3rd bite in a single reboot time\n"+
  "frame, you will DIE and be reborn a vampire.  Following your induction, \n"+
  "there is a mandatory guild tour so make arrangements to take it.  Also, \n"+
  "you should remember who bites you as they honor you greatly.\n\n");
  return 1; }

if(str == "guild" || str == "Guild") { write(
  "\n                          "+HIR+"GUILD INFO"+NORM+"\n"+
  "  "+BOLD+"ADVANCEMENT:"+NORM+"  The vampire guild has 4 guild levels."+
  "  These guild levels\n"+
  "are game level dependent.  When you attain the appropriate game level and\n"+
  "have completed the trial for that level, you will be able to use the\n"+
  "powers associated with that guild level.\n\n"+
  "  "+BOLD+"PETS:"+NORM+"  The vampire guild has a wolf as a guild pet."+
  "  You must have\n"+
  "attained the appropriate level to summon one.  You must also locate the\n"+
  "appropriate area from which to summon them also.\n\n"+
  "  "+BOLD+"GUILD LEADERSHIP:"+NORM+"  Each vampire has a voice in the "+
  "running of the\n"+
  "guild.  There is a guild wizard who oversees the total running of the\n"+
  "guild.  Under him is a vampire underlord who sees to the day to day\n"+
  "affairs.  There may also be some 'selected' helpers as well.  Some\n"+
  "issues may be decided by them but generally, the vampire family will\n"+
  "make the guild decisions collectively.\n\n"+
  "  "+BOLD+"GUILD HALL:"+NORM+"  The guild hall is quite a large place"+
  " with various shops\n"+
  "and rooms.  In many cases, a room will have a special purpose so it pays\n"+
  "to keep abreast of what's in the guild.\n\n");
  return 1; }

if(str == "officers" || str == "Officers") { write(
  "\n                            "+HIR+"VAMPIRE OFFICERS"+NORM+"\n"+
  "  The Vampire Guild tends to work as a democracy with each vampire\n"+
  "havng a vote on most issues.  The guild wizard is Eurale and he will\n"+
  "always have final say when issues are in dispute.  There is also an\n"+
  "Underlord that works as Eurale's right hand man.  He is in charge of\n"+
  "the day to day activities of the guild.  Some of the chosen family\n"+
  "members may also be able to replace fangs if they are lost but they\n"+
  "work for the Underlord and at his discretion.\n"+
  "\n");
  return 1; }

if(str == "biting" || str == "Biting") {
if(TP->query_guild_name() != "vampire") {
  write("The pages of this section are too blurry for you to read.\n");
  return 1; }
else { write(
  "\n                            "+HIR+"BITING"+NORM+"\n"+
  "  When you have attained game level +5 status and have done the 4th\n"+
  "guild trial, you will be elligible to bite new members into the vampire\n"+
  "family.  With this ability comes some additional responsibility.  You\n"+
  "should make an effort to take into account other family members and\n"+
  "their feelings before you bite anyone.  There is no need to hurry this\n"+
  "process.  If the prospective member is in such a hurry that they can't\n"+
  "wait for the process, you should probably pass them by.  Biting vampires\n"+
  "must also be willing to give a guild tour to the new member.  If you\n"+
  "do not have time to give a tour, make sure someone does.  If there is\n"+
  "noone to give a tour, do not bite them.  When you are the tour giver,\n"+
  "you should make sure that it is a quality tour.  Take time to answer \n"+
  "any questions.  As a biting vamp, you have the right to determine what\n"+
  "your personal requirements are before you will bite.  If you want to\n"+
  "party with the new member, that's fine.  If you want to chat, that's\n"+
  "also fine.  You decide.  Lastly, becoming a vampire should be something\n"+
  "the player should never forget.  It is up to you to make sure that\n"+
  "happens.  Make it theatrical and suspenseful but keep the time frame\n"+
  "reasonable as you are only 1 of 3 biters.  The family is only as good\n"+
  "as the members you bite so take this job seriously.\n"+
  HIR+"  WARNING"+NORM+" The 3rd bite is FATAL so make sure you tell the\n"+
  "          new recruit before you do it.\n\n"+
  "\n");
  return 1; }
}

if(str == "general" || str == "General") { write(
  "\n                            "+HIR+"GENERAL INFO"+NORM+"\n"+
  "  The vampire guild has a 'your choice' PK policy.  What that means is\n"+
  "that each vampire can decide for his/her self whether they want to be\n"+
  "a Player Killer or not.  Any vamp that kills another vamp or assists\n"+
  "in the killing of another vamp will be immediately expelled, however.\n"+
  "\n"+
  "  The guild line is to remain 'G' rated at all times.  If you must use\n"+
  "vulgar or otherwise inappropriate language, use one of the other chan-\n"+
  "nels that condones such nonsense.  Repeated violations of this rule\n"+
  "will result in loss of your fangs.\n"+
  "\n"+
  "  Common courtesy will be the common rule here.  Not everyone is going\n"+
  "to like everyone else but if we're all in the same family, we WILL be\n"+
  "cordial to one another.  If that is impossible, it's time for you to\n"+
  "look elsewhere for a guild.\n"+
  "\n"+
  "  Wizards that are also vampires will be afforded respect.  They earned\n"+
  "that right.  If you have a problem with that, you can write to me dir-\n"+
  "ectly to discuss it.  If they tell you to do something, do it.  You can\n"+
  "debate with them later or take it up with me.\n\n");
  return 1; }

if(str == "coffins" || str == "Coffins") {
if(TP->query_guild_name() != "vampire") {
  write("As you try to focus on the page, it blurs...\n");
  return 1; }
else { write(
  "\n                            "+HIR+"COFFINS"+NORM+"\n"+
  "  Each family member is entitled to some 'private space' where they\n"+
  "can get away and be alone when they need to.  To this end, each family\n"+
  "member is given a personal coffin when they are inducted.  Your coffin\n"+
  "is a personal space that only you can enter unless you invite another\n"+
  "vampire in.  The decoration of your coffin is left entirely up to you.\n"+
  "There is a shelf in your coffin that will allow you to place items\n"+
  "on it in case you have to leave Nirvana for a short while.  But know\n"+
  "this!  If you do not return to claim the items from the shelf before\n"+
  "the next reboot, they will disappear and be replaced by the monetary\n"+
  "value of them.  There is also storage space that you may purchase for\n"+
  "your coffin that will hold 3 items in the same manner as the lockers.\n"+
  "Lastly, the coffins are for vampires ONLY.  No non-vampire members\n"+
  "can enter them at any time.\n\n");
  return 1; }
}

if(str == "advancement" || str == "Advancement") {
if(TP->query_guild_name() != "vampire") {
  write("As you look at the pages, the letters begin to move about\n"+
        "the page, making them unreadable.\n");
  return 1; }
else { write(
  "\n                           "+HIR+"GUILD ADVANCEMENT"+NORM+"\n"+
  "  As you improve as a player, you will naturally gain game levels.\n"+
  "To advance in the Vampire Guild, you will be required to complete\n"+
  "vampire trials.  There are 4 altogether.  Each successful trial\n"+
  "completion bestows upon you greater skills and abilities.  When a\n"+
  "vampire 'thinks' they are ready to attempt a trial, all they need\n"+
  "do is visit the appropriate trialmaster who awaits them.  Upon\n"+
  "completion of all 4 trials, the vampire will be considered a full\n"+
  "nosferatu with all skills and abilities at their command.\n\n");
  return 1; }
}

if(str == "donations" || str == "Donations") {
if(TP->query_guild_name() != "vampire") {
  write("The pages are too blurry to read.\n");
  return 1; }
write("\n                          "+HIR+"DONATIONS\n"+NORM+
  "  The Vampire Guild Hall has a donation room where family members\n"+
  "who find themselves with excess weapons/armor/heals/etc can donate\n"+
  "them.  Vampires fortunate enough to be able to donate cannot put\n"+
  "stipulations about the use of whatever they drop in our donation\n"+
  "room.  Needy family members are expected to use common sense when\n"+
  "removing items from this room to either use or sell.  Storable\n"+
  "weapons/armor should not be sold as a shortcut to going out and\n"+
  "earning some coins on your own.  Heals and other items should be\n"+
  "used for what they were intended.  For someone to pick up every-\n"+
  "thing in the donation room only to run and sell it discourages not\n"+
  "only the donating family members but also goes against the spirit\n"+
  "of helping those in need.  Be respectful about free 'stuff' and use\n"+
  "your heads when taking it lest the supply dry up.\n");
  return 1; }


if(str == "wizards" || str == "Wizards") {
if(TP->query_guild_name() != "vampire") {
  write("The pages blur before your eyes...\n");
  return 1; }
write("\n                       "+HIR+"WIZARDS\n"+NORM+
  "  The Vampire family has a proud history of producing Wizards from\n"+
  "among our midst.  Be it known to all, however, that once they leave\n"+
  "our mortal family, they no longer have a voice in issues involving\n"+
  "our guild.  There is only one Vampire Wizard and that is Eurale.\n"+
  "All others are merely guests after assuming immortality.  They are\n"+
  "to be respected for their efforts and whatever contribution they\n"+
  "made in their past lives as vampires but they elected to move on.\n"+
  "Wizards ascending from any family are to be treated with respect\n"+
  "in general because of their position but they have no say in the\n"+
  "family issues and should be politely reminded of this.  If there\n"+
  "is an issue that cannot be resolved with a member of the immortal\n"+
  "staff, mail Eurale with the specifics and let him deal with it.\n"+
  "Do not put yourself in a position of peril when there is no need to\n"+
  "on your part.\n");
  return 1; }

}

get() {
  write("A "+HIC+"blue arc"+NORM+" stings your hand as you reach for "+
        "the book.\n");
  return 0; }
