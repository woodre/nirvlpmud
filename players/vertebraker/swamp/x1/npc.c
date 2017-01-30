#define MLOG "/players/vertebraker/log/Monster"

#include "/players/vertebraker/ansi.h"

/* gatortooth barter npc. */

inherit "/players/vertebraker/closed/std/monster";

#define Start "/players/vertebraker/swamp/village/path3"

#define BIG "players/vertebraker/swamp/OBJ/gator_tooth"
#define LIL "players/vertebraker/swamp/OBJ/young_tooth"
#define OBJDIR "/players/vertebraker/swamp/x1/"


object necklace;

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("gator hunter");
    set_alias("hunter");
    set_short("A gator hunter");
    set_long("\
He wears a tilted brim panama hat upon his head, and\n\
short, curly brown locks fall down just beneath his\n\
ears.  Long green cargo pants are tucked into thick brown\n\
galoshes.  A fishing vest, soiled with dirt and mud\n\
wraps around his shoulders.  He wears a necklace of teeth\n\
around his neck.\n");
    set_gender("male");
    set_race("human");
    set_al(-10); /* a bit unscrupulous */
    move_object(clone_object(OBJDIR + "g-knife"), this_object());
    move_object(clone_object(OBJDIR + "g-vest"), this_object());
    move_object(clone_object(OBJDIR + "g-boots"), this_object());
    necklace = clone_object(OBJDIR +  "g-necklace");
    necklace->set_teeth(6, 1);
    move_object(necklace, this_object());
    command("wield knife");
    command("wear vest");
    command("wear boots");
    command("wear necklace");
    set_level(22); /* stats per mguide */
    set_ac(armor_class - 5); /* compensate for worn armor */
    set_wander(30, 0);
    set_chat_chance(5);
    load_chat("The hunter looks around.\n");
    load_chat("The hunter frowns.\n");
    load_chat("The hunter runs a hand over his necklace.\n");
    load_chat("The hunter glances at the ground.\n");
    load_chat("The hunter looks to the west.\n");
    load_chat("The hunter fiddles with something in his vest.\n");
    load_chat("The hunter says: 'Got any gator teeth?  I'll buy.'\n");
    load_chat("The hunter mumbles: 'Everyone I love is dead.'\n");
    add_money(100 + random(200));
    set_ac_bonus(10); /* do_damage stuff */
    set_wc_bonus(27); /* swing_knife()[18] + side_slash()[18/2] */
    set_dead_ob(this_object());
}

void
swing_knife()
{
    object x;

    tell_object(attacker_ob, "\n\
\tThe hunter slashes violently at you with his knife!\n" + 
RED + "\tBlood" + NORM + " drips from your open wound.\n\n");
    tell_room(environment(), "\
The hunter slashes violently at " + 
(string)attacker_ob->query_name() + " with his knife!\n", ({ attacker_ob }));
    if(x = environment(attacker_ob))
      tell_room(x, RED + "\
Blood" + NORM + " drips from " +
(string)attacker_ob->query_name() + "'s open wound.\n",
       ({ attacker_ob }));

    attacker_ob->hit_player(40 + random(15));
}

void
side_slash()
{
    tell_object(alt_attacker_ob,  "\n\
\tThe hunter spins backwards and delivers a knife strike\n\
\tdeep into your belly, spinning upwards through your chest.\n\n");
    tell_room(environment(), "\
The hunter spins backwards and delivers a knife strike deep\n\
into " + (string)alt_attacker_ob->query_name() + "'s belly, \
spinning upwards through " + possessive(alt_attacker_ob) + " chest.\n",
    ({ alt_attacker_ob }));

    alt_attacker_ob->hit_player(40 + random(15));
}

void
heart_beat()
{
    object x;
    ::heart_beat();

    if(!(x = environment()))
    {
      dest_inv();
      destruct(this_object());
      return;
    }
    if(creator(x) != "vertebraker")
    {
      tell_room(x, "The gator hunter runs away.\n");
      move_object(this_object(), Start);
    }
    else if(attacker_ob && present(attacker_ob, environment(this_object())))
    {
      if(0 == random(3)) swing_knife();
      if(0 == random(3) && alt_attacker_ob && present(alt_attacker_ob, environment()) &&
       (alt_attacker_ob != attacker_ob))
        side_slash();
    }
}

void
init()
{
    ::init();
    add_action("cmd_barter","barter");
    add_action("cmd_barter","sell");
}

mixed
basename(object ob)
{
    string a, b;

    if(!sscanf(file_name(ob), "%s#%s", a, b))
      return 0;

    else return a;
}

string
defense_mode_heh()
{
    string fuka;

    switch(random(4))
    {
      case 0: fuka = BOLD + "The hunter leaps backwards!\n" + NORM;
         break;
      case 1: fuka = BOLD + "The hunter parries the attack!\n" + NORM;
         break;
      case 2: fuka = BOLD + "The hunter spins to the side!\n" + NORM;
         break;
      case 3: fuka = BOLD + "The hunter dodges " +
           (random(2) ? "left" : "right") + "!\n" + NORM;
         break;
    }

    return fuka;
}

do_damage(string *ya, string *mutha)
{
    int x;
    x = hit_point;
    ::do_damage(ya, mutha);
    if((0 == random(3)) && (hit_point < x) && !dead)
    {
      tell_room(environment(), defense_mode_heh());
      hit_point += (2 + random(3));
      if(hit_point > max_hp)
        hit_point = max_hp;
    }
}

status
cmd_barter(string str)
{
    string b;
    object x, me;

    if(attacker_ob) return 0;

    if(str == "gator tooth" || str == "tooth")
    {
      x = present(str, (me = this_player()));
      if(!x)
      {
        notify_fail("\
The gator hunter shakes his head and says, 'You don't have that.\n");
        return 0;
      }

      b = basename(x);

      if(creator(x) != "vertebraker" ||
        ( (b != BIG) && (b != LIL) ))
      {
        notify_fail("\
The gator hunter inspects the tooth and shakes his head.\n\
'This isn't the kind I am looking for.'\n");
        return 0;
      }

      write("\
The gator hunter inspects the tooth and nods.\n");
      tell_room(environment(),
         (string)me->query_name() + " \
hands the gator hunter a tooth.\n", ({ me }));      

      me->add_weight(-1);
      destruct(x);

      if(b == BIG)
      {
        write("\
The gator hunter smiles a great, broad smile.  He reaches\n\
into his pouch and retrieves a bundle of coins, and hurls\n\
them at you.  'Thank you my friend,' he says.\n");
        if(necklace)
        {
          me->add_money(4000 + random(2000));
          necklace->add_tooth(2);
          tell_room(environment(), "\
The hunter loops the large tooth around his necklace.\n");
        }
      }

      else
      {
        write("\
The gator hunter reaches into his pouch and tosses you\n\
a handful of gold coins.  He smiles and thanks you.\n");
        me->add_money(800 + random(200));
        if(necklace)
        {
          necklace->add_tooth(1);
          tell_room(environment(), "\
The hunter loops the small tooth around his necklace.\n");
        }
      }
      return 1;
    }

    return 0;
}

status
monster_died()
{
    if(attacker_ob)
/*
write_file(MLOG, HIB + "[" + NORM + ctime()[4..15] + HIB
+ "] " + NORM + capitalize((string)attacker_ob->query_real_name()) + " [" +
(int)attacker_ob->query_level() + "+" +
(int)attacker_ob->query_extra_level() + "] - Gator Hunter.\n");
*/
    tell_room(environment(), "\
\n\tThe gator hunter screams a bloodcurdling, primal scream\n\
\tas he heads to his eternal resting ground...\n\n");
    return 0;
}
