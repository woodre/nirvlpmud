/*
        l_color(str)

        Turn guild color either on or off.
*/
l_color(str) {
if(!str && str != "on" && str != "off") {
        write("Usage l_color <on/off>\n");
        return 1;
}
if(str == "on" && query_color() == "on") {
        write(RED+"Legion color"+END+" is already on.\n");
        return 1;
}
if(str == "off" && query_color() == "off") {
        write("Legion color is already off.\n");
        return 1;
}
else {
        if(query_color() == "off") {
                set_color(str);
                write("Setting "+RED+"Legion color"+END+" to "+str+".\n");
                return 1;
        }
        else {
                set_color(str);
                write("Setting Legion color to "+str+".\n");
                return 1;
        }
}
return 0;
}

