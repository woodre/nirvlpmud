/* Calls filer.c and allows a write to the workreport file 
   Usage: file string
*/

main(str)
{
   object f;
   if(!str) return 0;
   f = clone_object("/players/softly/closed/softool/filer");
   move_object(f,this_player());
   command("file "+str,this_player());
   destruct(f);
   return 1;
}
