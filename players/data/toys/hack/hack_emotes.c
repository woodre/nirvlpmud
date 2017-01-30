/* I reformatted the indentations to show the braces more clearly. */
/* I would suggest this as a general coding style as it helps with */
/* readability and finding errors too. I also converted the tabs to*/
/* 4 spaces each. Vital */

#include <ansi.h>
#include "/players/data/defs.h"
#define cpn ob->query_name()

fgrin(str)
{
    object ob;
    if(!str)
    {
        write(HIK+"You grin with a fatal look in your eyes.\n"+NORM);
        say(HIK+TPN+" grins with a fatal look in "+TPP+" eyes.\n"+NORM);
        return 1;
    }
    else
    {
        ob = present(str, environment(TP));
        if(ob && ob != TP)
        {
            write(HIK+"You grin fatally at "+cpn+".\n"+NORM);
            say(HIK+TPN+" grins fatally at "+cpn+".\n"+NORM, ob);
            tell_object(ob,HIK+TPN+" grins fatally at you.\n"+NORM);
            return 1;
/* Added this return */
        }
/* Added the above brace */
        else
/* Removed the braces around this else */
        ob = find_player(str);
        if(!ob || ob == TP || in_editor(ob) || ob->query_invis() >= TPL)
            return 0;
        if(ob->query_tellblock()){ write(cpn+" is blocking emotes.\n");
            return 1;
   }
        write(HIK+"You grin fatally at "+cpn+" from afar.\n"+NORM);
        tell_object(ob, HIK+TPN+" grins fatally at you from afar.\n"+NORM);
        return 1;
    }
}
