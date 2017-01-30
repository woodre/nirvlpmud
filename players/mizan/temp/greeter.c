id(str) { return str == "greeter"; }

short() { return "An automatic greeter"; }

reset(arg)
{
   if(arg) return;

   call_out("greet_function", 1);
}

greet_function()
{
   say("You hear a voice say: 'Welcome to CostCo. I love you.'\n");
   remove_call_out("greet_function");
   call_out("greet_function", 3);
}
