#include "../include/ansi.h"

/* Shardak Slayer v0.1 */

#define sd BOLD + "T" + NORM + "he " + BOLD + "S" + NORM + "layer " + BOLD + "S" + NORM + "word"
#define s (string)User->query_name() + "'s"
#define my "your " + BOLD + "S" + NORM + "layer " + BOLD + "S" + NORM + "word"

int life;
status Readied;

status
id(string arg)
{

    object a;

    if((a = previous_object()) && 
       (string)a->query_type() == "shield" && (status)a->is_armor())
      return (arg == "notarmor" || arg == "slayer" || arg == "slayer sword"
              || arg == "sword" || arg == "slayer_sword");

 /* make sure id is okay */
    return (arg == "slayer" || arg == "slayer sword" ||
            arg == "sword" || arg == "slayer_sword");
}

void
set_amt(int amt)
{
    life = amt;
}

void
reset(status arg)
{
    if(arg) return;
    call_out("em_me", 500);
}

string
query_type()
{
    return "sword";
}

void
init()
{
    add_action( "cmdSlayer",  "slayer"  );
    add_action( "cmdTwirl",   "twirl"   );
    add_action( "cmdFlaunt",  "flaunt"  );
    add_action( "cmdWave",    "wave"    );
    add_action( "cmdReady",   "ready"   );
    add_action( "cmdUnready", "unready" );
}

status
shield_check(object ob)
{
    object *all;
    int i, j;

    j = sizeof(all = all_inventory(ob));
    for(i=0;i<j;i++)
      if((string)all[i]->query_type() == "shield" &&
         (status)all[i]->is_armor() &&
         (status)all[i]->query_worn())
        return 1;
    return 0;
}
      

status
cmdSlayer(string arg)
{
    object x;

    if(!arg)
    {
      notify_fail("Syntax: 'slayer [ready/unready]'\n");
      return 0;
    }
    if(arg == "ready")
    {
      if(Readied)
      {
        write(my + " is already readied.\n");
        return 1;
      }
      if(shield_check(this_player()))
      {
        write("\
You cannot ready " + my + " whilst wearing a shield.\n");
        return 1;
      }
      if((x = (object)this_player()->query_weapon()) &&
         (status)x->two_handed())
      {
        write("\
You can't wield this while wielding a two handed weapon.\n");
        return 1;
      }
      write("\
You ready " + my + " in your off-hand.\n" + BOLD + "\
As you wield the mystical weapon, a surge of power runs through you.\n" +
       NORM);
      say((string)this_player()->query_name() + " \
readies " + sd + " in " + possessive(this_player()) + " off-hand.\n");
      Readied ^= 1;
      call_out("attackMess", 2, this_player());
      return 1;
    }
    else if(arg == "unready")
    {
      if(!Readied)
      {
        write(my + " is already unreadied.\n");
        return 1;
      }
      write("You unready " + my + ".\n");
      say((string)this_player()->query_name() + " \
unreadies " + sd + ".\n");
      Readied ^= 1;
      while(remove_call_out("attackMess") != -1);
      return 1;
    }
    else
    {
      notify_fail("\
Not a valid slayer command.\n\
Try slayer 'ready/unready'.\n");
      return 0;
    }
}

status
query_save_flag()
{
    object a;

    if((a = this_player()) && (a == environment()))
      write(sd + " crackles with energy.\n");
    
    return 1;
}

void
em_me()
{
    object User;

    if(!(User = environment()))
    {
      destruct(this_object());
      return;
    }

    else
    {
      object e;

      if(e = environment(User))
      {
        string a, b;

        switch(random(2))
        {
          case 0:
a = "Dark energy pulses through " + my + ".\n";
b = "Dark energy pulses through " + s + " " + sd + ".\n";
           break;
          case 1:
a = "Chaotic lifeforce gleams on the blade of " + my + ".\n";
b = "The blade of " + s + " " + sd + " gleams dimly.\n";
           break;
        }

        tell_object(User, a);
        tell_room(e, b, ({ User }));
      }
    }

    call_out("em_me", 500);
}   

status
drop()
{
    string x;

    if((x = query_verb()) == "drop")
    {
      write("\
As you drop " + sd + ", energy crackles around you,\n\
and then all is still again.\n" + sd + " \
disappears into the earth from which it came.\n");
      destruct(this_object());

      if(this_player())  /* j.i.c. */
        this_player()->recalc_carry();

      return 0;
    }

    return 1;
}

string *
whack_verb()
{
    switch(random(7))
    {
      case 0: return ({ "slice", "slices" });
      case 1: return ({ "slash", "slashes" });
      case 2: return ({ "hack",  "hacks" });
      case 3: return ({ "cut",   "cuts"  });
      case 4: return ({ "slit",  "slits" });
      case 5: return ({ "rend",  "rends" });
      case 6: return ({ "lacerate", "lacerates" });
    }
}

string
body_part()
{
    switch(random(8))
    {
      case 0: return "head";
      case 1: return (random(2) ? "right" : "left") + " leg";
      case 2: return (random(2) ? "right" : "left") + " arm";
      case 3: return "stomach";
      case 4: return "groin";
      case 5: return "chest";
      case 6: return "torso";
      case 7: return "face";
    }
} 

#define EN (string)enemy->query_name()
#define UN (string)user->query_name()
#define v  handle[0]
#define vs  handle[1]

string
genColour()
{
    switch(random(4))
    {
      case 0: return BOLD;
      case 1: return BOLD + BLK;
      case 2: return HIW;
      case 3: return RED;
    }
}

string * load_msgs(int dmg, object enemy, object user)
{
    string *handle, bp, rnd;

    if(!environment() || !environment(environment()))
      return ({ "", "", }); /* verte 6.6.01 */
    rnd = genColour();
    handle = whack_verb();
    handle[0]=rnd+handle[0]+NORM;
    handle[1]=rnd+handle[1]+NORM;
    bp = body_part();

    switch(dmg)
    {
      case 1..5:
        return ({
          "You " + v + " " + EN + "'s " + bp + " with " + sd + ".\n",
          UN + " " + vs + " your " + bp + " with " + sd + ".\n",
          UN + " " + vs + " " + EN + "'s " + bp + " with " + sd + ".\n" });
      case 6..10:
        return ({
          "You gracefully " + v + " " + EN + "'s " + bp + " with " + my + ".\n",
          UN + " gracefully " + vs + " your " + bp + " with " + sd + ".\n",
          UN + " gracefully " + vs + " " + EN + "'s " + bp + " with " + sd + ".\n" });
      case 11..15:
        return ({
          "You brilliantly " + v + " " + EN + " through the " + bp + ".\n",
          UN + " " + vs + " you through your " + bp + ".\n",
          UN + " " + vs + " " + EN + " through the " + bp + ".\n" });
    default:
        return ({
          "You brilliantly " + v + " " + EN + " through the " + bp + ".\n",
          UN + " " + vs + " you through your " + bp + ".\n",
          UN + " " + vs + " " + EN + " through the " + bp + ".\n" });
    }
}
        

void
attackMess( object a )
{
    if( !a )
    {
      destruct( this_object() );
      return;
    }
    else
    {
      int dmg, x;
      object ob;

      if(!(ob = (object)a->query_attack()) ||
         !environment(a) ||
         !present(ob, environment(a)))
     {
       call_out("attackMess", 2, a);
       return;
     }

      if(random(3)) {
      if((dmg = (int)a->query_level()) > 19)
        dmg = 19;

      if((x = (int)a->query_extra_level()) > 21)
        x = 21;

      x /= 5;
      dmg += x;


      dmg += 3 + random(4);
      if((int)ob->hit_player(random(dmg)))
      {
        int heh;
        string *z;

        z=load_msgs(dmg, ob, a);
        tell_object(ob, z[1]);
        tell_object(a,  z[0]); 

        if(environment(ob))
          tell_room(environment(ob), z[2], ({ ob, a }));

        if(!ob->query_ghost())
          {
            if(!random(8) && (status)ob->is_player() &&
               (int)ob->query_spell_point() >= (heh = random(dmg / 3)))
            {
              tell_object(a, "\
Your Slayer feeds off of the magical energy surrounding \n\
" + ((string)ob->short() ? (string)ob->short() : "your enemy") + ".\n");
              tell_object(ob,
(string)ob->query_name() + "'s Slayer feeds from your magical energy.\n");
            ob->add_spell_point(-heh);
            
            life += heh;
           }
         }

         dmg /= 2;
         if(!dmg) dmg = 1;
         if(random(3)) life -= dmg;
      }
      else
      {
        tell_object(a, "You missed.\n");
        tell_room(environment(a), 
          (string)a->query_name() + " missed " +
          (string)ob->query_name() + ".\n", ({ a }));
        life --;
      } 
    }
     if(life <= 0)
    {
      tell_object(a, my + " flickers and fades away.\n");
      destruct(this_object());
      return;
    }
     }
     call_out("attackMess", 2, a);
}

string
short()
{
    object User;

    if(!(User = environment())) return 0;

     else
    {
      object a;

      if((a = this_player()) && a == User)
      return my + (Readied ? " (readied)" : "");
       else
         return sd + (Readied ? " (readied)" : "");
     }
}

long()
{

    string pwr;

    if(life > 100)      pwr = "darkly glowing";
    else if(life > 50)  pwr = "dimly glowing";
    else if(life > 25)  pwr = "slightly glowing";
    else                pwr = "deathly dark";


    pwr = BOLD + pwr + NORM;

    write(
sd + " is an item of true BloodLust.\n\
A thick, serrated blade rests atop this sinister appendage\n\
of doom.  The thick, black leather grip comes to a peak\n\
resembling a serpent's head at the pommel, and any light\n\
in the room glints off of the " + pwr + " blade.\n");
if(Readied) write("Type \"slayer unready\" to unready the beast.\n");
else write("Type \"slayer ready\" to ready the beast.\n");
}

status
cmdReady(string arg)
{
    if(id(arg))
      return command("slayer ready", this_player());
}

status
cmdUnready(string arg)
{
    if(id(arg))
      return command("slayer unready", this_player());
}

status
cmdTwirl(string arg)
{
    if(id(arg))
    {
      object a;

      write("You twirl " + sd + " above your head gracefully.\n");
      say((string)(a = this_player())->query_name() + " \
twirls " + sd + " above " + possessive(a) + " head gracefully.\n");
      return 1;
    }
}

status
cmdFlaunt(string arg)
{
    if(id(arg))
    {
      object a;

      write("You flaunt " + sd + " menacingly.\n");
      say((string)(a = this_player())->query_name() + " \
flaunts " + sd + " menacingly.\n");
      return 1;
    }
}

status
cmdWave(string arg)
{
    if(id(arg))
    {
      object a;

      if((object)(a = this_player())->query_attack())
      { 
        write("Preparing for battle, you");
        say(  "Preparing for battle, " + 
         (string)a->query_name());
      }
      else
      {
        write("You");
        say((string)a->query_name());
      }
      write(" wave " + sd + " around your appendages\
 with much grace.\n");
      say(" waves " +  sd + " around " + possessive(a) +
      " body with lithe, astounding grace.\n");
      return 1;
    }
}
