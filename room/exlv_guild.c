inherit "/room/room";
/******************************************************************************
 * Program: exlv_guild.c
 * Path: /room
 * Type: Room
 * Created: by Boltar, recoded by Verte & Softly
 *
 * Purpose: Handles extra levels
 * 
 * History:
 *          07/22/2014 - Gnar
 *            Updated Costs to be an array instead of a Mapping, m_values on
 *            LD does not order the values.
 *          08/10/2014 - Gnar
 *            Updated correct_extra_level function, changed set extra level
 *            from i + 1 to i.
 ******************************************************************************/

#include "/room/tune.h"
#include "/players/boltar/things/esc.h"

#define BASEINT 2500000
#define MAX_LEV 100
#define TABLET "/room/exlv_tablet"
#define TESTCHAR_D "/obj/user/testchar-d"

static mapping Titles;
static int* Costs;

void
init_titles()
{
    int i;

    Titles = ([   1 : "the master of the yo-yo secret",
                  2 : "the master of silly putty",
                  3 : "the master of the nerf ball",
                  4 : "the grand master ranger",
                  5 : "the elder fighter",
                  6 : "the master of magic",
                  7 : "the elder warrior",
                  8 : "the cave master",
                  9 : "the legend of the east wind",
                 10 : "the master warrior",
                 11 : "the legendary warrior",
                 12 : "the elder conjurer",
                 13 : "the elder magician",
                 14 : "the elder of the southland",
                 15 : "the master of the night sky",
                 16 : "the master of the south wind",
                 17 : "the master of seasons",
                 18 : "the elder sorcerer",
                 19 : "the elder of the mortals",
                 20 : "the grand master elder sorcerer",
                 21 : "the grand master elder of the mortals" ]);

    for(i = 22; i < (MAX_LEV); i ++)
      Titles[i] = "the ancient of the mortals";

    Titles[100] = esc + "[1mthe Legend" + esc + "[2;37;0m";
}


void
init_costs()
{

    int i, x;

    Costs = allocate( MAX_LEV + 1 );
    Costs[0] = 0;
    Costs[1] = x = BASEINT;

    for(i = 2; i < 4; i ++)
      Costs[i] = (x += 200000);

    Costs[4] = (x += 400000);

    for(i = 5; i < 17; i ++)
      Costs[i] = (x += 300000);
    
    Costs[17] = (x += 400000);
    Costs[18] = (x += 800000);
    Costs[19] = (x += 900000);
    Costs[20] = (x += 1000000);
    Costs[21] = (x += 1111111);
   
    Costs[22] = (x = 12000000);
    
    for(i = 23; i < (MAX_LEV + 1); i ++)
      Costs[i] = (x += 1000000);
}
void
reset(status arg)
{
    if(find_object("/room/room"))
      destruct(find_object("/room/room"));
    "/room/room"->load_me_up_baby();
    if(arg) return;

    set_light(1);
    short_desc = "The senior adventurers' guild";
    items=({
      "paneling","Finely crafted wood paneling imported from exotic lands",
      "walls","Solid walls covered in a beautiful wood paneling",
      "chairs","Finely made with extra stuffing to be very comfortable",
      "guards","A pair of guards with extra fine equipment. Their armor shines and\n\
their deadly spears are held at the ready. With their straight\n\
backs and serious expressions these guys are not to be messed with",
    });
    long_desc =
   "At the top of the stairs you find the senior adventurers guild.\n"+
   "Here is where you may come to advance your level beyond 19.\n"+
   "This room is furnished better than the guild room below, wood\n"+
   "paneling on the walls with many nice chairs to sit on. Two guards\n"+
   "with spears guard the stairway that leads higher up the tower.\n"+
   "Like the main room below, the way of doing things is the same.\n"+
   "Commands: cost, advance, list (number).\n" +
   "It will cost a fee in coins per level to advance plus the cost of \n"+
   "any experience you may need to buy.\n";
    dest_dir = ({ "/room/adv_guild", "down",
                  "/room/pres_guild", "up",  });

    if(!present("tablet", this_object()))
      move_object(clone_object(TABLET), this_object());

    init_titles();
    init_costs();
}

get_new_title(lev, ob)
{
    string heh, a, b;
    if(lev == -1)
    {
      if(ob && (string)ob->query_gender() == "male")
        return "the grand master sorcerer";
      else
        return "the grand master sorceress";
    }
    heh = Titles[lev + 1];
    if(!ob) return heh;
    else
    {
      if((string)ob->query_gender() == "female")
      {
        if(sscanf(heh, "%smagician%s", a, b))
          heh = ((a ? a : "") + "magicienne" + (b ? b : ""));
        else if(sscanf(heh, "%ssorcerer%s", a, b))
          heh = ((a ? a : "") + "sorceress" + (b ? b : ""));
        else if(sscanf(heh, "%smaster%s", a, b))
          heh = ((a ? a : "") + "mistress" + (b ? b : ""));
      }
      return heh;
    }
}

int
get_next_exp(int lev)
{
    if(lev == -1) return 4;
    if( lev >= MAX_LEV) return 0;
    return Costs[lev + 1];
}

int
query_cost_for_extra_level(int lev, int xp)
{
    return (Costs[lev] - xp);
}

status
query_drop_castle()
{
    return 1;
}

status
query_limited_shadow()
{
    return 1;
}

void
init()
{
    object z;

    ::init();

    if((z = this_player()) && (status)z->is_player())
    {
      add_action("cmd_list", "list");
      add_action("cmd_advance", "advance");
      add_action("cmd_cost", "cost");
      if( this_player()->query_level() < 20 && !TESTCHAR_D->query_owner(this_player()->query_real_name()) )
        add_action("cmd_up", "up" );
    }
}

status
cmd_up() {
  string pname;
  pname = (string)this_player()->query_real_name();
  
  if( !this_player()->query_prestige_level() && this_player()->query_extra_level() < 100 )  {
    write("\n\nThe guards cross their spears and prevent you from entering the stairway.\n");
    say("\n\nThe guards cross their spears and block "+this_player()->query_name()+" from entering the stairway.\n");
    return 1;
  }
}

status
cmd_list(string arg)
{
   int z;

   if(!arg)
   {
     "/room/quest_room"->count();
     return 1;
   }

   if(arg == "all")
   {
     "/room/quest_room"->list_all();
     return 1;
   }

   if(sscanf(arg, "%d", z))
   {
     "/room/quest_room"->list(z);
     return 1;
   }

   "/room/quest_room"->count();
   return 1;
}

status
cmd_cost()
{
    int x, e, n, d, g;
    object a;

    if((int)(a = this_player())->query_level() < 19)
    {
      write("\
You cannot advance here until you become level 19.\n");
      return 1;
    }
    if((x = (int)a->query_extra_level()) >= MAX_LEV)
    {
      write("You may not advance any further. If you wish to find more prestige\n\
venture up the stairs to seek further glory.\n");
      return 1;
    }

    g = (x + 1);

    if((n = get_next_exp(x)) <= (e = (int)a->query_exp()))
    {
      write("\
It will cost you nothing to be promoted to level 19+" + g + ".\n");
      return 1;
    }

    if(((d = (n-e)) > (n / 10)) || (d > 15000))
    {
      write("\
You must be closer to the next level before buying experience.\n");
      return 1;
    }

    write("It will cost you " + ((d * 1000) / EXP_COST) +
          " gold coins to advance to level 19+" + g + ".\n");
    return 1;
}

void
nirvana_msg(string msg)
{
    int s;
    object *nirvy;

    s = sizeof(nirvy = users());

    while(s --)
      tell_object(nirvy[s], msg);
}

status
cmd_advance()
{
    int coincost,x, l, e, n, c, diff;
    object a;
    string sh, q;

    if((l = (int)(a = this_player())->query_level()) < 19)
    {
      write("You must finish advancing downstairs.\n");
      return 1;
    }

    coincost = ( this_player()->query_total_level()+1 ) * 10000 / 50;
    if (coincost > 6000) coincost = 6000 + (coincost-6000)/8;
    if((int)a->query_money() < coincost)
    {
      write("You need "+coincost+" gold coins to advance here.\n");
      return 1;
    }

    if((x = (int)a->query_extra_level()) >= MAX_LEV)
    {
      write("To advance further you must seek out prestige further up the tower.\n");
      return 1;
    }

    n = get_next_exp( x );
    e = (int)a->query_exp();
    diff = n - e;

    if(n > e)
    {
      if((diff > (n / 10)) || (diff > 15000))
      {
        write("\nYou must be closer to the next level before buying experience.\n");
        return 1;
      }
      c = (( diff  * 1000) / EXP_COST);
      if((int)a->query_money() < c)
      {
        write("You don't have enough gold coins to buy experience.\n");
        return 1;
      }

      a->add_money(-c);
    }

    a->set_extra_level(x + 1);
    a->set_title(get_new_title(x, a));

    x ++;

    write("You pay your "+coincost+" coin advancement fee.\n");
    if((string)a->query_guild_name() == "shardak" && present("shardak_mark", a))
    {
      present("shardak_mark", a)->BaseXp(n);
      present("shardak_mark", a)->save_me();
    }
    a->add_money(0-coincost);

    say((q = (string)a->query_name()) + " is now level 19+" + x + ".\n");
/* Added testchar check - Rump */
    if (!a->is_testchar())
      log_file("ADVANCE", ctime() + " " + q + " to player_level 19+" + x +
               "\n");

    if(e < n)
      a->add_exp(diff);

    sh = (string)a->short();

    switch(x)
    {
      case 0..6:
        write("You are now " + sh + ".\n");
        break;
      case 7..13:
        write("Well done, " + q + ".\nYou are now " + sh + ".\n");
        break;
      case 14..20:
        write("Welcome to your new class, mighty one.\nYou are now " + sh + ".\n");
        break;
      case 21:
        write("Amazing.\nYou are now a grand master elder of mortals.\n");
        break;
      case 22..(MAX_LEV - 1):
        write("You have achieved a rare accomplishment.\n"
             +"You are now " + sh + ".\n");
        break;
      case MAX_LEV:
        write("\
You have reached the pinnacle of mortal achievement on Nirvana.\n\
Your deeds and memory will live on forever, carved within the\n\
stone tablet you see before you.\n");
        if( !a->is_testchar() ) {
          nirvana_msg("\
The heavens shine down upon " + q + " who has advanced\n\
to the highest level among mortals.\n");
          present("the nirvana tablet of legends", 
            this_object())->encode_tablet(q);
        }
        break;
    }

    return 1;
}

void
correct_extra_level(object player)
{
    int e, x, i;

    if((int)player->query_level() > 19)
      return;
    

    if((e = (int)player->query_exp()) < Costs[1])
    {
      player->set_extra_level(0);
      return;
    }

    i = MAX_LEV;

    while(i --)
      if(Costs[i] <= e)
      {
        player->set_title(get_new_title(i - 1), player);
        player->set_extra_level(i);
        return;
      }

    player->set_extra_level(0);
}
    
int
check_level(int lev)
{
    return get_next_exp(lev - 1);
}

int
check_exp(int curr_exp, int inc)
{
    int i, b;

    i = MAX_LEV;
    

    while(i --)
    {
      if(Costs[i] <= curr_exp)
      {
        if((b = (i + inc)) < MAX_LEV)
        {
          if(b > -1)
            return Costs[b];
          else
            return Costs[0];
        }
        else return Costs[MAX_LEV - 1];
      }
    }

    return Costs[0];
}

        
/* following funcs left in just 'cause */

status
list_quests(string arg)
{
    cmd_list(arg);
    return 1;
}

status
advance()
{
    cmd_advance();
    return 1;
}

status
cost_for_extra_level()
{
    cmd_cost();
    return 1;
}
