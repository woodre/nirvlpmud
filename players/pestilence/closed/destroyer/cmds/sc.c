#include "/players/pestilence/ansi.h"
#pragma strict_types
#include "/players/vertebraker/closed/shardak/std.h"
#include "/players/vertebraker/closed/shardak/macros.h"
#include "/players/vertebraker/closed/shardak/people.h"
inherit CMD;

string
degree(int n, int max)
{
    if (!n)
        return("No      ");
    else {
        switch (4*n/max) {
            case 0: return("Little  ");
            case 1: return("Some    ");
            case 2: return("Yes     ");
            case 3: return("A lot   ");
            default: return("Very    ");
        }
    }
}

status
main(string arg)
{
    string      str;
    string      Colour, Class, Intox, Stuff, Soak, Encumb;
    int         Level, XLevel, Coins, Exp, QPts, GExp, GRank,combat;
    int         n, max, delay;
    object      ob;

    if (this_player()->query_ghost()) {
        write("You are in an immaterial state with no scores.\n");
        return 1;
    }
    write("\n");
    Level  = (int) this_player()->query_level();
    XLevel = (int) this_player()->query_extra_level();
    Coins  = (int) this_player()->query_money();
    Exp    = (int) this_player()->query_exp();
    GExp   = (int) this_player()->query_guild_exp();
    QPts   = (int) this_player()->query_quest_point();
    delay = (int) present("destroyer_ob",this_player())->query_spell_delay();
    GRank  = (int) this_player()->query_guild_rank();
    Stuff  = degree((int) this_player()->query_stuffed(), Level*8);
    Soak   = degree((int) this_player()->query_soaked(), Level*8);
    n = 0;
    for (ob = first_inventory(this_player()); ob; ob = next_inventory(ob))
        n += (int) ob->query_weight();
    Encumb = degree(n, 6 + Level + ((int)this_player()->query_attrib("str")/5));
    Intox  = "No";
    if (n = (int) this_player()->query_intoxination()) {
        n = (Level + 4)/n;
        switch (n) {
            case 0: Intox = "Stupor"; break;
            case 1: Intox = "Roaring"; break;
            case 2: Intox = "Somewhat"; break;
            case 3: Intox = "Quite"; break;
            default: Intox = "Slightly"; break;
        }
    }

write(HIW + "[~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~]\n" + NORM);
write(YEL +"                       A R M Y  O F  P E S T I L E N C E\n" +NORM);
write(WHT + "[~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~]\n" + NORM); 
    write(this_player()->short() + "\n");
    this_player()->show_age();
    if((int)this_player()->query_pregnancy())
    if (((int)this_player()->query_age() - (int)this_player()->query_pregnancy()) > 4000)
      write("You are Pregnant.\n");
    if (this_player()->query_invis())     write("You are Invisible.\n");
    if ((ob = (object) this_player()->query_hunted()) &&
        (str = (string) ob->query_name()))
        write("You are hunted by " + str + ".\n");

    write("\n");

    write("Level:      "    + pad(XLevel ? Level + "+" + XLevel : Level, 8) +
          "\tGuild Rank:  " + pad(GRank, 8) +
          "\tIntox'd:    "  + CYN + Intox + NORM +"\n");

    write("Coins:      "    + pad(Coins, 8) +
          "\tGuild Exp:   " + pad(GExp, 8) +
          "\tStuffed:    "  + CYN +Stuff + NORM + "\n");

    write("Experience: "    + pad(Exp, 12) +
          "Delay:       "+ pad(delay, 8) +
          "\tSoaked:     "  + CYN + Soak + NORM + "\n");

    write("Quest pts:  "    + pad(QPts, 5) +
          "\t\t\t" + 
          "\tEncumbered: "  + Encumb + "\n\n");

    write("Hit pts:    "+ HIY + uhp + NORM + "/" + HIC + umhp + NORM +
          "\tSpell pts:   " + HIY + usp + NORM + "/" + HIC + umsp + NORM + "\n");
    
write(HIW + "[~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~]\n" + NORM);

    return 1;
}
