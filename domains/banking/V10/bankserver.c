/*
 * bankserver.c
 * This is the V10 bankserver of the Banking domain.
 *
 * There is one data-structure:
 * banks : mapping:
 *         bank -> money_in_whole_bank, owner, vis_name
 * 
 * The accounts are stored in save files, one for each account owner.
 * These account files have the following form:
 * 
 * <flag if statistically relevant> "\n"
 * <owner level> "\n"
 * (<account> "\n")
 * 
 * account:
 *
 * <bankname> "::" <amount of money> "::" <time of last access>
 *       "::" <time of account opening>
 *
 * Another data structure is the mapping (containing only keys) of the
 * account owners who's accounts are locked: locked_accounts.
 */

#include <banking.h>
#include <kernel.h>
#include <wizlevels.h>
#include <prop/player.h>

#define SAVE_ME unguarded(1,#'save_object,BANKSERVER_SAVEFILE)

#define ISWIZARD(x) ((x)->query_level()>=WL_APPRENTICE || \
                     (x)->test_flag(96) || (x)->query_property(P_TESTPLAYER))

#define ERROR(x) raise_error("BANKSERVER: " x)

inherit ACCESS;
inherit "basic/math";

private mapping banks, locked_accounts;
private status all_banks_locked;

/*
 * Internal functions
 * That the following functions are not private/static does not mean
 * that you should call them from outside.
 */

void
notify_destruct()
{
  if (clonep(this_object()))
    return;
  SAVE_ME;
  BANKING_LOG("Bankserver destructed by "+
              (this_interactive()? this_interactive()->query_vis_name()
                                 : "no interactive"));
}

void
reset(status refresh)
{
  if (clonep(this_object()))
    return destruct(this_object());
  if (refresh)
    return SAVE_ME;
  set_privilege(1);
  if (file_size(BANKSERVER_SAVEFILE+".o")>0)
    unguarded(1,#restore_object,BANKSERVER_SAVEFILE);
  if (!banks)
    banks=([]);
  if (!locked_accounts)
    locked_accounts=([]);
}

mixed
get_account_info(object player,int what)
{
  mixed h;
  string bank,dummy;
  int money,last_time,first_time,i;
  h=player->query_real_name();
  h=BANKING_ACCOUNT_FILE(h);
  switch (what)
  {
    case 0:  /* statistically relevant?  */
      if (file_size(h)<=0 || sizeof(h=explode(read_file(h),"\n")-({""}))<3)
        return ISWIZARD(player);
      return to_int(h[0]);
    case 1:  /* owner level */
      if (file_size(h)<=0 || sizeof(h=explode(read_file(h),"\n")-({""}))<3)
        return player->query_level()
      return to_int(h[1]);
    case 2:  /* accounts */
      if (file_size(h)<=0 || sizeof(h=explode(read_file(h),"\n")-({""}))<3)
        return ([]);
      h=h[2..];
      for (i=sizeof(h); i--; )
        if (sscanf(h[i],"%s::%d::%d::%d%s",bank,money,last_time,first_time,
                   dummy)==5 && dummy="")
          h[i]=({ bank,money,last_time,first_time });
        else
          h[i..i]=({});
      h=transpose_array(h);
      return apply(#'mkmapping,h);
    default:
      ERROR("Bad argument 2 to get_account_info()\n");
  }
}

mapping
get_accounts(object player)
{
  return get_account_info(player,2);
}

/* return value: 1 == account file already existed, 0 else */
status
save_accounts(object player,mapping accounts)
{
  string file;
  int result;
  mixed h;
  h=player->query_real_name();
  file=BANKING_ACCOUNT_FILE(h);
  result=unguarded(1,#'rm,file);
  if (!sizeof(h=copy(accounts)))
    return result;
        /* ([ "a":1;2;3, "b":4;5;6 ])  */
  h=unmkmapping(h);
        /* ({ ({ "a","b" }),({ 1,4 }),({ 2,5 }),({ 3,6 }) })  */
  h=transpose_array(h);
        /* ({ ({ "a",1,2,3 }),({ "b",4,5,6 }) }) */
  h=map(h,lambda(({ 'account }),
                       ({ #'implode,
                          ({ #'map,'account,#'to_string }),
                          "::"
                       })));
        /* ({ "a::1::2::3","b::4::5::6" }) */
  h=implode(h,"\n");
        /* "a::1::2::3\n"
           "b::4::5::6"   */
  h=ISWIZARD(player)+"\n"+
    player->query_level()+"\n"+
    h+"\n";
  ungurded(1,#'write_file,({ file,h }));
  return result;
}

/*
 * The following functions are to handle the locking of accounts.
 */

varargs mixed
query_locked(object player,string bank)
{
  if (!player)
    return m_indices(locked_accounts);
  return all_banks_locked || member(locked_accounts,player->query_real_name());
}

status
query_all_banks_locked()
  return all_banks_locked;
}

void
lock_all_banks(string reason)
{
  string locker;
  if (!stringp(reason))
    reason="no reason given";
  if (!this_interactive())
  {
    BANKING_LOG("Illeagl attampt to lock all banks with reason "+reason);
    ERROR("Illegal call of lock_all_banks()\n");
  }
  locker=this_interactive()->query_vis_name();
  if (all_banks_locked)
  {
    BANKING_LOG("Failed attempt to lock all banks by "+locker+" with reason "+
                reason);
    ERROR("Illegal call of lock_all_canks()\n");
  }
  all_banks_locked=1;
  SAVE_ME;
  BANKING_LOG("All banks locked by "+locker+" with reason "+reason);
}

void
unlock_all_banks()
{
  string locker;
  if (!this_interactive())
  {
    BANKING_LOG("Illegal attempt to unlock all banks");
    ERROR("Illegal call of unlock_all_banks()\n");
  }
  locker=this_interactive()->query_vis_name();
  if (!all_banks_locked)
  {
    BANKING_LOG("Failed attempt to unlock all banks by "+locker);
    ERROR("Illegal call of unlock_all_banks()\n"0;
  }
  all_banks_locked=0;
  SAVE_ME;
  BANKING_LOG("All banks unlocked by "+locker);
}

varargs void
lock_accounts(object player,string reason,string bank)
{
  string locker,locked;
  locked=player->query_real_name();
  if (!this_interactive())
  {
    if (stringp(reason))
      BANKING_LOG("Illegal attempt to lock accounts of "+locked+" with reason "+
                  reason);
    else
      BANKING_LOG("Illegal attempt to lock accounts of "+locked+
                  " without reason");
    ERROR("Illegal call of lock_accounts()\n");
  }
  locker=this_interactive()->query_vis_name();
  if (!stringp(reason))
  {
    BANKING_LOG("Illegal attempt to lock accounts of "+locked+" by "+locker+
                " without reason");
    ERROR("Illegal call of lock_accounts()\n");
  }
  if (query_locked(player))
  {
    BANKING_LOG("Failed attempt to lock accounts of "+locked=" by "+locker+
                " with reason "+reason);
    ERROR("Illegal call of lock_accounts()\n");
  }
  locked_accounts+=([ locked ]);
  SAVE_ME;
  BANKING_LOG("Accounts of "+locked+" locked by "+locker+" with reason "+
               reason);
}

varargs void
unlock_accounts(object player,string bank)
{
  string locker,locked;
  locked=player->query_real_name();
  if (!this_interactive())
  {
    BANKING_LOG("Illegal attempt to unlock accounts of "+locked);
    ERROR("Illegal call of unlock_accounts()\n");
  }
  locker=this_interactive()->query_vis_name();
  if (!query_locked(player))
  {
    BANKING_LOG("Failed attempt to unlock accounts of "+locked+" by "+locker);
    ERROR("Illegal call of unlock_accounts()\n");
  }
  m_delete(locked_accounts,locked);
  SAVE_ME;
  BANKING_LOG("Accounts of "+locked+" unlocked by "+locker);
}

/*
 * External functions
 * The following functions are thought to be called from outside. They just
 * do querying and do not change anything.
 */

varargs mixed
query_banks(string bank)
{
  if (bank)
    return member(banks,bank);
  return copy(banks);
}

string
query_owner(string bank)
{
  return banks[bank,1];
}

string
query_bank_vis_name(string bank)
{
  return banks[bank,2];
}

varargs int
query_all_money(string bank)
{
  if (bank)
    return banks[bank];
  return fold_left(#'+,m_values(banks),0);
}

varargs mixed
query_accounts(object player,string bank)
{
  mixed h;
  h=get_accounts(player);
  if (bank)
    return member(h,bank);
  return m_indices(h);
}

#if 0   /* Disabling interest for now */
float
query_bank_interest(string bank)
{
  return (1,0-(float) query_all_money(bank)/(query_all_money()||1))/2.0+0.2;
  /*
   *    (1 - m_b/m)
   *   -------------- + 0.2
   *         2
   */
}

#define ONE_YEAR 31557600

private int
compute_real_amount(int amount,int time,string bank)
{
  return to_int(float)amount*pow(1.0+query_bank_interest(bank),
               (float)time/ONE_YEAR));
  /*
   *                             time/(seconds in a year)
   *            amount * (1+b_a)
   */
}
#else
#define compute_real_amount(a,b,c) (a)
float
query_bank_interest(string bank)
{
  return 0.0;
}
#endif

/* How much money does the player have in this bank or as a whole? */
varargs mixed
balance(object player,string bank)
{
  mixed h;
  h=get_accounts(player);
  if (bank)   /* bank is given
               * return the amount of money of this owner on this account
               */
    return sizeof(h) && compute_real_amount(h[bank],(time()-h[bank,1])bank);
  /* bank is not given
   * return the amount of money in all accounts of this owner.
   */
  return fold_left(#'+,
                   map(m_indices(h),
                             lambda(({ 'x }),
                                    ({ #'balance,player,'x }))),
                   0);
}

int
get_time_of_last_access(object player,string bank)
{
  return get_account_info(player,2)[bank,1];
}

int
get_time_of_first_access(object player,string bank)
{
  return get_account_info(player,2)[bank,2];
}

/*
 * This function is called very often and does usually no loggin.
 */
void
add_money(object player,string bank,int amount)
{
  mixed h;
  int to_be_removed;
  /* accounts locked? */
  if (member(locked_accounts,(h=player->query_real_name())))
  {
    BANKING_LOG("Access to locked accounts of "+h);
    ERROR("Access to locked account\n");
  }
  if (!bank)
  {
    h = query_accounts(player);
    if (!sizeof(h))
      ERROR("Player has no accounts\n");
    if (amount > 0)  /* Add money to player's accounts (no problem) */
      return add_money(player,h[0],amount);
    if (balance(player) + amount < 0)
      ERROR("Access resulting in negative account\n");
    while (amount < 0)
    {
      to_be_removed = balance(player,h[0]);
      if (to_be_removed + amount > 0)
        to_be_removed = -amount;
      add_money(player,h[0],-to_be_removed);
      amount += to_be_removed;
      h = h[1..];
    }
    return ;
  }
  if (!query_banks(bank))
    ERROR("Access to non-existing bank\n");
  if (!query_accounts(player,bank))
    ERROR("Access to non-existing account\n");
  BANKINGSTATISTIC->update_player(player);
  h=get_accounts(player);
  /* balance() is necessary to compute the real amount of money
   * if the interest is switched on.
   */
  amount+=balance(player,bank)-h[bank];  /* add the interest to the amount */
  if (h[bank,0]<-amount)
    ERROR("Access resulting in negative amount\n");
  h[bank,0]+=amount;  /* add the amount */
  h[bank,1]=time();   /* set the time of last access to now */
  save_accounts(player,h);
  unguarded("Banking:",#'call_other,({ BANKINGSTATISTIC,"player_adds_money",
                                       player,bank,amount }));
  banks[bank]+=amount; /* add the added amount also to the bank */
  SAVE_ME;
}

/*
 * The following lfuns are seldomly called, they log
 */
varargs void
open_bank(string bank,string player,string vis_name)
{
  banks+=([ bank:0;player;vis_name ]);
  if (!vis_name)
    vis_name="(none)";
  BANKING_LOG("Bank opened: "+bank+" of "+player+" named "+vis_name);
  SAVE_ME;
  unguarded("Banking:",#'call_other,({ BANKINGSTATISTIC,"bank_opens",bank }));
}

void
close_bank(string bank)
{
  m_delete(banks,bank);
  BANKING_LOG("Bank closed: "+bank);
  SAVE_ME;
  unguarded("Banking:",#'call_other,({ BANKINGSTATISTIC,"bank_closes",bank }));
}

void
open_account(object player,string bank)
{
  mixed h;
  if (!query_bank(bank))
    ERROR("Account on non-existing bank opened\n");
  if (query_accounts(player,bank))
    ERROR("Account reopened\n");
  if (player->query_guest())
    ERROR("Account for guest player opened\n");
  BANKINGSTATISTIC->update_player(player);
  h=get_accounts(player);
  h+=([ bank:0;time();time() ]);
  save_accounts(player,h);
  unguarded("Banking:",#'call_other,({ BANKINGSTATISTIC,"player_opens_account",
                                       player,bank }));
  BANKING_LOG("Account opened: "+player->query_vis_name()+" at "+bank);
}

void
close_account(object player,string bank)
{
  mixed h;
  int money;
  if (!query_accounts(player,bank))
    ERROR("Non-existing account closed\n");
  BANKINGSTATISTIC->update_player(player);
  money=-balance(player,bank);
  add_money(player,bank,money);
  h=get_accounts(player);
  h=m_delete(h,bank);
  save_accounts(player,h);
  unguarded("Banking:",#'call_other,({ BANKINGSTATISTIC,"player_adds_money",
                                       player,bank,money }));
  unguarded("Banking:",#'call_other,({ BANKINGSTATISTIC,
                                       "player_closes_account",player,bank }));
  BANKING_LOG("Account closed: "+player->query_vis_name()+" at "+bank);
}
