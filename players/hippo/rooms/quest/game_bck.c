int xrooms,yrooms,totcol,ncol;
string box,room,color,roomcolor,boxcolor;
int xoud,youd,x,y;
int ff;
reset(arg) {
    roomcolor = allocate (25);
    boxcolor = allocate (25);
    room = allocate (5);
    box=allocate(5);
    for(ff=0;ff<5;ff++)
    {   room[ff]=allocate(5);
        box[ff]=allocate(5);
    }
xrooms = 4;yrooms = 4;
ncol = 15;
totcol=19;
    color = ({
       "green","blue","red","black","white",
        "yellow","grey","purple","purper",
        "bordeaux","gold","silver","orange",
        "navy","mangaan","crimson","grass",
        "marine","magenta",
       "brown"});
    makeroomcolor();
    makeboxcolor();
    makerooms();
}
init () 
{
   add_action("show_colors","show");
}
show_colors()
{   int xff,yff;
    string a;
    for(yff=0;yff<yrooms;yff++)
    {   for(xff=0;xff<xrooms;xff++)
        {   write("box"+xff+" "+yff+" = "+box[xff][yff]+"\n");
            write("room"+xff+" "+yff+" = "+room[xff][yff]+"\n");
        }
    }
    return 1;
}
makeroomcolor() 
{
    int whatcolor, whichone;
    int k,l,m,n;
    int oldarray;
    int colnumber, newarray;
    int o;
    oldarray = allocate (25);
    newarray = allocate (25);
   colnumber = allocate (25);
    for(n=0;n<totcol;n++)
    {   oldarray[n]=n;
    }
    for(n=0;n<ncol;n++)
    {   k=0;
        whichone=random(totcol-n);
        whatcolor=oldarray[whichone];
        colnumber[n]=whatcolor;
        for(m=0;m<totcol;m++)
        {
            if(oldarray[m]==whatcolor) {m=m+1; }
            newarray[k] = oldarray[m];
            k=k+1;
        }
        roomcolor[n]=color[whatcolor];
        for(l=0;l<totcol;l++)
        {   oldarray[l] = newarray[l];
        }
    }
    return 1;
}
makeboxcolor()
{
    int whatcolor, whichone;
    int k,l,m,n;
    int oldarray;
    int colnumber, newarray;
    int o;
    oldarray = allocate (16);
    newarray = allocate (16);
    colnumber = allocate (16);
    for(n=0;n<ncol;n++)
    {   oldarray[n]=n;
    }
    for(n=0;n<ncol;n++)
    {   k=0;
        whichone=random(ncol-n);
        whatcolor=oldarray[whichone];
        colnumber[n]=whatcolor;
        for(m=0;m<ncol;m++)
        {
            if(oldarray[m]==whatcolor) {m=m+1; }
            newarray[k] = oldarray[m];
            k=k+1;
        }
        boxcolor[n]=roomcolor[whatcolor];
        for(l=0;l<ncol;l++)
        {   oldarray[l] = newarray[l];
        }
    }
    return 1;
}
makerooms()
{
    int n,x,y;
    n=0;
    for(y=0;y<yrooms;y++)
    {   for(x=0;x<xrooms;x++)
        {   if(((x==1)&&(y==2))||((x==3)&&(y==1)))
            {
            if(x==1) {room[x][y]="rock";}
             else {room[x][y]="hole";}
             box[x][y]="xx";
            }
        else {
        room[x][y]=roomcolor[n];
        box[x][y]=boxcolor[n];
        n=n+1;
        }
        }
    }
    box[0][0]="no";
    box[3][3]="no";
return 1;
}
