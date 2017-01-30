#include "/players/mizan/esc.h"
#include "definitions.h"

/*
 * PolymorphDM.c [Release 3.0 beta] Daemonized
 *
 * DO NOT CLONE THIS THING! It is meant to be loaded and accessed-
 * and that is IT! One big file that a whole bunch of smaller files
 * feed off from.
 *
 * Leave this header in here if you're going to use this code.
 * You can do whatever you want to improve it but i'd appreciate
 * improvement notices being mailed back to me.
 * Dont circulate off-nirvana. Mizan the wombat
 * Copyright Glue Spodware (c) 1997
 *
 */

id(str)
{
	/* this thing takes the meek id of a toaster */
	return str == "toaster";
}

short()
{
	/* Yup, a toaster. */
	return "A toaster"; 
}

long() 
{
   write("This is an ordinary looking toaster, but it seems to be busy,\n"+
      "doing the computational work of a desktop PC. It does not really want\n"+
      "to be bothered with.\n");
}

reset(arg) 
{
   /* move this object to its home */
   move_object(this_object(), HOME);

   /* load up the news */
   loadnews();

   if(!arg) 
   {
      /* init code here, to move some objects around */
      move_object(clone_object("/players/mizan/etheriel/environs/guild_sign"), HOME);
   }
}

init()
{
   if(this_player() &&
      living(this_player()) &&
      environment(this_player()) == this_object()) 
   {
      /* we dont like people inside the toaster. */
      write("The toaster drops you.\n");
      say("The toaster drops the " + (this_player()->query_name()) + ".\n");
      move_object(this_player(), HOME);
   }
}

/* ---- GUILD FUNCTIONS NOW --- */

/*
 * In an effort to keep the command set small, i put things in a drop-down
 * style. Most 'standard' guild functions are here.
 *
 */
guild_function(str) 
{
   string testo;

   if(!str || str == "escape") 
   {
      guild_escape();
      return 1;
   }
   
   else if(sscanf(str, "vibe %s", testo) == 1 ||
      sscanf(str, "tell %s", testo) == 1) 
   {
      guild_tell(testo);
      return 1;
   }

   else if(str == "who")
   { 
      guild_fancy_who();
      return 1; 
   }
   
   else if(str == "who /n") 
   {
      guild_fancy_who("/n"); 
      return 1; 
   }
   
   else if(str == "who /d")
   {
      guild_fancy_who("/d");
      return 1; 
   }

   else if(str == "help") 
   {
      info_function("guild");
      return 1;
   }
   
   else if(str == "fix") 
   {
      guild_fix();
      return 1;
   }
   
   else if(str == "save") 
   {
      /* save our stats, and guild stats too */
      object ob;
      ob = present(GUILD_ID, this_player());
      
      if(!ob) return 0;
      if(ob->query_current_morph() != "none") 
      {
         write("You must not be polymorphed to do this.\n");
         return 1;
      }

      ob->record_attribs();
      this_player()->save_me();
      write("Character and guild stats saved.\n");
      return 1;
   }

   else if(str == "motd")
   {
      cat(MOTD);
      return 1;
   }

   else if(str == "version")
   {
      write(CURRENT_VERSION + "\n");
      write(CURRENT_VERSION_BUILD + "\n");
      write(CURRENT_VERSION_DATE + "\n");
      return 1;
   }
   
   else if(str == "devstuff")
   {
/*
      call_other("/closed/wiz_soul", "more", DEVSTUFF);
 */
      cat(DEVSTUFF);
      return 1;
   }

   else if(str == "credits")
   {
/*
      call_other("/closed/wiz_soul", "more", CREDITS);
*/
      cat(CREDITS);
      return 1;
   }

   else if(str == "RETIRE!") 
   {
      if(check_dead()) return 1;
      guild_deduct_stats();
      return 1;
   }
   
   else if(sscanf(str, "banish %s", testo) == 1) 
   {
      if(check_dead()) return 1;
      if(!check_level(GC)) return 1;
      guild_deduct_stats(testo);
      return 1;
   }

   else if(str == "upgrade")
   {
      if(check_dead()) return 1;
   
      write("Done! You have converted your stats to the new guild object's\n"+
         "format.\n");
      write("Alas, I have pulled a Microsoft [tm] by making some of\n");
      write("the variables incompatible during the upgrade path.\n");
      write("Be sure to check that all your sets and toggles are\n"+
         "reconfigured okay on next login.\n");

      this_player()->set_guild_file("/players/mizan/closed/poly/core/gob.c");
      command("quit", this_player());
      return 1;
   }

   return 0;
}

/**
 * The guild channel. 
 * I made it mimic the standard game channels in functionality.
 *
 */
guild_tell(str) 
{
   object ob,gob;
   string temp,temp2,temp3,temp4;
   int v;

   if(!str) 
   {
      write("You must give a message.\n");
      return 1;
   }

   gob = present(GUILD_ID, this_player());
   if(!gob)
   {
      /* no gob, no service */
      return 0;
   }
   
   if(str == "list") 
   {
      /* lists people in a string, like channel gossip. */
      guild_tell_people();
      return 1;
   }

   if(str == "muffle") 
   {
      toggle_function("muffle");
      return 1;
   }

   if(this_player()->query_ghost())
      temp2 = "ghost";
   else temp2 = gob->query_morph_comm();

   if(!temp2) 
   {
      temp2 = "vibe";
      if(sscanf(str, "%s?", temp3) == 1) temp2 = "wonder";
      else if(sscanf(str, "%s??", temp3) == 1) temp2 = "boggle";
      else if(sscanf(str, "%s??%s", temp3, temp4) == 2) temp2 = "interrogate";
      
      else if(sscanf(str, "%s!!", temp3) == 1) temp2 = "yell";
      else if(sscanf(str, "%s!!%s", temp3, temp4) == 2) temp2 = "thunder";
   }
   
   if(gob->query_muffle()) 
   {
      /* override muffle when a chat command is issued */
      write("You were muffled! Muffle overridden.\n");
      gob->toggle_muffle();
   }
   
   if(sscanf(str, ":%s", temp) == 1) 
   {
      if(this_player()->query_invis() > 38)
         temp = ">> (" + temp2 + ")" + ESC + "[0m Someone " + temp + "\n";
      else temp = ">> (" + temp2 + ")" + ESC + "[0m " +
         capitalize(this_player()->query_real_name()) + " " + temp + "\n";
   } else {
      if(this_player()->query_invis() > 38) temp = ">> Someone " + temp2 + "s:" + ESC + "[0m " + str + "\n";
      else temp = ">> " + capitalize(this_player()->query_real_name()) + " " + temp2 + "s:" + ESC + "[0m " + str + "\n";
   }
   temp = format(temp, 70);
   
   ob = users();
   guild_echo(ESC + "[1m" + ESC + "[34m" + temp);
   return 1;
}

/** 
 * This function lists who is on the guild channel, standard game
 * lib style.
 *
 */
guild_tell_people() 
{
   object ob;
   string temp,a,b;
   int v;
   ob=users();
   
   temp = " ";
   for(v=0; v<sizeof(ob); v++) 
   {
      object oc;
      oc=present(GUILD_ID, ob[v]);
      if(oc && !oc->query_muffle()) 
      {
         if(!ob[v]->query_invis() || ob[v]->query_invis() < 19)
            temp = temp + capitalize(ob[v]->query_real_name()) + ", ";
      }
   }
   temp = "Players currently on the vibe channel:" + temp;
   temp = format(temp, 70);
   write(temp + "\n");
   return 1;
}

/* ---- i should make this static --- */

guild_echo(str) 
{
   object ob;
   int v;
   ob = users();
   for(v = 0; v < sizeof(ob); v++) 
   {
      object oc;
      string od;
      oc = present(GUILD_ID, ob[v]);

      if(oc && oc->query_original() &&
         !oc->query_muffle()) 
      {
         tell_object(ob[v], str);
      }
   }
}


/*
 * used to fix the guild object, trashes old one 
 */
guild_fix() 
{
   object ock,odk,oek;
   string temp;

   if(check_dead()) return 1;
   ock = present(GUILD_ID, this_player());

   if(ock) 
   {
      odk = present(MORPH_ID, this_player()); 
      if(odk) 
      {
         /* Forces return from polymorph during save */
         odk->unstrap_all();
         undo_polymorph();
      }

      write("Old object destructed.\n");
      oek = clone_object(GUILDFILE);
      move_object(oek, this_player());
      oek->add_charge(ock->query_charge());
      oek->fake_beat();
      
      destruct(ock);
      write("Done.\n");
      this_player()->reset(1);
      do_score();
      
   }
   return 1;
}

/**
 * The only guild 'teleport' allowed, and it only works in /room and jello
 * areas.
 */
guild_escape() 
{
   object room;
   string desta,test;
   if(check_dead()) return 1;
   
   if(this_player()->query_attack())
   {
      write("You are too busy fighting to do this.\n");
      return 1;
   }
   
   if(!check_sp(ESCAPE_COST)) return 1;
   
   room = environment(this_player());
   
   /* already home? hah! */
   if(room == environment(this_object())) 
   {
      write("A toaster pokes you in the ribs.\n");
      return 1;
   }
   desta = creator(room);
   
   if(!desta || sscanf(file_name(room), "/room%s", test) == 1) 
   {
      /* this is a backbone room */
      write("You fade into the environment and arrive in the guild room!\n\n");
      remote_say((this_player()->query_name()) + " fades from view.\n");
      move_object(this_player(), HOME);
      remote_say((this_player()->query_name()) + " drifts into view.\n");
      this_player()->add_spell_point(-ESCAPE_COST);
      this_player()->look();
      return 1;
   }
   else if(desta == "mizan" && 
      sscanf(room->short(), "Plane of Etherie%s", test) == 1) 
   {
      /* else we are in the jello */
      if(environment(this_player())->realm() != "NT" && 1 == random(8)) 
      {
         /* chance of failure */
         write("The ether-muck is a bit too thick here.\n");
         return 1;
      }

      write("You fade into the environment, a swirling flotsam and jetsam\n"+
         "of utter chaos, and arrive somewhere else.\n\n");
      remote_say((this_player()->query_name()) + " suddenly turns transparent and drifts away.\n");
      move_object(this_player(), HOME);
      remote_say((this_player()->query_name()) + " drifts into view.\n");
      
      this_player()->look();
      return 1;
   }
   
   write("You are too far out of range. It would not be safe to try this.\n");
   return 1;
}

/*
 * This is called when a player is banished from the guild, or if a player
 * leaves the guild voluntarily.
 */
guild_deduct_stats(str,arg) 
{
   object thingy,victim;
   string temp;

   if(!str) victim = this_player();
   else victim = find_player(str);
   
   if(!victim) 
   {
      write("That player is not currently logged in.\n");
      return 1;
   }
   
   if(victim->query_ghost()) 
   {
      write("That player is dead.\n");
      return 1;
   }
   
   if(victim->query_guild_name() != GUILDNAME) 
   {
      write("That player is not a member of the guild.\n");
      return 1;
   }
   
   if(victim->query_real_name() == "mizan") 
   {
      write("Funny.\n");
      return 1;
   }
   
   thingy = present(GUILD_ID, victim);
   if(!thingy) return 0;

   /* what is this for? I forgot. */
   if(thingy->qh() != "none")
      undo_polymorph(victim);
   
   if(arg) 
   {
      /* message out that player has been banished. */
      if(this_player()->query_invis() > 38)
      {
         /* as much as i dont want to do it, the identity of the invis wizard
          * must not be compromised.
          */
         temp = ">> (vibe)" + ESC + "[0m Someone (L" + 
         this_player()->query_level() + ") ";
      }
      else
      {
         temp = ">> (vibe)" + ESC + "[0m " +
         capitalize(this_player()->query_real_name()) + " ";
      }
      temp += "has banished " + victim->query_name() + " from the guild!\n";

      guild_echo(ESC + "[1m" + ESC + "[34m" + temp);

      /* do the dirty work here */
      thingy->set_current_morph("[BANISHED]");

      /* now log the action */
      write_file(LOGPATH + "POLY_BANISH",
         (this_player()->query_real_name()) + " banished " +
         str + " from the guild on " + ctime() + "\n");
   }
   else 
   {
      /* message out that player has left. */
      if(this_player()->query_invis() > 38)
      {
         temp = ">> (vibe)" + ESC + "[0m Someone (L" + 
         this_player()->query_level() + ") ";
      }
      else
      {
         temp = ">> (vibe)" + ESC + "[0m " +
         capitalize(this_player()->query_real_name()) + " ";
      }
      temp += "has left the guild!\n";

      guild_echo(ESC + "[1m" + ESC + "[34m" + temp);

      thingy->set_current_morph("[LEFT]");
      
      /* now log the action */
      write_file(LOGPATH + "POLY_RETIRE",
         (this_player()->query_real_name()) + " left the guild on " + ctime() + "\n");
   }

   thingy->record_attribs();
   destruct(thingy);    
   victim->set_guild_name(0);
   victim->set_guild_file(0);
   if(victim->query_exp()) victim->add_exp(-(victim->query_exp() / 3));
   victim->add_guild_exp(-victim->query_guild_exp());
   victim->add_guild_rank(-(victim->query_guild_rank()));
   
   call_other("room/adv_guild", "correct_level", victim);
   call_other("room/exlv_guild", "correct_extra_level", victim);
   victim->reset(1);
   victim->save_me();
   
   tell_object(victim,
      "Player stats recomputed.\n"+
      "You lose 1/3 of your current experience.\n"+
      "Guild name and files have been reset to zero.\n"+
      "If you wish to rejoin you must mail Mizan.\n"+
      "Good luck.\n");
   return 1;
}

/* ---- just what it does- guild fancy who
long and bulky... i know... shut up  --- */

guild_fancy_who(str) 
{
   object ob,oc;
   int v;
   ob = users();

   /* header */
   write("\n>>Polymorphs:-----------------------------------------------------------<<\n");
   write("Name\t\tLev GLev Sex Morph\t");
   if(str == "/n") write("Nickname\n");
   else if(str == "/d") write("Doing...\n");
   else write("Current location\n");
   
   /* main loop */
   for(v=0; v<sizeof(ob); v++) 
   {
      string tempr,temps;
      int lv,glv;
      tempr="";
      oc=present(GUILD_ID, ob[v]);
      
      /* query_original checks against bogus objects claiming id() */
      if(oc && oc->query_original() &&
         environment(ob[v]) && 
         ob[v]->query_invis() < 20) 
      {
         /* print the flags */
         if(query_idle(ob[v]) >= 5 * 60) tempr = tempr + "=";
         if(in_editor(ob[v])) tempr = tempr + "*";
         if(oc->query_muffle()) tempr = tempr + "!";
         
         /* now the name */
         tempr = tempr + capitalize(ob[v]->query_name()) + "\t";
         if(strlen(tempr) < 9) tempr = tempr + "\t";
         
         /* levels, guild and regular */
         lv = ob[v]->query_level();
         glv = ob[v]->query_guild_rank();
         
         if(lv < 10) tempr = tempr + "  " + lv + "  ";
         else if(lv > 9 && lv < 20) tempr = tempr + " " + lv + "  ";
         else if(lv > 19) tempr = tempr + "Wiz  ";
         
         if(glv < 10) tempr += " ";
         if(glv < GC) tempr += (" " + glv + "  ");
         else if(glv == GC) tempr += " GC  ";
         else if(glv > GC) 
         {
            if(ob[v]->query_real_name() == "mizan") tempr = tempr + "Moo  ";
            else if(ob[v]->query_real_name() == "bastion") tempr = tempr + "Eep ";
            else if(ob[v]->query_real_name() == "wizardchild") tempr = tempr + "Log  ";
            else tempr = tempr + "Wiz  ";
         }
         
         /* gender */
         tempr = tempr + capitalize(extract((ob[v]->query_gender()), 0, 0)) + "   ";
         
         /* current morph */
         if(!oc->query_current_morph()) tempr = tempr + "none\t";
         else
         {
            temps = oc->query_current_morph();
            if(strlen(temps) > 7) 
               tempr = tempr + extract(temps, 0, 6) + ".\t";
            else tempr = tempr + temps + "\t";
         }
         
         /* process the last option */
         if(str == "/n") temps = oc->query_nickname();
         else if(str == "/d") temps = oc->query_doing();
         else temps = (environment(ob[v]))->short();
         
         if(temps && strlen(temps) > 34) tempr = tempr + extract(temps, 0, 34) + ".\n";
         else tempr = tempr + temps + "\n";
       }
      
      write(tempr);
   }
   write("\n>>-Prefixes: '*' is wizard editing, '=' is idle, '!' is channel muffle  <<\n");
   write(">>----------------------------------------------------------------------<<\n");
   return 1;
}

/* ---- POLYMORPH FUNCTIONS NOW --- */

polymorph_function(str) 
{
   object gob,ob;
   gob = present(GUILD_ID, this_player());

   /* no gob no service */
   if(!gob) return 0;
   if(check_dead()) return 1;
   if(this_player()->query_pregnancy()) 
   {
      write("You cannot polymorph because you would kill your unborn child!\n");
      return 1;
   }
   
   if(!str) 
   {
      if(gob->query_current_morph() == "none") 
      {
         write("You are not currently polymorphed as anything.\n");
         return 1;
      }
      write("You are currently polymorphed as a " + (gob->query_current_morph()) + ".\n");
      return 1;
   }
   if(str == "help" || str == "info") 
   {
      info_function("polymorph");
      return 1;
   }
   
   /* cannot do if already morphed */
   if(gob->query_current_morph() != "none") 
   {
      write("You are already polymorphed as a " + 
         (gob->query_current_morph()) + "!\n");
      return 1;
   }
   
   /* cannot be fighting */
   if(this_player()->query_attack()) 
   {
      write("You are too busy fighting to concentrate.\n");
      return 1;
   }
   
   /* must be visible */
   if(this_player()->query_level() < 20 &&
      this_player()->query_invis()) 
   {
      write("You must be visible to polymorph into things.\n");
      return 1;
   }
   
   /* just insurance */
   record_stats();
   
   /* BIG NASTY IF-ELSE THING */

   /* L1 forms */   
   if(str == "spuckball")
      return polymorph_spuckball();
   else if(str == "puffer" || str == "pufferfish")
      return polymorph_pufferfish();
   else if(str == "wombat") 
      return polymorph_wombat();
 
   /* L2 forms */
   else if(str == "golem") 
      return polymorph_golem();
   else if(str == "tree") 
      return polymorph_tree();
   else if(str == "catapult")
      return polymorph_catapult();
   else if(str == "kwijibo")
      return polymorph_kwijibo();
   else if(str == "armor")
      return polymorph_armor();
   else if(str == "weapon")
      return polymorph_weapon();
   else if(str == "loafy" || str == "slow dog")
      return polymorph_loafy();
   
   /* L3 forms */  
   else if(str == "fungoid")
      return polymorph_fungoid();
   else if(str == "sponge") 
      return polymorph_sponge();
   else if(str == "blobel")
       return polymorph_blobel();
   else if(str == "treehouse")
      return polymorph_treehouse();

   /* L4 forms */
   else if(str == "puffball") 
      return polymorph_puffball();
   else if(str == "replicant") 
      return polymorph_replicant();
   else if(str == "shoutbox")
      return polymorph_shoutbox();
   else if(str == "wumpus")
      return polymorph_wumpus();
   else if(str == "slug" || str == "jungle slug")
      return polymorph_jungle_slug();
   
   /* L5 forms */  
   else if(str == "tetrapod") 
      return polymorph_tetrapod();
   else if(str == "bogglemancer")
      return polymorph_bogglemancer();
   else if(str == "spucktrooper")
      return polymorph_spucktrooper();
   else if(str == "mimic")
      return polymorph_mimic();
   else if(str == "cow")
      return polymorph_cow();
   
   /* L6 forms */
   else if(str == "fygar")
      return polymorph_fygar();
   else if(str == "spiral")
      return polymorph_spiral();
   else if(str == "volcano")
      return polymorph_volcano();
   else if(str == "gambler")
      return polymorph_gambler();
   else if(str == "toasteroven" || str == "toaster")
      return polymorph_toaster();
   
   /* L7 forms */
   else if(str == "dopple" || str == "doppleganger")
      return polymorph_doppleganger();
   else if(str == "spuckball howitzer" || str == "howitzer")
      return polymorph_spuck_hw();
   else if(str == "totoro")
      return polymorph_totoro();

   /* L8 forms */
   else if(str == "dragon")
      return polymorph_dragon();

   /* L9 forms */
   else if(str == "octopus")
      return polymorph_octopus();

   /* L10 forms */
   else if(str == "dark tetrapod")
      return polymorph_dark_tetrapod();
   else if(str == "mammoth" || str == "wooly mammoth")
      return polymorph_mammoth();
   
   /* L11 forms */
   else if(str == "spuckball tank destroyer" || str == "spuckball td")
      return polymorph_spuck_td();

   /* L12 forms */
   else if(str == "snowman")
      return polymorph_snowman();
   else if(str == "spam" || str == "spam loaf")
      return polymorph_spam_loaf();
   
   /* L13 forms */
   else if(str == "samurai")
      return polymorph_samurai();
   else if(str == "necromonger")
      return polymorph_necromonger();
   else if(str == "deathbeano")
      return polymorph_deathbeano();
   else if(str == "bjork")
      return polymorph_bjork();
   
   /* L14 forms */
   else if(str == "metaball")
      return polymorph_metaball();
   else if(str == "plague")
      return polymorph_plaque();
   else if(str == "chicken" || str == "kungfu chicken")
      return polymorph_kungfu_chicken();
   else if(str == "juggernaut")
      return polymorph_juggernaut();
   else if(str == "hydra")
      return polymorph_hydra();
   
   /* L15 forms */
   else if(str == "cloudkill")
      return polymorph_cloudkill();
   else if(str == "spuckball chaingun" || str == "chaingun")
      return polymorph_spuck_cg();
   else if(str == "barney")
      return polymorph_barney();
   else if(str == "spuckball cruiser" || str == "cruiser")
      return polymorph_spuck_crs();
   else if(str == "high tetrapod")
      return polymorph_high_tetrapod();
   else if(str == "dynamine")
      return polymorph_dynamine();
  
   /* end morphing routines */
   
   else if(str == "list")
      return polymorph_listforms();

   write("That is not one of the polymorph forms you know.\n");
   return 1;
}

/**
 * This function lists all of the poly forms available.
 *
 */
polymorph_listforms()
{
/*
   call_other("/closed/wiz_soul", "more", HELPDIR + POLYLIST);
 */
   cat(HELPDIR + POLYLIST);
   return 1;
}

/* POLYMORPH SPUCKBALL [1] */
polymorph_spuckball()
{
   do_polymorph(1,POLY_SPUCKBALL_COST,"wobble",POLY_SPUCKBALL_STAT,
      "You implode and shape yourself to the form of a Spuckball.\n"+
      "Everything suddenly turns a bit blurrier and sloshy, but within\n"+
      "a few moments your new form adjusts to the environment.\n");
   return 1;
}

/* POLYMORPH WOMBAT [1] */
polymorph_wombat()
{
   do_polymorph(1,POLY_WOMBAT_COST,"bleat",POLY_WOMBAT_STAT,
      "You absorb the energy within the clay's matrix and\n"+
      
      "new power courses through your new form as a wombat\n\n" +
      "You suddenly get the urge to dig holes and graze.\n");
   unready_items("armor",0);
   return 1;
}

/* POLYMORPH PUFFERFISH [1] */
polymorph_pufferfish()
{
   object uh,fish;
   uh = present(GUILD_ID, this_player());
   if(!uh) return 0;
   if(uh->query_charge() < POLY_PUFFERFISH_COST) 
   {
      write("You are too drained to do this.\n");
      return 1;
   }
   do_polymorph(1,POLY_PUFFERFISH_COST,"bubble",POLY_PUFFERFISH_STAT,
      "You take a deep breath and assume the meek form of a pufferfish.\n");
   fish = clone_object(POLY_PUFFERFISH_FORM);
   fish->set_owner(this_player()->query_real_name());
   move_object(fish, environment(this_player()));
   return 1;
}

/* POLYMORPH ARMOR [2] */
polymorph_armor()
{
   do_polymorph(2,POLY_ARMOR_COST,"mumble",POLY_ARMOR_STAT,
      "You furrow your brow, and *Pop!* you assume the shape of wearable armor.\n");
   return 1;
}

/* POLYMORPH WEAPON [2] */
polymorph_weapon()
{
   do_polymorph(2, POLY_WEAPON_COST,"beat",POLY_WEAPON_STAT,
      "Struggling somewhat, you shape yourself to the form of a usable weapon.\n");
   return 1;
}

/* POLYMORPH GOLEM [2] */
polymorph_golem()
{
   do_polymorph(2,POLY_GOLEM_COST,"rumble",POLY_GOLEM_STAT,
      "You expand and shape yourself to the form of a golem.\n");
   return 1;
}

/* POLYMORPH TREE [2] */
polymorph_tree()
{
   do_polymorph(2,POLY_TREE_COST,"bark",POLY_TREE_STAT,
      "Everything suddenly goes stiff...\n");
   unready_items("armor","weapons");
   return 1;
}

/* POLYMORPH CATAPULT [2] */
polymorph_catapult()
{
   object uh, pult;
   uh = present(GUILD_ID, this_player());

   if(!uh) return 0;
   if(uh->query_charge() < POLY_CATAPULT_COST) 
   {
      write("You are too drained to do this.\n");
      return 1;
   }

   do_polymorph(2,POLY_CATAPULT_COST,"hurl",POLY_CATAPULT_STAT,
      "With great effort, you shape yourself to the form of an\n"+
      "Acme Siege Catapult!\n");
      unready_items("armor","weapons");

   pult = clone_object(POLY_CATAPULT_FORM);
   pult->set_owner(this_player()->query_real_name());
   move_object(pult, environment(this_player()));
   return 1;
}

/* POLYMORPH LOAFY [2] */
polymorph_loafy()
{
   do_polymorph(2,POLY_LOAFY_COST,"mumble",POLY_LOAFY_STAT,
      "Woof. Everything turns slow and lazy as you take the form of\n"+
      "the incredibly immobile Loafy the Dog.\n");
   return 1;
}

/* POLYMORPH KWIJIBO [2] */
polymorph_kwijibo()
{
   do_polymorph(2,POLY_KWIJIBO_COST,"doh",POLY_KWIJIBO_STAT,
      "You lard out and take the lumbering shape of a kwijibo.\n"+
      "for some reason you have the urge to consume pork rinds, watch\n"+
      "television, and say 'Doh!'\n");
   return 1;
}

/* POLYMORPH FUNGOID [3] */
polymorph_fungoid()
{
   do_polymorph(3,POLY_FUNGOID_COST,"spore",POLY_FUNGOID_STAT,
     "You concentrate and shape yourself to the form of a fungoid.\n");
   return 1;
}

/* POLYMORPH SPONGE [3] */
polymorph_sponge()
{
   do_polymorph(3,POLY_SPONGE_COST,"foam",POLY_SPONGE_STAT,
      "You expand and shape yourself to the form of a sponge.\n");
   unready_items("armor","weapons");
   return 1;
}  

/* POLYMORPH SPR (Blobel) [3] */
polymorph_blobel()
{
   do_polymorph(3,POLY_SPR_COST,"blurble",POLY_SPR_STAT,
      "You concentrate intensely and shape yourself to the form of a blobel.\n");
   return 1;
}

/* POLYMORPH TREEHOUSE [3] */
polymorph_treehouse()
{
   do_polymorph(3,POLY_TREEHOUSE_COST,"club",POLY_TREEHOUSE_STAT,
      "Branches stem out of your head, and you take the shape of a treehouse.\n");
   return 1;
}
 
/* POLYMORPH PUFFBALL [4] */
polymorph_puffball()
{
   do_polymorph(4,POLY_PUFFBALL_COST,"puff",POLY_PUFFBALL_STAT,
         "You absorb the energy within the clay's matrix and\n"+
         "new power courses through your new form as a puffball.\n");
   unready_items("armor",0);
   return 1;
}
   
/* POLYMORPH REPLICANT [4] */
polymorph_replicant()
{
   do_polymorph(4,POLY_REPLICANT_COST,"vibe",POLY_REPLICANT_STAT,
      "You absorb the energy within the clay's matrix and\n"+
      "new power courses through you as you suddenly feel stronger...\n"+
      "faster... better... but your appearances are all the same.\n");
   return 1;
}

/* POLYMORPH SHOUTBOX [4] */
polymorph_shoutbox()
{
   do_polymorph(4,POLY_SHOUTBOX_COST,"bellow",POLY_SHOUTBOX_STAT,
      "You concentrate intensely and shape yourself to the form of a shoutbox.\n"+
      "Your mouth expands to gaping proportions, your lungs and chest expand\n"+
      "just the same. You feel bloody right dangerous, and like yelling\n"+
      "at someone.\n");
   unready_items("armor",0);
   
   return 1;
}

/* POLYMORPH WUMPUS [4] */
polymorph_wumpus()
{
   do_polymorph(4,POLY_WUMPUS_COST,"nog",POLY_WUMPUS_STAT,
     "Hroooof! You concentrate abend to the shape of the fearsome Wumpus!\n"+
     "Stay away from mazes though, you hear?\n");
   return 1;
}

/* POLYMORPH JUNGLE SLUG [4] */
polymorph_jungle_slug()
{
   do_polymorph(4,POLY_JUNGLE_SLUG_COST,"gop",POLY_JUNGLE_SLUG_STAT,
      "Mucus and other icky substances start to sweat from every part\n"+
      "of your body, as it turns soft and gooey. You are not the fearsome\n"+
      "jungle slug of the primeval Oomfoofa jungle!\n");
   return 1;
}

/* POLYMORPH BOG (Bogglemancer) [5] */
polymorph_bogglemancer()
{
   do_polymorph(5,POLY_BOG_COST,"gribble",POLY_BOG_STAT,
      "You absorb the energy within the clay's matrix and\n"+
      "reciting the Principles of Painless distraction, you suddenly drift\n"+
      "into a state of thoughtless awareness, and your new form.\n");
   return 1;
}

/* POLYMORPH TETRAPOD [5] */
polymorph_tetrapod()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(5,POLY_TETRAPOD_COST,"growl",POLY_TETRAPOD_STAT,
      "You concentrate and assume the polymorph of a tetrapod.\n"+
      "New arms pop out from nowhere but after a bit of confusion, and\n"+
      "much scratching and waving, everything feels okay.\n");
   return 1;
}

/* POLYMORPH MIMIC [5] */
polymorph_mimic()
{
   do_polymorph(5,POLY_MIMIC_COST,"mime",POLY_MIMIC_STAT,
      "You assume the shapeless mass of a generic creature.\n"+
      "Make sure you assume the form of something else by 'mimic <name>'.\n");
      unready_items("armor","weapons");
   return 1;
}

/* POLYMORPH SPUCKTROOPER [5] */
polymorph_spucktrooper()
{
   do_polymorph(5,POLY_SPUCKTROOPER_COST,"grobble",POLY_SPUCKTROOPER_STAT,
      "You implode and shape yourself to the form of a Spucktrooper.\n"+
      "Everything suddenly turns a bit blurrier and sloshy, but within\n"+
      "a few moments your new form adjusts to the environment.\n");
   return 1;
}

/* POLYMORPH COW [5] */
polymorph_cow()
{
   do_polymorph(5,POLY_COW_COST,"moo",POLY_COW_STAT,
      "You take the form of the enviable bovine provider of milk,\n"+
      "the awesome cow!\n");
   return 1;
}

/* POLYMORPH FYGAR [6] */
polymorph_fygar()
{
   do_polymorph(6,POLY_FYGAR_COST,"blurt",POLY_FYGAR_STAT,
      "You inflate yourself to assume the shape of Fygar the Dragon,\n"+
      "the happy beast of Dig-Dug.\n");
   return 1;
}

/* POLYMORPH GAMBLER [6] */
polymorph_gambler()
{
   do_polymorph(6,POLY_GAMBLER_COST,"dice",POLY_GAMBLER_STAT,
      "You take a gamble, rolling yourself into a random attribute form.\n");
   return 1;
}

/* POLYMORPH SPIRAL [6] */
polymorph_spiral()
{
   object gob,ob;
   gob = present(GUILD_ID, this_player());

   /* femme-only form */
   if(this_player()->query_gender() != "female") 
   {
      write("What? You can't assume this polymorph!\n(And castration is not fun).\n");
      return 1;
   }
   
   if(!check_wimpyoff()) return 1;
   
   do_polymorph(15,POLY_SPIRAL_COST,"mutter",POLY_SPIRAL_STAT,
      "You concentrate and assume the polymorph likeness of Spiral.\n"+
      "New arms pop out from nowhere but after a bit of confusion, and\n"+
      "much scratching and waving, everything feels fluid and natural.\n");
   unready_items("armor",0);
   return 1;
}

/* POLYMORPH VOLCANO [6] */
polymorph_volcano()
{
   do_polymorph(6,POLY_VOLCANO_COST,"erupt",POLY_VOLCANO_STAT,
      "You concentrate deeply and take the shape of a volcano\n"+
      "Complete with a direct pipeline to hot molten magma, the pathway\n"+
      "to hell, and all that other neat jazz.\n");
      unready_items("armor","weapons");
   return 1;
}

/* POLYMORPH DOPPLEGANGER [6] */
polymorph_doppleganger()
{
   do_polymorph(6,POLY_DOPPLEGANGER_COST,"blurt",POLY_DOPPLEGANGER_STAT,
      "Contortionist extraordinare! Facing grim consequences, you assume\n"+
      "the form of of the multifaceted doppleganger.\n");
   return 1;
}

/* POLYMORPH TOASTER [6] */
polymorph_toaster()
{
   do_polymorph(6,POLY_TOASTER_COST,"toast",POLY_TOASTER_STAT,
      "Roor! You assume the form of the almighty cordless toaster oven!\n");
   return 1;
}

/* POLYMORPH SPUCKBALL HOWITZER [7] */
polymorph_spuck_hw()
{
   do_polymorph(7,POLY_SPUCK_HW_COST,"fire",POLY_SPUCK_HW_STAT,
      "You wince as what was your body turns into a huge gun with\n"+
      "a barrel so wide people can fit their heads into it.\n"+
      "Hey now, not only are you a big gun but you know how to use it too.\n");
   return 1;
}

/* POLYMORPH TOTORO [7] */
polymorph_totoro()
{
   do_polymorph(7,POLY_TOTORO_COST,"mumble",POLY_TOTORO_STAT,
      "Taking the form of a large, squishy, furry japanese troll,\n"+
      "you don't feel like pounding anyone's head in or spilling\n"+
      "ludicrous amounts of blood, but rather like sniffing the flowers.\n"+
      "Roor!\n");
   return 1;
}

/* POLYMORPH DRAGON [8] */
polymorph_dragon()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(8,POLY_DRAGON_COST,"thunders",POLY_DRAGON_STAT,
      "Scaly armor, internal furnace, and built-in meat grinder claws.\n"+
      "Its fun to be a dragon but hard to fit into phone booths.\n");
   return 1;
}

/* POLYMORPH OCTOPUS [9] */
polymorph_octopus()
{
   do_polymorph(9,POLY_OCTOPUS_COST,"squid",POLY_OCTOPUS_STAT,
      "Things get wacky for a moment as eight limbs are whipping\n"+
      "around, but in a moment you're so happy, because you'll never\n"+
      "need a backscratcher or a pair of clamps as an octopus.\n");
   return 1;
}

/* POLYMORPH DARK TETRAPOD [10] */
polymorph_dark_tetrapod()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(10,POLY_DARK_TETRAPOD_COST,"growl",POLY_DARK_TETRAPOD_STAT,
      "You concentrate and assume the polymorph of a dark tetrapod.\n"+
      "New arms pop out from nowhere but after a bit of confusion, and\n"+
      "much scratching and waving, everything feels okay.\n"+
      "You have a powerful urge now to beat the living crap out of something.\n");
   return 1;
      
}

/* POLYMORPH WOOLY MAMMOTH [10] */
polymorph_mammoth()
{
   do_polymorph(10,POLY_MAMMOTH_COST,"trumpet",POLY_MAMMOTH_STAT,
      "Fur grows thickly about your body as you expand and take the shape\n"+
      "of a large wooly mammoth!\n");
   return 1;
}


/* POLYMORPH SPUCK TANK DESTROYER [11] */
polymorph_spuck_td()
{
   object uh, pult;
   uh = present(GUILD_ID, this_player());
   if(!uh) return 0;
   if(uh->query_charge() < POLY_SPUCK_TD_COST) 
   {
      write("You are too drained to do this.\n");
      return 1;
   }

   do_polymorph(11, POLY_SPUCK_TD_COST,"spod",POLY_SPUCK_TD_STAT,
      "Superhuman effort is required but you shape yourself to the form of\n"+
      "a Spuckball Tank Destroyer.\n");
      unready_items("armor","weapons");

   pult = clone_object(POLY_SPUCK_TD_FORM);
   pult->set_owner(this_player()->query_real_name());
   move_object(pult, environment(this_player()));
   return 1;
}

/* POLYMORPH SNOWMAN [12] */
polymorph_snowman()
{
   do_polymorph(12,POLY_SNOWMAN_COST,"flake",POLY_SNOWMAN_STAT,
      "Frosty had the right idea, being a snowman.\n"+
      "You shiver a bit as you turn into one, but quickly become\n"+
      "acclimated to it. Whether or not someone gets acclimated\n"+
      "to having their lips freeze when they kiss you is another story.\n");
   return 1;
}

/* POLYMORPH SPAM LOAF [12] */
polymorph_spam_loaf()
{
   do_polymorph(12,POLY_SPAM_LOAF_COST,"spam",POLY_SPAM_LOAF_STAT,
     "It took great effort, but you form yourself into a living,\n"+
     "breathing, moist, smelly, and walking loaf of Spam!\n");
   return 1;
}

/* POLYMORPH SAMURAI [13] */
polymorph_samurai()
{
   do_polymorph(13,POLY_SAMURAI_COST,"exclaim",POLY_SAMURAI_STAT,
      "Suei! Suei! Suei! Not only do you now want to kill\n"+
      "something, but you inherited the skills to do it cleanly,\n"+
      "quickly, and with a sense of self-righteousness.\n");
   return 1;
}

/* POLYMORPH NECROMONGER [13] */
polymorph_necromonger()
{
   do_polymorph(13,POLY_NECROMONGER_COST,"crumble",POLY_NECROMONGER_STAT,
      "Your skin rots and peels off!\n"+
      "Wait. You meant that. In either case you now look like a\n"+
      "big rotten furry corpse-eating cow, walking upright.\n");
   return 1;
}

/* POLYMORPH DEATHBEANO [13] */
polymorph_deathbeano()
{
   do_polymorph(13,POLY_DEATHBEANO_COST,"blorp",POLY_DEATHBEANO_STAT,
      "Stump! You suddenly contract and morph into the familiar stout,\n"+
      "orange frumpy shape that is the Beano. Beware! You are not the\n"+
      "average Beano...\n");
   return 1;
}

/* POLYMORPH BJORK [13] */
polymorph_bjork()
{
   /* femme-only form */
   if(this_player()->query_gender() != "female") 
   {
      write("What? You can't assume this polymorph!\n(And castration is not fun).\n");
      return 1;
   }

   do_polymorph(13,POLY_BJORK_COST,"chirp",POLY_BJORK_STAT,
      "In a flash, you metamophose into the vision of blue-eyed-pop...\n");
   return 1;
}

/* POLYMORPH METABALL [14] */
polymorph_metaball()
{
   do_polymorph(14,POLY_METABALL_COST,"worf",POLY_METABALL_STAT,
      "Biting your lip, it and then you suddenly transform into a\n"+
      "being of questionably stable matter.\n");
   return 1;
}

/* POLYMORPH PLAGUE [14] */
polymorph_plague()
{
   do_polymorph(14,POLY_PLAGUE_COST,"ebola",POLY_PLAGUE_STAT,
      "Reciting the complex and overall wicked chemical structures\n"+
      "of violent biological agents in your head, you take the deformed\n"+
      "and fearsomely misshapen evolutionary nightmare, the walking plague.\n"+
      "Hmm. Then again that does not make you very different from Newark NJ.\n");
   return 1;
}

/* POLYMORPH KUNG-FU CHICKEN [14] */
polymorph_kungfu_chicken()
{
   do_polymorph(14,POLY_KUNGFU_CHICKEN_COST,"cluck",POLY_KUNGFU_CHICKEN_STAT,
      "Sze diao! You feel like beating someone into a cloud of fine red\n"+
      "mist. You are the Kung Fu Chicken. Anything is possible.\n");
   return 1;
}

/* POLYMORPH JUGGERNAUT [14] */
polymorph_juggernaut()
{
   do_polymorph(14,POLY_JUGGERNAUT_COST,"grunt",POLY_JUGGERNAUT_STAT,
      "Your body expands, thickening and assuming the barrel-chested and utterly\n"+
      "fearless form of a juggernaut.\n");
   return 1;
}

/* POLYMORPH HYDRA [14] */
polymorph_hydra()
{
   do_polymorph(14, POLY_HYDRA_COST,"blast",POLY_HYDRA_STAT,
      "Five heads pop out of your body. Thick, gangly scales form and lunge\n"+
      "out from your skin. There is a sudden urge to torch, pillage, and\n"+
      "utterly devastate large cities. You are a Hydra.\n");
   return 1;
}

/* POLYMORPH CLOUDKILL [15] */
polymorph_cloudkill()
{
   do_polymorph(15,POLY_CLOUDKILL_COST, "drift",POLY_CLOUDKILL_STAT,
      "Your hands disappear!\n"+
      "You dissolve yourself and assume the form of a cloud of noxious\n"+
      "poison and gas. Rest assured, this is no sweetness and light.\n"+
      "Your enemies will be the first to know.\n");
   return 1;
}

/* POLYMORPH SPUCKBALL CHAINGUN [15] */
polymorph_spuck_cg()
{
   do_polymorph(15,POLY_SPUCK_CG_COST, "rip",POLY_SPUCK_CG_STAT,
      "Taking the familiar composition of Spuckstuff, or getting as close\n"+
      "to it as you can, you take the form of a Spuckball chaingun.\n");
   return 1;
}

/* POLYMORPH BARNEY [15] */
polymorph_barney()
{
   do_polymorph(15,POLY_BARNEY_COST, "blubber",POLY_BARNEY_STAT,
      "You take a deep breath, contemplating the evil form you are\n"+
      "about to assume. Remembering that despongification is only a button\n"+
      "away in the form of Pro Wrestling or hockey, you assume the form...\n\n"+
      "You become Barney, the purple dionsaur.\n");
   return 1;
}

/* POLYMORPH SPUCKBALL CRUISER [15] */
polymorph_spuck_crs()
{
   do_polymorph(15,POLY_SPUCK_CRS_COST, "hum",POLY_SPUCK_CRS_STAT,
      "Gathering all of the skill you have, you gate into your existence\n"+
      "a considerable amount of mass from the Plane of Etheriel. It responds\n"+
      "binding into your form as the compelling silouhette of a Spuckball\n"+
      "Cruiser.\n");
   return 1;
}

/* POLYMORPH DYNAMINE [15] */
polymorph_dynamine()
{
   do_polymorph(15,POLY_DYNAMINE_COST, "flicker",POLY_DYNAMINE_STAT,
      "You fade with a blinding pop into the form of a pure nuclear\n"+
      "energy producing whiz-thing. Combination black hole, and controlled\n"+
      "antimatter-matter annihilator, you are now a dynamine!\n");
   return 1;
}

/* POLYMORPH HIGH TETRAPOD [15] */
polymorph_high_tetrapod()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(15,POLY_HIGH_TETRAPOD_COST, "growl", POLY_HIGH_TETRAPOD_STAT,
      "Summoning all of the sanity left in your bloodstream, you take\n"+
      "the hulking and mean spirited form of the high tetrapod, whose\n"+
      "tolerance for stupidity is a legendary zero, and whose willingness\n"+
      "to use fists (all 4 of em) for no reason whatsoever is... well, expected.\n");
   return 1;
}

/**
 * ---- TOGGLE FUNCTIONS NOW --- 
 *
 * This function toggles switches in the player's gob.
 *
 */

toggle_function(str) 
{
   object ob;
   ob = present(GUILD_ID, this_player());
   
   /* no gob no service */
   if(!ob) return 0;
   
   if(!str || str == "list") 
   {
      write("\n>> Toggle settings: --------------<<\n\n");
      write("  autocharge\t");
      if(ob->query_autocharge()) write("ON\n"); else write("OFF\n");
      write("  drain\t\t");
      if(ob->query_drain()) write("MATTER\n"); else write("ENERGY\n");
      write("  entry\t\t");
      if(this_player()->query_home()) write("ETHER-MUCK\n"); else write("CHURCH\n");
      write("  eval\t\t");
      if(ob->query_eval()) write("ON\n"); else write("OFF\n");
      write("  invis\t\t");
      if(ob->query_invis()) write("ON\n"); else write("OFF\n");
      write("  max\t\t");
      if(ob->query_max()) write("ACTIVE\n"); else write("OFF\n");
      write("  moncharge\t");
      if(ob->query_moncharge()) write("ADDED\n"); else write("OFF\n");
      write("  monitor\t");
      if(ob->query_monitor()) write("ON\n"); else write("OFF\n");
      write("  msg\t\t");
      if(ob->query_msg()) write("ON\n"); else write("OFF\n");
      write("  muffle\t");
      if(ob->query_muffle()) write("ON\n"); else write("OFF\n");
      write("  news\t\t");
      if(ob->query_news_announce()) write("ON\n"); else write("OFF\n");

      write(">>--------------------------------<<\n");
      return 1;
   }    
   
   else if(str == "autocharge") 
   {
      if(ob->query_autocharge())
         write("Autocharge OFF.\n");
      else 
         write("Autocharge ON.\n");
      
      ob->toggle_autocharge();
      return 1;
   }
   
   else if(str == "drain") 
   {
      if(ob->query_drain())
         write("Corpse drain / charge transfers set to ENERGY.\n");
      else 
         write("Corpse drain / charge transfers set to MATTER.\n");
      
      ob->toggle_drain();
      return 1;
   }
   
   else if(str == "entry") 
   {
      if(this_player()->query_home()) 
      {
         write("Login toggled to the village church.\n");
         this_player()->set_home(0);
      }
      else
      {
         write("Login toggled to the Plane of Etheriel.\n");
         this_player()->set_home("players/mizan/etheriel/ROOMS/linna");
      }
      return 1;
   }
   
   else if(str == "eval") 
   {
      if(ob->query_eval()) 
         write("Combat spell evaluation OFF.\n");
      else 
         write("Combat spell evaluation ON.\n");
      
      ob->toggle_eval();
      return 1;
   }

   else if(str == "invis") 
   {
      if(ob->query_invis()) 
         write("The lump of clay fades into view.\n");
      else 
         write("The lump of clay fades from view.\n");
      
      ob->toggle_invis();
      return 1;
   }

   else if(str == "max") 
   {
      if(ob->query_max())
         write("Monitor will remain active throughout.\n");
      else
         write("Monitor will go idle when HP+SP maxmized.\n");
 
      ob->toggle_max();
      return 1;
   }
   
   else if(str == "moncharge") 
   {
      if(ob->query_moncharge()) 
         write("Monitor charge add-on turned OFF.\n");
      else 
         write("Monitor charge add-on ADDED.\n");
      
      ob->toggle_moncharge();
      return 1;
   }
   
   else if(str == "monitor") 
   {
      if(ob->query_monitor())
         write("Monitor turned OFF.\n");
      else 
         write("Monitor turned ON.\n");
      
      ob->toggle_monitor();
      ob->fake_beat();
      return 1;
   }
   
   else if(str == "muffle") 
   {
      if(ob->query_muffle())
         write("Muffle turned OFF (Channels open).\n");
      else 
         write("Muffle ON.\n");
      
      ob->toggle_muffle();
      return 1;
   }
   
   else if(str == "msg") 
   {
      if(ob->query_msg()) 
         write("Entry-exit messages toggled OFF.\n");
      else
         write("Entry-exit messages toggled ON.\n");
      
      ob->toggle_msg();
      return 1;
   }
   
   else if(str == "news") 
   {
      if(ob->query_news_announce())
         write("Announcing of news text completions turned OFF.\n");
      else 
         write("Announcements of news updates ON.\n");

      ob->toggle_news_announce();
      return 1;
   }
   
   return 0;
}

/**
 * ---- SET FUNCTION NOW ---
 *
 * This function sets variables in the players' guild objects.
 */
set_function(str) 
{
   object gob,mob;
   string varstr;
   int varint;

   gob = present(GUILD_ID, this_player());
   mob = present(MORPH_ID, this_player());

   /* no gob no service */
   if(!gob) return 0;
   
   if(str) 
   {
      if(sscanf(str, "msgin %s", varstr) == 1) 
      {
         gob->set_msgin(varstr);
         write("Entry message emote set to: " +
            (this_player()->query_name()) + " " + varstr + "\n");
      }
      else if(sscanf(str, "msgout %s", varstr) == 1) 
      {
         gob->set_msgout(varstr);
         write("Exit message emote set to: " + 
            (this_player()->query_name()) + " " + varstr + "\n");
      }
      else if(sscanf(str, "panic %s", varstr) == 1) 
      {
         gob->set_panic_key(varstr);
         write("Panic set to '" + varstr + "'.\n");
         gob->init();
      }
      else if(sscanf(str, "nickname %s", varstr) == 1) 
      {
         gob->set_nickname(varstr);
         write("Nickname set to '" + varstr + "'.\n");
      }
      else if(sscanf(str, "statkey %s", varstr) == 1) 
      {
         gob->set_superstat_key(varstr);
         write("Quick-stat key set to '" + varstr + "'.\n");
         gob->init();
      }
      else if(sscanf(str, "sig %s", varstr) == 1) 
      {
         write("Signature on newsgroups set to:\n" + varstr + "\n");
         gob->set_sig(varstr);
         return 1;
      }
      else if(sscanf(str, "pretitle %s", varstr) == 1) 
      {
         if(gob->query_current_morph() != "none") 
         {
            write("You must not be polymorphed to do this.\n");
            return 1;
         }
         this_player()->set_pretitle(varstr);
         gob->set_pretitle(varstr);
         write("Pretitle set to '" + varstr + "'.\n");
      }
      else if(sscanf(str, "title %s", varstr) == 1) 
      {
         if(!check_level(2)) return 1;
         if(gob->query_current_morph() != "none")
         {
            write("You must not be polymorphed to do this.\n");
            return 1;
         }
         if(strlen(varstr) > 99) varstr = extract(varstr, 0, 99);
         write("Title set to '" + varstr + "'.\n");
         this_player()->set_title(varstr);
         gob->set_title(varstr);
      }
      else if(sscanf(str, "doing %s", varstr)) 
      {
         if(strlen(varstr) > 35) varstr = extract(varstr, 0, 35);
         write("Doing set to '" + varstr + "'.\n");
         gob->set_doing(varstr);
      }
      else if(sscanf(str, "monitor %d", varint) == 1) 
      {
         if(varint < 3 || varint > 1000) {
            
            write("Monitor range is 3 - 1000.\n"); return 1;
         }
         write("Monitor interval set to " + varint + " (" + (varint * 2) + " seconds).\n");
         write("Monitor speeds up to update every round in combat.\n");
         gob->set_monitor_interval(varint);
      }
      else if(sscanf(str, "wimpy %d", varint) == 1) 
      {
         if(mob && mob->no_wimpyallow())
         {
            write("You cannot set wimpy in this form.\n");
            return 1;
         }

         if(varint < 0 || varint > 90) 
         {
            write("Wimpy percentage range is 0 - 90. Zero turns guild wimpy OFF.\n"); return 1;
         }
         write("Wimpy percentage set to " + varint + "%.\n");
         if(!varint) write("Guild wimpy now turned OFF.\n");
         gob->set_wimpy_pct(varint);
      }

      gob->record_attribs();
      return 1;
   }

   /* just print status if no args given */
   write("\n");
   write(">> Variable settings: ------------<<\n\n");
   write("  doing      " + (gob->query_doing()) + "\n");
   write("  msgin      " + (gob->query_msgin()) + "\n");
   write("  msgout     " + (gob->query_msgout()) + "\n");
   write("  monitor    " + (gob->query_monitor_interval()) + "\n");
   write("  nickname   " + (gob->query_nickname()) + "\n");
   write("  panic      " + (gob->query_panic_key()) + "\n");
   write("  pretitle   " + (this_player()->query_pretitle()) + "\n");
   write("  statkey    " + (gob->query_superstat_key()) + "\n");
   write("  sig        " + (gob->query_sig()) + "\n");
   write("  title      " + (this_player()->query_title()) + "\n");
   write("  wimpy      " + (gob->query_wimpy_pct()) + "\n");
   write(">>--------------------------------<<\n");
   return 1;
}

/* ****NEW!****
 * This function is used for setting variables native to polymorph
 * forms.
 */
pset_function(str)
{
    object gob;          /* the guild object verification   */
    string varstr;       /* temporary string variable.      */
    int varint;          /* temporary int variable.         */
    string cform;        /* the current morph of the player */

    /* no gob, no service */
    gob = present(GUILD_ID, this_player());
    if(!gob) return 0;
    else cform = gob->query_current_morph();

    if(cform == "none")
    {
        write("You are currently unmorphed.\n"+
              "There are no settings to display or alter in this state.\n");
        return 1;
    }
    else if(cform == "octopus")
    {
        /* nothing was entered, just display pset settings */
        return 1;
    }
    else
    {
        /* we are at the end of the line, if not specified then we dont
         * have any info to manipulate here.
         */
        write("There are no settings to display for this morph form.\n");
        return 1;
    }
}

/* ****NEW!****
 * This function is used for setting toggles native to polymorph forms.
 */
ptoggle_function(str)
{
    object ob;       /* the guild object       */
    string cform;    /* player's current morph */

    /* no gob, no service */
    ob = present(GUILD_ID, this_player());
    if(!ob) return 0;
    else cform = ob->query_current_morph();

    if(cform == "none")
    {
        /* this function does nothing if unmorphed. */
        write("You are currently unmorphed.\n"+
              "There are no toggless to display or alter in this state.\n");
        return 1;
    }
    else if(cform == "octopus")
    {
        if(str == "focus_hits")
        {
            if(ob->query_octopus_focus_hits()) write("Focus hits on primary attacker toggled OFF.\n");
            else write("Focus hits turned ON. Extra attacks will concentrate on primary.\n");
            ob->toggle_octopus_focus_hits();
            return 1;
        }
        else
        {
            /* just display what is toggled, and return. */
            write("  focus_hits\t");
            if(ob->query_octopus_focus_hits()) write("ON\n"); else write("OFF\n");
            return 1;
        }

    }
    else
    {
        /* we are at the end of the line, if not specified then we dont
         * have any info to manipulate here.
         */
        write("There are no toggles to display for this morph form.\n");
        return 1;
    }
}

/* ---- INFO FUNCTIONS NOW --- */

info_function(str) 
{
   string testj, temp, tempd;

   if(!str) 
   {
/*
      call_other("/closed/wiz_soul", "more", HELPDIR + "info");
 */
      cat(HELPDIR + "info");
      return 1;
   }
   else
   {
      if(sscanf(str, "guild %s", testj) == 1) 
      {
         temp = HELPDIR + "guild_" + strip_whitespace(testj);
      }
      if(sscanf(str, "polymorph %s", testj) == 1)
      {
         temp = HELPDIR + "poly_" + strip_whitespace(testj);
      }
      if(sscanf(str, "poly %s", testj) == 1) 
      {
         temp = HELPDIR + "poly_" + strip_whitespace(testj);
      }
      
      if(!temp) 
      {
         temp = strip_whitespace(HELPDIR + str);
      }
      
   }
   
/*
   call_other("/closed/wiz_soul", "more", temp);
 */
   cat(temp);
   return 1;
}

/* This function just strips the whitespace out of a string and replaces
 * them with _ underscores. 
 */
static strip_whitespace(str)
{
   string temp, letter;
   int i;

   temp = "";

   if(!str) return "";
   else
   {
      for(i = 0; i < strlen(str); i++)
      {
         /* grab a letter */
         letter = extract(str, i, i);
         
         /* if its a space, replace it. Else add the letter. */
         if(letter == " ") temp += "_";
         else temp += letter;
      }

      /* we're done. */
      return temp;
   }
}

/* ---- GUT FUNCTIONS NOW --- */


/**
 * The part that actually processes new stats
 *
 * Arguments:
 * lv      minimum polymorph Level to check against.
 * cost    The cost in charges (1 charge = 1 sp)
 * chan    The name of the guild channel they use while morphed.
 * str     The statline for the morph form
 * arg     A string the player is write()ten to when morphing
 */
do_polymorph(lv,cost,chan,str,arg) 
{
   object morpho, gob;
   string gfile, passes, rchan, newtitle;
   int rstat, cnt, strtemp, strtemp2, rcost;

   /* this is a large, heavy, beastly function */
   if(!check_level(lv)) return 1;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   rcost = cost;
   rchan = chan;
   rstat = allocate(6);
   cnt = 0;
   
   /* not enough juice... unless you are a wiz */
   if(this_player()->query_level() < 21 && 
      gob->query_charge() < rcost) 
   {
      write("There is'nt enough energy in the clay to help you polymorph.\n"+
         "This form requires [" + rcost + "] charges.\n");
      return 1;
   }

   if(sscanf(str, "%s#%s#%d#%d#%d#%d#%d#%d", gfile, newtitle,
      rstat[0], rstat[1], rstat[2],
      rstat[3], rstat[4], rstat[5]) != 8) 
   {
      write("This morph form is not completed yet.\n");
      return 1;
   }
   
   passes = allocate(6);
   passes[0]="stamina";
   passes[1]="intelligence";
   passes[2]="magic_aptitude";
   passes[3]="strength";
   passes[4]="stealth";
   passes[5]="luck";
   
   /* clone the mob now. */
   morpho = clone_object(PATHNAME + gfile);

   if(!morpho)
   {
      /* more error checking */

      if(this_player()->query_real_name() == "mizan")
      {
         write("Form is broken. Fix this you dope!\n");
         return 1;
      }

      write("Holy spod! This polymorph form is broken. Contact Mizan!\n");
      return 1;
   }

   move_object(morpho, this_player());
   remote_say((this_player()->query_name()) + " contorts and polymorphs into a " + gfile + ".\n");
   
   /* BREAK for strength-carry checking. */
   
   strtemp = call_other(this_player(), "query_attrib", "str");
   strtemp2 = strtemp + rstat[3];
   if(strtemp2 < strtemp) check_inventory_weight(strtemp - strtemp2);
   
   while(cnt < 5) 
   {
      int tempv,tempw;
      tempv = call_other(this_player(), "query_attrib", extract(passes[cnt], 0, 2));
      tempw = tempv + rstat[cnt];
      if(tempw < 1) tempw = 1;
      call_other(this_player(), "set_attrib", extract(passes[cnt], 0, 2), tempw);
      cnt ++;
   }
   
   /* wizzes get a free ride */
   if(this_player()->query_level() < 21)
      gob->add_charge(-rcost);

   gob->set_morph_comm(rchan);
   gob->set_current_morph(gfile);
   gob->set_title(this_player()->query_title());
   
   if(this_player()->query_pretitle())
      gob->set_pretitle(this_player()->query_pretitle());
   
   this_player()->set_pretitle("|");
   this_player()->set_title("the " + gfile);
   this_player()->reset(1);
   
   if(arg) write(arg);
   
   write("Type 'class' to see your new abilities.\n");
   
   gob->record_attribs();
   morpho->tick();
   check_points();
   write("\n->> ");
   return 1;
}


/* ---- bring a player back from polymorph --- */

undo_polymorph(arg, poof) 
{
   object morpho,gob,vic;
   string gfile,passes,gtemp;
   int rstat,cnt,strtemp;
   int ct; 
   
   ct = 0;
   cnt = 0;
   rstat = allocate(6);
   
   if(arg) vic = arg;
   else vic = this_player();

   gob = present(GUILD_ID, vic);
   if(!gob) return 0;

   if(gob->query_current_morph() =="none" ||
      !gob->query_current_morph()) 
   {
      if(!poof)
         tell_object(vic, "You are not polymorphed as anything.\n");
      if(!poof) return 1;
   }

   gfile = gob->query_main_stats();
   
   if(sscanf(gfile, "%s#%d#%d#%d#%d#%d#%d", 
      gtemp, rstat[0], rstat[1], rstat[2], 
      rstat[3], rstat[4], rstat[5]) != 7) return 0;
   
   passes = allocate(6);
   passes[0]="stamina";
   passes[1]="intelligence";
   passes[2]="magic_aptitude";
   passes[3]="strength";
   passes[4]="stealth";
   passes[5]="luck";
   
   morpho = present(MORPH_ID, vic);
   
   while(morpho) 
   {
      destruct(morpho);
      morpho = present(MORPH_ID, vic);
   }
   
   /* make sure stats are not past illegal bounds */
   if(poof && vic->query_level() < 21)
   {
      while(ct < 6) 
      {
         if(rstat[ct] > 20) rstat[ct] = 20;
         ct++;
      }
   }
   
   if(!poof) 
   {
      remote_say("A " + (gob->query_current_morph()) + " fades and melts into " + (vic->query_name()) + ".\n");
      write("You relax and return to your normal shape.\n");
   }
   
   /* BREAK for strength-carry checking. */
   
   strtemp = call_other(vic, "query_attrib", "str");
   strtemp = strtemp - rstat[3];
   if(strtemp > 0) check_inventory_weight(strtemp,vic);
   
   while(cnt < 5) 
   {
      int tempv;
      tempv = call_other(vic, "query_attrib", extract(passes[cnt], 0, 2));
      call_other(vic, "set_attrib", extract(passes[cnt], 0, 2), rstat[cnt]);
      cnt ++;
   }
   
   /* fix the soul, if it needs fixing */
   if(!present("soul", vic))
      move_object(clone_object("obj/soul.c"), vic);
   
   /* unset some stuff now */
   gob->set_current_morph("none");
   if(gob->query_pretitle())
      vic->set_pretitle(gob->query_pretitle());
   if(gob->query_title())
      vic->set_title(gob->query_title());
   gob->set_morph_comm("vibe");
   gob->record_attribs();
   vic->reset(1);
   vic->set_heart_beat(1);
   check_points();
   return 1;
}

/**
 * ---- compile attribs into a string to be broken down accessed whenever
 *
 * This is an internal function and should not be called directly.
 */

record_stats(arg) 
{
   object gob,vic;
   string tempq;
   if(arg) vic = arg;
   else vic = this_player();
   gob = present(GUILD_ID, vic);
   
   if(!gob) return 0; 
   tempq = gob->query_current_morph() + "#";
   tempq = tempq + vic->query_attrib("sta") + "#" +
   vic->query_attrib("int") + "#" +
   vic->query_attrib("mag") + "#" +
   vic->query_attrib("str") + "#" +
   vic->query_attrib("ste") + "#" +
   vic->query_attrib("luc");
   vic->set_guild_file(GUILDFILE);
   if(vic->query_pretitle())
      
   gob->set_pretitle(vic->query_pretitle());
   gob->set_title(vic->query_title());
   gob->set_main_stats(tempq);
   check_points(vic);
   gob->record_attribs();
   
   vic->save_me();
}

/* ---- when a player dies --- */

deduct_attrib(arg) 
{
   object ob,vic;
   if(arg) vic = arg;
   else vic = this_player();
   ob = present(GUILD_ID, vic);
   if(ob) return 0;
   undo_polymorph(vic);
   record_stats(vic);
   vic->reset(1);
}

/* ---- minor check sequences --- */

/**
 * checks that sps and hps are normal legit values.
 * If not, it bounds them properly.
 */
check_points(arg) 
{
   object vic;
   if(arg) vic = arg;
   else vic = this_player();

   if(vic->query_hp() > vic->query_mhp()) 
      vic->add_hit_point(-(vic->query_hp() - vic->query_mhp()));

   if(vic->query_sp() > vic->query_msp()) 
      vic->add_spell_point(-(vic->query_sp() - vic->query_msp()));
}

/**
 * Checks the guild level
 */
check_level(arg) 
{
   if(this_player()->query_pl_k() && this_player()->query_level() < 20) 
   {
      write("You fail.\n(You are a playerkiller!)\n");
      return 0;
   }
   
   if(this_player()->query_guild_rank() < arg) 
   {
      if(arg > 9) write("You fail.\n");
      else write("You must be guild level [" + arg + "] to do this.\n");
      return 0;
   } else return 1;
}

/**
 * checks player for sps
 */
check_sp(arg) 
{
   if(this_player()->query_sp() < arg) 
   {
      write("You feel too drained to attempt this.\n");
      return 0;
   } else return 1;
}

/*
 * this checks that wimpy is turned off by the player.
 * Used by forms like tetrapod.
 */
check_wimpyoff()
{
   object gob;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;

   if(this_player()->query_wimpy() || gob->query_wimpy_pct()) 
   {
      write("You must have wimpy turned off to assume this polymorph.\n"+
         "Check regular wimpy and guild wimpy and try again.\n");
      return 0;
   }
   else return 1;
}

/**
 * Checks that player is alive. 
 */
check_dead() 
{
   if(this_player()->query_ghost()) 
   {
      write("You are phased as a ghost.\n");
      return 1;
   } else return 0;
}

check_morph(str) 
{
   object gob;
   gob = present(GUILD_ID, this_player());

   if(!gob) return 0;
   
   if(gob->query_current_morph() == str) 
   {
      write("You cannot do that in your current polymorph.\n");
      return 1;
      
   } else return 0;
}

/**
 * This function compensates and recalcs weight for when player's
 * strength changes as a result of polymorphing from something
 * strong like an elephant to a mouse.
 */
check_inventory_weight(str,arg) 
{
   object vic,ob,next_ob;
   int rem_weight,new_max,new_str,max;
   int lev,curr_str;
   
   new_str = str;
   if(arg) vic = arg;
   else vic = this_player();
   
   /* First count up how much stuff player has, since no provision is made
    * in the living.c or player.c
    */
   
   ob = first_inventory(vic);

   while(ob) 
   {
      next_ob = next_inventory(ob);
      rem_weight = rem_weight + (ob->query_weight());
      ob = next_ob;
   }
   
   /* Determine carry limits before and after.
    */
   
   lev = vic->query_level();
   
   curr_str = vic->query_attrib("str");
   max = lev + 6 + (curr_str / 5);
   new_max = lev + 6 + ((curr_str - new_str) / 5);
   
   /* frogs cant carry as much */
   if(vic->query_frog()) 
   {
      max = max / 2;
      new_max = new_max / 2;
   }
   
   if(rem_weight > new_max) 
   {
      /* Now drop items until new weight limit is satisfied. */
      
      ob = first_inventory(vic);
      while(ob) 
      {
         next_ob = next_inventory(ob);
         if(rem_weight > new_max && !ob->drop()) 
         {
            rem_weight = rem_weight - (ob->query_weight());
            move_object(ob, environment(vic));
            remote_say((vic->query_name()) + " drops " + lower_case(ob->short()) + ".\n");
            
            write((ob->short()) + " is too heavy.\n");
            this_player()->add_weight(-(ob->query_weight()));
         }
         ob = next_ob;
         
      }
   }
   return 1;
}

/*
 * This function is used to translate hits that would normally go
 * over the damage cap to penalize the player committing the hit
 * with a loss of some experience points. 
 *
 * The poly guild DOES allow for hits above the cap- but the
 * exps here deducted are clearly a drawback for the amount of
 * damage being done. Questions? Ask me.
 *
 */
check_overdamagecap(person, damage)
{
   object ob;
   int dam;
   int diff_dam;

   dam = damage;
   ob = person;

   if(!ob || !dam) return 0;

   /* if player has less than a certain amount of exp, it will
    * restrict the damage to cap, and will not deduct exps.
    */
   if(ob->query_exp() < BASELINE_EXP)
      dam = DAMAGE_CAP;
   else
   {
      diff_dam = dam - DAMAGE_CAP;

      /* damage of over 100 should NOT happen but if they
       * do the code is here to penalize a hit that wicked very biggly.
       * 25-50 should be the normal range.
       */
      if(diff_dam > 100)
         ob->add_exp(-(diff_dam * SUPERHARD_DAMAGE_DIV));
      if(diff_dam > 75)
         ob->add_exp(-(diff_dam * EXTRAHARD_DAMAGE_DIV));
      else if(diff_dam > 50)
         ob->add_exp(-(diff_dam * VERYHARD_DAMAGE_DIV));
      else if(diff_dam > 25)
         ob->add_exp(-(diff_dam * HARD_DAMAGE_DIV));
      else
         ob->add_exp(-(diff_dam * LIGHT_DAMAGE_DIV));
   }
   return dam;
}

/* ---- remove weapons or armor or both --- */
unready_items(armor,weapon) 
{
   object ob;
   if(armor) write("You remove your worn armors.\n");
   if(weapon) 
   {
      write("You unready your wielded weapon.\n");
      this_player()->stop_wielding();
   }
   
   ob = first_inventory(this_player());
   
   while(ob) 
   {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      if(!oc->id("ND"))
         if(armor && oc->armor_class()) oc->drop("silently");
   }
}

/* ---- return living object, shortens code --- */

/*
 * arguments:
 *   arg - string living to be found.
 *   str - if null, can report back any creature. else must be player.
 *
 */
get_living(arg,str) 
{
   object ob;
   ob = present(arg, environment(this_player()));
   
   if(!ob) 
   {
      write("You ponder.\nThere is no such creature nearby.\n");
      return 0;
   }
   
   if(!living(ob)) 
   {
      write((ob->short()) + " is not a living thing!\n");
      write("You cringe in bogglement.\n");
      return 0;
   }
   
   if(str && ob->query_npc()) 
   {
      write((ob->query_name()) + " is not a player!\n");
      return 0;
   }
   return ob;
}

/* ---- player can 'say' to environment. --*/

remote_say(str) 
{
   this_player()->remote_say(str);
   return 1;
}

/**
 * called when player enters the game
 *
 * Arguments:
 *  arg   the player entering the game.
 */

entrance(arg) 
{
   object gob,ob;
   ob = arg;
   gob = present(GUILD_ID, ob);
   
   /* no gob, no service. This guild uses set_guild_file so
    * chances are if you dont have it, you have a BIG problem.
    */
   if(!gob) return 0;
   if(gob->query_current_morph() == "[LEFT]" ||
      gob->query_current_morph() == "[BANISHED]") 
   {
      ob->set_guild_file(0);
      destruct(gob);
      return 1;
   }

   if(ob->query_pl_k() && ob->query_level() < 20) 
   {
      /* just remind them */
      tell_object(ob, " >> You are a PLAYERKILLER!\n"+
         "    You will be unable to use most guild powers.\n");
      
   }
   
   if(ob->query_pregnancy()) 
   {
      /* just remind them */
      tell_object(ob, " >> You are pregnant!\n"+
         "    You will be unable to polymorph until you give birth.\n");
   }

   /* NO! This is evil for some reason
   undo_polymorph(ob);
   */
   
   /* i hate command() but i gotta use it here */
   command("revert me", ob);

   command("guild motd", ob);
   /*
   tell_object(ob, MOTD + "\n->> ");
    */
   return 1;
}

/* ---- WIZARD - GC POWER SPELLS NOW --- */

/**
 * There is no reason for GCs to give players levels. The current guild system
 * is rock solid and nothing needs fixing or tweaking with it.
 *
 */
promo_player(str) 
{
   object vct,gob;
   string plyr;
   int amt_promo,temp;

   if(!str)
   {
      /* no args given */
      write("Usage:  promo <playername> <levels>\n");
      write("        Promotes/demotes a polymorph's guild levels.\n");
      return 0;
   }

   if(this_player()->query_level() < 20) 
   {
      /* dont even handle it, bounce out */
      return 0;
   }

   if(sscanf(str, "%s %d", plyr, amt_promo) != 2) 
   {
      write("Usage:  promo <plyr> <levels>\n");
      return 1;
   }
   
   vct = find_player(plyr);

   if(!vct) 
   {
      write("Player not found.\n");
      return 1;
      
   }
   
   gob = present(GUILD_ID, vct);
   if(!gob)
   {
      write("That player is not in the guild.\n");
      return 1;
   }

   temp = vct->query_guild_rank() + amt_promo;
   if(temp < 1 || temp >= GC) 
   {
      write("That is an invalid amount.\n");
      return 1;
   }

   vct->add_guild_rank(amt_promo);
   record_stats(vct);
   
   write_file(LOGPATH + "PROMOS", (this_player()->query_real_name()) +
      " promoted " + (vct->query_real_name()) + " " +
      amt_promo + " levels to glevel " + (vct->query_guild_rank()) +
      " on " + ctime() + "\n");

   write("Done.\n");
   return 1;
}

/**
 * This function displays the charge levels of all polys
 * currently logged in.
 *
 * Usage: (WIZ ONLY)
 */
all_player_charges() 
{
   object ob;
   string temp;
   int i;
   temp = ">>--------------------------------------<<\nPlayer\tCharges\n";
   ob = users();
   for(i = 0; i < sizeof(ob); i++) 
   {
      /* cycle through all the users to find polys */
      object gob;
      gob = present(GUILD_ID, ob[i]);
      if(gob)
      {
         /* if is poly, we show the values */
         temp = temp + capitalize(ob[i]->query_real_name()) +
                "\t[" + gob->query_charge() + "]\n";
      }
      i++;
   }
   write(temp +">>--------------------------------------<<\n");
}

/* ---- GUILD POWER SPELLS NOW --- */

/**
 * REGAIN [1]
 * convert a corpse into matter (some gold coins) 
 * or energy into the clay as charges
 */
regain_corpse() 
{
   object ob,gob;
   int x,i;

   /* some checking */
   if(check_dead()) return 1;
   if(check_morph("sponge")) return 1;
   if(!check_sp(REGAIN_COST)) return 1;
   
   ob = present("corpse", this_player());
   if(!ob)
   {
      ob = present("corpse", environment(this_player()));
      if(!ob)
      {
         write("There is no corpse to regain energy from present.\n");
         return 1;
      }
      else 
      {
         this_player()->add_weight(-(ob->query_weight()));
         remote_say((this_player()->query_name()) + " drops the corpse.\n");
      }
   } 
   
   this_player()->add_spell_point(-REGAIN_COST);

   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   i = this_player()->query_attrib("wil") * 5;
   x= (i * ob->heal_value()) / 100;
   
   if(gob->query_drain()) 
   {
      write("You phase the matter of the corpse into some gold coins.\n");
      remote_say((this_player()->query_name()) + " turns a corpse into some gold coins!\n");
      destruct(ob);
      ob=clone_object("obj/money");
      ob->set_money(x * 2);
      move_object(ob, environment(this_player()));
      return 1;
   }
   else 
   {
      write("You charge the matter energy of the corpse into your sphere.\n"+
         "It begins to glow and shrink, as its matter is converted to pure energy.\n");
      remote_say((this_player()->query_name()) + " kneels to the ground next to " + lower_case(ob->short()) + ".\n");
      
      remote_say("It shrivels and disappears.\n");
      gob->add_charge(x);
      write("There are [" + (gob->query_charge()) + "] charges in the clay's matrix.\n");
      destruct(ob);
      return 1;
   }
}

fast_Do(str) 
{
   string a1,a2,a3,a4,a5;
   if(!str) 
   {
      write("Usage is 'Do <cmd1>,<cmd2>,<cmd3>...'\n"+
         "  Directional commands such as 'n,s,e,w,u,d' are the only types allowable.\n"+
         "  Limits of execution are 5 commands at once.\n");
      return 1;
      
   }
   write("You phase yourself into a gas.\n");
   
   if(sscanf(str, "%s,%s,%s,%s,%s", a1, a2, a3, a4, a5) == 5) 
   {
      exe(a1); exe(a2); exe(a3); exe(a4); exe(a5);
   }
   else if(sscanf(str, "%s,%s,%s,%s", a1, a2, a3, a4) == 4) 
   {
      exe(a1); exe(a2); exe(a3); exe(a4);
   }
   else if(sscanf(str, "%s,%s,%s", a1, a2, a3) == 3) 
   {
      exe(a1); exe(a2); exe(a3);
   }
   else if(sscanf(str, "%s,%s", a1, a2) == 2) 
   {
      exe(a1); exe(a2);
   }
   else 
      exe(str);

   write("You rephase yourself into a more solid form.\n");
   return 1;
}

/*
 * This is used by above's speedster fast_do.
 *
 */
static exe(str)
{
   string cmd;
   cmd = str;
   if(!cmd) return 0;
   
   if(cmd == "n" || cmd == "s" || cmd == "e" ||
      cmd == "w" || cmd == "u" || cmd == "d" ||
      cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se")
   
      command(cmd, this_player());
   else write("You fail.\n");
   
   return 1;
}

/* ---- ATOMIZE [3] nuke objects for their worth in healing or gold --- */
atomize_object(str) 
{
   object ob,gob;
   int x,i;
   if(check_dead()) return 1;
   if(check_morph("wombat")) return 1;
   if(check_morph("sponge")) return 1;
   if(!check_level(3)) return 1;

   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   if(!str)
   {
      write("Atomize what?\n");
      return 1;
   }
   ob = present(str, this_player());
   if(!ob)
   {
      ob = present(str, environment(this_player()));
      if(!ob)
      {
         write("You have no such item.\n");
         return 1;
      }
      write("You must get it first!\n");
      return 1;
   }
   
   /* can't atomize things like quicktypers */
   if(ob->drop() || !ob->get())
   {
      write("You fail.\n");
      return 1;
   }
   
   if(!check_sp(ATOMIZE_COST)) return 1;
   
   i = this_player()->query_attrib("pie") * 5;
   x = (i * (ob->query_value())) / 100;
   remote_say((ob->short()) + " is systematically absorbed by " + 
      (this_player()->query_name()) + ".\n");
   
   this_player()->add_weight(-(ob->query_weight()));
   
   if(gob->query_drain())
   {
      /* drain to coins (matter) */
      x = ob->query_value();
      if(x > 1500) x = random(500) + 1000;
      this_player()->add_money(x);
      write("You phase the matter and energy contained within " + 
         lower_case(ob->short()) +
         " into [" + x + "] gold coins.\n");
   } 
   else 
   {
      /* drain to charges (energy) */
      if(x > 5000) x = 5000;
      x = x / (70 - this_player()->query_attrib("wil"));
      this_player()->heal_self(x);
      write("The energy contained within " + 
         lower_case(ob->short()) +
         " heals you somewhat.\n");
  
      superstat(this_player());
   }
   destruct(ob);
   return 1;
}


/* ---- CHARGE [1] charges vital for polymorph functions ---*/

charge_clay(arg) 
{
   object ob,gob;
   int x;
   if(check_dead()) return 1;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   if(gob->query_current_morph() != "none")
   {
      if(gob->query_current_morph() != "wombat") 
      {
         write("You must not be polymorphed to do this.\n");
         return 1;
      }
   }
   if(!arg)
   {
      write("You have [" + (gob->query_charge()) + "] charges in the clay.\n");
      return 1;
   }
   if(sscanf(arg, "%d", x) != 1) return 0;
   if(x < 1)
   {
      write("ZZZZZZZZZAAAAAPPP!!!\n\nOUCH!!\n");
      this_player()->add_exp(-500);
      return 1;
   }
   if(this_player()->query_sp() < x) 
   {
      write("You don't have that many spell points!\n");
      return 1;
   }
   write("You divert [" + x + "] spell points of energy into the clay's matrix.\n");
   this_player()->add_spell_point(-x);
   gob->add_charge(x);
   write("There are [" + (gob->query_charge()) + "] charges in the clay.\n");
   return 1;
}

/* ---- SURVEY [2] scan room and nearby exits for stuff --- */

survey_area() 
{
   object room,temproom;
   string exits,tempg,temph,tempi;
   int i;

   if(check_dead()) return 1;
   if(!check_level(2)) return 1;
   if(!check_sp(SURVEY_COST)) return 1;
   
   room = environment(this_player());
   exits = room->query_dest_dir();
   
   if(!exits)
   {
      write("For some reason, you cannot survey this area.\n");
      return 1;
   }
   
   this_player()->add_spell_point(-SURVEY_COST);
   
   if(room->realm() == "NT" && 1 == random(3 + this_player()->query_guild_rank()))
   {
      write("You attempt to survey the area, but are suddenly distracted, and fail.\n");
      return 1;
   }
   
   write("You peer about intently.\n\n");
   remote_say((this_player()->query_name()) + " surveys the area carefully.\n");
   temph = environment(this_player())->short();
   
   if(temph && sscanf(temph, "Plane of Etherie%s", tempi) == 1) 
   {
      /* we are inside the jello. The room system is a bit different here. */
      while(i < sizeof(exits)) 
      {
         temproom = find_object("/players/mizan/etheriel/ROOMS/" + exits[i]);
         if(temproom) 
         {
            tempg = dump_inventory(temproom);
            if(tempg)
               write("Scanning " + exits[i] + " you find:\n" + tempg);
            else 
               write("Scanning " + exits[i] + " find nothing.\n");
         }
         else 
            write("Scanning towards " + exits[i] + " you find it is unexplored.\n");

         i++;
      }
      return 1;
   } 
   else 
   {
      i = 1;
      while(i < sizeof(exits)) 
      {
         temproom = find_object(exits[i-1]);
         if(temproom) 
         {
            tempg = dump_inventory(temproom);
            if(tempg) write("Looking " + exits[i] + " you find:\n" + tempg);
            else write("Looking " + exits[i] + " find nothing.\n");
         }
         else write("Looking " + exits[i] + " you find it is unexplored.\n");
         i = i + 2;
      }
      return 1;
   }
}

/* used by above */

static dump_inventory(arg) 
{
   object ob;
   string tempj;
   int lim;
   tempj = "";
   ob = first_inventory(arg);
   while(ob) {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      if(oc->short()) tempj = tempj + "\t" + (oc->short()) + ".\n";
      
      lim ++;
      if(lim > 12) {
         tempj = tempj + "\t[TRUNCATED]\n";
         break;
         }
   }
   return tempj;
}

/* ---- ETHER [3]
players in my guild will have a natural edge over others
in my castle. This spell allows fearsome movement. --- */

ether(str) 
{
   string temp,temp2;
   if(check_dead()) return 1;
   if(!check_level(3)) return 1;
   if(!check_sp(ETHER_COST)) return 1;
   this_player()->add_spell_point(-ETHER_COST);
   temp = environment(this_player())->short();
   
   
   if(!temp || sscanf(temp, "Plane of Etherie%s", temp2) != 1)  
   {
      write("You are not within the ether-muck.\n");
      return 1;
   }
   
   if(str == "net")
   {
      write("Ha. Ha. Ha.\n");
      return 1;
   }

   if(str == "tempest") 
   {
      write("A voice echoes: Doh! That would be HIGHLY stupid... Trust me.\n");
      return 1;
   }
   
   /*
   Not TOO godlike... reduced to keep castle mem use in check */
   call_other("/players/mizan/etheriel/ROOMS/" + str, "???");
   if(!find_object("/players/mizan/etheriel/ROOMS/" + str)) 
   {
      /*
      write("A voice echoes: There is no such area within the ether-muck.\n");
      */
      write("You know such a place exists but are not too sure how to get there.\n");
      return 1;
   }
   write("You move your matter towards destination " + str + ".\nA voice echoes: Here ya go.\n");
   this_player()->move_player("somewhere#players/mizan/etheriel/ROOMS/" + str);
   return 1;
}

/* ---- HELPME [>3] spots your location so other guild members can help. */

helpme() 
{
   object ob,gob;
   int i;
   string tmp;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   if(check_dead()) return 1;
   if(this_player()->query_guild_rank() > 3) 
   {
      write("You are too powerful to use this ability now.\n");
      return 1;
   }
   if(!this_player()->query_attack()) 
   {
      write("Relax! You're not fighting anything.\n");
      return 1;
   }
   
   if(this_player()->query_exp() < HELPME_COST) 
   {
      write("You don't have enough experience!\n");
      return 1;
   }
   
   /* punch thru muffle */
   if(gob->query_muffle()) 
   {
      write("You were muffled! Overriding muffle!\n");
      gob->toggle_muffle();
   }
   this_player()->add_exp(-HELPME_COST);
   ob = first_inventory(environment(this_player()));
   while(ob) {
      object oc;
      oc = ob;
      
      ob = next_inventory(ob);
      if(this_player()->query_attack() != oc && oc->query_attack() == this_player()) i ++;
      
   }
   tmp = "Help!! I'm fighting " + (this_player()->query_attack())->query_name();
   tmp = tmp + " at '" + (environment(this_player())->short()) + "'";
   if(i) tmp = tmp + " with " + i + " enemies present!\n";
   else tmp = tmp + "!\n";
   guild_tell(tmp);
   return 1;
}


/* ---- SUPERWHO [2] nasty and long and cpu-intensive.. but better
than other shit-whos IMHO */

superwho(str) 
{
   object ob;
   string toast;
   int wizzes,peeps,v,unlock;

   if(!check_level(2)) return 1;
   
   ob = users();
   
   /* build the header */
   write("\n>>Superwho----------------------------------------------------------------<<\n");
   write("Name\t\t Lev Sex P/K  Guild      ");
   
   /* parse cmd line */
   if(str)
   {
      /* let the display scroll over horizontally */
      if(sscanf(str, "%s -u", toast) == 1 ||
         str == "-u") unlock = 1;
      
      /* wizzes only get sitename or ip info */
      if(this_player()->query_level() > 20) 
      {
         if(str == "/ip") write("IP Number");
         if(str == "/s") write("Sitename");
      }
      if(str == "/a") write("Attacker");
      if(str == "/c") write("Condition");
      if(str == "/p") write("Height (',\"), Weight (lbs)");
   } 
   else 
      write("Current location");
   
   write("\n");
   for(v = 0; v < sizeof(ob); v++)
   {
      string tempr;
      string temps;
      int lv;
      
      tempr = "";
      if(environment(ob[v]) && ob[v]->query_name() && ob[v]->query_gender()) 
      {
         if(!ob[v]->query_invis() || ob[v]->query_invis() < 19) 
         {
            /* add some flags */
            if(ob[v]->query_ghost()) tempr = tempr + "@";
            if(query_idle(ob[v]) >= 5 * 60) tempr = tempr + "=";
            if(in_editor(ob[v])) tempr = tempr + "*";
            
            /* name */
            tempr += (capitalize(ob[v]->query_real_name()) + "\t");
            if(strlen(tempr) < 9) tempr = tempr + "\t";

            /* level */
            lv = ob[v]->query_level();
            if(lv < 10) tempr = tempr + "   " + lv + "  ";
            
            if(lv > 9 &&  lv< 20) tempr = tempr + "  " + lv + "  ";
            if(lv > 19)
            {
               /* this is a wiz, calibrate the levels */
               if(lv == 20) tempr = tempr + "Frob  ";
               if(lv > 20 && lv < 60) tempr = tempr + " Wiz  ";
               if(lv > 59 && lv < 100) tempr = tempr + "EWiz  ";
               if(lv > 99 && lv < 1000) tempr = tempr + "SWiz  ";
               if(lv > 999 && lv < 10000) tempr = tempr + "Arch  ";
               if(lv > 9999 && lv < 50000) tempr = tempr + " God  ";
               if(lv > 49999) tempr = tempr + "GOD!  ";
               wizzes = wizzes + 1;
            }

            /* gender */
            tempr = tempr + capitalize(extract(ob[v]->query_gender(), 0, 0)) + "   ";
            
            /* pk flag */
            if(ob[v]->query_pl_k()) tempr = tempr + "Y   ";
            else tempr = tempr + "N   ";
            
            /* guild name */
            if(ob[v]->query_guild_name() && strlen(ob[v]->query_guild_name()) > 1) 
            {
               if(!toast && strlen(ob[v]->query_guild_name()) > 7) tempr = tempr + extract((ob[v]->query_guild_name()), 0, 7) + ".\t";
               else tempr = tempr + (ob[v]->query_guild_name()) + "\t";
            }
            else 
               tempr = tempr + "none\t";
            
            /* parse the various options */
            if(str) 
            {
               if(str == "/ip" && this_player()->query_level() > 20)
                  temps = "(" + query_ip_number(ob[v]) + ")";
               
               if(str == "/s" && this_player()->query_level() > 20) 
                  temps = query_ip_name(ob[v]);
               
               if(str == "/a")
               {
                  object ty;
                  ty = ob[v]->query_attack();
                  temps = "";
                  
                  if(ty) 
                  {
                     temps = temps + superstat_colorize((ty->query_hp() * 100) / ty->query_mhp());
                     if(ty->short()) temps = temps + (ty->short());
                     else temps = temps + "Someone";
                  }
                  else 
                     temps = temps + "(Not fighting)";
                  temps =  temps + ESC + "[0m";
               }
               
               if(str == "/p") 
               {
                  int ft,ic,lb;
                  ft = ob[v]->query_phys_at(1);
                  ic = ob[v]->query_phys_at(2);
                  lb = ob[v]->query_phys_at(3);

                  if(ob[v]->query_level() < 21) 
                  {
                     temps = ft + " feet " + ic + " inches, " + lb + " lbs.";
                  } else temps = "(Unknown)";
               }  

               if(str == "/c") 
               {
                  int tsa,tsm;
                  tsa = ob[v]->query_hp();
                  tsm = ob[v]->query_mhp();
                  if(tsa < tsm/10) temps = superstat_colorize(10) + "In very bad shape.";
                  if(tsa < tsm/5) temps = superstat_colorize(25) + "In bad shape.";
                  
                  if(tsa < tsm/2) temps = superstat_colorize(45) + "Is somewhat hurt.";
                  if(tsa < tsm - 20) temps = superstat_colorize(85) + "Is slightly hurt.";
                  
                  if(tsm == tsa) temps = ESC + "[32m" + "In good shape.";
                  if(ob[v]->query_ghost()) temps = "Dead.";
                  /* CHANGED by mizan, this spell should check for levels. */
                  if(ob[v]->query_level() > this_player()->query_level()) temps = "(Unknown)";
                  if(ob[v]->query_level() > 20) temps = "(Not applicable)";
               }
            } else temps = (environment(ob[v]))->short();
            if(!temps) if(str) temps = " "; else temps = "(not available)";
            
            if(!unlock && strlen(temps) > 34) tempr = tempr + (extract(temps, 0, 34)) + ".\n";
            else tempr = tempr + temps + "\n";
            peeps = peeps + 1;
            
         }
         write(tempr + ESC + "[0m");
         
       } else write("[Logon]\n");
   }

   /* tail end */
   write("\n>>- '*' is wizard editing, '=' is idle.                                -<<\n");
   write(">>-Players: [" + peeps + "] Wizards: [" + wizzes + "] Date [" + ctime() + "]          ");
   if(peeps < 10) write(" ");
   write("-<<\n");
   return 1;
}

/* ---- modified player score ---- */
   
do_score() 
{
   object gob;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   if(check_dead()) return 1;

   /* do the original score first */
   this_player()->score();
   
   write("Guild rank:  \t[" + (this_player()->query_guild_rank()) + "]\n");
   write("Clay charges: \t[" + (gob->query_charge()) + "]\n");
   if(!gob->query_current_morph()) gob->set_current_morph("none");
   if(gob->query_current_morph() != "none") write("Current polymorph: [" +
         capitalize(gob->query_current_morph()) + "]\n");
   else write("You are not polymorphed.\n");
   
   if(gob->query_nickname() && gob->query_nickname() != "none")
      write("Your nickname is '" + (gob->query_nickname()) + "'.\n");

   write("Time: (USA CST) " + ctime() + "\n");

   if(gob->query_panic_key())
      write("Panic key is '" + (gob->query_panic_key()) + "'.\n");
   if(gob->query_superstat_key())
      write("Quick-Stat key is '" + (gob->query_superstat_key()) + "'.\n");
   if(gob->query_muffle())
      write("Guild channel is OFF.\n");
   if(gob->query_invis())
      write("Guild object is INVIS.\n");
   
   if(gob->query_drain()) write("Regain corpse toggled to MATTER.\n");
   else write("Regain corpse toggled to ENERGY.\n");
   return 1;
}

do_clock() 
{
   write("You look carefully at your clay and some words appear:\n");
   write("\nThe mud will reboot after 8 hours.\n");
   call_other("room/church","long","clock");
   write("\n");
   return 1;
}

superstat(moo, eep) 
{
   object atk,vc;
   string temp;
   int tpa,vh,vs,x,y;
  
   vc = moo;
   
   vh = (vc->query_hp() * 100) / vc->query_mhp();
   vs = (vc->query_sp() * 100) / vc->query_msp();
   
   temp = superstat_colorize(vh) + "HP<" + vc->query_hp() + "/" + vc->query_mhp() + "> ";
   temp = temp + superstat_colorize(vs) + "SP<" + vc->query_sp() + "/" + vc->query_msp() + "> ";
   
   if(vc->query_intoxination()) 
   {
      y = vc->query_level() + 3;
      x = (vc->query_intoxination() * 100) / y;
      temp = temp + superstat_colorize_inv(x) + "I<" + x + "%> ";
   }
   
   if(vc->query_stuffed()) 
   {
      y = vc->query_level() * 8;
      x = (vc->query_stuffed() * 100) / y;
      temp = temp + superstat_colorize_inv(x) + "F<" + x + "%> ";
   }
   
   if(vc->query_soaked()) 
   {
      y = vc->query_level() + 3;
      x = (vc->query_soaked() * 100) / y;
      temp = temp + superstat_colorize_inv(x) + "S<" + x + "%> ";
   }
   
   if(vc->query_attack()) 
   {
      atk = vc->query_attack();
      x = (atk->query_hp() * 10) / atk->query_mhp();
      temp = temp + superstat_colorize(x * 10) + "AHP<" + x + "/10 max>";
   }
   
   if(eep) 
   {
      tpa = eep;
      temp = temp + superstat_colorize((tpa * 100) / 2300) + "CH[" + tpa + "]";
   }
   
   temp = temp + ESC + "[0m";
   tell_object(vc, temp + "\n");
}

superstat_window(arg,ht,eep) 
{
   object ob;
   ob = arg;
   tell_object(ob,
      
      ESC + "[H");
   superstat(ob, eep);
   tell_object(ob,
      ESC + "[H" +
      ESC + "[" + ht + "D");
}

superstat_colorize(x) 
{
   int j;
   j = x;
   if(j == 100) return ESC + "[32m";
   else if(j > 80) return ESC + "[1m" + ESC + "[32m";
   else if(j > 60) return ESC + "[33m";
   else if(j > 40) return ESC + "[1m" + ESC + "[33m";
   else if(j > 20) return ESC + "[31m";
   return ESC + "[5m" + ESC + "[31m";
}

superstat_colorize_inv(x) 
{
   int j;
   j = x;
   if(j == 100) return ESC + "[5m" + ESC + "[31m";
   else if(j > 80) return ESC + "[31m";
   else if(j > 60) return ESC + "[1m" + ESC + "[33m";
   else if(j > 40) return ESC + "[33m";
   else if(j > 20) return ESC + "[1m" + ESC + "[32m";
   return ESC + "[32m";
}

/* ---- COMBAT SPELL DRIVERS --- */

/**
 * This is a truly hideous function.
 *
 * It performs the scaling and checking for a multiple target,
 * area attack ability. I don't know what the arguments are at
 * this moment, too lazy to document.
 *
 */
area_attack(limit,arg,swm,ssm,vwm,vsm,wwm,wsm,hwm,hsm,finwm,finsm,fwm,fsm)
{
   object foo,gob;
   int dam_divisor,dam_charges;
   gob = present(GUILD_ID, this_player());
  
   if(!gob) return 0;
   if(!arg) dam_charges = limit / 2;
   else if(sscanf(arg, "%d", dam_charges) != 1) return 0;

   if(dam_charges < 2 || dam_charges > limit) 
   {
      write("A voice echoes: That is out of range. Limits are 2 - " + limit + " sps.\n");
      return 1;
   }
   
   if(!check_sp(dam_charges)) return 1;

   this_player()->add_spell_point(-dam_charges);

   if(1 == random(this_player()->query_attrib("wil")) * 2) 
   {
      write(fwm);
      remote_say((this_player()->query_name()) + " " + fsm);
      return 1;
   }
   
   dam_divisor = count_livings();
   
   if(dam_divisor > 2) dam_divisor = dam_divisor - 1;
   dam_charges = dam_charges / dam_divisor;
   
   foo = first_inventory(environment(this_player()));

   write(swm);
   remote_say((this_player()->query_name()) + " " + ssm);
   
   while(foo) 
   {
      object foo2;
      foo2 = foo;
      foo = next_inventory(foo);
      if(living(foo2) && foo2 != this_player()) 
      {
         if(foo2->query_npc() && !foo2->is_kid() && !foo2->is_pet()) 
         {
            int foo_hp,foo_damage;
            foo_hp = foo2->query_hp();
            foo_damage = random(dam_charges);
            if(foo_hp < foo_damage ||
               foo_hp == foo_damage) 
               foo_damage = foo_hp - 1;
            
            write("You see " + capitalize(foo2->query_name()) + " " + vwm);
            remote_say(capitalize(foo2->query_name()) + " " + vsm);
            foo2->attack_object(this_player());
            /*
            foo2->hit_player(foo_damage);
            */
            /* the new method 
             * damage cap checking is done here 
             */
            hit_creature(this_player(), foo2, foo_damage);

            if(gob->query_eval()) evaluate_hit(foo_damage);
         }
         else 
         {
            if(1==random(3) && foo2->query_level() < 30) 
            {
               write("You see " + capitalize(foo2->query_name()) + " " + wwm);
               remote_say(capitalize(foo2->query_name()) + " " + wsm);
               foo2->run_away();
            } 
            else 
            {
               write(capitalize(foo2->query_name()) + " " + hwm);
               remote_say(capitalize(foo2->query_name()) + " " + hsm);
            }
         }
      }
   }
   write(finwm);
   remote_say((this_player()->query_name()) + finsm);
   return 1;
}

/**
 * This is a single attack spell function.
 *
 * inputs:
 * limit    what the spell costs.
 * arg      The name of the object to attack
 * swm      The write msg before the monster name.
 * swpm     The write msg after the monster name.
 * ssm      The say msg before the monster name.
 * sspm     The say msg after the monster name.
 *
 * I really should fix these functions. The arguments are so cobol, and
 * crufty, but this stuff works.
 */
single_attack(limit,arg,swm,swpm,ssm,sspm) 
{
   object gob,ob;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   if(check_dead()) return 1;
   if(!check_sp(limit)) return 1;
   
   if(!arg) 
   {
      ob = this_player()->query_attack();
      if(!ob) {
         write("Attack who?\n");
         return 1;
      }
   }
   
   if(arg && !ob) 
   {
      ob = present(arg, environment(this_player()));
      if(!ob) {
         write("There is no such creature present.\n");
         return 1;
      }
      
   }
   
   if(!living(ob)) 
   {
      write("You are left in a steep bogglement.\n");
      return 1;
   }
   
   if(ob->is_player()) 
   {
      write("You cannot use guild powers against other players!\n");
      return 1;
   }
   
   if(!this_player()->valid_attack(ob)) return 1;
   /* recalc, randomized and 'bonus' potential damage */
   this_player()->add_spell_point(-limit);

   /* Chance of failure dependent on willpower */
   if(random(this_player()->query_attrib("wil") * 2) == 1) 
   {
      write("You goofed and screw up.\n");
      return 1;
      
   }
   
   write(swm + (ob->query_name()) + swpm + "\n");
   remote_say(ssm  + (ob->query_name()) + sspm +"\n");
   /* Whos is right? Standard formula is spcost = 2x + y when dam = x + random(y)
   Boltar and Saber think spcost = x when dam = random(2x) */
   limit = random(2 * limit);
   /* For now my guild is at the higher setting to match others and compete with
   the living.c spell_object spells. */
   /*
   limit = random(limit / 2);
   */
   /*
   ob->hit_player(limit);
   */

   hit_creature(this_player(), ob, limit);

   if(gob->query_eval()) evaluate_hit(limit);
   if(ob && !ob->query_attack()) ob->attack_object(this_player());
   return 1;
}

/* ---- COMBAT SPELL DRIVER GUTS --- */

/*
 * This function simply counts the number of available targets in a room
 * and returns the number of potential blicks.
 *
 */
count_livings() 
{
   object moo;
   int whees;
   moo = first_inventory(environment(this_player()));
   while(moo)
   {
      object squish;
      squish = moo;
      moo = next_inventory(moo);
      if(living(squish) && squish->query_npc() && !squish->is_kid()
            && !squish->is_pet()) whees = whees + 1;
   }
   return whees;
}

/*
 * this function simply evaluates the potential hit of each attack and
 * writes a message to player's console.
 */
evaluate_hit(arg) 
{
   string tmp;
   tmp = "way over the legal limit";
   if(arg < (DAMAGE_CAP + 30)) tmp = "over the legal limit";
   if(arg < DAMAGE_CAP) tmp = "devastating";
   if(arg < 40) tmp = "bone crushing";
   if(arg < 30) tmp = "smashing";
   if(arg < 20) tmp = "very hard";
   if(arg < 10) tmp = "some hard";
   if(arg < 5) tmp = "some";
   if(arg < 3) tmp = "grazing";
   if(arg == 1) tmp = "tickling";
   else tmp = "no";
   
   write("**You feel you did " + tmp + " damage from that spell.\n");
   return 1;
}

static string msgs;

/**
 * This silly function just displays a cute msg when the attacker is at 1 hp. I dont
 * want to kill monsters with single_attack because it causes regen reset or heartbeat
 * problems if i do.
 *
 */
critical_hit_msg() 
{
   if(!msgs) {
      msgs = ({"spins about dizzily.","is beaten to a blind stupor.",
            "appears ready to die.","is critically hit!",
            "collapses to the ground with a heavy *thunk*","begins mumbling incoherently.",
            "wheezes and sputters violently.","begins twitching and convulsing in a Spuck-like way.",
            "staggers and stumbles in pain.","begins foaming at the mouth."
            });
   }
   return msgs[random(sizeof(msgs))];
}

/* MULTIPLE HIT-WIELD DRIVERS */

/*
 * dpi       The damage intended to be delivered
 * inum      The limb number doing the attacking
 * atk       The object being attacked
 * me        Ourselves
 * escsq     An escape sequence to modify the hit msgs
 * uncap     If not null, an issue will be given to remove damage cap.
 *           NOTE THAT EXPS will cost in extra hits.
 */

/* ---- arg = damage, inum = attack type, atk = attacker object --- */

extra_hit(dpi, inum, atk, me, escsq, uncap)
{
   object ob,person;
   string how,what,type,escape_seq;
   int dam,tmp;

/*
 * apr 95
 * i fixed this to work with the single hit proposal by boltar
 * to hit_player() check the poly morph objects for damage 
 * caps- they are the and are set to 50 max per round each. 
 */

   type = get_type(inum);
   tmp = dpi;
   
   dam = random(tmp);

   if(me) person = me;
   else person = this_player();
   
   if(escsq) 
   {
      escape_seq = escsq;
      tell_object(person, escape_seq);
   }
   
   if(random(person->query_attrib("ste")) < 6) 
   {
      tell_object(person, "Your " + type + " attack missed.\n");
      person->remote_say((person->query_name()) + " misses " +
         (person->query_possessive()) + " " + type + " attack.\n");
      return;
   }
   
   how = " to a bloody pulp";
   what = "massacre";

   if(dam < DAMAGE_CAP) { how = " to small fragments"; what = "massacre"; }
   if(dam < 30) { how = " with a bone crushing sound"; what = "smashed"; }
   if(dam < 20) { how = " very hard"; what = "hit"; }
   if(dam < 10) { how = " hard"; what = "hit"; }
   if(dam < 5) { how = ""; what = "hit"; }
   if(dam < 3) { how = ""; what = "grazed"; }
   if(dam == 1) { how = " in the stomach"; what = "tickled"; }
   ob = atk;

   if(!ob || ob->query_ghost()) return 0;

   /* display messages */
   tell_object(person, "You " + what + " " + 
      (ob->query_name()) +  how + " with your " +
      type + " attack.\n");

   person->remote_say((person->query_name()) + " " + what +
      " " + (ob->query_name()) + how +
      " with " + (person->query_possessive()) + " " +
      type + " attack.\n");

   if(ob->query_hp() <= dam) 
   {
      tell_room(environment(person), (ob->query_name()) + " " + critical_hit_msg() + "\n");
      dam = ob->query_hp() - 1;
   }

   if(escape_seq) tell_object(person, (ESC + "[0m"));

   /* NEW! This function does not do the damage anymore. That has migrated
    * to its own dedicated function, hit_creature.
    */
}

/*
 * This is the actual function that hits the creature in multiple
 * limb attacks. Its a quick-fix thing.
 *
 * arguments:
 * me    ourselves, is referenced only if the damage inflicted is over
 *       the legal damage cap, and exp is deducted.
 * what  our target.
 * dam   the amt of damage.
 */
hit_creature(me, what, damage)
{
   object ob;
   int dam;

   ob = what;
   dam = damage;
   if(!ob || damage <= 0) return 0;

/*
   if(dam > DAMAGE_CAP)
      dam = check_overdamagecap(me, dam);
 */
      if(dam > DAMAGE_CAP) dam = DAMAGE_CAP;


   ob->hit_player(dam);
}

/*
 * There will be no 'strap all' cos I didnt really like the idea.
 * Ok, the truth is that i am such an incompetent coder it never
 * worked right when i tried it.
 *
 */
strap_weapon(str) 
{
   int i,ok_flag;
   object mob, weapon, ob, oc;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   weapon = mob->query_weapon_list();
   if(sizeof(weapon) < 2) return 0;
   
   if(!this_player()->query_weapon()) 
   {
      write("You must wield a primary weapon first.\n");
      return 1;
   }

   if(!str) 
   {
      write("Strap what?\n");
      return 1;
   }
   
   /* Normal one-item strapping */
   
   ob = present(str, this_player());
   if(!ob) 
   {
      write("You have no such item.\n");
      return 1;
   }

   if(!ob->weapon_class() || this_player()->query_weapon() == ob) 
   {  
      write("You cannot strap that!\n");
      return 1;
   }
   
   while(i < sizeof(weapon)) 
   {
      if(!weapon[i] && !ok_flag) 
      {
         ok_flag = 1;
         weapon[i] = ob;
         write("You strap " + lower_case(ob->short()) + " as a " + get_type(i) + " weapon.\n");
         remote_say((this_player()->query_name()) + " wields " + 
            lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");
         move_object(weapon[i], mob);
      }
      i++;
   }
   if(!ok_flag) write("You have no more free limbs.\n");
   else mob->set_weapon_list(weapon);
   return 1;
}

unstrap_weapon(str) 
{
   object mob,weapon,ob;
   int i,ok_flag;
   mob = present(MORPH_ID, this_player());
   if(!str || !mob) return 0;
   weapon = mob->query_weapon_list();
   if(!weapon) return 0;

   ob = present(str, mob);
   while(i < sizeof(weapon)) 
   {
      if(weapon[i] && !ok_flag) 
      {
         if(ob && ob == weapon[i]) 
         {
            write("You unstrap " + lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");
            
            remote_say((this_player()->query_name()) + " unwields " +
               lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");
            move_object(weapon[i], this_player());
            weapon[i] = 0;
            ok_flag = 1;
         }
      }
      
      i++;
   }
   if(!ok_flag) write("You have no such weapon strapped.\n");
   else mob->set_weapon_list(weapon);
   
   return 1;
}

multiweapon_mob_short(arg, str) 
{
   object mob,weapon;
   string temp;
   int period_flag,a;
   mob = arg;
   if(!arg) return 0;
   weapon = mob->query_weapon_list();
   temp = "";
   while(a < sizeof(weapon)) 
   {
      if(weapon[a]) 
      {
         temp = temp + (weapon[a]->short()) + " (wielded " + get_type(a) + ").\n";
         period_flag = 1;
      }
      a++;
   }
   temp = temp + str;
   return temp;
}

unstrap_all(arg) 
{
   object person,mob,ob;
   int i;
   person = arg;
   if(!person) return 0;
   mob = present(MORPH_ID, person);
   if(!mob) return 0;
   
   ob = all_inventory(mob);
   for(i = 0; i < sizeof(ob); i ++) 
   {
      if(ob[i]) 
      {
         tell_object(person, "You unstrap " + lower_case(ob[i]->short()) + ".\n");
         person->remote_say((person->query_name()) + " stops wielding " + (ob[i]->query_name()) + " as a " +
            get_type(i) + " weapon.\n");
         move_object(ob[i], person);
         ob[i] = 0;
       }
   }
   mob->set_weapon_list(0);
}

get_type(arg) 
{
   string type;
   int num;
   num = arg;
   if(num == 0) type = "secondary";
   if(num == 1) type = "tertiary";
   if(num == 2) type = "quaternary";
   if(num == 3) type = "pentiary";
   if(num == 4) type = "hexiary";
   if(num == 5) type = "septiary";
   if(num == 6) type = "octiary";
   return type;
}


/* ----emote and say subroutines --- */

mod_say(str) 
{
   object gob;
   string vrb,tmpn,tmpo,tmpp;
   gob = present(GUILD_ID, this_player());
   if(!str || !gob) return 0;
   if(sscanf(str, "%s!", tmpo) == 1) vrb = "exclaim";
   else if(sscanf(str, "%s!!", tmpo) == 1) vrb = "scream";
   else if(sscanf(str, "%s!!!%s", tmpo, tmpp) == 2) vrb = "holler";
   else if(sscanf(str, "%s?", tmpo) == 1) vrb = "ask";
   else if(sscanf(str, "%s?%s", tmpo, tmpp) == 2) vrb = "postulate";
   else vrb = "say";
   
   if(gob->query_current_morph() == "none" || gob->query_current_morph() == "replicant")
      tmpn = (this_player()->query_name()) + " " + vrb + "s: " + str + "\n";
   else
      tmpn = (this_player()->query_name()) + " the " +
   (gob->query_current_morph()) + " " + vrb + "s: " + str + "\n";
   tmpn = format(tmpn, 70);
   this_player()->remote_say(tmpn);
   
   if(this_player()->query_brief()) write("Ok.\n");
   else write("You " + vrb + ": " + str + "\n");
   return 1;
}

mod_emote(str) 
{
   object gob;
   string tmpp;
   gob = present(GUILD_ID, this_player());
   if(!str || !gob) return 0;
   if(gob->query_current_morph() == "none" || gob->query_current_morph() == "replicant")
      tmpp = (this_player()->query_name()) + " " + str + "\n";
   else
      tmpp = (this_player()->query_name()) + " the " +
   
   (gob->query_current_morph()) + " " + str + "\n";
   remote_say(format(tmpp, 70));
   if(this_player()->query_brief()) write("Ok.\n");
   else write(tmpp);
   
   return 1;
}

/* ---- [NEWS READER STUFF] 8< cut here--- */


string news_group;
string messages;
int num_messages;

loadnews() 
{
   if(!restore_object(NEWSFILE)) 
   {
      news_group = allocate(5);
      news_group[0] = "guild.announce";
      news_group[1] = "guild.general";
      news_group[2] = "guild.bugs&ideas";
      news_group[3] = "anything.else";

      /* Last group reserved for hilev guild + */
      news_group[4] = "guild.command";
      
      num_messages = allocate(5);
      messages = allocate(5);
      messages = ({"","","",""});
      save_object(NEWSFILE);
   }
   
}

news_grouplist() 
{
   int i;
   write("You study your lump of clay and some words appear on it:\n"+
      "\n>> Current available groups:\n\n");
   while(i < sizeof(news_group)) {
      if(i == (sizeof(news_group) - 1) && this_player()->query_guild_rank() < GC) break;
      write(" (" + (i + 1) + ")\t[" + news_group[i] + "] (" + num_messages[i] + ") messages.\n");
      i++;
   }
   return 1;
}


news_headers() 
{
   string hd, body, rest;
   int i,indx,tmp;
   i = 1;
   indx = index_number();
   if(!num_messages[indx])
   {
      write("\n>> [" + news_group[indx] + "] is empty.\n");
      return 1;
   }
   rest = messages[indx];
   write("\n>> Postings in group [" + news_group[indx] + "]:\n");
   
   while(rest != 0 && rest != "") 
   {
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      
      if(tmp != 2 && tmp != 3) 
      {
         write("\n>> File corrupted.\n");
         return;
      }
      write(i + ":\t" + hd + "\n");
      i += 1;
   }
   return 1;
   
}

news_read(str) 
{
   string hd, body, rest;
   int i,indx,tmp;
   
   if(str == 0 || sscanf(str, "%d", i) != 1) return 0;
   
   indx = index_number();
   
   if(i > num_messages[indx]) 
   {
      write("\n>> There are only (" + num_messages[indx] +") messages.\n");
      
      return 1;
   }
   
   rest = messages[indx];
   
   while(rest != 0 && rest != "") 
   {
      i -= 1;
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);

      if (tmp != 2 && tmp != 3) 
      {
         write("Corrupt.\n");
         return;
      }

      if (i == 0) 
      {
         write("\n>> The message is titled '" + hd + "':\n\n");
         write(body);
         write(">> End of message (" + str + ").\n");
         return 1;
      }
   }
   write("\n>> Hm. This should not happen.\n");
}

news_delete(str,arg) 
{
   string hd, body, rest;
   int i,indx,tmp;
   if(str == 0 || sscanf(str, "%d", i) != 1) return 0;
   indx = index_number();

   if(i > num_messages[indx]) 
   {
      write(">> There are only [" + num_messages[indx] +"] postings.\n");
      return 1;
   }

   rest = messages[indx];
   messages[indx] = "";
   
   while(rest != 0 && rest != "") 
   {
      i -= 1;
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      if (tmp != 2 && tmp != 3) 
      {
         write("\n>> File corrupted.\n");
         return;
      }

      if (i == 0) 
      {
         if(!arg) write("\n>> Done.\n");
         messages[indx] = messages[indx] + rest;
         num_messages[indx] -= 1;
         save_object(NEWSFILE);
         return 1;
      }
      messages[indx] = messages[indx] + hd + ":\n**\n" + body + "\n**\n";
   }
   write("\n>> Hm. This should not happen.\n");
}


index_number() 
{
   object gob;
   int i;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   i = gob->query_news_index();
   
   if(i >= sizeof(news_group)) 
   {
      i = 0;
      gob->set_news_index(i);
   }
   return i;
   
}

news_next_group() 
{
   object gob;
   int i,max;

   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   i = index_number();
   i++;
   if(i == (sizeof(news_group) - 1) && 
      this_player()->query_guild_rank() < GC) i = 0;
   if(i >= sizeof(news_group)) i = 0;
   gob->set_news_index(i);
   write("\n>> Switching to group [" + news_group[i] + "], (" +
      
      num_messages[i] + ") messages.\n");
   return 1;
}

news_post_check(hd) 
{
   int indx;
   indx = index_number();
   
   if(!hd) 
   {
      write(">> You must give a header.\n");
      return 0;
   }
   
   if(num_messages[indx] == 25) 
   {
      news_delete("1","silent");
      return 1;
   }

   if(strlen(hd) > 55) 
   {
      write("\n>> The header is too long.\n");
      return 0;
   }
   
   write("\n>> Posting to [" + news_group[indx] + "]:\n");
   write(">> Give message, ** to finish, ~q to abort.\n");
   return 1;
}

news_feed(arg,str) 
{
   
   object gob;
   string new_hd;
   int indx;
   indx = index_number();
   gob = present(GUILD_ID, this_player());

   if(this_player()->query_invis() && 
      this_player()->query_real_name() == "mizan")
      new_hd = "[Spuck, " + extract(ctime(time()), 4, 9) + "]  " + arg;
   new_hd = "[" + capitalize(this_player()->query_real_name()) +
   ", " + extract(ctime(time()), 4, 9)+ "]  " + arg;
   
   if(gob && gob->query_sig())
      messages[indx] = messages[indx] + new_hd + ":\n**\n" + str + "\n" +
   (gob->query_sig()) + "\n\n**\n";
   else
      messages[indx] = messages[indx] + new_hd + ":\n**\n" + str + "\n**\n";

   num_messages[indx] += 1;
   save_object(NEWSFILE);
   write("\n>> Message posted.\n");

   if(gob && gob->query_news_announce())
      if(indx != (sizeof(news_group) -1))
   guild_tell(":has completed a news message in [" + news_group[indx] + "].");
   else write("Announce message muffled due to newsgroup type.\n");
   return 1;
}

news_goto_group(arg) 
{
   object gob;
   int i;
   gob = present(GUILD_ID, this_player());
   if(!arg) return 0;
   if(!gob) return 0;
   if(sscanf(arg, "%d", i) != 1) return 0;
   i--;

   if(i < 0 || i > sizeof(news_group)) 
   {
      write(">> Invalid newsgroup number.\n");
      return 1;
   }
   
   if(this_player()->query_guild_rank() < GC &&
         i == (sizeof(news_group) - 1)) 
   {
      write(">> Invalid newsgroup number.\n");
      return 1;
   }
   
   write(">> Going to news group [" + news_group[i] + "], (" + num_messages[i] + ") messages.\n");
   gob->set_news_index(i);
   return 1;
}

news_add_group(str) 
{
   string msgtmp,grptmp;
   int numtmp;
   int i;
   if(!check_level(5)) return 1;

   if(strlen(str) > 30) 
   {
      write(">> That header name is too long. 30 characters or less.\n");
      return 1;
   }
   
   msgtmp = messages;
   numtmp = num_messages;
   grptmp = news_group;
   messages = allocate(sizeof(msgtmp + 1));
   num_messages = allocate(sizeof(numtmp + 1));
   news_group = allocate(sizeof(grptmp + 1));
   while(i < sizeof(messages)) 
   {
      if(i == (sizeof(messages) - 2)) 
      {
         messages[i] = "";
         news_group[i] = str;
         messages[i+1] = msgtmp[i];
         news_group[i+1] = grptmp[i];
         num_messages[i+1] = numtmp[i];
         break;
      }
      else
      {
         messages[i] = msgtmp[i];
         news_group[i] = grptmp[i];
         num_messages[i] = numtmp[i];
      }
      i++;
   }
   write(">> New newsgroup formed.\n");
   guild_tell(": has created a new newsgroup [" + str + "]!\n");
   save_object(NEWSFILE);
   return 1;
}

news_delete_group(str) 
{
   string msgtmp, grptmp;
   string tmp;
   int numtmp, sel, i;
   if(!check_level(5)) return 1;
   if(sscanf(str, "%d", sel) != 1) return 0;
   if(sel == sizeof(news_group)) return 0;

   if(sel < 4) 
   {
      write(">> You cannot delete that newsgroup.\n");
      return 1;
   }

   if(num_messages[sel]) 
   {
      write(">> That newsgroup is not empty!\n");
      return 1;
   }
   msgtmp = messages;
   grptmp = news_group;
   numtmp = num_messages;
   tmp = news_group[(sel - 1)];
   messages = allocate(sizeof(msgtmp - 1));
   news_group = allocate(sizeof(grptmp - 1));
   num_messages = allocate(sizeof(numtmp - 1));
   while(i < sizeof(messages)) 
   {
      if(i == sizeof(messages)) 
      {
         messages[i] = msgtmp[i + 1];
         news_group[i] = grptmp[i + 1];
         num_messages[i] = numtmp[i + 1];
         break;
      }
      else
      {
         messages[i] = msgtmp[i];
         news_group[i] = grptmp[i];
         num_messages[i] = numtmp[i];
      }
      i++;
   }
   write(">> Deletion successful.\n");
   guild_tell(": has deleted newsgroup [" + tmp + "]!\n");
   save_object(NEWSFILE);
   return 1;
}

/* ---- SPDM.c  8< cut here--- */


spuckball_gobble(arg) 
{
   object mob, ob, room;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   room = environment(this_player());
   if(!room) return 0;
   
   ob = present(arg, room);
   
   if(!ob) 
   {
      write("You cringe in bogglement as there is no such item present.\n");
      return 1;
      
   }
   
   if(ob->drop() || !ob->get() || living(ob) || !ob->short()) 
   {
      write("You cannot gobble that, for some reason.\n");
      return 1;
   }
   
   if(!mob->add_weight(ob->query_weight())) 
   {
      write("Oof! You feel rather heavy already. Another item and you would burst.\n");
      return 1;
   }
   
   move_object(ob, mob);
   write("You gobble up " + lower_case(ob->short()) + "!\n");
   write("Yum.\n");
   remote_say((this_player()->query_name()) + " gobbles up " + lower_case(ob->short()) + "!\n");
   mob->burp_routine();
   
   return 1;
}

spuckball_spew(arg) 
{
   object mob, ob, room;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   room = environment(this_player());
   if(!room) return 0;
   ob = present(arg, mob);

   if(!ob) 
   {
      write("Funny, you don't remember gobbling up that item.\n");
      return 1;
   }
   
   mob->add_weight(-(ob->query_weight()));
   move_object(ob, room);
   write("You spew up " + lower_case(ob->short()) + "!\n");
   write("Ick.\n");
   
   remote_say((this_player()->query_name()) + 
      " spews up " + lower_case(ob->short()) + "!\n");
   remote_say("It is covered in a thin layer of slimy goo. Ick.\n");
   return 1;
}

spuckball_squit(arg) 
{
   single_attack(SPUCKBALL_SQUIT_COST,arg,
      "You squit "," painfully up against a wall.",
      (this_player()->query_name()) + " squits "," painfully against a wall.");
   return 1;
}

/* ---- WOMBAT SPELLS --- */

wombat_sniff(str) 
{
   object ob;
   int i;
   if(!str) return 0;
   ob = present(str, environment(this_player()));

   if(!ob) 
   {
      write("There is no '" + str + "' here.\n");
      return 1;
   }

   if(!living(ob)) 
   {
      write((ob->short()) + " smells just like a " + str + ".\n");
      return 1;
   }

   write((ob->query_name()) + " ");
   i = ob->query_alignment();
   
   /* now chain eval the alignment */
   if(i > 750) 
      write("smells like a bar of Ivory soap. Mmmm! 99 44/100% Pure!\n");
   if(i > 500 && i < 751)
      write("smells like a new air freshener. Pretty Good.\n");
   if(i > 250 && i < 501)
      write("smells like freshly done landry. It's okay.\n");
   if(i > 50 && i < 251)
      write("smells pretty nice.\n");
   if(i > 0 && i < 51)
      write("smells okay.\n");
   if(i == 0) 
      write("has no detectable odor.\n");
   if(i > -50 && i < 0)
      write("smells somewhat okay, with a touch of nastiness.\n");
   if(i > -250 && i < -51)
      write("smells pretty grimy and generally unpleasant.\n");
   if(i > -500 && i < -251)
      write("carries a pretty heinous odor. Live in fear!\n");
   if(i > -750 && i < -501)
      write("bears evil like the foul stench of a decomposing tunafish.\n");
   if(i < -749)
      write("utterly reeks of evil, like a sewage treatment facility.\n");
   
   remote_say((this_player()->query_name()) + 
      " sniffs " + (ob->query_name()) + " carefully.\n");
   tell_object(ob, (this_player()->query_name()) + 
      " sniffs you from head to toe.\n");
   return 1;
}

wombat_dig() 
{
   object burrow,burrow_entrance,mob,room;
   if(check_dead()) return 1;
   if(!check_sp(WOMBAT_BURROW_COST)) return 1;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   
   burrow = mob->query_burrow();
   
   if(!burrow) 
   {
      burrow=clone_object(WOMBAT_BURROW);
      burrow->set_owner(this_player()->query_real_name());
      mob->set_burrow(burrow);
   }

   room = environment(this_player());
   if(!room) return 0;
   
   if(room->query_realm() == "NT") 
   {
      write("Something in this room is preventing you from digging a tunnel.\n");
      remote_say((this_player()->query_name()) + " chomps on some dirt.\n");
      return 1;
   }
   
   this_player()->add_spell_point(-WOMBAT_BURROW_COST);
   if(this_player()->query_attack() && 
      random(this_player()->query_attrib("ste")) < 5) 
   {
      write("You are too busy fighting!\n");
      return 1;
   }

   if(!present("burrow", environment(this_player()))) 
   {
      burrow_entrance=clone_object(WOMBAT_BURROW_ENTRANCE);
      burrow_entrance->set_owner(this_player()->query_real_name());
      move_object(burrow_entrance, environment(this_player()));
   }
   
   write("You begin digging furiously and arrive in your comfortable burrow.\n");
   remote_say((this_player()->query_name()) + " begins digging furiously and when the dust settles, disappears.\n");
   move_object(this_player(), burrow);
   remote_say((this_player()->query_name()) + " tumbles in.\n");
   command("look", this_player());
   return 1;
}

/* ---- WOMBAT DRAG --- */

wombat_drag(str)
{
   object old_drag_ob,drag_ob,mob,testobj;
   mob = present(MORPH_ID, this_player());

   if(!mob) return 0;
   if(check_dead()) return 1;
   old_drag_ob = mob->query_drag_ob();
   
   if(old_drag_ob) 
   {
      write("You stop dragging " +
         lower_case(old_drag_ob->short()) + ".\n");
      remote_say((this_player()->query_name()) + 
         " stops dragging " + lower_case(old_drag_ob->short()) + ".\n");
      
      mob->set_drag_ob(0);
      testobj = present(LOOSEN_ID, old_drag_ob);
      if(testobj) destruct(testobj);
      if(!str) return 1;
   }
   
   drag_ob = present(str, environment(this_player()));
   
   if(!drag_ob) 
   {
      write("There is no such object here.\n");
      return 1;
   }

   if(drag_ob == this_player()) 
   {
      write("You pick yourself up by the rump and fall to the floor.\n");
      return 1;
   }
   
   if(!drag_ob->get()) 
   {
      write("You can't drag that.\n");
      return 1;
   }
   
   write("You are now dragging " + lower_case(drag_ob->short()) + ".\n");
   remote_say((this_player()->query_name()) + " begins dragging " + lower_case(drag_ob->short()) + ".\n");
   mob->set_drag_ob(drag_ob);
   return 1;
}

wombat_forage() 
{
   if(!check_sp(WOMBAT_FORAGE_COST)) return 1;
   
   write("You dig the surrounding area furiously and find a potato!\n");
   remote_say((this_player()->query_name()) + 
      " digs a hole carefully and finds a potato!\n");

   move_object(clone_object("players/mizan/etheriel/heals/raw-potato"), this_player());

   this_player()->add_spell_point(-WOMBAT_FORAGE_COST);
   return 1;
}

wombat_chomp(arg) {
   single_attack(WOMBAT_CHOMP_COST,arg,
      
      "You bare your teeth and viciously take chomp ","!",
      (this_player()->query_name()) + " chomps ", " and bites off some of its flesh!");
   return 1;
}

/*
 * KWIJIBO abilities
 *
 */

kwijibo_wigout()
{

}

kwijibo_consume()
{
}

kwijibo_vegetate()
{
}

kwijibo_jiggle()
{
}


/* ---- SPONGE spells [3]--- */

sponge_sponge(arg) 
{
   object ob,atk;
   ob = get_living(arg);
   if(!ob) return 1;
   atk = ob->query_attack();
   
   if(!atk) 
   {
      write((ob->query_name()) + " is not fighting anything.\n");
      return 1;
   }
   
   write("You are now sponging hits for " + (ob->query_name()) + ".\n");
   remote_say((this_player()->query_name()) +
      " slowly waddles in the way and starts sponging hits for " + (ob->query_name()) + ".\n");
   atk->attack_object(this_player());
   this_player()->attack_object(0);
   return 1;
}

/* ---- BLOBEL spells [3]--- */

blobel_deepsurvey_area() 
{
   object room,temproom;
   string exits,tempg,temph,tempi;
   int i;

   if(check_dead()) return 1;
   if(!check_sp(BLOBEL_DEEPSURVEY_COST)) return 1;
   
   room = environment(this_player());
   exits = room->query_dest_dir();
   if(!exits) 
   {
      write("For some reason, you cannot deep survey this area.\n");
      return 1;
   }

   this_player()->add_spell_point(-BLOBEL_DEEPSURVEY_COST);

   if(room->realm() == "NT" && 1 == random(3 + this_player()->query_guild_rank())) 
   {
      write("You attempt to deep survey the area, but are suddenly distracted, and fail.\n");
      return 1;
   }

   write("You peer about intently.\n\n");
   remote_say((this_player()->query_name()) + " deep surveys the area carefully.\n");

   temph = environment(this_player())->short();
   
   if(temph && sscanf(temph, "Plane of Etherie%s", tempi) == 1) 
   {
      /* we are inside the jello */
      while(i < sizeof(exits)) 
      {
         temproom = find_object("/players/mizan/etheriel/ROOMS/" + exits[i]);
         if(temproom) 
         {
            tempg = blobel_dump_inventory(temproom);
            if(tempg) write("Scanning " + exits[i] + " you find:\n" + tempg);
            else write("Scanning " + exits[i] + " find nothing.\n");
         }
         else write("Scanning towards " + exits[i] + " you find it is unexplored.\n");
         i++;
      }
      return 1;
   } else {
      /* we are elsewhere */
      i = 1;
      while(i < sizeof(exits)) 
      {
         temproom = find_object(exits[i-1]);
         if(temproom) 
         {
            tempg = blobel_dump_inventory(temproom);
            
            if(tempg) write("Looking " + exits[i] + " you find:\n" + tempg);
            else write("Looking " + exits[i] + " find nothing.\n");
            }
         else write("Looking " + exits[i] + " you find it is unexplored.\n");
         i = i + 2;
        }
      return 1;
   }
}

/* used by above */

static blobel_dump_inventory(arg) 
{
   object ob;
   string tempj;
   int lim;
   tempj = "";
   ob = first_inventory(arg);
   
   while(ob) 
   {
      object oc;
      object od;

      oc = ob;
      ob = next_inventory(ob);
      if(oc->short())
      {
         tempj += tempj + "\t" + (oc->short()) + " ";
         if(living(oc))
         {
            tempj += "[" + (oc->query_hp() * 10) / oc->query_mhp() + "/10]HP ";
            od = oc->query_attack();
            if(od)
               tempj += "Attacking: " + od->query_name();
         }

         tempj += "\n";         
      }
      
      lim ++;
      if(lim > 11)
      {
         tempj = tempj + "\t[TRUNCATED]\n";
         break;
      }
   }
   return tempj;
}

/**
 * This sends an object into the guild room.
 *
 */
blobel_tuck(arg)
{
   object ob;
   ob = present(arg, this_player());
   if(!ob)
   {
      /* they dont have the object. */
      write("You have no such item.\n");
      return 1;
   }

   if(!check_sp(BLOBEL_TUCK_COST)) return 1;

   /* ok tell em what happened */
   write("You open a fold to Destination linna, Plane of Etheriel.\n");
   write(ob->short() + " is tucked into the fold and disappears.\n");

   say(this_player()->query_name() + " opens a fold to somewhere in the Plane of Etheriel.\n");

   say(ob->short() + " is tucked into the fold and disappears.\n");

   this_player()->add_spell_point(-BLOBEL_TUCK_COST);

   this_player()->add_weight(-ob->query_weight());
   move_object(ob, HOME);
   tell_room(HOME, ob->short() + " suddenly materializes.\n");
   return 1;

}

/**
 * Attack spell.
 */
blobel_confusion(arg) 
{
   single_attack(BLOBEL_CONFUSION_COST,arg,
      "You focus a bewildernoggling array of confusion and mentally assault ",".",
      (this_player()->query_name()) + " mentally fuzzles "," and leaves it a crying, whimpering mess.");
   return 1;
}

blobel_unfrog(arg) 
{
   object ob;
   
   if(!check_sp(BLOBEL_UNFROG_COST)) return 1;
   if(!arg) ob = this_player();
   else ob = get_living(arg,"player");
   if(!ob) return 1;
   if(!ob->query_frog()) {
      write((ob->query_name()) + " is not a frog.\n");
      
      return 1;
   }
   
   this_player()->add_spell_point(-BLOBEL_UNFROG_COST);
   write("You concentrate and attempt to alter polymorph the frog curse.\n");
   remote_say((this_player()->query_name()) + " goes into a deep lapse and general stupor.\n");
   
   ob->frog_curse();
   return 1;
}

/* ---- FUNGOID spells [3]--- */

fungoid_gribble(arg) 
{
   single_attack(FUNGOID_GRIBBLE_COST,arg,
      "You gribble wildly at "," and pause in secret delight watching it suffer.",
      (this_player()->query_name()) + " gribbles violently at ","!");
   return 1;
}

fungoid_puff(arg) 
{
   single_attack(FUNGOID_PUFF_COST,arg,
      "You puff a poisonous spore at ",".",
      
      (this_player()->query_name()) + " zoks "," with a poisonous spore!");
   return 1;
}

fungoid_spog(arg) 
{
   single_attack(FUNGOID_SPOG_COST,arg,
      "You detach a highly infectious viral spog at ","!",
      (this_player()->query_name()) + " detaches an infectious spog at "," with lethal accuracy!");
   return 1;
}


fungoid_spore(arg) 
{
   area_attack(60,arg,"You wiggle excitedly and eject a cloud of poisonous spores!\n",
      "ejects a cloud of poisonous spores!\n",
      "choke violently on the cloud!\n",
      "chokes violently on the cloud!\n",
      "flee in panic from the cloud!\n",
      "flees in panic from the cloud!\n",
      "escapes harm for some reason.\n",
      "seems unaffected by the cloud.\n",
      "The cloud fades and thins out from view.\n",
      "grins evilly.\n",
      "You try to eject some spores but nothing happens.\n",
      "wiggles excitedly but nothing happens.\n");
   
   return 1;
}

/* ---- PUFFBALL spells [4]--- */

puffball_fry(arg) 
{
   single_attack(PUFFBALL_FRY_COST,arg,
      "You belch a few billion amperes of electricity at ",".",
      (this_player()->query_name()) + " makes a Crispy "," with a few billion amperes of electricity!");
   return 1;
}

puffball_vaporize(arg) 
{
   single_attack(PUFFBALL_VAPORIZE_COST,arg,
      "With great effort and concentration,\nyou vector a matter detonation at ",".",
      (this_player()->query_name()) + " vectors a nuclear matter detonation at ",
      "!\nImagine a cigarette lighter exploding in your face. Ouch!");
   return 1;
}

puffball_nova(arg) 
{
   area_attack(200,arg,
      "You concentrate with all your might and every single particle\n"+
      "nearby you converts to pure energy (e = mc^2)!\n",
      "explodes in a blinding flash!\n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n",
      
      "is struck head-on by a few trillion watts of energy. Fearsome.\n",
      "is reduced to a carbon cinder by the blast!\n",
      "blasted clear across the room!\n",
      "is blasted clear across the room!\n",
      "escapes harm for some reason.\n",
      "hits the dirt and escapes harm.\n",
      "You struggle but reform back into your current polymorph.\n",
      "fades into view.\n",
      "You goof, and time your explosion incorrectly. No one is affected.\n",
      "suddenly energizes but fades away just as quickly. It looked painful.\n");
   return 1;
   
}


puffball_gain(str) 
{
   int testh;
   if(sscanf(str, "hp %d", testh) == 1) {
      if(testh < 1 || testh > 1000) return 0;
      if(testh > this_player()->query_sp()) {
         write("You only have [" + this_player()->query_sp() + "] spell points.\n");
         return 1;
      }
      this_player()->add_spell_point(-testh);
      this_player()->add_hit_point(testh);
      write("You transfer [" + testh + "] units of energy for hitpoint gain.\n");
      return 1;
   }
   if(sscanf(str, "sp %d", testh) == 1) {
      if(testh < 1 || testh > 1000) return 0;
      if(testh > this_player()->query_hp()) {
         write("You only have [" + this_player()->query_hp() + "] hitpoints.\n");
         return 1;
         
      }
      if(this_player()->query_hp() - testh < 20) {
         write("Somehow, you cannot bring yourself to do this.\n");
         return 1;
      }
      this_player()->add_hit_point(-testh);
      this_player()->add_spell_point(testh);
      write("You transfer [" + testh + "] units of energy for spell point gain.\n");
      return 1;
   }
   
   write("Usage: 'gain hp <X>' to transfer <X> spell points to hitpoints.\n"+
      "\t'gain sp <X>' to transfer <X> hitpoints to spell points.\n");
   return 1;
}


puffball_finish() 
{
   object ob;
   
   int x;
   ob = this_player()->query_attack();
   
   if(!ob) 
   {
      write("You must be fighting something first.\n");
      return 1;
   }
   
   if(ob->is_player()) 
   {
      write("You cannot use this ability against other players.\n");
      return 1;
   }

   /* Make it so spell can only be used if monster is weaker than 10% */
   x = (ob->query_hp() * 100) / ob->query_mhp();
   
   if(x > 10) 
   {
      write((ob->query_name()) + " needs to be weakened somewhat more.\n");
      return 1;
   }
   /* 65 hps the the most damage the spell can do... with player at glev 5 */
   if((25 + (this_player()->query_guild_rank() * 8)) < ob->query_hp()) 
   {
      write((ob->query_name()) + " is still too strong.\n");
      return 1;
   }
   
   if(!check_sp((ob->query_hp()))) return 1;
   
   this_player()->add_spell_point(-(ob->query_hp()));
      
   /* Chance of failure dependent on willpower. */
   
   if(1 == random(this_player()->query_attrib("wil"))) 
   {
      write("Ack! You somehow screw up and the energy gathered explodes in your face!\n");
      remote_say((this_player()->query_name()) + " begins to glow brightly but suddenly implodes!\n");
      remote_say("\n* * B O O M  ! ! ! * * * \n\nYou curse violently.\n");
      return 1;
   }
   write("With a daring lunge, you convert most of your puffball mass into pure\n"+
      "energy to strike a finishing shot to " + (ob->query_name()) + ".\n");
   remote_say((this_player()->query_name()) + " begins to glow brightly and explodes at " + (ob->query_name()) + "!\n");
   remote_say((ob->query_name()) + " is struck by a critically hitting blast!\n"); 
   remote_say((this_player()->query_name()) + " triumphantly strikes down " + (ob->query_name()) + ".\n");

   hit_creature(this_player(), ob, (ob->query_hp()));
   return 1;
}

/* ---- SHOUTBOX spells [4]--- */

shoutbox_bellow(arg) 
{
   area_attack(100,arg,
      "You take a deep breath...\n"+
      "Your lungs stretch like a weather baloon and then you release!\n"+
      "You bellow: aaAAAAAAAAAUUUUUUUUUGGGGGGHHHH!!!!!!\n",
      "takes a DEEP breath and HOLLERS at everyone in the room!\n",
      "get torn apart by the thundering bass. Neato!\n",
      "is torn apart by the thundering bass!\n",
      "flung across the room by the deafening noise!\n",
      "is flung across the room by the deafening noise!\n",
      "flattened by the sound but emerges unscathed.\n",
      "is flattened by the sound but emerges unscathed.\n",
      "You take a few deep breaths to recover.\n",
      "takes a few deep breaths to recover.\n",
      "Your throat is too dry and the spell fails.\n",
      "takes a DEEP breath and tries to scream loudly but snarfs and sputters.\n");
   return 1;
}

shoutbox_shrill(arg) 
{
   single_attack(SHOUTBOX_SHRILL_COST,arg,
      "You emit a screeching, ultrahigh frequency yowl at ","!",
      (this_player()->query_name()) + " emits a sound about as unpleasant as fingernails being\n"+
      "dragged across a chalkboard! AAaaaauuugh!\n"," screams and grasps its ears in rabid pain!");
   return 1;
}

shoutbox_curse(arg) 
{
   string lang;
   int i;
   i=random(8);
   if(i == 1) lang = "broken swahili";
   if(i == 2) lang = "icelandic";
   if(i == 3) lang = "swedish";
   if(i == 4) lang = "arabic";
   if(i == 5) lang = "greek";
   if(i == 6) lang = "yiddish";
   if(i == 7) lang = "german";
   if(i == 8) lang = "japanese";
 
   single_attack(SHOUTBOX_CURSE_COST,arg,
      "You swear and curse profusely in " + lang + " at ",".",
      (this_player()->query_name()) + " utterly insults "," in " + lang +
      " to the point that it begins to sulk and whine piteously!");
   return 1;
}

shoutbox_superblink(arg) 
{
   single_attack(SHOUTBOX_SUPERBLINK_COST,arg,
      "You blink loudly.\n"," is dealt a devastating blow and winces in pain!.",
      (this_player()->query_name()) + " blinks loudly at ",
      " and it suddenly is taken aback by the shock!\n\t*  *  *  B  O  O  M  !  !  !  *  *\n");
   return 1;
}

shoutbox_reverb(arg) 
{
   single_attack(SHOUTBOX_REVERB_COST,arg,
      "You channel a painful reverb directly at ","!",
      (this_player()->query_name()) + " channels a painful reverb at ",
      " and it is ripped inside out from the whippingly painful sound!\n");
   return 1;
   
}

shoutbox_holler(arg) 
{
   object ob;
   if(!check_sp(SHOUTBOX_HOLLER_COST)) return 1;
   
   if(this_player()->query_attack()) 
   {
      write("You are too busy fighting to do this.\n");
      return 1;
   }
   
   ob = get_living(arg);
   if(!ob) return 1;
   this_player()->add_spell_point(-SHOUTBOX_HOLLER_COST);
   
   write("You holler loudly at " + (ob->query_name()) + "!\n");
   remote_say((this_player()->query_name()) + " hollers loudly at " + (ob->query_name()) + "!\n");
   if(1 == random(this_player()->query_attrib("wil"))) return 1;

   if(ob->query_level() < this_player()->query_level()) 
   {
      remote_say((ob->query_name()) + " flees in panic!\n");
      ob->run_away();
   }
   else 
   {
      remote_say((ob->query_name()) + " is rather annoyed.\n");
      if(ob->query_npc()) ob->attack_object(this_player());
      
   }
   return 1;
}

shoutbox_calm() 
{
   object ob;
   if(!check_sp(SHOUTBOX_CALM_COST)) return 1;
   write("You scream: 'S T O P   F I G H T I N G ! !' at the top your lungs...\n");
   remote_say((this_player()->query_name()) + " hollers: S T O P   F I G H T I N G ! !\n");
   
   this_player()->add_spell_point(-SHOUTBOX_CALM_COST);
   if(1 == random(this_player()->query_attrib("wil"))) return 1;
   ob = first_inventory(environment(this_player()));
   while(ob) 
   {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      oc->attack_object();
      oc->attack_object();
      oc->stop_fight();
      oc->stop_fight();
      oc->stop_hunter();
      oc->stop_hunter();
   }
   
   write("That felt dandy, did'nt it?\n");
   remote_say((this_player()->query_name()) + " does the disco duck.\n");
   return 1;
   
}

/* ---- BOGGLEMANCER spells [5]--- */

bogglemancer_speedball(arg) 
{
   single_attack(BOG_SPEEDBALL_COST,arg,
      "You create a huge fuzzy speedball and charge it up with electricity.\n"+
      "With the flick of the wrist you deftly hurl it at",".",
      (this_player()->query_name()) + " blasts ",
      " with a giant speedball of supercharged dryer lint!\nZZzzzZZzzZzzZZzZzzzZZAAAPPP!!!\n\n");
   return 1;
}

bogglemancer_zokwave(arg) 
{
   single_attack(BOG_ZOKWAVE_COST,arg,
      "You unleash some happy radiation at the general direction of ","!",
      (this_player()->query_name()) + " unleases a fearsome barrage of funky new radioactive particles.\n",
      " seems to melt and crackle in a Spuck-like way.");
   return 1;
}

bogglemancer_charbroil(arg) {
   
   single_attack(BOG_CHARBROIL_COST,arg,
      "Fearsome tongues of flame erupt around you as you superheat the air surrounding ",".",
      (this_player()->query_name()) + " lights the air surrounding ",
      " aflame\nand sets cooks it to a medium-rare crisp!\n" + (this_player()->query_name()) + " giggles inanely.");
   return 1;
}

bogglemancer_sandbag(arg) 
{
   single_attack(BOG_SANDBAG_COST,arg,
      "With great effort you create a heavy bag of sand and hurl it at ","!",
      "A heavy bag of sand drops from the sky and whacks "," silly!");
   return 1;
}

bogglemancer_tree(arg) 
{
   single_attack(BOG_TREE_COST,arg,
      "You create a tree and stuff it into a convenient orifice on ",".",
      (this_player()->query_name()) + " creates a tree and shoves it painfully somewhere into ",
      " !\nYou cringe at the sight.");
   return 1;
}

bogglemancer_lint(arg) 
{
   single_attack(BOG_LINT_COST,arg,
      "You force a wad of dryer lint down ","'s throat!",
      (this_player()->query_name()) + " shoves a thick wad of dryer lint down ","'s throat!");
   
   return 1;
}

bogglemancer_piano(arg) 
{
   single_attack(BOG_PIANO_COST,arg,
      "Principles of Painless distraction take over fully, and a grand piano\n"+
      "materializes, falling out of the sky only to crash into ","!",
      "A grand piano pops out of nowhere and comes crashing down onto ",".\nThat looked stupidly painful. Eep.");
   return 1;
   
}

bogglemancer_anvil(arg) 
{
   single_attack(BOG_ANVIL_COST,arg,
      "An anvil falls from the sky and comes crashing down on ",".",
      "You boggle bemusedly as an anvil suddenly falls from the sky on ",".");
   return 1;
}

/* ---- TETRAPOD SPELLS [5] --- */

tetrapod_raar(str) 
{
   object mob;
   int mhp,hp,sp,i,j;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   hp = this_player()->query_hp();
   sp = this_player()->query_sp();
   mhp = this_player()->query_mhp();

   if(hp == mhp) 
   {
      write("You raar loudly but nothing happens.\n");
      return 1;
   }
   
   if(!str) i = (sp / 2);
   else if(sscanf(str, "%d", i) !=1) return 0;
   j = i * 2;
   if(!check_sp(j)) return 1;
   this_player()->add_spell_point(-j);
   this_player()->add_hit_point(i);
   write("You deep dig down and revitalize yourself with a burst of explosive energy!\n"+
      ESC + "[1m" + ESC + "[31m" + "You go: 'RAAAAAR!'\n" + ESC + "[0m");
    remote_say(ESC + "[1m" + ESC + "[31m" +
      (this_player()->query_name()) + " goes: 'RAAAAAAR!'\n"+
      ESC + "[0m" + (this_player()->query_name()) + " suddenly appears revitalized!\n");
   return 1;
}

tetrapod_blitz(arg) 
{
   /* Gain an extra attack on monsters */
   int i, temp, wtemp;
   object ob, mob, victim, weapon;

   if(!check_sp(TETRAPOD_BLITZ_COST)) return 1;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   
   if(!arg)
      victim = this_player()->query_attack();
   else 
   {
      victim = get_living(arg);
      if(!this_player()->valid_attack(victim)) return 1;
      
      /* not kosher for pk */
      if(victim->is_player()) 
      {
         write("You cannot use this ability against other players.\n");
         return 1;
      }
   }
   
   if(!victim) 
   {
      write("Blitz who?\n");
      return 1;
   }
   
   /* a double-double check! */
   if(victim->is_player()) 
   {
      write("You fail.\n");
      return 1;
   }

   weapon = mob->query_weapon_list();
   write("You explode into a furious frenzy!\n");
   remote_say((this_player()->query_name()) + " breaks into an uncontrollable fury!\n");
   
   while(i < sizeof(weapon)) 
   {
      if(1 == random(3)) write("You scream loudly!\n");
      else if(1 == random(3)) write("You attack with a god-like fury!\n");
      else write("You descend upon your foe with a fearsome wrath!\n");
      
      if(weapon[i]) 
      {
         wtemp = (2 * weapon[i]->weapon_class());
         extra_hit(wtemp , i, victim);
         temp += wtemp;
      }

      if(weapon[i] && 1 == random(2))
      {
         wtemp = weapon[i]->weapon_class();
         extra_hit(wtemp, i,victim);
         temp += wtemp;
      }
      i++;
   }

   hit_creature(this_player(), victim, temp);

   this_player()->add_spell_point(-TETRAPOD_BLITZ_COST);
   remote_say("You cringe in terror.\n");
   write("You feel spent, but are gleeful at the pain and damage you have caused.\n");
   
   remote_say((this_player()->query_name()) + " begins panting heavily, and says: 'Wicked'.\n");
   return 1;
}

/* ---- SPUCKTROOPER SPELLS [5] --- */

spucktrooper_gobble(arg) 
{
   object mob, ob, room;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   room = environment(this_player());
   if(!room) return 0;
   
   ob = present(arg, room);

   if(!ob) 
   {
      write("You cringe in bogglement as there is no such item present.\n");
      return 1;
   }

   if(ob->drop() || !ob->get() || living(ob) || !ob->short()) 
   {
      write("You try diligently to gobble that object, but fail.\n");
      return 1;
   }
   
   if(!mob->add_weight(ob->query_weight())) 
   {
      write("Oof! You feel rather heavy already. Another item and you would burst.\n");
      return 1;
   }
   move_object(ob, mob);
   write("You gobble up " + lower_case(ob->short()) + "!\n");
   write("Yum.\n");
   remote_say((this_player()->query_name()) + " gobbles up " + lower_case(ob->short()) + "!\n");
   mob->burp_routine();
   
   return 1;
}

spucktrooper_spew(arg) 
{
   object mob, ob, room;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   room = environment(this_player());
   if(!room) return 0;
   ob = present(arg, mob);

   if(!ob) 
   {
      write("Funny, you don't remember gobbling up that item.\n");
      return 1;
   }
   
   mob->add_weight(-(ob->query_weight()));
   move_object(ob, room);
   write("You spew up " + lower_case(ob->short()) + "!\n");
   write("Ick.\n");
   remote_say((this_player()->query_name()) + " spews up " + lower_case(ob->short()) + "!\n");
   remote_say("It is covered in a thick layer of slimy goo. Ick.\n");
   return 1;
}

spucktrooper_hwarf(arg) 
{
   object mob, ob, beast;
   int dam;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   beast = this_player()->query_attack();
   
   if(!beast) 
   {
	  write("You have to be fighting something first.\n");
	  return 1;
   }
   
   ob = present(arg, mob);
   
   if(!ob) 
   {
      write("Funny, you don't remember gobbling up that item.\n");
      return 1;
   }
   
   dam = (ob->query_value() / 60);
   if(dam > DAMAGE_CAP) dam = DAMAGE_CAP;

   if(!check_sp(dam)) return 1;
   
   mob->add_weight(-(ob->query_weight()));
   single_attack(dam, (beast->query_name()),
      "You hwarf up " + lower_case(ob->short()) + " and it goes rocketing through the air, smashing ", " silly!",
	  (this_player()->query_name()) + " hwarfs up " + lower_case(ob->short()) + " and it goes rocketing through the air, smashing ",
	  " into a dizzy stupor!");

   destruct(ob);
   return 1;
}

spucktrooper_squit(arg) 
{
   single_attack(SPUCKTROOPER_SQUIT_COST,arg,
      "You SQUIT "," painfully up against a wall.",
      (this_player()->query_name()) + " squits "," painfully through a wall.");
   return 1;
}

spucktrooper_bletch(arg) 
{
   area_attack(130,arg,
      "With great focus, you expunge all of the spod that has been building inside you...\n",
      "detonates in a greasyg flash!\n"+
      "\nDuck! Incoming wave of...SPAM!\n\n",
      "is pelted in the head by molten glop of Spam [tm].\n",
      "is left a searing, smouldering mess by the wave of funky Spam[tm]!\n",
      "thrown clear across the room!\n",
      "is thrown wickedly across the room!\n",
      "ducks and escapes bodily harm.\n",
      "ducks just in time to escape bodily harm.\n",
      "You burp loudly.\n",
      "burps loudly, hocking phlegm and loogies all over the place.\n",
      "Frock! Nothing happened!\n",
      "sweels up violently, suddenly, but then quickly fades.\n");
   return 1;
   
}

/* ---- MIMIC SPELLS [5] --- */

mimic_mimic(str)
{
   object mob;
   object ob,oc;
   
   mob = present(MORPH_ID, this_player());
   if(!mob || !str) return 0;

   if(!check_sp(MIMIC_MIMIC_COST)) return 1;

   ob = environment(this_player());
   if(!ob || !ob->is_puffer()) return 0;

   oc = present(str, ob);
   if(!oc || oc->query_invis() > 18)
   {
      write("There is no '" + str + "' here.\n");
      return 0;
   }

   if(!oc->short())
   {
      write("That is an invisible object!\n");
      return 1;
   }

   write("You copy the features of " + oc->query_name() + " onto that of your own.\n");

   if(living(oc))
   {
      /* living object */
      ob->set_name(oc->query_name());
      ob->set_race(oc->query_race());
      ob->set_short(oc->short());
   }
   else
   {
      ob->set_name(str);
      ob->set_race(str);
      ob->set_short(oc->short());
      /* non-living object */
   }

   this_player()->add_spell_point(-MIMIC_MIMIC_COST);

   return 1;
}


/* ---- SPIRAL SPELLS [6] --- */

spiral_xpower() 
{
  
   /* Enhanced attack per round, uses all sps */
   object mob,victim;
   int pot_dam;
   pot_dam = this_player()->query_msp();
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   if(!check_sp(pot_dam)) return 1;
   victim = this_player()->query_attack();
   
   if(!victim) 
   {
      write("You must be fighting something first.\n");
      return 1;
   }
   
   if(victim->is_player()) 
   {
      write("You cannot use this ability against other players.\n");
      return 1;
   }
   /* Charges the MOB for a certain amt of attacks */
   mob->charge_spiral_xpower(pot_dam / 60);
   this_player()->add_spell_point(-pot_dam);
   write("Zzzzzaaaap! Every spellpoint converts into a blinding burst\n"+
      "of explosive, crackling energy...\nYou throw your head back and cackle gleefully!\n");
   
   write("You explode into a headstrong, all out attack on " + (victim->query_name()) + "!\n");
   remote_say((this_player()->query_name()) + " is suddenly enveloped in a blinding, deafening flash!\n\n");
   remote_say((this_player()->query_name()) + " bursts into a rhythmic frenzy and all out assault on " +
      
      (victim->query_name()) + "!\n");
   return 1;
}

spiral_switch(arg) 
{
   /* Switch places with another player attacking something */
   
   object ob, victim;
   if(!check_sp(SPIRAL_SWITCH_COST)) return 1;
   ob = present(arg, environment(this_player()));
   if(!ob) return 0;
 
   if(!living(ob)) 
   {
      write("You boggle in discontent.\n");
      return 1;
   }
   
   victim = ob->query_attack();
   
   if(!victim) 
   {
      write((ob->query_name()) + " is not fighting anything!\n");
      return 1;
   }
   
   if(!this_player()->valid_attack(victim)) return 1;
   write("You switch phases with " + (ob->query_name()) + "!\n");
   remote_say((this_player()->query_name()) + " begins a strange dance and bodies switch around.\n");
   
   ob->stop_fight();
   ob->stop_fight();
   ob->stop_hunter();
   ob->stop_hunter();
   
   this_player()->attack_object(victim);
   victim->attack_object(this_player());
   this_player()->add_spell_point(-SPIRAL_SWITCH_COST);
   return 1;
}

spiral_swords(arg) 
{
   /* Turn weapons into missile objects */
   object junk,mob,victim;
   int i;
   mob = present(MORPH_ID, this_player());
   
   junk = arg;
   if(!mob) return 0;
   
   if(!junk) 
   {
      write("You don't have any weapons strapped!\n");
      return 1;
   }
   victim = this_player()->query_attack();

   if(!victim) 
   {
      write("You are not fighting anything!\n");
      return 1;
   }
   
   if(victim->is_player()) 
   {
      write("You cannot use this ability against other players.\n");
      return 1;
   }
   
   /* Begin attack */
   write("You release your strapped weapons as missiles against " +
      (victim->query_name()) + "!\n");
   
   remote_say((this_player()->query_name()) + 
      " utters a short mantra... 'Dancing Swords!'\n");

   while(i < sizeof(junk)) 
   {
      object ob;
      int dam;
      /* Cycle through elements of array */
      ob = junk[i];
      if(ob) 
      {
         dam = ob->query_value();
         if(dam) 
         {
            dam = dam / 60;
            if(dam > DAMAGE_CAP) dam = DAMAGE_CAP;
            /* Treat each attack as a separately cast spell */
            single_attack(dam,victim,
               (ob->short()) + " phases into a dancing sword and launches itself at ","!",
               (ob->short()) + " turns into a dancing sword and launches itself at ","!");

         }
         else 
         {
            write((ob->short()) + " bounces harmlessly from " + (victim->query_name()) + ".\n");
            remote_say("A dancing sword bounces harmlessly away from " + (victim->query_name()) + ".\n");
         }
         
         /* Recalc weight & destruct */
         /*
         this_player()->add_weight(-(ob->query_weight()));
          */
            destruct(ob);
            junk[i] = 0;

         }
      i++; 
   }

   remote_say((this_player()->query_name()) + " smiles wickedly.\n");
   mob->set_weapon_list(junk);
   return 1;
}

spiral_multihit() 
{
   /* Attacks everything in the room once with each limb */
   object mob,weapon,ob,room;
   int i;
   int dam;
   if(!check_sp(SPIRAL_MULTIHIT_COST)) return 1;
   
   
   room = environment(this_player());
   mob = present(MORPH_ID, this_player());
   if(!room || !mob) return 0;
   weapon = mob->query_weapon_list();
   ob = first_inventory(room);
   
   /* Begin cycling attacks now... */
   write("You eye everything living in the room intently.\n");
   remote_say((this_player()->query_name()) +
      " sizes up everything living in the current room.\n");

   if(count_livings() < 6)
      write("You don't see enough visible targets to make the most of this attack.\n");
   
   while(ob) 
   {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      if(living(oc)) 
      {
         if(oc->is_pet() || oc->is_kid() || oc->is_player()) 
         {
            /* Spare kids, pets, and players */
            write("You decide to spare " + (oc->query_name()) + ".\n");
            remote_say((this_player()->query_name()) + " glares at " +
               (oc->query_name()) + " but suddenly turns away.\n"); 
         }
         else 
         {
            /* First hit goes to primary weapon */
            if(!i || i == 0) this_player()->attack_object(oc);
            else 
            {
               /* Strapped weapons or extra limbs */
               if(weapon[i]) 
               {
                  dam = weapon[i]->weapon_class();
                  extra_hit(dam, i, oc, this_player());

               } else extra_hit(3, i, oc, this_player());
               oc->attack_object(this_player());
               i++;
               if(i > sizeof(weapon)) break;
            }
         }
      }
   }

   this_player()->add_spell_point(-SPIRAL_MULTIHIT_COST);
   return 1;
}

/* ---- DARK TETRAPOD SPELLS [10] --- */

/* heals self (hitpoint only) by drawing from clay power */
dark_tetrapod_vigor(arg)
{
   /* pulls from energy from charges and 'heals' player somewhat */
   int i;
   int max;

   object gob;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   max = gob->query_charge();
   
   i = arg;
   if(!i) return 0;
   if(i < 0 || i > max)
   {
      write("You have [" + max + "] charges in your clay.\n");
      return 1;
   }

   /* conversion isnt totally efficient, like 4/5 */
   max = (max * 3) / 5;

   write("You draw energy from the clay and are invigorated!\n");
   remote_say((this_player()->query_name()) + " draws power from within a lump of magical clay and is invigorated!\n");

   this_player()->add_hit_point(max);
   gob->add_charge(-max);
   check_points();
   return 1;
}

/* hide invisibly */
dark_tetrapod_cloak()
{
}

/* returns from hiding */
dark_tetrapod_decloak()
{
}

/* ---- NECROMONGER SPELLS [13] --- */
necromonger_deathcloud(arg) 
{
   area_attack(800,arg,
      "You expunge your innards to the world, exposing a noxious death cloud!\n",
      "turns inside-out, guts exposing, but a noxious cloud of gas spews forth!\n",
      "convulse and gasp in the vicious spew!\n",
      "convulses and gasps for air in the vicious spew!\n",
      "fall to the ground from the wicked gas!\n",
      "is knocked to the ground by the wicked gas!\n",
      "hold its breath and escapes harm.\n",
      "holds its breath and escapes harm.\n",
      "You fold yourself back again.\n",
      "folds back, inside-in again.\n",
      "You fail to develop a large enough cloud to kill anything with.\n",
      "begins sneezing uncontrollaby.\n");
   return 1;
}

/* make beef jerky out of a corpse */
necromonger_jerky()
{
}

necromonger_coldsuck(arg) 
{
   single_attack(NECRO_COLDSUCK_COST,arg,
      "You touch "," and inhale some of its pathetic lifeforce!",
      (this_player()->query_name()) + " touches ",
      " and sucks some of the life from it.");
   return 1;
}

/* ---- SAMURAI SPELLS [13] --- */

/* begins protecting a player, or monster */
samurai_protect()
{
}

/* ---- HIGH TETRAPOD SPELLS [15] --- */

/* an area attack ability */
high_tetrapod_tremolo(arg)
{
}

/* a single magical attack ability */
high_tetrapod_solaris(arg)
{
   single_attack(HTETRA_SOLARIS_COST, arg,
      "Waves of fusive energy pour from your limbs as you reach out to strike  ","!",
      (this_player()->query_name()) + " glows intensely and strikes ",
      " with a blinding wave of solarelectric power!");
   return 1;
}

/* a pet attack ability */
high_tetrapod_preclusion(arg)
{
}

/* makes a trophy out of a corpse */
high_tetrapod_blick(arg)
{
}

/* ---- DYNAMINE SPELLS [15] --- */

/* produce a weapon */
dynamine_produce_weapon()
{
}

dynamine_produce_armor()
{
}

dynamine_produce_heal()
{
}

/* a terrifying area attack ability */
dynamine_protonshower(arg)
{
}

dynamine_neutrona(arg)
{
}
