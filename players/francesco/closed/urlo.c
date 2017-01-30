#include <esc.h>
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
  return "Fran's urlo";
}

id(str) {
        if( str == "urlo" ) return 1;
        return 0;
}

init() {
        add_action("urlo","urlo");
        add_action("urlo0","urlo0");
        return 1;
}

urlo0() {
int i; 
object u; 
u=users(); 
for(i=sizeof(u)-1;i>=0;i--)
tell_object(u[i],"\nSomeone gossips: Test.\n");
return 1;
}

urlo() {
int i; 
object u; 
u=users(); 
for(i=sizeof(u)-1;i>=0;i--)
{tell_object(u[i],"\n     ________________                           ______________\n");
tell_object(u[i],"    \/                \\                         \/ \/            \\---_\n");
tell_object(u[i],"   \/ \/          \\ \\   \\                       |     -    -         \\\n");
tell_object(u[i],"   |                  |                       | \/         -   \\  _  |\n");
tell_object(u[i],"  \/                  \/                        \\    \/  \/   \/\/    __   \\\n");
tell_object(u[i]," |      ___\\ \\| | \/ \/                          \\\/ \/\/ \/\/ \/ \/\/\/  \/      \\\n");
tell_object(u[i]," |      \/          \\                           |             \/\/\\ __   |\n");
tell_object(u[i]," |      |           \\                          \\              \/\/\/     \\\n");
tell_object(u[i],"\/       |      _    |                           \\               \/\/  \\ |\n");
tell_object(u[i],"|       |       \\   |                            \\   \/--          \/\/  |\n");
tell_object(u[i],"|       |       _\\ \/|                             \/ (o-            \/ \\|\n");
tell_object(u[i],"|      __\\     <_o)\\o-        \/                  \/            __   \/\\ |\n");
tell_object(u[i],"|     |             \\        \/     Yeah,        \/              .)  \/  |\n");
tell_object(u[i]," \    ||             \\      \/      Heh Heh Heh \/   __          &\/ \/ \\ |\n");
tell_object(u[i],"  |   |__          _  \\    \/       Heh Heh. \\ (____ *)         -  |   |\n");
tell_object(u[i],"  |   |           (*___)  \/                  \\    \/               |  |\n");
tell_object(u[i],"  |   |       _     |    \/                    \\  (____            |  |\n");
tell_object(u[i],"  |   |    \/\/_______\/                             ####\\           |  |\n");
tell_object(u[i],"  |  \/       | UUUUU__   \\                    \/   ____\/ )         |_\/\n");
tell_object(u[i],"   \\|        \\_nnnnnn_\\~\\ \\                  \/   (___             \/\n");
tell_object(u[i],"    |       ____________\/  \\                \/     \\____          |\n");
tell_object(u[i],"    |      \/             Ya, ya,                      \\          |\n");
tell_object(u[i],"    |_____\/               YA!                          \\__________\\\n");
}
return 1;
}

drop() {destruct(this_object()); return 1;}
