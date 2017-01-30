#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 10) return 0;

tell_object(user, 
 "Your "+name+" releases pure evil...\n");
 user->add_alignment(-300);
return 0;
}


