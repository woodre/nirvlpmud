/* list the help command if the syntax is correct for the player channel
 * otherwise - just pass it along to regular help system
 */

int help(string str){
   if(str == "player channel" || str == "channel" || str == "pc"){
      write("Use 'pchelp' for help with the Player channel.\n");
      return 1;
   }
   else return 0;
}
