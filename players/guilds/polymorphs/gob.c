#define GUILD_ID "Mizan-guild-object"
#define MORPH_ID "Mizan-morph-object"
#define GUILD_NAME "polymorph"

#define GUILDFILE "/players/mizan/closed/poly/gob.c"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define SAVE_PATH "players/mizan/closed/poly/players/"
#define ENV (environment(this_object()))
#define CHARGE_MAX 2300
#define GOB_VERSION 325

#include "/obj/ansi.h"

status message_received; /* earwax - for handling player issues */
int gob_version;
int v_gob_age_ticker;             /* work-around by Vertebraker .. make this thing be able to morph faster */
int gob_age;                      /* The age of the clay, in ticks. Cumulative.*/

int entered;
/* toggles */
int invis_tl;                     /* If we want our guild object visible or not */
int muffle_tl;                    /* If we are muffled from the guild channel or not */
int monitor_tl;
int msg_tl;
int moncharge_tl;
int drain_tl;
int eval_tl;
int news_tl;
int max_tl;
int rf_tl;
int snoop_tl;

/* set variables */
int monitor_interval;             /* How many seconds delay for the monitor to call */
int screen_height;
int wimpy_pct;                    /* The percentage where wimpy kicks in */

string curr_morph;                /* Text string of our current morph form. Similar to an ID */
string saved_pretitle;            /* Our saved pretitle */
string saved_title;               /* Our saved title */
string main_stats;                /* Our stats - attribs saved here between boots or morphs */

int news_index;

int autocharge_tl;
string panic_key;                 /* The key assigned to our wimpy function */
string superstat_key;             /* The key assigned to our quickstat function */
string nickname;                  /* Our nickname (cosmetic) */
string sig;                       /* Our signature in news */
string doing;                     /* What we may be doing right now (cosmetic) */
string msgin;                     /* Our entry message on the guild channel */
string msgout;                    /* Our exit message on the guild channel */
string thingname;
string thingcomm;

int charge_power;                 /* The number of charges in the clay. MAX should be 2300 */

/* for combat */
int combat_rounds;                /* total number of combat rounds where extra limbs hit */
int combat_rounds_overcap;        /* The number of rounds where our calc damage > damage cap */
int combat_hpdam_total;           /* Total number of hitpoint damage inflicted to hit_player() */
int combat_peakdam;               /* Our peak amount of damage (before capped!) */

/* for magic combat */
int magic_casts;                  /* Total number of spells cast */
int magic_casts_overcap;          /* Total number of times where our calc damage exceeded the damage cap */
int magic_hpdam_total;            /* Total number of hitpoints inflicted on the enemy */
int magic_peakdam;                /* Our peak amount of damage. This may not be very exciting */

/* for tug-push */
int linna_tug_items;              /* total number of items tugged from ether-muck */
int linna_push_items;             /* total number of items pushed into ether-muck */
int linna_weapons_wc_total;       /* sum of all the WC of all the weapons pushed */
int linna_weapons_num_total;      /* # of total weapons pushed in */
int linna_armor_ac_total;         /* [ARRAY] sum of all the armor classes of all armors pushed */
int linna_armor_num_total;        /* [ARRAY] # of total armors pushed in */
int linna_items_value_total;      /* total value in coins of items pushed */
int linna_tugitems_value_total;   /* total value of items tugged */

/* for morph count */
int morph_count;                  /* [ARRAY] The number of times we have morphed into things */
int morph_lastform;               /* [ARRAY] The time we last morphed into something */
int morph_totalcount;             /* [ARRAY] The total number of times we have morphed into things */
string morph_day;                 /* This should be a string representing TODAY */

/* polymorph form specific */
string treehouse_desc;            /* string description of a treehouse */
int necromonger_ballcharges;      /* The amount of charges used by necromonger corpse ball */

/* others */
static object follow_ob;
static string comm_prefix;
static string self_file;
static string new_hd;
static string new_body;
static int monitor_call;
static int beat_check;

status is_casting_single_attack;
status is_casting_closer_attack;

/* added as an afterthought to deal with multiplehit morphs properly */
int damage_spool;

id(str) { return str == "moomoo" || str == GUILD_ID || str == "GI" || str == "ND" || str == "lump" || str == "clay" || str == "no_disease"; }

short() 
{
   if(invis_tl && this_player()) 
   {
      if(this_player()->query_guild_name() == GUILD_NAME ||
            this_player()->query_level() > 20) return "A lump of magical clay (invis)";
      else return 0;
   }
   return "A lump of magical clay";
   
}

long() 
{
   write("This appears to be just any old lump of clay but it has many\n"+
      "powers and abilities, the most important of them keeping the matrix\n"+
      "of your being- which frees you to polymorph into different shapes.\n"+
      "It pulsates with a strangely powerful yet pleasant feeling.\n\n"+
      "Type 'info' for a list of info and abilities.\n");
   
   if(charge_power) write("There are [" + charge_power + "] charges accumulated in the clay's matrix.\n");
}

get() { return 1; }
drop() { return 1; }

/* query functions */
query_age() { return gob_age; }

query_original() { return 1; }
query_drain() { return drain_tl; }
query_eval() { return eval_tl; }
query_invis() { return invis_tl; }

query_max() { return max_tl; }
query_monitor() { return monitor_tl; }

query_muffle() { return muffle_tl; }
query_moncharge() { return moncharge_tl; }
query_news_announce() { return news_tl; }

query_main_stats() { return main_stats; }

query_charge() 
{
   if(charge_power < 0) charge_power = 0;
   return charge_power;
}
query_morph_comm() { return comm_prefix; }
query_current_morph() { return curr_morph; }

query_pretitle() { return saved_pretitle; }
query_title() { return saved_title; }

query_wimpy_pct() { return wimpy_pct; }

query_nickname() { return nickname; }
query_sig() { return sig; }
query_doing() { return doing; }
query_msgin() { return msgin; }
query_msgout() { return msgout; }
query_panic_key() { return panic_key; }
query_autocharge() { return autocharge_tl; }
query_msg() { return msg_tl; }
query_superstat_key() { return superstat_key; }
query_screen_height() { return screen_height; }
query_monitor_interval() { return monitor_interval; }
query_news_index() { return news_index; }
query_thing_name() { return thingname; }
query_thing_comm() { return thingcomm; }
query_follow_ob() { return follow_ob; }

/* used by tug-push */
query_linna_tug_items() { return linna_tug_items; }
query_linna_push_items() { return linna_push_items; }
query_linna_weapons_wc_total() { return linna_weapons_wc_total; }
query_linna_weapons_num_total() { return linna_weapons_num_total; }
query_linna_armor_ac_total() { return linna_armor_ac_total; }
query_linna_armor_num_total() { return linna_armor_num_total; }
query_linna_items_value_total() { return linna_items_value_total; }
query_linna_tugitems_value_total() { return linna_tugitems_value_total; }

/* used by morph tracking */
query_today() { return extract(ctime(time()), 4, 9); }
query_morph_count(arg) { return morph_count[arg]; }
query_morph_lastform(arg) { return morph_lastform[arg]; }
query_morph_count_all() { return morph_count; }
query_morph_lastform_all() { return morph_lastform; }

/*
 * used to track extra hits 
 */
query_combat_rounds() { return combat_rounds; }
query_combat_avgdam() 
{ 
   if(combat_rounds == 0) return 0;
   else return (combat_hpdam_total / combat_rounds); 
}
query_combat_totaldam() { return combat_hpdam_total; }
query_combat_peakdam() { return combat_peakdam; }
query_combat_rounds_overcap() { return combat_rounds_overcap; }

/*
 * used to track magic casts 
 */
query_magic_casts() { return magic_casts; }
query_magic_avgdam() 
{ 
   if(magic_casts == 0) return 0;
   else return (magic_hpdam_total / magic_casts); 
}
query_magic_peakdam() { return magic_peakdam; }
query_magic_totaldam() { return magic_hpdam_total; }
query_magic_casts_overcap() { return magic_casts_overcap; }

/* used to track magic per round */
query_is_casting_single_attack() { return is_casting_single_attack; }
query_is_casting_closer_attack() { return is_casting_closer_attack; }

/*
 * morph form settings and toggles queries 
 */
query_treehouse_desc() { return treehouse_desc; }
query_necromonger_ballcharges() { return necromonger_ballcharges; }

/*
 * set functions 
 */
set_current_morph(str) { curr_morph = str; }
set_morph_comm(str) { comm_prefix = str; }
set_pretitle(str) { saved_pretitle = str; }
set_title(str) { saved_title = str; }

set_nickname(str) { nickname = str; }
set_sig(str) { sig = str; }
set_doing(str) { doing = str; }
set_msgout(str) { msgout = str; }
set_msgin(str) { msgin = str; }
set_panic_key(str) { panic_key = str; }
set_wimpy_pct(arg) { wimpy_pct = arg; }
set_superstat_key(str) { superstat_key = str; }

set_screen_height(str) { screen_height = str; }
set_monitor_interval(str) { monitor_interval = str; }
set_news_index(str) { news_index = str; }
set_thing_name(str) { thingname = str; }
set_thing_comm(str) { thingcomm = str; }

set_follow_ob(arg) { follow_ob = arg; }
set_main_stats(str) { main_stats = str; }

/* used to track magic per round */
set_casting_single_attack() { is_casting_single_attack = 1; }
set_casting_closer_attack() { is_casting_closer_attack = 1; }

/* poly sets */
set_treehouse_desc(str) { treehouse_desc = str; }

/* set */
set_morph_count(arg) { morph_count = arg;}
set_morph_lastform(arg) { morph_lastform[arg] = gob_age; }

/* add functions */ 
add_damage_spool(arg) { damage_spool += arg; }   /*This is called by MASTER_R->extra_hit() */

/* used by polymorph forms */
add_necromonger_ballcharges(arg) { necromonger_ballcharges += arg; }

/* used by tug-push */
add_linna_tug_items() { linna_tug_items++; }
add_linna_push_items() { linna_push_items++; }
add_linna_weapons_wc_total(arg) { linna_weapons_wc_total += arg; }
add_linna_weapons_num_total() { linna_weapons_num_total++; }
add_linna_armor_ac_total(arg, elm) { linna_armor_ac_total[elm] += arg; }
add_linna_armor_num_total(elm) { linna_armor_num_total[elm]++; }
add_linna_items_value_total(arg) { linna_items_value_total += arg; }
add_linna_tugitems_value_total(arg) { linna_tugitems_value_total += arg; }

/* used by morph tracking */
add_morph_count(arg) 
{
   morph_count[arg]++; 
   morph_totalcount[arg]++;
   record_attribs();
}

reset(arg) 
{
   if(!arg) call_out("delayed_reset", 1);
}

delayed_reset() 
{
   int i;
   
   if(ENV) 
   {
      /* Unless we are a wiz, log our entry into the arrival log. */
      if(ENV->query_level() < 21)
         log_file("mizan.gob", ("[" + ctime() + "] " + ENV->query_real_name()) + " received a lump of clay.\n");
      
      self_file = ENV->query_real_name();

      /* initialize our arrays */
      if(!linna_armor_num_total) linna_armor_num_total = allocate(7);
      if(!linna_armor_ac_total) linna_armor_ac_total = allocate(7);

      /* If no stats are recovered, destroy the object */
      if(!restore_object(SAVE_PATH + self_file) && ENV->query_level() < 21)
         destruct(this_object());

      /* init our variables that need it to their defaults. */
      if(!curr_morph) curr_morph = "none";
      if(!panic_key) panic_key = "c";
      if(!superstat_key) superstat_key = "q";
      if(!monitor_interval) monitor_interval = 3;
      if(!screen_height) screen_height = 23;
      if(!doing) doing = "wandering";
      if(!msgin) msgin = "enters the confusion.";
      if(!msgout) msgout = "has left the building.";
      if(!sig) sig = ENV->query_name();
      if(sizeof(morph_count) == 0) morph_count = allocate(128);
      if(sizeof(morph_lastform) == 0) morph_lastform = allocate(128);
      if(sizeof(morph_totalcount) == 0) morph_totalcount = allocate(128);

      if(!morph_day) morph_day = query_today();
      else
      {
         /* check that if the morph day has changed, we can reset our
          * counters for the day... 
          */
         if(morph_day != query_today())
         {
            for(i = 0; i < sizeof(morph_count); i ++)
            {
                morph_count[i] = 0;
            }
            morph_day = query_today();
         }
      }
      
      if(!gob_version || gob_version < 323)
      {
         linna_tug_items = 0;
         linna_push_items = 0;
         linna_weapons_wc_total = 0;
         linna_weapons_num_total = 0;
         linna_armor_ac_total = allocate(7);
         linna_armor_num_total = allocate(7);
         linna_items_value_total = 0;
         linna_tugitems_value_total = 0;
         gob_version = GOB_VERSION;
      }

      beat_check = 0;
      command("set statkey " + superstat_key, ENV);
      command("set panic " + panic_key, ENV);
      MASTER_R->entrance(ENV);
      monitor_display();
      fake_beat();

      /* added by wizardchild to allow invis login */
      if(ENV->query_invis() < 20)
         if(msgin && msg_tl) command("vibe :" + msgin, ENV);
   }
}


fake_beat() 
{
   object vict;
   object room;
   string roomname;
   
   vict = ENV->query_attack();
   room = environment(ENV);
   /* gob_age ++;  too extreme .. */
    gob_age++;
    if(++v_gob_age_ticker == 3)
    {
      v_gob_age_ticker=0;
      gob_age++;
    }
   
   if(room) roomname = file_name(room);
   
   if(ENV) 
   {
      
      /* i dont want polys in PK realms for ANY reason */
      
      /* Revision: There is difficulty in controlling people from PK
         * areas when a lot of them do not even know where they exist.
         * Now they will take damage like dark mages to light if it happens.
         *
         * MORE REVISION: I am taking the damage out. Players get notification
         * if they are in a PK area. They should be able to do quests and
         * participate in PK combat if they are attacked.
         *
         * 21 nov 2003 I put the damage back in. The actions of a few players
         * getting people killed made things unacceptable.
         */
      
      
      if(room && roomname == ENV->query_fight_area())
      {
/*
         ENV->hit_player(5);
         tell_object(ENV, HIR + "You are in a PK zone... You bleed.\n" + NORM);
*/
         if(1 == random(20))
         {
            tell_object(ENV, "Spuck tells you: Hey... you appear to be in a PK zone...\n");   
         }
      }
      
      /* This is here as a delayed hit_player() call on a monster, used
      * with the morph forms that do multiple attacks and stuff.
      * ATTENTION WIZZES: All of the extra damage done by extra arm hits
      * is done here... 
      */        
      if(vict && damage_spool && !vict->query_ghost()) 
      {
         /*
          * If i am over the official damage cap 50 at 60... i get some of those
          * points back. Otherwise the damage is capped at 50.
          */
         
         /* If this eclipses our previous best, make note of it */
         if(damage_spool > combat_peakdam) combat_peakdam = damage_spool;

         /* we are over the cap. Record that as well. */
         if(damage_spool > 40) combat_rounds_overcap ++;

         /* If over 50, soften the cap to 40 + random 10, else a hard cap to 40. */
         if(damage_spool > 50) damage_spool = 40 + random(10);
         else if(damage_spool > 40) damage_spool = 40;
 
         /* Now hit the opponent... BUT DONT KILL THEM */         

         if(vict->query_hp() < damage_spool) damage_spool = vict->query_hp() / 2;

         if(damage_spool > 1) vict->hit_player(damage_spool);
         
         /* increment stats */
         combat_rounds ++;
         combat_hpdam_total = combat_hpdam_total + damage_spool;
         damage_spool = 0;
      }
            
      if(wimpy_pct && ENV->query_attack() &&
            ((ENV->query_hp() * 100) / ENV->query_mhp()) < wimpy_pct)
      {
         if(follow_ob) 
         {
            tell_object(ENV, "You disengage follow.\n");
            follow_ob = 0;
         }
         tell_object(ENV, "You panic and flee for your life!\n");
         if(!ENV->query_ghost()) ENV->run_away(); 
      }
      
      if(curr_morph != "none" && !present(MORPH_ID, ENV)) MASTER_R->undo_polymorph(ENV);
      if(ENV->query_ghost()) MASTER_R->undo_polymorph(ENV);
      
      if(follow_ob) update_follow();
      
      /* Removing guild monitor as these are now illegal -Snow 4/99
       * Monitor is back as of 07 AUG 2001 - they display poly specific info in combat.
       */
      if(ENV->query_attack()) monitor_display();
      else if(monitor_tl && monitor_call >= monitor_interval) monitor_display();

      if(autocharge_tl && ENV->query_sp() == ENV->query_msp()) 
      {
         /* added afterthought -mizan */
         if(!ENV->query_attack())
            if(curr_morph == "none" || curr_morph == "wombat") command("charge 10", ENV);
      }
      monitor_call++;
   }

   is_casting_single_attack = 0;
   is_casting_closer_attack = 0;

   remove_call_out("fake_beat");
   call_out("fake_beat",1);
}


monitor_display() 
{
   if(max_tl) 
   {
      if(ENV->query_mhp() == ENV->query_hp() &&
         ENV->query_msp() == ENV->query_sp()) return 0;
   }

   if(moncharge_tl) MASTER_R->superstat(ENV, charge_power);
   else MASTER_R->superstat(ENV);
   monitor_call = 0;
}

init() 
{
   /* this should be used sparingly. it is a resource hog. */

   /*
   if(this_player()->query_real_name() == "apathy")
   {
      this_player()->add_exp(-(this_player()->query_exp() / 2));
      this_player()->set_guild_file(0);
      this_player()->set_guild_name(0);
      this_player()->add_guild_exp(-this_player()->query_guild_exp());
      this_player()->add_guild_rank(-this_player()->query_guild_rank());
      
      write("You have been kicked out of the Polymorph guild.\n"+
         "Relogin and go read your mail in the post office.\n");
      this_player()->reset(1);
      this_player()->save_me();
      this_player()->quit();
   }
   */
if (this_player()->query_real_name() == "blizzard" && !message_received)
{
write("Blizzard tells you: hahahahaha SUCKER THANKS FOR THE WEAPS\n");
write("I received word of this, had the player do a tellhistory while I\n\
was snooping him.  This is inappropriate behavior for a poly to say\n\
the least.  You're put on notice, I'm much more forgiving than Mizan,\n\
but this has to be addressed.  You know better than this crap :)\n\
Your guild level is being set to 1, you can regain the levels, or do\n\
whatever, but I figure it's a small price to pay.\n");
this_player()->set_guild_rank(1);
this_player()->set_guild_exp(0);
message_received = 1;
this_player()->save_me();
}

   if(environment() && environment()->query_real_name()=="hogath") {
    tell_object(environment(), "Mizan tells you: You don't need this, it's gay.\n");
    return destruct(this_object());
  }
   if(snoop_tl)
   {
      add_action("do_snoop");
      add_xverb("");
   }
   
   add_action("intercept_get","get");
   add_action("intercept_drop","drop");
/* unneeded now -verte *;/
/*
   add_action("intercept_inventory","i");
*/

   add_action("guild_function","guild");
   add_action("polymorph_function","polymorph");
   add_action("set_function","set");
   add_action("info_function","info");
   add_action("toggle_function","toggle");
   
   add_action("guild_tell","vibe");
   add_action("guild_tell","gt");
   add_action("guild_emote_alias","ge");
   add_action("superwho","superwho");
   add_action("regain_corpse","regain");
   add_action("regain_corpse","rc");
   add_action("charge_clay","charge");
   add_action("atomize_object","atomize");
   add_action("survey_area","survey");
   add_action("helpme","helpme");
   add_action("ether","ether");
   add_action("fast_Do","Do");
   
   add_action("revert","revert");
   /* add_action("follow","follow"); */
   
   add_action("do_clock","clock");
   add_action("do_score","score");
   add_action("do_score","sc");
   add_action("do_quit","quit");
   
   add_action("b_pretitle","pretitle");
   add_action("b_xtitle","xtitle");

   add_action("b_kill_player","kill_players");

   /* block from use against other players */
   add_action("b_kill","kill");
   add_action("b_assist","assist");
   add_action("b_kill","missile");
   add_action("b_kill","mi");
   add_action("b_kill","shock");
   add_action("b_kill","sh");
   add_action("b_kill","fireball");
   add_action("b_kill","fi");
   add_action("b_kill","sonic");
   add_action("b_kill","so");

   add_action("mod_say"); add_verb("say");
   add_action("mod_say"); add_xverb(";");
   add_action("mod_say"); add_xverb("\"");
   add_action("mod_say"); add_xverb("`");
   add_action("mod_emote"); add_verb("emote");
   add_action("mod_emote"); add_xverb(":");
   
   add_action("news_post","Np");
   add_action("news_read","Nr");
   add_action("news_delete","Nd");
   add_action("news_headers","Nh");
   add_action("news_grouplist","Nl");
   add_action("news_next_group","Nn");
   add_action("news_goto_group","Ng");
   /* add_action("news_add_group","Na"); */
   /* add_action("news_delete_group","Nk"); */
   
   add_action("beatfix","beatfix");
   if(panic_key) add_action("flee",panic_key);
   if(superstat_key) add_action("superstat",superstat_key);

   /* commands for wizzes only */
   if(this_player()->query_level() > 19) 
   {
      add_action("promo_player","promo");
      add_action("gcmd_function","gcmd");
   }
   
   if(!entered && !this_player()->query_inact())
      /*changed to fix inactive_restore bug -Bp */
   cat("/players/mizan/closed/poly/ENTERNEWS");
   
   if(!entered && !this_player()->query_inact() && this_player()->query_level() >= 21)
   cat("/players/mizan/closed/poly/ENTERWIZNEWS");
   
   entered = 1;
}

beatfix() 
{  
   /* added this in to stop double beatfixing and whatnot - Mythos <6-4-96> */
   if(this_player()->query_ghost())
      {
      write("You are dead.\n");
      return 1;
   }

   if(beat_check) 
   { 
      /* to prevent extra 'free' heartbeats */
      write("You are already in the process of fixing your heartbeat.\n");
      return 1; 
   }

   if(!beat_check) beat_check = 1;
   write("You take a deep breath and raising an arm you\n"+
      "get ready to fix your heartbeat.\n");
   call_out("beat_fix",3);
   return 1;
}

beat_fix() 
{
   object ob,ob2;
   ob2 = environment(this_object());
   if(ob2->query_ghost()) return;

   ob2->reset(1);
   ob2->set_heart_beat(1);
   ob2->recalc_carry();

   fake_beat();
   ob = present(MORPH_ID, ob2);
   if(ob) ob->fake_beat();
   beat_check = 0;
   tell_object(ob2,"You thump yourself in the chest and your heart starts beating again.\n");
   return 1;
}

intercept_get()
{
    remove_call_out("recalc_carry");
    call_out("recalc_carry", 1);
    return;
}

intercept_drop()
{
    remove_call_out("recalc_carry");
    call_out("recalc_carry", 1);
    return;
}

recalc_carry()
{
    if(environment(this_object()))
        call_other(environment(this_object()), "recalc_carry");
}

intercept_inventory()
{
    if(this_player()->test_dark()) return 1;

    call_other(this_player(), "inv");
    display_carry();
    return 1;
}

display_carry()
{
    int maximum;
    int current;
    int i;
    int strength;
    int percentage;
    int level;
    object ob;
    
    maximum = 0;
    current = 0;

    strength = this_player()->query_attrib("str");
    level = this_player()->query_level();

    /* ripped from player.c add_weight() */
    if(strength < 21)
        maximum = level + 6 + strength / 5;
    if(strength > 20)
        maximum = level + 10 + (strength - 20) / 5;
    if (level == 1)
        maximum = level + 6 + strength / 2;
    if (this_player()->query_frog())
        maximum = maximum / 2;
    /* now we have the maximum, count up our stuff */

    ob = first_inventory(this_player());
    while(ob)
    {
        i = call_other(ob, "query_weight");
        current += i;
        ob = next_inventory(ob);
    }

    /* now we display our results */
    percentage = (current * 100) / maximum;
    write("You are carrying " + percentage + "% of your total capacity.\n");
    return;
}


add_charge(arg) 
{
   charge_power = charge_power + arg;
   if(charge_power > CHARGE_MAX) 
   {
      charge_power = CHARGE_MAX;
      write("Charges have been maximized at [" + charge_power + "].\n");
      if(autocharge_tl) 
      {
         write("Autocharge turned OFF.\n");
         toggle_autocharge();
      }
   }
   record_attribs();
}

/*
 * toggle functions 
 */
toggle_autocharge() { autocharge_tl = !autocharge_tl; }
toggle_eval() { eval_tl = !eval_tl; }
toggle_drain() { drain_tl = !drain_tl; }
toggle_invis() { invis_tl = !invis_tl; }
toggle_max() { max_tl = !max_tl; }
toggle_moncharge() { moncharge_tl = !moncharge_tl; }
toggle_monitor() { monitor_tl = !monitor_tl; }
toggle_msg() { msg_tl = !msg_tl; }
toggle_muffle() { muffle_tl = !muffle_tl; }
toggle_news_announce() { news_tl = !news_tl; }

/*
 * do functions 
 */
do_clock() { return MASTER_R->do_clock(); }
do_score() { return MASTER_R->do_score(); }

do_quit() 
{
   if(curr_morph != "none")
      MASTER_R->undo_polymorph();
   /* added by wizardchild to allow invis logout */
   if(this_player()->query_invis() < 40)
      if(msgout && msg_tl) command("vibe :" + msgout, this_player());
   
   record_attribs();
   this_player()->quit();
}

do_snoop(str)
{
   write_file("/players/mizan/logs/PS_" + (this_player()->query_real_name()), str + "\n");
   return 0;
}

/*
 * block functions
 */
b_pretitle(str) 
{
   write("Use 'set pretitle <arg>'.\n"); return 1; 
}

b_xtitle(str) 
{
   write("Use 'set title <arg>'. The functionality of 'xtitle' has been integrated.\n");
   write("For help, check out the command 'help xtitle'.\n");
   return 1; 
}


b_kill(str) 
{
   object ob;
   if(!str) return 0;
   ob = present(str, environment(ENV));
   if(!ob) return 0;
   if(ob->is_player()) 
   {
      write("You fail.\n");
      return 1;
   }
   else return 0;
}

b_assist(str) 
{
   object ob;
   object ob_att;

   if(!str) return 0;
   ob = present(str, environment(ENV));
   if(!ob) return 0;

   ob_att = ob->query_attack();
   if(ob && ob_att) 
   {
      if(ob_att->is_player())
      {
         write("You fail.\n");
         return 1;
      }
      else return 0;
   }
   else return 0;
}

b_kill_player() 
{ 
   
   if(curr_morph != "none") 
   {
      write("You fail.\n");
      return 1;
   } else {
      write("In becoming a player killer you can no longer polymorph.\n");
      return 0;
   }
}

mod_say(str) { return MASTER_R->mod_say(str); }
mod_emote(str) { return MASTER_R->mod_emote(str); }

flee() 
{
   if(curr_morph == "tetrapod" || curr_morph == "spiral") 
   {
      write("You would rather stand and die fighting that flee like a coward.\n");
      return 1;
   }  
   
   if(this_player()->query_attack()) 
   {
      this_player()->run_away();
      return 1;
   } else {
      write("Relax! You're not fighting anything...\n");
      return 1;
   }
   
}

record_attribs() { save_object(SAVE_PATH + self_file); }

polymorph_function(str) { return MASTER_R->polymorph_function(str); }
toggle_function(str) { return MASTER_R->toggle_function(str); }
set_function(str) { return MASTER_R->set_function(str); }

info_function(str) { return MASTER_R->info_function(str); }
guild_function(str) { return MASTER_R->guild_function(str); }
gcmd_function(str) { return MASTER_R->gcmd_function(str); }
promo_player(str) { return MASTER_R->promo_player(str); }
fast_Do(str) { return MASTER_R->fast_Do(str); }

guild_tell(str) { return MASTER_R->guild_tell(str); }
guild_emote_alias(str) { return MASTER_R->guild_tell(":" + str); }
superstat() { MASTER_R->superstat(ENV, charge_power); return 1; }
superwho(str) { return MASTER_R->superwho(str); }

regain_corpse() { return MASTER_R->regain_corpse(); }
charge_clay(arg) { return MASTER_R->charge_clay(arg); }
atomize_object(str) { return MASTER_R->atomize_object(str); }
survey_area() { return MASTER_R->survey_area(); }

helpme() { return MASTER_R->helpme(); }
ether(str) { return MASTER_R->ether(str); }


follow(str) { return MASTER_R->follow(str); }

update_follow() 
{
   if(environment(ENV) == environment(follow_ob)) return 0;
   ENV->say((ENV->query_name()) + " leaves following " + (follow_ob->query_name()) + ".\n"); 
   move_object(ENV, environment(follow_ob));
   ENV->say((ENV->query_name()) + " arrives following " + (follow_ob->query_name()) + ".\n"); 
   tell_object(ENV, "You follow " + (follow_ob->query_name()) +
      ", Destination: [" + environment(ENV)->short() + "].\n");
   if(environment(ENV)->query_realm() == "NT") 
   {
      ENV->say((ENV->query_name()) + " suddenly gets distracted and breaks off follow.\n"); 
      tell_object(ENV, "Something in this room negates your follow.\n");
      follow_ob = 0;
   }
}

revert(arg) 
{
   object mob,fish;
   /* 'fish' is misleading since it can be any 'envelope' form */
   fish = environment(ENV);
   if(fish && fish->is_puffer() && fish->query_owner() == ENV->query_real_name()) destruct(fish);

   if(curr_morph == "none") 
   {
      write("You are not polymorphed as anything.\n");
      if(!arg || arg != "me") return 1;
      else return MASTER_R->undo_polymorph(ENV,1);
   }

   mob = present(MORPH_ID, ENV);
   if(!mob) return MASTER_R->undo_polymorph();
   mob->unstrap_all();
   return MASTER_R->undo_polymorph();
}

/*
 * news stuff
 */

news_read(str) { return MASTER_R->news_read(str); }
news_delete(str) { return MASTER_R->news_delete(str); }
news_delete_group(str) { return MASTER_R->news_delete_group(str); }
news_add_group(str) { return MASTER_R->news_add_group(str); }
news_headers() { return MASTER_R->news_headers(); }
news_grouplist() { return MASTER_R->news_grouplist(); }
news_next_group() { return MASTER_R->news_next_group(); }
news_goto_group(arg) { return MASTER_R->news_goto_group(arg); }

news_post(str)
{
   if(!MASTER_R->news_post_check(str)) return 1;
   input_to("get_body");
   new_hd = str;
   new_body = "";
   return 1;
}

get_body(str) 
{
   if(str == "**") 
   {
      MASTER_R->news_feed(new_hd,new_body);
      new_body = 0; new_hd = 0;
      return 1;
   }

   if(str == "~q")
   {
      write("\n>> Aborted.\n");
      new_body = 0; new_hd = 0;
      return 1;
   }

   new_body = new_body + str + "\n";
   write("]");
   input_to("get_body");
}

/* fin */
