
inherit "room/room";

reset(arg) {
    string env;
    int num;
   if(arg) return;
    short_desc = "Giulus' room" ;
    long_desc = 
"\nYOU LAND IN THE LAND OF THE SECRETS AGENTS!!\n\n"+
 "                 @@@@\n"+
 "                @@  o\\ \n"+
 "                @@    >\n"+
 "                 \\  ^/ \n"+
 "               ___|_|___\n"+
 "              /  /\\ /\\  \\ \n"+
 "             / / \\ | / \\ \\ \n"+
 "            /  )  \\|/  (  \\ \n"+
 "           /  /|   |___|\\  \\ \n"+
 "           \\  \\|   (________)\n" +   
 "            \\  \\_v_|__ |\n"+
 "             \\ / __/--\"|\n"+
 "              V__/~|   |\n"+
 "               L7------I\n";
    num=random(3);
    if(!num)
        env="/players/hurtbrain/workroom";
    else if(num==1)
        env="/players/hurtbrain/workroom2";
    else
        env="/players/hurtbrain/castello/entrance";
   dest_dir =
   ({
    env ,"south",
    } ) ;
}
