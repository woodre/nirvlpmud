/* Combat ability that is slightly better than shock.
   Must be Muscle guild level to use it.
*/

#define BASEDAM 4
#define RANDDAM random(10)
#define GRAFTCOST 40
#define AT_MSG "You are slammed by the butt of a Mobster's gun.\n"

butt_cmd(string str){
     string err_msg;
     object ob;
     int dam;

     dam = BASEDAM+RANDDAM;
     if(!str && !ATT){
        write("Butt whom?\n");
        return 1;
     }
     if(!str && ATT){
        str == ATT->query_real_name();
     }
     ob = present(str, ENVTP);
     if(!ob){
         write(capitalize(str) + "is not here.\n");
         return 1;
     }
/*     if(find_player(str)){
         write("You may not use this ability on a player.\n");
         return 1;
     }  */
     if(!living(ob)){
        write("Whaddaya doin'?  Ya think you're some kinna' wiseguy? "+
              " That's not even alive!\n");
        return 1;
     }
     err_msg=ability_check(str, GRAFTCOST);
     while(err_msg != ""){
          write(err_msg);
          return 1;
     }
     write("You flip your gun around and slam the butt of it into " +
           ob->query_real_name() + ".\n");
     say(TPN + " spins his gun around and slams " + ob->query_real_name() +
         " with the butt end of it.\n");
     this_player()->spell_object(ob, "gun butt", dam, 0, AT_MSG);
     TPGO->add_graft(-GRAFTCOST);
     if(ob && !ob->query_attack()){
        ob->attacked_by(this_player());
     }
     return 1;
}
