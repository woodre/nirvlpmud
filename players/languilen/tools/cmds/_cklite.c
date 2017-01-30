cmd_cklite(arg){
int lite;

    if(arg){
       write("This command doesn't need an argument.\n");
       return 1;
    }
    lite = this_player()->set_light(0);
    write("Light value = "+lite+".\n");
    return 1;
}
