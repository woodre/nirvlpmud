/*  Line control object.  This object will keep track of any number
 *  of channels dynamically.  Important external functions to call are
 *  listener(), broadcast(), get_list_all() and get_list_listener().
 */

#pragma strict_types

#include "/players/llew/closed/lsong/line.h"

  /***********
   * Globals *
   ***********/

/* Mapping of list of channels and people on channels.
 *  (mapping)lines[(mapping)channels[(string)name: (int)muffled]]
 */
mapping lines;

/* Temporary string array to hold list of names to return. */
string *list;

  /*************************
   * Function Declarations *
   *************************/

void reset(int arg);
status listener(string chan, string name, int arg);
void broadcast(string chan, string mess);
string *get_list_all(string chan);
string *get_list_listeners(string chan);
mapping clean_line(mapping map);
void clean_all_lines();

  /************************
   * Function Definitions *
   ************************/

void reset(int arg)
{
   if (arg)
   {
      /* Clean up all the lines. */
      clean_all_lines();
      return;
   }

   /* Create empty mapping of channels on creation. */
   lines = ([]);
}

/* Function: listener
 * In:       string chan     The name of the channel to affect.
 *           string name     The player to apply argument to.
 *           int arg         What to affect about the player.
 *                           (ADD_MEMBER, SUB_MEMBER, TOGGLE_LINE, TURN_ON, TURN_OFF)
 * Return:   True if action completed, false if there was a problem.
 * Desc:     This function will create channels, add people to channels,
 *           remove them, and toggle listening to a channel.
 */
status listener(string chan, string name, int arg)
{
   /* Check if we got a channel and a name to affect. */
   if (!chan || !name) return 0;

   /* If the channel does not exist, create a new one that is empty. */
   if (!lines[chan]) lines[chan] = ([]);

   /*  Apply the desired action to the line/player. */
   switch(arg)
   {
      case ADD_MEMBER:
         if (!lines[chan][name])
            lines[chan] += ([ name: 1 ]);
         break;
      case SUB_MEMBER:
         lines[chan] = m_delete(lines[chan], name);
         break;
      case TOGGLE_LINE:
         if (!lines[chan][name]) return 0;
         lines[chan][name] = !lines[chan][name];
         break;
      case TURN_ON:
         if (!lines[chan][name]) return 0;
         lines[chan][name] = 1;
         break;
      case TURN_OFF:
         if (!lines[chan][name]) return 0;
         lines[chan][name] = 0;
         break;
      default:
         return 0;
   }

   /* Apply general clean up in case of a bad name, and return success. */
   lines[chan] = clean_line(lines[chan]);
   return 1;
}

 /* Function: broadcast
  * In:       string chan     The channel to send a message to.
  *           string mess     The text to send to the channel.
  * Desc:     Sends a message to all those that are on the channel
  *           and have the channel unmuffled.
  */
void broadcast(string chan, string mess)
{
   /* Make sure the line exists before we go sending it a message. */
   if (lines[chan])
   {
      int x;
      string *index;
      int msize;

      /* Clean line of any bad names. */
      lines[chan] = clean_line(lines[chan]);

      /* Create a temporary array of the names to send message to. */
      index = m_indices(lines[chan]);

      /* Loop the names and send the message if they have the line unmuffled. */
      for (x = 0, msize = sizeof(index); x < msize; x++)
      {
         if (lines[chan][index[x]] == 1)
            tell_object(find_player(index[x]), mess);
      }
   }
}

 /* Function: get_list_all
  * Return:   String array of everyone on the channel.
  * Desc:     To get a list of real names of the people on a channel.
  */
string *get_list_all(string chan)
{
   /* Return an empty array if the channel doesn't exist. */
   if (!lines[chan]) return list = ({});

   /* Clean the list up before sending it back. */
   lines[chan] = clean_line(lines[chan]);

   /* Create a temporary array of the names to send message to. */
   /* Create an array of the names on the list and return it. */
   list = m_indices(lines[chan]);
   return list;
}

 /* Function: get_list_listeners
  * Return:   String array of unmuffled people on the channel.
  * Desc:     To get a list of real names of those listening.
  */
string *get_list_listeners(string chan)
{
   int x;
   int msize;
   string *index;

   /* Create a blank list of listeners. */
   list = ({});

   /* Return blank list if channel doesn't exist. */
   if (!lines[chan]) return list;

   /* Clean up the line before checking names. */
   lines[chan] = clean_line(lines[chan]);

   /* Get array of keys (names) in the line mapping. */
   index = m_indices(lines[chan]);

   /* Loop through the names and add to list if unmuffled. */
   if (lines[chan])
      for (x = 0, msize = sizeof(index); x < msize; x++)
         if (lines[chan][index[x]] == 1)
            list += ({ index[x] });

   /* Return the list of listeners. */
   return list;
}

 /* Function: clean_line
  * In:       mapping map   A channel to check if the names are all valid.
  * Return:   A mapping of the valid list of names.
  * Desc:     Cleans out names in list that are invalid, logged off, etc...
  */
mapping clean_line(mapping map)
{
   int x;
   int size;
   string *index;
   string *bad;

   /* Get array of keys (names) in the mapping. */
   index = m_indices(map);
   /* Create emtpy array of bad indices to remove later. */
   bad = ({});

   /* Loop keys to check for vailidity.  Add to bad list if not. */
   for (x = 0, size = sizeof(index); x < size; x++)
   {
      if (!find_player(index[x])) bad += ({ index[x] });
   }

   /* Go through the list of bad keys and remove them from the mapping. */
   for (x = 0, size = sizeof(bad); x < size; x++)
      map = m_delete(map,bad[x]);

   /* Return a shiny clean list of valid names. */
   return map;
}

 /* Function: clean_all_lines
  * Desc:     Clean out all channels of bad names, and any channels
  *           that no longer have any names in them.
  */
void clean_all_lines()
{
   int x;
   int size;
   string *index;
   string *bad;
   string *tempstr;

   /* Get array of keys (channels) in main mapping. */
   index = m_indices(lines);
   /* Create empty array of bad channels to remove later. */
   bad = ({});

   /* Loop all the channels. */
   for (x = 0, size = sizeof(index); x < size; x++)
   {
      /* Clean up the line before we check if it is empty. */
      lines[index[x]] = clean_line(lines[index[x]]);

      /* Put the cleaned up line's keys (names) in a temp array to
       * check the size.  This must be done because m_sizeof() does
       * not work.
       */
      tempstr = m_indices(lines[index[x]]);
      if (sizeof(tempstr) == 0)
         bad += ({ lines[index[x]] });
   }

   /* Clear all bad channels from the mapping. */
   for (x = 0, size = sizeof(bad); x < size; x++)
      lines = m_delete(lines, bad[x]);
}
