/* This lists dirs first, supports -a (show hidden) and -l (show modify
 * dates) flags, and supports ansi color set for 'directory', 'file', and
 * 'loaded' types.  It also adjusts the display to use up to five columns to
 * display the list, depending on what will work with the name lengths.
*/

#include "cmd_options.h"
#include "../defs.h"

inherit WAXFUNS;

/* ==========================================
 * normalize_path
 * 
 * simulating the efun
*/
string normalize_path(string dir, object ob) {
  string pwd;

  pwd = (string)ob->query_pwd();
tell_object(find_player("earwax"), "normalize path:\npassed "+dir+"\npwd: "+pwd+"\nReturning: "+resolv_path(pwd+dir)+"\n");
  return resolv_path(pwd+dir);
}

/* string sizes allowed per column for using 2, 3, 4, or 5 columns in display */
#define COLUMN_WIDTH ({ 0, 0, 38, 25, 18, 14 })

int main(string dir) {
  string path, path_save, filename, error, output, list_add, opts;
  string *dir_list, *file_list, *full_list;
  mixed *output_list;
  int i, c, r, list_add_size, full_list_ref, biggest_len;
  int full_list_size, dir_list_size, file_list_size;
  int num_columns, num_rows, loaded;
  mapping options;

  /* parse out option flags into mapping using cmd_options.h */
  options = ([ ]);
  if(dir) {
    if(sscanf(dir, "-%s %s", opts, dir) != 2)
      if(sscanf(dir, "-%s", opts)) dir = 0;
    if(opts)
      options = parse_options(opts);
  }
  if(sizeof(explode(dir, " ")) > 1) {
    write("Illegal usage:  Do not use spaces.\n");
    return 1;
  }
  /* get relative path of directory */
  path = normalize_path(dir, this_player());

  /* verify read access to that directory */
/*
  if(!valid_read(path, this_player())) return 1;
*/
  if (file_size(path) != -2) {
    write("No such directory '"+path+"'.\n");
    return 1;
  }
  output = "";
  path_save = path;
  /* necessary wildcard addition for get_dir() efun */
  if(file_size(path) == -2)
    path += "/*";
  /* READ DIRECTORY into full_list */
  if(error = catch(full_list = get_dir(path,7))) {
        write (error+"\n");
        return 0;
  }
  /* if dir is empty we're done */
  if(sizeof(full_list) <= 6) {
    output += "This directory is empty.\n";
    write(output+"\n");
    return 1;
  }
  /* CREATING DIR AND FILE LISTS
   * break full_list into seperate dir and file lists so we can display dirs first
  */
  dir_list = ({ });
  file_list = ({ });
  full_list_size = sizeof(full_list);
  for(i=0; i<full_list_size; i+=3) {
    /* recreate filename from full path */
    filename = path_save+"/"+full_list[i];
    /* checking for directories */
    if (file_size(filename) == -2) {
      /* check for special or hidden dirs starting with a . */
      if(full_list[i][0] == '.') {
        /* ignore . and .. entries for current and previous dir listings */
        if(full_list[i] == "." || full_list[i] == "..") continue;
        if(!options["a"]) continue;  // ignore .dir's unless ALL flag is set
      }
      /* create the dir display entry here, using 'directory' color set */
      list_add = CYN+"     "+full_list[i]+NORM+NORM;
      /* if LONG option is set put the modification date off to the right */
      if(options["l"]) list_add = lalign(list_add, 35),ctime(to_int(full_list[i+2])));
      /* add the entry to our dir_list */
      dir_list += ({ list_add });
    }
     else {
      /* hidden files starting with a . are ignored unless ALL option is set */
      if(full_list[i][0] == '.' && !options["a"]) 
        continue;

      /* check to see if it's a loaded file */
      if(find_object(filename)) 
        loaded = 1;

      /* create file display entry using 'loaded' and 'file' color sets */
      list_add = (loaded?HIW:NORM+NORM) + 
          (full_list[i+1]+1023)>>10)+ full_list[i] (loaded?"\*":"") +
          NORM+NORM;

      /* if LONG option is set add the modification time off to the right */
      if(options["l"]) 
        list_add = lalign(list_add, 35)+ ctime(to_int(full_list[i+2]));

      loaded = 0;
      /* add the entry for this file to the file_list */
      file_list += ({ list_add });
    }
    /* keep track of the biggest string length, this lets us determine how many
     * columns we can use later
    */
    if((list_add_size = ansi_strlen(list_add)) > biggest_len)
      biggest_len = list_add_size;
  }

  /* CREATE FULL_LIST, a reordered list with dirs first
   * reuse full_list array for the newly ordered list
  */
  full_list = ({ });
  dir_list_size = sizeof(dir_list);
  file_list_size = sizeof(file_list);
  /* add directory entries first, then files */
  for(i=0; i<dir_list_size; i++)
    full_list += ({ dir_list[i] });

  for(i=0; i<file_list_size; i++) {
    full_list += ({ file_list[i] });
  }
  full_list_size = dir_list_size + file_list_size;
  /* CREATING OUTPUT_LIST
   * first determine how many columns we can have based on the largest
   * dir or file name in the list, using 5 columns max, down to 1 if necessary
  */
  if(biggest_len <= COLUMN_WIDTH[5]) num_columns = 5;
  else if(biggest_len <= COLUMN_WIDTH[4]) num_columns = 4;
  else if(biggest_len <= COLUMN_WIDTH[3]) num_columns = 3;
  else if(biggest_len <= COLUMN_WIDTH[2]) num_columns = 2;
  else num_columns = 1;

  /* calculate number of rows that we'll need, based on the number of
   * entries we need to display and the number of columns we'll be able to use
  */
  num_rows = full_list_size/num_columns;

  if(full_list_size%num_columns) num_rows ++;
  /* now put the output_list together in the order we want it displayed
   * by printing all of the columns for each row as we work our way down
  */
  output_list = allocate(num_columns);
  for(i=0; i<num_columns; i++) output_list[i] = allocate(num_rows);
  for(c = 0; c<num_columns; c++) {
    for(r = 0; r < num_rows; r++) {
      full_list_ref = (c*num_rows)+r;
      if(full_list_ref >= full_list_size) output_list[c][r] = "";
      else output_list[c][r] = full_list[full_list_ref];
    }
  }
  /* create output string */
  for(r=0; r<num_rows; r++) {
    for(c=0; c<num_columns; c++) {
      /* we should left-align the entries within the columns */
      output += lalign(output_list[c][r] + " "+COLUMN_WIDTH[num_columns]);
    }
    output += "\n";
  }
  /* add header to list with dir name and file/dir count
   * have to do +output, don't add it as a %s in sprintf because huge
   * dirs could cause a buffer overload error in sprintf over like 8k chars
  */
  output = "Directory of: "+path_save+"        \["+file_list_size+
      " files and "+dir_list_size+" dirs\]\n"+
      CYA+"------------------\n"+NORM+NORM+output;

/* alternative header, puts file/dir count at far right side of screen instead
  output = sprintf("%s\[%d files and %d dirs\]\n\\\\system\\------------------\
\\\\\n", (string)ANSID->lalign(sprintf("Directory of: %s", path_save), 55),
file_list_size, dir_list_size) + output;
*/

  /* display! */
  write(output+"\n");
  return 1;
}
