/* odoyle rulz */

#include <security.h>

int
cmd_upd_dir_zzz(string x)
{
    if((int)this_player()->query_level() < CREATE)
      return 0;

    else
    {
      string dir;
      string *files;
      int s;
      
      files = explode(x,"/");
      files -= ({ files[sizeof(files)-1] });
      
      dir = implode(files,"/");
      
      files = get_dir(x);
      s = sizeof(files);
      write("Updating "+s+" files...\n");
      while(s--) {
        write(dir+"/"+files[s]+"\n");
        destruct(dir+"/"+files[s]);
      }
    
    }

    return 1;
}
