/* Loan Daemon for Nirvana's Loan Sharks */
/* Verson 1.0                            */
/* Fred & Earwax Compilation             */
/* Change this and suffer Earwax's wrath */


#define L_SAVE "players/fred/closed/loans/loan_log"


/*********** Current Variables ***********/

string       *names;
int       *loan_amt;
int *time_remaining;



/********* Historical Variables **********/

int   *past_loans;
int *past_amounts;
int *credit_score;


/********* Misc Variables **********/

static mixed *Current;  /* for sorting purposes           */
static mixed sorted;    /* Array once sorted              */
static int juice;       /* will be used for interest calc */
static int rating;      /* will be used for interest calc */
static int a,b,i,k;     /* for general use throughout     */

void save_info();
void order_array();

void reset(mixed arg)
{
  if(arg) return;
  
  if(!restore_object(L_SAVE))
  {
    names           = ({ }); /* Player's Name                    */
    loan_amt        = ({ }); /* Amount borrowed + Interest       */
    time_remaining  = ({ }); /* Time until loan is due           */
  
    past_loans      = ({ }); /* How many times taken loans       */
    past_amounts    = ({ }); /* Running total of loan amounts    */
    credit_score    = ({ }); /* What kind of credit do they have */
    save_info(); 
  }      
}


/****** Controlling Loan Info *******/   

new_loan(string me, int amt, int time, int x, int y)
{
  if((i = member_array(me, names)) < 0)
  {
    b = ((amt * 140) / 100);
    loan_amt       +=  ({ b });
    names          +=  ({ me });  
    time_remaining +=  ({ time });    
    past_loans     +=  ({ x });
    past_amounts   +=  ({ y });
    credit_score   +=  ({ 60 });
  }
  else
  {
    b = ((amt * (200 - query_credit_score(me))) / 100);
    loan_amt[i]       +=  b;
    time_remaining[i] +=  time;    
  }
  save_info();
}

loan_pd(string me, int amt)
{
  i = member_array(me, names);  
   loan_amt[i]       -= amt;
   past_amounts[i]   += amt;
   past_loans[i]     +=   1;
   time_remaining[i]  =   0;    
   save_info(); 
}

int query_loan_amt(string me)
{
  i = member_array(me, names);
  return loan_amt[i];
}

int query_time_remaining(string me)
{
  i = member_array(me, names);
  return time_remaining[i];
}

int query_past_loans(string me)
{
  i = member_array(me, names);
  return past_loans[i];
} 

int query_past_amounts(string me)
{
  i = member_array(me, names);
  return past_amounts[i];
}

int query_credit_score(string me)
{
  i = member_array(me, names);
  return credit_score[i];
}

void start_up(string me)
{
  i = member_array(me, names);
  Current += ({ time_remaining[i], me });
  order_array();
}


/************* Sorting Array **************/


int sort_me(int x, int y)
{
  return (y > x);
}

void order_arrays()
{
  int x, z, y, i, j;
  int *check;

  time_remaining = sort_array(time_remaining, "sort_me", this_object());
  names = allocate(sizeof(time_remaining));

  y = sizeof(time_remaining);

  check = ({ });

  for(x = 0; x < y; x ++)
  {
    j = 0;
    i = member_array(time_remaining[x], Current);
    while(!j)
    {
      z = member_array(i, check);
      if(z == -1)
      {
        check += ({ i });
        j = 1;
      }
      else
      {
        i += 2;
      }
    }
    if(intp(Current[i+1])){ i += 1; }
    names[x] = Current[i+1];
  }
}

void save_info()
{
  save_object(L_SAVE);
}