/******************************************************************************
 *  File:           composer.c
 *  Function:       compose news post
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         09/06/2004
 *  Notes:          starting from semi-scratch
 *  Change History: version 1.0 release, 2005.10.29 [converting to lib]
 *****************************************************************************/
#pragma strict_types

#include <security.h>
#include <ansi.h>
#include <news.h>

#define PROMPT "]"

inherit "obj/treasure";

string  Global_Subject;             /* news headline */
string  Global_Body;                /* news body */
int     Global_Size;                /* news size */
string  Global_Message;             /* Text of Output Message */
string  *Global_Posts;              /* Posts in Current Group */
string  Global_Group;               /* Path to Current Group  */
string  Global_Name;                /* Name of Current Group  */
string  *Global_Group_Names; /* Necessitated by Archaic input_to function */
mapping Global_Group_List;          /* Group:Path Mapping     */
string  Global_ID;                  /* Message Name/ID Tag    */

void reset(status arg);
void init();
status post_it(string str);
varargs status compose_post(string subject);
void get_subject(string subject);
status get_subject2(string subject);
status get_message(string text);
status last_line(string text);
void final_prep(string str);
status commit_to_file();
string string_level();
void list_groups();
status select_group();
status select_group2(string group);
status write_out_post();
status proceed_to_posting(string answer);
status proceed_to_write(string answer);

void
reset(status arg)
{
   if(arg) return;
   set_name("poster");
   set_alias("a poser");
   set_short("A Poster");
   set_long("This is a small news poster. Now you can 'post'.\n");
   set_weight(1);
   set_value(0);
}

void
init()
{
  ::init();
/*   if (this_player() && this_player()->query_level() > 20) */
    add_action("post_it","post");
/*   else */
/*     destruct(this_object()); */
}

status
post_it(string str)
{
  "/players/vital/closed/news/composer.c"->compose_post(str);
  return 1;
}

varargs status
compose_post(string subject)
{
  Global_Size = 1;
  if (!subject || subject == "")
  {
    write("  Welcome to the vNews System. The vNews Poster is currently at \
version\n" + HIW + VERSION + NORM +" and will probably undergo several \
revisions before it is\ncompletely functional. If you have any issues with \
the way the vNews\nReader works, mudmail Vital immediately.\n\nPlease select \
a newsgroup for your post.\n");
    list_groups();
    select_group();
    return 1;
  }
  if (subject == BLANK_SUBJECT)
  {
    input_to("get_subject");
    return 1;
  }
  if ( !Global_Name )
  {
    select_group();
    return 1;
  }
  get_subject2(subject);
  return 1;
}

void
get_subject(string subject)
{
  if (!subject || subject == "")
  {
    write("Headline defaulting to " + BLANK_SUBJECT + "\n");
    get_subject2(BLANK_SUBJECT);
    return;
  }
  if (subject == "x")
  {
    write("No Post Created. Good bye.\n");
    return; /* from return 1 - verte */
  }
  if (strlen(subject) > MAX_TITLE)
  {
    write("Headline is too long. You only have " + MAX_TITLE +
          " characters.\n");
    compose_post();
    return;
  }
  if (subject == "~q")
  {
    write("Message Posting Aborted!\n");
    return;
  }
  get_subject2(subject);
  return;
}

status
get_subject2(string subject)
{
  Global_Subject = subject;
  write("\nCreating news message with the headline:\n\t\"" +
    Global_Subject + "\"\n");
  write("The message \"" + Global_Subject + "\" will be posted under \"" +
    Global_Name + "\"\n\tDo you want to proceed? [y]es/[n]o:\n");
  input_to("proceed_to_posting");
  return 1;
}

status
proceed_to_posting(string answer)
{
  if ( !answer || answer == "" || !stringp(answer) )
  {
    get_subject2(Global_Subject);
    return 1;
  }
  if (answer == "x")
  {
    write("No Post Created. Good bye.\n");
    return 1;
  }
  if ( answer == "n" || answer == "no" || answer == "N" || answer == "No")
  {
    write("Please enter a new subject for your message.\n  Subject: \]\n");
    input_to("get_subject");
    return 1;
  }
  write("Starting message posting. Enter '**' to post the message to the\n\
newsgroup and '~q' to abort. Enter the message:\n");
  Global_Body = "";
  Global_Size = 1;
  call_other("/obj/user/text_edit","start_edit",this_object(),"final_prep",50);
  return 1;    
}


void
final_prep(string str)
{
  string poster_name, poster_level, datestamp, temp;
  if (!str || str == "")
  {
    write("The message is blank. Exiting vNews System.\n");
    return;
  }
  poster_name = capitalize((string)this_player()->query_real_name());
  poster_level = string_level();
  datestamp = ctime();
  temp =  "Posted:    " + datestamp + "\n" +
          "Subject:   " + Global_Subject + "\n" +
          "Author:    " + poster_name + "\n" +
          "Level:     " + poster_level + "\n" +
          "Message: \n" + str;
  Global_Body = temp;
  commit_to_file();
}

status
proceed_to_write(string answer)
{
  if ( !answer || answer == "" || !stringp(answer) )
  {
    write("You must input either \'yes\' or \'no\'.\n");
    commit_to_file();
    return 1;
  }
  if ( answer == "n"  ||
       answer == "no" ||
       answer == "N"  ||
       answer == "No" ||
       answer == "x" )
  {
    write("Exiting News Post with out writing changes.\n");
    return 1;
  }
  write_out_post();
}

status
commit_to_file()
{
  if(!Global_Group)
  {
    write("No file name to write.\n");
    select_group();
    return 1;
  }
  if(!Global_Body)
  {
    write("No message to write.\n");
    return 0;
  }
  write(Global_Body + "\n");
  write("\n\nIs this correct? Select \[yes\]\/\[no\]: ");
  input_to("proceed_to_write");
  return 1;
}

status
write_out_post()
{
  string post_file;
  int datestamp;
  datestamp = time();
  post_file = Global_Group + datestamp + ".news";
  
  write_file(post_file, Global_Body);
  write("Posting Message to " + Global_Name +".\n");
  write(Global_Body + "\n");
  if ( text_contains(Global_Name, "dev") )
  {
    emit_channel("wiz", "\(Dev\) A new post has been made to the " +
      Global_Name + " group.\n");
    return 1;
  }
  else
  {
    emit_channel("announce", "\(Announce\) A new post has been made to the " +
      Global_Name + " group.\n");
    return 1;
  }
  return 1;
}

string
string_level()
{
  int player_level, player_xlevel;
  player_level = (int)this_player()->query_level();
  player_xlevel = (int)this_player()->query_extra_level();
  switch (player_level)
  {
    case 20..39 : return "Content Creator";
    case 40..99 : return "Developer";
    case 100..699 : return "Senior Developer";
    case 700..100000 : return "Administrator";
    default : return "Level: " + player_level + "+" + player_xlevel;
  }
}

void
list_groups()
{
  int a, b, c, d, e, f, g, h, i, j;
  string *level1, *level2, *level3, *level4, *level5;
  string name;

  Global_Group_List = ([ ]);
  level1 = get_dir(GROUPS + "???*");
  a = sizeof(level1);
  for (b = 0; b < a; b++)
  {
    if(file_size(GROUPS + level1[b]) == -2);
    {
      name = level1[b];
      Global_Group_List += ([ name:GROUPS + level1[b] + "/" ]);
      if (level2 = get_dir(GROUPS + level1[b] + "/???*"))
      {
        c = sizeof(level2);
        for (d = 0; d < c; d++ )
        {
          if (file_size(GROUPS + level1[b] + "/" + level2[d]) == -2)
          {
            name = level1[b] + "." + level2[d];
            Global_Group_List += ([ name:GROUPS + level1[b] + "/" +
              level2[d] + "/" ]);
            if (level3 = get_dir(GROUPS + level1[b] + "/" + level2[d] +
              "/???*"))
            {
              e = sizeof(level3);
              for (f = 0; f < e; f++)
              {
                if (file_size(GROUPS + level1[b] + "/" + level2[d] + "/" +
                  level3[f]) == -2)
                {
                  name = level1[b] + "." + level2[d] + "." + level3[f];
                  Global_Group_List += ([ name:GROUPS + level1[b] + "/" +
                    level2[d] + "/" + level3[f] + "/" ]);
                  if (level4 = get_dir(GROUPS + level1[b] + "/" + level2[d] +
                    "/" + level3[f] + "/???*"))
                  {
                    g = sizeof(level4);
                    for (h = 0; h < g; h++)
                    {
                      if (file_size(GROUPS + level1[b] + "/" + level2[d] + "/"
                        + level3[f] + "/" + level4[h]) == -2)
                      {
                        name = level1[b] + "." + level2[d] + "." + level3[f] +
                          "." + level4[h];
                        Global_Group_List += ([ name:GROUPS + level1[b] +
                          "/" + level2[d] + "/" + level3[f] + "/" +
                          level4[h] + "/" ]);
                        if (level5 = get_dir(GROUPS + level1[b] + "/" +
                          level2[d] + "/" + level3[f] + "/" + level4[h] +
                          "/???*"))
                        {
                          i = sizeof(level5);
                          for (j = 0; j < i; j++)
                          {
                            if (file_size(GROUPS + level1[b] + "/" +
                              level2[d] + "/" + level3[f] + "/" + level4[h] +
                              "/" + level5[j]) == -2)
                            {
                              name = level1[b] + "." + level2[d] + "." +
                                level3[f] + "." + level4[h] + "." + level5[j];
                              Global_Group_List += ([ level5[j]:GROUPS +
                                level1[b] + "/" + level2[d] + "/" + level3[f] +
                                "/" + level4[h] + "/" + level5[j] + "/" ]);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

status
select_group()
{
  int x, y, z, temp;
  string output;
  
  Global_Group_Names = keys(Global_Group_List);
  z = 0;
  write("Select a newsgroup by number from the list below:\n");
  y = sizeof(Global_Group_Names);
  for (x = 0; x < y; x++)
  {
    if ( (this_player()->query_level() < WIZARD ) )
      if ( !(text_contains(Global_Group_Names[x], "poetry")) )
        continue;
    output = pad("[" + (x + 1) + "] ", -5) +
      pad(Global_Group_Names[x], 32);
    if (z < 1)
      z++;
    else
    {
      z = 0;
      output += "\n";
    }
    write(output);
  }
  write("\nSelect Group's Number: ");
  input_to("select_group2");
  return 1;
}

status
select_group2(string group)
{
  int selected_number;
  string junk;
  if (group == "")
  {
    write("Returning to previous menu.\n");
    compose_post();
    return 1;
  }
  if (group == "x")
  {
    write("No Post Created. Good bye.\n");
    return 1;
  }
  if (sscanf(group, "%d %s", selected_number, junk) == 1)
  {
    if (selected_number < 1 || 
        selected_number > (sizeof(Global_Group_Names)) ) 
    {
      write("There is no group " + selected_number + "\n");
      select_group();
      return 0;
    }
    Global_Name = Global_Group_Names[selected_number - 1];
    Global_Group = Global_Group_List[Global_Name];
    if ( this_player()->query_level() < WIZARD )
    {
      if ( !text_contains(Global_Group, "poetry") )
      {
        write("There is no group " + selected_number + "\n");
/*         if (message_menu(group)) return 1; */
        select_group();
      }
    }
    write("You have selected the group: [" + selected_number + "] " +
      Global_Name + "\n");
    write("\nEnter subject of your message:\n" + PROMPT);
    input_to("get_subject");
    return 1;
  }
    else
  {
    write("You failed to enter a valid value.\n");
    select_group();
  }
  return 1;
}


