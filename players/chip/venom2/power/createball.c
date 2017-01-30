/*  Level 6 Creation Spell: createsphere - Creates an object 
     that will do one of 4 things. Heal, Attack, Bind, or Transfer
     Mp.  See the object itself for more explanation:
     ~/venom2/OBJ/sphere.c          
*/

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object ob;
	string type;

	if(USER->query_ghost()) return 0;
	if(CRE < 6) return 0;
	if(!str){ 
        tell_object(USER,
        "createball <heal, attack, bind, or transfer>\n");
        return 1;
        } 
	if(GOB->query_mp() < 50){
		tell_object(USER,
		"You do not have enough "+HIK+"Dark Matter"+NORM+" for that.\n");
		return 1;
	}
      if(USER->query_sp() < 50){
            tell_object(USER,
            "You lack the energy to do that.\n");
            return 1;
      }
if(str == "heal" || str == "Heal"){
     type = "Heal";
     }
else if(str == "attack" || str == "Attack"){
     type = "Attack";
     }
else if(str == "bind" || str == "Bind"){
     type = "Bind";
     }
else if(str == "transfer" || str == "Transfer"){
     type = "Transfer";
     }
else{
    tell_object(USER, "createball <heal, attack, bind, or transfer>\n");
    return 1;
    }
ob = clone_object("/players/chip/venom2/OBJ/sphere.c");
ob->set_who(USER->query_real_name());
ob->set_type_of(type);
move_object(ob, environment(USER));
GOB->add_mp(-50);
USER->add_spell_point(-50);
     tell_object(USER,
	"You place your palm on the ground...\n"+
      "A "+HIK+"Dark Matter Sphere"+NORM+" forms at your feet.\n");
     tell_room(environment(USER),
     USER->query_name()+" kneels to the ground...\n"+
     capitalize(USER->PRO)+" forms a "+HIK+"Dark Matter"+BOLD+" Sphere"+NORM+" at "+USER->POS+" feet.\n", ({USER}));
     return 1;
}

