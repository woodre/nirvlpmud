#define AWIZ ({ "vertebraker","vital","x", "earwax"})

/*
* Shardak guild by Dragnar/John + Balowski/Rasmus
* restored with love by Verte
*/

#include "/players/balowski/lib.h"
inherit BASE;
#include "def.h"
#include "macros.h"
#include "daemons.h"
#include "people.h"
#include "mark/emotes.h"
#include "mark/gen_bonus.h"
#include "mark/soul_check.h"
status SpecFlag;
int BaseXp;
static int casting;
int sac_pts;


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
object           Spinal;

id(string str)
{

    return str == "pro_object" || str == "mark" || str == OBJID ||
       str == "guild_object" || str == "no_spell" ||
       str == "generic_wc_bonus" || str == "no_mini" ||
       str == "kill_check_object" || str == "player_attack_object";
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
	return "You have the Mark of Shardak carved into your right hand";
    else
	return environment()->query_name() +
	   " has the Mark of Shardak carved into " +
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
  if((int)this_player()->query_level() < 21)
    this_player()->set_home("/players/vertebraker/closed/shardak/room/grotto");
  write(RED);
    cat(NEWS);
write(NORM);
    this_player()->add_player_id("demon");
    if(this_player()->query_level() < 20)
    {
    write("\n");
     }
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
    if (environment() == this_player()) {
       if(!this_player()->query_shardak_death_shadow()) {
        object ob;
        ob = clone_object(OBJDIR + "sshadow");
        ob->shadow_player(environment());
      }
    restore_me();
        set_heart_beat(1);
        if(this_player()->query_level() < 21)
        {
           this_player()->set_home(GROTTO);
           this_player()->set_guild_name(GUILDNAME);
      }

	    CHANNELD->register(this_player(), ({"[Servants]","{Servants}",}));
      /*
        add_attribute("ansi", this_player());
        */
	/*
	if (pointerp(notes)) Boards = insert_alist("servants", notes, Boards);
	*/
	notes = 0;
      if(!cmds) ACTIOND->GetMap();
	if (cmds = ACTIOND->query_cmds(frozen)) {
	    string *ks; int i;
	    i = sizeof(ks = keys(cmds));
	    while (i--) add_action("cmd_hook", ks[i]);
	}
    add_action("DoIt"); add_xverb("");
    }
}

cmd_hook(string str)
{
    string cmd;
    if(!swiped_powers) swiped_powers = ({ });
    if(this_player()->query_ghost()) return 0;
    if(member_array(query_verb(), swiped_powers) != -1)
    {
      write("You have lost that ability to Shardak.\n");
      return 1;
    }
    if (cmd = cmds[query_verb()])
	return (status) cmd->main(str);
}



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
Muffled() { return 0; }
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

static int wop;
void
heart_beat()
{
    casting = 0; /* clear casting */

    if(!User)
    {
      set_heart_beat(0);
      return;
    }
    if((int)User->query_level() < 19)
    {
      object ob;

      if(sac_pts > 0) sac_pts -= (1 + random(3));
      if(!random(1000) && sac_type && (sac_pts <= 0))
      {
        string cmd_to_swipe;

        string *ks;  ks = keys(cmds);
        cmd_to_swipe = (ks[random(sizeof(ks))]);

        if(member_array(cmd_to_swipe, (string *)ACTIOND->query_base()) == -1)
        {
          tell_object(User, "\
Shardak frowns upon you from afar.\n");
          User->hit_player(66 + random(33), "other|evil");
          if(!swiped_powers)
            swiped_powers = ({ });
          swiped_powers += ({ cmd_to_swipe });
          tell_object(User, "\
You have lost the ability to " + BOLD +
                  cmd_to_swipe + NORM + ".\n");
          this_object()->save_me();
        }

      }
      if((ob = present("crusader shield", User)) ||
         (ob = present("crucifix", User)) ||
         (ob = present("cross", User)) || 
         (ob = present("holy symbol", User)))
      {
        string sh, nm;

        if((sh = (string)ob->short()) && (int)ob->query_value()
           && (int)ob->query_weight() && !ob->query_auto_load()
           && (nm = (string)ob->query_name()))
        {
          object e;
          if(e = environment(User))
            if(!transfer(ob, e)) /* success ! */
              tell_object(User, "Something is very wrong...\n");
        }         
      }     
    }
}

int       TotPKills;   /* Total number of Player Kills */
string   *PKills;      /* Array of two key elements, the name of a Player killed,
                          and an array of every time the Shardak has killed
                          that Player */

getTime()
{
    string c, m, cx;
    c = ctime();

    switch(m = c[4..6]) {  /* un-truncate the month */
      case "Jan": m = "January";    break;
      case "Feb": m = "February";   break;
      case "Mar": m = "March";      break;
      case "Apr": m = "April";      break;
      case "Jun": m = "June";       break;
      case "Jul": m = "July";       break;
      case "Aug": m = "August";     break;
      case "Sep": m = "September";  break;
      case "Oct": m = "October";    break;
      case "Nov": m = "November";   break;
      case "Dec": m = "December";   break;
    }

    cx = c[8..9];
    if(cx[0] == ' ') cx = cx[1..1];
    return (m + " " + cx + ", " + c[20..23]);
}

kill_check(ob) {
  if(ob->is_player() && !ob->id("masakado")) {
    string oname;
    int i;
    if(!environment(environment()) || environment(environment())->query_spar_area()) return;
    tell_object(environment(), "\n\t\
You have slain " + (oname = ob->query_name()) + " and have recorded the kill.\n\n");
    CHANNELD->broadcast(environment()->query_name() + 
      " has killed " + oname + ".\n", 1, "[Servants]");
    TotPKills += ((int)ob->query_level() + (int)ob->query_extra_level());
    if(!PKills) PKills = ({ });
    i = member_array((oname = (string)ob->query_real_name()), PKills);
    if(i == -1)
      PKills += ({ oname, ({ getTime() }) });
    else
      PKills[i + 1] += ({ getTime() });

    save_me();
  }
}

query_pkills() { return PKills; }
query_tot_pkills() { return TotPKills; }

Spinal(ob) { if(!ob) return Spinal; else return (Spinal = ob); }
