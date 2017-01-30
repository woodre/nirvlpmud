/*
 *  Bash.h
 *  Mob Combat Ability
 */

bash_cmd(string str){
     string err_msg;
     object ob;
     int dam;

     dam = random(10)+10;
     if(!str && !ATT){
        write("Bash who?\n");
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
        write("Whaddaya doin'?  Ya think you're some kinna' wiseguy?  That's not even alive!\n");
	return 1;
     }
     err_msg=ability_check(str, 30);
     while(err_msg != ""){
          write(err_msg);
          return 1;
     }
     write("Your brass knuckles slam into "+ ob->query_real_name() + " heavily.\n");
     say(TPN + " slams " + ob->query_real_name() + " with a pair of brass knuckles.\n");
     this_player()->spell_object(ob, "brass knuckles", dam, 0);
     TPGO->add_graft(-30);
     if(ob && !ob->query_attack()){
        ob->attacked_by(this_player());
     }
     return 1;
}
