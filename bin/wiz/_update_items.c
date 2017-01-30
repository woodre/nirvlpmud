/* _update_items.c
 * companion to player command _check_item.c
 * allows wizards to check for items to update
 * < 100 wizards only see items in their own dirs
 */
  
#define DAEMON "/obj/user/check_item_daemon.c"
#define TMP_FILE "/obj/check_item"
  
mapping lusers;
int cmd_line;

reset() {
  if(!lusers)
    lusers=([]);
}

cmd_update_items(string str) {
  string filename;
  string *lines;
  if(str) {
    if(str=="-single") {
      lines=this_object()->get_files(this_player()->query_real_name(),
          this_player()->query_level(),
          "unupdated");
      if(!sizeof(lines))
        write("Sorry, no un-updated files found.\n");
      else
        write(lines[0]+"\n");
    } else if(str=="-count") {
      lines=this_object()->get_files(this_player()->query_real_name(),
          this_player()->query_level(),
          "unupdated");
      write(sizeof(lines)+" waiting to be checked.\n");
    } else if(sscanf(str,"-update %s",filename)) {
      cmd_line=1;
      this_object()->enter_updated_filename(filename,1);
      cmd_line=0;
    } else if(sscanf(str,"-noupdate %s",filename)) {
      cmd_line=1;
      this_object()->enter_updated_filename(filename,0);
      cmd_line=0;
    } else {
      write("Syntax: update_items [-count|-single|-update <filename>|-noupdate <filename>].\n");
    }
    return 1;
  }
  write("\
Welcome to the item update interface.\n\
Please notify Illarion if there are any problems.\n\n\
Update Item Menu:\n\
[1] List files waiting for update\n\
[2] Mark a file as updated\n\
[3] List updated files\n\
[q] Exit\n\
Enter your selection: ");
  lusers[this_player()]="none";
  input_to("main_menu_select");
  return 1;
}

string *get_files(string name,int lev,string type) {
  string *lines;
  if(type=="updated")
    lines=(mixed)DAEMON->get_updated();
  else
    lines=(mixed)DAEMON->get_not_updated();
  if(!lines)
    return 0;
  if(lev<100)
    lines=regexp(lines,name);
  return lines;
}

show_files(str) {
  string name;
  int lev;
  string *lines;
  name=this_player()->query_real_name();
  lines=get_files(this_player()->query_real_name(),
                  this_player()->query_level(),
                  str);
  lev=sizeof(lines);
  if(!lev) {
    write("No "+str+" files found.\n");
    return 1;
  }
  write("The following files are listed as "+str+"\n");
  rm(TMP_FILE+"."+name);
  while(lev--)
    write_file(TMP_FILE+"."+name,lines[lev]);
  "/bin/wiz/_more"->cmd_more(TMP_FILE+"."+name);
  return 1;
}

prompt_filename() {
  write("What filename do you want to list as being updated?\nFilename [q to quit]: ");
  input_to("enter_updated_filename");
}

main_menu_select(str) {
  switch(str) {
    case "1": return show_files("not updated");
    case "2": return prompt_filename();
              return 1;
    case "3": return show_files("updated");
    case "q": write("Goodbye.\n");
              return 1;
    default: return cmd_update_items();
  }
}

enter_updated_filename(str,approved) {
  string name,junk;
  int lev;
  if(!str || str=="q")
    return cmd_line?0:cmd_update_items();
  if(str[0..0]=="/")
#ifndef __LDMUD__ /* Rumplemintz */
    str=str[1..-1];
  if(str[-2..-1]==".c")
    str=str[0..-3];
#else
    str = str[1..<1];
  if (str[<2..<1] == ".c")
    str = str[0..<3];
#endif
  lev=(int)this_player()->query_level();
  name=(string)this_player()->query_real_name();
  junk=(string)DAEMON->check_item(str);

  if(!junk || lev<100 && sscanf(str,"%s"+name+"%s",junk,junk) !=2) {
    write("File "+str+" not found in update list.\n");
    return cmd_line?0:prompt_filename();
  }
  junk=DAEMON->check_item(str);
  if(junk=="updated") {
    write("That file has already been marked as updated.\n");
    return cmd_line?0:prompt_filename();
  }
  if(cmd_line) {
    DAEMON->mark_updated(str,name+":"+(approved?"yes":"no"));
    if(approved) write("Item marked as updated.\n");
    else write("Item marked as rejected.\n");
  } else {
    write("Did the file need updating? [y/n] ");
    input_to("prompt_approve");
    lusers[this_player()]=str;
  }
}

prompt_approve(str) {
  string name;
  if(!lusers[this_player()]) {
    write("Oops.  Illarion screwed up.  Drop him a line and let him know.\n");
    return;
  }
  if(!str || (str != "y" && str != "n")) {
    write("Did the file ("+lusers[this_player()]+") need updating? [y/n] ");
    input_to("prompt_approve");
    return;
  }
  name=this_player()->query_real_name();
  DAEMON->mark_updated(lusers[this_player()],name+":"+(str=="y"?"yes":"no"));
  write("That file has been marked as "+(str=="y"?"updated":"not needing update")+".  Thanks!\n");
  return prompt_filename();
}
