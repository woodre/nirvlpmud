
slamtwo()
{
  int damageone;
  
  if(!ATT) return;

  if(random(100) < 60)
  {
    TOM "<"+HIR+"slam"+NORM+"> You grab "+ATT->QN+" and toss "+ATT->OBJ+" into the air!\n"+
        "       "+ATT->QN+" screams as "+ATT->PRO+" crashes into the ground.\n");

    tell_object(ATT,
      "<"+HIR+"slam"+NORM+"> "+BOLD+CAP((string)GOB->query_symbiote())+NORM+" grab's you and tosses you through the air.\n"+
      "You scream as you collide with the ground!\n");
    damageone = 10;
  }
  else
  {
    TOM "<"+HIR+"slam"+NORM+"> You grab "+ATT->QN+" by the leg.\n"+
        "       "+ATT->QN+" blurs as "+ATT->PRO+" is spun around and around.\n"+
        "       "+ATT->QN+" flies wildly into the air landing with a loud thud.\n");

    tell_object(ATT,
      BOLD+CAP((string)GOB->query_symbiote())+NORM+" grab's you by the leg.\n"+
      "You see a blur as your are spun around and around.\n"+
      "You fly through the air landing with a solid THUD!\n");
    damageone = 15;
  }
  return damageone;
}
