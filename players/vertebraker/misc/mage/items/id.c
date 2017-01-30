#include "/players/vertebraker/ansi.h"

inherit "/players/vertebraker/closed/std/treasure";

void
reset(int arg)
{
    if(arg) return;
    set_id("scroll of identify");
    set_alias("scroll");
    add_id("identify");
    set_short("A scroll of identify");
    set_long("\
A partially unrolled piece of parchment, loosely tied with a\n\
black ribbon.  There is some writing upon it that you can read,\n\
and the title identifies it as a 'Scroll of Identify'.\n");
    set_weight(1);
    set_value(100);
}

void
init()
{
    ::init();
    add_action("cmd_read", "read");
    add_action("cmd_whatis", "whatis");
}

status
cmd_read(string str)
{
    if(!str) return 0;
    if(id(str))
    {
      write("\
The scroll reads:\n\n\
\t\tSpeak forth the words: 'whatis [item]'.\n\n");
      say((string)this_player()->query_name() + " reads a scroll.\n");
      return 1;
    }
    return 0;
}

void
print_armor(object x)
{
    string wt, ac, type, info;

    write(x->short() + " .. Armor.\n");
    type = (string)x->query_type();
    if(!type) type = "unknown";
    if(type == "armor")
      switch((int)x->armor_class())
      {
        case 0:
          ac = "Virtually nil";
          break;
        case 1:
          ac = "Slight";
          break;
        case 2:
          ac = "Okay";
          break;
        case 3:
          ac = "Good";
          break;
        case 4:
          ac = "Very good";
          break;
        case 5..1000:
          ac = "Adamant";
          break;
      }
    else
      switch((int)x->armor_class())
      {
        case 0:
          ac = "Slight";
          break;
        case 1:
          ac = "Good";
          break;
        case 2:
          ac = "Very Protective";
          break;
        case 3..1000:
          ac = "Astounding";
          break;
      }
    switch((int)x->query_weight())
    {
      case 0..1:
        wt = "Very light";
        break;
      case 2..3:
        wt = "Light";
        break;
      case 4..5:
        wt = "Medium";
        break;
      case 6..7:
        wt = "Heavy";
        break;
      case 8..9:
        wt = "Very heavy";
        break;
      default:
        wt = "Extremely heavy";
        break;
    }
    info = (string)x->query_info();
    if(!info) info = "Unknown";
    write("\
Protection: " + ac + ".\n\
Weight:     " + wt + ".\n\
Type:       " + capitalize(type) + ".\n\
Info:       " + info + ".\n\
Value:      " + (int)x->query_value() + ".\n");
}

void
print_weapon(object x)
{
    int wear;
    string wc, wt, type, info, condition;

    switch((int)x->weapon_class())
    {
      case 0..3:   wc = "Ineffective"; break;
      case 4..6:   wc = "Weak"; break;
      case 7..10:  wc = "Slight"; break;
      case 11..13: wc = "Decent"; break;
      case 14..16: wc = "Medium"; break;
      case 17..18: wc = "High"; break;
      case 19..20: wc = "Extreme"; break;
      case 21..10000: wc = "Astounding"; break;
    }
    switch((int)x->query_weight())
    {
      case 0..1:
        wt = "Very light";
        break;
      case 2..3:
        wt = "Light";
        break;
      case 4..5:
        wt = "Medium";
        break;
      case 6..7:
        wt = "Heavy";
        break;
      case 8..9:
        wt = "Very heavy";
        break;
      default:
        wt = "Extremely heavy";
        break;
    }
    type = (string)x->query_type();
    if(!type) type = "Unknown";
    info = (string)x->query_info();
    type = capitalize(type);
    if(!info) info = "Unknown";
    info = capitalize(info);

    wear = (int)x->query_wear();
    if(wear < 40) condition = "Like new";
    if(wear > 39 && wear < 100) condition = "A little worn";
    if(wear > 99 && wear < 200) condition = "Somewhat worn";
    if(wear > 199 && wear < 400) condition = "Worn";
    if(wear > 399) condition = "Well worn";

    write(x->short() + " .. Weapon.\n");
    write("\
Strength:    " + wc + ".\n\
Weight:      " + wt + ".\n\
Type:        " + type + ".\n\
Info:        " + info + ".\n\
Wear:        " + wear + ".\n\
Value:       " + (int)x->query_value() + ".\n");
}

void
print_treasure(object x)
{
    string wt, info;
    switch((int)x->query_weight())
    {
      case 0..1:
        wt = "Very light";
        break;
      case 2..3:
        wt = "Light";
        break;
      case 4..5:
        wt = "Medium";
        break;
      case 6..7:
        wt = "Heavy";
        break;
      case 8..9:
        wt = "Very heavy";
        break;
      default:
        wt = "Extremely heavy";
        break;
    }
    info = (string)x->query_info();
    if(!info) info = "Unknown";
    write(x->short() + " .. Item.\n");
    write("\
Weight:     " + wt + ".\n\
Info:       " + info + ".\n\
Value:      " + (int)x->query_value() + ".\n");
}

status
cmd_whatis(string str)
{
    object x, z;

    if(!(x = present(str, (z = this_player()))))
      x = present(str, environment(z));

    if(!x)
    {
      notify_fail("You don't see that here.\n");
      return 0;
    }
    if(living(x))
    {
      notify_fail("The scroll will not work on a living thing.\n");
      return 0;
    }
    if(!x->short())
    {
      notify_fail("That cannot be identified.\n");
      return 0;
    }

    write("You speak forth the magical words of identification.\n");
    say((string)z->query_name() + " speaks forth the magical words of \
identification.\n");
    write("The scroll bursts into flames.\n");
    z->add_weight(-1);
    if((status)x->is_armor()) print_armor(x);
    else if((int)x->is_weapon()) print_weapon(x);
    else print_treasure(x);

    destruct(this_object());
    return 1;
}
