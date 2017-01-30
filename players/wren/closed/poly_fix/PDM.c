#include <esc.h>
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

static string msgs;     /* [ARRAY] Messages used in combat */
 
int poly_limits;        /* [ARRAY] Used to store array of polymorph form limit count */
int poly_timelapse;     /* [ARRAY] Used to store array of times allowed before reversion */
int poly_levels;        /* [ARRAY] Used to store what levels a player has to be to morph */
string poly_names;

string news_group;      /* [ARRAY] News stuff - used to store array of all topics */
string messages;        /* [ARRAY] News stuff - used to store array of all messages */
int num_messages;       /* [ARRAY] Used to store message counts */
 
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
      /*
      move_object(clone_object("/players/mizan/etheriel/environs/guild_sign"), HOME);
      */
   }

   /* This must be put in order of polymorph IDs... */
   poly_limits = ({
      20,  /* POLY_SPUCKBALL */
      10,  /* POLY_PUFFERFISH */
       8,  /* POLY_WOMBAT */
       8,  /* POLY_GOLEM */
       6,  /* POLY_TREE */
       8,  /* POLY_CATAPULT */
      10,  /* POLY_LOAFY */
      10,  /* POLY_FUNGOID */
      14,  /* POLY_SPONGE */
       8,  /* POLY_SPR */
       4,  /* POLY_TREEHOUSE */
       8,  /* POLY_WUMPUS */
      10,  /* POLY_REPLICANT */
      12,  /* POLY_PUFFBALL */
       8,  /* POLY_SHOUTBOX */
       6,  /* POLY_JUNGLE_SLUG */
       5,  /* POLY_OCTOPUS */
       4,  /* POLY_TETRAPOD */
       6,  /* POLY_BOG */
       6,  /* POLY_SPUCKTROOPER */
      12,  /* POLY_MIMIC */
       5,  /* POLY_COW */
       4,  /* POLY_DIVYA */
       3,  /* POLY_JUGGERNAUT */
       5,  /* POLY_NECROMONGER */
       5,  /* POLY_GAMBLER */
       6,  /* POLY_PHB */
       4,  /* POLY_SPUCKMOBILE */
       8,  /* POLY_BABOON */
       3,  /* POLY_HIGH_MIMIC */
       2,  /* POLY_DARK_TETRAPOD */
       255, /* POLY_TESTFORM */
       3, /* POLY_WEREWOMBAT */
       4, /* POLY_SHAMEN */
       3, /* POLY_BSOD */
       2, /* POLY_FIREWALL */
       1, /* POLY_VOLCANO */
       3, /* POLY_PORNSTAR */
       2, /* POLY_TETRAPOD_ADEPT */
       3, /* POLY_DARK_WUMPUS */
       5, /* POLY_ROCK */
       1, /* POLY_BOG_ADEPT */
   });


   /* This must be put in order of polymorph IDs... */
   poly_levels = ({
       1,  /* POLY_SPUCKBALL */
       1,  /* POLY_PUFFERFISH */
       1,  /* POLY_WOMBAT */
       2,  /* POLY_GOLEM */
       2,  /* POLY_TREE */
       2,  /* POLY_CATAPULT */
      21,  /* POLY_LOAFY */
       3,  /* POLY_FUNGOID */
       3,  /* POLY_SPONGE */
       3,  /* POLY_SPR */
       3,  /* POLY_TREEHOUSE */
       3,  /* POLY_WUMPUS */
       4,  /* POLY_REPLICANT */
       4,  /* POLY_PUFFBALL */
       4,  /* POLY_SHOUTBOX */
      21,  /* POLY_JUNGLE_SLUG */
       4,  /* POLY_OCTOPUS */
       5,  /* POLY_TETRAPOD */
       5,  /* POLY_BOG */
       5,  /* POLY_SPUCKTROOPER */
       5,  /* POLY_MIMIC */
      21,  /* POLY_COW */
      21,  /* POLY_DIVYA */
      21,  /* POLY_JUGGERNAUT */
      21,  /* POLY_NECROMONGER */
      21,  /* POLY_GAMBLER */
      21,  /* POLY_PHB */
      21,  /* POLY_SPUCKMOBILE */
      21,  /* POLY_BABOON */
      21,  /* POLY_HIGH_MIMIC */
      21,  /* POLY_DARK_TETRAPOD */
      21,  /* POLY_TESTFORM */
      21,  /* POLY_WEREWOMBAT */
      21,  /* POLY_SHAMAN */
      21,  /* POLY_BSOD */
      21,  /* POLY_FIREWALL */
      21,  /* POLY_VOLCANO */
      21,  /* POLY_PORNSTAR */
      21,  /* POLY_TETRAPOD_ADEPT */
      21,  /* POLY_DARK_WUMPUS */
      21,  /* POLY_ROCK */
      21,  /* POLY_BOG_ADEPT */   
   });
   
   /* This must be put in order of polymorph IDs...
    * Remember that this is specified in MINUTES, not callout seconds.
    */
   poly_timelapse = ({
       3, /* POLY_SPUCKBALL */
       3, /* POLY_PUFFERFISH */
       3, /* POLY_WOMBAT */
       5, /* POLY_GOLEM */
      10, /* POLY_TREE */
      10, /* POLY_CATAPULT */
       5, /* POLY_LOAFY */
       7, /* POLY_FUNGOID */
       3, /* POLY_SPONGE */
       7, /* POLY_SPR */
      10, /* POLY_TREEHOUSE */
       7, /* POLY_WUMPUS */
       5, /* POLY_REPLICANT */
       5, /* POLY_PUFFBALL */
       5, /* POLY_SHOUTBOX */
       5, /* POLY_JUNGLE_SLUG */
      20, /* POLY_OCTOPUS */
      30, /* POLY_TETRAPOD */
       5, /* POLY_BOG */
       5, /* POLY_SPUCKTROOPER */
       5, /* POLY_MIMIC */
      10, /* POLY_COW */
      30, /* POLY_DIVYA */
      30, /* POLY_JUGGERNAUT */
      10, /* POLY_NECROMONGER */
       5, /* POLY_GAMBLER */
      15, /* POLY_PHB */
      30, /* POLY_SPUCKMOBILE */
       5, /* POLY_BABOON */
      30, /* POLY_HIGH_MIMIC */
      45, /* POLY_DARK_TETRAPOD */
       0, /* POLY_TESTFORM */
      45, /* POLY_WEREWOMBAT */
      45, /* POLY_SHAMAN */
      60, /* POLY_BSOD */
      60, /* POLY_FIREWALL */
      60, /* POLY_VOLCANO */
      10, /* POLY_PORNSTAR */
      45, /* POLY_TETRAPOD_ADEPT */
      45, /* POLY_DARK_WUMPUS */
       2, /* POLY_ROCK */
      45, /* POLY_BOG_ADEPT */
    });

   poly_names = ({
      "Spuckball",  /* POLY_SPUCKBALL */
      "Pufferfish",  /* POLY_PUFFERFISH */
      "Wombat",  /* POLY_WOMBAT */
      "Golem",  /* POLY_GOLEM */
      "Tree",  /* POLY_TREE */
      "Catapult",  /* POLY_CATAPULT */
      "Loafy",  /* POLY_LOAFY */
      "Fungoid",  /* POLY_FUNGOID */
      "Sponge",  /* POLY_SPONGE */
      "Blobel",  /* POLY_SPR */
      "Treehouse",  /* POLY_TREEHOUSE */
      "Wumpus",  /* POLY_WUMPUS */
      "Replicant",  /* POLY_REPLICANT */
      "Puffball",  /* POLY_PUFFBALL */
      "Shoutbox",  /* POLY_SHOUTBOX */
      "Jungle Slug",  /* POLY_JUNGLE_SLUG */
      "Octopus",  /* POLY_OCTOPUS */
      "Tetrapod",  /* POLY_TETRAPOD */
      "Bogglemancer",  /* POLY_BOG */
      "Spucktrooper",  /* POLY_SPUCKTROOPER */
      "Mimic",  /* POLY_MIMIC */
      "Cow",  /* POLY_COW */
      "Divya",  /* POLY_DIVYA */
      "Juggernaut",  /* POLY_JUGGERNAUT */
      "Necromonger",  /* POLY_NECROMONGER */
      "Gambler",  /* POLY_GAMBLER */
      "Pointy Haired Boss",  /* POLY_PHB */
      "Spuckmobile",  /* POLY_SPUCKMOBILE */
      "Baboon",  /* POLY_BABOON */
      "High Mimic",  /* POLY_HIGH_MIMIC */
      "Dark Tetrapod",  /* POLY_DARK_TETRAPOD */
      "Testform",  /* POLY_TESTFORM */
      "Werewombat", /* POLY_WEREWOMBAT */
      "Shaman", /* POLY_SHAMAN */
      "Blue Screen", /* POLY_BSOD */
      "Firewall", /* POLY_FIREWALL */
      "Volcano",  /* POLY_VOLCANO */
      "Pornstar", /* POLY_PORNSTAR */
      "Tetrapod Adept", /* POLY_TETRAPOD_ADEPT */
      "Dark Wumpus", /* POLY_DARK_WUMPUS */
      "Rock", /* POLY_ROCK */
      "Bogglemancer Adept", /* POLY_BOG_ADEPT */
    });
   
   
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
      info_function("guild_");
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
      cat(DEVSTUFF);
      return 1;
   }

   else if(str == "credits")
   {
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

   return 0;
}

guild_tell_history(str)
{
  write(">> Vibe History:\n\n");
  tail("/log/mizan.poly_vibes");
  return 1;
}

/**
 * The guild channel. 
 * I made it mimic the standard game channels in functionality.
 *
 */
guild_tell(str) 
{
   object ob, gob, pet;
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

   if(str == "history") 
   {
      /* lists people in a string, like channel gossip. */
      guild_tell_history();
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

   pet = find_living("mizPet");
   if(pet)
   {
/*
      tell_room("/players/mizan/workroom", "Message: " + str + " sent to test creature.\n");
 */
       pet->parse_guild_tell(this_player(), str);
   }
   
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

      if(oc && oc->query_original() && !oc->query_muffle()) 
      {
         tell_object(ob[v], str);
      }
   }

   write_file(LOGPATH + "POLY_VIBE", str);
   
   log_file("mizan.poly_vibes", str);
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
      oek->set_morph_count(ock->query_morph_count());

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
   
   room = environment(this_player());
   
   /* already home? hah! */
   if(room == environment(this_object())) 
   {
      remote_say("A toaster pokes " + this_player()->query_name() + " in the ribs.\n");
      write("A toaster pokes you in the ribs.\n");
      return 1;
   }

   desta = creator(room);
   
   if(!desta || sscanf(file_name(room), "/room%s", test) == 1) 
   {
      if(!check_sp(ESCAPE_COST)) return 1;
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
         victim->query_level() + ") ";
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
         victim->query_level() + ") ";
      }
      else
      {
         temp = ">> (vibe)" + ESC + "[0m " +
         capitalize(victim->query_real_name()) + " ";
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

   if(victim->query_exp()) victim->add_exp(-(victim->query_exp() * 2 / 3));

   victim->add_guild_exp(-victim->query_guild_exp());
   victim->add_guild_rank(-(victim->query_guild_rank()));
   victim->set_home("/room/church.c");
   
   call_other("room/adv_guild", "correct_level", victim);
   call_other("room/exlv_guild", "correct_extra_level", victim);
   victim->reset(1);
   victim->save_me();
   
   tell_object(victim,
      "Player stats recomputed.\n"+
      "You lose 2/3 of your current experience.\n"+
      "Guild name and files have been reset to zero.\n"+
      "If you wish to rejoin you must mail Mizan.\n"+
      "Good luck.\n");
   return 1;
}

/* ---- just what it does- guild fancy who
 *      long and bulky... i know... shut up  --- */

guild_fancy_who(str) 
{
   object ob,oc, andre;
   string tempr,temps;
   int lv,glv;
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
         
         if(!intp(glv)) glv=0;
         if(glv < 10) tempr += " ";
         if(glv < GC) tempr += (" " + glv + "  ");
         else if(glv == GC) tempr += " GC  ";
         else if(glv > GC) 
         {
            if(ob[v]->query_real_name() == "mizan") tempr = tempr + "Moo  ";
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
         
         if(temps && strlen(temps) > 34) tempr = tempr + extract(temps, 0, 34) + ESC + "[0m" + ESC + "[0m" + ".\n";
         else tempr = tempr + temps + ESC + "[0m" + ESC + "[0m" + "\n";
       }
       write(tempr);      
   }
   
   /* Lets show Andre, if he is here */
   andre = find_living("mizPet");
   if(andre && environment(andre))
   {
      temps = environment(andre)->short();
      temps = extract(temps, 0, 34);
      tempr = "Andre the Giant   -    -  M   none      " + temps + ESC + "[0m\n";
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
   
   if(this_player()->query_pregnancy()) 
   {
      write("You cannot polymorph because you would kill your unborn child!\n");
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
   
   if(str == "history")
      return polymorph_history();
   else if(str == "chart")
      return polymorph_chart();

   /* BIG NASTY IF-ELSE THING */

   /* L1 forms */   
   else if(str == "spuckball")
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
   else if(str == "wumpus")
      return polymorph_wumpus();

   /* L4 forms */
   else if(str == "puffball") 
      return polymorph_puffball();
   else if(str == "replicant") 
      return polymorph_replicant();
   else if(str == "shoutbox")
      return polymorph_shoutbox();
   else if(str == "octopus")
      return polymorph_octopus();
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
   else if(str == "necromonger")
      return polymorph_necromonger();
   else if(str == "divya")
      return polymorph_divya();
   else if(str == "gambler")
      return polymorph_gambler();
   else if(str == "spuckmobile")
      return polymorph_spuckmobile();
   else if(str == "baboon")
      return polymorph_baboon();

   /* L7 forms */
   else if(str == "high_mimic" || str == "high mimic")
      return polymorph_high_mimic();
   else if(str == "dark_tetrapod" || str =="dark tetrapod")
      return polymorph_dark_tetrapod();
   else if(str == "phb")
      return polymorph_phb();
   else if(str == "werewombat")
      return polymorph_werewombat();
   else if(str == "shaman")
      return polymorph_shaman();

   /* L8 forms */
   else if(str == "juggernaut")
      return polymorph_juggernaut();
   else if(str == "bsod")
      return polymorph_bsod();
   else if(str == "firewall")
      return polymorph_firewall();
   else if(str == "volcano")
      return polymorph_volcano();
   else if(str == "pornstar")
      return polymorph_pornstar();

   /* L9 forms */
   else if(str == "tetrapod adept")
      return polymorph_tetrapod_adept();
   else if(str == "dark wumpus")
      return polymorph_dark_wumpus();
   else if(str == "rock")
      return polymorph_rock();
   else if(str == "bogglemancer adept")
      return polymorph_bog_adept();
       
   /* L21 TEST forms */
   else if(str == "testform" || str == "test")
      return polymorph_testform();
  
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
   cat(POLYLIST);
   return 1;
}

polymorph_history()
{
   write(">> A listing of what people have polymorphed into recently is below:\n\n");
   tail("/players/mizan/logs/POLYFORMS_SIMPLE");
   return 1;
}

polymorph_chart()
{
   int i, j, k, l, m, ib, ic;
   int counter;
   string result, temp;
   object gob;
   
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   k = gob->query_age();
   
   counter = this_player()->query_guild_rank();
   if(counter > 21) counter = 21;
   result = ">>Morph Amounts Remaining-------------------------------------------------<<\n";
   result = result + "  Form Name       Num. Left      Status\n\n";
   
   for(i = 1; i <= counter; i++)
   {
      ib = gob->query_morph_count_all();
      ic = gob->query_morph_lastform_all();

      result = result + "LEVEL[" + i + "]\n";
      
      for(j = 0; j < sizeof(poly_limits); j++)
      {
         if(poly_levels[j] == i)
         {
            temp = "  " + poly_names[j];
            if(strlen(temp) < 8) temp = temp + "\t\t\t";
            else if(strlen(temp) < 16) temp = temp + "\t\t";
            else if(strlen(temp) < 24) temp = temp + "\t";
            
            m = (poly_limits[j] - ib[j]);
            if(m < 10) result = result + temp + "  " + m + "\t";
            else result = result + temp + " " + m + "\t";

           
            /* check if we have been away from a morph long enough */
            l = (k - ic[j]);
            if((l / 60) < poly_timelapse[j] && ic[j] != 0) result = result + " Must wait" + time_to_string((poly_timelapse[j] * 60) - l) + "\n";
            else result = result + " Ready.\n";
         }
      }
   }
   
   write(result + "\n");
   return 1;
}

time_to_string(arg)
{
   int foo, i;
   string dc_text;
   
   dc_text = "";
   i = arg;
   foo = i / 60;
   if((i-foo) == 0) dc_text = dc_text + ("(" + foo + " minutes).\n");
   else dc_text = dc_text + ("(" + foo + " minutes, " + (i-(foo * 60)) + " seconds)");

   return dc_text;
}

/* POLYMORPH SPUCKBALL [1] */
polymorph_spuckball()
{
   do_polymorph(POLY_SPUCKBALL, POLY_SPUCKBALL_COST, "wobble", POLY_SPUCKBALL_STAT,
      "You implode and shape yourself to the form of a Spuckball.\n"+
      "Everything suddenly turns a bit blurrier and sloshy, but within\n"+
      "a few moments your new form adjusts to the environment.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH WOMBAT [1] */
polymorph_wombat()
{
   do_polymorph(POLY_WOMBAT, POLY_WOMBAT_COST, "bleat", POLY_WOMBAT_STAT,
      "You absorb the energy within the clay's matrix and\n"+
      
      "new power courses through your new form as a wombat\n\n" +
      "You suddenly get the urge to dig holes and graze.\n", "armor", 0, 0);
   return 1;
}

/* POLYMORPH PUFFERFISH [1] */
polymorph_pufferfish()
{
   do_polymorph(POLY_PUFFERFISH, POLY_PUFFERFISH_COST, "bubble", POLY_PUFFERFISH_STAT,
      "You take a deep breath and assume the meek form of a pufferfish.\n",
      "armor","weapons", POLY_PUFFERFISH_FORM);
   return 1;
}

/* POLYMORPH GOLEM [2] */
polymorph_golem()
{
   do_polymorph(POLY_GOLEM, POLY_GOLEM_COST, "rumble", POLY_GOLEM_STAT,
      "You expand and shape yourself to the form of a golem.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH TREE [2] */
polymorph_tree()
{
   do_polymorph(POLY_TREE, POLY_TREE_COST, "bark", POLY_TREE_STAT,
      "Everything suddenly goes stiff...\n", "armor", "weapons", 0);
   return 1;
}

/* POLYMORPH CATAPULT [2] */
polymorph_catapult()
{
   do_polymorph(POLY_CATAPULT, POLY_CATAPULT_COST, "hurl", POLY_CATAPULT_STAT,
      "With great effort, you shape yourself to the form of an\n"+
      "Acme Siege Catapult!\n", 
      "armor", "weapons", POLY_CATAPULT_FORM);
   return 1;
}

/* POLYMORPH LOAFY [2] */
polymorph_loafy()
{
   do_polymorph(POLY_LOAFY, POLY_LOAFY_COST, "mumble", POLY_LOAFY_STAT,
      "Woof. Everything turns slow and lazy as you take the form of\n"+
      "the incredibly immobile Loafy the Dog.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH FUNGOID [3] */
polymorph_fungoid()
{
   do_polymorph(POLY_FUNGOID, POLY_FUNGOID_COST,"spore",POLY_FUNGOID_STAT,
     "You concentrate and shape yourself to the form of a fungoid.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH SPONGE [3] */
polymorph_sponge()
{
   do_polymorph(POLY_SPONGE, POLY_SPONGE_COST,"foam",POLY_SPONGE_STAT,
      "You expand and shape yourself to the form of a sponge.\n", 0, "weapons", 0);
   return 1;
}  

/* POLYMORPH SPR (Blobel) [3] */
polymorph_blobel()
{
   do_polymorph(POLY_SPR, POLY_SPR_COST,"blurble",POLY_SPR_STAT,
      "You concentrate intensely and shape yourself to the form of a blobel.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH TREEHOUSE [3] */
polymorph_treehouse()
{
   /* I added this out of respect for wizzes who may have quest rooms
    * or explicit 'death trap' type areas where they don't want the
    * players to have an 'easy' out.
    */
   if(environment(this_player())->realm() == "NT" ||
      environment(this_player())->query_realm() == "NT")
   {
      write("You are unable to plant your roots here, for some reason.\n");
      return 1;
   }
   
   do_polymorph(POLY_TREEHOUSE, POLY_TREEHOUSE_COST,"club",POLY_TREEHOUSE_STAT,
      "Branches stem out of your head, and you take the shape of a treehouse.\n",
      "armor", "weapons", POLY_TREEHOUSE_FORM);

   return 1;

}
 
/* POLYMORPH WUMPUS [3] */
polymorph_wumpus()
{
   do_polymorph(POLY_WUMPUS, POLY_WUMPUS_COST,"hroof",POLY_WUMPUS_STAT,
     "Hroooof! You concentrate and expand to the shape of the fearsome Wumpus!\n"+
     "You now have three arms and are covered from head to toe in brown fur.\n"+
     "Stay away from mazes and bottomless pits though, you hear?\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH PUFFBALL [4] */
polymorph_puffball()
{
   do_polymorph(POLY_PUFFBALL, POLY_PUFFBALL_COST,"puff",POLY_PUFFBALL_STAT,
         "You absorb the energy within the clay's matrix and\n"+
         "new power courses through your new form as a puffball.\n", "armor", 0, 0);
   return 1;
}
   
/* POLYMORPH REPLICANT [4] */
polymorph_replicant()
{
   do_polymorph(POLY_REPLICANT, POLY_REPLICANT_COST,"vibe",POLY_REPLICANT_STAT,
      "You absorb the energy within the clay's matrix and\n"+
      "new power courses through you as you suddenly feel stronger...\n"+
      "faster... better... but your appearances are all the same.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH SHOUTBOX [4] */
polymorph_shoutbox()
{
   do_polymorph(POLY_SHOUTBOX, POLY_SHOUTBOX_COST,"bellow",POLY_SHOUTBOX_STAT,
      "You concentrate intensely and shape yourself to the form of a shoutbox.\n"+
      "Your mouth expands to gaping proportions, your lungs and chest expand\n"+
      "just the same. You feel bloody right dangerous, and like yelling\n"+
      "at someone.\n", "armor", 0, 0);
   return 1;
}

/* POLYMORPH JUNGLE SLUG [4] */
polymorph_jungle_slug()
{
   do_polymorph(POLY_JUNGLE_SLUG, POLY_JUNGLE_SLUG_COST,"gop",POLY_JUNGLE_SLUG_STAT,
      "Mucus and other icky substances start to sweat from every part\n"+
      "of your body, as it turns soft and gooey. You are not the fearsome\n"+
      "jungle slug of the primeval Oomfoofa jungle!\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH OCTOPUS [4] */
polymorph_octopus()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(POLY_OCTOPUS, POLY_OCTOPUS_COST,"squid",POLY_OCTOPUS_STAT,
      "Things get wacky for a moment as eight limbs are whipping\n"+
      "around, but in a moment you're so happy, because you'll never\n"+
      "need a backscratcher or a pair of clamps as an octopus.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH BOG (Bogglemancer) [5] */
polymorph_bogglemancer()
{
   do_polymorph(POLY_BOG, POLY_BOG_COST,"gribble",POLY_BOG_STAT,
      "You absorb the energy within the clay's matrix and\n"+
      "reciting the Principles of Painless distraction, you suddenly drift\n"+
      "into a state of thoughtless awareness, and your new form.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH TETRAPOD [5] */
polymorph_tetrapod()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(POLY_TETRAPOD, POLY_TETRAPOD_COST,"growl",POLY_TETRAPOD_STAT,
      "You concentrate and assume the polymorph of a tetrapod.\n"+
      "New arms pop out from nowhere but after a bit of confusion, and\n"+
      "much scratching and waving, everything feels okay.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH SPUCKTROOPER [5] */
polymorph_spucktrooper()
{
   do_polymorph(POLY_SPUCKTROOPER, POLY_SPUCKTROOPER_COST,"grobble",POLY_SPUCKTROOPER_STAT,
      "You implode and shape yourself to the form of a Spucktrooper.\n"+
      "Everything suddenly turns a bit blurrier and sloshy, but within\n"+
      "a few moments your new form adjusts to the environment.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH MIMIC [5] */
polymorph_mimic()
{
   do_polymorph(POLY_MIMIC, POLY_MIMIC_COST,"mime",POLY_MIMIC_STAT,
      "You assume the shapeless mass of a generic creature.\n"+
      "Make sure you assume the form of something else by 'imitate <name>'.\n", 
      "armor", "weapons", POLY_MIMIC_FORM);
   return 1;
}

/* POLYMORPH COW [5] */
polymorph_cow()
{
   do_polymorph(POLY_COW, POLY_COW_COST,"moo",POLY_COW_STAT,
      "You expand and fill out the bulky frame of a cow. Spots appear from everywhere\n"+
      "and you have the urge to lactate and MOO loudly.\n", 
      "armor", "weapons", 0);
   return 1;
}

/* POLYMORPH DIVYA [6] */
polymorph_divya()
{
   if(!check_wimpyoff()) return 1;
   if(!check_gender("female")) return 1;
   
   do_polymorph(POLY_DIVYA, POLY_DIVYA_COST,"whisper",POLY_DIVYA_STAT,
      "Contorting yourself into a prime focus and then releasing with\n"+
      "wicked conviction, six arms sprout where there was once two and\n"+
      "you assume the form of the Divya Gotterdamurung.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH NECROMONGER [6] */
polymorph_necromonger()
{
   do_polymorph(POLY_NECROMONGER, POLY_NECROMONGER_COST,"groan",POLY_NECROMONGER_STAT,
      "Concentrating deeply, you think of wretched things such as the\n"+
      "bloated corpse of Richard Simmons [tm] covered in sticky lard.\n"+
      "You assume the form of the feared Necromonger.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH BABOON [6] */
polymorph_baboon()
{
   do_polymorph(POLY_BABOON, POLY_BABOON_COST,"shriek",POLY_BABOON_STAT,
      "You shrink in size, a dark olive fur grows from basically every\n"+
      "point on your body, and you have the craving for bananas, walnuts,\n"+
      "howling madly, and throwing your own feces at people. You have\n"+
      "assumed the form of a baboon.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH GAMBLER [6] */
polymorph_gambler()
{
   int i, a, jackpot;
   string statline, negline;
   
   if(!check_wimpyoff()) return 1;

   statline = "gambler#gambler";
   jackpot = 0;
   
   /* This one is a more complex morph to handle.
    * Player can lose or gain up to 8 points across the board in
    * their overall stats. Stats are generated here.
    */
   for(i = 0; i < 6; i++)
   {
      a = random(8);
      /* ONCE IN A BLUE MOON a player hits JACKPOT! */
      if(1 == random(250) && jackpot == 0)
      {
        jackpot = 1;
        a = a + 15 + random(15);
      }
      
      /* decide if it is positive or negative */
      if(1 == random(2)) negline = "-";
      else negline = "";
         
      statline = statline + "#" + negline + a;
   }

   do_polymorph(POLY_GAMBLER, POLY_GAMBLER_COST,"bet",statline,
      "You let it ride and assume the shape of whatever weirdness comes.\n"+
      "to mind... You assume the shape of a gambler.\n\n", 0, 0, 0);
   if(jackpot != 0)
      write("You seem to have struck JACKPOT today as one of your stats is LOADED!!\n"+
      "Check it...\n");
   command("sc2", this_player());
   return 1;
}

/* POLYMORPH SPUCKMOBILE [6] */
polymorph_spuckmobile()
{
   do_polymorph(POLY_SPUCKMOBILE, POLY_SPUCKMOBILE_COST,"grimpo",POLY_SPUCKMOBILE_STAT,
      "Things get blurry, and you squit yourself into the shape of a Spuckmobile!\n",
      "armor", "weapons", POLY_SPUCKMOBILE_FORM);
   return 1;
}

/* POLYMORPH HIGH MIMIC [7] */
polymorph_high_mimic()
{
   do_polymorph(POLY_HIGH_MIMIC, POLY_HIGH_MIMIC_COST,"mime",POLY_HIGH_MIMIC_STAT,
      "Taking a deep breath, you assume the shapeless mass of a generic.\n"+
      "creature. Make sure you assume the form of something else by 'imitate <name>'.\n", 
      "armor", "weapons", POLY_HIGH_MIMIC_FORM);
   return 1;
}

/* POLYMORPH DARK_TETRAPOD [7] */
polymorph_dark_tetrapod()
{
   if(!check_wimpyoff()) return 1;

   do_polymorph(POLY_DARK_TETRAPOD, POLY_DARK_TETRAPOD_COST,"growl",POLY_DARK_TETRAPOD_STAT,
      "You concentrate and assume the polymorph of a dark tetrapod.\n"+
      "New arms pop out from nowhere but after a bit of confusion, and\n"+
      "much scratching and waving, everything feels okay.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH PHB [7] */
polymorph_phb()
{
   do_polymorph(POLY_PHB, POLY_PHB_COST,"direct",POLY_PHB_STAT,
      "You cringe as you nearly go bald, gain some paunch around the sides, and\n"+
      "suddenly feel numb from the neck down as you form some clothing around\n"+
      "yourself. That necktie stranging bloodflow to the head surely is not a\n"+
      "great thing either. You have just assumed the shape of a Pointy Haired Boss.\n", "armor", 0, 0);
   return 1;
}

/* POLYMORPH WEREWOMBAT [7] */
polymorph_werewombat()
{
   do_polymorph(POLY_WEREWOMBAT, POLY_WEREWOMBAT_COST,"bleat",POLY_WEREWOMBAT_STAT,
      "Thick, stubby brown fur literally explodes from all places as you shrink\n"+
      "and assume the squat, stocky form of the fearsome Werewombat!\n"+
      "Your mouth starts to burn as you suddenly crave the taste of fresh blood.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH SHAMAN [7] */
polymorph_shaman()
{
   do_polymorph(POLY_SHAMAN, POLY_SHAMAN_COST,"rave",POLY_SHAMAN_STAT,
      "You turn inward and collect yourself into a state of thoughtless awareness.\n"+
      "Blood courses with great speed through your veins, and you let the morph\n"+
      "process simply choose a course of its own. You have assumed the shape of the\n"+
      "medicinal Shaman.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH JUGGERNAUT [8] */
polymorph_juggernaut()
{
   if(!check_gender("male")) return 1;

   do_polymorph(POLY_JUGGERNAUT, POLY_JUGGERNAUT_COST,"thunder",POLY_JUGGERNAUT_STAT,
      "You grunt loudly and expand in size! Muscles rippling and bulging\n"+
      "where there was once fat, you almost hurt yourself in the whole\n"+
      "process of assuming the form of the Juggernaut.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH BSOD [8] */
polymorph_bsod()
{
   do_polymorph(POLY_BSOD, POLY_BSOD_COST,"watson",POLY_BSOD_STAT,
      "You curl inwards and recite a mantra to protect yourself during the\n"+
      "formation of this form... 'When in doubt reboot or power cycle...\n"+
      "Your flesh fades into a digital mass, nearly pure energy. You cringe\n"+
      "at first but allow the Dark side to engulf you fully\n"+
      "You are now the fearsome Blue Screen of Death.\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH FIREWALL [8] */
polymorph_firewall()
{
   do_polymorph(POLY_FIREWALL, POLY_FIREWALL_COST,"filter",POLY_FIREWALL_STAT,
      "Everything around you gets blurry and blue... the light from outside\n"+
      "fades and you revert into the fearsome filtering firewall.\n", 0, "weapons", 0);
   return 1;
}

/* POLYMORPH VOLCANO [8] */
polymorph_volcano()
{
   do_polymorph(POLY_VOLCANO, POLY_VOLCANO_COST,"vent",POLY_VOLCANO_STAT,
      "Melding yourself to the ground, you channel into it and derive the kind\n"+
      "of mass energy you will need to assume the form of the polymorph volcano!\n", 
      "armor", "weapons", 0);
   return 1;
}

/* POLYMORPH PORNSTAR [8] */
polymorph_pornstar()
{
   do_polymorph(POLY_PORNSTAR, POLY_PORNSTAR_COST,"pump",POLY_PORNSTAR_STAT,
      "Taking all of your clothes off, you assume the form of a pornstar. Woo!\n", "armor", 0, 0);
   return 1;
}

/* POLYMORPH TETRAPOD_ADEPT [9] */
polymorph_tetrapod_adept()
{
   do_polymorph(POLY_TETRAPOD_ADEPT, POLY_TETRAPOD_ADEPT_COST,"snarl",POLY_TETRAPOD_ADEPT_STAT,
      "\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH DARK WUMPUS [9] */
polymorph_dark_wumpus()
{
   do_polymorph(POLY_DARK_WUMPUS, POLY_DARK_WUMPUS_COST,"froop",POLY_DARK_WUMPUS_STAT,
      "\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH ROCK [9] */
polymorph_rock()
{
   do_polymorph(POLY_ROCK, POLY_ROCK_COST,"rock",POLY_ROCK_STAT,
      "You shape yourself into the form of a boring old rock.\n", "armor", "weapons", 0);
   return 1;
}

/* POLYMORPH BOGGLEMANCER ADEPT [9] */
polymorph_bog_adept()
{
   do_polymorph(POLY_BOG_ADEPT, POLY_BOG_ADEPT_COST,"grobble",POLY_BOG_ADEPT_STAT,
      "\n", 0, 0, 0);
   return 1;
}

/* POLYMORPH TESTFORM [21] */
polymorph_testform()
{
   do_polymorph(POLY_TESTFORM, POLY_TESTFORM_COST,"vibe",POLY_TESTFORM_STAT,
      "You polymorph into the current test form.\n", 0, 0, 0);
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

/* Remove guild monitor as these are now illegal -Snow 4/99
 * Monitor returned as of 07 AUG 2001 - They display
 * polymorph specific information in combat.
 */
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
   
/* Remove guild monitor as these are now illegal -Snow 4/99
 * Monitor returned as of 07 AUG 2001 - Displays polymorph
 * specific information in combat.
 */
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
/* Remove guild monitor as these are now illegal -Snow 4/99
 * Monitor returned as of 07 AUG 2001 - Polymorph specific info displayed.
 */
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
/* Remove guild monitor as these are now illegal -Snow 4/99
 * Monitor returned as of 07 AUG 2001 - polymorph specific info is displayed.
 */
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

/* ---- INFO FUNCTIONS NOW --- */

info_function(str) 
{
   string testj, temp, tempd;

   if(!str) 
   {
      cat(HELPDIR + "info");
      return 1;
   }
   else
   {
      if(sscanf(str, "guild %s", testj) == 1) 
         temp = HELPDIR + "guild_" + strip_whitespace(testj);

      if(sscanf(str, "polymorph %s", testj) == 1)
         temp = HELPDIR + "poly_" + strip_whitespace(testj);

      if(sscanf(str, "poly %s", testj) == 1) 
         temp = HELPDIR + "poly_" + strip_whitespace(testj);
      
      if(!temp) 
         temp = strip_whitespace(HELPDIR + str);
      
   }
   
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

/* ---- GCMD FUNCTIONS NOW --- */
gcmd_function(str)
{
   if(!str) return;
   
   if(str == "damcap") return gcmd_damcap();
   if(str == "rtime") return gcmd_rtime();   
   if(str == "charges") return gcmd_charges();
   
   return 0;
}

/**
 * This function displays the multilimb combat stats of all polys
 * currently logged in.
 *
 * Usage: (WIZ ONLY)
 */
gcmd_damcap()
{
   object ob, gob;
   string temp;
   int i;
   
   ob = users();
   
   write("\n>>Guild Damage Ratings----------------------------------------------------<<\n");
   write("Name\t\tTot Dam\t\tRounds\tRds OC\tMax Dam\tAvg Dam/Round\n");
   for(i = 0; i < sizeof(ob); i++)
   {
      gob = present(GUILD_ID, ob[i]);
      if(gob)
      {
         temp = ob[i]->query_name() + "\t";
         if(strlen(ob[i]->query_name()) < 8) temp = temp + "\t";
         
         temp = temp + gob->query_combat_totaldam() + "\t\t";
         temp = temp + gob->query_combat_rounds() + "\t";
         temp = temp + gob->query_combat_rounds_overcap() + "\t";
         temp = temp + gob->query_combat_peakdam() + "\t";
         temp = temp + gob->query_combat_avgdam() + "\t\n";

         write(temp);
      }
   }
   return 1;
}

/**
 * This function displays the amount of time until reversion for all polys
 * currently logged in and morphed.
 *
 * Usage: (WIZ ONLY)
 */
gcmd_rtime()
{
   object ob, gob, mob;
   int i;
   
   ob = users();
   write("\n>>Morph Form Clocks-------------------------------------------------------<<\n");
   write("Name\t\tCurrent Form\tClock\n");
   
   for(i = 0; i < sizeof(ob); i++)
   {
      gob = present(GUILD_ID, ob[i]);
      mob = present(MORPH_ID, ob[i]);
      
      if(gob)
      {
         write(ob[i]->query_name());
         if(strlen(ob[i]->query_name()) < 8) write("\t");
         write("\t");
         
         write(gob->query_current_morph());
         if(strlen(gob->query_current_morph()) < 8) write("\t");
         write("\t");
         
         if(mob) call_other(mob, "rtime", 0);
         write("\n");
      }
   }
   return 1;
}

/**
 * This function displays the charge levels of all polys
 * currently logged in.
 *
 * Usage: (WIZ ONLY)
 */
gcmd_charges()
{
   object ob, gob;
   int i;
   
   ob = users();
   write("\n>>All Polymorph Clay Charges----------------------------------------------<<\n");
   write("Name\t\tCurrent Form\tCharges\n");
   
   for(i = 0; i < sizeof(ob); i++)
   {
      gob = present(GUILD_ID, ob[i]);
      
      if(gob)
      {
         write(ob[i]->query_name());
         if(strlen(ob[i]->query_name()) < 8) write("\t");
         write("\t");
         
         write(gob->query_current_morph());
         if(strlen(gob->query_current_morph()) < 8) write("\t");
         write("\t");
         
         write(gob->query_charge() + "\n");
      }
   }
   return 1;
}



/* ---- GUT FUNCTIONS NOW --- */


/**
 * The part that actually processes new stats
 *
 * Arguments:
 * pid     The ID number of the morph. 
 *         Used to check how many times a player is allowed to morph.
 * cost    The cost in charges (1 charge = 1 sp)
 * chan    The name of the guild channel they use while morphed.
 * str     The statline for the morph form
 * arg     A string the player is write()ten to when morphing
 */
do_polymorph(pid, cost, chan, str, arg, weapons, armor, mform) 
{
   object mob, gob, rob, room;
   string gfile, passes, rchan, newtitle;
   int rstat, cnt, strtemp, strtemp2, rcost, ltime;

   /* this is a large, heavy, beastly function */
   
   /* check for levels */
   if(!check_level(poly_levels[pid])) return 1;

   /* no gob, no service */
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   rcost = cost;
   rchan = chan;
   rstat = allocate(6);
   cnt = 0;

   /* Check the amount of times a player can take this form */
   if(gob->query_morph_count(pid) > poly_limits[pid])
   {
      write("You are too drained to assume this form.\n"+
         "You must wait until the next reboot.\n");
      call_other("room/church","long","clock");
      return 1;
   }

   /* Check if the player can take this form again. */
   ltime = (gob->query_age() - gob->query_morph_lastform(pid));
   
   if(gob->query_morph_lastform(pid) && (ltime / 60) < poly_timelapse[pid])
   {
      write("You are too drained to assume this form yet.\n");
      write("You must wait another [" + (poly_timelapse[pid] - (ltime / 60)) + "] minutes.\n");
      remote_say((this_player()->query_name()) + " attempts to polymorph but is too time drained.\n");
      return 1;
   }
   
   /* not enough juice... unless you are a wiz */
   if(this_player()->query_level() < 21 && 
      gob->query_charge() < rcost) 
   {
      write("There is'nt enough energy in the clay to help you polymorph.\n"+
          "This form requires [" + rcost + "] charges.\n");
      remote_say((this_player()->query_name()) + " attempts to polymorph but is too charge drained.\n");
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
   mob = clone_object(PATHNAME + gfile);

   if(!mob)
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

   move_object(mob, this_player());
   remote_say((this_player()->query_name()) + " contorts and polymorphs into a " + newtitle + ".\n");
   
   /* BREAK for strength-carry checking. */
   strtemp = call_other(this_player(), "query_attrib", "str");
   strtemp2 = strtemp + rstat[3];
   if(strtemp2 < strtemp) check_inventory_weight(strtemp - strtemp2);

   /* handle the attribute adjustments */   
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
   
   /* Set other variables */
   gob->set_morph_comm(rchan);
   gob->set_current_morph(newtitle);
   gob->set_title(this_player()->query_title());
   
   if(this_player()->query_pretitle())
      gob->set_pretitle(this_player()->query_pretitle());
   
   this_player()->set_pretitle("|");
   this_player()->set_title("the " + newtitle);
   this_player()->reset(1);
   
   /* If we have a morph message, show it */
   if(arg) write(arg);
   
   /* Increment the counter */
   gob->add_morph_count(pid);

   write("\nYou are able to assume this morph [" + 
   (poly_limits[pid] - gob->query_morph_count(pid)) + "] more times until the next day.\n");

   gob->set_morph_lastform(pid);
   
   write("Type 'class' to see your new abilities.\n");
      
   gob->record_attribs();
   mob->tick();
   check_points();
   
   if(weapons || armor) unready_items(weapons, armor);

   /* If we have a roving object, clone it */
   if(mform != 0)
   {
      room = environment(this_player());
      if(room)
      {
         rob = clone_object(mform);
         rob->set_owner(this_player()->query_real_name());
         move_object(rob, environment(this_player()));
      }
   }
   
   
   write("\n->> ");

   /* log everything */
   write_file(LOGPATH + "POLYFORMS", (this_player()->query_real_name()) +
      " morphed to '" + str + "' at " + ctime() + "\n");
   
   /* log simple version for players */
   if(this_player()->query_level() < 21)
      write_file(LOGPATH + "POLYFORMS_SIMPLE", (this_player()->query_name()) +
      " morphed into to a '" + newtitle + "' at " + ctime() + "\n");

   return 1;
}


/* ---- bring a player back from polymorph --- */

undo_polymorph(arg, poof) 
{
   object morpho,gob,vic,ob,room;
   string gfile,passes,gtemp;
   int rstat;
   int cnt;
   int strtemp;
   int ct; 
   int i;           /* used as a generic random number */
   int j;           /* used as a generic random number */
   
   status was_dead; /* this is set if a player came to us dead, so we can deduct a stat later */
   
   ct = 0;
   cnt = 0;
   was_dead = 0;
   rstat = allocate(6);
   
   if(arg) vic = arg;
   else vic = this_player();

   gob = present(GUILD_ID, vic);
   if(!gob) return 0;

   /* It is important to move the player out when they die...
    * I know it seems like a cheap move but my code brings the
    * player back to life and if they just stand there, they will die
    * repeatedly!
    */
   if(vic->query_ghost())
   {
     /* set up the ansi */
     tell_object(vic, ESC + "[1m" + ESC + "[37m");
   
     tell_object(vic, "\n\n>> YOU ARE DEAD!\n\n"+
        "Spuck opens a fold and reaches in from the ether-muck and drags your soul to\n"+
        "Destination Linna. You have been brought back into the Guild room.\n\n");
     
     was_dead = 1;
     
     if(environment(vic))
     {
        tell_object(vic, "Spuck tells you: I tracked your corpse to be in:\n       '" + environment(vic)->short() + "'!\n");
     
        ob = first_inventory(environment(vic));
        while(ob)
        {
           if(living(ob) && !ob->query_invis() && ob != vic) tell_object(vic, "Spuck tells you: '" + ob->query_name() + "' was present.\n");
           ob = next_inventory(ob);
        }
        tell_object(vic, "Spuck tells you: Good luck getting your corpse back...\n");
     }

     tell_object(vic, ESC + "[0m");

     /* Before moving the player out, we want to dump all of their inventory
      * in the current room. By now the game driver thinks that they are
      * alive so we can just start dropping shit here.
      */
     ob = first_inventory(vic);
     room = environment(vic);
     if(room)
     {
        while(ob)
        {
           if(!ob->drop())
           {
              move_object(ob, room);
              vic->add_weight(-(ob->query_weight()));
              if(ob->short()) tell_object(vic, ob->short() + " falls to the ground!\n");
           }
           ob = next_inventory(ob);
        }
     }
     /* end of shit droppage */
     
     vic->move_player("in a dimensional tear#/players/mizan/etheriel/ROOMS/linna");
     /* TODO remove a random stat from player */
     command("look", vic);
   }

   gfile = gob->query_main_stats();
   
   if(!gfile)
   {
   }
   else if(sscanf(gfile, "%s#%d#%d#%d#%d#%d#%d", 
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
/* stat limits higher now, changing from 20 to cap of 30 - Wren*/                  
         if(rstat[ct] > 30) rstat[ct] = 30;
         ct++;
      }
   }
   
   /* I forgot why i put this here. It is confusing */
   if(!poof) 
   {
      remote_say("A " + (gob->query_current_morph()) + " fades and melts into " + (vic->query_name()) + ".\n");
      write("You relax and return to your normal shape.\n");
   }
   
   /* BREAK for strength-carry checking. */
   
   strtemp = call_other(vic, "query_attrib", "str");
   strtemp = strtemp - rstat[3];
   if(strtemp > 0) check_inventory_weight(strtemp,vic);

   /* if a player came to us dead we need to randomly remove a stat */
   if(was_dead)
   {
      i = (random(6));
      j = rstat[i];
      j = j - 1;
      if(j < 1) j = 1;
      rstat[i] = j;
   }
   
   /* now set the attributes */  
   while(cnt < 5) 
   {
      int tempv;
      tempv = call_other(vic, "query_attrib", extract(passes[cnt], 0, 2));
      call_other(vic, "set_attrib", extract(passes[cnt], 0, 2), rstat[cnt]);
      cnt ++;
   }
   
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
/* took this out cos it was halving player HP and SPS for some odd reason
   check_points(vic);
 */
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

   if(vic) 
   {
      if(vic->query_hp() > vic->query_mhp()) 
         vic->add_hit_point(-(vic->query_hp() - vic->query_mhp()));

      if(vic->query_sp() > vic->query_msp()) 
         vic->add_spell_point(-(vic->query_sp() - vic->query_msp()));
   }
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

/*
 * Gender checking
 */
check_gender(str)
{
   if(this_player()->query_gender() == str) return 1;
   else
   {
      write("You must be " + str + " for this. Sorry.\n");
      return 0;
   }
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
   
   if(!vic) return 1;
   
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
/*
            remote_say((vic->query_name()) + " drops " + lower_case(ob->short()) + ".\n");
 */            

            tell_room(environment(vic), (vic->query_name()) + " drops " + lower_case(ob->short()) + ".\n");
            
            tell_object(vic, (ob->short()) + " is too heavy.\n");
            vic->add_weight(-(ob->query_weight()));
         }
         ob = next_ob;
         
      }
   }
   return 1;
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
   
   if(!arg || arg=="")
   {
     write("No creature specified. You are confused.\n");
     return 1;
   }
   
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
  if(!str) return 1;
  if(this_player())
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
   
   write_file(LOGPATH + "POLY_PROMOS", (this_player()->query_real_name()) +
      " promoted " + (vct->query_real_name()) + " " +
      amt_promo + " levels to glevel " + (vct->query_guild_rank()) +
      " on " + ctime() + "\n");

   write("Done.\n");
   return 1;
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
   
   if(!ob) return 0;
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
/* ----- 9-19 Verte added check per remote_selling RULES ----- */
      if(x > 1000) x = 1000;
/* ----- taken out by Verte 9-19 ----- */
/*
      if(x > 1500) x = random(500) + 1000;
*/
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
  if(!str) return 1;
  if(!environment(this_player())) return 1;
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
  if(read_file("/players/mizan/etheriel/ROOMS/"+str))
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
   object ob, andre;
   string toast;
   string tempr;
   string temps;
   int lv;
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
      
      tempr = "";
      if(environment(ob[v]) && ob[v]->query_name() && ob[v]->query_gender()) 
      {
/*
 * Changed to reflect new rule for players not to be able to see each
 * other who are equal levels as invis...
         if(!ob[v]->query_invis() || ob[v]->query_invis() < 19) 
 */
         if(!ob[v]->query_invis() || (ob[v]->query_level() < this_player()->query_level()) || ob[v] == this_player()) 
         {
            /* add some flags */
            if(ob[v]->query_ghost()) tempr = tempr + "@";
            if(query_idle(ob[v]) >= 5 * 60) tempr = tempr + "=";
            if(ob[v]->query_invis()) tempr = tempr + "#";
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
                  temps =  temps + ESC + "[0m" + ESC + "[0m";
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
            
            if(!unlock && strlen(temps) > 34) tempr = tempr + (extract(temps, 0, 34)) + ESC + "[0m" + ESC + "[0m.\n";
            else tempr = tempr + temps + ESC + "[0m\n";
            peeps = peeps + 1;
            
         }
         write(tempr);
         
       } else write("[Logon]\n");

   }

   /* Let's show Andre if we can find him :) */
   andre = find_living("mizPet");
   if(andre && environment(andre))
   {
      temps = environment(andre)->short();
      temps = extract(temps, 0, 34);
      tempr = "Andre the Giant    -  M   N   polymorp. " + temps + "\n";
      write(tempr + ESC + "[0m");
   }

   
   /* tail end */
   write("\n>>- '*' is wizard editing, '=' is idle, '@' is dead, '#' is invis.     -<<\n");
   if(andre && environment(andre))
      write(">>-Players: [" + peeps + "] Wizards: [" + wizzes + "] Ally: [1] Date [" + ctime() + "]");
   else
      write(">>-Players: [" + peeps + "] Wizards: [" + wizzes + "] Date [" + ctime() + "]          ");
   if(peeps < 10) write(" ");
   write("-<<\n");
   return 1;
}

/* ---- modified player score ---- */
   
do_score() 
{
   object gob, mob;
   gob = present(GUILD_ID, this_player());
   mob = present(MORPH_ID, this_player());
   
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
   
   if(mob) call_other(mob, "rtime", 0);
   
   return 1;
}

do_clock() 
{
   write("You look carefully at your clay and some words appear:\n");
   write("\nThe mud will reboot after 12 hours.\n");
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
      y = vc->query_level() * 8;
      x = (vc->query_soaked() * 100) / y;
      temp = temp + superstat_colorize_inv(x) + "S<" + x + "%> ";
   }
   
   if(vc->query_attack()) 
   {
      atk = vc->query_attack();
      x = (atk->query_hp() * 10) / atk->query_mhp();
      temp = temp + superstat_colorize(x * 10) + "AHP<" + x + "/10 max> ";
   }
   
   if(eep) 
   {
      tpa = eep;
      temp = temp + superstat_colorize((tpa * 100) / 2300) + "CH[" + tpa + "]";
   }
   
   temp = temp + ESC + "[0m";
   tell_object(vc, temp + "\n");
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

   /* New change. If the player is not fighting already they cannot
    * cast an area attack. 07 APR 2001
    */
   if(!this_player()->query_attack())
   {
     write("You need to be fighting something before you can do this.\n");
     return 1;
   }

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

            /* Randomly don't kill the creature outright */
            if(foo_hp < foo_damage || foo_hp == foo_damage)
               if(1 == random(3)) foo_damage = foo_hp - 1;
            
            write("You see " + capitalize(foo2->query_name()) + " " + vwm);
            remote_say(capitalize(foo2->query_name()) + " " + vsm);

            /* Redirect all targets to this player if they are not engaged in combat */
            if(foo2 && !foo2->query_ghost() && !foo2->query_attack())
               foo2->attack_object(this_player());
            
            /* Cap our damage now, and strike! */
            if(foo_damage > MAGIC_DAMAGE_CAP) foo_damage = MAGIC_DAMAGE_CAP;
            foo2->hit_player(foo_damage);

            /* Evaluate our hit */
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

/* UNCOMMENT THIS TO MAKE LIVE if(this_player()->query_level() > 19) */
   if(gob->query_is_casting_single_attack())
   {
      write("Yes, yes.\n");
      return 1;
   }
   
   if(!check_sp(limit)) return 1;

   /* If no arg is given we assume it is our current attacker... */   
   if(!arg) 
   {
      ob = this_player()->query_attack();
      if(!ob) 
      {
         write("Attack who?\n");
         return 1;
      }
   }

   /* No attacker? No service! */   
   if(arg && !ob) 
   {
      ob = present(arg, environment(this_player()));
      if(!ob) {
         write("There is no such creature present.\n");
         remote_say(this_player()->query_name() + " searches the area for something to attack.\n");
         return 1;
      }
      
   }
   
   /* Attacking walls is not exciting. */   
   if(!living(ob) || ob->query_ghost()) 
   {
      write("You are left in a steep bogglement.\n");
      remote_say(this_player()->query_name() + " appears to be in a state of steep bogglement.\n");
      return 1;
   }

   /* Guild powers cannot be used against others in PK. */   
   if(ob->is_player()) 
   {
      write("You cannot use guild powers against other players!\n");
      return 1;
   }
   
   /* Let the game player object audition the attacker */
   if(!this_player()->valid_attack(ob)) return 1;
   
   /* recalc, randomized and 'bonus' potential damage */
   this_player()->add_spell_point(-limit);

   /* Chance of failure dependent on willpower.
    * BEST CASE - 1/40 chance.
    */
   if(random(this_player()->query_attrib("wil") * 2) == 1) 
   {
      write("You goofed and screw up.\n");
      return 1;
   }
   
   /* Tell the room what is happening */
   write(swm + (ob->query_name()) + swpm + "\n");
   remote_say(ssm  + (ob->query_name()) + sspm +"\n");

   /* The official spell formula matches the game spells. */
   limit = random(2 * limit);

   /* Hit creature is our FILTERED attack system */
   hit_creature(this_player(), ob, limit);

   if(gob->query_eval()) evaluate_hit(limit);

   gob->set_casting_single_attack();
 
   /* Allow the attacker to attack us! */
   if(ob && !ob->query_attack())
      ob->attack_object(this_player());
      
   return 1;
}


/**
 * This is a single attack spell function that deals direct hit_player on the creature.
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
closer_attack(limit,arg,swm,swpm,ssm,sspm) 
{
   object gob,ob;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   if(check_dead()) return 1;

/* UNCOMMENT THIS TO MAKE LIVE  if(this_player()->query_level() > 19) */
   if(gob->query_is_casting_closer_attack())
   {
      write("Yes, yes.\n");
      return 1;
   }

   if(!check_sp(limit)) return 1;

   /* If no arg is given we assume it is our current attacker... */   
   if(!arg) 
   {
      ob = this_player()->query_attack();
      if(!ob) 
      {
         write("Attack who?\n");
         return 1;
      }
   }

   /* No attacker? No service! */   
   if(arg && !ob) 
   {
      ob = present(arg, environment(this_player()));
      if(!ob) {
         write("There is no such creature present.\n");
         remote_say(this_player()->query_name() + " searches the area for something to attack.\n");
         return 1;
      }
      
   }
   
   /* Attacking walls is not exciting. */   
   if(!living(ob) || ob->query_ghost()) 
   {
      write("You are left in a steep bogglement.\n");
      remote_say(this_player()->query_name() + " appears to be in a state of steep bogglement.\n");
      return 1;
   }

   /* Guild powers cannot be used against others in PK. */   
   if(ob->is_player()) 
   {
      write("You cannot use guild powers against other players!\n");
      return 1;
   }
   
   /* Let the game player object audition the attacker */
   if(!this_player()->valid_attack(ob)) return 1;
   
   /* recalc, randomized and 'bonus' potential damage */
   this_player()->add_spell_point(-limit);

   /* Chance of failure dependent on willpower.
    * BEST CASE - 1/20 chance.
    */
   if(random(this_player()->query_attrib("wil")) == 1) 
   {
      write("You goofed and screw up.\n");
      return 1;
   }
   
   /* Tell the room what is happening */
   write(swm + (ob->query_name()) + swpm + "\n");
   remote_say(ssm  + (ob->query_name()) + sspm +"\n");

   /* The official spell formula matches the game spells. */
   limit = random(2 * limit);

   /* check if under the cap */
   if(limit > MAGIC_DAMAGE_CAP) limit = MAGIC_DAMAGE_CAP;
   
   if(living(ob)) ob->hit_player(limit);

   if(gob->query_eval()) evaluate_hit(limit);

   gob->set_casting_closer_attack();
   
   /* Allow the attacker to attack us! */
   if(ob && !ob->query_ghost() && !ob->query_attack())
      ob->attack_object(this_player());
      
   return 1;
}

/**
 * This is a modification of the single attack spell function that
 * leaves an object in the room to do further damage over a spread of
 * call outs.
 *
 * inputs:
 * limit    what the spell costs.
 * idstr    The name of the string of the attack spell
 * rs_file  The object to be cloned, its filename
 * arg      The name of the object to attack
 * swm      The write msg before the monster name.
 * swpm     The write msg after the monster name.
 * ssm      The say msg before the monster name.
 * sspm     The say msg after the monster name.
 *
 * I really should fix these functions. The arguments are so cobol, and
 * crufty, but this stuff works.
 */
callout_attack(limit, idstr, rs_file, arg, swm, swpm, ssm, sspm) 
{
   object gob, ob, rsob, ersob, room;
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   room = environment(this_player());
   if(!room) return 0;
   
   if(check_dead()) return 1;
   if(!check_sp(limit)) return 1;

   /* If no arg is given we assume it is our current attacker... */   
   if(!arg) 
   {
      ob = this_player()->query_attack();
      if(!ob) 
      {
         write("Attack who?\n");
         return 1;
      }
   }

   /* No attacker? No service! */   
   if(arg && !ob) 
   {
      ob = present(arg, environment(this_player()));
      if(!ob) {
         write("There is no such creature present.\n");
         remote_say(this_player()->query_name() + " searches the area for something to attack.\n");
         return 1;
      }
      
   }
   
   /* Attacking walls is not exciting. */   
   if(!living(ob) || ob->query_ghost()) 
   {
      write("You are left in a steep bogglement.\n");
      remote_say(this_player()->query_name() + " appears to be in a state of steep bogglement.\n");
      return 1;
   }

   /* Guild powers cannot be used against others in PK. */   
   if(ob->is_player()) 
   {
      write("You cannot use guild powers against other players!\n");
      return 1;
   }
   
   /* If there is already a spell object here, we cannot cast. */
   ersob = present(idstr, room);
   if(ersob)
   {
      write("You must wait.\n");
      return 1;
   }

   /* Let the game player object audition the attacker */
   if(!this_player()->valid_attack(ob)) return 1;
   
   /* recalc, randomized and 'bonus' potential damage */
   this_player()->add_spell_point(-limit);

   /* Chance of failure dependent on willpower.
    * BEST CASE - 1/20 chance.
    */
   if(random(this_player()->query_attrib("wil")) == 1) 
   {
      write("You goofed and screw up.\n");
      return 1;
   }
   
   /* Tell the room what is happening */
   write(swm + (ob->query_name()) + swpm + "\n");
   remote_say(ssm  + (ob->query_name()) + sspm +"\n");

   /* Clone the rsob and plant it here... */
   rsob = clone_object(rs_file);
   if(!rsob) return 0;
   
   rsob->set_owner(this_player());
   rsob->set_attacker(ob);
   rsob->set_room(room);
   
   move_object(rsob, room);
   
   /* Allow the attacker to attack us! */
   if(ob && !ob->query_ghost() && !ob->query_attack())
      ob->attack_object(this_player());
      
   return 1;
}

/*
 * Arguments:
 *
 * tp           [obj] The object that this is happening from.
 * attacker     [obj] Our attacker object
 * chance       [int] the possibility of this actually engaging, where 1 = random(chance)
 * wmsg         [str] The string message that is told to the local player.
 * smsg         [str] The string message that is told to the rest of the room.
 * wc_divisor   [int] If we want to cut our WC by any divisor, wc = wc/wc_divisor.
 * rcut_chance  [int] The chance that our damage will get cut, where 1 = random(rcut_chance)
 * rcut_divisor [int] The amount our damage will get divided by
 * wbr_chance   [int] The chance our weapon will be broken. The default is 4700000 and 
 *              should be good for 99% of the time.
 * damcap       [int] What our damage cap should be.
 *
 * Returns:
 * 0 if error or attack has missed.
 * 1 if success, and attack has activated and possibly landed.
 */
 
multilimb_synchronized_attack(tp, attacker, chance, wmsg, smsg, wc_divisor, rcut_chance, rcut_divisor, wbr_chance, damcap)
{
   object mob, me, weapon;
   int i, tmp, total_damage;
  
   me = tp;
   if(!me) return 0;
   if(!rcut_chance || rcut_chance < 2) return 0;
   if(!rcut_divisor || rcut_divisor < 2) return 0;
    
   /* No mob, no service */
   mob = present(MORPH_ID, me);
   if(!mob) return 0;
  
   weapon = mob->query_weapon_list();
  
   /* THE SYNCHRONIZED ATTACK */
   
   if(chance == 1 || 1 == random(chance))
   {
      /* If we have something to say, say it */
      if(wmsg && smsg)
      {
         tell_object(me, wmsg);
         me->remote_say(smsg);
      }
            
      while(i < sizeof(weapon)) 
      {
         if(weapon[i] && environment(weapon[i]) == mob) 
         {
            if(wc_divisor < 0)
               tmp = damage_level_filter(weapon[i]->weapon_class() * ((-1) * wc_divisor), mob->query_damage_level_filter());
            else
               tmp = damage_level_filter(weapon[i]->weapon_class() / wc_divisor, mob->query_damage_level_filter());

            /* randomly cut our damage */
            if(1 == random(rcut_chance)) tmp = tmp / rcut_divisor;
            total_damage = total_damage + tmp;
            weapon[i]->count_hit_made();
                  
            if(weapon[i]->query_wear() > 1 && random(wbr_chance / weapon[i]->query_wear()) < 10)
               weapon[i]->weapon_breaks();
                  
             extra_hit(tmp, i, attacker, me);
          }
          else
          {
             /* bare-fisted */
             if(attacker) extra_hit(3, i, attacker, me);
             total_damage += 3;
          }
              
          i++;
       }
            
       /* this cleans up the extra ANSI if there was any*/
       tell_object(me, ESC + "[0m");
       me->remote_say(ESC + "[0m");
            
       if(total_damage > damcap) total_damage = damcap;

       if(attacker && !attacker->query_ghost())
          hit_creature(me, attacker, total_damage);
          
       return 1;
   }  /* END SYNCHRONIZED ATTACK */
   return 0;
}

/*
 * Arguments:
 * tp           [obj] the player that is issuing the hits...
 * attacker     [obj] The thing it is attacking.
 * chance       [int] The chance that the hit will land, where i = random(chance);
 * wmsg         [str] (OPTIONAL) The string message that is told to the local player.
 * smsg         [str] (OPTIONAL) The string message that is told to the rest of the room.
 * wc_divisor   [int] If we want to cut our WC by any divisor, wc = wc/wc_divisor.
 * rcut_chance  [int] The chance that our damage will get cut, where 1 = random(rcut_chance)
 * rcut_divisor [int] The amount our damage will get divided by
 * wbr_chance   [int] The chance our weapon will be broken. The default is 4700000 and 
 *              should be good for 99% of the time.
 *
 * Returns:
 * 0 if error or attack has missed.
 * 1 if success, and attack has activated and possibly landed.
 */
multilimb_cyclic_attack(tp, attacker, chance, wmsg, smsg, wc_divisor, rcut_chance, rcut_divisor, wbr_chance)
{
   object mob, me, weapon;
   int i, tmp, total_damage;

   me = tp;
   if(!me) return 0;
   if(!chance || chance < 2) return 0;
    
   /* No mob, no service */
   mob = present(MORPH_ID, me);
   if(!mob) return 0;
  
   weapon = mob->query_weapon_list();

   /* THE CYCLIC ATTACK */
   while(i < sizeof(weapon)) 
   {
      if(1 == random(chance))
      {
         /* If we have something to say, say it */
         if(wmsg && smsg)
         {
            tell_object(me, wmsg);
            me->remote_say(smsg);
         }
         

         if(weapon[i] && environment(weapon[i]) == mob) 
         {
            if(wc_divisor < 0)
               tmp = damage_level_filter(weapon[i]->weapon_class() * ((-1) * wc_divisor), mob->query_damage_level_filter());
            else
               tmp = damage_level_filter(weapon[i]->weapon_class() / wc_divisor, mob->query_damage_level_filter());

            if(1 == random(rcut_chance)) tmp = tmp / rcut_divisor;
            total_damage = total_damage + tmp;
            weapon[i]->count_hit_made();
                     
            if(weapon[i]->query_wear() > 1 && random(wbr_chance / weapon[i]->query_wear()) < 10)
               weapon[i]->weapon_breaks();
                     
            if(attacker) extra_hit(tmp, i, attacker, me);
         }
         else
         {
            /* bare-fisted */
            if(attacker) extra_hit(3, i, attacker, me);
            total_damage += 3;
         }

         /* this cleans up the extra ANSI if there was any*/
         tell_object(me, ESC + "[0m");
         me->remote_say(ESC + "[0m");

      } /* end while random */
   i++;
   }


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
   if(arg > (MAGIC_DAMAGE_CAP + 30)) tmp = "over the legal limit";
   else if(arg > MAGIC_DAMAGE_CAP) tmp = "devastating";
   else if(arg > 40) tmp = "bone crushing";
   else if(arg > 30) tmp = "smashing";
   else if(arg > 20) tmp = "very hard";
   else if(arg > 10) tmp = "some hard";
   else if(arg > 5) tmp = "some";
   else if(arg > 3) tmp = "grazing";
   else if(arg == 1) tmp = "tickling";
   else tmp = "no";
   
   write("**You feel you did " + tmp + " damage from that attack.\n");
   return 1;
}

damage_level_filter(arg, dam_factor)
{
   if(dam_factor == 0)
   {
      /* We half the damage inflicted here no matter what. */
      return (arg / 2);
   }
   else if(dam_factor == 1)
   {
      /* We return 1/2 to 2/3 of the damage here */
      if(1 == random(3))
         return (arg * 2) / 3;
      else return (arg / 2);
   }
   else if(dam_factor == 2)
   {
      if(1 == random(3))
         return arg;
      else return (arg * 5) / 8;
   }
   else if(dam_factor == 3)
   {
      if(1 == random(2))
         return arg;
      else return (arg * 2) / 3;
   }
   else return arg;
   
}

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
   object ob, gob, person;
   string how,what,type,escape_seq;
   int dam,tmp;

/*
 * apr 95
 * i fixed this to work with the single hit proposal by boltar
 * to hit_player() check the poly morph objects for damage 
 * caps- they are the and are set to 50 max per round each. 
 */
 
/* WHAT IS HAPPENING HERE:
 * This function serves mostly to make a fancy emote describing the
 * kind of damage being inflicted on a player. The resulting damage
 * is then queued to the player's GUILD OBJECT and every fake_beat()
 * if there is attacker it gets hit with the damage.
 *
 * The damage cap is being applied THERE.
 * The opponent is also not dealt enough damage to really kill, this
 * is done to prevent the double-death problem that can occur if the
 * non-natural hit gets the parting shot. Damage cap is 40 HP/r at the
 * time of this writing.
 *
 * Also note that i have two types of damage cap defined in definitions.h
 * One is magic, and the other extra limbs.
 */

   type = get_type(inum);
   tmp = dpi;
   
   dam = random(tmp);

   if(me) person = me;
   else person = this_player();
   
   if(!person) return;
   gob = present(GUILD_ID, person);

   /* If there is ANSI we send it */   
   if(escsq) 
   {
      escape_seq = escsq;
      tell_object(person, escape_seq);
   }

   /* If a player is not stealthy enough they will miss */   
   if(random(person->query_attrib("ste")) < 5) 
   {
      tell_object(person, "Your " + type + " attack missed.\n");
      person->remote_say((person->query_name()) + " misses " +
         (person->query_possessive()) + " " + type + " attack.\n");
      return 0;
   }
   
   /* Cycle through the descriptions */
   how = " to a bloody pulp";
   what = "massacre";

   if(dam < COMBAT_DAMAGE_CAP) { how = " to small fragments"; what = "massacre"; }
   if(dam < 30) { how = " with a bone crushing sound"; what = "smashed"; }
   if(dam < 20) { how = " very hard"; what = "hit"; }
   if(dam < 10) { how = " hard"; what = "hit"; }
   if(dam < 5) { how = ""; what = "hit"; }
   if(dam < 3) { how = ""; what = "grazed"; }
   if(dam == 1) { how = " in the stomach"; what = "tickled"; }
   ob = atk;

   /* Don't proceed if they are dead... */
   if(!ob || ob->query_ghost()) return 0;

   /* display messages to player and the room*/
   tell_object(person, "You " + what + " " + 
      (ob->query_name()) +  how + " with your " +
      type + " attack.\n");

   person->remote_say((person->query_name()) + " " + what +
      " " + (ob->query_name()) + how +
      " with " + (person->query_possessive()) + " " +
      type + " attack.\n");

   /* If the creature is about to die, dont kill them!! */
   if(ob->query_hp() <= dam) 
   {
      tell_room(environment(person), (ob->query_name()) + " " + critical_hit_msg() + "\n");
      dam = ob->query_hp() - 1;
   }

   /* Finish off the ANSI if there is any. */
   if(escape_seq) tell_object(person, (ESC + "[0m"));

   if(gob)
      gob->add_damage_spool(dam);

   return 0;
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

   /* Negative damage BAD! */
   if(!ob || damage <= 0) return 0;

   /* Note that this function is ONLY called for magic damage hits.
    * Extra limb hits are handled in the heartbeat of the gob.
    */
   if(dam > MAGIC_DAMAGE_CAP) dam = MAGIC_DAMAGE_CAP;

   /* Added by Snow 3/99 to help avoid call_out killing */
   if(ob->query_ghost()) return;

   if(dam <= 0) return;
   
/* added 90% chance rather than 100% ..
   holy shit it takes some friggin' time to kill sometimes.
    -verte
*/
   if(random(10))
     if(dam >= ob->query_hp()) dam = ob->query_hp() / 2;
   
   if(dam > 1) ob->hit_player(dam);
}

/*
 * There will be no 'strap all' cos I didnt really like the idea.
 * Ok, the truth is that i am such an incompetent coder it never
 * worked right when i tried it.
 *
 * ARGS:
 * str - string; the id name of the weapon
 * max - int; the max weight of the weapon
 *
 */
strap_weapon(str, max) 
{
   int i, j, ok_flag, weapon_limit;
   object mob, weapon, ob, oc;
   status a;
   
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   
   weapon_limit = mob->query_weapon_limit();
    
   weapon = mob->query_weapon_list();
   if(sizeof(weapon) < (weapon_limit - 2)) return 0;
   
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
   
   /* when a player does 'strap all' */
   if(str == "all")
   {
      ob = all_inventory(this_player());
      
      for(j = 0; j < sizeof(ob); j++)
      {

         a = 0;
         
         /* if the object is a weapon and its not what we are wielding... proceed */
         if(ob[j]->weapon_class() && this_player()->query_weapon() != ob[j]) 
         {  
            /* let us see if we can strap the weapon */
            i = 0;
            while(i < sizeof(weapon)) 
            {
               /* no weapon[i]? Good! That means a free slot to strap to */
               if(!weapon[i] && !a) 
               {
                  /* weapon too heavy... no good */
                  if(max && ob[j]->query_weight() > max)
                  {
                     if(ob[j]->short()) write(ob[j]->short() + " is too heavy.\n");
                  }
                  else
                  {
                     a = 1;
                     weapon[i] = ob[j];
                     weapon[i]->set_hit_func(this_player());
                     write("You strap " + (ob[j]->short() ? lower_case(ob[j]->short()) : "it") + " as a " + get_type(i) + " weapon.\n");
                     remote_say((this_player()->query_name()) + " wields " + 
                        (weapon[i]->short() ? lower_case(weapon[i]->short()) : "something") + " as a " + get_type(i) + " weapon.\n");
                     move_object(weapon[i], mob); 
                  }
               }
               i ++;
            }
            
            /* we didnt strap this... */
            if(!a && ob[j]->short())
               write(ob[j]->short() + " (NOT STRAPPED)...\n");

         }

      } /* end for() */

      mob->set_weapon_list(weapon);
      
      write("Done.\n");
      return 1;
   }

   else

   {
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
      
      if(max && ob->query_weight() > max)
      {
         write(ob->short() + " is too heavy to be strapped.\n");
         return 1;
      }
      
      while(i < sizeof(weapon)) 
      {
         if(!weapon[i] && !ok_flag) 
         {
            ok_flag = 1;
            weapon[i] = ob;
            weapon[i]->set_hit_func(this_player());
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

/*
 * What this function does is displays the proper contents of a MOB.
 * Sometimes the mob will contain objects that have been gobbled up.
 * Sometimes it will contain weapons that are strapped.
 * Soemtimes both items are in there.
 * We need to properly display and render both types of items.
 *
 * Inputs:
 * arg - our MOB
 * str - String attached to MOB
 */
multiweapon_mob_short(arg, str) 
{
   object mob, weapon, ob;
   string temp;
   int i,a, weapon_match;
   
   mob = arg;
   if(!arg) return 0;
   weapon = mob->query_weapon_list();
   weapon_match=0;
   temp = "";

   /* Render the objects */
   ob = all_inventory(mob);
   
   for(i = 0; i < sizeof(ob); i++)
   {
       /* this is kludgey. If the object is already on
        * the weapon list we need to change the desc for it */
       weapon_match=0;
              
       for(a = 0; a < sizeof(weapon); a++)
       {
         /* if this is a match it is a strapped weapon */
         if(ob[i] == weapon[a] && weapon_match == 0)
         {
            temp = temp + (ob[i]->short()) + " (wielded " + get_type(a) + ").\n";
            weapon_match = 1;
         }
       }
       
       if(weapon_match == 0) temp = temp + ob[i]->short() + " (gobbled).\n";

   }

   /* now add the tag line */
   temp = temp + str;
   
   /* done! */
   return temp;
}

unstrap_all(arg) 
{
   object person,mob,ob,room;
   int i;
   person = arg;
   room = environment(person);
   if(!person || !room) return 0;
   mob = present(MORPH_ID, person);
   if(!mob) return 0;
   
   /* unstrap the weapons first... */
   ob = mob->query_weapon_list();
   for(i = 0; i < sizeof(ob); i ++)
   {
      if(ob[i])
      {
          tell_object(person, "You unstrap " + ((string)ob[i]->short() ?  lower_case(ob[i]->short()) : "it") + ".\n");
          person->remote_say((person->query_name()) + " stops wielding " +
             (ob[i]->query_name()) + " as a " + get_type(i) + " weapon.\n");
          move_object(ob[i], person);
          ob[i] = 0;
      }
   }

   /* now deal with other objects */
   ob = all_inventory(mob);
   for(i = 0; i < sizeof(ob); i ++) 
   {
      if(ob[i]) 
      {
          /* if the object is not a weapon we spit it out onto the ground... */
          /* We have to drop to the ground because the weight carried was relative
           * to that of the sphere... 
           */
          move_object(ob[i], room);
          tell_room(room, (ob[i]->short()) + " falls to the ground.\n");
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
   if(num == 3) type = "quinary";
   if(num == 4) type = "senary";
   if(num == 5) type = "septenary";
   if(num == 6) type = "octonary";
   if(num == 7) type = "nonary";
   if(num == 8) type = "denary";
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

   if(strlen(hd) > 50) 
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
      new_hd = "[Spuck, " + ctime(time()) + "]  " + arg;
   new_hd = "[" + capitalize(this_player()->query_real_name()) +
   ", " + ctime(time())+ "]  " + arg;
   
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
   
   if(!arg)
   {
     write("Gobble what object?\n");
     return 1;
   }

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
   if(!arg) return 0;
   mob = present(MORPH_ID, this_player());
   if(!mob) return 0;
   room = environment(this_player());
   if(!room) return 0;

   if(!arg)
   {
     write("Spew what object, spunky?\n");
     return 1;
   }
   
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
   
   if(str == this_player()->query_real_name())
   {
     write("I'm sure you would really like to do that.\n");
     return 1;
   }
   
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
   
   if(!str || str =="")
   {
     write("Drag what object?\n");
     return 1;
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

wombat_chomp(arg) 
{
   single_attack(WOMBAT_CHOMP_COST,arg,
      
      "You bare your teeth and viciously take chomp ","!",
      (this_player()->query_name()) + " chomps ", " and bites off some of its flesh!");
   return 1;
}


/* ---- SPONGE spells [3]--- */

sponge_sponge(arg) 
{
   object ob,atk;
   
   if(!arg)
   {
     write("Sponge hits for whom?\n");
     return 1;
   }
   
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

sponge_evaluate(str) 
{
   object ob;
   int i;
   
   if(!check_sp(SPONGE_EVALUATE_COST)) return 1;
   
   if(!str) return 0;
   
   ob = present(str, environment(this_player()));

   if(!ob) 
   {
      write("There is no '" + str + "' here.\n");
      return 1;
   }

   if(!living(ob)) 
   {
      write((ob->short()) + " appears to be a " + str + ".\n");
      return 1;
   }

   write((ob->query_name()) + " ");
   i = ob->query_ac();
   
   /* now chain eval the ac */
   if(i > 50)
      write("appears to be absolutely invincible... Protected like a GOD!\n");
   else if(i > 40) 
      write("appears to be built hella tough... like Mr. T!\n");
   else if(i > 30)
      write("appears to be as well protected as a main battle tank!\n");
   else if(i > 20)
      write("appears to be as well protected as a bank vault!\n");
   else if(i > 15)
      write("appears to be the definition of well armored protection!\n");
   else if(i > 13)
      write("appears to be extremely well protected and armored.\n");
   else if(i > 11)
      write("appears to be very adequately armored and protected.\n");
   else if(i > 9)
      write("appears to be adequately armored and protected.\n");
   else if(i > 7)
      write("appears to be decently armored.\n");
   else if(i > 5)
      write("appears to have basic armor.\n");
   else if(i > 3)
      write("appears to have very minimal armor and protection.\n");
   else if(i > 0)
      write("appears to basically unarmored.\n");
   else if(i == 0)
      write("appears to be completely unarmored, like a bare naked Beano.\n");
   else
      write("appears to be QUITE screwed, with a red target painted on their back.\n");
   
   remote_say((this_player()->query_name()) + 
      " slowly examines " + (ob->query_name()) + "'s armor very carefully.\n");
   tell_object(ob, (this_player()->query_name()) + 
      " sniffs at your general direction.\n");
   return 1;
}

/* ---- BLOBEL spells [3]--- */

blobel_deepsurvey() 
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
   
   if(!arg || arg=="")
   {
     write("Tuck what object?\n");
     return 1;
   }
   
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

   if(!ob)
   {
     write("You stump yourself in an array of confusion.\n");
     return 1;
   }

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
   
   if(!str)
   {
     write("Gain what to what?\n");
     return 1;
   }
   
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

   if(!arg || arg=="")
   {
     write("Holler at whom?\n");
     return 1;
   }

   if(arg == this_player()->query_real_name())
   {
     write("Don't be stupid.\n");
     return 1;
   }
   
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
   
   write("That felt dandy, didn't it?\n");
   remote_say((this_player()->query_name()) + " does the disco duck.\n");
   return 1;
}

/* ---- OCTOPUS spells [4]--- */

octopus_inkjet()
{
   object att;
  
   if(!check_sp(OCTOPUS_INKJET_COST)) return 1;
  
   att = this_player()->query_attack();
   if(!att)
   {
     write("You can only do this when you are fighting something.\n");
     return 1;
   }
  
   this_player()->add_spell_point(-OCTOPUS_INKJET_COST);
   
   write("You squit your insides and a BLAST OF INK explodes all over " + att->query_name() + "!\n");
   remote_say((this_player()->query_name()) + " sprays a wave of jet black ink all over " + att->query_name() + "!\n");
   
   att->stop_fight();
   att->stop_fight();
   att->stop_hunter();
   att->stop_hunger();
   att->attack_object();
   att->attack_object();
   
   this_player()->stop_fight();
   this_player()->stop_fight();
   this_player()->stop_hunter();
   this_player()->stop_hunter();
   this_player()->attack_object();
   this_player()->attack_object();

   write("\nYou flee in panic!!\n\n");
   this_player()->run_away();   
  
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

bogglemancer_charbroil(arg) 
{
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

/* note that the gobble and spew of spuckball is used */

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
   
   if(!arg)
   {
     write("Hwarf what item?\n");
     return 1;
   }

   ob = present(arg, mob);
   
   if(!ob) 
   {
      write("Funny, you don't remember gobbling up that item.\n");
      return 1;
   }
   
   /* This divisor is the norm */
   dam = (ob->query_value() / 15);
   if(dam > MAGIC_DAMAGE_CAP) dam = MAGIC_DAMAGE_CAP;

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

/* ---- DIVYA SPELLS [6] --- */
divya_lswords(arg) 
{
   closer_attack(DIVYA_LSWORDS_COST,arg,
      "You phase an ethereal dagger into existence and it fades into view, spinning wildly.\n"+
      "You cry: 'LUNGING SWORD!' and it rockets at ","!",
      (this_player()->query_name()) + " folds in an ethereal dagger, spinning wildly.\n" +
      (this_player()->query_name()) + " cries 'LUNGING SWORD!' and it rockets at ",
      "!\n");
   return 1;
}

divya_dswords(arg)
{
   callout_attack(DIVYA_DSWORDS_COST, DIVYA_DSWORDS_ID, DIVYA_DSWORDS_FILE, arg, 
      ESC + "[1m" + ESC + "[36m" + "You gate in a set of six ethereal swords and they fade into view.\n"+
      "You cry: 'DANCING SWORDS!' and they begin to spin rapidly around ","!" + ESC + "[0m" + ESC + "[0m",
      ESC + "[1m" + ESC + "[36m" + (this_player()->query_name()) + " gates in a set of six ethereal swords.\n" +
      (this_player()->query_name()) + " cries 'DANCING SWORDS!' and they begin to spin rapidly around ",
      "!" + ESC + "[0m" + ESC + "[0m" + "\n");
   return 1;
}

/* bail out of combat */
divya_switch()
{
   object att;
  
   if(!check_sp(DIVYA_SWITCH_COST)) return 1;
  
   att = this_player()->query_attack();
   if(!att)
   {
     write("You can only do this when you are fighting something.\n");
     return 1;
   }
  
   this_player()->add_spell_point(-DIVYA_SWITCH_COST);
   
   write("You fold a warp in space at " + att->query_name() + "!\n");
   remote_say((this_player()->query_name()) + " folds a warp in space over " + att->query_name() + 
      ", confusing " + att->query_objective() + " momentarily!\n");
   
   att->stop_fight();
   att->stop_fight();
   att->stop_hunter();
   att->stop_hunger();
   att->attack_object();
   att->attack_object();
   
   this_player()->stop_fight();
   this_player()->stop_fight();
   this_player()->stop_hunter();
   this_player()->stop_hunter();
   this_player()->attack_object();
   this_player()->attack_object();

   write("\nYou switch away from the room!!\n\n");
   this_player()->run_away();   
  
   return 1;
}

/* hide invisibly */
divya_egress()
{
   object uh, frm;
   uh = present(GUILD_ID, this_player());

   if(!uh) return 0;
   if(!check_sp(DIVYA_EGRESS_COST)) return 1;

   if(this_player()->query_attack())
   {
      write("It costs more to do this while fighting...\n");
      if(!check_sp(DIVYA_EGRESS_COST / 2)) return 1;
   }
   
   write("You mutter: EGRESS...\n");
   write("You concentrate intently and zap yourself into another reality.\n");
   
   remote_say(this_player()->query_name() + " the divya says: EGRESS...\n");
   remote_say(this_player()->query_name() + " disappears in a blinding flash!\n");

   frm = clone_object(DIVYA_EGRESS_FORM);
   frm->set_owner(this_player()->query_real_name());
   move_object(frm, environment(this_player()));
   move_object(this_player(), frm);
   
   return 1;
}


/* ---- NECROMONGER SPELLS [6] --- */
necromonger_cloudkill(arg) 
{
/* TODO 
 * This ability needs to work better when the critters are close to dying 
 */
 
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
necromonger_jerky(str)
{
   object ob,gob;
   int x,i;

   /* some checking */
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
   
   write("You charge the matter energy of the corpse into your sphere.\n"+
      "It begins to glow and shrink, as its matter is converted to pure energy.\n");
   remote_say((this_player()->query_name()) + " kneels to the ground next to " + lower_case(ob->short()) + ".\n");
      
   remote_say("It shrivels and disappears.\n");
   gob->add_charge(x);
   write("There are [" + (gob->query_charge()) + "] charges in the clay's matrix.\n");
   destruct(ob);
   return 1;
}

/* create a pet out of a corpse */
necromonger_animate(str)
{
}

necromonger_cold(arg) 
{
   single_attack(NECRO_COLD_COST,arg,
      "You touch "," and inhale some of its pathetic lifeforce!",
      (this_player()->query_name()) + " touches ",
      " and sucks some of the life from it.");
   return 1;
}

/* ---- BABOON SPELLS [6] --- */
baboon_feces(arg)
{
   single_attack(BABOON_FECES_COST,arg,
      "You throw a handful of feces at ","!",
      (this_player()->query_name()) + " hoots loudly and hurls a handful of feces at ","!\nSPLAT!!!");
   return 1;
}

/* ---- DARK TETRAPOD SPELLS [7] --- */

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
   
   if(sscanf(arg, "%d", i) != 1) return 0;
   if(!i) return 0;
   
   if(i < 0 || i > max)
   {
      write("You have [" + max + "] charges in your clay.\n");
      return 1;
   }

   /* conversion isnt totally efficient, like 3/5 */
   max = (max * 3) / 5;

   write("You draw energy from the clay and are invigorated!\n");
   remote_say((this_player()->query_name()) + " glows and crackles with a silent hum of power momentarily.\n");

   this_player()->add_hit_point(max);
   gob->add_charge(-max);
   check_points();
   return 1;
}

/* hide invisibly */
dark_tetrapod_cloak()
{
   object uh, frm;
   uh = present(GUILD_ID, this_player());

   if(!uh) return 0;
   if(!check_sp(DARK_TETRAPOD_CLOAK_COST)) return 1;

   if(this_player()->query_attack())
   {
      write("It costs more to do this while fighting...\n");
      if(!check_sp(DARK_TETRAPOD_CLOAK_COST / 2)) return 1;
   }
   
   write("You mutter: CLOAK...\n");
   write("You concentrate intently and fade from view.\n");
   
   remote_say(this_player()->query_name() + " the dark tetrapod says: CLOAK...\n");
   remote_say(this_player()->query_name() + " fades from view.\n");

   frm = clone_object(DARK_TETRAPOD_CLOAK_FORM);
   frm->set_owner(this_player()->query_real_name());
   move_object(frm, environment(this_player()));
   return 1;
}

dark_tetrapod_calm() 
{
   object ob;
   
   /* Use shoutbox's amount... */
   
   if(!check_sp(SHOUTBOX_CALM_COST)) return 1;
   write("You cast preclusion and call an end to the fighting.\n");
   remote_say((this_player()->query_name()) + " casts preclusion and calls an end to the fighting.\n");
   
   this_player()->add_spell_point(-SHOUTBOX_CALM_COST);
   if(1 == random(this_player()->query_attrib("wil")))
   {
      write("However... something messed up.\n");
      remote_say("However, something messed up.\n");
      return 1;
   }
   
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
   
   write("You smirk.\n");
   remote_say((this_player()->query_name()) + " smirks.\n");
   return 1;
   
}

/* ---- FIREWALL SPELLS [7] --- */
firewall_halt()
{
   object ob;
   if(!check_sp(FIREWALL_HALT_COST)) return 1;
   write("You bellow: 'FIGHTING#shutdown now!'\n");
   remote_say((this_player()->query_name()) + " bellow: 'FIGHTING#shutdown now!'\n");
   
   this_player()->add_spell_point(-FIREWALL_HALT_COST);
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
   
   write("You burp loudly.\n");
   remote_say((this_player()->query_name()) + " burps loudly.\n");
   return 1;
}

