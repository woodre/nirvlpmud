#include "../DEFS.h"
#include DEFS_ENHANCEMENTS


void usage()
{
  string msg, fluxColor, fluxName, myFluxType, myFluxColor, myFluxName;
  string *fluxList;
  int i;

  fluxList = (string*)call_other(ENHANCEMENTD, "getFluxInfoList", "type");
  msg = "Usage: flux_set <type>\n"+
        "<type> - is the type of blast rays emitted, from one of the following:\n"+LINE;
  for (i=0; i < sizeof(fluxList); i++)
  {
    fluxColor = (string)call_other(ENHANCEMENTD, "getFluxInfo", "color", fluxList[i]);
    fluxName  = (string)call_other(ENHANCEMENTD, "getFluxInfo", "name", fluxList[i]);
    msg += "   "+fluxColor+fluxName+OFF+"\n";
  }
  msg += "   Random (emits a ray of random type)\n";
  msg+=LINE;

  myFluxType  = (string)IPTP->query_flux_type();
  if (myFluxType)
  {
    myFluxName  = (string)call_other(ENHANCEMENTD, "getFluxInfo", "name", myFluxType);
    myFluxColor = (string)call_other(ENHANCEMENTD, "getFluxInfo", "color", myFluxType);
  }
  else
  {
    myFluxName = "Random";
    myFluxColor = "";
  }

  msg += "Your flux generator currently emits "+
        myFluxColor+myFluxName+OFF+" rays.\n";

  write(msg);
}


status main(string str)
{
  status hasFlux;
  string inputFlux, fluxNameIter, fluxName, fluxType, fluxColor;
  string *fluxList;
  int i;

  hasFlux = (status)IPTP->item_electricflux() ||
            (status)IPTP->item_heatflux()     ||
            (status)IPTP->item_magneticflux();

  if (!hasFlux && !IPTP->guild_wiz())
    return 0;

  fluxList = (string*)call_other(ENHANCEMENTD, "getFluxInfoList", "name");

  if (!str)
  {
    usage();
    return 1;
  }

  inputFlux = str;

  fluxList = (string*)call_other(ENHANCEMENTD, "getFluxInfoList", "type");
  for (i=0; i < sizeof(fluxList); i++)
  {
    fluxNameIter = (string)call_other(ENHANCEMENTD, "getFluxInfo", "name", fluxList[i]);
    if (lower_case(inputFlux) == lower_case(fluxNameIter))
    {
      fluxName = fluxNameIter;
      fluxType = fluxList[i];
    }
  }

  if (!fluxType && lower_case(inputFlux) != "random")
  {
    write("No such flux type.\n");
    usage();
    return 1;
  }
  else if (lower_case(inputFlux) == "random")
  {
    IPTP->set_flux_type(0);
    fluxName = "Random";
    fluxColor = OFF;
  }
  else
  {
    IPTP->set_flux_type(fluxType);
    fluxColor = (string)call_other(ENHANCEMENTD, "getFluxInfo", "color", fluxType);
  }
  IPTP->save_me();

  write("You set your flux generator to emit "+
        fluxColor+fluxName+OFF+" rays.\n");
  return 1;
}
