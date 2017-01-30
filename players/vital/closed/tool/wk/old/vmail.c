#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

main(str)
{
    int x;
    string messages;
    mixed *arr;
    if(!str)
    {
        write("View who's mail?\n");
        return 1;
    }
    if(!restore_object("post_dir/"+str))
    {
        write("No messages.\n");
        return 1;
    }
    arr = explode(messages,"\n**\n");
    for(x=0;x<sizeof(arr);x++)
    {
        write(arr[x]+"\n");
    }
    return 1; 
}
