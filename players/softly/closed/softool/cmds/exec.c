/* nice little cmd that runs lines of code w/o creating an obj
   Original created by Verte ... Thanks :)
*/

#define JUNK "/players/softly/closed/softool/tempjunk.c"
main(str) 
{
  if(!str) 
    {
      notify_fail("You must supply some code :p\n");
      return 0; 
    }
  destruct(JUNK);
  rm(JUNK);
  write_file(JUNK,"#include \"/players/softly/closed/define.h\"\n"+
	     "execute_file() {\n"+
	     str+"\n"+
	     " return 1; }\n");
  JUNK->execute_file();
  destruct(JUNK);
  rm(JUNK);
  return 1; 
}
