/*
 *  Intimidate.h
 *  Mob Graft Ability
 */

intimidate_cmd(string str){
     int amt;
     object ob;

     ob = find_player(str);
     if(!ob){
        write("You must use this against a player.\n");
        return 1;
     }
     amt = find_graft(ob);
     if(amt == 0){
        write(str+" has no money!\n");
        return 1;
     }
     write("You get "+amt+" coins out of "+str+".\n");
     TPGO->add_graft(amt);
     return 1;
}
