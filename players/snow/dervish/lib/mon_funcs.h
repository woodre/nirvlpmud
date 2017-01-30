string
m_decode(string str)
{
   int s; 
   string *words, word;

   words = explode(str, "#");
   s = sizeof(words);

   while(s--)
   {
     if((word = (string)ENV(TO)->replace_read(words[s])) && word != "sd")
       words[s] = word;
     else if(words[s] == "sd") /* if spell delay */
       words[s] = "" + (int)TO->query_spell_delay();
   }

   str = (implode(words, ""));

   words = explode(str, "$");
   s = sizeof(words);

   while(s--)
     if((word = (string)ENV(TO)->replace_ansi(words[s])))
       words[s] = word;

   str = (implode(words, "")) + esc + "[0m";
   return str;
}
