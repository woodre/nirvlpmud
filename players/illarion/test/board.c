#include "/obj/esc.h"
#define NORM ESC + "[0m]"
/* board.c
 *
 * generic message board object
 *
 * by illarion@nirvana
 *
 * messages format: unique_msg_num
 */

#define DATA_DIR "players/illarion/test/"
#define TEXT_EDIT "/obj/user/text_edit"
#define MAX_MESSAGE 50
#define MAX_COMMENT 50
#define MAX_LINES 50

/* saved vars */

mixed *message_data;        /* contains content of messages mapping for saving purposes */
mixed *reader_data;         /* contents of readers mapping for saving purposes */
int next_message_number;    /* next unique message number to be used */       
int next_comment_number;    /* next unique comment number to be used */

/* non-saved vars */

static mapping messages;    /* ([int message_number:({string header,string message,mapping comments]) */
                            /* comments is: ([int comment_number:({string header,string message})]); */
static mapping readers;     /* ([string reader_name:({message_nums_read,comment_nums
_read})]) */
static int num_msgs;        /* number of messages on the board */
static string name;         /* the name of the board (should be unique from other boards with same DATA_DIR */
/* set these vars up when cloning the board */
static string fname;        /* allows spaces in the name */
static int post_level;      /* level needed to post a new message */
static int comment_level;   /* level needed to post a comment */
static int read_level;      /* level required to read the board */
static int remove_level;    /* level needed to remove a message or comment.  
                               anyone can remove their own messages/comments */
static string short_color;
static object post_ob;      /* use the set functions for these objects to control special cases like guilds, etc */
static string post_fun;
static object comment_ob;
static string comment_fun;
static object read_ob;
static string read_fun;
static object remove_ob;
static string remove_fun;
                               
static mapping lusers;      /* keeps track of data from people writing messages to allow multiple writers */
static string post_announce; /* channel to announce new messages */
static string comm_announce; /* channel to announce new comments */

convert_messages_to_array() {
  int *map_keys;
  int s,x;
  message_data=({});
  map_keys=keys(messages);
  s=sizeof(map_keys);
  for(x=0;x<s;x++) {
    message_data+=({map_keys[x]});
    message_data+=({messages[map_keys[x]][0]});
    message_data+=({messages[map_keys[x]][1]});
    message_data+=({convert_comments_to_array(messages[map_keys[x]][2])});
  }
}

convert_messages_to_map() {
  int s,x;
  messages=([]);
  s=sizeof(message_data);
  for(x=0;x<s;x+=4)
    messages[message_data[x]]=({message_data[x+1],message_data[x+2],convert_comments_to_map(message_data[x+3])});
}

convert_comments_to_array(mapping comments) {
  int *map_keys;
  int s,x;
  mixed *ret;
  ret=({});
  if(!comments)
    return ret;
  map_keys=keys(comments);
  s=sizeof(map_keys);
  for(x=0;x<s;x++) {
    ret+=({map_keys[x]});
    ret+=({comments[map_keys[x]][0]});
    ret+=({comments[map_keys[x]][1]});
  }
  return ret;
}

convert_comments_to_map(array comments) {
  int s,x;
  mapping ret;
  ret=([]);
  s=sizeof(comments);
  for(x=0;x<s;x+=3)
    ret[comments[x]]=({comments[x+1],comments[x+2]});
  return ret;
}

convert_readers_to_array() {
  int s,x;
  int *map_keys;
  map_keys=keys(readers);
  s=sizeof(map_keys);
  reader_data=({});
  for(x=0;x<s;x++) {
    reader_data+=({map_keys[x]});
    reader_data+=({readers[map_keys[x]][0]});
    reader_data+=({readers[map_keys[x]][1]});
  }
}

convert_readers_to_map() {
  int s,x;
  readers=([]);
  s=sizeof(reader_data);
  for(x=0;x<s;x+=3)
    readers[reader_data[x]]=({reader_data[x+1],reader_data[x+2]});
}  
  
save_board() {
  convert_messages_to_array();
  convert_readers_to_array();
  save_object(DATA_DIR+fname);
}

restore_board() {
  restore_object(DATA_DIR+fname);
  convert_readers_to_map();
  convert_messages_to_map();
}

status check_post_special() {
  if(!post_ob || !post_fun) return 1;
  return (status)call_other(post_ob, post_fun);
}
status check_comment_special(int post_number) {
  if(!comment_ob || !comment_fun) return 1;
  return (status)call_other(comment_ob, comment_fun, post_number);
}
/* Make sure the special can handle a post number of -1 for a general check, and a 
   specific number for reading a certain message */
status check_read_special(int post_number) {
  if(!read_ob || !read_fun) return 1;
  return (status)call_other(read_ob, read_fun, post_number);
}
status check_remove_special(int post_number) {
  if(!remove_ob || !remove_fun) return 1;
  return (status)call_other(remove_ob, remove_fun, post_number);
}

id(str) {
  return str=="board" || str=="bulletin board" || str==name;
}

set_name(str) {
  int x,s;
  if(!str) {
    return;
  }
  name=str;
  fname="";
  s=strlen(name);
  for(x=0; x<s; x++)
    if(name[x..x]==" ")
      fname+="_";
    else
      fname+=name[x..x];  
  restore_board();
  num_msgs=sizeof(keys(messages));
  lusers=([]);
}

query_name() {
  return name;
}

get_all_unread() {
  object me;
  string name;
  int total_coms;
  int unread_coms;
  int unread_msgs;
  int *comm_nums;
  int *mess_nums;
  int s,s2;
  me=this_player();
  if(!me->is_player())
    return "";
  if(me->query_level()<read_level || !check_read_special(-1))
    return "";
  mess_nums=keys(messages);
  s=sizeof(mess_nums);
  name=(string)this_player()->query_real_name();
  if(!readers[name])
    readers[name]=({({}),({})});
  while(s--) {
    if(member_array(mess_nums[s],readers[name][0])==-1)
      unread_msgs++;
    comm_nums=keys(messages[mess_nums[s]][2]);
    s2=sizeof(comm_nums);
    while(s2--) {
      total_coms++;
      if(member_array(comm_nums[s2],readers[name][1])==-1)
        unread_coms++;
    }
  }
  return " ("+num_msgs+" message"+(num_msgs==1?"":"s")+", "+unread_msgs+" unread, "
            +total_coms+" comment"+(total_coms==1?"":"s")+", "+unread_coms+" unread)";
}

short() {
  if(!name)
    return 0;
  if(!short_color) 
    short_color="";
  return "A bulletin board ["+short_color+name+NORM+get_all_unread();
}

comment_check(int msg_num) {
  int *comments;
  int s,x;
  int unread;
  string name;
  if(!messages[msg_num])
    return "";
  name=this_player()->query_real_name();
  if(!readers[name])
    readers[name]=({({}),({})});
  comments=keys(messages[msg_num][2]);
  s=sizeof(comments);
  for(x=0;x<s;x++)
    if(member_array(comments[x],readers[name][1])==-1)
      unread++;
  if(!s)
    return "none";
  return ""+s+", "+unread+" unread";
}

read_check(msg_id) {
  string name;
  name=(string)this_player()->query_real_name();
  if(!readers[name])
    readers[name]=({({}),({})});
  if(member_array(msg_id,readers[name][0])==-1)
    return "U";
  return " ";
}

string process_header(string header) {
  string author,subject,time;
  if(sscanf(header,"Poster: %s Subject: %s Time: %s",author,subject,time)!=3)
    return header;
  return pad(subject,25)+pad(author,12)+time[0..5]+time[-6..-1];
}

string process_header_long(string header) {
  string author,subject,time;
  if(sscanf(header,"Poster: %s Subject: %s Time: %s",author,subject,time)!=3)
    return header;
  return "Subject: "+subject+"\n"+
         "Author:  "+pad(author,12)+"  Time: "+time;
}

long() {
  int *msgs;
  int x;
  write(short()+"\n");
  if(!this_player()->is_player())
    return;
  if(this_player()->query_level() < read_level || !check_read_special(-1)) {
    write("The contents of the board are oddly blurred.\n");
    return;
  }
  write("Use <board_help> for a list of commands.\n");
  if(!num_msgs) {
    write("Nothing has been posted on it.\n");
    return;
  }
  msgs=(mixed)keys(messages);
  write("     Subject                  Author        Date       Comments\n");
  for(x=0;x<num_msgs;x++)
    write(read_check(msgs[x])+pad(""+(x+1),-2)+" "+process_header(messages[msgs[x]][0])+"  "+comment_check(msgs[x])+"\n");
}

init() {
  if(this_player()->query_level() >= read_level && check_read_special(-1)) {
    add_action("show_help","board_help");
    add_action("cmd_read","read");
    add_action("cmd_post","post");
    add_action("cmd_remove","remove");
    add_action("cmd_list","list");
  }
}

show_help() {
  write("The following commands are available:\n"+
        "board_help\n"+
        "list\n"+
        "read message <#>\n"+
        "post message\n"+
        "list comments for message <#>\n"+
        "read comment <#> for message <#>\n"+
        "post comment for message <#>\n"+
        "remove message <#>\n"+
        "remove comment <#> for message <#>\n"+
        "   All commands will also work if you leave out 'message' and 'comment', ie,\n"+
        "   post for <#>, read <#> or read <#> for <#>.\n"
  );
  return 1;
}

int cmd_list(string str) {
  int num;
  mapping comments;
  string name;
  int *comms;
  int x,s;
  if(!str || str=="messages") {
    long();
    return 1;
  }
  if(!sscanf(str,"comments for message %d",num)
     && !sscanf(str,"for %d",num)) {
    
    notify_fail("Syntax: list\n"+
                "        list for <#>\n"+
                "        list comments for message <#>\n");
    return 0;
  }
  if(num<0 || num > num_msgs) {
    notify_fail("There is no message "+num+"\n");
    return 0;
  }
  comments=messages[keys(messages)[num-1]][2];
  comms=keys(comments);
  s=sizeof(comms);
  if(!s) {
    write("There are no comments for message "+num+"\n");
    return 1;
  }
  write("There are "+s+" comments for message "+num+":\n");
  name=(string)this_player()->query_real_name();
  write("     Subject                  Author           Date\n");
  for(x=0;x<s;x++) 
    write((member_array(comms[x],readers[name][1])==-1?"U":" ")+pad(""+(x+1),-2)+" "+process_header(comments[comms[x]][0])+" "+"\n");
  return 1;
}

int cmd_read(string str) {
  int mnum,cnum;
  int *msg_nums;
  int *com_nums,s;
  mapping comments;
  string name,junk;
  if(str) {
    msg_nums=keys(messages);
    name=(string)this_player()->query_real_name();
    if(sscanf(str,"message %d",mnum) || (sscanf(str,"%d%s",mnum,junk)==2 && junk=="")) {
      if(mnum<0 || mnum>num_msgs) {
        notify_fail("There is no message "+mnum+"\n");
        return 0;
      }
      if(!check_read_special(mnum-1)) {
        return 0;
      }
      write(process_header_long(messages[msg_nums[mnum-1]][0])
           +" Comments: "+comment_check(msg_nums[mnum-1])+"\n"
           +"---------------------------------------------------------------------\n"
           +messages[msg_nums[mnum-1]][1]+"\n");
      if(member_array(msg_nums[mnum-1],readers[name][0])==-1)
        readers[name][0]+=({msg_nums[mnum-1]});
      save_board();
      return 1;
    } else if(sscanf(str,"comment %d for message %d",cnum,mnum)==2
           || sscanf(str,"%d for %d",cnum,mnum)==2) {
      if(mnum<0 || mnum>num_msgs) {
        notify_fail("There is no message "+mnum+"\n");
        return 0;
      }
      comments=messages[msg_nums[mnum-1]][2];
      com_nums=keys(comments);
      s=sizeof(com_nums);
      if(cnum < 0 || cnum > s) {
        notify_fail("There is no comment "+cnum+" for message "+mnum+"\n");
        return 0;
      }
      write(process_header_long(comments[com_nums[cnum-1]][0])+"\n"
           +"---------------------------------------------------------------------\n"
           +comments[com_nums[cnum-1]][1]+"\n");
      if(member_array(com_nums[cnum-1],readers[name][1])==-1)
        readers[name][1]+=({com_nums[cnum-1]});
      save_board();
      return 1;
    }
  }
  notify_fail("Syntax: read <#>\n"+
              "        read message <#>\n"+
              "        read <#> for <#>\n"+
              "        read comment <#> for message <#>\n");
  return 0;

}

void remove_read_nums(int msg_id) {
  int *comment_nums;
  int s,x;
  int s2;
  string *reader_names;
  comment_nums=keys(messages[msg_id][2]);
  reader_names=keys(readers);
  s=sizeof(reader_names);
  while(s--) {
    if(member_array(msg_id,readers[reader_names[s]][0]) != -1)
      readers[reader_names[s]][0]-=({msg_id});
    s2=sizeof(comment_nums);
    while(s2--)
      if(member_array(comment_nums[s2],readers[reader_names[s]][1]) != -1)
        readers[reader_names[s]][1]-=({comment_nums[s2]});
  }
}

void remove_read_comm(int comm_id) {
  int s;
  string *reader_names;
  reader_names=keys(readers);
  s=sizeof(reader_names);
  while(s--)
    if(member_array(comm_id,readers[reader_names[s]][1]) != -1)
      readers[reader_names[s]][1]-=({comm_id});
} 

int cmd_remove(string str) {
  int cnum,mnum;
  string postername,name;
  object me;
  string junk,poster_name;
  mapping comments;
  int s,lev;
  int *msg_nums;
  int *com_nums;
  if(str) {
    me=this_player();
    name=(string)me->query_real_name();
    msg_nums=keys(messages);
    lev=(int)me->query_level();
    if(sscanf(str,"message %d",mnum) || sscanf(str,"%d%s",mnum,junk)==2 && junk=="") {
      
      if(mnum<0 || mnum>num_msgs) {
        notify_fail("There is no message "+mnum+"\n");
        return 0;
      }
      sscanf(messages[msg_nums[mnum-1]][0],"Poster: %s Subject: %s", postername, junk);
      if(lev < remove_level && lower_case(postername)!=name) {
        write("You may only remove your own messages from this board.\n");
        return 1;
      }
      if(!check_remove_special(mnum-1))
      {
        return 0;
      }
      remove_read_nums(msg_nums[mnum-1]);
      messages=m_delete(messages,msg_nums[mnum-1]);
      num_msgs--;
      write("You have removed message "+mnum+" and all its comments.\n");
      save_board();
      return 1;
    } else if(sscanf(str,"comment %d for message %d",cnum,mnum)==2
           || sscanf(str,"%d for %d",cnum,mnum)==2) {
      if(mnum<0 || mnum>num_msgs) {
        notify_fail("There is no message "+mnum+"\n");
        return 0;
      }
      comments=messages[msg_nums[mnum-1]][2];
      com_nums=keys(comments);
      s=sizeof(com_nums);
      if(cnum < 0 || cnum > s) {
        notify_fail("There is no comment "+cnum+" for message "+mnum+"\n");
        return 0;
      }
      sscanf(comments[com_nums[cnum-1]][0],"Poster: %s Subject: %s",postername,junk);
      if(lev < remove_level && lower_case(postername)!=name) {
        write("You may only remove your own comments from this board.\n");
        return 1;
      }
      remove_read_comm(com_nums[cnum-1]);
      messages[msg_nums[mnum-1]][2]=m_delete(messages[msg_nums[mnum-1]][2],com_nums[cnum-1]);
      write("You have removed comment "+cnum+" for message "+mnum+"\n");
      save_board();
      return 1;
    }

    
  }
  notify_fail("Syntax: read <#>\n"+
              "        read message <#>\n"+
              "        read <#> for <#>\n"+
              "        read comment <#> for message <#>\n");
  return 0;
}

int cmd_post(string str) {
  object me;
  int mnum;
  me=this_player();
  if(!str || str=="message") {
    if((int)me->query_level() < post_level) {
      write("You may not post messages on this board.\n");
      return 1;
    }
    if(!check_post_special())
    {
      return 0;
    }
    if(num_msgs>=MAX_MESSAGE) {
      write("No more messages can be posted on this board.\n");
      return 1;
    }
    lusers[me]=({"message",0,"",0});
    write("What is the subject of your message?\nSubject:");
    input_to("enter_subject");
    return 1;
  } else if(sscanf(str,"comment for message %d",mnum)==1
         || sscanf(str,"for %d",mnum)==1) {
    if((int)me->query_level() < comment_level) {
      write("You may not post comments on this board.\n");
      return 1;
    }
    if(!check_comment_special(mnum-1))
    {
      return 0;
    }
    if(mnum < 0 || mnum > num_msgs) {
      write("There is no message "+mnum+".\n");
      return 1;
    }
    if(sizeof(messages[keys(messages)[mnum-1]][2]) > MAX_COMMENT) {
      write("No more comments can be posted for message "+mnum+".\n");
      return 1;
    }
    lusers[me]=({"comment",0,"",keys(messages)[mnum-1]});
    write("What is the subject of your comment?\nSubject:");
    input_to("enter_subject");
    return 1;
    
  }
  notify_fail("Syntax: post\n"+
              "        post message\n"+
              "        post for <#>\n"+
              "        post comment for message <#>\n");
  return 0;
}

enter_subject(str) {
  if(!lusers[this_player()]) {
    write("You're not in the users mapping.\n");
    return;
  }
  if(!str || str=="") {
    write("You must enter a subject. (q to quit)\nSubject:");
    input_to("input_subject");
    return;
  }
  if(str=="q") {
    lusers=m_delete(lusers,this_player());
    write("Aborted.\n");
    return;
  }
  lusers[this_player()][1]=str;
  call_other(TEXT_EDIT,"start_edit",this_object(),"end_write",MAX_LINES);
}

end_write(string final) {
  object me;
  string name,header;
  me=this_player();
  name=(string)me->query_real_name();
  if(!lusers[me]) {
    write("Something has gone wrong... Your message could not be posted.\n");
    return;
  }  
  if(!final) {
    write(capitalize(lusers[me][0])+" aborted.\n");
  } else {
    header=ctime();
    header=header[8..10]+header[4..6]+header[-5..-1]+header[10..15];
    header="Poster: "+capitalize(name)+" Subject: "+lusers[me][1]+" Time: "+header;    
    if(!readers[name])
      readers[name]=({({}),({})});
    if(lusers[me][0]=="message") {
      num_msgs++;
      next_message_number++;
      readers[name][0]+=({next_message_number});
      messages[next_message_number]=({header,final,([])});
      if(post_announce)
        emit_channel(post_announce,"("+post_announce+") A new message has been posted to the "+query_name()+" board.\n");
    } else {
      int msg_num;
      next_comment_number++;
      readers[name][1]+=({next_comment_number});
      messages[lusers[me][3]][2][next_comment_number]=({header,final});
      if(comm_announce)
        emit_channel(comm_announce,"("+comm_announce+") A new comment has been posted to the "+query_name()+" board.\n");
    }
    write("Your "+lusers[me][0]+" has been posted.\n");
    save_board();
  }
  lusers=m_delete(lusers,me);    
}


set_post_level(x) {
  post_level=x;
}

void set_post_special(object ob, string str)
{
  post_ob = ob;
  post_fun = str;
}



set_comment_level(x) {
  comment_level=x;
}

void set_comment_special(object ob, string str)
{
  comment_ob = ob;
  comment_fun = str;
}



set_read_level(x) {
  read_level=x;
}

void set_read_special(object ob, string str)
{
  read_ob = ob;
  read_fun = str;
}


set_remove_level(x) {
  remove_level=x;
}

void set_remove_special(object ob, string str)
{
  remove_ob = ob;
  remove_fun = str;
}

set_post_announce(x) {
  post_announce=x;
}

set_comm_announce(x) {
  comm_announce=x;
}

set_short_color(x) {
  short_color=x;
}