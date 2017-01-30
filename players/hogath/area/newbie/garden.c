/*
 *      File:                   garden.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 3/5/2004
 *      Notes:                  
 *      Change History:         06/05/04
 */

#include <ansi.h>
#include <security.h>

inherit "room/room";  /*inherits room obj*/

int i;

reset(arg){
    if(!present("rabbit"))
    {
     for (i=1;i<3;i++)
      {
       move_object(clone_object("/players/hogath/area/mobs/newbie/rabbit.c"), this_object());
      }
     }/*monster call*/
     
    
if(!arg)
    {
     set_light(1);
     short_desc = "Garden";  /*room short description*/
     long_desc = 
"     A garden just outside the kitchen, neatly arranged rows of \n"+
"vegetables give it a homey and rustic look. A pleasant feeling of \n"+
"peaceful happiness surrounds it, although it looks as though something\n"+
"or someone has been raiding it.\n"+
"A large sign has been placed in front of a hole in the back of the garden.\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/mound2.c","north",  /*exits from room*/
    "/players/hogath/area/newbie/hole.c","hole",
    });
    }
items =
     ({
       "vegetable","Delicious looking cabbage, corn and tomatoes.\n",
       "hole","A dark hole in the ground, maybe you could enter it.\n",
       "kitchen","A small kitchen can be seen through the door to the north.\n",
       "garden","A neatly arranged series of rows and planted vegetables.\n",
       "row","A straight pile of dirt, it seems this would be a good place to plant some vegetables.\n",
       "rows","These are neatly planned rows of cabbage, corn, and tomatoes.\n",
       "cabbage","Ripe green heads of cabbage line this row.\n",
       "corn","Large green stalks with ripe yellow sweet corn stand here.\n",
       "tomatoes","Red vine ripened tomatoes tempt your taste buds.\n",
       "tomato","A lucious red tomato tempts you.\n",
       "vegetables","Delicious looking cabbage, corn and tomatoes.\n",
       "sign","A sign you can read.\n",});
}/*stuff to look at*/

init()
{   ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*add listen command*/
    add_action("read_sign","read");}

cmd_smell(str) {/*smell function*/
    switch(str){
      case "vegetable" : 
      case "vegetables" : write("Pick one and smell it.\n"); break;
      case "garden" : write("You try to smell dirt and get a dirty nose!\n"); break;
      case "cabbage" : write("Gingerly smelling the cabbage waters the mouth.\n"); break;
      case "tomato" : 
      case "tomatoes" : write("Gingerly smelling the tomato cause a mouth watering sensation.\n"); break;
      case "corn" : write("Sweet corn causes a mouth watering sensation.\n"); break;
      case "row" : 
      case "rows" : write("The rows smell like dirt.\n"); break;
      default :
      if(!str){
         write("The air smells strongly of fertilizer.\n"); break;
       }
      else {
        write("You don't detect any smell from "+str+".\n");break;
    }
}   
    return 1;

}

cmd_listen(str) {/*listen function*/
    
    switch(str){
      case "cabbage" : write("Cabbage crunches as it is trod upon.\n"); break;
      case "tomato" :
      case "tomatoes" : write("The tomato squishes when stepped on.\n"); break;
      case "corn" : write("Corn crunches under foot.\n"); break;
      case "garden" : write("Wind rustles through the garden.\n"); break;
      case "hole" : write("A strange silence surrounds the hole.\n"); break;
      default :
      if(!str){
         write("Crickets can be heard chirping throughout the garden.\n"); break;
       }
      else {
        write("You don't detect a sound from the "+str+".\n");break;
      }
    }
  return 1;

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
    write("If your entering the hole bring a light,"+NORM+"\n\n"+
"and beware of the bunnies!"+
""+
"\n\n"+
BOLD+"Hogath\n"+NORM);
    return 1;
}
