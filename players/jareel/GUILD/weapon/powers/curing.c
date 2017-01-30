#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
object poison;
if(random(100) > 30) return 0; 
if(!present(ATT, environment(USER))) return 0;
	poison = first_inventory(USER);
	while (poison) {
		next = next_inventory(poison);
		if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
			poison->id("poison")) {
			tell_object(USER,
			HIG+"The "+HIW+name+HIG+" glows...\n"+
         "Poison is destroyed"+NORM+HIW+"..."+NORM+"\n");
			destruct(poison);
		}
		poison = next;
	}
return 0;
}

