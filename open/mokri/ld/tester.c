#include "/players/mokri/define.h"
#define LDHELP "/open/mokri/ld/ldhelp/"
inherit "/obj/treasure.c";

reset(int arg) {
   if(arg) return;
   set_id("tester");

   set_short("an LD tester");
   set_long("blah. test LD stuff\n"+
            "commands:\n"+
            "ldhelp     get help\n"+
"mail2      new mail system\n");
}

init()
{
::init();
#ifdef __LDMUD__
add_action("mail2","mail2");
add_action("ldhelp","ldhelp");
#endif
}

int list_dir(string path)
{
   int x, a, b, longest;
   string file, *files;

   files = get_dir(path);
   longest = -1;
   for(x = 0; x < sizeof(files); x++)
   {
      if(strlen(files[x]) + 1> longest)
         longest = strlen(files[x]) + 1;
   }

   for(x = 0; x < sizeof(files); x++)
   {
      write(capitalize(files[x]));
      for(a = 0; a < (longest - strlen(files[x])); a++)
      write(" ");
      b++;
      if(b == 4)
         {
         b = 0;
         write("\n");
       }
   }
   return 1;
}

int ldhelp(string str)
{
   int x;
   string my_dir, file, *files;
   if(!str)
      {
      write("ldhelp is available on the following items:\n\n");
      list_dir(LDHELP);
      write("\n");
      return 1;
   }

   str = lower_case(str);
   files = get_dir(LDHELP);
   x = member(files,str);
     if(x == -1)
      {
      write("No such help file.\n");
      return 1;
   }
   file = read_file(LDHELP + files[x]);
   write(file + "\n");
   return 1;
}

int mail2(string str)
{
    object mailer;

    mailer = clone_object("/players/mokri/mysql/mail_reader");
    mailer->main(str);
    return 1;
}

drop() { return 1; }
query_auto_load() { return "/open/mokri/ld/tester.c:"; }
