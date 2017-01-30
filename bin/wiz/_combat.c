/* 07/13/07 Earwax: very basic, just to get an idea of combat stats */

inherit "/players/earwax/lib/waxfuns.c";

string put_decimal(int arg)
{
  string num;

  if (!arg) return "0.00";
  num = arg + "";

#ifndef __LDMUD__ /* Rumplemintz */
  return num[0..-3]+"."+num[-2..-1];
#else
  return num[0..<3] + "." + num[<2..<1];
#endif
}

int cmd_combat(string arg)
{
  mapping info;
  string *names;
  int dealt, taken, hbs, rating;
  int i;
  string str_rating;

  info = (mapping)"/daemons/combat"->query_info();

  if (!info) {
    write("No information to report at this time.\n");
    return 1;
  }

  names = m_indices(info);
  write(" Player           Dealt     Dealt     Rating     Dealt/Taken/HBs in combat.\n");
  write("  Name            -----     -----     \n");
  write("                   HBs      Taken     \n\n");

  i = sizeof(names);
  while(i--) {
    dealt = info[names[i]][0];
    taken = info[names[i]][1];
    hbs = info[names[i]][2];
    if (!hbs) continue;
    if (!taken) continue;
    rating = ((dealt * 100) / hbs) * ((dealt * 100) / taken);
    str_rating = rating+"";
#ifndef __LDMUD__ /* Rumplemintz */
    str_rating = str_rating[0..-5]+"."+str_rating[-4..-3];
#else
    str_rating = str_rating[0..<5] + "." + str_rating[<4..<3];
#endif
    write(pad(capitalize(names[i]), 13)
      + ralign(put_decimal(((dealt*100)/hbs)), 10)
      + ralign(put_decimal(((dealt*100)/taken)), 10)
/*
      + ralign(put_decimal((((dealt*dealt)*100)/(hbs*taken))), 10)
      + ralign(put_decimal((((dealt-taken)*100)/hbs)), 10)
*/
      + ralign(str_rating, 11)
      + "     " + dealt+":"+taken+":"+hbs+"\n");
  }

  return 1;
}

#ifdef 0
int cmd_combat(string arg)
{
  "/daemons/combat"->dump_info();
  return 1;
}
#endif
