#define TPGO present("TRAV_OB",this_player())
cmd_module(){
     object module;

     if(environment(this_player())->query_realm()=="NT"){
        write("You can not open the door to the module here!\n");
        return 1;
     }
     module=TPGO->query_mod();
     if(module){
        write("You open a door to your module and jump through.\n");
        say(this_player()->query_name()+" pauses a moment in concentration. A glowing blue door\n\
appears hovering above the ground.  "+this_player()->query_name()+" jumps into it just before\n\
it closes.\n");
        move_object(this_player(),module);
        command("look",this_player());
        return 1;
     }
     write("Your attempt to gate to your module has failed!\n");
     say(this_player()->query_name()+" pauses a moment in concentration.  Nothing appears to\n\
happen but "+this_player()->query_name()+" looks tired.\n");
     return 1;
}
