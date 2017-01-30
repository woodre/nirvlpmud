/*
 * Written by Verte 4-28-01
 * to allow for Colourization Decoding
 */

#include "/players/boltar/things/esc.h"

string
c_decode(string str)
{
   int s; 
   string *words, word, heh;


   words = explode(str, "$");
   s = sizeof(words);

   while(s--)
     if(heh = (string)this_player()->replace_ansi(words[s]))
       words[s] = heh;

   str = (implode(words, "")) + esc + "[0m";
   return str;
}
