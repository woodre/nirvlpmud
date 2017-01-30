/*---------------------*/
/*Owner :  Hogath      */
/*Created:  2/13/04    */
/*Area:  ENTRANCE      */
/*---------------------*/
#include <ansi.h>

inherit "room/room";  /*inherits room obj*/

reset(arg){
    if(!arg)
    {
     set_light(1);
     short_desc = "Bare Field";  /*room short description*/
     long_desc = 
"     A large shimmering rift stands here before a dark and\n"+
"forboding forest.  The ground around you is bare, as if burned\n"+
"by the magical energies that are coming from the within the rift.\n"+
"To the south a shallow mound can be seen in a grassy field.\n"+
"There is a sign here that can read here as well.\n";                /*long description of room*/

    
dest_dir = ({
    "room/mount_pass","rift",
    "/players/hogath/area/newbie/field.c","south",/*exits from room*/
    });
            
    }
items = 
     ({
       "mound","A small mound to the south of the rift",
       "field","A grass filled field to the south of the rift",
       "rift","The "+HIB+"blue"+NORM+"-"+BOLD+"green"+NORM+" portal will take you back to Nirvana",
       "ground","The ground is dry and cracked, as though blasted by\n"+
                "some gigantic force",/*items you can look at*/
       "sign","This can be read",});
}

init()
{
    ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*adds listen command*/
    add_action("read_sign","read");   /*adds sign to be read*/
}   
search_me(str)   /*search function*/
{
    if(!str)
    {
     notify_fail("What are you trying to search\n");
     return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

read_sign(str)  /*read sign function*/
{
    if(!str) return 0;
    if(str !="sign") return 0;
    write(HIW+"Welcome to Hogaths area!"+NORM+"\n\n"+
"NORTH -- Incomplete\n"+
"SOUTH -- NEWBIE AREA LEVELS 1-10\n"+
"\n\n\n"+
BOLD+"Hogath\n"+NORM);
    return 1;
}

cmd_smell(str) /*smell function*/
{
    switch(str){
      case "field":
      case "mound": write("It is too far away for you to smell it.\n");break;
      case "rift": write("The rift gives of a faint odor of ozone.\n");break;
      default : write("You try to smell the "+str+" but whatever odor it might have"+
                      "is over powered by the burning smell of the rift.\n"); break;
    }
      
    return 1;
}

cmd_listen(str) /*listen function*/
{
    switch(str){
      case "rift":write("Crackling energy can be heard around the rift.\n");break;
      default :
      if (!str) {write("What are you trying to listen too???\n");return 1;}
    else {
      write("You listen to the "+str+", but only hear the crackling of the rift in the background.\n");
  }
}
return 1;}



