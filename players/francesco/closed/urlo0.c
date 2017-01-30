#include <ansi.h>
#define myself this_player()
static string i;
reset(arg) {
        if(arg) return;
        /* Initialization code goes here */
}
    query_auto_load() {
    return "/players/trix/closed/obj/tool.c:";
}

long() {
        write( "L'urlo!!!\n" );
        return 1;
}

short() {
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name()) {
    tell_object(environment(this_object()),esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
    tell_object(environment(this_object()),capitalize(who)+" has just checked your inventory.");
    tell_object(environment(this_object()),esc+"[0m"+"\n");
   }
   return "Francesco's urlo (bugged)";
}

id(str) {
        if( str == "urlo" ) return 1;
        return 0;
}

init() {
        add_action("urlo","urlo");
        add_action("urlo0","urlo0");
        add_action("fuoco","fuoco");
        return 1;
}

urlo0(str) {
int i; 
object u; 
u=users(); 
for(i=sizeof(u)-1;i>=0;i--)
tell_object(u[i],str+"\n");
return 1;
}

fuoco(str) {
int i; 
object u; 
u=users(); 
for(i=sizeof(u)-1;i>=0;i--)
tell_object(u[i],"                              *  * *\n"+
                 "                            *  *   *  *\n"+
                 "                          *   *     *   *\n"+
                 "                        *    *       *    *\n"+
                 "                       *    *         *    *\n"+
                 "                      *    *           *    *\n"+
                 "                     *     *           *     *\n"+
                 "                     *     *           *     *\n"+
                 "                                 *\n"+
                 "                                 *\n"+
                 "                                 *\n"+
                 "                                 *\n"+
                 "                                 *\n"+
                 "                                 *\n");
return 1;
}

drop() {destruct(this_object()); return 1;}
