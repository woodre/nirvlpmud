/*          Yeah.... did you get the memo?  
            non rakh weapons 6-16 rakh weapons 9-19
*/
starkwield(string wep){
object weapon;
int setwc;

if(!wep){write("Wield what?\n"); return 1;}
if(!present(wep,TP)){write("Wield what?\n"); return 1;}

weapon = present(wep,TP);
storedwepobj = weapon;
setwc=6+hunting_lvl;

if(weapon->query_type()=="spear" || weapon->query_type()=="polearm"){
    setwc=9+hunting_lvl;
}
storedwc = weapon->weapon_class();
if(setwc < weapon->weapon_class()){
    weapon->set_class(setwc);
    return 0;
}
TP->wield(weapon);
return 1;}


/*unwielding time!*/

starkunwield(string wep){
object weapon;
if(wep)
    weapon = present(wep,TP);
    else
    weapon = storedwepobj;
if(present(storedwepobj,TP)){
    weapon->set_class(storedwc);
    TP->stop_wielding();
    write("Ok!\n");
    return 1;
}
return 1;
}