#include "/players/vital/closed/headers/vital.h"

string color, type;

random_exit() {
    string verb;
    choose_color(x);
    choose_items(y);
    verb = query_verb();
    TP->move_player(verb+"#/players/vital/color/room/"+color+type+".c");
    return 1;
}

choose_color(int x) {
    switch(random(200)) {
        case        0: color = "platinum"; break;/*   0.5% chance  */
        case     1..3: color = "gold";     break;/*   1.5% chance  */
        case     4..8: color = "black";    break;/*   2.5% chance  */
        case    9..15: color = "green";    break;/*   3.5% chance  */
        case   16..24: color = "white";    break;/*   4.5% chance  */
        case   25..59: color = "blue";     break;/*  17.5% chance  */
        case   60..94: color = "red";      break;/*  17.5% chance  */
        case  95..129: color = "yellow";   break;/*  17.5% chance  */
        case 130..164: color = "purple";   break;/*  17.5% chance  */
        case 165..199: color = "silver";   break;/*  17.5% chance  */
    }
    return color;
}

choose_items(int x) {
    switch(random(100)) {
        case   0..1: type = "01"; break;/*  2% chance */
        case   2..3: type = "02"; break;/*  2% chance */
        case   4..8: type = "03"; break;/*  5% chance */
        case  9..22: type = "04"; break;/* 14% chance */
        case 23..36: type = "05"; break;/* 14% chance */
        case 37..50: type = "06"; break;/* 14% chance */
        case 51..66: type = "07"; break;/* 15% chance */
        case 67..81: type = "08"; break;/* 16% chance */
        case 82..99: type = "09"; break;/* 18% chance */
    }
    return type;
}
