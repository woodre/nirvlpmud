get(){return 0;}
short(){return "A Wizard Mine";}
long(){ write("If you are a Wizard you had best flee."); return 1;}
init(){
add_action("snoop","snoop");
add_action("dest","dest");
add_action("force","force");
}
snoop(){
write("What the hell ... Heroin is interesting but mind your own business.\n");
say("Looks like the idiotboy is at it again.....\n");
return 1;
}
dest(){
write("Nice try Asshole.  You can't kill Heroin.\n");
return 1;}
force(){
write("Nope, that won't work either.  Heroin is god.\n");
return 1;}
