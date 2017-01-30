#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

status
QRangerInfo() { return 1; }

status 
RangerInfo(string str)
{
  if(str) { return 1; }

  write(""+
  "-------------------   Ansi   --------------------\n"+
  "Allows you to change the ansi color of your title\n"+
  "Availible colors:\n\n"+
  WHITE+"White"+OFF+"\n"+
  REVERSE+BOLD+BLACK+"Black"+OFF+"\n"+
  BOLD+BLACK+"Grey"+OFF+"\n"+
  RED+"Red"+OFF+"\n"+
  BOLD+RED+"Bold Red"+OFF+"\n"+
  GREEN+"Green"+OFF+"\n"+
  BOLD+GREEN+"Bold Green"+OFF+"\n"+
  BLUE+"Blue"+OFF+"\n"+
  BOLD+BLUE+"Bold Blue"+OFF+"\n"+
  BROWN+"Brown"+OFF+"\n"+
  YELLOW+"Yellow"+OFF+"\n"+
  CYAN+"Cyan"+OFF+"\n"+
  BOLD+CYAN+"Bold Cyan"+OFF+"\n"+
  MAGENTA+"Purple"+OFF+"\n"+
  BOLD+MAGENTA+"Bold Purple"+OFF+"\n\n"+

  "To change use the command 'ansi <color>'\n\n");
  return 1;
}


status
RangerPower(string str)
{
  string msg;
  if(!str)
  {
    previous_object()->SRangerAnsi(OFF);
    write("Ansi set to " + previous_object()->QRangerAnsi() + str + NORM +"\n");
    return 1;
  }
  switch(str)
  {
    case "Green":
    case "green": previous_object()->SRangerAnsi(GREEN); break;
    case "Bold Green":
    case "bold green": previous_object()->SRangerAnsi(BOLD+GREEN); break;
    case "Blue":
    case "blue": previous_object()->SRangerAnsi(BLUE); break;
    case "Bold Blue":
    case "bold blue": previous_object()->SRangerAnsi(BOLD+BLUE); break;
    case "Red":
    case "red": previous_object()->SRangerAnsi(RED); break;
    case "Bold Red":
    case "bold red": previous_object()->SRangerAnsi(BOLD+RED); break;
    case "White":
    case "white": previous_object()->SRangerAnsi(BOLD); break;
    case "Black":
    case "black": previous_object()->SRangerAnsi(REVERSE+BOLD+BLACK); break;
    case "Grey":
    case "grey": previous_object()->SRangerAnsi(BOLD+BLACK); break;
    case "Purple":
    case "purple": previous_object()->SRangerAnsi(MAGENTA); break;
    case "Yellow":
    case "yellow": previous_object()->SRangerAnsi(YELLOW); break;
    case "Brown":
    case "brown": previous_object()->SRangerAnsi(BROWN); break;
    case "Cyan":
    case "cyan": previous_object()->SRangerAnsi(CYAN); break;
    case "Bold Cyan":
    case "bold cyan": previous_object()->SRangerAnsi(BOLD+CYAN); break;
    case "Bold Purple":
    case "bold purple": previous_object()->SRangerAnsi(BOLD+MAGENTA); break;
    default: write("That is not a valid color.\n");
  }
  write("Ansi set to " + previous_object()->QRangerAnsi() + str + NORM + "\n");
  return 1;
}


