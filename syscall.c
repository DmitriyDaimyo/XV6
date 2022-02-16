//system call tracing

void
syscall(void)
{
  int num;
  int msk = 0;
  struct proc *p = myproc();
  num = p->trapframe->a7;

  if(num > 0 && num < NELEM(syscalls) && syscalls[num]) {
    p->trapframe->a0 = syscalls[num]();
  } else {
    printf("%d %s: unknown sys call %d\n",
            p->pid, p->name, num);
    p->trapframe->a0 = -1;
  }
  if(num == 22)
    p->wastrace = 1;
  else if(((p->mask) & (msk = 1 << num)) && (p->wastrace == 1))
		printf("%d: syscall %s -> %d\n", p->pid, syscall_string[num-1], p->trapframe->a0);

}
