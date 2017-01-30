inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
set_weight(0);
set_value(5);
}
short(){ return ""+HIW+"F"+HIC+"a"+HIB+"K"+HIG+"i"+HIR+"e "+BLK+"H"+HIY+"e"+NORM+BLU+"A"+YEL+"L"+NORM+" ."+HIR+"1"+NORM+""; }
long(){ write("A fake heal for heal types ."+HIR+"1"+NORM+".\nYou can use '"+HIW+"sneakheal"+NORM+"' to place it onto another player.\nYou can also '"+HIW+"cash"+NORM+"' it in.\n"); }
id(str){ return str == "heal" || str == "fakie heal"; }
query_save_flag(){      return 1;       }


init(){
   ::init();
   add_action("HEALME","eat");
   add_action("HEALME","pop");
   add_action("HEALME","squeeze");
   add_action("sneakheal","sneakheal");
   add_action("cashme","cash");
}

HEALME(arg){
if(arg != "THIS IS NOT COOL"){
write(HIW+BLINK+"YOU JUST TRIED TO USE A FAKIE HEAL!\n"+NORM); 
write("The FaKie HeAL disintegrates.\n");
destruct(this_object());
return 1; }
}
/* This is borrowed from Mizan's KickMe! sign! */
sneakheal(arg) {
int chance;
object vict;
        if(!arg) return 0;
        vict=find_player(arg);
        if(!vict) { write(vict+" is not here!\n"); return 1; }
        if(!present(vict, environment(this_player()))) {
        write(vict+" is not in the same room.\n");
        return 1; }
        if((vict->query_level())>19) {
        write("Ahh... not a good idea...\n");
        return 1;
        }
        chance=random(10);
        if(chance > 6) {
                write(HIM+"YOU FAILED!\n"+HIY+""+arg+" knows you are using FaKie HeAL!\n"+NORM);
                say((this_player()->query_name())+" places a heal into "+arg+"'s inventory. \n");
                tell_object(vict, (this_player()->query_name())+" "+HIW+BLINK+"JUST TRIED TO PUT A FAKIE HEAL ON YOU!!!!\n"+NORM);
                return 1;
                }
        write("You place the FaKie HeAL into "+arg+"'s inventory\n");
        move_object(this_object(), vict);
        return 1;
        }

cashme(arg){
if(arg == "fakie heal" || arg == "heal"){
write("You cash in the FaKie HeAL for "+HIY+"coins"+NORM+".\n");
this_player()->add_money(100+random(1401));
destruct(this_object());
return 1; }
write("Cash what?\n");
return 1; }
