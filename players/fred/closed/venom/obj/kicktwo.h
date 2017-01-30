static int done3n, dtwo3n;
static string hit3;
static string part3;

kicktwo()
{
  int damageone;

  random_part32n();
  random_hit32n();

  if(!ATT) return;  

  TOM "<"+HIR+"kick"+NORM+"> You "+hit3+" "+ATT->QN+" in the "+part3+".\n");
	
  tell_object(ATT,
    "<"+HIR+"kick"+NORM+"> "+BOLD+CAP((string)GOB->query_symbiote())+NORM+" "+hit3+"'s you in the "+part3+".\n");

  damageone = done3n + dtwo3n;
  return damageone;
}      
  
random_hit32n()
{
  switch(random(5) + 1)
  {
    case 4..5:
      hit3 = "slam"; 
      dtwo3n = 4;
      break;
    case 1..3:
      hit3 = "kick";
      dtwo3n = 3;
      break;
    default:
      hit3 = "kick";
      dtwo3n = 2;
     break;          
  }
}

random_part32n()
{
  switch(random(20) + 1) 
  {
    case 19..20:
      part3 = "face";
      done3n = 5;
      break;
    case 17..18:
      part3 = "chest";
      done3n = 4;
      break;
    case 11..16:
      part3 = "arm";
      done3n = 3;
      break;
    case 6..10:
      part3 = "leg";
      done3n = 2;
      break;
    case 1..5:
      part3 = "hand";
      done3n = 1;
      break;
    default:
      part3 = "hand";
      done3n = 0;
      break;
  } 
} 
