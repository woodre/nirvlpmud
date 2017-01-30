#define AWIZ ({ "vertebraker","sandman","vital","laera","zeus","earwax","pestilence","mosobp","linus", "forbin"})
inherit "/players/vertebraker/closed/std/m_efuns";

/*
* Shardak guild by Dragnar/John + Balowski/Rasmus
* restored with love by Verte
*/

#include "/players/balowski/lib.h"
#include "include/people.h"
#include "include/def.h"
#include "include/tasks.h"
#include "include/daemons.h"
#include "include/macros.h"
#include "include/std.h"
#include "mark/emotes.h"


status SpecFlag;
int BaseXp;
static int casting;
int sac_pts;

inherit BASE;

string sac_type;
object flames;
string *swiped_powers;
static int      cmd_block;
static int      knife;
int             guild_class;
int             pkills;         /* registered player kills */
static status          muffled;        /* guild channel muffle */
string         *wstmsg;         /* messages for waste spell */
string          Class;          /* class/rank */
string          DragonName;     /* name of dragon (lowercase) */
mapping         Skills;         /* permanent skills */
static mapping  Bonuses;        /* temporary skill bonuses */

int             solved;         /* bit field with solved tasks */
                                /* easy for computers to interpret ;-) */
status          frozen;         /* frozen by the law */
static mapping  cmds;           /* [command : file] - list */
static object   dragon;         /* player's dragon */
int		    *notes;         /* notes read from bboard */
mixed		    *Boards;        /* alist of notes read per bboard */
static object   Owner;          /* this_player() */


id(string str)
{

    return str == "pro_object" || str == "mark" || str == OBJID ||
       str == "guild_object" || str == "no_spell" ||
       str == "generic_wc_bonus" || str == "no_mini" ||
       str == "kill_check_object";
}

long()
{
    write("\
This is the mark that you recieved when you joined the members of\n\
the underworld.  Type 'help guild' to see the powers it gives you.\n");
}

extra_look()
{
    if (this_player() == environment())
       return "The " + NORM + RED + "Mark of Shardak" + NORM + " is carved into your right hand";
    else
	return environment()->query_name() +
	   " has the "+RED+"Mark of Shardak"+NORM+" carved into " +
	   environment()->query_possessive() + " right hand";
}


void
reset(status arg)
{
    ::reset(arg);
    if(arg) return;
     if(!swiped_powers) swiped_powers = ({ });
}

query_auto_load()
{
    if(Class) return AUTOLOAD;
}


init_arg(x)
{
    if(this_player()->query_level() < 20)
/*
      write_file(LOGDIR + "EXP",
       "[e] "+ctime()[4..15] + " : " + this_player()->query_real_name() +
       " " + this_player()->query_guild_rank() + " " + 
       this_player()->query_level() + "+" + 
       this_player()->query_extra_level() +" " 
       + this_player()->query_exp() + "\n");
*/

    if (!this_player()->query_invis())
	CHANNELD->broadcast(this_player()->query_name() + " enters the game.\n",
			    0, "{Servants}");
    while(remove_call_out("do_emote") != -1);
    call_out("do_emote", 500 + random(500));
}

stop_cmds()
{
    cmd_block = 1;
}

enable_cmds()
{
    cmd_block = 0;
}
create()
{
    if (!root()) {
	Boards = ({ ({ }), ({ }), });
    }
    else {
        CHANNELD->add_channel("[Servants]", RED + "[Servants]" + NORM + " ");
        CHANNELD->add_channel("{Servants}", RED + "{Servants}" + NORM + " ");
    }
}
    
init()
{
    string tempname;

    if (!(Owner = environment())) return;
    else {
    if(!this_player()->query_shardak_death_shadow()) {
      object ob;
      ob = clone_object(OBJDIR + "sshadow");
      ob->shadow_player(environment());
    }
    restore_me();
/*
    if(SpecFlag)
    {
      string nn;
      nn = (string)this_player()->query_real_name();
      if(nn == "alanna") { 
        write(HIM + "\n\t<<< Mail Vertebraker if you get this, your old scar should be re-acquired.\n\t     Type 'save' and 'logme' to make sure. :)\n\t     Have a sunny day. >>>>>\n\n" + NORM);
        destruct(present("scar", this_player()));
        move_object(clone_object("/players/dragnar/closed/scar"), this_player());
     }

      SpecFlag = 0;
      save_me();
    }
*/
/*
    if(!SpecFlag)
    {
     string class;
     int    sdk;
     if(environment()->query_real_name() == "dazed")
     {
      sdk=1;
      class="Master";
     }
     else if(environment()->query_real_name() == "cerberus")
     {
      sdk=1;
      class="Berzerker";
     }
     if(sdk)
     {
      environment()->ClassName(class);

      msg = (current > new) ? " has been auto-degraded to class "
                          : " has been auto-promoted to class ";
      CHANNELD->broadcast(name + msg + class + " by " +
         "Vertebraker's li'l script.\nGot beef?\nMail the man.\n", 0, 
         "{Servants}");
      SpecFlag=1;
     }
    }
*/
        set_heart_beat(1);
        if(this_player()->query_level() < 21)
        {
           this_player()->set_home(GROTTO);
           this_player()->set_guild_name(GUILDNAME);
      }

        else
           if(member_array((string)this_player()->query_real_name(), AWIZ) == -1) { destruct(this_object()); return; }
	    CHANNELD->register(this_player(), ({"[Servants]","{Servants}",}));
        add_attribute("ansi", this_player());
	if (pointerp(notes)) Boards = insert_alist("servants", notes, Boards);
	notes = 0;
      if(!cmds) ACTIOND->GetMap();
	if (cmds = ACTIOND->query_cmds(frozen)) {
	    string *ks; int i;
	    i = sizeof(ks = keys(cmds));
	    while (i--) add_action("cmd_hook", ks[i]);
	}
    add_action("DoIt"); add_xverb("");
    }
    if (Owner && interactive(Owner)) {
      tempname = (string)environment()->query_real_name();
/*
      HIERARCHYD->add_member(tempname,lower_case(Class));
*/
    }
}

cmd_hook(string str)
{
    string cmd;
    if(!swiped_powers) swiped_powers = ({ });
    if(this_player()->query_ghost()) return 0;
    /* Added by Earwax 7/23/03 must be PK to use spells */
    if(!this_player()->query_pl_k())
    {
      notify_fail("You must have PK set to use this command.\n");
      return 0;
    }
    if(member_array(query_verb(), swiped_powers) != -1)
    {
      write("You have lost that ability to Shardak.\n");
      return 1;
    }
    if (cmd = cmds[query_verb()])
	return (status) cmd->main(str);
}

/*
string query_nickname(string name)
{
    object qt;
    if (qt = present("shardak_qt", environment())) {
	return (string) qt->query_nickname(name);
    }
    return name;
}
*/

drop()  { return 1;}
get()   { return 1;}

Light(l)        { return set_light(l);}
wstmsg(w) { return (w ? (wstmsg = w) : wstmsg); }
GuildClass(x)   { return strtoclass(Class);}
ClassName(x)
{
    if(x) { Class = x; guild_class = strtoclass(Class); }
    else return Class;
}

PKills(ks)      { return (pkills += ks);}
Muffled(mf)     { return (muffled ^= mf);}
Freeze(x)       { return (frozen ^= x);}
Dragon(d)       { return d ? (dragon = d) : dragon;}
DragonName(n)   { return n ? (DragonName = n) : DragonName;}
QuerySkill(s)   { return (Skills ? Skills[s] : 0) +
			 (Bonuses ? Bonuses[s] : 0);}
RaiseSkill(s,x) { return Skills ? (Skills = ([s:x])) : (Skills[s] += x);}
SetSkill(s,x)   { return Skills ? (Skills = ([s:x])) : (Skills[s] = x);}
QueryBonus(s)   { return Bonuses ? Bonuses[s] : 0;}
RaiseBonus(s,x) { return Bonuses ? (Bonuses = ([s:x])) : (Bonuses[s] += x);}
ResetCasting() { casting = 0; }
ThrowingKnife(c) { if(c) knife = c; else return knife; }
CastingSpell(c)
{
    if(c) casting = c;
    else return casting;
}
SetBonus(s,x)   { return Bonuses ? (Bonuses = ([s:x])) : (Bonuses[s] = x);}

save_me()
{
    if (GuildClass())
    save_object(SAVE_PATH + environment()->query_real_name());
}

restore_me()
{
    int x;
    x = restore_object(SAVE_PATH + environment()->query_real_name());
    if(!Boards) Boards = ({ ({ }), ({ }), });
    Boards = order_alist(Boards);
    if (!Class) Class = classtostr(guild_class);
    return x;
}

remove_object()
{
    CHANNELD->deregister(this_object(), "Servants");
    CHANNELD->deregister(environment(), ({"[Servants]","{Servants}"}));
    save_me();
}

/*
 * Bulletin board functions
 * 2 broken items in 3.1.2-DR rear their heads
 */
/*mixed*/
new_notes(string board, int *avail)
{
    int *read, index;

    read = assoc(board, Boards);
    if (!avail) return read;
    if (!read) return sizeof(avail);
    
    read = read & avail;
    /*Boards = insert_alist(board, read, Boards);*/
    index = assoc(board, Boards[0]);
    Boards[1][index] = read;
    return (sizeof(avail) - sizeof(read));
}

void
read_note(string board, int *n)
{
    int index;

    index = assoc(board, Boards[0]);
    if (index < 0)	/* not found, first note read */
	Boards = insert_alist(board, n, Boards);
    else		/* add to list of notes read */
	Boards[1][index] += n;
}

/*
 * Small section for tasks
 */
int
query_solved(int mask)
{
    return solved & mask;
}

void
add_solved(int task)
{
    if (LOGD->log_task(task, previous_object()))
	solved |= task;
}

int
query_combat_method()
{
    /* 
     * actually this is rather good. Self inflicted damage is not blocked
     * fleeing and returning fucks up a bit
     */
    if (this_player() != environment())
	return 2;       /* + paladin_shield->shield_bonus(pro_object) */
    else
	return 3;       /* + second_weapon->dual_hit(pro_object) */
}

static object SpellOb;

SpellObject(o) { return o ? (SpellOb = o) : SpellOb;}

int
hit_bonus()
{
    /*printf("mark::bonus_hit\tSpellOb = %O\n", SpellOb);*/
    if (SpellOb) {
	int i;
    
	i = (int) SpellOb->hit_bonus();
	SpellOb = 0;
	return i;
    }
}

DoIt()
{
    if(cmd_block && (int)this_player()->query_level() < 20)
    {
      write("Something is holding you back.\n");
      return 1;
    }
}

QueryBaseXp() { return BaseXp; }
BaseXp(int x)
{
    if(!x) return BaseXp;
    else BaseXp = x;
}

query_flames()
{
    if(!flames) return 0;
    if(!present(flames, environment(environment())))
    {
      tell_room(environment(flames), "\
The dark flame blazes away...\n");
      destruct(flames);
      flames = 0;
    }
    else return flames;
}

set_flames(ob)
{
    flames = ob;
}

Sacrifice() { return sac_pts; }

NeedSacrifice(x) { sac_type = x; save_me(); }

add_sacrifice(x) { sac_pts += x; }
query_sacrifice_type() { return sac_type; }

void
give_me_back_my_power_foo()
{
    if(!swiped_powers || !sizeof(swiped_powers))
      return;

    else
    {
      string a;
      int indice;

      a = swiped_powers[indice = random(sizeof(swiped_powers))];

      tell_object(User, "\
Shardak has re-granted you the power to " + BOLD + a + NORM + ".\n");

      swiped_powers -= ({ swiped_powers[indice] });
      save_me();
    }
}


void
mini_dest(string arg)
{
   tell_object(environment(),
   RED +
    "Shardak has banned the usage of miniguilds.\n" + NORM);
}

void
call_pet()
{
    if(previous_object()->is_pet())
    {
      tell_object(environment(),
"Shardak has banned the usage of pets.\n");
      destruct(previous_object());
    }
}

/*
void
guild_death()
{
    int cexp, level, ex_lv;

    BaseXp = (int)environment()->query_exp();
    
    level = (int)environment()->query_level();
    ex_lv = (int)environment()->query_extra_level();

    cexp = (int)"/room/adv_guild"->check_level(level);

    if(BaseXp < cexp)
      "/room/adv_guild"->correct_level(environment());
    if(ex_lv)
    {
      cexp = (int) "/room/exlv_guild"->check_level(ex_lv);
      if(BaseXp < cexp)
        "/room/exlv_guild"->correct_extra_level(environment());
    }
}
*/

#include "include/pk_check.h"
#include "mark/heart_beat.h"

int gen_wc_bonus() {
  object env, targ;

  if ((Owner) && (targ = (object)Owner->query_attack())) {
    if ((int)targ->query_alignment() < -333) return (-random(3));
    else if ((int)targ->query_alignment() > -1) return random((int)targ->query_guild_rank() * 3 / 4);
  }

  return 0;
}
