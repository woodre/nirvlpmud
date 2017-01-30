/*
 *  A ranged emote for the Storm Bards of Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


bard_image(str)  {

string target, mess;

  if(!str || sscanf(str, "%s %s", target, mess) !=2)  {
    write("Who do you want to send a bard image to?\n");
    write("Syntax: btell < player > < message >\n");
    return 1;
        }

  if(!find_player(lower_case(target)))  {
    write("That player is not within the realm of magic.\n");
    return 1;
        }

  if(in_editor(TARGET))  {
    write("That wizard is editing and should not be distrubed.\n");
    return 1;

        }

if(COLOR)  {

  tell_object(TARGET,
    "Your ears fill with a light "+HIM+"etheral music"+
     NORM+" which somehow suggests that\n"+tp+" "+mess+"\n");
     
  write("You sing your "+HIM+"etheral song"+NORM+" to "+
        target+", who gets the image of\n"+tp+" "+mess+"\n");

        }  else  {

  tell_object(TARGET,
    "Your ears fill with a light etheral music which somehow suggests that\n"+
    tp+" "+mess+"\n");
  write("You sing your etheral song to "+target+", who gets the etheral image of\n"+
    tp+" "+mess+"\n");

        }

  call_other(TP, "ad_spell_point", -1);
  return 1;

        }
