/* ignore this, testing
#define User find_player("heh")
#define PO previous_object()
*/
#include "/players/boltar/things/esc.h"

int
endurance_monitor()
{
    int j, k;

    if((int)PO->query_max_endurance() == 0)
      return 0;

    j = (int)PO->query_endurance();
    j *= 100;
    k = (int)PO->query_max_endurance();
    j /= k;


    if(j > 100)
      j = 100;

    return j;
}

string
m_decode(string str)
{
   int s; 
   string *words, word;

   words = explode(str, "#");
   s = sizeof(words);

   while(s--)
   {
     if((word = (string)User->replace_read(words[s])) && word != "end")
       words[s] = word;
     else if(words[s] == "end") /* if endurance token */
       words[s] = "" + endurance_monitor();
   }

   str = (implode(words, ""));

   words = explode(str, "$");
   s = sizeof(words);

   while(s--)
     if((word = (string)User->replace_ansi(words[s])))
       words[s] = word;

   str = (implode(words, "")) + esc + "[0m";
   return str;
}
