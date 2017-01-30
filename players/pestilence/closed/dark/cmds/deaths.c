#include "/players/vertebraker/ansi.h"

#define DEATHLOG "/log/DEATHS"

status
main()
{
    int i, s, f, h, year, exp;
    string text, *Deaths, Death, time, corpse, killer, flag,
     sxp, gold;

    write("\tYou commune with the dark gods...\n");
    f = file_size(DEATHLOG);

    if(!f)
    {
      notify_fail("No deaths to report.\n");
      return 0;
    }
 
    if(f > 1000) h = 1000;
    else h = f;
    
    text = read_bytes(DEATHLOG, (f - h), h);

    Deaths = explode(text, "\n");
    s = sizeof(Deaths);

    write("[" + RED + "\
----------------------------------------------------------" +
    NORM + "]\n");
    for(i = 0; i < s; i ++)
    {
      Death = Deaths[i];
      if(Death[0..6] == "Spar-> ")
      {
        flag = HIB + "S" + NORM;
        Death = Death[7..strlen(Death)-1];
      }
      else
        flag = BOLD + "D" + NORM;
      if(sscanf(Death, "%s 200%d %s %d exp %s gold killed by %s.",
        time, year, corpse, exp, gold, killer) == 6 &&
        corpse != "guest" && (exp > 5885))
      {
        time = time[4..15];
        corpse = pad(capitalize(corpse), 15);
        sxp = pad("" + exp + "xp", 12);
        gold = pad(gold + "gp", 10);
        
        write("\
[" + flag + "] " + time + "\n\t" +
corpse + sxp + gold + capitalize(killer) + ".\n");
      }
    }
    write("[" + RED + "\
----------------------------------------------------------" +
    NORM + "]\n");
    return 1;
}
