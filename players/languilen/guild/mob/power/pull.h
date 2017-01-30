/*
 *  Pull.h
 *  Mob G-Wep Ability
 */

pull_cmd(string str){
     string *list;
     mapping guns;

     if(!str){
        notify_fail("What gun do you want to pull?\n");
        return 0;
     }
     if(!TPGO->query_gun() || TPGO->query_gun() == "" || TPGO->query_gun() == 0){
        guns = TPGO->query_all_guns();
        list = keys(guns);
        if(member_array(str, list) == -1){
           notify_fail("That's not a gun you have!\n");
           return 0;
        }
        TPGO->set_gun(str);
        write("You pull the "+str+" from under your jacket.\n");
        return 1;
     } else {
        notify_fail("Don't you think you ought to put away the one you have out first?\n");
        return 0;
     }
     return 0;
}
