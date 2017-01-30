/* i can ease the pain. */

#include "/players/vertebraker/ansi.h"

#define MLOG "/players/vertebraker/log/Monster"
#define CLOAK "/players/vertebraker/misc/mage/items/cloak"
#define SIGN "/players/vertebraker/misc/mage/sign"
#define POTIONS "/players/vertebraker/misc/mage/items/"
#define WORKSHOP "/players/vertebraker/misc/mage/workshop"
#define PORTAL "/players/vertebraker/misc/mage/items/portal"

inherit "/players/vertebraker/closed/std/monster";
inherit "/players/vertebraker/closed/std/m_efuns";

mapping Items;
string sign, remembered_location;

void
rebuild_list()
{
    string s, p, sw, g, m, cl, d, cy;

    s  = pad("" + Items["scroll"] + "", 2);
    p =  pad("" + Items["portal"] + "", 2);
    sw = pad("" + Items["swirly"] + "", 2);
    g  = pad("" + Items["green"] + "", 2);
    m  = pad("" + Items["magenta"] + "", 2);
    cl = pad("" + Items["clear"] + "", 2);
    d  = pad("" + Items["dusky"] + "", 2);
    cy = pad("" + Items["cyan"] + "", 2);

    sign = HIW + "\
=====Items==================Qty=================Price=====\n" + NORM + "\
Scroll of Identify:         " + s + "                  150\n\
Dusky Flask:                " + d + "                  750\n\
Wand of Portals:            " + p + "                  1000\n" +
BOLD + "POTIONS" + NORM + ":\n\
Swirling Blue and White:    " + sw + "                  400\n\
Green:                      " + g + "                  600\n\
Magenta:                    " + m + "                  700\n\
Clear:                      " + cl + "                  500\n\
Cyan:                       " + cy + "                  500\n\n\
Note: You may buy '#' of 'what', i.e. 'buy 3 cyan.'\n";
    rm(SIGN);
    write_file(SIGN, sign);
}

void
restock_me()
{
    Items = ([ "scroll" : 20, "portal" : 20, "swirly" : 15,
                "green": 10, "magenta" : 5, "clear" : 5, 
                "dusky" : 5, "cyan" : 10 ]);
}

void
reset(status arg)
{
     if(arg) return;
     monster::reset();
     /* initial stock */
     restock_me();
     set_name("gilmour");
     set_short("Gilmour " + BOLD + "the Seer" + NORM);
     set_long("\
Wearing robes of the finest silversilk, Gilmour the Seer is\n\
one of the Wandering Mages of Sin'tara.  He is reknowned for\n\
his potion brewing skill.  His left hand trembles with the\n\
magical energy suppressed within, eager to escape.  In his\n\
right hand he clutches a time-beaten oak staff.  A cloak hangs\n\
from his neck, covering the rear strap of a shimmering red\n\
jeweled pendant.  His feet are adorned with dark crimson\n\
boots, and his auburn locks flow gently along his shoulders.\n\
He sells a variety of goods that you may 'list' or 'buy'.\n");
      set_race("human");
      set_gender("male");
      set_alias("gilmour_the_seer");
      set_alt_name("mage");
      set_level(22);
      add_money(500 + random(800));
      set_chat_chance(5);
      load_chat("Gilmour whispers a few words to himself.\n");
      load_chat("Gilmour nods at you knowingly.\n");
      load_chat("Gilmour smiles and looks around.\n");
      load_chat("\
Gilmour kneels down to the earth and picks up a handful of dirt.\n\
He lets it flow gently to the ground and smiles.\n");
      load_chat("Gilmour glances up at the sky.\n");
      load_chat("Gilmour holds his staff aloft and mutters a phrase.\n");
      load_chat("Gilmour asks, \"Come to buy?\"\n");
      set_wc_bonus(54);
      set_dead_ob(this_object());
}

void
init()
{
    monster::init();
    if(!sign)
    {
      rebuild_list();
      call_out("move_heh_heh_heh", 90);
      call_out("eq_check", 600);
    }
    add_action("cmd_list", "list");
    add_action("cmd_buy",  "buy");
    add_action("cmd_buy",  "purchase");
    add_action("no_way",   "sell");
}

status
cmd_list()
{
    write("Gilmour says, \"I sell the following items:\"\n\n");
    cat(SIGN);
    return 1;
}
     
status
monster_died()
{
    int ac;
    object a, b, c, d, x;

    if(!(x = environment())) return 0;

    if(attacker_ob)
    {
      write_file(MLOG,
        HIB + "[" + NORM + ctime()[4..15] + HIB + "]" + NORM +
        " " + (string)attacker_ob->query_name() + " [" +
        (int)attacker_ob->query_level() + "+" +
        (int)attacker_ob->query_extra_level() + "] - Gilmour\n");
      tell_room(x,
"\n\
Gilmour looks penitently up at the sky, and as he falls\n\
to the earth, a look of calmness passes over his visage.\n\
He gazes calmly and lets out a sigh as he collapses to his\n\
final resting place....\n");
    }
        
    a = clone_object("/obj/weapon");
    b = clone_object("/obj/armor");
    c = clone_object(CLOAK);
    d = clone_object("/obj/armor");
      
    a->set_name("oak staff");
    a->set_alias("staff crafted from oak");
    a->set_class(14);
    a->set_short("A staff crafted from oak");
    a->set_weight(2);
    a->set_type("staff");
    a->set_read("Property of Gilmour the Seer.\n");
    a->set_long("\
A dusty brown staff with scores of markings all over the\n\
body.   It crooks up into a blunt handle on the peak.\n\
There is some writing on the side.\n");
    a->set_message_hit(({
        "crushed", "'s skull with a swing from the staff",
        "bashed", " relentlessly",
        "solidly whacked","",
        "smacked", " with a tremendous swing",
        "smacked", "",
        "grazed","",
        "grazed", "", }));
    a->set_value(200 + random(100));

    b->set_name("silversilk robes");
    b->set_alias("robes");
    b->set_short("Robes of " + HIW + "silversilk" + NORM);
    b->set_long("\
Crafted from beautiful silversilk, the robes are a sure\n\
marker of the sign of a wizard.  They have been enchanted\n\
and glow with a strange blue aura just above them.\n");
    b->set_weight(1);
    b->set_type("armor");
    b->set_ac(3);
    b->set_value(1000 + random(666));
    b->set_save_flag();

    d->set_name("crimson boots");
    d->set_alias("boots");
    d->set_short(RED + "Dark crimson boots" + NORM);
    d->set_weight(1);
    d->set_type("boots");
    d->set_ac(ac = (1 + random(2)));
    switch(ac)
    {
      case 1:
        d->set_long("\
Dark red crimson boots crafted from thick leather.  They are\n\
beautiful to behold and fit seamlessly over the wearer's feet.\n");
        break;
      case 2:
        d->set_long("\
Dark red crimson boots crafted from thick leather.  They are\n\
beautiful to behold and fit seamlessly over the wearer's feet.\n\
They seem to be quite protective.\n");
        break;
    }
    d->set_value(666 + random(333));
    d->set_save_flag();

    move_object(a, x);
    move_object(b, x);
    move_object(c, x);
    move_object(d, x);

    return 0;
}

void
fire_bolt()
{
    tell_object(attacker_ob, "\
Gilmour whispers a few words and points at you.\n\n" + HIR +
"\tflames erupt all over you...\n\n" + NORM);
    tell_room(environment(), "\
Gilmour whispers a few words and flames erupt all over " +
(string)attacker_ob->query_name() + ".\n", ({ attacker_ob }));
    attacker_ob->hit_player(44 + random(22), "other|fire");
}

void
ice_bolt()
{
    tell_object(attacker_ob, "\
Gilmour whispers a few words and points at you.\n\n" + HIB +
"\tRocks of ice smash into you!\n\n" + NORM);
    tell_room(environment(), "\
Gilmour whispers a few words and magical ice smashes into " +
(string)attacker_ob->query_name() + ".\n", ({ attacker_ob }));
    attacker_ob->hit_player(44 + random(22), "other|ice");
}

void
gem_missile()
{
    tell_object(attacker_ob, "\
Gilmour whispers a few words and points at you.\n\n" + HIR +
"\tHardened " + HIC + "diamonds" + NORM + " form from the earth and \
cut into you!\n\n" + NORM);
    tell_room(environment(), "\
Gilmour whispers a few words, and magical diamonds assault " +
(string)attacker_ob->query_name() + ".\n", ({ attacker_ob }));
    attacker_ob->hit_player(44 + random(22), "physical");
}

void
heart_beat()
{
    object newport;
    monster::heart_beat();
    if((newport = find_living("gilmour_the_seer")) && (newport != this_object())) return destruct(this_object());
    if(!(newport = environment()))
    {
      move_object(this_object(), "/room/void");
      destruct(this_object());
     }

    if(file_name(newport)[0..9] != "room/south" && !newport->gilmour_workshop())
    {
      tell_room(newport, "\
Gilmour studies his surroundings.\n\
He shakes his head and waves his staff in the air.\n");
      move_object(this_object(), "/room/south/sforst24");
      tell_room(environment(), "\
Gilmour arrives in a flash of light.\n");
      return;
    }
     
    if(attacker_ob)
    {
      if(0 == random(3)) fire_bolt();
      if(0 == random(3)) ice_bolt();
      if(0 == random(3)) gem_missile();
    }
}
    
status
cmd_buy(string str)
{
    int c, cnt, cost;
    string i, j, path, item, woof;
    object x, z;

    if(!str)
    {
      notify_fail("\
Gilmour asks, \"What would you like to buy?\"\n");
      return 0;
    }

    if(!sscanf(str, "%d %s", c, i)) { c = 1; i = str; }
        
    if(c < 1) c = 1;

    if(i == "scroll" || i == "scrolls" || i == "identify" ||
       i == "scroll of identify")
    {
      cost = 150;
      path = POTIONS + "id";
      item = "scroll";
    }
    else if(i == "wand" || i == "wand of portals" || i == "portals"
            || i == "wands" || i == "wands of portals")
    {
      cost = 1000;
      path = POTIONS + "wand";
      item = "portal";
    }
    else if(i == "swirling" || i == "swirling blue and white" ||
       i == "blue" || i == "blue and white" || i == "white" ||
       i == "swirling blue and white potions" ||
       i == "swirling blue and white potion")
    {
      cost = 400;
      path = POTIONS + "tele";
      item = "swirly";
    }
    else if(i == "green" || i == "green potions" ||
            i == "green potion")
    {
      cost = 600;
      path = POTIONS + "regen";
      item = "green";
    }
    else if(i == "magenta" || i == "magenta potions" || 
            i == "magenta potion")
    {
      cost = 700;
      path = POTIONS + "defense";
      item = "magenta";
    }
    else if(i == "clear" || i == "clear potions" || i == "clear potion")
    {
      cost = 500;
      path = POTIONS + "invis";
      item = "clear";
    }
    else if(i == "dusky" || i == "dusky flasks" || i == "dusky flask")
    {
      cost = 750;
      path = POTIONS + "dark";
      item = "dusky";
    }
    else if(i == "cyan")
    {
      cost = 500;
      path = POTIONS + "cure";
      item = "cyan";
    }

    else
    {
      notify_fail("\
Gilmour asks, \"What would you like to buy?\n");
      return 0;
    }

    x = this_player();
    cost *= c;
    if((int)x->query_money() < cost)
    {
      notify_fail("\
You don't have enough money.\n");
      return 0;
    }
    if(!Items[item])
    {
      notify_fail("\
Gilmour says, \"I am out of that item.\"\n");
      return 0;
    }

    z = clone_object(path);
    if(!x->add_weight((int)z->query_weight()))
    {
      notify_fail("\
Gilmour frowns and says, \"You can't carry it.\"\n");
      return 0;
    }

    woof = (string)z->query_name();
    if(c == 1) 
    {
      write("You buy a " + woof + " from Gilmour.\n");
       say((string)x->query_name() + " buys a " + woof +
         " from Gilmour.\n", ({ x }));
      move_object(z, x);
      x->add_money(-cost);
      Items[item]--;
    }
    else
    {
      say((string)x->query_name() + " buys several items from Gilmour.\n");
      while(c--) 
      {
        if(Items[item])
        {
          z = clone_object(path); 
          move_object(z, x);
          Items[item] --;
          cnt ++;
        }
        else
        {
          write("Gilmour says: \"I only have " + cnt + ".\"\n" +
                "He hands you the goods.\n");
          x->add_money(-((cost / c) * cnt));
          rebuild_list();
          return 1;
        }
      }
      write("Gilmour hands you " + cnt + " of the item.\n");
      x->add_money(-cost);
    }
    
    rebuild_list();
    return 1;
}

void
eq_check()
{
    int a, i;
    object click, *pow, grok;

    if(!(grok = environment()))

    a = sizeof(pow = m_indices(Items));
    for(i = 0; i < a; i ++)
      if(!Items[pow[i]])
      {
        tell_room(grok, "\
Gilmour glances into the pockets of his cloak.\n\
He frowns and whispers a few words.\n\
Gilmour vanishes from the immediate area.\n");
        remembered_location = file_name(grok);
        move_object(this_object(),  WORKSHOP);
        call_out("return_with_goods", 600);
        return;
      }
    call_out("eq_check", 600);
}

void
return_with_goods()
{
    object goo;

    restock_me();

    if(!remembered_location)
    {
      goo = find_object("/room/south/sforst24");
      if(!goo)
      {
        "/room/south/sforst24"->load_me();
        goo = find_object("/room/south/sforst24");
      }
      tell_room(goo, "Gilmour appears in a flash of light.\n");
      move_object(this_object(), goo);
      return;
    }

    goo = find_object(remembered_location);

    if(!goo)
    {
      remembered_location->load_me();
      goo = find_object(remembered_location);
    }
    
    rebuild_list();
    tell_room(goo, "Gilmour appears in a flash of light.\n");
    move_object(this_object(), goo);
    call_out("eq_check", 600);
}

void
catch_tell(string str)
{
    int cost;
    string who, bling, blang;
    object hole, x, p;

    if(!environment()) return;

    if(sscanf(str, "%s tells %s", who, bling) && who)
    {
      if(hole = find_player(lower_case(who)))
      {
        if((status)environment()->gilmour_workshop())
        {
          tell_object(hole, "\
Gilmour telepaths, \"I am busy at the moment.\"\n");
          return;
        }
        if((int)hole->query_spell_point() < (cost = (60 + random(20))))
        {
          tell_object(hole, "\
Gilmour telepaths, \"You don't have enough magical energy for\n\
me to channel, to bring you here.\"\n");
          return;
        }
        if(!(x = environment(hole)) || (string)x->realm() == "NT")
        {
          tell_object(hole, "\
Gilmour telepaths, \"Even I cannot release you from your present\n\
locus.\"\n");
          return;
        }
        if(x == environment())
        {
          tell_object(hole, "Gilmour pokes you menacingly.\n");
          return;
        }        
        if(present("green_portal", x))
        {
          tell_object(hole, "\
Gilmour telepaths, \"All you must do is enter the portal.\"\n");
          return;
        }
        tell_room(environment(), "\
Gilmour waves his hands strangely.\n");
        tell_room(x, "A mysterious " + GRN + "green" + NORM + 
        " portal opens within the immediate vicinity.\n");
        tell_room(environment(), "\
A mysterious " + GRN + "green" + NORM + " portal opens within the\n\
immediate vicinity.\n");
        tell_object(hole, "\
Gilmour telepaths, \"Step into the portal!\"\n");
        hole->add_spell_point(-cost);
        p = clone_object(PORTAL);
        p->set_dest(file_name(environment()));
        move_object(p, x);
        p = clone_object(PORTAL);
        p->set_dest(file_name(x));
        move_object(p, environment());
        return;
      }
    }
}

status
no_way()
{
    notify_fail("Gilmour shakes his head.\n");
    return 0;
}


status
id(string str)
{
    if(::id(str)) return 1;
    if(str == "seer" || str == "gilmour the seer") return 1;
}

void
move_heh_heh_heh()
{
    if(!attacker_ob)
    random_move();
    call_out("move_heh_heh_heh", 90);
}
