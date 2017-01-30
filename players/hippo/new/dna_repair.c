#include "std.h"
#include "/players/hippo/bs.h"
int i;
object dna;
string repairing;
 id(str) { return str == "repair"; }
reset(arg) {
   i=2+random(2);
}
long() {
   write("You are looking at a difficult repair mechanism. This was carried"+BS+
      "by a HIV-virus, and you wander if it could repair frame-shifted dna strings."+BS+
      "At least you could try..."+BS);
}
short() {
   return "A DNA-repair mechanism.";
}
query_save_flag() {return 1;}
init() {
   add_action("repair","repair");
}
repair(arg){
   if(arg!="dna") {
      notify_fail("You could only repair DNA. And you gotta have it for repairing."+BS);
		return 0;
		}
repairing = "dna";
if(!present(repairing)){
   write("You should get the DNA before you can repair it!"+BS);
   return 1;
}
i=i-1;
 this_player()->heal_self(300);
 write("You have repaired the dna-string. This healed you completely."+BS);
say(this_player()->query_name() +" was fully healed by the DNA-repair mechanism"+BS);
 if(i==0){
 write("This was the last time you could heal yourself. The repair mechanism is"+BS+
      "messed up itself, and you can not use it again."+BS);
	        destruct(this_object());
       destruct(present("dna",this_player()));
                }
	return 1;
        }

get() {
    return 1;
}

query_weight() {
   return 1;
}
