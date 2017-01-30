int xnrofrooms, ynrofrooms, nrofcolors;
int colornr;
int arraylength;
string roomcolor;
string boxcolor;
string colors;
reset(arg) {
nrofcolors = 4;
   xnrofrooms = 2;
   ynrofrooms = 2;
   colors = ({
       "green","blue","red","black","white",
       "brown"});
    makeroomcolor();
    makeboxcolor();
}
init () 
{
   add_action("show_colors","show");
    add_action("makeroomcolor","color");
}
show_colors()
{   int z;
    for(z=0;z<nrofcolors;z++)
    {   write ("room "+z+" = "+roomcolor[z]+"\n");
        write ("box "+z+" = "+boxcolor[z]+"\n");
    }
    return 1;
}
makeroomcolor() 
{
    string colordel;
    filter_array(colors,"pick",colordel);
}
pick(colordel)
{
    int ndel;
    ndel = random (sizeof(colors));
   colordel = colors[ndel];
return 1;
}
