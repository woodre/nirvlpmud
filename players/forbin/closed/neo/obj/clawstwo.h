static int done1n, dtwo1n;
static string hit1;
static string part1;

clawstwo()
{
  int damageone;

  random_part1n();
  random_hit1n();

  if(!ATT) return;

  TOM "<"+HIR+"claw"+NORM+"> You "+hit1+" "+ATT->QN+" in the "+part1+".\n");
	
  tell_object(ATT,
    "<"+HIR+"claw"+NORM+"> "+BOLD+CAP((string)GOB->query_symbiote())+NORM+" "+hit1+" you in the "+part1+".\n");
  damageone = done1n + dtwo1n;
  return damageone;
}      
  
random_hit1n()
{
  switch(random(10) + 1)
  {
    case 8..10:
      hit1 = "ripped";
      dtwo1n = 5;
      break;
    case 5..7:
      hit1 = "slashed";
      dtwo1n = 4;
      break;
    case 1..4:
      hit1 = "grazed";
      dtwo1n = 3;
      break;
    default:
      hit1 = "miss";
      dtwo1n = 0;
      break;          
  }
}

random_part1n()
{
  switch(random(20) + 1)
  {
    case 19..20:
      part1 = "face";
      done1n = 5;
      break;
    case 15..18:
      part1 = "chest";
      done1n = 4;
      break;
    case 13..14:
      part1 = "arm";
      done1n = 3;
      break;
    case 8..12:
      part1 = "leg";
      done1n = 2;
      break;
    case 1..7:
      part1 = "hand";
      done1n = 1;
      break;
    default:
      part1 = "hand";
      done1n = 0;
      break;
  }
} 
