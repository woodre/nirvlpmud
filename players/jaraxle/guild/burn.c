/* 

     Burn: Main attack spell

   Coded by Vertebraker@Nirvana (c) 2000

*/

#include "/players/vertebraker/ansi.h"
#include "../people.h"

#include "../std.h"
#include "../def.h"
#include "../tasks.h"
#include "../macros.h"

#define TP   this_player()
#define QN   query_name()
#define RN   query_real_name()
#define TPN (string)TP->QN

inherit CMD;

status main(string who)
{
    int         base, cost, sub, dmg, l, bonus, my_factor, rnd_factor;
    object      x, flames;
    string      g, c;

    needrank(2);
    flames = (mixed)previous_object()->query_flames();
    needtask(FLAMES_TASK);

    if((status)this_player()->query_ghost()) return 0;

    if((int)TP->query_spell_dam())
    {
      if(0 == random(3))
        notify_fail("\
The darkflame crackles within you...\n");
      else if(0 == random(3))
        notify_fail("\
The fire has leapt from you... You cannot summon it again right now.\n");
      else if(0 == random(3))
        notify_fail("\
The dark fire ignores your command...\n");
      else
        notify_fail("\
Flames rise up and fall back down...\n");
      return 0;
    }

    base = random((int)this_player()->query_guild_rank() * 2);

/*
    switch(base)
    {
      case 15..10000: base = 6; break;
      case 12..14:   base = 5; break;
      case 9..11:    base = 4; break;
      case 6..8:    base = 3; break;
      case 4..5:    base = 2; break;
      default:     base = 1; break;
    }
*/
    
/*
    l = (int)this_player()->query_level();
    if(l > 19) l = 19;
    if(random(2)) base += (random(4));
    if((int)previous_object()->GuildClass() == C_MASTER) base += random(3);
    cost = ((base * 5) + random(l));

    sub = (int)this_player()->query_extra_level();

    if(sub > 21) sub = 21;

    if(sub)
    {
      sub = (sub / 3);
      if(sub < 1) sub = 1;
      if(random(3))
      cost -= sub;
    }
*/
    
     base = (int)this_player()->query_guild_rank();
    if(base == 1 || base == 2) { dmg = 5 + random(15); cost = (10 + 7 + random(2)); }
    if(base == 3 || base == 4) { dmg = 10 + random(20); cost = (10 + 10); }
     if(base == 5 || base == 6) { dmg = 10 + random(26); cost = (10 + 13); }
     if(base >= 7) { dmg = 14 + random(28); cost = (14 + 14); }
     if(base == 8) dmg += random(3);
     if((int)previous_object()->GuildClass() == C_MASTER) { dmg += random(3); cost -= random(2); }
    if(!present("shardak_fire", environment(this_player()))) dmg -= (4 + random(4));

    if(dmg < 0) dmg = random(3);
    needmana(cost);

    if(who)
    {
      who = lower_case(who);
      if(!(x = present(who, environment(this_player())))
         || !living(x))
      {
        notify_fail("\
You don't see " + capitalize(who) + " here.\n");
        return 0;
      }
      if(this_player() == x || !this_player()->valid_attack(x))
      {
        notify_fail("\
The dark gods will not permit that...\n");
        return 0;
      }
    }
    else
    {
      x = (mixed)this_player()->query_attack();
      if(!x)
      {
        notify_fail("\
Who do you wish to burn... ?\n");
        return 0;
      }
    }
    if(0 == random(100))
    {
      write(BOLD + BLK + "\
\tYour right hand blazes with intense energy...\n" + NORM);
      bonus += (1 + random(4));
    }
    if(0 == random(2))
    {
      write("\tYou gesture at " + (string)x->QN + "...\n");
      say("\t" + TPN + " gestures at " + 
        (string)x->QN + "...\n", x);
      tell_object(x, "\t" + TPN + " gestures at you...\n");
    }
    else if(0 == random(2))
    {
      write("\tWith a lifted hand, you motion at " 
       + (string)x->QN + "...\n");
      say("\tWith a lifted hand, " 
        + TPN + " motions at " +(string)x->QN + "...\n", x);
      tell_object(x, "\tWith a lifted hand, " +
         TPN + " motions at you...\n");
    }
    else if(0 == random(2))
    {
      write("\tYou glare at " + (string)x->QN 
        + " and wave your hand...\n");
      say("\t" + TPN + " glares at " + (string)x->QN + 
        " and waves " + possessive(TP) + " hand...\n", x);
      tell_object(x, "\t" + TPN + " glares at you and waves " 
        + possessive(TP) + " hand...\n");
    }
    else
    {
      write("\tYou hold your hands out and thrust at " +
        (string)x->QN + "...\n");
      say("\t" + TPN + " holds " + possessive(TP) + " hands out and "
        + "thrusts at " + (string)x->QN + "...\n", x);
      tell_object(x,"\t" + TPN + " holds " + 
        possessive(TP) + " hands " 
        + "out and thrusts at you...\n");
    }
   rnd_factor = (cost * 40 / 60);
   if(rnd_factor < 2) rnd_factor = 2;
   my_factor = (cost * 100 / 300);
   if(random(4)) my_factor += (4 + random(6));
   dmg = my_factor + random(rnd_factor);
    switch(dmg)
    {
/*
        g = "The flames warm " + 
             (string)x->QN + "...";
        c = "The flames warm you...";
        break;
*/
      case 4..7:
        g = "The fire lightly singes " + 
             (string)x->QN + "...";
        c = "The fire lightly singes you...";
        break;
      case 8..11:
        g = "The flames rise up and burn " + 
             (string)x->QN + "...";
        c = "The flames rise up and burn you...";
        break;
      case 12..15:
        g = RED + "Twisting flames blaze into " +
             (string)x->QN + "..." + NORM;
        c = RED + "Twisting flames rise up and blaze into you..."
            + NORM;
        break;
      case 16..19:
        g = RED + "Flames dance around " +
             (string)x->QN + "'s skin, leaving severe burns..."
            + NORM;
        c = RED + "Flames dance around your skin, leaving" +
               " severe burns..." + NORM;
        break;
      case 20..23:
        g = RED + "Scorching, volcanic flames melt through " +
             (string)x->QN + "!" + NORM;
        c = RED + "Scorching, volcanic flames melt through you!\n" 
             + NORM;
        break;
      case 24..27:
        g = RED + "Dark bursts of flame explode all around " +
             (string)x->QN + "!" + NORM;
        c = RED + "Dark bursts of flame explode all around you!"
             + NORM;
        break;
      case 30..33:
        g = RED + "Whirlwinds of tempestuous fire rage through " +
             (string)x->QN + "...." + NORM;
        c = RED + "Whirlwinds of tempestuous fire rage through " +
              "you...." + NORM;
        break;
      case 34..37: g = BOLD + BLK + "Blasts of evil fire rip through " + (string)x->QN + "..." + NORM; c = BOLD + BLK + "Blasts of evil fire rip through you..." + NORM; break;
      case 38..41: g = RED + "Hellfire erupts through " + (string)x->QN + "'s very soul..." + NORM; c = RED + "Hellfire erupts through your very soul..." + NORM; break;
      case 42..43: g = HIR + "The Flames of the Underworld tear through " + (string)x->QN + "!" + NORM + "\n\t" + (string)x->QN + " screams in agony!"; c = HIR + "The Flames of the Underworld tear through you!\n" + NORM + "\tYou scream in agony!"; break;
      case 44..10000:
        g = BLINK + RED + "\
Demonic fire rips through every pore of " + (string)x->QN + "'s \
being...\n" + NORM;
        c = BLINK + RED + "\
Demonic fire rips through every pore of your being...\n" + NORM;
        break;
       default:
        g = "The flames warm " + 
             (string)x->QN + "...";
        c = "The flames warm you...";
        break;
    }

 
    if(flames)
    flames->reduce_strength(1 + random(3));
    tell_room(environment(x), g + "\n", ({ x }));
    tell_object(x, c + "\n");
    if((string)this_player()->query_real_name() == "vertebraker") {
    write("dmg: " + dmg + "\n");
     write("cost: " + cost + "\n");
}
    TP->spell_object(x, "spell of burning", dmg, cost, "", "");
 
    return 1;
}


