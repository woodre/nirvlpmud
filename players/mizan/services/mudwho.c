/* A little daemon which reports once per minute who is logged in */
/* The output file is then copied over to where the web server can see it. */

id(str) { return str == "owl"; }

short() { return "A small barn owl"; }

get() { return 0; }

reset(arg)
{
    if(arg) return;

    move_object(this_object(), "/players/mizan/workroom");

    remove_call_out("fake_beat");
    call_out("fake_beat", 1);
}

fake_beat()
{
    object ob;
    int i;
    string wizresult;
    string playerresult;
    string result;
    int wizcount, playercount;
 
    wizresult = "";
    playerresult = "";
    result = "";
    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(!ob[i]->query_invis() && environment(ob[i]))
        {
            if(ob[i]->query_level() < 20)
            {
                playerresult += "<li class='page_item'>";

                /* if the player has PK set */
                if(ob[i]->query_pl_k()) playerresult += "<span style='color:red'>*</span>&nbsp;";

                playerresult += ob[i]->query_name() + "</li>";
                playercount ++;
            }
            else
            {
                wizresult += "<li class='page_item'>" + ob[i]->query_name() + "</li>";
                wizcount ++;
            }
        }
    }

    result += "<b>Players:</b><BR>\n";
    if(playercount == 0) result += "<ul class='children'><li class='page_item'>(none)</li></ul>\n";
    else result += "<ul class='children'>" + playerresult + "</ul>\n";

    result += "<BR><b>Wizards:</b><BR>\n";
    if(wizcount == 0) result += "<ul class='children'><li class='page_item'>(none)</li></ul>\n";
    else result += "<ul class='children'>" +  wizresult + "</ul>\n";

    result += "<br><b>Notes:</b><BR>\n";
    result += "<ol class='children'>\n";

    result += "<li class='page_item'>There ";
    if(playercount == 1) result += "is " + playercount + " player and ";
    else result += "are " + playercount + " players and ";

    if(wizcount == 1) result +=  wizcount + " wizard ";
    else result += wizcount + " wizards "; 

    result += "logged in.</li>\n";
    result += "<li>Names with a <span style='color:red'>*</span> are those with their player killer flag set.</li>\n";
    result += "<li class= 'page_item'>Please note that results update once per minute.</li><li class='page_item'>Invisible players are also not shown.</li>\n";

    result += "</ol>\n";

    if(playercount > 1 || wizcount > 1)
    {
        log_file("mizan.who.txt", result);
    }
    remove_call_out("fake_beat");
    call_out("fake_beat", 60);

}
