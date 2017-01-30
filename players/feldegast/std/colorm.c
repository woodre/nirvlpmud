string rand_color()
{
  switch(random(12))
  {
    case 0: return HIB; break;
    case 1: return HIR; break;
    case 2: return HIY; break;
    case 3: return HIM; break;
    case 4: return HIG; break;
    case 5: return HIC; break;
    case 6: return BLU; break;
    case 7: return RED; break;
    case 8: return YEL; break;
    case 9: return MAG; break;
    case 10: return GRN; break;
    case 11: return CYN; break;
  }
}

string multi_color(string str)
{
  string new;
  string *part;
  int i, length;
  int p;

  p = 0;
  part = allocate(2 * strlen(str));

  length = strlen(str);
  for(i = 0; i < length; i++)
  {
    part[i*2] = str[i];
    part[i*2+1] = rand_color();
  }
  new = implode(part, "");
  return new;
}
