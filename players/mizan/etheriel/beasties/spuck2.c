#include "/players/mizan/esc.h"
#define BOLDBLUE ESC + "[1m" + ESC + "[34m"
#define OFF ESC + "[0m"
int x;
inherit "obj/monster";

#define LOG 1
#define GUILD_ID "Mizan-guild-object"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define HOME "/players/mizan/etheriel/ROOMS/spuck.c"
#define GUILDFILE "/players/mizan/closed/poly/gob"
#define SAVEPATH "players/mizan/closed/poly/players/"
#define LOGPATH "/players/mizan/logs/"

#define LEV_TWO_COST        40000
#define LEV_THREE_COST      80000
#define LEV_FOUR_COST      100000
#define LEV_FIVE_COST      300000
#define LEV_SIX_COST       750000
#define LEV_SEVEN_COST    1000000
#define LEV_EIGHT_COST    1500000
#define LEV_NINE_COST     2000000

/* Do not change these values without consulting me first. */

#define ATTRIB_COST          3000
#define ATTRIB_COST_TWO      4500
#define ATTRIB_COST_THREE    6000

/* Wren adjustments to bring new stat limits to polys 11-06-02 */

#define ATTRIB_COST_FOUR     12000      /* 21 - 23 */
#define ATTRIB_COST_FIVE     20000      /* 24 - 26 */
#define ATTRIB_COST_SIX      28000      /* 27 - 29 */
#define ATTRIB_COST_SEVEN    35000      /* 30      */

#define ATTRIBS_PER_LEVEL 5
#define ATTRIBS_ABOVE_LEVEL 10 
#define MAX_FREE_ATTRIB 10
#define TOTAL_FREE_ATTRIB 80

/* Costs are directly out of the new 'help attribs' */
/* End Wren addition */

string main_stats;
string comm_prefix;
string curr_morph;
string nickname;
int monitor_interval;
int screen_height;

reset(arg)
{
   object armor;
   object gold;
   int a;
   ::reset(arg);
   if(arg) return;
   set_no_clean(1);
   fake_beat();
   set_name("Spuck");
   set_race("spuck");
   set_alias("fatass");

   set_short("Spuck, the Master of the Soft and Squishy things");
   set_long("Before you is a semi-translucent bulk of a thing, constantly\n"+
	"changing color and shape. Spuck is composed of a nearly indestructable\n"+
	"compound and it would NOT be a very good idea to try killing it.\n"+
	"It appears that Spuck will buy any items you may wish to sell.\n");
   set_level(25);
   set_hp(50000);
   set_al(0);
   set_wc(25);

   set_ac(56);
   set_heal(15,10);
   while(a < 5) 
   {
      gold=clone_object("players/mizan/etheriel/items/spuckballs-ext3.c");
      move_object(gold,this_object());
      a++;
   }

   gold = clone_object("/players/mizan/etheriel/items/spuck-flexgun.c");
   move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext3.c"), gold);
   move_object(gold, this_object());

   set_chat_chance(8);

   load_chat("Spuck absorbs something. It looks gross.\n");
   load_chat("Spuck says: Howdy!\n");
   load_chat("Spuck says: I have good prices!\n");
   load_chat("Spuck blinks.\n");
   load_chat("Spuck wibbles: Are you here to join the Polymorphs?\n");
   load_chat("Spuck says: All you have to do is 'join polymorphs'.\n");
   load_chat("Spuck grins biggly.\n");
   load_chat("Spuck noggles violently.\n");
   load_chat("Spuck changes color.\n");
}

init() 
{
   ::init();
   add_action("sell","sell");
   add_action("buy","value");
   add_action("buy","buy");
   add_action("buy","list"); 

   add_action("advance","advance");
   add_action("join","join");
   add_action("raise","raise");
}

fake_beat() 
{
   object att;
   string temp;
   
   att = this_object()->query_attack();

   if(att && att->query_guild_name() == "polymorph")
   {
      say("Spuck growls: You ungrateful shit!\n");
      
      temp = "[" + ctime() + "] " + att->query_real_name() + " attacked Spuck and was expelled from polys.\n";
      write_file(LOGPATH + "ATTACK_SPUCK", temp);

      MASTER_R->guild_deduct_stats(att->query_real_name());

      tell_object(att, "Spuck kicks you out of the guild!\n\n");
      say("Spuck does something funky.\n");

      MASTER_R->guild_echo(BOLDBLUE + ">> A toaster vibes: " + OFF + capitalize(att->query_real_name()) +
      " has been dismissed from the guild for attacking Spuck.\n");

      att->attack_object();
      att->attack_object();
      att->stop_fight();
      att->stop_fight();
      att->stop_hunter();
      att->stop_hunter();

      this_object()->attack_object();
      this_object()->attack_object();
      this_object()->stop_fight();
      this_object()->stop_fight();
      this_object()->stop_hunter();
      this_object()->stop_hunter();
      
      att->move_player("X#room/wild1");
   }
   
   if(att && 1 == random(20))
   {
      MASTER_R->guild_echo(BOLDBLUE + ">> Spuck grobbles: " + OFF + "Uh... I am currently being attacked by " + att->query_name() + "...\n");
   }
   remove_call_out("fake_beat");
   call_out("fake_beat", 2);
}

buy() 
{
   write("You can only sell things to Spuck.\n");
   return 1;
}

sell(item) 
{
   object ob;
   if(!item) return 0;
   if(item == "all") 
   {
      object next;
      ob = first_inventory(this_player());
      while(ob) 
      {
         next = next_inventory(ob);
         if(environment(ob))
            if(!ob->drop() && ob->query_value() && environment(ob) != this_object()) 
            {
                write(ob->short() + ":\t");
                do_sell(ob);
            }
         ob = next;
      } /* end of while */

   write("Ok.\n");
   return 1;
   } /* end of item == all */


   ob = present(item, this_player());
   if(!ob) ob = present(item, this_object());
      if(!ob) 
      {
         write("Spuck groks: No such item ("); write(item); write(") here.\n");
         return 1;
      }
   do_sell(ob);
   return 1;
}

do_sell(ob) 
{
   int value;
   value = ob->query_value();
   if(!value) 
   {
      write("Spuck glorps: " + ob->short() + " is worth squat!\n");
      return 1;
   }
   if(environment(ob) == this_player()) 
   {
      int weight;
      if(call_other(ob, "drop", 0)) 
      {
         write("Spuck says: can't take it from you!\n");
         return 1;
      }
      weight = call_other(ob, "query_weight", 0);
      call_other(this_player(), "add_weight", - weight);
   }

   /* changed by mythos with mizan's permission - 11/6/95 */
 
   if(value > 1000 && ob->query_guild_name() != "polymorph") 
   {
      value=random(10)+1000;
      write("Spuck says: Hmmm.... I'm a bit low on money...\n");
   }
  
   else if(value > 1000 && ob->query_guild_name() == "polymorph") 
   {
      value = random(20) + 1000;
      write("Spuck says: Hmm... I'm a bit low on money. Your donation is appreciated :)\n");
   }

   write("You get "); write(value); write(" gold coins.\n");
   say(call_other(this_player(), "query_name", 0) + " sells " +
   call_other(ob, "short", 0) + ".\n");

   call_other(this_player(), "add_money", value);
   write("Spuck absorbs the item, and it is gone...\n");
   destruct(ob);
   return 1;
}

find_item_in_player(i) 
{
   object ob;
   ob = first_inventory(this_player());
   while(ob) 
   {
      if(call_other(ob, "id", i)) return ob;
      ob = next_inventory(ob);
   }
   return 0;
}

query_permanency() { return 1; }

int doing_tl;

join(str) 
{
   object tp;
   tp = this_player();
   
   if(tp->query_real_name() == "guest") 
   {
      write("Spuck looks at you and goes: 'Doh!'\n");
      return 1;
   }
  
   if(tp->query_level() < 3) 
   {
      write("Spuck says: I'm sorry, but you must be at least level 3 to join any guild.\n");
      return 1;
   }
  
   if(restore_object(SAVEPATH + (tp->query_real_name()))) 
   {
      if(curr_morph == "[BANISHED]") 
      {
         write("Spuck grogs: Whoa! Hold on buddy, you were banished. Etc.\n");
         return 1;
      }
      
      if(curr_morph == "[LEFT]") 
      {
         write("Spuck grogs: Hmm... You have to mail Mizan if you want back in.\n");
         write("Spuck gorks: It's not my decision, really.\n");
         return 1;
      }

      if(!present(GUILD_ID, this_player()) && tp->query_guild_name() == "polymorph") 
      {
         move_object(clone_object(GUILDFILE), tp);
         tp->set_guild_file(GUILDFILE);
         write("Spuck tells you: Oooh.. you lost your lump of clay...\n"+
         "Spuck tells you: I'll give you a new one... Here ya go.\n");
         write_file("/players/mizan/logs/RENEWAL", (tp->query_real_name()) +
         " renewed a clay on " + ctime() + ".\n");
         write("Spuck detaches some of itself and has given you a new lump of clay.\n");
         return 1;
      }
      write("Spuck boggles: You are already in the guild!\n");
      return 1;
   }

   if(!str) 
   {
      write("Spuck tells you: What do you want to join?\n");
      return 1;
   }
   
   if(str != "polymorphs") 
   {
      write("Spuck borgles: Sorry, I don't handle that organization.\n");
      return 1;   
   }
   
   if(doing_tl) 
   {
      write("Spuck is busy with someone, please wait for a minute.\n");
      return 1;
   }

   write("Spuck tworbles: Hmm... So you want to join the polymorphs, eh?\n");
   write("  There are'nt many rules you need to follow but if you break any one\n"+
   "  of them you will be in deep splork.\n");

   if(tp->query_pl_k()) 
   {
      write("\nSpuck blaps: For one, player killers will not be able to polymorph.\n"+
      "  Come back someday when you don't have your player killing flag set anymore.\n");
      return 1;
   }
   doing_tl = 1;
   write("\nSpuck postulates: Most importantly, we are a family. There is no\n"+
   "  guild command as you know it and everyone here are treated as EQUALS\n"+
   "  whether they are level 1 or level 5. The only exeception to this are\n"+
   "  guild admins, of which so far is only Mizan, and elder wizards, who are\n"+
   "  outside the jurisdiction of guilds in general.\n");
   write("Spuck borks: Do you agree to this term? (y or n)\n");
   input_to("join2");
   return 1;
}

join2(str) {
  if(!str) {
    write("Spuck goes: What?\n");
    input_to("join2");
  } else
  if(str == "y" || str == "yes" || str == "Y") {
    write("Spuck seems to nod in agreement.\n");
    write("\nSpuck glorbles: Okay. You will also have to agree that an unprovoked\n"+
   "  attack on other members of the guild will get you banished, no matter what.\n"+
   "\nSpuck floogs: Attacking me as well will have the same effect.\n"+
   "Spuck grins biggly.\n");
    write("Spuck borks: Do you agree to this term? (y or n)\n");
    input_to("join_final");
    return 1;
  } else 
  if(str =="n" || str == "no" || str == "N") {
    write("Spuck morbles: I'm sorry then. You would not fit into the guild if you\n"+
    "  did not believe in the concept of the guild as a family.\n");
    doing_tl = 0;
    return 1;
  } else {
    write("Spuck goes: What? Type 'y' or 'n'.\n");
    input_to("join2");
    return 1;
  }
}

join_final(str) {
  object tp;
  tp = this_player();
  if(!str) {
    write("Spuck goes: What?\n");
    input_to("join2");
  } else
  if(str == "y" || str == "yes" || str == "Y") {
    if(!tp->query_guild_name() || tp->query_guild_name() == "none") {
      if(tp->query_guild_exp() || tp->query_guild_rank()) {
         write("Spuck bombles: Technically, you were still in a guild.\n"+
        "Clearing all previous guild stats...\n");
        tp->add_exp(tp->query_guild_exp());
        tp->add_guild_exp(-(tp->query_guild_exp()));
        tp->add_guild_rank(-tp->query_guild_rank());
      }
      tp->add_guild_rank(1);
      main_stats = "none#" + tp->query_attrib("sta") + "#" +
      tp->query_attrib("int") + "#" +

      tp->query_attrib("mag") + "#" +
      tp->query_attrib("str") + "#" +
      tp->query_attrib("ste") + "#" +
      tp->query_attrib("luc");
      tp->set_guild_file(GUILDFILE);

      comm_prefix = "vibe";
      curr_morph = "none";
      nickname = "none";
      monitor_interval = 3;
      screen_height = 23;
      tp->set_guild_name("polymorph");
      save_object(SAVEPATH + (tp->query_real_name()));
     write("Spuck cheers happily!\nSpuck says: Welcome to the guild!!\n    Type 'info listing' for a list of help topics...\n"+
      "    Type 'vibe <msg>' to communicate on the guild channel,\n"+
      "    and 'guild who' to see who else is logged on.\n"+
    "\n");
      say((this_player()->query_name()) + " has joined the polymorphs!\n");
  write_file("/players/mizan/logs/JOIN",
    (this_player()->query_real_name()) + " joined the guild on " + ctime() + "\n");
      move_object(clone_object(GUILDFILE), this_player());
      MASTER_R->guild_echo(BOLDBLUE + ">> Spuck announces: " + OFF + (this_player()->query_name()) + " has joined the guild! Yay!\n");
      doing_tl = 0;
      return 1;
    }
    write("Spuck mmmrugs: You must leave your old guild first.\n");
    doing_tl = 0;
    return 1;
  } else 
  if(str =="n" || str == "no" || str == "N") {

    write("Spuck morbles: I'm sorry then. You would not fit into the guild if you\n"+
    "  cannot agree to attack other members and me unprovoked.\n");
    doing_tl = 0;
    return 1;

  } else {
    write("Spuck goes: What? Type 'y' or 'n'.\n");
    input_to("join_final");
    return 1;
  }
}


advance() {
  int gexp,next_exp,level,rank;
  int min_exp,value;
  object gob;

  level = this_player()->query_level();
  gob = present(GUILD_ID, this_player());
  gexp = this_player()->query_guild_exp();
  rank = this_player()->query_guild_rank();


  if(!gob) return 0;
  if(this_player()->query_ghost()) {

    write("Spuck boggles at you.\n"+
    "Spuck swibbles: But you're phased as a ghost! Go restore yourself and come back.\n");

  }

  if(this_player()->query_level() > 20) {

    write("Spuck gobbles something in disbelief.\n"+
    "Spuck goes: Hmm... It's 'this_player()->add_guild_rank(x)'\n"+
    "if you can patch yourself. Bog!\n");
    return 1;
  }

  if(this_player()->query_extra_level()) 
    min_exp = call_other("/room/exlv_guild", "get_next_exp", (this_player()->query_extra_level()-1));
  else min_exp = call_other("/room/adv_guild", "get_next_exp", (this_player()->query_level()-1));
  value = (this_player()->query_exp() + (-min_exp));
  if(rank == 1) next_exp = LEV_TWO_COST;
  if(rank == 2) next_exp = LEV_THREE_COST;
  if(rank == 3) next_exp = LEV_FOUR_COST;
  if(rank == 4) next_exp = LEV_FIVE_COST;

  if(rank >= 5 && rank < 10) 
  {
    write("Spuck boggles: Hey! you're already at the highest level in the guild!\n");
    return 1;
  }

  if(rank >= 10) {
    write("Spuck grins biggly.\n"+
    "Spuck glorps: Don't be greedy.\n");
    return 1;
  }

  if(value < next_exp) 
  {
    write("Spuck looks you over carefully.\n"+
    "Spuck bombles: Somehow, I don't think you are ready for the next level.\n"+
    "Come back after you get ["+ (next_exp - value) + "] more experience.\n");
    return 1;
  }

  write("\nYou have been promoted to guild level " + (rank + 1) + " by Spuck.\n");
  say((this_player()->query_name()) + " has advanced in " + (this_player()->query_possessive()) + " level in " +
  (this_player()->query_possessive()) + " guild.\n");
  if(rank == 1) write("Spuck pats you on the head.\nSpuck bleats: Nice job!");
  if(rank == 2) write("Spuck licks you.\n");
  if(rank == 3) write("Spuck grins biggly.\n");
  if(rank == 4) write("Spuck cheers.\nSpuck bobbles: You are at the highest level in the guild!\n");
  
  this_player()->add_exp(-next_exp);
  this_player()->add_guild_exp(next_exp);
  this_player()->add_guild_rank(1);

  write("You are now guild level [" + ( rank + 1 ) + "].\n");
  say((this_player()->query_name())+" is now level [" + ( rank + 1 ) + "] in the guild.\n");

  this_player()->save_me();
  gob->record_attribs();

  MASTER_R->guild_echo(BOLDBLUE + ">> Spuck moggles: " + OFF + capitalize(this_player()->query_real_name()) +
  " advanced to level " + (rank + 1) + "!\n");
 
#ifdef LOG
  write_file("/players/mizan/logs/ADVANCE",
  this_player()->query_real_name()+" advanced to "+
  this_player()->query_guild_rank()+" on "+ctime()+"\n");
#endif

  remove_call_out("cheer");
  call_out("cheer", (5 + random(3)));
  return 1;
}

cheer() {
  MASTER_R->guild_echo(BOLDBLUE + ">> (vibe) " + OFF + "Spuck gives off a round of applause!\n");
  return 1;
}

raise(str) {
  object gob;
  int new,expcost,current,minexp,next_exp;
/* Wren adding string and int for the new Illarion code */
  string attrib,raise,thing;
  int totalattrib,totallevel,maxachived;

  gob = present(GUILD_ID, this_player());
  if(!gob || this_player()->query_guild_name() != "polymorph") return 0;
  if(gob->query_current_morph() != "none") {
    write("Spuck groks: Get out of polymorph first.\n");
    return 1;
  }

  if(str !="str" && str !="sta" && str != "wil" && str != "mag" &&
    str !="pie" && str != "ste" && str != "luc" && str != "int" &&
/* Wren addition for charisma and dexterity */
    str != "cha" && str != "dex")
/* Wren addition ends */
    {
    write("Spuck goes: Huh? Raise what stat? \n");
    return 1;
  }

  if(this_player()->query_level() > 19) 
  {
    write("Spuck grombles: Bok! Silly wizards.\n");
    return 1;
  }
  current = call_other(this_player(), "query_attrib", str);
  new = current + 1;
  if(current < 12) expcost = -ATTRIB_COST;
  if(current < 16 && current > 11) expcost = -ATTRIB_COST_TWO;
  if(current < 20 && current > 15) expcost = -ATTRIB_COST_THREE;

/* Wren addition for new stat levels */
  if(current < 23 && current > 19) expcost = -ATTRIB_COST_FOUR;
  if(current < 26 && current > 22) expcost = -ATTRIB_COST_FIVE;
  if(current < 29 && current > 25) expcost = -ATTRIB_COST_SIX;
  if(current < 30 && current > 28) expcost = -ATTRIB_COST_SEVEN;

  if(current > 29) {
    write("Spuck glorps: That attribute is at its highest possible value.\n");
    return 1;
/* Wren additions end */
  }
  /* if over 20, and lost attrib, charge same as 20 to regain -Bp*/
  maxachived = this_player()->query_attrib_max(str);
  if(maxachived > current && new > 20)
     expcost = -ATTRIB_COST_THREE;


if(this_player()->query_extra_level() < 1) {
     next_exp = call_other("/room/adv_guild", "get_next_exp", (this_player()->query_level()-1));
     minexp = this_player()->query_exp() - next_exp; 
     }

if(this_player()->query_extra_level() > 0) {
     next_exp = call_other("/room/exlv_guild", "get_next_exp", (this_player()->query_extra_level()-1));
     minexp = this_player()->query_exp() - next_exp; 
     }


    if(-(expcost) > minexp) {
            write("Spuck grombles: You don't have enough free experience available.\n");
            return 1;
      }


/* Wren addition for limiting stat raises per level as set by Illarion's code 
 * in the adv_guild. On second thought to cover all possibilities I'll include 
 * all the new raise code in case of poly joining at lvl 3 and not having spent
 * total points. dunno should work ok, makes spuck a bit lumpier.
*/

  totalattrib=this_player()->query_total_stats();
  totallevel=this_player()->query_level()+this_player()->query_extra_level();


 
      /* Max 5 raises per level */
         if(totalattrib >= TOTAL_FREE_ATTRIB+(ATTRIBS_PER_LEVEL*totallevel) &&
            current > 14 ) {
            write("Spuck glorples: You must gain a level before raising your attributes.\n");
            return 1;
       }
      /* Attribs can't be more than 10 above current level */
         if(new > totallevel+ATTRIBS_ABOVE_LEVEL) {
            write("Spuck glorps: You cannot raise "+str+" higher at your current level.\n");
            return 1;
       }

      /* Finish allocating 80 free attribs before buying any, so it doesn't mess the count up */      
         if(new > MAX_FREE_ATTRIB && totalattrib < TOTAL_FREE_ATTRIB) {
            write("Spuck grombles: Finish allocating your free attributes before buying one.\n");
            return 1;
       } 
      /* Calculate the cost.  Stat raises are free if the new stat is 10 or lower, and under
         80 total stats have been allocated */       
         if( totalattrib < TOTAL_FREE_ATTRIB ) {
             expcost = 0;
             write("Spuck glorps: You have "+(TOTAL_FREE_ATTRIB-totalattrib-1)+" free customize stat points left.\n");
             return 1;
       }  
/* Wren addition ends */

  

  write("You feel Spuck patching your internal stats.\n");
  call_other(this_player(), "set_attrib", str, new);

  if(new > maxachived)
    call_other(this_player(), "add_attrib_max", str,1);
  this_player()->add_exp(expcost);
  MASTER_R->record_stats(this_player());
  this_player()->reset(1);
  this_player()->save_me();
  write("Spuck says: Ok.\n");
  return 1;
}

heal_self(n) 
{
int damm;
damm = n;
  if(damm < -25) damm = -25;
  ::heal_self(damm);
}

query_prevent_shadow() { return 1; }

heart_beat() 
{
  set_ac(56);
  set_wc(26);
  set_heal(15,10);
  ::heart_beat();
}
