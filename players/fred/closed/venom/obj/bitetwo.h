static int done2n, dtwo2n;
static string part2n;

bitetwo()
{
  int damageone;

  random_part2n();

  if(!ATT) return;

  TOM "<"+HIR+"bite"+NORM+"> A tentacle lashes out from "+BOLD+CAP((string)GOB->query_symbiote())+NORM+". Flesh is devoured.\n");
 
  tell_object(ATT,
    "<"+HIR+"bite"+NORM+"> A tentacle lashes out at you from "+BOLD+CAP((string)GOB->query_symbiote())+NORM+". Flesh is devoured.\n");

  dtwo2n = 5;
 
  damageone = done2n + dtwo2n;
  USER->add_hit_point(random(2)+1);   
  return damageone;
}

  
random_part2n()
{
  switch(random(20) + 1)
  {
    case 19..20:
      part2n = "face";
      done2n = 5;
      break;
    case 16..18:
      part2n = "chest";
      done2n = 4;
      break;
    case 11..15:
      part2n = "arm";
      done2n = 3;
      break;
    case 6..10:
      part2n = "leg";
      done2n = 2;
      break;
    case 1..5:
      part2n = "hand";
      done2n = 1;
      break;
    default:
      part2n = "hand";
      done2n = 1;
      break;
  }
}
