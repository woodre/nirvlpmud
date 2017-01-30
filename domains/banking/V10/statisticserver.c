/*
 * This is the V10 statisticserver of the Banking domain
 */

#include <banking.h>
#include <kernel.h>
#include <describe.h>
#include <wizlevels.h>
#include <prop/player.h>
#include <fingerd.h>
#include <closures.h>
#include <time_units.h>
#include <limits.h>
#include <is_wizard.h>

#define SAVE_ME unguarded(1,#'save_object,BANKINGSTATISTIC_SAVEFILE)

#define ISWIZARD(x) is_wizard(x,IW_TOOLUSER)

inherit ACCESS;

/*
 * Data structures:
 *
 * sells,buys,withdraws,deposits: mappings:
 *   level: amount as a whole; number of actions
 * 
 * balance: mapping:
 *   level: amount as a whole; number of players with accounts on this level
 *
 * banks: mapping:
 *   bank: number of accounts; money as a whole
 *
 * transactions: mapping:
 *   playername: transacted money; time of last transaction
 *
 */

mapping sells,buys,withdraws,deposits,balance,banks,transactions;
int log_min_withdraw,log_min_deposit;
int next_backup;

mapping query_buys() { return copy(buys); }
mapping query_sells() { return copy(sells); }
mapping query_withdraws() { return copy(withdraws); }
mapping query_deposits() { return copy(deposits); }
mapping query_balance() { return copy(balance); }
mapping query_banks() { return copy(banks); }

int query_log_min_withdraw() { return log_min_withdraw; }
int query_log_min_deposit() { return log_min_deposit; }

/*
 * Internal functions
 */
void
notify_destruct()
{
  if (clonep(this_object()))
    return;
  BANKING_LOG("Statisticserver destructed by "+
              this_interactive()->query_vis_name());
  SAVE_ME;
}

varargs void
update_transactions(string name)
{
  if (name)
    transactions += ([ name: (transactions[name] *
                              pow(TRANSACTION_DECAY,
                                  to_float(time()-transactions[name,1]) /
                                  ONE_WEEK)); time() ]);
  else
    filter(m_indices(transactions),#'update_transactions);
}

mixed *
query_transactions()
{
  update_transactions();
  return order_alist(map(m_values(transactions),#'to_int),
                     m_indices(transactions));
}

void
reset(status arg)
{
  if (clonep(this_object()))
  {
    destruct(this_object());
    return;
  }
  if (arg)
  {
    SAVE_ME;
    return;
  }
  if (find_call_out("one_week_over") >= 0)
    raise_error("Illegal call of reset(0)\n");
  unguarded(1,#'restore_object,BANKINGSTATISTIC_SAVEFILE);
  if (!sells)
    sells = m_allocate(0,2);
  if (!buys)
    buys = m_allocate(0,2);
  if (!withdraws)
    withdraws = m_allocate(0,2);
  if (!deposits)
    deposits = m_allocate(0,2);
  if (!balance)
    balance = m_allocate(0,2);
  if (!banks)
    banks = m_allocate(0,2);
  if (!transactions)
    transactions = m_allocate(0,2);
  if (!log_min_withdraw)
    log_min_withdraw = 10000;
  if (!log_min_deposit)
    log_min_deposit = 5000;
  next_backup = time() + ONE_WEEK - time() % ONE_WEEK;
  if (find_call_out("one_week_over") < 0)
    call_out("one_week_over",next_backup-time());
}

void
clean_transactions()
{
  update_transactions();
  transactions = filter(transactions,
                        lambda(({ 'name, 'args }),
                               ({ #'>,
                                  ({ #'abs, ({ CL_L_INDEX, 'args, 0 }) }),
                                  1000.0 })));
}

static void
one_week_over()
{
  next_backup += ONE_WEEK;
  walk_mapping(([ "sells": sells,
                  "buys": buys,
                  "withdraws": withdraws,
                  "deposits": deposits,
                  "balance": balance,
                  "banks": banks ]),
               lambda(({ 'k,'v }),
                      ({ (#'unguarded),
                         "Banking:",
                         (#'call_other),
                         ({ CL_ARRAY,
                            BANKINGSTATISTIC_ARCHIVE,
                            "add_data",
                            'k,
                            'v }) })));
  BANKINGSTATISTIC_ARCHIVE->save_me();
  sells = m_allocate(0,2);
  buys = m_allocate(0,2);
  withdraws = m_allocate(0,2);
  deposits = m_allocate(0,2);
  call_out("one_week_over",ONE_WEEK);
  clean_transactions();
  SAVE_ME;
}

/*
 * To be called by the clients (our interfaces and so on)
 */
void
player_buys(object pl,int money)
{
  mixed h;
  if (ISWIZARD(pl))
    return;
  h = pl->query_level();
  buys[h] += money;
  buys[h,1]++;
}

void
player_sells(object pl,int money)
{
  mixed h;
  if (ISWIZARD(pl))
    return;
  h = pl->query_level();
  sells[h] += money;
  sells[h,1]++;
}

/*
 * Each time we get information about a player using a bank and thus
 * giving us information about him we have to check if what we know is
 * still correct.  To check this call update_player(pl)
 */
private void player_changes_level(object pl,int from,int to);

void
update_player(object pl)
{
  int old_level,new_level;
  status was_wizard;
  was_wizard = BANKSERVER->get_account_info(pl,0);
  old_level = BANKSERVER->get_account_info(pl,1);
  if ISWIZARD(pl))
  {                /* irrelevant player */
    if (!was_wizard)  /* we did not know yet that this player was irrelevant */
      player_changes_level(pl,old_level,0);
    return;
  }
  new_level = pl->query_level();
  if (was_wizard)  /* a former wizard is now not one */
    old_level = 0;
  if (old_level != new_level)  /* player has new level since last time */
    player_changes_level(pl,old_level,new_level);
}

private void
player_changes_level(object pl,int from,int to)
{
  int b;
  b = BANKSERVER->balance(pl);
  if (from)
  {
    balance[from] -= b;
    balance[from,1]--;
  }
  else   /* player appeared, add all his accounts */
    map(BANKSERVER->query_accounts(pl),
              lambda(({ 'x }),
                     ({ (#',),
                        ({ (#'+=),({ CL_INDEX,banks,'x }),1 }),
                        ({ (#'+=),
                           ({ CL_INDEX,banks,'x,1 }),
                           ({ (#'call_other),
                              BANKSERVER,"balance",pl,'x }) }) })));
  if (to)
  {
    balance[to] += b;
    balance[to,1]++;
  }
  else   /* player disappeared, remove all his accounts */
    map(BANKSERVER->query_accounts(pl),
              lambda(({ 'x }),
                     ({ (#',),
                        ({ (#'-=),({ CL_INDEX,banks,'x }),1 }),
                        ({ (#'-=),
                           ({ CL_INDEX,banks,'x,1 }),
                           ({ (#'call_other),
                              BANKSERVER,"balance",pl,'x }) }) })));
}

/*
 * This is called when a player has a movement on his bank accounts
 */
void
player_adds_money(object pl,string bank,int money)
{
  string name;
  int new_level;
  if (!check_previous_privilege("Banking:"))
    raise_error("Illegal call of player_adds_money()\n");
  new_level = pl->query_level();
  if (ISWIZARD(pl))
    return;
  balance[new_level] += money;
    /* log the movement to make finding cheaters possible */
  name = pl->query_real_name();
  update_transactions(name);
  transactions[name] += to_float(money);
  if (money > 0)
  {   /* deposit */
    deposits[new_level] += money;
    deposits[new_level,1]++;
    if (money > log_min_deposit)
      BANKING_LOG(pl->query_vis_name() + " deposits " + money + " in " +
                  to_string(environment(pl)));
  }
  else if (money < 0)
  {   /* withdraw */
    withdraws[new_level] -= money;
    withdraws[new_level,1]++;
    if (-money > log_min_withdraw)
      BANKING_LOG(pl->query_vis_name() + " withdraws " + (-money) + " in " +
                  to_string(environment(pl)));
  }
      /* else just update */
  banks[bank,1] += money;
  SAVE_ME;
}

/*
 * This is called when a new bank is opened or an old one is closed
 */
void
bank_opens(string bank)
{
  if (!check_previous_privilege("Banking:"))
    raise_error("Illegal call of bank_opens()\n");
  banks[bank] = 0;
  SAVE_ME;
}

void
bank_closes(string bank)
{
  if (!check_previous_privilege("Banking:"))
    raise_error("Illegal call of bank_closes()\n");
  /* Here the data about this bank should be subtracted from the whole...
   * still to be done, after all, banks close seldom
   */
  m_delete(banks,bank);
  SAVE_ME;
}

/*
 * This is called when a player opens or closes an account in a bank
 */
void
player_opens_account(object pl,string bank)
{
  if (!check_previous_privilege("Banking:"))
    raise_error("Illegal call of player_opens_account()\n");
  if (!ISWIZARD(pl))
    banks[bank]++;
}

void
player_closes_account(object pl,string bank)
{
  if (!check_previous_privilege("Banking:"))
    raise_error("Illegal call of player_closes_account()\n");
  if (!ISWIZARD(pl))
    banks[bank]--;
}

/*
 * These are to be called just by the members of Banking to adjust
 */
void
set_log_min_withdraw(int i)
{
  if (!check_previous_privilege("Banking:"))
  {
    BANKING_LOG(this_interactive()->query_vis_name()+
                " tried to set log_min_withdraw to "+i);
    raise_error("Illegal call of set_log_min_withdraw()\n");
  }
  log_min_withdraw = i;
  BANKING_LOG(this_interactive()->query_vis_name()+
              " set log_min_withdraw to "+i);
}

void
set_log_min_deposit(int i)
{
  if (!check_previous_privilege("Banking:"))
  {
    BANKING_LOG(this_interactive()->query_vis_name()+
                " tried to set log_min_deposit to "+i);
    raise_error("Illegal call of set_log_min_deposit()\n");
  }
  log_min_deposit = i;
  BANKING_LOG(this_interactive()->query_vis_name()+
              " set log_min_deposit to "+i);
}

/*
 * This updates the mapping 'balance' and is very costly, do not call
 * it without good reason
 */
private void
update_balance_loop(string *owners,int i)
{
  object pl;
  int b, level;
  status is_wizard;
  while (get_eval_cost() > MAX_COST-100000 && i--)
  {
    pl = FINGERD->load_player(owners[i]));
    if (!pl)    /* player disappeared, ok */
      continue;
    is_wizard = BANKSERVER->get_account_info(pl,0);
    if (is_wizard)
      continue;
    level = BANKSERVER->get_account_info(pl,1);
    b = BANKSERVER->balance(pl);
    balance[level] += b;
    balance[level,1]++;
    map(BANKSERVER->query_accounts(pl),
              lambda(({ 'x }),
                     ({ (#',),
                        ({ (#'+=),({ CL_INDEX,banks,'x }),1 }),
                        ({ (#'+=),
                           ({ CL_INDEX,banks,'x,1 }),
                           ({ (#'call_other),
                              BANKSERVER,"balance",pl,'x }) }) })));
  }
  if (i>=0)
  {
    if (this_player())
      write("Still "+describe("1 player",0,0,i,1)+" accounts to compute.\n");
    call_out(#'update_balance_loop,10,owners,i);
  }
  else
  {
    if (this_player())
      write("Finished.\n");
    SAVE_ME;
  }
}

void
update_balance()
{
  string *owners;
  string i;
  if (!check_previous_privilege("Banking:"))
  {
    BANKING_LOG(this_interactive()->query_vis_name()+
                " tried to update the balance.");
    raise_error("Illegal call of update_balance()\n");
  }
  BANKING_LOG(this_interactive()->query_vis_name()+" updated the balance.");
  unguarded(1,#'save_object,BANKINGSTATISTIC_SAVEFILE+time());
  owners = ({});
  for (i="/"BANKING"save/accounts/a/"; i[<2]<='z'; i[<2]++)
    owners += get_dir(i);
  balance = m_allocate(0,2);
  banks = m_allocate(0,2);
  update_balance_loop(owners,sizeof(owners));
}
