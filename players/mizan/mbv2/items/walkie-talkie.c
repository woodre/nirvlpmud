#include "/obj/ansi.h"
#include "/players/mizan/mbv2/definitions.h"
#include "/players/mizan/mbv2/router.h"


status is_radio_on;

id(str)
{
    if(is_radio_on)
        return str == "radio" || str == "walkie-talkie" || str == RADIO_ID;
    else
        return str == "radio" || str == "walkie-talkie";
}

short()
{
    if(is_radio_on)
        return "A portable walkie-talkie radio " + HIW + "(ON)" + NORM; 
    else
        return "A portable walkie-talkie radio"; 
}

long()
{
    write("This is a fairly cheap yet rugged walkie-talkie radio that has seen some\n"+
          "better days. It looks like you can only turn the radio on and off with the\n"+
          "commands 'radio on' and 'radio off'.\n");

    if(is_radio_on)
        write("The radio is currently on.\n"); 
    else
        write("The radio is currently off.\n"); 

    if(this_player() && this_player()->query_level() > 19 && this_player()->is_player())
    {
        write("\n"+
              "Being a wizard, you notice some more information about this device.\n"+
              "More commands:\n\n"+
              
              HIY + "rollcall\n"+ NORM +
              "  Displays a listing of all monsters deployed, their locations, and their\n"+
              "  respective index numbers.\n\n"+
              
              HIY + "report <indexnum>\n" + NORM +
              "Displays on the radio channel status of what the monster is currently doing.\n\n" +
              
              HIY + "orderhelp\n" + NORM +
              "Displays help regarding specific orders that are available to you with each\n" +
              "monster. A bit of a longish read, right-o.\n\n" +
              
              HIY + "order <indexnum> <command> <parameters> <duration>\n"+ NORM +
              "Sends an order to a specific monster. All orders share similar syntax in\n" +
              "that you need to specify an index and command. Parameters and duration MAY\n" +
              "be optional. Refer to 'orderhelp' for more information about specific commands.\n\n"+

              HIY + "ordertype <monsterrace> <command> <parameters> <duration>\n"+ NORM +
              "Similar to 'order', but you can group commands to an entire race of monsters.\n"+
              "For example, 'ordertype beano killobj mizan 10' would tell all Beanos to\n" +
              "execute the order that you have just issued.\n\n" +

              HIY + "orderteam <teamname> <command> <parameters> <duration>\n"+ NORM +
              "Similar to 'order', but you can group commands to an entire team of monsters.\n"+
              "For example, 'orderteam MonstersInc killobj mizan 10' would tell all members to\n" +
              "execute the order that you have just issued. Check 'mstatall t' for team names.\n\n" +

              HIY + "ordercabal <cabalname> <command> <parameters> <duration>\n"+ NORM +
              "Similar to 'order', but you can group commands to an entire cabal of monsters.\n"+
              "For example, 'ordercabal nutjobs killobj mizan 10' would tell all members to\n" +
              "execute the order that you have just issued. Check 'mstatall t' for all cabals.\n\n" +

              HIY + "orderall <command> <parameters> <duration>\n"+ NORM +
              "Orders all monsters a specific command. Known issue: sometimes you get an\n" +
              "'execution too long' thing. It's because of the way i am verifying monsters\n"+
              "in an array. It's a slight problem.\n\n" +

              HIY + "mattrib <indexnum>\n" + NORM +
              "Displays the attributes of a particular monster.\n\n"+

              HIY + "mstatall <option>\n" + NORM +
              "Displays stats relevant to all monsters. Valid flags are as follows:\n" +
              " mstatall h   Shows the health of all monsters, and their heal quotas.\n" +
              " mstatall c   Shows composite values, plus WC/AC, EXP worth, and levels.\n" +
              " mstatall a   Shows monster attributes in raw number percentages.\n" +
              " mstatall g   Shows how much gold, plus nexus infuse point.\n" +
              " mstatall t   Shows team and cabal name information.\n");
    }
}

get() { return 1; }
query_value() { return 220; }
query_weight() { return 1; }
query_save_flag() { return 1; }

init()
{
	add_action("on_rradio","radio");
    add_action("on_rreport","report");
    add_action("on_rreportall","reportall");
    add_action("on_rrollcall","rollcall");
    add_action("on_rorder","order");
    add_action("on_rorderhelp","orderhelp");
    add_action("on_rorderteam","orderteam");
    add_action("on_rordercabal","ordercabal");
    add_action("on_rordertype","ordertype");
    add_action("on_rorderall","orderall");
    add_action("on_rmattrib","mattrib");
    add_action("on_rstatall","mstatall");

}

on_rrollcall(arg) 
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    
    if(this_player() && this_player()->query_level() < 1000)
        log_file("mizan.orders.log", ctime() + " " + this_player()->query_real_name() + " rollcall " + arg + "\n");

    return TACTICAL_DM->on_rollcall(arg); 
}

on_rorder(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;

    if(this_player() && this_player()->query_level() < 1000)
        log_file("mizan.orders.log", ctime() + " " + this_player()->query_real_name() + " order " + arg + "\n");

    return TACTICAL_DM->on_order(arg); 
}

on_rorderteam(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    if(this_player() && this_player()->query_level() < 1000)
        log_file("mizan.orders.log", ctime() + " " + this_player()->query_real_name() + " orderteam " + arg + "\n");

    return TACTICAL_DM->on_orderteam(arg); 
}

on_rordercabal(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    if(this_player() && this_player()->query_level() < 1000)
        log_file("mizan.orders.log", ctime() + " " + this_player()->query_real_name() + " ordercabal " + arg + "\n");

    return TACTICAL_DM->on_ordercabal(arg); 
}

on_rordertype(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    if(this_player() && this_player()->query_level() < 1000)
        log_file("mizan.orders.log", ctime() + " " + this_player()->query_real_name() + " orderteam " + arg + "\n");

    return TACTICAL_DM->on_ordertype(arg); 
}


on_rreport(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    return TACTICAL_DM->on_report(arg); 
}

on_rreportall()
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    return TACTICAL_DM->on_report(); 
}

on_rorderall(arg) 
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;

    write("Orderall is being deprecated from abuse.\n"+
          "Use 'ordercabal' or 'orderteam' instead...\n");

    if(this_player() && this_player()->query_level() < 1000)
        log_file("mizan.orders.log", ctime() + " " + this_player()->query_real_name() + " orderall " + arg + "\n");
    
    return TACTICAL_DM->on_orderall(arg); 
}

on_rorderhelp(arg)
{
    string myfile;

    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;

    myfile = "/players/mizan/mbv2/help/";

    /* the TXT extension is used to prevent players from using directory attacks */
    if(!arg)
        myfile += "index.txt";
    else
        myfile += arg + ".txt";

    cat(myfile);
    return 1;
}


on_rradio(arg)
{
    if(!arg) return 0;

    if(arg == "on")
    {
        if(is_radio_on)
        {
            write("The radio is already on.\n");
            return 1;
        }
        else
        {
            write("You switch the radio on.\n");
            say(this_player()->query_name() + " switches a walkie-talkie radio on.\n");
            is_radio_on = 1;
            return 1;
        }
    }
    else if(arg == "off")
    {
        if(!is_radio_on)
        {
            write("The radio is already off.\n");
            return 1;
        }
        else
        {
            write("You switch the radio off.\n");
            say(this_player()->query_name() + " switches a walkie-talkie radio off.\n");
            is_radio_on = 0;
            return 1;
        }
    }
    else return 0;
}

on_rmattrib(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    return TACTICAL_DM->on_attrib_monster(arg);
}

on_rstatall(arg)
{
    if(this_player()->query_level() < 20 || !interactive(this_player())) return 0;
    return TACTICAL_DM->on_statall(arg);
}