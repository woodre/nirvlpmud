#include <ansi.h>

status cmd_btitle(string str)
{
  int gen;
  string title;
  if(str) return 0;
  
    if((string)this_player()->query_gender() == "male") {
      gen =0;
    }
    else {
      gen = 1;
    }
  switch((int)this_player()->query_guild_rank())
  {
    case 1:
      title="the Oblate";
      break;
    case 2:
      title="the Postulant";
      break;
    case 3:
      title="the Adept of Shadows";
      break;
    case 4:
      if(gen == 0) {
        title="the Brother of Darkness";
      }
      else {
        title="the Sister of Darkness";
      }
      break;
    case 5:
      title="the "+HIK+"Monk"+NORM;
      break;
    case 6:
      title="the "+HIC+"H"+HIK+"eirodeacon"+NORM;
      break;
    case 7:
      title="the "+HIM+"H"+HIK+"eiromonk"+NORM;
      break;
    case 8:
      if(gen == 0) {
        title="the "+HIK+"Subprior"+NORM;
      }
      else {
        title="the "+HIK+"Subprioress"+NORM;
      }
      break;
    case 9:
      if(gen == 0) {
        title="the "+HIK+"Prior"+NORM;
      }
      else {
        title="the "+HIK+"Prioress"+NORM;
      }
      break;
    case 10:
      if(gen == 0) {
        title="the "+HIK+"Abbot"+NORM;
      }
      else {
        title="the "+HIK+"Abbess"+NORM;
      }
      break;
    case 11:
      if(gen == 0) {
        title="the "+HIC+"H"+HIK+"egumen"+NORM;
      }
      else {
        title="the "+HIC+"I"+HIK+"humenia"+NORM;
      }
      break;
    case 12:
      if(gen == 0) {
        title="the "+HIM+"A"+HIK+"rchimandrite"+NORM;
      }
      else {
        title="the "+HIM+"A"+HIK+"rchimandrate"+NORM;
      }
      break;
    case 13:
      if(gen == 0) {
        title="the "+HIK+"M"+HIC+"aster"+NORM+" of the "+HIK+"D"+HIC+"ark "+HIK+"H"+HIC+"and"+NORM;
      }
      else {
        title="the "+HIK+"M"+HIC+"istress"+NORM+" of the "+HIK+"D"+HIC+"ark "+HIK+"H"+HIC+"and"+NORM;
      }
      break;
    case 14:
      title="the "+MAG+"Whisper"+NORM+" of a "+HIK+"Night's Breeze"+NORM;
      break;
    case 15:
      title="the "+HIW+"S"+HIK+"hadowdancer"+NORM;
      break;
    case 16:
      title="the "+HIW+"B"+HIK+"ishop"+NORM;
      break;
    case 17:
      title="the "+HIW+"M"+HIK+"aster "+HIW+"N"+HIK+"ightweaver"+NORM;
      break;
    case 18:
      title="the "+HIR+"D"+HIK+"reamstalker"+NORM;
      break;
    case 19:
      title="the "+HIW+"D"+HIK+"ark "+HIW+"H"+HIK+"and "+NORM+"of the "+HIC+"N"+HIK+"ightlord"+NORM;
      break;
    case 20:
      title="the "+HIW+"O"+HIK+"ne "+HIC+"["+HIW+"U"+HIK+"nholy "+HIW+"P"+HIK+"erfection"+HIC+"]"+NORM;
      break;
    default:
      title="the Stooge";
      break;
  }
  this_player()->set_title(title);
  write("The darkness shrouds you.\n");
  write("Your new title is: "+title+"\n");

  say("The darkness shrouds around "+(string)this_player()->query_name()+".\n");
  return 1;
}
