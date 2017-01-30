#include <ansi.h>

main()
{
        object *us;
        object ob;
        int s;
        
        s = sizeof(us = users());
        
        while(s--)
        {
                if(us[s] && (int)us[s]->query_level() < 20)
                {
                        if(!present("double_xp_object", us[s]))
                        {
                                move_object(clone_object("/obj/secure/double_obj.c"), us[s]);
                                tell_object(us[s], HIR+"\n\nThe Gods look down upon you and deem you worthy of\n");
                                tell_object(us[s], HIK+"HALF EXPERIENCE err wait no ...."+HIR+"           DOUBLE EXPERIENCE!\n\n"+NORM);
                        }
                }
        }
        write("Ok.\n");
        return 1;
}
