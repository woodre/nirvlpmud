#pragma strong_types
#pragma no_shadow

#include <wizlist.h>

#define ACCOUNTS        4

#define EXP_GAIN        0
#define EXP_LOSS        1
#define MONEY_GAIN      2
#define MONEY_LOSS      3

int sort_param;

private void charge_account(string name,int amount,int account) {
  int *temp;

  // changed object_name() to load_name(), Coogan, 21-Nov-2003
  if (stringp(creator_file(load_name(previous_object()))) &&
      !previous_object()->handle_wizlist_add_money_on_our_own())
    return;

  if (!name)
    return;

  if (!pointerp(temp = get_extra_wizinfo(name)))
    temp = allocate(ACCOUNTS);
  temp[account] += amount;
  set_extra_wizinfo(name, temp);
}

void add_money(int amount,object who) {
  if (amount < 0)
    charge_account(creator(who),-amount,MONEY_LOSS);
  else
    charge_account(creator(who), amount,MONEY_GAIN);
}

void add_exp(int amount,object who) {
  if (amount < 0)
    charge_account(creator(who),-amount,EXP_LOSS);
  else
    charge_account(creator(who), amount,EXP_GAIN);
}

static int match_regexp(mixed *wizlist_entry,string selector) {
  return sizeof(regexp(wizlist_entry[0..0],selector));
}

static int greater_alpha(mixed *a,mixed *b) {
  return a[0]>b[0];
}

static int less_cost(mixed *a,mixed *b) {
  return a[2]<b[2];
}

static int less_hb(mixed *a,mixed *b) {
  return a[3]<b[3];
}

static int less_mem(mixed *a,mixed *b) {
  return a[5]<b[5];
}

static status less_extra(mixed a,mixed b) {
  a = a[6];
  if (a)
    a = a[sort_param];
  b = b[6];
  if (b)
    b = b[sort_param];
  return a<b;
}

void show_wizlist(mixed selector) {
  mixed *wizlist;
  mixed *result;
  string sort_func;
  int i;
  int commands;
  int top;

  top = -1;
  sort_param = 0;
  selector = explode(selector," ")-({""});
  if (member(selector, "-top") > -1)
    sort_func = "less_cost";
  else
    sort_func = "greater_alpha";
  for (i=0;i<sizeof(selector);) {
    if (selector[i][0]=='-') {
      switch (selector[i++]) {
      case "-top":
        selector[i-1] = 0;
        if (i==sizeof(selector))
          top = 10;
        else if (sscanf(selector[i],"%d",top)!=1 || top<=0)
          top = 10;
        else
          selector[i++] = 0;
        break;

      case "-sort":
        selector[i-1]=0;
        if (i==sizeof(selector))
          sort_func = "greater_alpha";
        else {
          switch (selector[i]) {
          case "cost":
            sort_func = "less_cost";
            break;
          case "names":
            sort_func = "greater_alpha";
            break;
          case "mem":
            sort_func = "less_mem";
            break;
          case "hb":
            sort_func = "less_hb";
            break;
          case "+exp":
            sort_func = "less_extra";
            sort_param = EXP_GAIN;
            break;
          case "-exp":
            sort_func = "less_extra";
            sort_param = EXP_LOSS;
            break;
          case "+money":
            sort_func = "less_extra";
            sort_param = MONEY_GAIN;
            break;
          case "-money":
            sort_func = "less_extra";
            sort_param = MONEY_LOSS;
            break;
          default:
            i--;
          }
          selector[i++]=0;
        }
      }
    }
    else
      i++;
  }
  selector -= ({ 0 });
  selector = implode(selector," ");
  wizlist = wizlist_info();
  commands = 0;
  for (i=0;i<sizeof(wizlist);i++)
    commands += wizlist[i][1];
  write("Total commands so far: " + commands + "\n");
  wizlist = filter(wizlist,"match_regexp",this_object(),selector);
  wizlist = sort_array(wizlist,sort_func,this_object());
  if (top>0)
    wizlist = wizlist[0..top-1];
  result = allocate(sizeof(wizlist)+1);
  result[0] = "\
NAME        | EVALCOST     HB  ARRAYS    EXP GIVEN/LOST  MONEY GIVEN/LOST\n\
------------+------------------------------------------------------------\n";
  for (i=0;i<sizeof(wizlist);i++) {
    mixed *t,*u;
    t = wizlist[i];
    u = t[WL_EXTRA];
    if (!pointerp(u))
      u = allocate(ACCOUNTS);
    result[i+1] = sprintf("%11-s | %7dk %6d %7d %8d/%8d %8d/%8d\n",
                          t[WL_NAME], t[WL_COST]/1000, t[WL_HEART_BEATS],
                          t[WL_ARRAY_TOTAL],
                          u[EXP_GAIN],u[EXP_LOSS],u[MONEY_GAIN],u[MONEY_LOSS]);
  }
  this_player()->view_text(implode(result,""),
                           this_player()->query_commandline());
  this_player()->start_view();
}

