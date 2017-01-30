/* 11/22/05 Earwax: added color to the song :) */

inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#include "definitions.h"
#include <ansi.h>

#if 0 /* Gnar */
inherit "/players/mizan/closed/poly/mob.c";
#endif

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

string theme_song;
int song_bar;
string song_colors;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A fuzzy brown sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of a big, three-armed furry brown creature with an incredibly big\n"+
  "mouth and teeth. You feel like Mr. Born To Destroy! RAAARGH!\n"+
  "This sphere contains your matrix of regneration for a loafy.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("wumpus");
   set_multilimbed(2);
   set_weapon_wlim(3);
   set_deathtime(3000);
   set_weight_limit(30);
   set_block_wimpy();
/*
   set_block_magic();
 */
   song_bar = 0;

   theme_song = ({
    "It is the Wumpus!",
    "It's going to get you!",
    "When you least expect it! The Wumpus will get you!",
    "Because the Wumpus...",
    "...The Wumpus is fearsome!",
    "So you had better kiss your butt goodbye!",
    "The Wumpus is crazy... The Wumpus will kill you!",
    "The Wumpus will rip your throat OUT!",
    "Wumpus is all about cranial mutilation!",
    "The Wumpus is badass.. but we all know that!",
    "The Wumpus will kick... your... butt... tonight!",
    "Wumpus, Wumpus, will kick some bloody rear!",
    "Look out for the Wumpus cos its a killer!",
    "Whoa! The Wumpus is coming for your head...",
    "Keep it up, keep it up, die at the hands of the Wumpus!",
    "Beeeyotch! Wumpus is gonna stick a tin can in yo' butt!",
    "The Wumpus TAUNTS you like the little BEANO that you are!",
    "Wumpus kill, Wumpus kill, Wumpus kill!",
    "The Wumpus is gonna beat your ass, doodah, doodah!",
    "If I were a Wumpus... I would be so happy!",
    "But i'm not a Wumpus... so i'll run quickly!",
    "Because the Wumpus is born.. to.. Destroy!",
    "Fee.. Fi.. Foe.. Fum.. I think I smell a Wumpus kicking butt!",
    "Hey look! It's a Wumpus!",
    "Wumpus eats the CHILI!",
    "Wumpus eats the TACO!",
    "Wumpus eats the BEAN...BURRITO!",
    "Wumpus eats the ONION SOUP!",
    "Wumpus eats the STINKY FRUIT!",
    "Violent fart! Wow that smarts! The Wumpus is gaseous tonight!",
    "Violent fart! Gas that kills!",
    "Makes you wish you were a Wumpus!",
    "The Wumpus is here to kick some butt, hurrah, hurrah!",
    "The Wumpus is here to kick some butt, HURRAH! HURRAH!",
    "You won't have a chance, so do that silly dance...",
    "Bend over and kiss your ass goodbye HURRAH! HURRAH!",
    "The Wumpus... now in 'kickass action hero' flavor too!",
    "The Wumpus will be BAAAHCK.",
    "YO ADRIAN!! The Wumpus is here to kick some behind!",
    "Yeah, that's right. His real name is Jackie 'The Wumpus' Chan!",
    "Step it up yo, step it up... The Wumpus is in town!",
  });

  song_colors = ({
    RED, BLK, GRN, YEL, BLU, MAG, CYN, WHT,
    HIK, HIR, HIG, HIY, HIB, HIM, HIC, HIW
  });

} 
 
init()
{
   ::init();
   add_action("wumpus_defecate","defecate");
}

extra_look() 
{
  if(ENV) return (ENV->query_name()) + 
     " is big, brown, and furry, and seems to have three arms.\n";
}

random_emote()
{
      /* RANDOM EMOTES */
      if(1 == random(200)) 
      {
         tell_object(ENV, "You fart violently.\n");
         ENV->remote_say((ENV->query_name()) + " farts violently!\n");
      }

      if(1 == random(220)) 
      {
         tell_object(ENV, "You scratch yourself.\n");
         ENV->remote_say((ENV->query_name()) + " scratches " + ENV->query_objective() + "self.\n");
      }
  
      if(1 == random(80)) 
      {
         tell_object(ENV, "You go 'RAAAAAAR!'.\n");
         ENV->remote_say((ENV->query_name()) + " bellows to the room: 'RAAAAAR!'\n");
      }

      if(1 == random(220)) 
      {
         tell_object(ENV, "You grin biggly.\n");
         ENV->remote_say((ENV->query_name()) + " grins biggly.\n");
      }

      if(1 == random(220)) 
      {
         tell_object(ENV, "You sniff yourself.\n");
         ENV->remote_say((ENV->query_name()) + " sniffs itself.\n");
      }
}

/* this has been redone to fit the new damage system */
fake_beat() 
{
   object attacker;
   int i, j, total_damage;
   int tmp;
   
   /* Total damage should not exceed 50 per round. */
   if(ENV)
   {
     attacker = ENV->query_attack();
     if(!attacker) random_emote();

     /*Put in ghost check due to double deaths -Snow 4/99 */

     if(attacker && !ENV->query_ghost())
      {
         /* THE THEME SONG */
         if(1 == random(2))
         {
            wumpus_theme_song();
         }
      
         /* What's happening here looks crazy but its actually quite
          * simple. One of two attack types will happen.
          *
          * (3/4ths of the time...)
          * Cyclic: Only one extra arm per round will engage, randomly
          * during the combat round. This gives the player a
          * strike that is halfway between tetrapod and golem.
          *
          * (1/4th of the time...)
          * Synchronized: All arms will engage and strike the target
          * at once. This is the fun one.
          */

         j = MASTER_R->multilimb_synchronized_attack(
                ENV,         /* ourselves */
                attacker,    /* our attacker */
                3,           /* The chance of this attack hitting, in this case 1 / x of the time */
                ESC + "[1m" + ESC + "[31m" + "You grunt violently and find your beat!" + ESC + "[0m\n" + ESC + "[1m" + ESC + "[37m",
                ENV->query_name() + " grunts wildly and lunges to attack!\n" + ESC + "[1m" + ESC + "[37m",
                1,           /* The WC divisor applied to our strapped weapons, where = to 1 / x */
                8,           /* The chance our WC gets gutted for no reason, where = to 1 every x rounds */
                2,           /* The divisor we get gutted, where damage = to damage / x hitpoints */
                4700000,     /* The divisor our our weapon breakage. Can be tweaked to break sooner */
                COMBAT_DAMAGE_CAP);  /* The max cumulative damage per round that can be done */
             
         if(!j) MASTER_R->multilimb_cyclic_attack(
                   ENV,       /* ourselves */
                   attacker,  /* our attacker */
                   2,         /* The chance that the hit lands, where for each arm 1 / x chance hits */
                   0,         /* A string that we tell ourselves */
                   0,         /* A string everyone else sees */
                   1,         /* The divisor applied to our WC on each limb. Default is 1. */
                   8,         /* The chance we get gutted, where = 1 per every x combat round */
                   2,         /* the divisor for what we gut our damage, where damage = damage / x hitpoints */
                   4700000);  /* Our weapon breakage divisor */       
         
      } /* end of if ATTACKER */

   } /* end of if ENV */

   ::fake_beat();
}

wumpus_theme_song()
{
   if(theme_song)
   {
     /* 11/21/05 Earwax: made it colorful :) */
     if(song_bar == (sizeof(theme_song) - 1)) song_bar = 0;
     tell_object(ENV, song_colors[random(16)]+U
       +"A little birdie sings: '" + theme_song[song_bar] + "'\n" +NORM);
     ENV->remote_say(song_colors[random(16)]+U
       +"A little birdie sings: '" + theme_song[song_bar] + "'\n" +NORM);
     song_bar ++;
   }
}

wumpus_defecate()
{
    return MASTER_R->wumpus_defecate();
}

