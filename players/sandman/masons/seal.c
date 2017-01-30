
#include "/players/sandman/masons/broker.c"

int muffled, banished, guild_rank, guild_exp, level, guild_loan;
int wimpy_at, wimpystate, wimdir, battle, rank, start_time, shadow;
string me, gender, wimpydir;
object womble;


reset(arg) {
      if(!guild_rank)
        guild_rank = 3;
          if (this_player() && this_player()->query_guild_exp() == 0){
        this_player()->add_guild_exp(1);
        return 1;
      }
      start_time = 0;
      battle = 0;
      if(arg)
        return;
}

set_guild_rank(s) { guild_rank = s; }

set_guild_loan(ln) { guild_loan = ln; }

query_guild_loan() { return guild_loan; }

set_guild_exp(a) { guild_exp = a; }

query_guild_exp() { return guild_exp; }

query_guild_rank() { return guild_rank; }

set_muffled(mf) { muffled = mf; }

query_muffled() { return muffled; }

set_wimdir(wr) { wimdir = wr; }

query_wimdir() { return wimdir; }

set_wimpy_at(wa) { wimpy_at = wa; }

query_wimpy_at() { return wimpy_at; }

query_wimpydir() { return wimpydir; }

set_wimpydir(wp) { wimpydir = wp; }

set_battle(bt) { battle = bt; }

query_battle() { return battle; }

set_wimpystate(wst) { wimpystate = wst; }

query_wimpystate() { return wimpystate; }

id(str) { return str == "seal" || str == "mason_seal"; }


query_auto_load() {
    return "players/sandman/masons/seal:"+guild_rank+"#"+guild_exp+
           "#"+guild_loan;
}

drop() {
    return 1;
}

short() { return "A Consistory Seal (worn)"; }

long() {
       write("The seal itself is circular in shape.  Engraved in the seal\n");
       write("is a picture of a double-headed eagle grasping a sword\n");
       write("in its talons.  Balanced on the heads of the eagle is\n");
       write("a pyramid with the number 20 inscribed in it, which\n");
       write("signifies the highest level obtainable by a mortal mason.\n");
       write("\n");
       write("Type 'seal' for more info on abilities.\n");
}

get() {
   return 1;
}

init_arg(arg) {
     sscanf(arg, "%d#%d#%d", guild_rank, guild_exp, guild_loan);
     cat("/players/sandman/masons/NEWS");
     return;
}

init() {

    me = this_player()->query_real_name();
    write("\n\nForced restore............\n\n");
    add_action("lay_hands","treat");
    add_action("emote","emote");
    add_action("register","reset");
    add_action("summon","summon");
    add_action("cast_light","cast");
    add_action("muffles","muffles");
    add_action("battlescore","battlescore");
    add_action("confer","confer");
    add_action("battlescore","bsc");
    add_action("check_ranks","check");
    add_action("wimpydir","wimpydir");
    add_action("wimpyhp","wimpyhp");
    add_action("rank_titles","gtitle");
    add_action("rank","rank");
    add_action("xsell","xsell");
    add_action("assess","assess");
    add_action("teleport","teleport");
    add_action("recruit","recruit");
    add_action("greet","greet");
    add_action("news","news");
    add_action("judge","judge");
    add_action("compare","compare");
    add_action("mason_tell","mt");
    add_action("mason_emote","me");
    add_action("logged_on","masons");
    add_action("help_seal","seal");
    add_action("spy","spy");
    add_action("recon","recon");
    add_action("munch","munch");
    add_action("dream","dream");
    add_action("shadow","shadow");
    set_heart_beat(1);
}

seeya_guild() {
   write("Changing guild experience into player experience...\n");
   write("Thanks for hanging around and look out for the\n");
   write("Paladins guild...guaranteed to be different...it should\n");
   write("be open in he next week or so. \n");
   write("             -Sandman\n");
   this_player()->add_exp(guild_exp);
   log_file("sandman.ck", "Swapping out guild exp ("+guild_exp+") for "+
      this_player()->query_real_name()+"\n");
   destruct(this_object());
   return 1;
}

check_ranks(str) {
     string who;
     object ckguild;
     int exp, loan;

     if(guild_rank < 30) {
       write("You must have a guild rank of 30 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Useage:  check <member>\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if(find_player(who)->query_invis() > 0 && guild_rank < 100) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     ckguild = present("seal", find_player(who));
     if(!ckguild) {
       write(capitalize(who)+" is not a member.\n");
       return 1;
     }
     rank = ckguild->query_guild_rank();
     exp = ckguild->query_guild_exp();
     loan = ckguild->query_guild_loan();
     write(find_player(who)->short()+"\n");
     write("Level: "+find_player(who)->query_level()+"\n");
     write("Experience: "+find_player(who)->query_exp()+"\n");
     write("Gold coins: "+find_player(who)->query_money()+"\n");
     write("Guild rank: "+rank+"\n");
     write("Guild exp: "+exp+"\n");
     write("Guild loan: "+loan+"\n");
     return 1;
}

register() {
     object ob, new_seal;
     int rank, exp, loan;
     new_seal = clone_object("players/sandman/masons/seal");
     rank = this_object()->query_guild_rank();
     exp = this_object()->query_guild_exp();
     loan = this_object()->query_guild_loan();
     wimdir = this_object()->query_wimdir();
     wimpy_at = this_object()->query_wimpy_at();
     wimpydir = this_object()->query_wimpydir();
     muffled = this_object()->query_muffled();
     battle = this_object()->query_battle();
     wimpystate = this_object()->query_wimpystate();
     new_seal->set_wimdir(wimdir);
     new_seal->set_wimpy_at(wimpy_at);
     new_seal->set_wimpydir(wimpydir);
     new_seal->set_muffled(muffled);
     new_seal->set_battle(battle);
     new_seal->set_wimpystate(wimpystate);
     new_seal->set_guild_rank(rank);
     new_seal->set_guild_loan(loan);
     new_seal->set_guild_exp(exp);
     move_object(new_seal, this_player());
     destruct(this_object());
     write("Your Consistory seal has been reset.\n");
     return 1;
}

wimpyhp(str) {
     if(!str) {
       if(wimpystate == 0) {
         write("Guildwimpy is not on.\n");
         return 1;
       }
       write("Guildwimpy has been turned off.\n");
       wimpystate = 0;
       wimdir = 0;
       wimpydir = 0;
       return 1;
     }
     if(sscanf(str, "%d", wimpy_at) != 1) {
       write("Useage:  wimpyhp <hit point>\n");
       return 1;
     }
     wimpystate = 1;
     write("Guildwimpy has been turned on and set at "+wimpy_at+".\n");
     set_heart_beat(1);
     return 1;
}

heart_beat() {
     if(!me) return;
     if(wimpystate == 1 && find_player(me)->query_hp() < wimpy_at) {
       if(find_player(me)->query_attack()) {
         if(wimdir == 1) {
           command(wimpydir, find_player(me));
         } else
         find_player(me)->run_away();
       }
     }
     if(battle == 1) {
       int hitpt, spellpt, mhit, mspell;
       hitpt = find_player(me)->query_hp();
       spellpt = find_player(me)->query_spell_point();
       mhit = find_player(me)->query_mhp();
       mspell = find_player(me)->query_msp();
       tell_object(find_player(me),
       "HP["+hitpt+"/"+mhit+"]    SP["+spellpt+"/"+mspell+"]\n");
     }
     if (shadow == 1) {
        if(environment(this_player()) != environment(womble)) {
        move_object(this_player(),environment(womble));
        tell_object(womble,this_player()->query_name()+" follows you.\n");
        tell_object(this_player(),"You move to: "+environment(womble)->short()+
                    ".\n");
        }
     }
}

wimpydir(str) {
      if(!str || sscanf(str, "%s", wimpydir) != 1) {
        write("Useage:  wimpydir <direction>\n");
        return 1;
      }
      write("Wimpydir set to : "+wimpydir+"\n");
      wimdir = 1;
      return 1;
}

battlescore() {
     if(battle == 0) {
       write("Battlescore is turned on.\n");
       battle = 1;
       set_heart_beat(1);
       return 1;
     } else
     battle = 0;
     write("Battlescore is turned off.\n");
     return 1;
}

rank_titles() {
     string title;
     gender = this_player()->query_gender();

     if(gender == "female") {
       if(guild_rank == 3) 
         { title = "the Secret Mistress"; }
       if(guild_rank == 4) 
         { title = "the Knightess of the Sword"; }
       if(guild_rank == 5) 
         { title = "the Knightess of the East & West"; }
       if(guild_rank == 6) 
         { title = "the Knightess of the Rose Croix"; }
       if(guild_rank == 7)
         { title = "the Grand Pontiff"; }
       if(guild_rank == 8) 
         { title = "the Mistress Ad Vitam"; }
       if(guild_rank == 9)
         { title = "the Prussian Knightess"; }
       if(guild_rank == 10) 
         { title = "the Knightess of the Royal Axe"; }
       if(guild_rank == 11) 
         { title = "the Chief of the Tabernacle"; }
       if(guild_rank == 12)
         { title = "the Princess of the Tabernacle"; }
       if(guild_rank == 13) 
         { title = "the Knightess of the Brazen Serpent"; }
       if(guild_rank == 14)
         { title = "the Princess of Mercy"; }
       if(guild_rank == 15)
         { title = "the Knightess Commander of the Temple"; }
       if(guild_rank == 16)
         { title = "the Knightess of the Sun, Adept"; }
       if(guild_rank == 17)
         { title = "the Grand Scottish Knightess of St. Andrew"; }
       if(guild_rank == 18)
         { title = "the Knightess Kadosh"; }
       if(guild_rank == 19)
         { title = "the Inspector Inquisitor"; }
       if(guild_rank == 20)
         { title = "the Sublime Princess of the Royal Secret"; }
       if(guild_rank >= 30)
         { title = "the Guild Commander"; }
      } else {
     if(guild_rank == 3) { title = "the Secret Master"; }
     if(guild_rank == 4) { title = "the Knight of the Sword"; }
     if(guild_rank == 5) { title = "the Knight of the East & West"; }
     if(guild_rank == 6) { title = "the Knight of the Rose Croix"; }
     if(guild_rank == 7) { title = "the Grand Pontiff"; }
     if(guild_rank == 8) { title = "the Master Ad Vitam"; }
     if(guild_rank == 9) { title = "the Prussian Knight"; }
     if(guild_rank == 10) { title = "the Knight of the Royal Axe"; }
     if(guild_rank == 11) { title = "the Chief of the Tabernacle"; }
     if(guild_rank == 12) { title = "the Prince of the Tabernacle"; }
     if(guild_rank == 13) { title = "the Knight of the Brazen Serpent"; }
     if(guild_rank == 14) { title = "the Prince of Mercy"; }
     if(guild_rank == 15) { title = "the Knight Commander of the Temple"; }
     if(guild_rank == 16) { title = "the Knight of the Sun, Adept"; }
     if(guild_rank == 17) { title = "the Grand Scottish Knight of St. Andrew";}
     if(guild_rank == 18) { title = "the Knight Kadosh"; }
     if(guild_rank == 19) { title = "the Inspector Inquisitor"; }
     if(guild_rank == 20) { title = "the Sublime Prince of the Royal Secret"; }
     if(guild_rank >= 30) { title = "the Guild Commander"; }
     }
     call_other(this_player(),"set_title", title);
     write("You are now: "+this_player()->short()+"\n");
     return 1;
}

banish() {
     string me;
     me = this_player()->query_real_name();

     if(restore_object("players/sandman/masons/BANISHED/"+me)) {
       write("You have been banished from the Guild.\n");
       write("If you wish to re-enter you must petition a Guildmaster.\n");
       destruct(this_object());
       return 1;
     }
     return 1;
}


rank() {
     write(this_player()->short()+" ("+this_player()->query_level()+")\n");
     write("Hit points: "+this_player()->query_hp()+"\n");
     write("Spell points:  "+this_player()->query_spell_point()+"\n");
     write("Experience: "+this_player()->query_exp()+"\n");
     write("Gold coins: "+this_player()->query_money()+"\n");
     write("Guild rank: "+guild_rank+"\n");
     write("Guild experience: "+guild_exp+"\n");
     write("Guild loan: "+guild_loan+"\n");
     if(wimpystate == 1) {
     write("Guildwimpy is on.  Wimpyhp: "+wimpy_at+"   Wimpydir: "+wimpydir+"\n");
     } else
     write("Guildwimpy is off.\n");
     if(muffled == 1) {
       write("Guildmuffles are on.\n");
     } else
     write("Guildmuffs are off.\n");
     return 1;
}

spy(str) {
     string who;

     if(guild_rank < 8) {
       write("You must have a guild ranking of 8 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Useage:  spy <player>\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 10) {
       write("You are too low on power.\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if(find_player(who)->query_invis() > 0) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if(find_player(who)->query_level() > 20) {
       write("You cannot spy on wizards.\n");
       return 1;
     }
     call_other(this_player(), "add_spell_point", -10);
     write(capitalize(who)+"'s location:\n");
     write(call_other(find_player(who), "look")+"\n");
     return 1;
}

muffles(str) {

     if(!str) {
       write("Useage: muffles <on/off>\n");
       return 1;
     }
     if(str == "on") {
       if(muffled == 1) {
         write("You already have your muffles on.\n");
         return 1;
       } else
       muffled = 1;
       write("You are now muffled.\n");
       return 1;
     }
     if(str == "off") {
       if(muffled == 0) {
         write("Your muffles are not on.\n");
         return 1;
       } else
       muffled = 0;
       write("Your muffles are now off.\n");
       return 1;
     }
}

recon(str) {
string who;
object ob,ob2,ob3,ob4,ob5,ob6,ob7;

if(!str) {
   write("Check who?\n");
   return 1;
}

who = str;

if(!find_player(who)) {
   write(capitalize(who)+" is not on.\n");
   return 1;
}

ob = present("license",find_player(who));
ob2 = present("fangs",find_player(who));
ob3 = present("robes",find_player(who));
ob4 = present("badge",find_player(who));
ob5 = present("guild",find_player(who));
ob6 = present("pentagram",find_player(who));

if(ob) {
   write(capitalize(who)+" is a foul assassin!\n");
   return 1;
}

if(ob2) {
   write(capitalize(who)+" is a dreaded vampire!\n");
   return 1;
}
if(ob3) {
   write(capitalize(who)+" is a misguided cleric!\n");
   return 1;
}
if(ob4) {
   write(capitalize(who)+" is a shape-shifting doppleganger!\n");
   return 1;
}
if(ob5) {
   write(capitalize(who)+" is a cheating thief!\n");
   return 1;
}
if(ob6) {
   write(capitalize(who)+" is a pitiful alchemist!\n");
   return 1;
}
   write(capitalize(who)+" is not a member of a competing guild.\n");
   return 1;
}
munch(str) {

   object target;

   if(!str || str != "corpse") {
      write("Usage: munch corpse\n");
      return 1;
   }
   target = present("corpse",environment(this_player()));
   if(!target) {
      write("You see no corpse to munch on.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 3) {
      write("You do not have the needed sp to munch a corpse.\n");
      return 1;
   }
   write("You whip out your Jeff Dahmer cook book, and find the correct\n");
   write("recipe. Performing a magical gesture the corpse becomes a meal.\n");
   write("You dig in and eat.\n");
   destruct(target);
   this_player()->heal_self(10);
   this_player()->add_spell_point(-2);
   return 1;
}

dream(str) {
   object victim;
   int hurt;

   if(!str) {
      write("Usage: dream <player/monster>\n");
      return 1;
   }
   victim = present(str, environment(this_player()));
   if(!victim) {
      write("Your intended target is not here.\n");
      return 1;
   }
   if(guild_rank < 16) {
      write("You must be guild level 16 to use this command.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 50) {
      write("You do not have enough sp to use dream.\n");
      return 1;
   }
   if(victim->query_npc() == 0) {
      write("You may not attack players with this spell.\n");
      return 1;
   }
   hurt = 10+random(50);
   this_player()->spell_object(victim, "dream", hurt, 35);
   write("You send a horrible dream to "+capitalize(str)+".\n");
   tell_object(victim,
      this_player()->query_name()+" sends you a horrible dream!\n");
   tell_room(environment(this_player()),
      this_player()->query_name()+" sends a horrible dream!\n");
   return 1;
}




xsell(str) {
     string item;
     object itemob;
     int val;

     if(guild_rank < 5) {
       write("You must have a guild ranking of 5 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", item) != 1) {
       write("Useage:  xsell <item>\n");
       return 1;
     }
     itemob = present(item, this_player());
     if(!itemob) {
       write("You do not have a "+item+".\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 10) {
       write("You are too low on power.\n");
       return 1;
     }
     call_other(this_player(),"add_spell_point", -10);
     val = call_other(itemob, "query_value");
     if(val == 0) {
       write("The dragon flies in and looks at the "+item+".\n");
       write("The dragon says:  That "+item+" has no value.\n");
       say("A small dragon flies in and looks at a "+item+" in "+
           capitalize(this_player()->query_name())+"'s inventory.\n");
       say("The dragon speaks to "+capitalize(this_player()->query_name())+
           " in a foreign tongue.\n");
       return 1;
     }
     if(val > 1000) {
       val = 1000;
     }
     say("A small dragon appears and snatches a "+item+" from "+
         capitalize(this_player()->query_name())+"'s inventory.\n");
     say("Then disappears only to come back and give "+
         capitalize(this_player()->query_name())+" some money.\n");
     say("The dragon flies away.\n");
     write("A small dragon appears and takes the "+item+" to the shop.\n");
     write("The dragon returns and gives you "+val+" gold coins.\n");
     write("The small dragon flies away.\n");
     call_other(this_player(),"add_money", val);
     destruct(itemob);
     return 1;
}

shadow(str) {
   if(guild_rank < 5) {
      write("You must have a guild ranking of 5 to use this command.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 15) {
      write("You do not have enough spell points for this power.\n");
      return 1;
   }
   if(!str) {
      write("Usage: shadow <player name> or <off>.\n");
      return 1;
   }
   womble = present(str, environment(this_player()));
   if(!womble || str == "off" || !str) {
      write("You are not following anyone.\n");
      shadow = 0;
      return 1;
   }
   if(womble->query_level() >= 20) {
      write("You may not follow wizards.\n");
      return 1;
   }
   write("You are now following "+womble->query_name()+".\n");
   shadow = 1;
   this_player()->add_spell_point(-15);
   return 1;
}

recruit(str) {
     string who, recruitee;
     int level, level2;

     if(guild_rank < 10) {
       write("You must have a guild ranking of 10 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Useage:  recruit <player>\n");
       return 1;
     }
     if(!present(find_player(who), environment(this_player()))) {
       write(capitalize(who)+" is not here.\n");
       return 1;
     }
     if(present("seal", find_player(who))) {
       write(capitalize(who)+" is already a member!\n");
       return 1;
     }
     recruitee = find_player(who)->query_real_name();
     if(restore_object("players/sandman/masons/BANISHED/"+recruitee)) {
       write("That person has been banished from the Guild.\n");
       write("To re-enter the person must petition the Guildmasters.\n");
       return 1;
     }
     if(find_player(who)->query_guild_exp() > 0) {
       write(capitalize(who)+" is a member of another guild.\n");
       return 1;
     }
     level = this_player()->query_level();
     level2 = find_player(who)->query_level();
     if(level2 < 3) {
        write("A person must be level 3 to join a guild.\n");
        return 1;
     }
     move_object(clone_object("players/sandman/masons/seal"), find_player(who));
     write("You have recruited "+capitalize(who)+" into the Guild.\n");
     tell_object(find_player(who), "You have been recruited into the Guild!\n");
     tell_object(find_player(who), "Type 'seal' for a list of abilities.\n");
     find_player(who)->add_guild_exp(1);
     write_file("/open/GUILDLOGS/RECRUIT",
          capitalize(this_player()->query_real_name())+"("+
          this_player()->query_level()+") recruited "+
          capitalize(who)+"("+level2+") -> "+ctime(time())+"\n");
     return 1;
}

news() {
     cat("/players/sandman/masons/NEWS");
     return 1;
}

help_seal(str) {
     if(!str) {
       cat("/players/sandman/masons/HELP");
       return 1;
     }
     if(str == "battle") {
       cat("/players/sandman/masons/BATTLE");
       return 1;
     }
     if(str == "ranks") {
       cat("/players/sandman/masons/RANKS");
       return 1;
     }
     if(str == "start") {
       cat("/players/sandman/masons/START");
       return 1;
     }
     if(str == "summon") {
       cat("/players/sandman/masons/SUMMON");
       return 1;
     }
}

assess(str) {
     string item, me;
     object itemob;
     int class;
     me = this_player()->query_name();

     if(guild_rank < 18) {
       write("You must have a guild ranking of 18 to use this command.\n");
       return 1;
     }
     if(!str || str == "weapon" || str == "armor") {
       write("Useage:  assess weapon/armor <item>\n");
       return 1;
     }
     if(sscanf(str, "weapon %s", item) == 1) {
       itemob = present(item, this_player());
       if(!itemob) {
         write("The "+item+" is not in your possession.\n");
         return 1;
       }
       if(call_other(this_player(),"query_spell_point") < 30) {
         write("You are too low on power.\n");
         return 1;
       }
       class = call_other(itemob, "weapon_class", 0);
       if(class == 0) {
         write("You have trouble evaluating this weapon.\n");
         say(capitalize(me)+" looks befuddled.\n");
         return 1;
       }
       call_other(this_player(),"add_spell_point", -30);
       say(capitalize(me)+" studies the "+item+" carefully.\n");
       if(class < 4) {
         write("The "+item+" is a very bad weapon.\n");
         return 1;
       }
       if(class < 8) {
         write("The "+item+" is a bad weapon.\n");
         return 1;
       }
       if(class < 12) {
         write("The "+item+" is an average weapon.\n");
         return 1;
       }
       if(class < 16) {
         write("The "+item+" is a good weapon.\n");
         return 1;
       }
       if(class < 18) {
         write("The "+item+" is a very good weapon.\n");
         return 1;
       }
       if(class <= 20) {
         write("The "+item+" is an extremely good weapon.\n");
         return 1;
       }
       if(class > 20) {
         write("The "+item+" is an excellent weapon.\n");
         write_file("/players/sandman/masons/ILLEGAL",
              "Illegal weapon:  "+capitalize(this_player()->query_real_name())+
              " assessing "+call_other(itemob,"short")+" ("+creator(itemob)+")\n");
         return 1;
       }
       return 1;
     }
     if(sscanf(str, "armor %s", item) == 1) {
       itemob = present(item, this_player());
       if(!itemob) {
         write("The "+item+" is not in your possession.\n");
         return 1;
       }
       if(call_other(this_player(),"query_spell_point") < 30) {
         write("You are too low on power.\n");
         return 1;
       }
       class = call_other(itemob, "armor_class", 0);
       if(class == 0) {
         write("You have trouble evaluating this armor.\n");
         say(capitalize(me)+" looks befuddled.\n");
         return 1;
       }
       call_other(this_player(),"add_spell_point", -30);
       if(class == 1 || class == 2) {
         write("The "+item+" is average armor.\n");
         return 1;
       }
       if(class == 3) {
         write("The "+item+" is good armor.\n");
         return 1;
       }
       if(class == 4) {
         write("The "+item+" is very good armor.\n");
         return 1;
       }
       if(class > 4) {
         write("The "+item+" is excellent armor.\n");
         write_file("/players/sandman/GUILD/ILLEGAL",
              "Illegal armor:  "+capitalize(this_player()->query_real_name())+
              " assessing "+call_other(itemob,"short")+" ("+creator(itemob)+")\n");
         return 1;
       }
       return 1;
     }
     write("Useage:  assess weapon/armor <item>\n");
     return 1;
}
emote(str) {
   string me;
   if(!str) {
      write("Emote what?\n");
      return 1;
   }
   me = capitalize(this_player()->query_real_name());
   tell_room(environment(environment()),me+" "+str+"\n");
   return 1;
}

greet(str) {
    string who, me;
    object dest1;
    dest1=environment(this_player());
    me=this_player()->query_name();
    
    if(!str) {
      write("You must specify someone to greet.\n");
      return 1;
    }
    if(sscanf(str,"%s",who) != 1) {
      write("Useage:  greet <member>\n");
      return 1;
    }
    if(!find_player(who)) {
      write("That player is not on.\n");
      return 1;
    }
    if(!present("seal",find_player(who))) {
      write(capitalize(who)+" is not a guildmember.\n");
      return 1;
    }
    if(!present(find_player(who),dest1)) {
       write("That player is not here.\n");
       return 1;
    }
    tell_room(dest1,capitalize(me)+" and "+capitalize(who)+" clasp hands and join thumbnails.\n");
    tell_room(dest1,capitalize(me)+" says:  Greetings on all three points of the triangle.\n");
    tell_room(dest1,"\n");
    tell_room(dest1,capitalize(who)+" lifts his hands and makes a squared-U sign.\n");
    tell_room(dest1,capitalize(me)+" says:  Oh Lord my God is there no hope for the widow's son?\n");
    tell_room(dest1,"\n");
    tell_room(dest1,capitalize(who)+" says:  Will you spell it or triangle it?\n");
    tell_room(dest1,capitalize(me)+" says:  I will triangle it.  Ba.\n");
    tell_room(dest1,capitalize(who)+" says:  Ra.\n");
    tell_room(dest1,capitalize(me)+" says: Ka.\n");
    return 1;
}

logged_on() {
   object list, guild;
   int i, rank;
   string muffles;

   list = users();
 write("<========================================>\n");
write("Rank:\tName:        \t\n");
write("-----\t-------------\t\n");
   for(i=0; i < sizeof(list); i++) {
      guild = present("seal",list[i]);
      if(guild) {
        string name;
        name = list[i]->query_name();
        name = capitalize(name);
        if(strlen(name) < 8)
          name = name + "\t";
        rank = guild->query_guild_rank();
        if(guild->query_muffled() == 0) { muffles = ""; }
        if(guild->query_muffled() == 1) { muffles = "(muffled)"; }
        if(list[i]->query_invis() > 0) { write(""); } else
        write(rank+"\t"+name+"\t"+muffles+"\n");
      }
   }
 write("<========================================>\n");
   return 1;
}
mason_tell(str) {
     object ob, guild, mason;
     int i;
     string me;

     me = this_player();
     mason = this_object();
     if(!str) {
       Write("Tell guildmembers what?\n");
       return 1;
     }
     ob = users();
     for(i = 0; i < sizeof(ob); i++) {
        guild = present("mason_seal", ob[i]);
        if(guild && guild->query_muffled() == 0) {
          tell_object(ob[i], me->query_name()+" (guild):  "+str+"\n");
        }
     }
     return 1;
}

mason_emote(str) {
   object ob, guild;
   int i;
   string me;
   me = this_player()->query_name();
   if(!str) {
      write("Usage: me <emote string>\n");
      return 1;
   }
   ob = users();
   for(i = 0; i < sizeof(ob); i++) {
      guild = present("mason_seal", ob[i]);
      if(guild && guild->query_muffled() == 0) {
        tell_object(ob[i], "(guild): "+me+" "+str+"\n");
      }
   }
   return 1;
}

confer() {
     object guild, ob;
     int i;
     string me;

     if(guild_rank < 30) {
       write("You must have a guild rank of 30 to use this command.\n");
       return 1;
     }
     me = this_player();
     ob = users();
     for(i = 0; i < sizeof(ob); i++) {
       guild = present("mason_seal", ob[i]);
       if(guild) {
         guild->set_muffled(0);
         tell_object(ob[i], "");
         tell_object(ob[i], "----A GUILD CONFERENCE HAS BEEN CALLED----\n");
       }
     }
     return 1;
}

lay_hands(str) {
    string who, me;
    object dest2;
    me=this_player()->query_name();
    dest2=environment(this_player());

    if(guild_rank < 15) {
      write("You must have a guild ranking of 15 to use this.\n");
      return 1;
    }
    if(time() < start_time + 300) {
      write("You are too tired to treat anyone now.\n");
      return 1;
    } else
    if(!str) {
      write("Useage:  treat <player>\n");
      return 1;
    }
    if(sscanf(str, "%s", who) != 1) {
      write("Useage:  treat <player>\n");
      return 1;
    }
    if(call_other(this_player(),"query_spell_point") < 80) {
      write("You are too low on power.\n");
      return 1;
    }
    if(!find_player(who)) {
      write("Player is not on.\n");
      return 1;
    }
    if(!present(find_player(who),dest2)) {
      write("That player is not here.\n");
      return 1;
    } else
    call_other(find_player(who),"add_hit_point",random(30)+30);
    call_other(this_player(),"add_spell_point",-80);
    tell_object(find_player(who),capitalize(me)+" heals you!\n");
    tell_room(dest2,capitalize(me)+" places his hands on "+capitalize(who)+" and concentrates.\n");
    write("You heal "+capitalize(who)+".\n");
    start_time = time();
    return 1;
}

teleport(str) {
     string me, who;
     object old, guild,dest3;
     old = environment(this_player());
     me = this_player()->query_name();

     if(guild_rank < 20) {
       write("You must have a guild ranking of 20 to use this command.\n");
        return 1;
     }
     if(!str) {
       write("You must specifiy someone to teleport to.\n");
       return 1;
     }
     if(this_player()->query_attack()) {
       write("You are too busy fighting to concentrate on teleporting.\n");
       return 1;
     }
     if(str == "lodge") {
       if(this_player()->query_spell_point() < 35) {
         write("You are too low on power.\n");
         return 1;
       }
       call_other(this_player(),"move_player",
                      "in a puff of smoke#players/sandman/masons/guild_lodge");
       call_other(this_player(),"add_spell_point", -35);
       return 1;
     }
     if(sscanf(str,"%s", who) != 1) {
       write("Useage:  teleport <player>\n");
       return 1;
     }
     if(call_other(this_player(),"query_spell_point") < 75) {
       write("You are too low on power.\n");
       return 1;
     }
     if(!find_player(who) || find_player(who)->query_invis() > 0) {
       write(capitalize(who)+" is not on now.\n");
       return 1;
     }
     if(find_player(who)->query_level() > 20) {
       write("You may not teleport to wizards.\n");
       return 1;
     }
     guild = present("seal", find_player(who));
     if(!guild) {
       write("You can only teleport to other guild members.\n");
       return 1;
     }
     dest3 = environment(find_player(who));
     tell_room(old,capitalize(me)+" disappears is a flash of light.\n");
     tell_room(dest3,capitalize(me)+" arrives in a flash of light.\n");
     call_other(this_player(),"add_spell_point", -75);
     move_object(this_player(), dest3);
     return 1;
}

judge(str) {
    string what;

    if(!str) {
      write("You must specify someone to judge.\n");
      return 1;
    }
    if(sscanf(str, "%s", what) != 1) {
      write("Useage:  judge <living>.\n");
      return 1;
    }
    if(call_other(this_player(),"query_spell_point") < 5) {
      write("You are too low on power.\n");
      return 1;
    }
    if(!find_living(what) || find_living(what)->query_invis() > 0 ||
            !present(find_living(what), environment(this_player()))) {
      write(capitalize(what)+" is not here!\n");
      return 1;
    }
    if(find_living(what)->query_level() > 20) {
      write("Who are you to judge a Wizard??\n");
      return 1;
    }
    if(call_other(find_living(what),"query_alignment") < -500) {
      write(capitalize(what)+" is very mean.\n");
      call_other(this_player(), "add_spell_point", -5);
      return 1;
    }
    if(call_other(find_living(what),"query_alignment") < 0) {
      write(capitalize(what)+" is mean.\n");
      call_other(this_player(), "add_spell_point", -5);
      return 1;
    }
    if(call_other(find_living(what),"query_alignment") == 0) {
      write(capitalize(what)+" is neutral.\n");
      call_other(this_player(), "add_spell_point", -5);
      return 1;
    }
    if(call_other(find_living(what),"query_alignment") > 500) {
      write(capitalize(what)+" is very good.\n");
      call_other(this_player(), "add_spell_point", -5);
      return 1;
    } else
      write(capitalize(what)+" is good.\n");
      call_other(this_player(),"add_spell_point", -5);
      return 1;
}

summon(str) {
   object dest, demon;
   string me;
   me = this_player()->query_name();

   if(str == "guardian") {
   if(this_player()->query_spell_point() < 20) {
     write("You are too low on power.\n");
     return 1;
   }
   demon = clone_object("players/sandman/masons/guardian");
   dest = environment(this_player());
   write("You summon a guardian demon.\n");
   say(capitalize(me)+" utters an encantation and a large guardian demon "+
      "appears in a puff of smoke.\n");
   demon->set_owner(this_player()->query_real_name());
   move_object(demon, dest);
   this_player()->add_spell_point(-20);
   return 1;
   }
   if(str == "djinni") {
      if(this_player()->query_spell_point() < 20) {
        write("You are too low on power.\n");
        return 1;
      }
      write("You summon a Djinni.\n");
      say(capitalize(me)+" speaks an incantation and a Djinni appears "+
         "in a puff of smoke.\n");
      this_player()->add_spell_point(-20);
      demon = clone_object("players/sandman/masons/djinni");
      dest = environment(this_player());
      demon->set_owner(this_player()->query_real_name());
      move_object(demon, dest);
      return 1;
    }
}

cast_light(str) {
    object dest, light;
    if(!str) return 0;
    if(str == "light") {
      if(this_player()->query_spell_point() < 5) {
        write("You are too low on power.\n");
        return 1;
      }
      dest = environment(this_player());
      light = clone_object("players/sandman/masons/light");
      move_object(light, dest);
      this_player()->add_spell_point(-5);
      say(capitalize(this_player()->query_name())+" builds a magical fire.\n");
      write("You create a magical fire.\n");
      this_player()->look();
      return 1;
    }
}
