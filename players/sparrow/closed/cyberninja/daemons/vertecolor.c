#define esc ""

string
replace_ansi(string word)
{
    string z;

    if(!word) return word;
    switch(word)
    {
      case "-":  z = esc + "[0m"; break;
      case "H":  z = esc + "[1m"; break;
      case "K":  z = esc + "[30m"; break;
      case "R":  z = esc + "[31m"; break;
      case "G":  z = esc + "[32m"; break;
      case "Y":  z = esc + "[33m"; break;
      case "B":  z = esc + "[34m"; break;
      case "M":  z = esc + "[35m"; break;
      case "C":  z = esc + "[36m"; break;
      case "W":  z = esc + "[37m"; break;
      case "N":  z = esc + "[2;37;0m"; break;
      case "HK": z = esc + "[1;30m"; break;
      case "HR": z = esc + "[1;31m"; break;
      case "HG": z = esc + "[1;32m"; break;
      case "HY": z = esc + "[1;33m"; break;
      case "HB": z = esc + "[1;34m"; break;
      case "HM": z = esc + "[1;35m"; break;
      case "HC": z = esc + "[1;36m"; break;
      case "HW": z = esc + "[1;37m"; break;
    }
    
    if(!z) return word;
    return z;
}

string
filter_msg(string str)
{
    int s; 
    string *words;

    if(!str) return str;
    s = sizeof(words = explode(str, "$"));

    while(s--)
      if(replace_ansi(words[s]))
        words[s] = replace_ansi(words[s]);

    str = (implode(words, "")) + esc + "[0m";
    return str;
}
