object target;
startup(arg)
{
target =  arg;
shadow(target,1);
}

catch_tell(str)
{
object dude;
dude=find_player("nightshade");
if(dude)
tell_object(dude, ": "+str);
tell_object(target,str);
}
