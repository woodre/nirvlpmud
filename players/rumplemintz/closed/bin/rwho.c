#include <ansi.h>

object *
sort_by_level(object *who) {
  int i, j, sorted;
  object tmp;
  
  j = sizeof(who);
  sorted = 0;
  while (!sorted) {
    sorted = 1;
    j --;
    for (i = 0; i < j; i ++)
      if (who[i]->query_level() < who[i+1]->query_level()) {
        tmp = who[i];
        who[i] = who[i+1];
        who[i+1] = tmp;
        sorted = 0;
      }
  }
  return who;
}

string
add_zero(mixed str) {
  str = "" + str;
  if (strlen(str) == 1)
    str = "0" + str;
  return str;
}

int
rwho() {
  int lev, xlev, invis;
  object *ppl;
  int x, count1, count2;
  string shrt, levstring;

  ppl = sort_by_level(users());
  
  write("\n");
  write(BLU+
"<-------------------------------------------------------------------------->"+
NORM+"\n");
  write(HIW);
  write("\t\t\t  n  i  r  v  a  n  a\n");
  write(NORM);
  write("\t\t  ...since 1991: still the original.\n");
  write(BLU+
"<-------------------------------------------------------------------------->"+
NORM+"\n");
  for (x = 0; x <sizeof(ppl); x++) {
    lev = (int)ppl[x]->query_level();
    invis = (int)ppl[x]->query_invis();
    shrt = (string)ppl[x]->short();
    xlev = (int)ppl[x]->query_extra_level();
    if (invis > this_player()->query_level())
      continue;
    if (!shrt)
      shrt = "("+ppl[x]->query_real_name()+")";
    if (lev > 19) {
      switch (lev) {
      case 100000:
        levstring = BLU+"[     "+HIW+BLINK+"GOD"+NORM+BLU+" ]"+NORM;
        break;
      case 10000:
        levstring = BLU+"[    "+HIW+"DEMI"+NORM+BLU+" ]"+NORM;
        break;
      case 5000..5001:
        levstring = BLU+"[    "+HIY+"ARCH"+NORM+BLU+" ]"+NORM;
        break;
      case 1000:
        levstring = BLU+"[   "+HIG+"ELDER"+NORM+BLU+" ]"+NORM;
        break;
      case 101..999:
        levstring = BLU+"[ "+CYN+"RETIRED"+NORM+BLU+" ]"+NORM;
        break;
      case 100:
        levstring = BLU+"[  "+HIC+"SENIOR"+NORM+BLU+" ]"+NORM;
        break;
      case 41..99:
        levstring = BLU+"[  "+HIM+"MENTOR"+NORM+BLU+" ]"+NORM;
        break;
      case 31..40:
        levstring = BLU+"[  "+CYN+"WIZARD"+NORM+BLU+" ]"+NORM;
        break;
      case 21..30:
        levstring = BLU+"[  "+MAG+"NEWWIZ"+NORM+BLU+" ]"+NORM;
        break;
      case 20:
        levstring = BLU+"[  "+WHT+"APPWIZ"+NORM+BLU+" ]"+NORM;
        break;
      }
      write(levstring);
      write(shrt);
      write("\n");
      count2++;
    } else {
      if (xlev = (int)ppl[x]->query_extra_level())
        levstring = BLU+" {"+NORM+" "+lev+"+"+pad(add_zero(xlev),3);
      else
        levstring = BLU+" {"+NORM+"   "+pad(""+lev,2)+"  ";
      levstring += BLU+"}"+NORM+" ";
      write(levstring);
      write(shrt);
      write("\n");
      count1++;
    }
  }
  write(BLU+
"<-------------------------------------------------------------------------->"+
NORM+"\n");
  write("    "+count2+" wizard"+(count2 == 1 ? "" : "s")+" online");
  write("    "+count1+" player"+(count1 == 1 ? "" : "s" )+" online\n");
  return 1;
}
