shaped_arm()
{
  string msg, msg2;

  if(!random(3))
  {
    switch(random(6))
    {
      case 5:
        msg = "You "+HIK+"O B L I T E R A T E"+NORM+" "+ATTN+"'s torso with your "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+"";      
        msg2 = ""+USER->query_name()+" "+HIK+"O B L I T E R A T E S"+NORM+" "+ATTN+"'s torso with their "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+"";
        break;
                    
      case 4:
        msg = "You swing your "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" at "+ATTN+", "+HIR+"destroying"+NORM+" their face";
        msg2 = ""+USER->query_name()+" swings their "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" at "+ATTN+", "+HIR+"destroying"+NORM+" their face";
        break;
                    
      case 3:
        msg = "Your "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" "+HIG+"demolishes"+NORM+" one of "+ATTN+"'s arteries, spraying "+RED+"blood"+NORM+" everywhere";
        msg2 = ""+USER->query_name()+"'s "+HIW+"["+HIK+""+shaped_form+""+HIW+"] "+HIG+"demolishes"+NORM+" one of "+ATTN+"'s arteries, spraying "+RED+"blood"+NORM+" everywhere";
        break;
                    
      case 2:
        msg = "You spin around and plant your "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" upside "+ATTN+"'s head";
        msg2 = ""+USER->query_name()+" spins around and plants their "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" upside "+ATTN+"'s head";
        break;
               
      case 1:
        msg = "You "+HIW+"hit"+NORM+" "+ATTN+" with a solid blow from your "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+"";
        msg2 = ""+USER->query_name()+" "+HIW+"hits"+NORM+" "+ATTN+" with a solid blow from their "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+"";
        break;
                          
      case 0:
        msg = "Your "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" "+YEL+"grazes"+NORM+" "+ATTN+"'s torso";
        msg2 = ""+USER->query_name()+"'s "+BOLD+"["+NORM+HIK+""+shaped_form+""+NORM+BOLD+"]"+NORM+" "+YEL+"grazes"+NORM+" "+ATTN+"'s torso";
        break;
                      
      default:
        msg = "You "+HIB+"miss"+NORM+" "+ATTN+"";
        msg2 = ""+USER->query_name()+" "+HIB+"misses"+NORM+" "+ATTN+"";
        break;         
    }   
               
    tell_object(USER, "["+HIW+"Shaped"+NORM+"] "+msg+".\n");
    tell_room(environment(USER), msg2+".\n", ({USER}));
  }
}
