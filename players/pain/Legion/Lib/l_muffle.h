/*
        l_muffle(str)

        Set the Legion channel muffle to either off or on.
*/
l_muffle(str) {
if(!str && str != "on" && str != "off") {
        write("Usage l_muffle <on/off>\n");
        return 1;
}
if(str == "on" && query_muffs() == "on" && query_color() == "on") {
        write(RED+"Legion muffle"+END+" is already on.\n");
        return 1;
}
if(str == "on" && query_muffs() == "on" && query_color() == "off") {
        write("Legion muffle is already on.\n");
        return 1;
}
if(str == "off" && query_muffs() == "off" && query_color() == "on") {
        write(RED+"Legion muffle"+END+" is already off.\n");
        return 1;
}
if(str == "off" && query_muffs() == "off" && query_color() == "off") {
        write("Legion muffle is already off.\n");
        return 1;
}
else {
        if(query_color() == "on") {
                set_muffs(str);
                write("Setting "+RED+"Legion muffle"+END+" to "+str+".\n");
                return 1;
        }
        else {
                set_muffs(str);
                write("Setting Legion muffle to "+str+".\n");
                return 1;
        }
}
return 0;
}


