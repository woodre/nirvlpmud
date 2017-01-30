#include "/players/pestilence/ansi.h"

main(){
        object woo2;
        int woo;
        int i;
        i = 1;
        woo = first_inventory(this_player());
        
        write(
                HIK+"   ____________ [ Ehanced Inventory ] ____________"+NORM+"\n"+
        "   Item: \n");
        
        while(woo){
                woo2 = next_inventory(woo);
                if(woo->short()){
                        if(i < 10){ write("["+HIW+"0"+i+NORM+"] "+woo->short()+" "); }
                        else{ write("["+HIW+i+NORM+"] "+woo->short()+"  ");  }
                        if(woo->armor_class()){  write(HIW+"["+woo->query_type()+"]"+NORM+"\n"); }
                        else if(woo->weapon_class()){ write(HIW+"[Weapon]"+NORM+"\n"); }
                        else{ write("\n"); }
                        i++;
                }
                
                woo = woo2;
        }
        return 1;
}
