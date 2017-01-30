/******************************************************************************
 *  File:           news_reader.c
 *  Function:       
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2003 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         15/1/04
 *  Notes:          
 *  Change History: 02/09/05 - switched to inheritable for formatter.
 *****************************************************************************/

string Global_Wiz_Description, Global_Long_Description;

string
short()
{
  return "Newspaper";
}

/* There are long descriptions, and then there are my long          */
/* descriptions, like this one that will show the commands to come  */
/* for coders when they look at the news. I'm debating whether or   */
/* not to put a short description in for this.                      */
void
long()
{
  Global_Long_Description =
"  This is a large, informative newspaper that was printed on the \n\
Xerox, DocuColor iGen3. Digital Production Press Printer in the \n\
Nirvana Newsroom. It has been printed just for you to provide the \n\
world with information from every corner of the world. There are \n\
words printed all over and you have the option to 'read' the news \n\
if you desire.\n";
  Global_Wiz_Description = 
"\n\
  As a ranking purveyor of code on Nirvana, you have some extra \n\
options available to you. The following additional options have \n\
not yet been added into the newsreader, but are planned:\n\
\tNewsgroup Creation \& Management\n\
\t\tLocking, Editing, Tracking\n\
\tSubgroup Creation \& Management\n\
\tPrevious News Post Editing\n\
\tColor Input Support\n\
\tModerators\n\
\t\tCreator \& Delegated Moderation Including Players\n\n\
More features upon request and completion of existing feature set.\n";
  if (environment(this_object())->query_level() < 20)
      tell_object(environment(this_object()), Global_Long_Description);
  if (environment(this_object())->query_level() > 20)
      tell_object(environment(this_object()), Global_Long_Description + Global_Wiz_Description);
}

/* Plans for the future are to have this mention that the owner is busy */
/* reading the news if looked at while engaged in the reading process.  */
/* Also, I want this to display a message that the owner has unread     */
/* posts or not.                                                        */
void
extra_look()
{
  if (this_player() == environment())
    tell_object(environment(this_object()), "You can read the news.\n");
  else write(environment(this_object())->query_name()+" can read the news.\n");
}
